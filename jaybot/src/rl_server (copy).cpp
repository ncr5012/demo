#include <functional>
#include <memory>

#include "rclcpp/rclcpp.hpp"
#include "rl_custom_messages/msg/range_array.hpp" // replace "rl_custom_messages" with your package name
#include "rl_custom_messages/srv/observation_service.hpp" // replace "rl_custom_messages" with your new service message type

using std::placeholders::_1;
using std::placeholders::_2;

class RangeSubscriber : public rclcpp::Node
{
public:
  RangeSubscriber()
  : Node("range_subscriber")
  {
    subscription_ = this->create_subscription<rl_custom_messages::msg::RangeArray>( // replace "rl_custom_messages" with your package name
      "range_data", 10, std::bind(&RangeSubscriber::topic_callback, this, _1));
    service_ = this->create_service<rl_custom_messages::srv::ObservationService>("get_range_data",
    std::bind(&RangeSubscriber::service_callback, this, _1, _2));
  }

private:
  void topic_callback(const rl_custom_messages::msg::RangeArray::SharedPtr msg)// replace "rl_custom_messages" with your package name
  {
    RCLCPP_INFO(this->get_logger(), "I heard - Left: '%f', Front: '%f', Right: '%f', Back: '%f'",
                 msg->range_left, msg->range_front, msg->range_right, msg->range_back);
    last_range_data_ = *msg;
  }

  void service_callback(
    const std::shared_ptr<rl_custom_messages::srv::ObservationService::Request> request,
    std::shared_ptr<rl_custom_messages::srv::ObservationService::Response> response)
  {
    (void)request; // Silence unused parameter warning

    response->range_data = last_range_data_;
  }

  rclcpp::Subscription<rl_custom_messages::msg::RangeArray>::SharedPtr subscription_; // replace "rl_custom_messages" with your package name
  rclcpp::Service<rl_custom_messages::srv::ObservationService>::SharedPtr service_;
  rl_custom_messages::msg::RangeArray last_range_data_;
};

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<RangeSubscriber>());
  rclcpp::shutdown();
  return 0;
}


