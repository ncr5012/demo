// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from rl_custom_messages:srv/EmotionService.idl
// generated code does not contain a copyright notice
#include "rl_custom_messages/srv/detail/emotion_service__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "rl_custom_messages/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "rl_custom_messages/srv/detail/emotion_service__struct.h"
#include "rl_custom_messages/srv/detail/emotion_service__functions.h"
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


using _EmotionService_Request__ros_msg_type = rl_custom_messages__srv__EmotionService_Request;

static bool _EmotionService_Request__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _EmotionService_Request__ros_msg_type * ros_message = static_cast<const _EmotionService_Request__ros_msg_type *>(untyped_ros_message);
  // Field name: structure_needs_at_least_one_member
  {
    cdr << ros_message->structure_needs_at_least_one_member;
  }

  return true;
}

static bool _EmotionService_Request__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _EmotionService_Request__ros_msg_type * ros_message = static_cast<_EmotionService_Request__ros_msg_type *>(untyped_ros_message);
  // Field name: structure_needs_at_least_one_member
  {
    cdr >> ros_message->structure_needs_at_least_one_member;
  }

  return true;
}  // NOLINT(readability/fn_size)

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_rl_custom_messages
size_t get_serialized_size_rl_custom_messages__srv__EmotionService_Request(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _EmotionService_Request__ros_msg_type * ros_message = static_cast<const _EmotionService_Request__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name structure_needs_at_least_one_member
  {
    size_t item_size = sizeof(ros_message->structure_needs_at_least_one_member);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

static uint32_t _EmotionService_Request__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_rl_custom_messages__srv__EmotionService_Request(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_rl_custom_messages
size_t max_serialized_size_rl_custom_messages__srv__EmotionService_Request(
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

  // member: structure_needs_at_least_one_member
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint8_t);
  }

  return current_alignment - initial_alignment;
}

static size_t _EmotionService_Request__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_rl_custom_messages__srv__EmotionService_Request(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_EmotionService_Request = {
  "rl_custom_messages::srv",
  "EmotionService_Request",
  _EmotionService_Request__cdr_serialize,
  _EmotionService_Request__cdr_deserialize,
  _EmotionService_Request__get_serialized_size,
  _EmotionService_Request__max_serialized_size
};

static rosidl_message_type_support_t _EmotionService_Request__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_EmotionService_Request,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, rl_custom_messages, srv, EmotionService_Request)() {
  return &_EmotionService_Request__type_support;
}

#if defined(__cplusplus)
}
#endif

// already included above
// #include <cassert>
// already included above
// #include <limits>
// already included above
// #include <string>
// already included above
// #include "rosidl_typesupport_fastrtps_c/identifier.h"
// already included above
// #include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
// already included above
// #include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
// already included above
// #include "rl_custom_messages/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
// already included above
// #include "rl_custom_messages/srv/detail/emotion_service__struct.h"
// already included above
// #include "rl_custom_messages/srv/detail/emotion_service__functions.h"
// already included above
// #include "fastcdr/Cdr.h"

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

#include "rosidl_runtime_c/string.h"  // results
#include "rosidl_runtime_c/string_functions.h"  // results

// forward declare type support functions


using _EmotionService_Response__ros_msg_type = rl_custom_messages__srv__EmotionService_Response;

static bool _EmotionService_Response__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _EmotionService_Response__ros_msg_type * ros_message = static_cast<const _EmotionService_Response__ros_msg_type *>(untyped_ros_message);
  // Field name: results
  {
    const rosidl_runtime_c__String * str = &ros_message->results;
    if (str->capacity == 0 || str->capacity <= str->size) {
      fprintf(stderr, "string capacity not greater than size\n");
      return false;
    }
    if (str->data[str->size] != '\0') {
      fprintf(stderr, "string not null-terminated\n");
      return false;
    }
    cdr << str->data;
  }

  return true;
}

static bool _EmotionService_Response__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _EmotionService_Response__ros_msg_type * ros_message = static_cast<_EmotionService_Response__ros_msg_type *>(untyped_ros_message);
  // Field name: results
  {
    std::string tmp;
    cdr >> tmp;
    if (!ros_message->results.data) {
      rosidl_runtime_c__String__init(&ros_message->results);
    }
    bool succeeded = rosidl_runtime_c__String__assign(
      &ros_message->results,
      tmp.c_str());
    if (!succeeded) {
      fprintf(stderr, "failed to assign string into field 'results'\n");
      return false;
    }
  }

  return true;
}  // NOLINT(readability/fn_size)

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_rl_custom_messages
size_t get_serialized_size_rl_custom_messages__srv__EmotionService_Response(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _EmotionService_Response__ros_msg_type * ros_message = static_cast<const _EmotionService_Response__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name results
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->results.size + 1);

  return current_alignment - initial_alignment;
}

static uint32_t _EmotionService_Response__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_rl_custom_messages__srv__EmotionService_Response(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_rl_custom_messages
size_t max_serialized_size_rl_custom_messages__srv__EmotionService_Response(
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

  // member: results
  {
    size_t array_size = 1;

    full_bounded = false;
    is_plain = false;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        1;
    }
  }

  return current_alignment - initial_alignment;
}

static size_t _EmotionService_Response__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_rl_custom_messages__srv__EmotionService_Response(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_EmotionService_Response = {
  "rl_custom_messages::srv",
  "EmotionService_Response",
  _EmotionService_Response__cdr_serialize,
  _EmotionService_Response__cdr_deserialize,
  _EmotionService_Response__get_serialized_size,
  _EmotionService_Response__max_serialized_size
};

static rosidl_message_type_support_t _EmotionService_Response__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_EmotionService_Response,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, rl_custom_messages, srv, EmotionService_Response)() {
  return &_EmotionService_Response__type_support;
}

#if defined(__cplusplus)
}
#endif

#include "rosidl_typesupport_fastrtps_cpp/service_type_support.h"
#include "rosidl_typesupport_cpp/service_type_support.hpp"
// already included above
// #include "rosidl_typesupport_fastrtps_c/identifier.h"
// already included above
// #include "rl_custom_messages/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "rl_custom_messages/srv/emotion_service.h"

#if defined(__cplusplus)
extern "C"
{
#endif

static service_type_support_callbacks_t EmotionService__callbacks = {
  "rl_custom_messages::srv",
  "EmotionService",
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, rl_custom_messages, srv, EmotionService_Request)(),
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, rl_custom_messages, srv, EmotionService_Response)(),
};

static rosidl_service_type_support_t EmotionService__handle = {
  rosidl_typesupport_fastrtps_c__identifier,
  &EmotionService__callbacks,
  get_service_typesupport_handle_function,
};

const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, rl_custom_messages, srv, EmotionService)() {
  return &EmotionService__handle;
}

#if defined(__cplusplus)
}
#endif
