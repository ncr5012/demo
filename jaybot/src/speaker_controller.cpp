#include <rclcpp/rclcpp.hpp>
#include "rl_custom_messages/msg/motor_commands.hpp"
#include <stdlib.h> // For system()
#include <functional>
#include <sstream>

class SoundPlayer : public rclcpp::Node
{
public:
  SoundPlayer()
  : Node("sound_player")
  {
    subscription_ = this->create_subscription<rl_custom_messages::msg::MotorCommands>(
      "sound_commands", 10, std::bind(&SoundPlayer::topic_callback, this, std::placeholders::_1));
  }

private:
  void topic_callback(const rl_custom_messages::msg::MotorCommands::SharedPtr msg)
  {
    if(msg->commands.empty())
    {
      RCLCPP_INFO(this->get_logger(), "Received empty command list");
      return;
    }

    int sound_index = msg->commands[0];

    std::stringstream ss;
    ss << sound_index;
    RCLCPP_INFO(this->get_logger(), "Received command: '%s'", ss.str().c_str());

    if(sound_index == 0)  // Do nothing for command 0
    {
      RCLCPP_INFO(this->get_logger(), "Received command 0, doing nothing");
      return;
    }
    else
    {
      RCLCPP_INFO(this->get_logger(), "Playing sound file index: '%d'", sound_index);
      play_sound(sound_index);  // Pass the command value as the sound index
    }
  }

  void play_sound(int sound_index)
  {
    std::string command;
    command = "aplay /home/rlcontrol/jay_ws/jaybot/src/sounds/sound" + std::to_string(sound_index) + ".wav";

    RCLCPP_INFO(this->get_logger(), "Executing command: '%s'", command.c_str());
    int result = system(command.c_str());
    if(result == -1)
    {
      RCLCPP_ERROR(this->get_logger(), "Error executing system command");
    }
    else if(result != 0)
    {
      RCLCPP_ERROR(this->get_logger(), "Error playing sound file with exit status: %d", WEXITSTATUS(result));
    }
  }

  rclcpp::Subscription<rl_custom_messages::msg::MotorCommands>::SharedPtr subscription_;
};

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<SoundPlayer>());
  rclcpp::shutdown();
  return 0;
}
