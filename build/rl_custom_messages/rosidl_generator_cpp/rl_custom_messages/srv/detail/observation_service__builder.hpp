// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from rl_custom_messages:srv/ObservationService.idl
// generated code does not contain a copyright notice

#ifndef RL_CUSTOM_MESSAGES__SRV__DETAIL__OBSERVATION_SERVICE__BUILDER_HPP_
#define RL_CUSTOM_MESSAGES__SRV__DETAIL__OBSERVATION_SERVICE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "rl_custom_messages/srv/detail/observation_service__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace rl_custom_messages
{

namespace srv
{

namespace builder
{

class Init_ObservationService_Request_sound_action
{
public:
  explicit Init_ObservationService_Request_sound_action(::rl_custom_messages::srv::ObservationService_Request & msg)
  : msg_(msg)
  {}
  ::rl_custom_messages::srv::ObservationService_Request sound_action(::rl_custom_messages::srv::ObservationService_Request::_sound_action_type arg)
  {
    msg_.sound_action = std::move(arg);
    return std::move(msg_);
  }

private:
  ::rl_custom_messages::srv::ObservationService_Request msg_;
};

class Init_ObservationService_Request_motor_action
{
public:
  Init_ObservationService_Request_motor_action()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ObservationService_Request_sound_action motor_action(::rl_custom_messages::srv::ObservationService_Request::_motor_action_type arg)
  {
    msg_.motor_action = std::move(arg);
    return Init_ObservationService_Request_sound_action(msg_);
  }

private:
  ::rl_custom_messages::srv::ObservationService_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::rl_custom_messages::srv::ObservationService_Request>()
{
  return rl_custom_messages::srv::builder::Init_ObservationService_Request_motor_action();
}

}  // namespace rl_custom_messages


namespace rl_custom_messages
{

namespace srv
{

namespace builder
{

class Init_ObservationService_Response_range_data
{
public:
  Init_ObservationService_Response_range_data()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::rl_custom_messages::srv::ObservationService_Response range_data(::rl_custom_messages::srv::ObservationService_Response::_range_data_type arg)
  {
    msg_.range_data = std::move(arg);
    return std::move(msg_);
  }

private:
  ::rl_custom_messages::srv::ObservationService_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::rl_custom_messages::srv::ObservationService_Response>()
{
  return rl_custom_messages::srv::builder::Init_ObservationService_Response_range_data();
}

}  // namespace rl_custom_messages

#endif  // RL_CUSTOM_MESSAGES__SRV__DETAIL__OBSERVATION_SERVICE__BUILDER_HPP_
