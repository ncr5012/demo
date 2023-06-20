#include "rclcpp/rclcpp.hpp"
#include "rl_custom_messages/msg/range_array.hpp"
#include "rl_custom_messages/msg/motor_commands.hpp"
#include "rl_custom_messages/srv/observation_service.hpp"

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

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<RangeSubscriber>());
  rclcpp::shutdown();
  return 0;
}



