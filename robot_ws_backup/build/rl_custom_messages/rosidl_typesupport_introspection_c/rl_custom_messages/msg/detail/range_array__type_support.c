// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from rl_custom_messages:msg/RangeArray.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "rl_custom_messages/msg/detail/range_array__rosidl_typesupport_introspection_c.h"
#include "rl_custom_messages/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "rl_custom_messages/msg/detail/range_array__functions.h"
#include "rl_custom_messages/msg/detail/range_array__struct.h"


#ifdef __cplusplus
extern "C"
{
#endif

void rl_custom_messages__msg__RangeArray__rosidl_typesupport_introspection_c__RangeArray_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  rl_custom_messages__msg__RangeArray__init(message_memory);
}

void rl_custom_messages__msg__RangeArray__rosidl_typesupport_introspection_c__RangeArray_fini_function(void * message_memory)
{
  rl_custom_messages__msg__RangeArray__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember rl_custom_messages__msg__RangeArray__rosidl_typesupport_introspection_c__RangeArray_message_member_array[4] = {
  {
    "range_left",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(rl_custom_messages__msg__RangeArray, range_left),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "range_front",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(rl_custom_messages__msg__RangeArray, range_front),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "range_right",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(rl_custom_messages__msg__RangeArray, range_right),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "range_back",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(rl_custom_messages__msg__RangeArray, range_back),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers rl_custom_messages__msg__RangeArray__rosidl_typesupport_introspection_c__RangeArray_message_members = {
  "rl_custom_messages__msg",  // message namespace
  "RangeArray",  // message name
  4,  // number of fields
  sizeof(rl_custom_messages__msg__RangeArray),
  rl_custom_messages__msg__RangeArray__rosidl_typesupport_introspection_c__RangeArray_message_member_array,  // message members
  rl_custom_messages__msg__RangeArray__rosidl_typesupport_introspection_c__RangeArray_init_function,  // function to initialize message memory (memory has to be allocated)
  rl_custom_messages__msg__RangeArray__rosidl_typesupport_introspection_c__RangeArray_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t rl_custom_messages__msg__RangeArray__rosidl_typesupport_introspection_c__RangeArray_message_type_support_handle = {
  0,
  &rl_custom_messages__msg__RangeArray__rosidl_typesupport_introspection_c__RangeArray_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_rl_custom_messages
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, rl_custom_messages, msg, RangeArray)() {
  if (!rl_custom_messages__msg__RangeArray__rosidl_typesupport_introspection_c__RangeArray_message_type_support_handle.typesupport_identifier) {
    rl_custom_messages__msg__RangeArray__rosidl_typesupport_introspection_c__RangeArray_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &rl_custom_messages__msg__RangeArray__rosidl_typesupport_introspection_c__RangeArray_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
