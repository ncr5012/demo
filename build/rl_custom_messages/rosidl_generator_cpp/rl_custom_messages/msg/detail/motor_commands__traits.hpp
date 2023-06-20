// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from rl_custom_messages:msg/MotorCommands.idl
// generated code does not contain a copyright notice

#ifndef RL_CUSTOM_MESSAGES__MSG__DETAIL__MOTOR_COMMANDS__TRAITS_HPP_
#define RL_CUSTOM_MESSAGES__MSG__DETAIL__MOTOR_COMMANDS__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "rl_custom_messages/msg/detail/motor_commands__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace rl_custom_messages
{

namespace msg
{

inline void to_flow_style_yaml(
  const MotorCommands & msg,
  std::ostream & out)
{
  out << "{";
  // member: commands
  {
    if (msg.commands.size() == 0) {
      out << "commands: []";
    } else {
      out << "commands: [";
      size_t pending_items = msg.commands.size();
      for (auto item : msg.commands) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const MotorCommands & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: commands
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.commands.size() == 0) {
      out << "commands: []\n";
    } else {
      out << "commands:\n";
      for (auto item : msg.commands) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const MotorCommands & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace msg

}  // namespace rl_custom_messages

namespace rosidl_generator_traits
{

[[deprecated("use rl_custom_messages::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const rl_custom_messages::msg::MotorCommands & msg,
  std::ostream & out, size_t indentation = 0)
{
  rl_custom_messages::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use rl_custom_messages::msg::to_yaml() instead")]]
inline std::string to_yaml(const rl_custom_messages::msg::MotorCommands & msg)
{
  return rl_custom_messages::msg::to_yaml(msg);
}

template<>
inline const char * data_type<rl_custom_messages::msg::MotorCommands>()
{
  return "rl_custom_messages::msg::MotorCommands";
}

template<>
inline const char * name<rl_custom_messages::msg::MotorCommands>()
{
  return "rl_custom_messages/msg/MotorCommands";
}

template<>
struct has_fixed_size<rl_custom_messages::msg::MotorCommands>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<rl_custom_messages::msg::MotorCommands>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<rl_custom_messages::msg::MotorCommands>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // RL_CUSTOM_MESSAGES__MSG__DETAIL__MOTOR_COMMANDS__TRAITS_HPP_
