// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from rl_custom_messages:msg/RangeArray.idl
// generated code does not contain a copyright notice

#ifndef RL_CUSTOM_MESSAGES__MSG__DETAIL__RANGE_ARRAY__STRUCT_HPP_
#define RL_CUSTOM_MESSAGES__MSG__DETAIL__RANGE_ARRAY__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__rl_custom_messages__msg__RangeArray __attribute__((deprecated))
#else
# define DEPRECATED__rl_custom_messages__msg__RangeArray __declspec(deprecated)
#endif

namespace rl_custom_messages
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct RangeArray_
{
  using Type = RangeArray_<ContainerAllocator>;

  explicit RangeArray_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->range_left = 0.0;
      this->range_front = 0.0;
      this->range_right = 0.0;
      this->range_back = 0.0;
    }
  }

  explicit RangeArray_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->range_left = 0.0;
      this->range_front = 0.0;
      this->range_right = 0.0;
      this->range_back = 0.0;
    }
  }

  // field types and members
  using _range_left_type =
    double;
  _range_left_type range_left;
  using _range_front_type =
    double;
  _range_front_type range_front;
  using _range_right_type =
    double;
  _range_right_type range_right;
  using _range_back_type =
    double;
  _range_back_type range_back;

  // setters for named parameter idiom
  Type & set__range_left(
    const double & _arg)
  {
    this->range_left = _arg;
    return *this;
  }
  Type & set__range_front(
    const double & _arg)
  {
    this->range_front = _arg;
    return *this;
  }
  Type & set__range_right(
    const double & _arg)
  {
    this->range_right = _arg;
    return *this;
  }
  Type & set__range_back(
    const double & _arg)
  {
    this->range_back = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    rl_custom_messages::msg::RangeArray_<ContainerAllocator> *;
  using ConstRawPtr =
    const rl_custom_messages::msg::RangeArray_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<rl_custom_messages::msg::RangeArray_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<rl_custom_messages::msg::RangeArray_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      rl_custom_messages::msg::RangeArray_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<rl_custom_messages::msg::RangeArray_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      rl_custom_messages::msg::RangeArray_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<rl_custom_messages::msg::RangeArray_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<rl_custom_messages::msg::RangeArray_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<rl_custom_messages::msg::RangeArray_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__rl_custom_messages__msg__RangeArray
    std::shared_ptr<rl_custom_messages::msg::RangeArray_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__rl_custom_messages__msg__RangeArray
    std::shared_ptr<rl_custom_messages::msg::RangeArray_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const RangeArray_ & other) const
  {
    if (this->range_left != other.range_left) {
      return false;
    }
    if (this->range_front != other.range_front) {
      return false;
    }
    if (this->range_right != other.range_right) {
      return false;
    }
    if (this->range_back != other.range_back) {
      return false;
    }
    return true;
  }
  bool operator!=(const RangeArray_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct RangeArray_

// alias to use template instance with default allocator
using RangeArray =
  rl_custom_messages::msg::RangeArray_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace rl_custom_messages

#endif  // RL_CUSTOM_MESSAGES__MSG__DETAIL__RANGE_ARRAY__STRUCT_HPP_
