#include "rclcpp/rclcpp.hpp"
#include "rl_custom_messages/msg/range_array.hpp"
#include "rl_custom_messages/msg/motor_commands.hpp"
#include "rl_custom_messages/msg/image_array.hpp"
#include "rl_custom_messages/srv/observation_service.hpp"
#include "rl_custom_messages/srv/image_service.hpp"
#include <sensor_msgs/msg/image.hpp>
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
    motor_commands.commands.clear(); // Clear previous commands
    std::copy(request->action.begin(), request->action.end(), std::back_inserter(motor_commands.commands));
    std::string commands_str = "Received motor_commands: ";
    for (const auto& command : motor_commands.commands)
    {
        commands_str += std::to_string(command) + ", ";
    }
    RCLCPP_INFO(this->get_logger(), commands_str.c_str());

    response->range_data = last_range_data_;
    motor_command_publisher_->publish(motor_commands);
  }

  rclcpp::Subscription<rl_custom_messages::msg::RangeArray>::SharedPtr subscription_;
  rclcpp::Service<rl_custom_messages::srv::ObservationService>::SharedPtr service_;
  rclcpp::Publisher<rl_custom_messages::msg::MotorCommands>::SharedPtr motor_command_publisher_;
  rl_custom_messages::msg::RangeArray last_range_data_;
  rl_custom_messages::msg::MotorCommands motor_commands;
};

class ImageServer : public rclcpp::Node
{
public:
    ImageServer(std::string topic)
    : Node("image_server_" + topic)
    {
        subscription_ = this->create_subscription<sensor_msgs::msg::Image>(
        topic, 10, std::bind(&ImageServer::topic_callback, this, _1));
        service_ = this->create_service<rl_custom_messages::srv::ImageService>("get_image_data_" + topic,
        std::bind(&ImageServer::service_callback, this, _1, _2));
    }

private:
    void topic_callback(const sensor_msgs::msg::Image::SharedPtr msg)
    {
        cv_bridge::CvImagePtr cv_ptr;
        try
        {
            cv_ptr = cv_bridge::toCvCopy(msg, sensor_msgs::image_encodings::BGR8);
        }
        catch (cv_bridge::Exception& e)
        {
            RCLCPP_ERROR(this->get_logger(), "cv_bridge exception: %s", e.what());
            return;
        }
        last_image_data_ = cv_ptr->image;
    }

    void service_callback(
        const std::shared_ptr<rl_custom_messages::srv::ImageService::Request> request,
        std::shared_ptr<rl_custom_messages::srv::ImageService::Response> response)
    {
        rl_custom_messages::msg::ImageArray img_msg;
        img_msg.data.assign(last_image_data_.data, last_image_data_.data + last_image_data_.total()*last_image_data_.channels());
        response->image_data = img_msg;
    }

    rclcpp::Subscription<sensor_msgs::msg::Image>::SharedPtr subscription_;
    rclcpp::Service<rl_custom_messages::srv::ImageService>::SharedPtr service_;
    cv::Mat last_image_data_;
    std::thread display_thread_;
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
        // The data is in msg->```
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



