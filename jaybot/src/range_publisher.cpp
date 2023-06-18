#include <chrono>
#include <functional>
#include <memory>
#include <string>
#include <vector>

#include "rclcpp/rclcpp.hpp"
#include "rl_custom_messages/msg/range_array.hpp" 

#include "jaybot/RangeSensor.h" // Assuming this is the correct include for Rangesensor

using namespace std::chrono_literals;

class RangePublisher : public rclcpp::Node
{
public:
  RangePublisher()
  : Node("range_publisher"),
  
    rangesensorl{15, 14},
    rangesensorf{3, 2},
    rangesensorr{23, 18},
    rangesensorb{22, 27}

  {
    publisher_ = this->create_publisher<rl_custom_messages::msg::RangeArray>("range_data", 10);
    timer_ = this->create_wall_timer(500ms, std::bind(&RangePublisher::timer_callback, this));
  }

private:
  void timer_callback()
  {
    auto message = rl_custom_messages::msg::RangeArray();
    /*
    Rangesensor rangesensorl{15, 14};
    Rangesensor rangesensorf{3, 2};
    Rangesensor rangesensorr{23, 18};
    Rangesensor rangesensorb{22, 27};
    */
    message.range_left = rangesensorl.Range();
    message.range_front = rangesensorf.Range();
    message.range_right = rangesensorr.Range();
    message.range_back = rangesensorb.Range();

    RCLCPP_INFO(this->get_logger(), "Publishing: '%lf', '%lf', '%lf', '%lf'", 
    message.range_left, message.range_front, message.range_right, message.range_back);
    publisher_->publish(message);
  }

  
  // Define your sensors here
  Rangesensor rangesensorl;
  Rangesensor rangesensorf;
  Rangesensor rangesensorr;
  Rangesensor rangesensorb;
  
  rclcpp::TimerBase::SharedPtr timer_;
  rclcpp::Publisher<rl_custom_messages::msg::RangeArray>::SharedPtr publisher_; // replace with your message type if not available
};

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<RangePublisher>());
  rclcpp::shutdown();
  return 0;
}

