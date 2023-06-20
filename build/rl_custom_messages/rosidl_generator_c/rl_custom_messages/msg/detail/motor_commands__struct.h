// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from rl_custom_messages:msg/MotorCommands.idl
// generated code does not contain a copyright notice

#ifndef RL_CUSTOM_MESSAGES__MSG__DETAIL__MOTOR_COMMANDS__STRUCT_H_
#define RL_CUSTOM_MESSAGES__MSG__DETAIL__MOTOR_COMMANDS__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'commands'
#include "rosidl_runtime_c/primitives_sequence.h"

/// Struct defined in msg/MotorCommands in the package rl_custom_messages.
typedef struct rl_custom_messages__msg__MotorCommands
{
  rosidl_runtime_c__int32__Sequence commands;
} rl_custom_messages__msg__MotorCommands;

// Struct for a sequence of rl_custom_messages__msg__MotorCommands.
typedef struct rl_custom_messages__msg__MotorCommands__Sequence
{
  rl_custom_messages__msg__MotorCommands * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} rl_custom_messages__msg__MotorCommands__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // RL_CUSTOM_MESSAGES__MSG__DETAIL__MOTOR_COMMANDS__STRUCT_H_
