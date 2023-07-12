// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from rl_custom_messages:msg/AudioData.idl
// generated code does not contain a copyright notice

#ifndef RL_CUSTOM_MESSAGES__MSG__DETAIL__AUDIO_DATA__BUILDER_HPP_
#define RL_CUSTOM_MESSAGES__MSG__DETAIL__AUDIO_DATA__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "rl_custom_messages/msg/detail/audio_data__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace rl_custom_messages
{

namespace msg
{

namespace builder
{

class Init_AudioData_data
{
public:
  explicit Init_AudioData_data(::rl_custom_messages::msg::AudioData & msg)
  : msg_(msg)
  {}
  ::rl_custom_messages::msg::AudioData data(::rl_custom_messages::msg::AudioData::_data_type arg)
  {
    msg_.data = std::move(arg);
    return std::move(msg_);
  }

private:
  ::rl_custom_messages::msg::AudioData msg_;
};

class Init_AudioData_channels
{
public:
  explicit Init_AudioData_channels(::rl_custom_messages::msg::AudioData & msg)
  : msg_(msg)
  {}
  Init_AudioData_data channels(::rl_custom_messages::msg::AudioData::_channels_type arg)
  {
    msg_.channels = std::move(arg);
    return Init_AudioData_data(msg_);
  }

private:
  ::rl_custom_messages::msg::AudioData msg_;
};

class Init_AudioData_sample_rate
{
public:
  Init_AudioData_sample_rate()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_AudioData_channels sample_rate(::rl_custom_messages::msg::AudioData::_sample_rate_type arg)
  {
    msg_.sample_rate = std::move(arg);
    return Init_AudioData_channels(msg_);
  }

private:
  ::rl_custom_messages::msg::AudioData msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::rl_custom_messages::msg::AudioData>()
{
  return rl_custom_messages::msg::builder::Init_AudioData_sample_rate();
}

}  // namespace rl_custom_messages

#endif  // RL_CUSTOM_MESSAGES__MSG__DETAIL__AUDIO_DATA__BUILDER_HPP_
