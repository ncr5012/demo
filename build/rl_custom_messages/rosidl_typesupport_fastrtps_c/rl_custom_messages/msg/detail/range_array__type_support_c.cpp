// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from rl_custom_messages:msg/RangeArray.idl
// generated code does not contain a copyright notice
#include "rl_custom_messages/msg/detail/range_array__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "rl_custom_messages/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "rl_custom_messages/msg/detail/range_array__struct.h"
#include "rl_custom_messages/msg/detail/range_array__functions.h"
#include "fastcdr/Cdr.h"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

// includes and forward declarations of message dependencies and their conversion functions

#if defined(__cplusplus)
extern "C"
{
#endif


// forward declare type support functions


using _RangeArray__ros_msg_type = rl_custom_messages__msg__RangeArray;

static bool _RangeArray__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _RangeArray__ros_msg_type * ros_message = static_cast<const _RangeArray__ros_msg_type *>(untyped_ros_message);
  // Field name: range_left
  {
    cdr << ros_message->range_left;
  }

  // Field name: range_front
  {
    cdr << ros_message->range_front;
  }

  // Field name: range_right
  {
    cdr << ros_message->range_right;
  }

  // Field name: range_back
  {
    cdr << ros_message->range_back;
  }

  return true;
}

static bool _RangeArray__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _RangeArray__ros_msg_type * ros_message = static_cast<_RangeArray__ros_msg_type *>(untyped_ros_message);
  // Field name: range_left
  {
    cdr >> ros_message->range_left;
  }

  // Field name: range_front
  {
    cdr >> ros_message->range_front;
  }

  // Field name: range_right
  {
    cdr >> ros_message->range_right;
  }

  // Field name: range_back
  {
    cdr >> ros_message->range_back;
  }

  return true;
}  // NOLINT(readability/fn_size)

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_rl_custom_messages
size_t get_serialized_size_rl_custom_messages__msg__RangeArray(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _RangeArray__ros_msg_type * ros_message = static_cast<const _RangeArray__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name range_left
  {
    size_t item_size = sizeof(ros_message->range_left);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name range_front
  {
    size_t item_size = sizeof(ros_message->range_front);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name range_right
  {
    size_t item_size = sizeof(ros_message->range_right);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name range_back
  {
    size_t item_size = sizeof(ros_message->range_back);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

static uint32_t _RangeArray__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_rl_custom_messages__msg__RangeArray(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_rl_custom_messages
size_t max_serialized_size_rl_custom_messages__msg__RangeArray(
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

  // member: range_left
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: range_front
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: range_right
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: range_back
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  return current_alignment - initial_alignment;
}

static size_t _RangeArray__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_rl_custom_messages__msg__RangeArray(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_RangeArray = {
  "rl_custom_messages::msg",
  "RangeArray",
  _RangeArray__cdr_serialize,
  _RangeArray__cdr_deserialize,
  _RangeArray__get_serialized_size,
  _RangeArray__max_serialized_size
};

static rosidl_message_type_support_t _RangeArray__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_RangeArray,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, rl_custom_messages, msg, RangeArray)() {
  return &_RangeArray__type_support;
}

#if defined(__cplusplus)
}
#endif
