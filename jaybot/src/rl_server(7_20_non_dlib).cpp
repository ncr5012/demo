#include "rclcpp/rclcpp.hpp"
#include "rl_custom_messages/msg/range_array.hpp"
#include "rl_custom_messages/msg/motor_commands.hpp"
#include "rl_custom_messages/srv/observation_service.hpp"
#include "rl_custom_messages/srv/image_service.hpp"
#include <sensor_msgs/msg/compressed_image.hpp>
#include <cv_bridge/cv_bridge.h>
#include <opencv2/opencv.hpp>
#include <thread>

using std::placeholders::_1;
using std::placeholders::_2;

class RangeSubscriber : public rclcpp::Node
{
public:
  RangeSubscriber()
  : Node("range_subscriber")
  {
    subscription_ = this->create_subscription<rl_custom_messages::msg::RangeArray>(
      "range_data", 10, std::bind(&RangeSubscriber::topic_callback, this, _1));
    service_ = this->create_service<rl_custom_messages::srv::ObservationService>("get_range_data",
    std::bind(&RangeSubscriber::service_callback, this, _1, _2));
    motor_command_publisher_ = this->create_publisher<rl_custom_messages::msg::MotorCommands>("motor_commands", 10);
    sound_command_publisher_ = this->create_publisher<rl_custom_messages::msg::MotorCommands>("sound_commands", 10);
  }

private:
  void topic_callback(const rl_custom_messages::msg::RangeArray::SharedPtr msg)
  {
    RCLCPP_INFO(this->get_logger(), "I heard - Left: '%f', Front: '%f', Right: '%f', Back: '%f'",
                 msg->range_left, msg->range_front, msg->range_right, msg->range_back);
    last_range_data_ = *msg;
  }

  void service_callback(
    const std::shared_ptr<rl_custom_messages::srv::ObservationService::Request> request,
    std::shared_ptr<rl_custom_messages::srv::ObservationService::Response> response)
  {
    motor_commands.commands.clear(); // Clear previous motor commands
    std::copy(request->motor_action.begin(), request->motor_action.end(), std::back_inserter(motor_commands.commands));

    sound_commands.commands.clear(); // Clear previous sound commands
    std::copy(request->sound_action.begin(), request->sound_action.end(), std::back_inserter(sound_commands.commands));

    std::string motor_commands_str = "Received motor_commands: ";
    for (const auto& command : motor_commands.commands)
    {
        motor_commands_str += std::to_string(command) + ", ";
    }
    RCLCPP_INFO(this->get_logger(), motor_commands_str.c_str());

    std::string sound_commands_str = "Received sound_commands: ";
    for (const auto& command : sound_commands.commands)
    {
        sound_commands_str += std::to_string(command) + ", ";
    }
    RCLCPP_INFO(this->get_logger(), sound_commands_str.c_str());

    response->range_data = last_range_data_;
    motor_command_publisher_->publish(motor_commands);
    sound_command_publisher_->publish(sound_commands);
  }

  rclcpp::Subscription<rl_custom_messages::msg::RangeArray>::SharedPtr subscription_;
  rclcpp::Service<rl_custom_messages::srv::ObservationService>::SharedPtr service_;
  rclcpp::Publisher<rl_custom_messages::msg::MotorCommands>::SharedPtr motor_command_publisher_;
  rclcpp::Publisher<rl_custom_messages::msg::MotorCommands>::SharedPtr sound_command_publisher_;
  rl_custom_messages::msg::RangeArray last_range_data_;
  rl_custom_messages::msg::MotorCommands motor_commands;
  rl_custom_messages::msg::MotorCommands sound_commands;
};


class ImageServer : public rclcpp::Node
{
public:
    ImageServer(std::string topic)
    : Node("image_server_" + topic)
    {
        subscription_ = this->create_subscription<sensor_msgs::msg::CompressedImage>(
        topic, 10, std::bind(&ImageServer::topic_callback, this, _1));
        service_ = this->create_service<rl_custom_messages::srv::ImageService>("get_image_data_" + topic,
        std::bind(&ImageServer::service_callback, this, _1, _2));
    }

private:
    void topic_callback(const sensor_msgs::msg::CompressedImage::SharedPtr msg)
    {
        last_image_data_ = *msg;  // Directly store the compressed image
    }

    void service_callback(
        const std::shared_ptr<rl_custom_messages::srv::ImageService::Request> request,
        std::shared_ptr<rl_custom_messages::srv::ImageService::Response> response)
    {
        response->image_data = last_image_data_; // Forward the compressed image
    }

    rclcpp::Subscription<sensor_msgs::msg::CompressedImage>::SharedPtr subscription_;
    rclcpp::Service<rl_custom_messages::srv::ImageService>::SharedPtr service_;
    sensor_msgs::msg::CompressedImage last_image_data_;
};

class AudioReceiverSubscriber : public rclcpp::Node
{
public:
    AudioReceiverSubscriber()
    : Node("audio_receiver_subscriber")
    {
        subscription_ = this->create_subscription<sensor_msgs::msg::Image>(
        "audio_data", 10, std::bind(&AudioReceiverSubscriber::topic_callback, this, _1));
    }

private:
    void topic_callback(const sensor_msgs::msg::Image::SharedPtr msg) const
    {
        RCLCPP_INFO(this->get_logger(), "Received Audio Data");
        // Here you can write the audio data to a file, send it to a speech-to-text API, etc.
        // The data is in msg->
    }

    rclcpp::Subscription<sensor_msgs::msg::Image>::SharedPtr subscription_;
};

int main(int argc, char * argv[])
{
    rclcpp::init(argc, argv);

    auto range_subscriber = std::make_shared<RangeSubscriber>();
    auto image_server_0 = std::make_shared<ImageServer>("camera_image_0");
    auto image_server_1 = std::make_shared<ImageServer>("camera_image_1");
    auto audio_receiver_subscriber = std::make_shared<AudioReceiverSubscriber>();

    rclcpp::executors::MultiThreadedExecutor executor;

    executor.add_node(range_subscriber);
    executor.add_node(image_server_0);
    executor.add_node(image_server_1);
    executor.add_node(audio_receiver_subscriber);

    executor.spin();

    rclcpp::shutdown();
    return 0;
}



