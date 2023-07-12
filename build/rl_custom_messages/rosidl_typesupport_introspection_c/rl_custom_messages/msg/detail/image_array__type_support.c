// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from rl_custom_messages:msg/ImageArray.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "rl_custom_messages/msg/detail/image_array__rosidl_typesupport_introspection_c.h"
#include "rl_custom_messages/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "rl_custom_messages/msg/detail/image_array__functions.h"
#include "rl_custom_messages/msg/detail/image_array__struct.h"


// Include directives for member types
// Member `encoding`
#include "rosidl_runtime_c/string_functions.h"
// Member `data`
#include "rosidl_runtime_c/primitives_sequence_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void rl_custom_messages__msg__ImageArray__rosidl_typesupport_introspection_c__ImageArray_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  rl_custom_messages__msg__ImageArray__init(message_memory);
}

void rl_custom_messages__msg__ImageArray__rosidl_typesupport_introspection_c__ImageArray_fini_function(void * message_memory)
{
  rl_custom_messages__msg__ImageArray__fini(message_memory);
}

size_t rl_custom_messages__msg__ImageArray__rosidl_typesupport_introspection_c__size_function__ImageArray__data(
  const void * untyped_member)
{
  const rosidl_runtime_c__uint8__Sequence * member =
    (const rosidl_runtime_c__uint8__Sequence *)(untyped_member);
  return member->size;
}

const void * rl_custom_messages__msg__ImageArray__rosidl_typesupport_introspection_c__get_const_function__ImageArray__data(
  const void * untyped_member, size_t index)
{
  const rosidl_runtime_c__uint8__Sequence * member =
    (const rosidl_runtime_c__uint8__Sequence *)(untyped_member);
  return &member->data[index];
}

void * rl_custom_messages__msg__ImageArray__rosidl_typesupport_introspection_c__get_function__ImageArray__data(
  void * untyped_member, size_t index)
{
  rosidl_runtime_c__uint8__Sequence * member =
    (rosidl_runtime_c__uint8__Sequence *)(untyped_member);
  return &member->data[index];
}

void rl_custom_messages__msg__ImageArray__rosidl_typesupport_introspection_c__fetch_function__ImageArray__data(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const uint8_t * item =
    ((const uint8_t *)
    rl_custom_messages__msg__ImageArray__rosidl_typesupport_introspection_c__get_const_function__ImageArray__data(untyped_member, index));
  uint8_t * value =
    (uint8_t *)(untyped_value);
  *value = *item;
}

void rl_custom_messages__msg__ImageArray__rosidl_typesupport_introspection_c__assign_function__ImageArray__data(
  void * untyped_member, size_t index, const void * untyped_value)
{
  uint8_t * item =
    ((uint8_t *)
    rl_custom_messages__msg__ImageArray__rosidl_typesupport_introspection_c__get_function__ImageArray__data(untyped_member, index));
  const uint8_t * value =
    (const uint8_t *)(untyped_value);
  *item = *value;
}

bool rl_custom_messages__msg__ImageArray__rosidl_typesupport_introspection_c__resize_function__ImageArray__data(
  void * untyped_member, size_t size)
{
  rosidl_runtime_c__uint8__Sequence * member =
    (rosidl_runtime_c__uint8__Sequence *)(untyped_member);
  rosidl_runtime_c__uint8__Sequence__fini(member);
  return rosidl_runtime_c__uint8__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember rl_custom_messages__msg__ImageArray__rosidl_typesupport_introspection_c__ImageArray_message_member_array[4] = {
  {
    "height",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(rl_custom_messages__msg__ImageArray, height),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "width",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(rl_custom_messages__msg__ImageArray, width),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "encoding",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(rl_custom_messages__msg__ImageArray, encoding),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "data",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(rl_custom_messages__msg__ImageArray, data),  // bytes offset in struct
    NULL,  // default value
    rl_custom_messages__msg__ImageArray__rosidl_typesupport_introspection_c__size_function__ImageArray__data,  // size() function pointer
    rl_custom_messages__msg__ImageArray__rosidl_typesupport_introspection_c__get_const_function__ImageArray__data,  // get_const(index) function pointer
    rl_custom_messages__msg__ImageArray__rosidl_typesupport_introspection_c__get_function__ImageArray__data,  // get(index) function pointer
    rl_custom_messages__msg__ImageArray__rosidl_typesupport_introspection_c__fetch_function__ImageArray__data,  // fetch(index, &value) function pointer
    rl_custom_messages__msg__ImageArray__rosidl_typesupport_introspection_c__assign_function__ImageArray__data,  // assign(index, value) function pointer
    rl_custom_messages__msg__ImageArray__rosidl_typesupport_introspection_c__resize_function__ImageArray__data  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers rl_custom_messages__msg__ImageArray__rosidl_typesupport_introspection_c__ImageArray_message_members = {
  "rl_custom_messages__msg",  // message namespace
  "ImageArray",  // message name
  4,  // number of fields
  sizeof(rl_custom_messages__msg__ImageArray),
  rl_custom_messages__msg__ImageArray__rosidl_typesupport_introspection_c__ImageArray_message_member_array,  // message members
  rl_custom_messages__msg__ImageArray__rosidl_typesupport_introspection_c__ImageArray_init_function,  // function to initialize message memory (memory has to be allocated)
  rl_custom_messages__msg__ImageArray__rosidl_typesupport_introspection_c__ImageArray_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t rl_custom_messages__msg__ImageArray__rosidl_typesupport_introspection_c__ImageArray_message_type_support_handle = {
  0,
  &rl_custom_messages__msg__ImageArray__rosidl_typesupport_introspection_c__ImageArray_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_rl_custom_messages
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, rl_custom_messages, msg, ImageArray)() {
  if (!rl_custom_messages__msg__ImageArray__rosidl_typesupport_introspection_c__ImageArray_message_type_support_handle.typesupport_identifier) {
    rl_custom_messages__msg__ImageArray__rosidl_typesupport_introspection_c__ImageArray_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &rl_custom_messages__msg__ImageArray__rosidl_typesupport_introspection_c__ImageArray_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
