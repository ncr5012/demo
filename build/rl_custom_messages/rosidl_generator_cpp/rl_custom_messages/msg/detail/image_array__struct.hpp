// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from rl_custom_messages:msg/ImageArray.idl
// generated code does not contain a copyright notice

#ifndef RL_CUSTOM_MESSAGES__MSG__DETAIL__IMAGE_ARRAY__STRUCT_HPP_
#define RL_CUSTOM_MESSAGES__MSG__DETAIL__IMAGE_ARRAY__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__rl_custom_messages__msg__ImageArray __attribute__((deprecated))
#else
# define DEPRECATED__rl_custom_messages__msg__ImageArray __declspec(deprecated)
#endif

namespace rl_custom_messages
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct ImageArray_
{
  using Type = ImageArray_<ContainerAllocator>;

  explicit ImageArray_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->height = 0ul;
      this->width = 0ul;
      this->encoding = "";
    }
  }

  explicit ImageArray_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : encoding(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->height = 0ul;
      this->width = 0ul;
      this->encoding = "";
    }
  }

  // field types and members
  using _height_type =
    uint32_t;
  _height_type height;
  using _width_type =
    uint32_t;
  _width_type width;
  using _encoding_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _encoding_type encoding;
  using _data_type =
    std::vector<uint8_t, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<uint8_t>>;
  _data_type data;

  // setters for named parameter idiom
  Type & set__height(
    const uint32_t & _arg)
  {
    this->height = _arg;
    return *this;
  }
  Type & set__width(
    const uint32_t & _arg)
  {
    this->width = _arg;
    return *this;
  }
  Type & set__encoding(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->encoding = _arg;
    return *this;
  }
  Type & set__data(
    const std::vector<uint8_t, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<uint8_t>> & _arg)
  {
    this->data = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    rl_custom_messages::msg::ImageArray_<ContainerAllocator> *;
  using ConstRawPtr =
    const rl_custom_messages::msg::ImageArray_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<rl_custom_messages::msg::ImageArray_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<rl_custom_messages::msg::ImageArray_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      rl_custom_messages::msg::ImageArray_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<rl_custom_messages::msg::ImageArray_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      rl_custom_messages::msg::ImageArray_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<rl_custom_messages::msg::ImageArray_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<rl_custom_messages::msg::ImageArray_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<rl_custom_messages::msg::ImageArray_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__rl_custom_messages__msg__ImageArray
    std::shared_ptr<rl_custom_messages::msg::ImageArray_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__rl_custom_messages__msg__ImageArray
    std::shared_ptr<rl_custom_messages::msg::ImageArray_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const ImageArray_ & other) const
  {
    if (this->height != other.height) {
      return false;
    }
    if (this->width != other.width) {
      return false;
    }
    if (this->encoding != other.encoding) {
      return false;
    }
    if (this->data != other.data) {
      return false;
    }
    return true;
  }
  bool operator!=(const ImageArray_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct ImageArray_

// alias to use template instance with default allocator
using ImageArray =
  rl_custom_messages::msg::ImageArray_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace rl_custom_messages

#endif  // RL_CUSTOM_MESSAGES__MSG__DETAIL__IMAGE_ARRAY__STRUCT_HPP_
