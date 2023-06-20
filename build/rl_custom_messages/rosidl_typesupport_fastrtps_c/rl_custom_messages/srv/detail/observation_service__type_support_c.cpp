// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from rl_custom_messages:srv/ObservationService.idl
// generated code does not contain a copyright notice
#include "rl_custom_messages/srv/detail/observation_service__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "rl_custom_messages/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "rl_custom_messages/srv/detail/observation_service__struct.h"
#include "rl_custom_messages/srv/detail/observation_service__functions.h"
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


using _ObservationService_Request__ros_msg_type = rl_custom_messages__srv__ObservationService_Request;

static bool _ObservationService_Request__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _ObservationService_Request__ros_msg_type * ros_message = static_cast<const _ObservationService_Request__ros_msg_type *>(untyped_ros_message);
  // Field name: action
  {
    size_t size = 12;
    auto array_ptr = ros_message->action;
    cdr.serializeArray(array_ptr, size);
  }

  return true;
}

static bool _ObservationService_Request__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _ObservationService_Request__ros_msg_type * ros_message = static_cast<_ObservationService_Request__ros_msg_type *>(untyped_ros_message);
  // Field name: action
  {
    size_t size = 12;
    auto array_ptr = ros_message->action;
    cdr.deserializeArray(array_ptr, size);
  }

  return true;
}  // NOLINT(readability/fn_size)

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_rl_custom_messages
size_t get_serialized_size_rl_custom_messages__srv__ObservationService_Request(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _ObservationService_Request__ros_msg_type * ros_message = static_cast<const _ObservationService_Request__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name action
  {
    size_t array_size = 12;
    auto array_ptr = ros_message->action;
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

static uint32_t _ObservationService_Request__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_rl_custom_messages__srv__ObservationService_Request(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_rl_custom_messages
size_t max_serialized_size_rl_custom_messages__srv__ObservationService_Request(
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

  // member: action
  {
    size_t array_size = 12;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  return current_alignment - initial_alignment;
}

static size_t _ObservationService_Request__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_rl_custom_messages__srv__ObservationService_Request(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_ObservationService_Request = {
  "rl_custom_messages::srv",
  "ObservationService_Request",
  _ObservationService_Request__cdr_serialize,
  _ObservationService_Request__cdr_deserialize,
  _ObservationService_Request__get_serialized_size,
  _ObservationService_Request__max_serialized_size
};

static rosidl_message_type_support_t _ObservationService_Request__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_ObservationService_Request,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, rl_custom_messages, srv, ObservationService_Request)() {
  return &_ObservationService_Request__type_support;
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
// #include "rl_custom_messages/srv/detail/observation_service__struct.h"
// already included above
// #include "rl_custom_messages/srv/detail/observation_service__functions.h"
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

#include "rl_custom_messages/msg/detail/range_array__functions.h"  // range_data

// forward declare type support functions
size_t get_serialized_size_rl_custom_messages__msg__RangeArray(
  const void * untyped_ros_message,
  size_t current_alignment);

size_t max_serialized_size_rl_custom_messages__msg__RangeArray(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, rl_custom_messages, msg, RangeArray)();


using _ObservationService_Response__ros_msg_type = rl_custom_messages__srv__ObservationService_Response;

static bool _ObservationService_Response__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _ObservationService_Response__ros_msg_type * ros_message = static_cast<const _ObservationService_Response__ros_msg_type *>(untyped_ros_message);
  // Field name: range_data
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, rl_custom_messages, msg, RangeArray
      )()->data);
    if (!callbacks->cdr_serialize(
        &ros_message->range_data, cdr))
    {
      return false;
    }
  }

  return true;
}

static bool _ObservationService_Response__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _ObservationService_Response__ros_msg_type * ros_message = static_cast<_ObservationService_Response__ros_msg_type *>(untyped_ros_message);
  // Field name: range_data
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, rl_custom_messages, msg, RangeArray
      )()->data);
    if (!callbacks->cdr_deserialize(
        cdr, &ros_message->range_data))
    {
      return false;
    }
  }

  return true;
}  // NOLINT(readability/fn_size)

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_rl_custom_messages
size_t get_serialized_size_rl_custom_messages__srv__ObservationService_Response(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _ObservationService_Response__ros_msg_type * ros_message = static_cast<const _ObservationService_Response__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name range_data

  current_alignment += get_serialized_size_rl_custom_messages__msg__RangeArray(
    &(ros_message->range_data), current_alignment);

  return current_alignment - initial_alignment;
}

static uint32_t _ObservationService_Response__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_rl_custom_messages__srv__ObservationService_Response(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_rl_custom_messages
size_t max_serialized_size_rl_custom_messages__srv__ObservationService_Response(
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

  // member: range_data
  {
    size_t array_size = 1;


    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      current_alignment +=
        max_serialized_size_rl_custom_messages__msg__RangeArray(
        inner_full_bounded, inner_is_plain, current_alignment);
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  return current_alignment - initial_alignment;
}

static size_t _ObservationService_Response__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_rl_custom_messages__srv__ObservationService_Response(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_ObservationService_Response = {
  "rl_custom_messages::srv",
  "ObservationService_Response",
  _ObservationService_Response__cdr_serialize,
  _ObservationService_Response__cdr_deserialize,
  _ObservationService_Response__get_serialized_size,
  _ObservationService_Response__max_serialized_size
};

static rosidl_message_type_support_t _ObservationService_Response__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_ObservationService_Response,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, rl_custom_messages, srv, ObservationService_Response)() {
  return &_ObservationService_Response__type_support;
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
#include "rl_custom_messages/srv/observation_service.h"

#if defined(__cplusplus)
extern "C"
{
#endif

static service_type_support_callbacks_t ObservationService__callbacks = {
  "rl_custom_messages::srv",
  "ObservationService",
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, rl_custom_messages, srv, ObservationService_Request)(),
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, rl_custom_messages, srv, ObservationService_Response)(),
};

static rosidl_service_type_support_t ObservationService__handle = {
  rosidl_typesupport_fastrtps_c__identifier,
  &ObservationService__callbacks,
  get_service_typesupport_handle_function,
};

const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, rl_custom_messages, srv, ObservationService)() {
  return &ObservationService__handle;
}

#if defined(__cplusplus)
}
#endif
