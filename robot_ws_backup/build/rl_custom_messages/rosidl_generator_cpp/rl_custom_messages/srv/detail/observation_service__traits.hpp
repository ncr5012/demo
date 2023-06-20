// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from rl_custom_messages:srv/ObservationService.idl
// generated code does not contain a copyright notice

#ifndef RL_CUSTOM_MESSAGES__SRV__DETAIL__OBSERVATION_SERVICE__TRAITS_HPP_
#define RL_CUSTOM_MESSAGES__SRV__DETAIL__OBSERVATION_SERVICE__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "rl_custom_messages/srv/detail/observation_service__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace rl_custom_messages
{

namespace srv
{

inline void to_flow_style_yaml(
  const ObservationService_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: action
  {
    if (msg.action.size() == 0) {
      out << "action: []";
    } else {
      out << "action: [";
      size_t pending_items = msg.action.size();
      for (auto item : msg.action) {
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
  const ObservationService_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: action
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.action.size() == 0) {
      out << "action: []\n";
    } else {
      out << "action:\n";
      for (auto item : msg.action) {
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

inline std::string to_yaml(const ObservationService_Request & msg, bool use_flow_style = false)
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
  const rl_custom_messages::srv::ObservationService_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  rl_custom_messages::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use rl_custom_messages::srv::to_yaml() instead")]]
inline std::string to_yaml(const rl_custom_messages::srv::ObservationService_Request & msg)
{
  return rl_custom_messages::srv::to_yaml(msg);
}

template<>
inline const char * data_type<rl_custom_messages::srv::ObservationService_Request>()
{
  return "rl_custom_messages::srv::ObservationService_Request";
}

template<>
inline const char * name<rl_custom_messages::srv::ObservationService_Request>()
{
  return "rl_custom_messages/srv/ObservationService_Request";
}

template<>
struct has_fixed_size<rl_custom_messages::srv::ObservationService_Request>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<rl_custom_messages::srv::ObservationService_Request>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<rl_custom_messages::srv::ObservationService_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'range_data'
#include "rl_custom_messages/msg/detail/range_array__traits.hpp"

namespace rl_custom_messages
{

namespace srv
{

inline void to_flow_style_yaml(
  const ObservationService_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: range_data
  {
    out << "range_data: ";
    to_flow_style_yaml(msg.range_data, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const ObservationService_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: range_data
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "range_data:\n";
    to_block_style_yaml(msg.range_data, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const ObservationService_Response & msg, bool use_flow_style = false)
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
  const rl_custom_messages::srv::ObservationService_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  rl_custom_messages::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use rl_custom_messages::srv::to_yaml() instead")]]
inline std::string to_yaml(const rl_custom_messages::srv::ObservationService_Response & msg)
{
  return rl_custom_messages::srv::to_yaml(msg);
}

template<>
inline const char * data_type<rl_custom_messages::srv::ObservationService_Response>()
{
  return "rl_custom_messages::srv::ObservationService_Response";
}

template<>
inline const char * name<rl_custom_messages::srv::ObservationService_Response>()
{
  return "rl_custom_messages/srv/ObservationService_Response";
}

template<>
struct has_fixed_size<rl_custom_messages::srv::ObservationService_Response>
  : std::integral_constant<bool, has_fixed_size<rl_custom_messages::msg::RangeArray>::value> {};

template<>
struct has_bounded_size<rl_custom_messages::srv::ObservationService_Response>
  : std::integral_constant<bool, has_bounded_size<rl_custom_messages::msg::RangeArray>::value> {};

template<>
struct is_message<rl_custom_messages::srv::ObservationService_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<rl_custom_messages::srv::ObservationService>()
{
  return "rl_custom_messages::srv::ObservationService";
}

template<>
inline const char * name<rl_custom_messages::srv::ObservationService>()
{
  return "rl_custom_messages/srv/ObservationService";
}

template<>
struct has_fixed_size<rl_custom_messages::srv::ObservationService>
  : std::integral_constant<
    bool,
    has_fixed_size<rl_custom_messages::srv::ObservationService_Request>::value &&
    has_fixed_size<rl_custom_messages::srv::ObservationService_Response>::value
  >
{
};

template<>
struct has_bounded_size<rl_custom_messages::srv::ObservationService>
  : std::integral_constant<
    bool,
    has_bounded_size<rl_custom_messages::srv::ObservationService_Request>::value &&
    has_bounded_size<rl_custom_messages::srv::ObservationService_Response>::value
  >
{
};

template<>
struct is_service<rl_custom_messages::srv::ObservationService>
  : std::true_type
{
};

template<>
struct is_service_request<rl_custom_messages::srv::ObservationService_Request>
  : std::true_type
{
};

template<>
struct is_service_response<rl_custom_messages::srv::ObservationService_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // RL_CUSTOM_MESSAGES__SRV__DETAIL__OBSERVATION_SERVICE__TRAITS_HPP_
