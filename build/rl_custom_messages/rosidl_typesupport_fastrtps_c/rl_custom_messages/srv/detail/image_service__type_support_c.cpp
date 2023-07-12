// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from rl_custom_messages:srv/ImageService.idl
// generated code does not contain a copyright notice
#include "rl_custom_messages/srv/detail/image_service__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "rl_custom_messages/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "rl_custom_messages/srv/detail/image_service__struct.h"
#include "rl_custom_messages/srv/detail/image_service__functions.h"
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


using _ImageService_Request__ros_msg_type = rl_custom_messages__srv__ImageService_Request;

static bool _ImageService_Request__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _ImageService_Request__ros_msg_type * ros_message = static_cast<const _ImageService_Request__ros_msg_type *>(untyped_ros_message);
  // Field name: structure_needs_at_least_one_member
  {
    cdr << ros_message->structure_needs_at_least_one_member;
  }

  return true;
}

static bool _ImageService_Request__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _ImageService_Request__ros_msg_type * ros_message = static_cast<_ImageService_Request__ros_msg_type *>(untyped_ros_message);
  // Field name: structure_needs_at_least_one_member
  {
    cdr >> ros_message->structure_needs_at_least_one_member;
  }

  return true;
}  // NOLINT(readability/fn_size)

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_rl_custom_messages
size_t get_serialized_size_rl_custom_messages__srv__ImageService_Request(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _ImageService_Request__ros_msg_type * ros_message = static_cast<const _ImageService_Request__ros_msg_type *>(untyped_ros_message);
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

static uint32_t _ImageService_Request__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_rl_custom_messages__srv__ImageService_Request(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_rl_custom_messages
size_t max_serialized_size_rl_custom_messages__srv__ImageService_Request(
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

static size_t _ImageService_Request__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_rl_custom_messages__srv__ImageService_Request(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_ImageService_Request = {
  "rl_custom_messages::srv",
  "ImageService_Request",
  _ImageService_Request__cdr_serialize,
  _ImageService_Request__cdr_deserialize,
  _ImageService_Request__get_serialized_size,
  _ImageService_Request__max_serialized_size
};

static rosidl_message_type_support_t _ImageService_Request__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_ImageService_Request,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, rl_custom_messages, srv, ImageService_Request)() {
  return &_ImageService_Request__type_support;
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
// #include "rl_custom_messages/srv/detail/image_service__struct.h"
// already included above
// #include "rl_custom_messages/srv/detail/image_service__functions.h"
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

#include "rl_custom_messages/msg/detail/image_array__functions.h"  // image_data

// forward declare type support functions
size_t get_serialized_size_rl_custom_messages__msg__ImageArray(
  const void * untyped_ros_message,
  size_t current_alignment);

size_t max_serialized_size_rl_custom_messages__msg__ImageArray(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, rl_custom_messages, msg, ImageArray)();


using _ImageService_Response__ros_msg_type = rl_custom_messages__srv__ImageService_Response;

static bool _ImageService_Response__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _ImageService_Response__ros_msg_type * ros_message = static_cast<const _ImageService_Response__ros_msg_type *>(untyped_ros_message);
  // Field name: image_data
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, rl_custom_messages, msg, ImageArray
      )()->data);
    if (!callbacks->cdr_serialize(
        &ros_message->image_data, cdr))
    {
      return false;
    }
  }

  return true;
}

static bool _ImageService_Response__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _ImageService_Response__ros_msg_type * ros_message = static_cast<_ImageService_Response__ros_msg_type *>(untyped_ros_message);
  // Field name: image_data
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, rl_custom_messages, msg, ImageArray
      )()->data);
    if (!callbacks->cdr_deserialize(
        cdr, &ros_message->image_data))
    {
      return false;
    }
  }

  return true;
}  // NOLINT(readability/fn_size)

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_rl_custom_messages
size_t get_serialized_size_rl_custom_messages__srv__ImageService_Response(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _ImageService_Response__ros_msg_type * ros_message = static_cast<const _ImageService_Response__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name image_data

  current_alignment += get_serialized_size_rl_custom_messages__msg__ImageArray(
    &(ros_message->image_data), current_alignment);

  return current_alignment - initial_alignment;
}

static uint32_t _ImageService_Response__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_rl_custom_messages__srv__ImageService_Response(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_rl_custom_messages
size_t max_serialized_size_rl_custom_messages__srv__ImageService_Response(
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

  // member: image_data
  {
    size_t array_size = 1;


    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      current_alignment +=
        max_serialized_size_rl_custom_messages__msg__ImageArray(
        inner_full_bounded, inner_is_plain, current_alignment);
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  return current_alignment - initial_alignment;
}

static size_t _ImageService_Response__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_rl_custom_messages__srv__ImageService_Response(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_ImageService_Response = {
  "rl_custom_messages::srv",
  "ImageService_Response",
  _ImageService_Response__cdr_serialize,
  _ImageService_Response__cdr_deserialize,
  _ImageService_Response__get_serialized_size,
  _ImageService_Response__max_serialized_size
};

static rosidl_message_type_support_t _ImageService_Response__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_ImageService_Response,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, rl_custom_messages, srv, ImageService_Response)() {
  return &_ImageService_Response__type_support;
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
#include "rl_custom_messages/srv/image_service.h"

#if defined(__cplusplus)
extern "C"
{
#endif

static service_type_support_callbacks_t ImageService__callbacks = {
  "rl_custom_messages::srv",
  "ImageService",
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, rl_custom_messages, srv, ImageService_Request)(),
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, rl_custom_messages, srv, ImageService_Response)(),
};

static rosidl_service_type_support_t ImageService__handle = {
  rosidl_typesupport_fastrtps_c__identifier,
  &ImageService__callbacks,
  get_service_typesupport_handle_function,
};

const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, rl_custom_messages, srv, ImageService)() {
  return &ImageService__handle;
}

#if defined(__cplusplus)
}
#endif
