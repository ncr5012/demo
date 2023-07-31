// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from rl_custom_messages:srv/EmotionService.idl
// generated code does not contain a copyright notice

#ifndef RL_CUSTOM_MESSAGES__SRV__DETAIL__EMOTION_SERVICE__BUILDER_HPP_
#define RL_CUSTOM_MESSAGES__SRV__DETAIL__EMOTION_SERVICE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "rl_custom_messages/srv/detail/emotion_service__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace rl_custom_messages
{

namespace srv
{


}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::rl_custom_messages::srv::EmotionService_Request>()
{
  return ::rl_custom_messages::srv::EmotionService_Request(rosidl_runtime_cpp::MessageInitialization::ZERO);
}

}  // namespace rl_custom_messages


namespace rl_custom_messages
{

namespace srv
{

namespace builder
{

class Init_EmotionService_Response_results
{
public:
  Init_EmotionService_Response_results()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::rl_custom_messages::srv::EmotionService_Response results(::rl_custom_messages::srv::EmotionService_Response::_results_type arg)
  {
    msg_.results = std::move(arg);
    return std::move(msg_);
  }

private:
  ::rl_custom_messages::srv::EmotionService_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::rl_custom_messages::srv::EmotionService_Response>()
{
  return rl_custom_messages::srv::builder::Init_EmotionService_Response_results();
}

}  // namespace rl_custom_messages

#endif  // RL_CUSTOM_MESSAGES__SRV__DETAIL__EMOTION_SERVICE__BUILDER_HPP_
