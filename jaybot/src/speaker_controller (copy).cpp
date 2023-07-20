//ALSA is screwy on the raspberry pi - make sure to check alsamixer and the defaults if using the usb speaker



#include <rclcpp/rclcpp.hpp>
#include "rl_custom_messages/msg/motor_commands.hpp"
#include <stdlib.h> // For system()
#include <functional>


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
      for(auto i = msg->commands.begin(); i != msg->commands.end(); i++)
      {
          RCLCPP_INFO(this->get_logger(), "Received command: '%d'", *i);
      }

      auto it = std::find(msg->commands.begin(), msg->commands.end(), 1);
      if (it != msg->commands.end())
      {
          int sound_index = std::distance(msg->commands.begin(), it);
          RCLCPP_INFO(this->get_logger(), "Playing sound file index: '%d'", sound_index);
          if(sound_index != 0)  // Don't play sound for index 0
          {
            play_sound(sound_index);
          }
      }
  }

  void play_sound(int sound_index)
  {
    std::string command = "aplay /home/rlcontrol/jay_ws/jaybot/src/sounds/sound" + std::to_string(sound_index) + ".wav 2>&1";
    int result = system(command.c_str());
    if(result != 0)
    {
        RCLCPP_ERROR(this->get_logger(), "Error playing sound file. Command output:\n%s", command.c_str());
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

