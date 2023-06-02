// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from rl_custom_messages:msg/RangeArray.idl
// generated code does not contain a copyright notice

#ifndef RL_CUSTOM_MESSAGES__MSG__DETAIL__RANGE_ARRAY__TRAITS_HPP_
#define RL_CUSTOM_MESSAGES__MSG__DETAIL__RANGE_ARRAY__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "rl_custom_messages/msg/detail/range_array__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace rl_custom_messages
{

namespace msg
{

inline void to_flow_style_yaml(
  const RangeArray & msg,
  std::ostream & out)
{
  out << "{";
  // member: range_left
  {
    out << "range_left: ";
    rosidl_generator_traits::value_to_yaml(msg.range_left, out);
    out << ", ";
  }

  // member: range_front
  {
    out << "range_front: ";
    rosidl_generator_traits::value_to_yaml(msg.range_front, out);
    out << ", ";
  }

  // member: range_right
  {
    out << "range_right: ";
    rosidl_generator_traits::value_to_yaml(msg.range_right, out);
    out << ", ";
  }

  // member: range_back
  {
    out << "range_back: ";
    rosidl_generator_traits::value_to_yaml(msg.range_back, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const RangeArray & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: range_left
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "range_left: ";
    rosidl_generator_traits::value_to_yaml(msg.range_left, out);
    out << "\n";
  }

  // member: range_front
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "range_front: ";
    rosidl_generator_traits::value_to_yaml(msg.range_front, out);
    out << "\n";
  }

  // member: range_right
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "range_right: ";
    rosidl_generator_traits::value_to_yaml(msg.range_right, out);
    out << "\n";
  }

  // member: range_back
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "range_back: ";
    rosidl_generator_traits::value_to_yaml(msg.range_back, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const RangeArray & msg, bool use_flow_style = false)
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
  const rl_custom_messages::msg::RangeArray & msg,
  std::ostream & out, size_t indentation = 0)
{
  rl_custom_messages::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use rl_custom_messages::msg::to_yaml() instead")]]
inline std::string to_yaml(const rl_custom_messages::msg::RangeArray & msg)
{
  return rl_custom_messages::msg::to_yaml(msg);
}

template<>
inline const char * data_type<rl_custom_messages::msg::RangeArray>()
{
  return "rl_custom_messages::msg::RangeArray";
}

template<>
inline const char * name<rl_custom_messages::msg::RangeArray>()
{
  return "rl_custom_messages/msg/RangeArray";
}

template<>
struct has_fixed_size<rl_custom_messages::msg::RangeArray>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<rl_custom_messages::msg::RangeArray>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<rl_custom_messages::msg::RangeArray>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // RL_CUSTOM_MESSAGES__MSG__DETAIL__RANGE_ARRAY__TRAITS_HPP_
