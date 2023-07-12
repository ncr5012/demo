// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__type_support.cpp.em
// with input from rl_custom_messages:msg/AudioData.idl
// generated code does not contain a copyright notice
#include "rl_custom_messages/msg/detail/audio_data__rosidl_typesupport_fastrtps_cpp.hpp"
#include "rl_custom_messages/msg/detail/audio_data__struct.hpp"

#include <limits>
#include <stdexcept>
#include <string>
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_fastrtps_cpp/identifier.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_fastrtps_cpp/wstring_conversion.hpp"
#include "fastcdr/Cdr.h"


// forward declaration of message dependencies and their conversion functions

namespace rl_custom_messages
{

namespace msg
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_rl_custom_messages
cdr_serialize(
  const rl_custom_messages::msg::AudioData & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: sample_rate
  cdr << ros_message.sample_rate;
  // Member: channels
  cdr << ros_message.channels;
  // Member: data
  {
    cdr << ros_message.data;
  }
  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_rl_custom_messages
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  rl_custom_messages::msg::AudioData & ros_message)
{
  // Member: sample_rate
  cdr >> ros_message.sample_rate;

  // Member: channels
  cdr >> ros_message.channels;

  // Member: data
  {
    cdr >> ros_message.data;
  }

  return true;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_rl_custom_messages
get_serialized_size(
  const rl_custom_messages::msg::AudioData & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: sample_rate
  {
    size_t item_size = sizeof(ros_message.sample_rate);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: channels
  {
    size_t item_size = sizeof(ros_message.channels);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: data
  {
    size_t array_size = ros_message.data.size();

    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    size_t item_size = sizeof(ros_message.data[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_rl_custom_messages
max_serialized_size_AudioData(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  full_bounded = true;
  is_plain = true;


  // Member: sample_rate
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: channels
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint16_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint16_t));
  }

  // Member: data
  {
    size_t array_size = 0;
    full_bounded = false;
    is_plain = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);

    current_alignment += array_size * sizeof(uint16_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint16_t));
  }

  return current_alignment - initial_alignment;
}

static bool _AudioData__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  auto typed_message =
    static_cast<const rl_custom_messages::msg::AudioData *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _AudioData__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<rl_custom_messages::msg::AudioData *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _AudioData__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const rl_custom_messages::msg::AudioData *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _AudioData__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_AudioData(full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}

static message_type_support_callbacks_t _AudioData__callbacks = {
  "rl_custom_messages::msg",
  "AudioData",
  _AudioData__cdr_serialize,
  _AudioData__cdr_deserialize,
  _AudioData__get_serialized_size,
  _AudioData__max_serialized_size
};

static rosidl_message_type_support_t _AudioData__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_AudioData__callbacks,
  get_message_typesupport_handle_function,
};

}  // namespace typesupport_fastrtps_cpp

}  // namespace msg

}  // namespace rl_custom_messages

namespace rosidl_typesupport_fastrtps_cpp
{

template<>
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_EXPORT_rl_custom_messages
const rosidl_message_type_support_t *
get_message_type_support_handle<rl_custom_messages::msg::AudioData>()
{
  return &rl_custom_messages::msg::typesupport_fastrtps_cpp::_AudioData__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, rl_custom_messages, msg, AudioData)() {
  return &rl_custom_messages::msg::typesupport_fastrtps_cpp::_AudioData__handle;
}

#ifdef __cplusplus
}
#endif
