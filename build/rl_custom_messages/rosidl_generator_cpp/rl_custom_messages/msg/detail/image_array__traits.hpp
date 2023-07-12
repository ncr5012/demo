// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from rl_custom_messages:msg/ImageArray.idl
// generated code does not contain a copyright notice

#ifndef RL_CUSTOM_MESSAGES__MSG__DETAIL__IMAGE_ARRAY__TRAITS_HPP_
#define RL_CUSTOM_MESSAGES__MSG__DETAIL__IMAGE_ARRAY__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "rl_custom_messages/msg/detail/image_array__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace rl_custom_messages
{

namespace msg
{

inline void to_flow_style_yaml(
  const ImageArray & msg,
  std::ostream & out)
{
  out << "{";
  // member: height
  {
    out << "height: ";
    rosidl_generator_traits::value_to_yaml(msg.height, out);
    out << ", ";
  }

  // member: width
  {
    out << "width: ";
    rosidl_generator_traits::value_to_yaml(msg.width, out);
    out << ", ";
  }

  // member: encoding
  {
    out << "encoding: ";
    rosidl_generator_traits::value_to_yaml(msg.encoding, out);
    out << ", ";
  }

  // member: data
  {
    if (msg.data.size() == 0) {
      out << "data: []";
    } else {
      out << "data: [";
      size_t pending_items = msg.data.size();
      for (auto item : msg.data) {
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
  const ImageArray & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: height
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "height: ";
    rosidl_generator_traits::value_to_yaml(msg.height, out);
    out << "\n";
  }

  // member: width
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "width: ";
    rosidl_generator_traits::value_to_yaml(msg.width, out);
    out << "\n";
  }

  // member: encoding
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "encoding: ";
    rosidl_generator_traits::value_to_yaml(msg.encoding, out);
    out << "\n";
  }

  // member: data
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.data.size() == 0) {
      out << "data: []\n";
    } else {
      out << "data:\n";
      for (auto item : msg.data) {
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

inline std::string to_yaml(const ImageArray & msg, bool use_flow_style = false)
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
  const rl_custom_messages::msg::ImageArray & msg,
  std::ostream & out, size_t indentation = 0)
{
  rl_custom_messages::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use rl_custom_messages::msg::to_yaml() instead")]]
inline std::string to_yaml(const rl_custom_messages::msg::ImageArray & msg)
{
  return rl_custom_messages::msg::to_yaml(msg);
}

template<>
inline const char * data_type<rl_custom_messages::msg::ImageArray>()
{
  return "rl_custom_messages::msg::ImageArray";
}

template<>
inline const char * name<rl_custom_messages::msg::ImageArray>()
{
  return "rl_custom_messages/msg/ImageArray";
}

template<>
struct has_fixed_size<rl_custom_messages::msg::ImageArray>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<rl_custom_messages::msg::ImageArray>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<rl_custom_messages::msg::ImageArray>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // RL_CUSTOM_MESSAGES__MSG__DETAIL__IMAGE_ARRAY__TRAITS_HPP_
