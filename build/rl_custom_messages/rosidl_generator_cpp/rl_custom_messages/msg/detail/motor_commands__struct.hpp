// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from rl_custom_messages:msg/MotorCommands.idl
// generated code does not contain a copyright notice

#ifndef RL_CUSTOM_MESSAGES__MSG__DETAIL__MOTOR_COMMANDS__STRUCT_HPP_
#define RL_CUSTOM_MESSAGES__MSG__DETAIL__MOTOR_COMMANDS__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__rl_custom_messages__msg__MotorCommands __attribute__((deprecated))
#else
# define DEPRECATED__rl_custom_messages__msg__MotorCommands __declspec(deprecated)
#endif

namespace rl_custom_messages
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct MotorCommands_
{
  using Type = MotorCommands_<ContainerAllocator>;

  explicit MotorCommands_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_init;
  }

  explicit MotorCommands_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_init;
    (void)_alloc;
  }

  // field types and members
  using _commands_type =
    std::vector<int32_t, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<int32_t>>;
  _commands_type commands;

  // setters for named parameter idiom
  Type & set__commands(
    const std::vector<int32_t, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<int32_t>> & _arg)
  {
    this->commands = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    rl_custom_messages::msg::MotorCommands_<ContainerAllocator> *;
  using ConstRawPtr =
    const rl_custom_messages::msg::MotorCommands_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<rl_custom_messages::msg::MotorCommands_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<rl_custom_messages::msg::MotorCommands_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      rl_custom_messages::msg::MotorCommands_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<rl_custom_messages::msg::MotorCommands_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      rl_custom_messages::msg::MotorCommands_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<rl_custom_messages::msg::MotorCommands_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<rl_custom_messages::msg::MotorCommands_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<rl_custom_messages::msg::MotorCommands_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__rl_custom_messages__msg__MotorCommands
    std::shared_ptr<rl_custom_messages::msg::MotorCommands_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__rl_custom_messages__msg__MotorCommands
    std::shared_ptr<rl_custom_messages::msg::MotorCommands_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const MotorCommands_ & other) const
  {
    if (this->commands != other.commands) {
      return false;
    }
    return true;
  }
  bool operator!=(const MotorCommands_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct MotorCommands_

// alias to use template instance with default allocator
using MotorCommands =
  rl_custom_messages::msg::MotorCommands_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace rl_custom_messages

#endif  // RL_CUSTOM_MESSAGES__MSG__DETAIL__MOTOR_COMMANDS__STRUCT_HPP_
