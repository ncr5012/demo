// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from rl_custom_messages:msg/RangeArray.idl
// generated code does not contain a copyright notice

#ifndef RL_CUSTOM_MESSAGES__MSG__DETAIL__RANGE_ARRAY__BUILDER_HPP_
#define RL_CUSTOM_MESSAGES__MSG__DETAIL__RANGE_ARRAY__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "rl_custom_messages/msg/detail/range_array__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace rl_custom_messages
{

namespace msg
{

namespace builder
{

class Init_RangeArray_range_back
{
public:
  explicit Init_RangeArray_range_back(::rl_custom_messages::msg::RangeArray & msg)
  : msg_(msg)
  {}
  ::rl_custom_messages::msg::RangeArray range_back(::rl_custom_messages::msg::RangeArray::_range_back_type arg)
  {
    msg_.range_back = std::move(arg);
    return std::move(msg_);
  }

private:
  ::rl_custom_messages::msg::RangeArray msg_;
};

class Init_RangeArray_range_right
{
public:
  explicit Init_RangeArray_range_right(::rl_custom_messages::msg::RangeArray & msg)
  : msg_(msg)
  {}
  Init_RangeArray_range_back range_right(::rl_custom_messages::msg::RangeArray::_range_right_type arg)
  {
    msg_.range_right = std::move(arg);
    return Init_RangeArray_range_back(msg_);
  }

private:
  ::rl_custom_messages::msg::RangeArray msg_;
};

class Init_RangeArray_range_front
{
public:
  explicit Init_RangeArray_range_front(::rl_custom_messages::msg::RangeArray & msg)
  : msg_(msg)
  {}
  Init_RangeArray_range_right range_front(::rl_custom_messages::msg::RangeArray::_range_front_type arg)
  {
    msg_.range_front = std::move(arg);
    return Init_RangeArray_range_right(msg_);
  }

private:
  ::rl_custom_messages::msg::RangeArray msg_;
};

class Init_RangeArray_range_left
{
public:
  Init_RangeArray_range_left()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_RangeArray_range_front range_left(::rl_custom_messages::msg::RangeArray::_range_left_type arg)
  {
    msg_.range_left = std::move(arg);
    return Init_RangeArray_range_front(msg_);
  }

private:
  ::rl_custom_messages::msg::RangeArray msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::rl_custom_messages::msg::RangeArray>()
{
  return rl_custom_messages::msg::builder::Init_RangeArray_range_left();
}

}  // namespace rl_custom_messages

#endif  // RL_CUSTOM_MESSAGES__MSG__DETAIL__RANGE_ARRAY__BUILDER_HPP_
