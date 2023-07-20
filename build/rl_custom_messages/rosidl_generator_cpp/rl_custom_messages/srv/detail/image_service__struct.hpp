// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from rl_custom_messages:srv/ImageService.idl
// generated code does not contain a copyright notice

#ifndef RL_CUSTOM_MESSAGES__SRV__DETAIL__IMAGE_SERVICE__STRUCT_HPP_
#define RL_CUSTOM_MESSAGES__SRV__DETAIL__IMAGE_SERVICE__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__rl_custom_messages__srv__ImageService_Request __attribute__((deprecated))
#else
# define DEPRECATED__rl_custom_messages__srv__ImageService_Request __declspec(deprecated)
#endif

namespace rl_custom_messages
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct ImageService_Request_
{
  using Type = ImageService_Request_<ContainerAllocator>;

  explicit ImageService_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->structure_needs_at_least_one_member = 0;
    }
  }

  explicit ImageService_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->structure_needs_at_least_one_member = 0;
    }
  }

  // field types and members
  using _structure_needs_at_least_one_member_type =
    uint8_t;
  _structure_needs_at_least_one_member_type structure_needs_at_least_one_member;


  // constant declarations

  // pointer types
  using RawPtr =
    rl_custom_messages::srv::ImageService_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const rl_custom_messages::srv::ImageService_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<rl_custom_messages::srv::ImageService_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<rl_custom_messages::srv::ImageService_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      rl_custom_messages::srv::ImageService_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<rl_custom_messages::srv::ImageService_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      rl_custom_messages::srv::ImageService_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<rl_custom_messages::srv::ImageService_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<rl_custom_messages::srv::ImageService_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<rl_custom_messages::srv::ImageService_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__rl_custom_messages__srv__ImageService_Request
    std::shared_ptr<rl_custom_messages::srv::ImageService_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__rl_custom_messages__srv__ImageService_Request
    std::shared_ptr<rl_custom_messages::srv::ImageService_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const ImageService_Request_ & other) const
  {
    if (this->structure_needs_at_least_one_member != other.structure_needs_at_least_one_member) {
      return false;
    }
    return true;
  }
  bool operator!=(const ImageService_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct ImageService_Request_

// alias to use template instance with default allocator
using ImageService_Request =
  rl_custom_messages::srv::ImageService_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace rl_custom_messages


// Include directives for member types
// Member 'image_data'
#include "sensor_msgs/msg/detail/compressed_image__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__rl_custom_messages__srv__ImageService_Response __attribute__((deprecated))
#else
# define DEPRECATED__rl_custom_messages__srv__ImageService_Response __declspec(deprecated)
#endif

namespace rl_custom_messages
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct ImageService_Response_
{
  using Type = ImageService_Response_<ContainerAllocator>;

  explicit ImageService_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : image_data(_init)
  {
    (void)_init;
  }

  explicit ImageService_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : image_data(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _image_data_type =
    sensor_msgs::msg::CompressedImage_<ContainerAllocator>;
  _image_data_type image_data;

  // setters for named parameter idiom
  Type & set__image_data(
    const sensor_msgs::msg::CompressedImage_<ContainerAllocator> & _arg)
  {
    this->image_data = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    rl_custom_messages::srv::ImageService_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const rl_custom_messages::srv::ImageService_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<rl_custom_messages::srv::ImageService_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<rl_custom_messages::srv::ImageService_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      rl_custom_messages::srv::ImageService_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<rl_custom_messages::srv::ImageService_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      rl_custom_messages::srv::ImageService_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<rl_custom_messages::srv::ImageService_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<rl_custom_messages::srv::ImageService_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<rl_custom_messages::srv::ImageService_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__rl_custom_messages__srv__ImageService_Response
    std::shared_ptr<rl_custom_messages::srv::ImageService_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__rl_custom_messages__srv__ImageService_Response
    std::shared_ptr<rl_custom_messages::srv::ImageService_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const ImageService_Response_ & other) const
  {
    if (this->image_data != other.image_data) {
      return false;
    }
    return true;
  }
  bool operator!=(const ImageService_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct ImageService_Response_

// alias to use template instance with default allocator
using ImageService_Response =
  rl_custom_messages::srv::ImageService_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace rl_custom_messages

namespace rl_custom_messages
{

namespace srv
{

struct ImageService
{
  using Request = rl_custom_messages::srv::ImageService_Request;
  using Response = rl_custom_messages::srv::ImageService_Response;
};

}  // namespace srv

}  // namespace rl_custom_messages

#endif  // RL_CUSTOM_MESSAGES__SRV__DETAIL__IMAGE_SERVICE__STRUCT_HPP_
