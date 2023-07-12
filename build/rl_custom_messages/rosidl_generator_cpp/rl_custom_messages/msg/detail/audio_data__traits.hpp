// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from rl_custom_messages:msg/AudioData.idl
// generated code does not contain a copyright notice

#ifndef RL_CUSTOM_MESSAGES__MSG__DETAIL__AUDIO_DATA__TRAITS_HPP_
#define RL_CUSTOM_MESSAGES__MSG__DETAIL__AUDIO_DATA__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "rl_custom_messages/msg/detail/audio_data__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace rl_custom_messages
{

namespace msg
{

inline void to_flow_style_yaml(
  const AudioData & msg,
  std::ostream & out)
{
  out << "{";
  // member: sample_rate
  {
    out << "sample_rate: ";
    rosidl_generator_traits::value_to_yaml(msg.sample_rate, out);
    out << ", ";
  }

  // member: channels
  {
    out << "channels: ";
    rosidl_generator_traits::value_to_yaml(msg.channels, out);
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
  const AudioData & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: sample_rate
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "sample_rate: ";
    rosidl_generator_traits::value_to_yaml(msg.sample_rate, out);
    out << "\n";
  }

  // member: channels
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "channels: ";
    rosidl_generator_traits::value_to_yaml(msg.channels, out);
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

inline std::string to_yaml(const AudioData & msg, bool use_flow_style = false)
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
  const rl_custom_messages::msg::AudioData & msg,
  std::ostream & out, size_t indentation = 0)
{
  rl_custom_messages::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use rl_custom_messages::msg::to_yaml() instead")]]
inline std::string to_yaml(const rl_custom_messages::msg::AudioData & msg)
{
  return rl_custom_messages::msg::to_yaml(msg);
}

template<>
inline const char * data_type<rl_custom_messages::msg::AudioData>()
{
  return "rl_custom_messages::msg::AudioData";
}

template<>
inline const char * name<rl_custom_messages::msg::AudioData>()
{
  return "rl_custom_messages/msg/AudioData";
}

template<>
struct has_fixed_size<rl_custom_messages::msg::AudioData>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<rl_custom_messages::msg::AudioData>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<rl_custom_messages::msg::AudioData>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // RL_CUSTOM_MESSAGES__MSG__DETAIL__AUDIO_DATA__TRAITS_HPP_
