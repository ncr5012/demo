// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from rl_custom_messages:msg/MotorCommands.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "rl_custom_messages/msg/detail/motor_commands__rosidl_typesupport_introspection_c.h"
#include "rl_custom_messages/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "rl_custom_messages/msg/detail/motor_commands__functions.h"
#include "rl_custom_messages/msg/detail/motor_commands__struct.h"


// Include directives for member types
// Member `commands`
#include "rosidl_runtime_c/primitives_sequence_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void rl_custom_messages__msg__MotorCommands__rosidl_typesupport_introspection_c__MotorCommands_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  rl_custom_messages__msg__MotorCommands__init(message_memory);
}

void rl_custom_messages__msg__MotorCommands__rosidl_typesupport_introspection_c__MotorCommands_fini_function(void * message_memory)
{
  rl_custom_messages__msg__MotorCommands__fini(message_memory);
}

size_t rl_custom_messages__msg__MotorCommands__rosidl_typesupport_introspection_c__size_function__MotorCommands__commands(
  const void * untyped_member)
{
  const rosidl_runtime_c__int32__Sequence * member =
    (const rosidl_runtime_c__int32__Sequence *)(untyped_member);
  return member->size;
}

const void * rl_custom_messages__msg__MotorCommands__rosidl_typesupport_introspection_c__get_const_function__MotorCommands__commands(
  const void * untyped_member, size_t index)
{
  const rosidl_runtime_c__int32__Sequence * member =
    (const rosidl_runtime_c__int32__Sequence *)(untyped_member);
  return &member->data[index];
}

void * rl_custom_messages__msg__MotorCommands__rosidl_typesupport_introspection_c__get_function__MotorCommands__commands(
  void * untyped_member, size_t index)
{
  rosidl_runtime_c__int32__Sequence * member =
    (rosidl_runtime_c__int32__Sequence *)(untyped_member);
  return &member->data[index];
}

void rl_custom_messages__msg__MotorCommands__rosidl_typesupport_introspection_c__fetch_function__MotorCommands__commands(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const int32_t * item =
    ((const int32_t *)
    rl_custom_messages__msg__MotorCommands__rosidl_typesupport_introspection_c__get_const_function__MotorCommands__commands(untyped_member, index));
  int32_t * value =
    (int32_t *)(untyped_value);
  *value = *item;
}

void rl_custom_messages__msg__MotorCommands__rosidl_typesupport_introspection_c__assign_function__MotorCommands__commands(
  void * untyped_member, size_t index, const void * untyped_value)
{
  int32_t * item =
    ((int32_t *)
    rl_custom_messages__msg__MotorCommands__rosidl_typesupport_introspection_c__get_function__MotorCommands__commands(untyped_member, index));
  const int32_t * value =
    (const int32_t *)(untyped_value);
  *item = *value;
}

bool rl_custom_messages__msg__MotorCommands__rosidl_typesupport_introspection_c__resize_function__MotorCommands__commands(
  void * untyped_member, size_t size)
{
  rosidl_runtime_c__int32__Sequence * member =
    (rosidl_runtime_c__int32__Sequence *)(untyped_member);
  rosidl_runtime_c__int32__Sequence__fini(member);
  return rosidl_runtime_c__int32__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember rl_custom_messages__msg__MotorCommands__rosidl_typesupport_introspection_c__MotorCommands_message_member_array[1] = {
  {
    "commands",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(rl_custom_messages__msg__MotorCommands, commands),  // bytes offset in struct
    NULL,  // default value
    rl_custom_messages__msg__MotorCommands__rosidl_typesupport_introspection_c__size_function__MotorCommands__commands,  // size() function pointer
    rl_custom_messages__msg__MotorCommands__rosidl_typesupport_introspection_c__get_const_function__MotorCommands__commands,  // get_const(index) function pointer
    rl_custom_messages__msg__MotorCommands__rosidl_typesupport_introspection_c__get_function__MotorCommands__commands,  // get(index) function pointer
    rl_custom_messages__msg__MotorCommands__rosidl_typesupport_introspection_c__fetch_function__MotorCommands__commands,  // fetch(index, &value) function pointer
    rl_custom_messages__msg__MotorCommands__rosidl_typesupport_introspection_c__assign_function__MotorCommands__commands,  // assign(index, value) function pointer
    rl_custom_messages__msg__MotorCommands__rosidl_typesupport_introspection_c__resize_function__MotorCommands__commands  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers rl_custom_messages__msg__MotorCommands__rosidl_typesupport_introspection_c__MotorCommands_message_members = {
  "rl_custom_messages__msg",  // message namespace
  "MotorCommands",  // message name
  1,  // number of fields
  sizeof(rl_custom_messages__msg__MotorCommands),
  rl_custom_messages__msg__MotorCommands__rosidl_typesupport_introspection_c__MotorCommands_message_member_array,  // message members
  rl_custom_messages__msg__MotorCommands__rosidl_typesupport_introspection_c__MotorCommands_init_function,  // function to initialize message memory (memory has to be allocated)
  rl_custom_messages__msg__MotorCommands__rosidl_typesupport_introspection_c__MotorCommands_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t rl_custom_messages__msg__MotorCommands__rosidl_typesupport_introspection_c__MotorCommands_message_type_support_handle = {
  0,
  &rl_custom_messages__msg__MotorCommands__rosidl_typesupport_introspection_c__MotorCommands_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_rl_custom_messages
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, rl_custom_messages, msg, MotorCommands)() {
  if (!rl_custom_messages__msg__MotorCommands__rosidl_typesupport_introspection_c__MotorCommands_message_type_support_handle.typesupport_identifier) {
    rl_custom_messages__msg__MotorCommands__rosidl_typesupport_introspection_c__MotorCommands_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &rl_custom_messages__msg__MotorCommands__rosidl_typesupport_introspection_c__MotorCommands_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
