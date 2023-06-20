// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from rl_custom_messages:srv/ObservationService.idl
// generated code does not contain a copyright notice

#ifndef RL_CUSTOM_MESSAGES__SRV__DETAIL__OBSERVATION_SERVICE__STRUCT_HPP_
#define RL_CUSTOM_MESSAGES__SRV__DETAIL__OBSERVATION_SERVICE__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__rl_custom_messages__srv__ObservationService_Request __attribute__((deprecated))
#else
# define DEPRECATED__rl_custom_messages__srv__ObservationService_Request __declspec(deprecated)
#endif

namespace rl_custom_messages
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct ObservationService_Request_
{
  using Type = ObservationService_Request_<ContainerAllocator>;

  explicit ObservationService_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      std::fill<typename std::array<int32_t, 12>::iterator, int32_t>(this->action.begin(), this->action.end(), 0l);
    }
  }

  explicit ObservationService_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : action(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      std::fill<typename std::array<int32_t, 12>::iterator, int32_t>(this->action.begin(), this->action.end(), 0l);
    }
  }

  // field types and members
  using _action_type =
    std::array<int32_t, 12>;
  _action_type action;

  // setters for named parameter idiom
  Type & set__action(
    const std::array<int32_t, 12> & _arg)
  {
    this->action = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    rl_custom_messages::srv::ObservationService_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const rl_custom_messages::srv::ObservationService_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<rl_custom_messages::srv::ObservationService_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<rl_custom_messages::srv::ObservationService_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      rl_custom_messages::srv::ObservationService_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<rl_custom_messages::srv::ObservationService_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      rl_custom_messages::srv::ObservationService_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<rl_custom_messages::srv::ObservationService_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<rl_custom_messages::srv::ObservationService_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<rl_custom_messages::srv::ObservationService_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__rl_custom_messages__srv__ObservationService_Request
    std::shared_ptr<rl_custom_messages::srv::ObservationService_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__rl_custom_messages__srv__ObservationService_Request
    std::shared_ptr<rl_custom_messages::srv::ObservationService_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const ObservationService_Request_ & other) const
  {
    if (this->action != other.action) {
      return false;
    }
    return true;
  }
  bool operator!=(const ObservationService_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct ObservationService_Request_

// alias to use template instance with default allocator
using ObservationService_Request =
  rl_custom_messages::srv::ObservationService_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace rl_custom_messages


// Include directives for member types
// Member 'range_data'
#include "rl_custom_messages/msg/detail/range_array__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__rl_custom_messages__srv__ObservationService_Response __attribute__((deprecated))
#else
# define DEPRECATED__rl_custom_messages__srv__ObservationService_Response __declspec(deprecated)
#endif

namespace rl_custom_messages
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct ObservationService_Response_
{
  using Type = ObservationService_Response_<ContainerAllocator>;

  explicit ObservationService_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : range_data(_init)
  {
    (void)_init;
  }

  explicit ObservationService_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : range_data(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _range_data_type =
    rl_custom_messages::msg::RangeArray_<ContainerAllocator>;
  _range_data_type range_data;

  // setters for named parameter idiom
  Type & set__range_data(
    const rl_custom_messages::msg::RangeArray_<ContainerAllocator> & _arg)
  {
    this->range_data = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    rl_custom_messages::srv::ObservationService_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const rl_custom_messages::srv::ObservationService_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<rl_custom_messages::srv::ObservationService_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<rl_custom_messages::srv::ObservationService_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      rl_custom_messages::srv::ObservationService_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<rl_custom_messages::srv::ObservationService_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      rl_custom_messages::srv::ObservationService_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<rl_custom_messages::srv::ObservationService_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<rl_custom_messages::srv::ObservationService_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<rl_custom_messages::srv::ObservationService_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__rl_custom_messages__srv__ObservationService_Response
    std::shared_ptr<rl_custom_messages::srv::ObservationService_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__rl_custom_messages__srv__ObservationService_Response
    std::shared_ptr<rl_custom_messages::srv::ObservationService_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const ObservationService_Response_ & other) const
  {
    if (this->range_data != other.range_data) {
      return false;
    }
    return true;
  }
  bool operator!=(const ObservationService_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct ObservationService_Response_

// alias to use template instance with default allocator
using ObservationService_Response =
  rl_custom_messages::srv::ObservationService_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace rl_custom_messages

namespace rl_custom_messages
{

namespace srv
{

struct ObservationService
{
  using Request = rl_custom_messages::srv::ObservationService_Request;
  using Response = rl_custom_messages::srv::ObservationService_Response;
};

}  // namespace srv

}  // namespace rl_custom_messages

#endif  // RL_CUSTOM_MESSAGES__SRV__DETAIL__OBSERVATION_SERVICE__STRUCT_HPP_
