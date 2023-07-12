// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from rl_custom_messages:msg/AudioData.idl
// generated code does not contain a copyright notice

#ifndef RL_CUSTOM_MESSAGES__MSG__DETAIL__AUDIO_DATA__STRUCT_H_
#define RL_CUSTOM_MESSAGES__MSG__DETAIL__AUDIO_DATA__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'data'
#include "rosidl_runtime_c/primitives_sequence.h"

/// Struct defined in msg/AudioData in the package rl_custom_messages.
typedef struct rl_custom_messages__msg__AudioData
{
  uint32_t sample_rate;
  uint16_t channels;
  rosidl_runtime_c__int16__Sequence data;
} rl_custom_messages__msg__AudioData;

// Struct for a sequence of rl_custom_messages__msg__AudioData.
typedef struct rl_custom_messages__msg__AudioData__Sequence
{
  rl_custom_messages__msg__AudioData * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} rl_custom_messages__msg__AudioData__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // RL_CUSTOM_MESSAGES__MSG__DETAIL__AUDIO_DATA__STRUCT_H_
