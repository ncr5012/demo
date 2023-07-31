// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from rl_custom_messages:srv/EmotionService.idl
// generated code does not contain a copyright notice

#ifndef RL_CUSTOM_MESSAGES__SRV__DETAIL__EMOTION_SERVICE__TRAITS_HPP_
#define RL_CUSTOM_MESSAGES__SRV__DETAIL__EMOTION_SERVICE__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "rl_custom_messages/srv/detail/emotion_service__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace rl_custom_messages
{

namespace srv
{

inline void to_flow_style_yaml(
  const EmotionService_Request & msg,
  std::ostream & out)
{
  (void)msg;
  out << "null";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const EmotionService_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  (void)msg;
  (void)indentation;
  out << "null\n";
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const EmotionService_Request & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace rl_custom_messages

namespace rosidl_generator_traits
{

[[deprecated("use rl_custom_messages::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const rl_custom_messages::srv::EmotionService_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  rl_custom_messages::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use rl_custom_messages::srv::to_yaml() instead")]]
inline std::string to_yaml(const rl_custom_messages::srv::EmotionService_Request & msg)
{
  return rl_custom_messages::srv::to_yaml(msg);
}

template<>
inline const char * data_type<rl_custom_messages::srv::EmotionService_Request>()
{
  return "rl_custom_messages::srv::EmotionService_Request";
}

template<>
inline const char * name<rl_custom_messages::srv::EmotionService_Request>()
{
  return "rl_custom_messages/srv/EmotionService_Request";
}

template<>
struct has_fixed_size<rl_custom_messages::srv::EmotionService_Request>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<rl_custom_messages::srv::EmotionService_Request>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<rl_custom_messages::srv::EmotionService_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rl_custom_messages
{

namespace srv
{

inline void to_flow_style_yaml(
  const EmotionService_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: results
  {
    out << "results: ";
    rosidl_generator_traits::value_to_yaml(msg.results, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const EmotionService_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: results
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "results: ";
    rosidl_generator_traits::value_to_yaml(msg.results, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const EmotionService_Response & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace rl_custom_messages

namespace rosidl_generator_traits
{

[[deprecated("use rl_custom_messages::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const rl_custom_messages::srv::EmotionService_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  rl_custom_messages::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use rl_custom_messages::srv::to_yaml() instead")]]
inline std::string to_yaml(const rl_custom_messages::srv::EmotionService_Response & msg)
{
  return rl_custom_messages::srv::to_yaml(msg);
}

template<>
inline const char * data_type<rl_custom_messages::srv::EmotionService_Response>()
{
  return "rl_custom_messages::srv::EmotionService_Response";
}

template<>
inline const char * name<rl_custom_messages::srv::EmotionService_Response>()
{
  return "rl_custom_messages/srv/EmotionService_Response";
}

template<>
struct has_fixed_size<rl_custom_messages::srv::EmotionService_Response>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<rl_custom_messages::srv::EmotionService_Response>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<rl_custom_messages::srv::EmotionService_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<rl_custom_messages::srv::EmotionService>()
{
  return "rl_custom_messages::srv::EmotionService";
}

template<>
inline const char * name<rl_custom_messages::srv::EmotionService>()
{
  return "rl_custom_messages/srv/EmotionService";
}

template<>
struct has_fixed_size<rl_custom_messages::srv::EmotionService>
  : std::integral_constant<
    bool,
    has_fixed_size<rl_custom_messages::srv::EmotionService_Request>::value &&
    has_fixed_size<rl_custom_messages::srv::EmotionService_Response>::value
  >
{
};

template<>
struct has_bounded_size<rl_custom_messages::srv::EmotionService>
  : std::integral_constant<
    bool,
    has_bounded_size<rl_custom_messages::srv::EmotionService_Request>::value &&
    has_bounded_size<rl_custom_messages::srv::EmotionService_Response>::value
  >
{
};

template<>
struct is_service<rl_custom_messages::srv::EmotionService>
  : std::true_type
{
};

template<>
struct is_service_request<rl_custom_messages::srv::EmotionService_Request>
  : std::true_type
{
};

template<>
struct is_service_response<rl_custom_messages::srv::EmotionService_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // RL_CUSTOM_MESSAGES__SRV__DETAIL__EMOTION_SERVICE__TRAITS_HPP_
