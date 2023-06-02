#include <functional>
#include <memory>

#include "rclcpp/rclcpp.hpp"
#include "rl_custom_messages/msg/range_array.hpp" // replace "rl_custom_messages" with your package name

using std::placeholders::_1;

class RangeSubscriber : public rclcpp::Node
{
public:
  RangeSubscriber()
  : Node("range_subscriber")
  {
    subscription_ = this->create_subscription<rl_custom_messages::msg::RangeArray>( // replace "rl_custom_messages" with your package name
      "range_data", 10, std::bind(&RangeSubscriber::topic_callback, this, _1));
  }

private:
  void topic_callback(const rl_custom_messages::msg::RangeArray::SharedPtr msg) const // replace "rl_custom_messages" with your package name
  {
    RCLCPP_INFO(this->get_logger(), "I heard - Left: '%f', Front: '%f', Right: '%f', Back: '%f'",
                 msg->range_left, msg->range_front, msg->range_right, msg->range_back);
  }
  rclcpp::Subscription<rl_custom_messages::msg::RangeArray>::SharedPtr subscription_; // replace "rl_custom_messages" with your package name
};

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<RangeSubscriber>());
  rclcpp::shutdown();
  return 0;
}

