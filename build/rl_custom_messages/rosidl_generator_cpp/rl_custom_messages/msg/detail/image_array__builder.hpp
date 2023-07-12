// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from rl_custom_messages:msg/ImageArray.idl
// generated code does not contain a copyright notice

#ifndef RL_CUSTOM_MESSAGES__MSG__DETAIL__IMAGE_ARRAY__BUILDER_HPP_
#define RL_CUSTOM_MESSAGES__MSG__DETAIL__IMAGE_ARRAY__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "rl_custom_messages/msg/detail/image_array__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace rl_custom_messages
{

namespace msg
{

namespace builder
{

class Init_ImageArray_data
{
public:
  explicit Init_ImageArray_data(::rl_custom_messages::msg::ImageArray & msg)
  : msg_(msg)
  {}
  ::rl_custom_messages::msg::ImageArray data(::rl_custom_messages::msg::ImageArray::_data_type arg)
  {
    msg_.data = std::move(arg);
    return std::move(msg_);
  }

private:
  ::rl_custom_messages::msg::ImageArray msg_;
};

class Init_ImageArray_encoding
{
public:
  explicit Init_ImageArray_encoding(::rl_custom_messages::msg::ImageArray & msg)
  : msg_(msg)
  {}
  Init_ImageArray_data encoding(::rl_custom_messages::msg::ImageArray::_encoding_type arg)
  {
    msg_.encoding = std::move(arg);
    return Init_ImageArray_data(msg_);
  }

private:
  ::rl_custom_messages::msg::ImageArray msg_;
};

class Init_ImageArray_width
{
public:
  explicit Init_ImageArray_width(::rl_custom_messages::msg::ImageArray & msg)
  : msg_(msg)
  {}
  Init_ImageArray_encoding width(::rl_custom_messages::msg::ImageArray::_width_type arg)
  {
    msg_.width = std::move(arg);
    return Init_ImageArray_encoding(msg_);
  }

private:
  ::rl_custom_messages::msg::ImageArray msg_;
};

class Init_ImageArray_height
{
public:
  Init_ImageArray_height()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ImageArray_width height(::rl_custom_messages::msg::ImageArray::_height_type arg)
  {
    msg_.height = std::move(arg);
    return Init_ImageArray_width(msg_);
  }

private:
  ::rl_custom_messages::msg::ImageArray msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::rl_custom_messages::msg::ImageArray>()
{
  return rl_custom_messages::msg::builder::Init_ImageArray_height();
}

}  // namespace rl_custom_messages

#endif  // RL_CUSTOM_MESSAGES__MSG__DETAIL__IMAGE_ARRAY__BUILDER_HPP_
