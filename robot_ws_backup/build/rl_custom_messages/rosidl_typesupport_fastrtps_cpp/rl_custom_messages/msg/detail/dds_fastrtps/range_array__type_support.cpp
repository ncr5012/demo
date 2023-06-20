// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__type_support.cpp.em
// with input from rl_custom_messages:msg/RangeArray.idl
// generated code does not contain a copyright notice
#include "rl_custom_messages/msg/detail/range_array__rosidl_typesupport_fastrtps_cpp.hpp"
#include "rl_custom_messages/msg/detail/range_array__struct.hpp"

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
  const rl_custom_messages::msg::RangeArray & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: range_left
  cdr << ros_message.range_left;
  // Member: range_front
  cdr << ros_message.range_front;
  // Member: range_right
  cdr << ros_message.range_right;
  // Member: range_back
  cdr << ros_message.range_back;
  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_rl_custom_messages
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  rl_custom_messages::msg::RangeArray & ros_message)
{
  // Member: range_left
  cdr >> ros_message.range_left;

  // Member: range_front
  cdr >> ros_message.range_front;

  // Member: range_right
  cdr >> ros_message.range_right;

  // Member: range_back
  cdr >> ros_message.range_back;

  return true;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_rl_custom_messages
get_serialized_size(
  const rl_custom_messages::msg::RangeArray & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: range_left
  {
    size_t item_size = sizeof(ros_message.range_left);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: range_front
  {
    size_t item_size = sizeof(ros_message.range_front);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: range_right
  {
    size_t item_size = sizeof(ros_message.range_right);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: range_back
  {
    size_t item_size = sizeof(ros_message.range_back);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_rl_custom_messages
max_serialized_size_RangeArray(
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


  // Member: range_left
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: range_front
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: range_right
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: range_back
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  return current_alignment - initial_alignment;
}

static bool _RangeArray__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  auto typed_message =
    static_cast<const rl_custom_messages::msg::RangeArray *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _RangeArray__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<rl_custom_messages::msg::RangeArray *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _RangeArray__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const rl_custom_messages::msg::RangeArray *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _RangeArray__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_RangeArray(full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}

static message_type_support_callbacks_t _RangeArray__callbacks = {
  "rl_custom_messages::msg",
  "RangeArray",
  _RangeArray__cdr_serialize,
  _RangeArray__cdr_deserialize,
  _RangeArray__get_serialized_size,
  _RangeArray__max_serialized_size
};

static rosidl_message_type_support_t _RangeArray__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_RangeArray__callbacks,
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
get_message_type_support_handle<rl_custom_messages::msg::RangeArray>()
{
  return &rl_custom_messages::msg::typesupport_fastrtps_cpp::_RangeArray__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, rl_custom_messages, msg, RangeArray)() {
  return &rl_custom_messages::msg::typesupport_fastrtps_cpp::_RangeArray__handle;
}

#ifdef __cplusplus
}
#endif
