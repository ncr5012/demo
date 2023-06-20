// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from rl_custom_messages:msg/MotorCommands.idl
// generated code does not contain a copyright notice

#ifndef RL_CUSTOM_MESSAGES__MSG__DETAIL__MOTOR_COMMANDS__BUILDER_HPP_
#define RL_CUSTOM_MESSAGES__MSG__DETAIL__MOTOR_COMMANDS__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "rl_custom_messages/msg/detail/motor_commands__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace rl_custom_messages
{

namespace msg
{

namespace builder
{

class Init_MotorCommands_commands
{
public:
  Init_MotorCommands_commands()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::rl_custom_messages::msg::MotorCommands commands(::rl_custom_messages::msg::MotorCommands::_commands_type arg)
  {
    msg_.commands = std::move(arg);
    return std::move(msg_);
  }

private:
  ::rl_custom_messages::msg::MotorCommands msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::rl_custom_messages::msg::MotorCommands>()
{
  return rl_custom_messages::msg::builder::Init_MotorCommands_commands();
}

}  // namespace rl_custom_messages

#endif  // RL_CUSTOM_MESSAGES__MSG__DETAIL__MOTOR_COMMANDS__BUILDER_HPP_
