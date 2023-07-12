// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from rl_custom_messages:msg/AudioData.idl
// generated code does not contain a copyright notice

#ifndef RL_CUSTOM_MESSAGES__MSG__DETAIL__AUDIO_DATA__STRUCT_HPP_
#define RL_CUSTOM_MESSAGES__MSG__DETAIL__AUDIO_DATA__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__rl_custom_messages__msg__AudioData __attribute__((deprecated))
#else
# define DEPRECATED__rl_custom_messages__msg__AudioData __declspec(deprecated)
#endif

namespace rl_custom_messages
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct AudioData_
{
  using Type = AudioData_<ContainerAllocator>;

  explicit AudioData_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->sample_rate = 0ul;
      this->channels = 0;
    }
  }

  explicit AudioData_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->sample_rate = 0ul;
      this->channels = 0;
    }
  }

  // field types and members
  using _sample_rate_type =
    uint32_t;
  _sample_rate_type sample_rate;
  using _channels_type =
    uint16_t;
  _channels_type channels;
  using _data_type =
    std::vector<int16_t, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<int16_t>>;
  _data_type data;

  // setters for named parameter idiom
  Type & set__sample_rate(
    const uint32_t & _arg)
  {
    this->sample_rate = _arg;
    return *this;
  }
  Type & set__channels(
    const uint16_t & _arg)
  {
    this->channels = _arg;
    return *this;
  }
  Type & set__data(
    const std::vector<int16_t, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<int16_t>> & _arg)
  {
    this->data = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    rl_custom_messages::msg::AudioData_<ContainerAllocator> *;
  using ConstRawPtr =
    const rl_custom_messages::msg::AudioData_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<rl_custom_messages::msg::AudioData_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<rl_custom_messages::msg::AudioData_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      rl_custom_messages::msg::AudioData_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<rl_custom_messages::msg::AudioData_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      rl_custom_messages::msg::AudioData_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<rl_custom_messages::msg::AudioData_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<rl_custom_messages::msg::AudioData_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<rl_custom_messages::msg::AudioData_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__rl_custom_messages__msg__AudioData
    std::shared_ptr<rl_custom_messages::msg::AudioData_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__rl_custom_messages__msg__AudioData
    std::shared_ptr<rl_custom_messages::msg::AudioData_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const AudioData_ & other) const
  {
    if (this->sample_rate != other.sample_rate) {
      return false;
    }
    if (this->channels != other.channels) {
      return false;
    }
    if (this->data != other.data) {
      return false;
    }
    return true;
  }
  bool operator!=(const AudioData_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct AudioData_

// alias to use template instance with default allocator
using AudioData =
  rl_custom_messages::msg::AudioData_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace rl_custom_messages

#endif  // RL_CUSTOM_MESSAGES__MSG__DETAIL__AUDIO_DATA__STRUCT_HPP_
