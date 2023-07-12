// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from rl_custom_messages:msg/ImageArray.idl
// generated code does not contain a copyright notice

#ifndef RL_CUSTOM_MESSAGES__MSG__DETAIL__IMAGE_ARRAY__STRUCT_H_
#define RL_CUSTOM_MESSAGES__MSG__DETAIL__IMAGE_ARRAY__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'encoding'
#include "rosidl_runtime_c/string.h"
// Member 'data'
#include "rosidl_runtime_c/primitives_sequence.h"

/// Struct defined in msg/ImageArray in the package rl_custom_messages.
/**
  * The height and width of the image
 */
typedef struct rl_custom_messages__msg__ImageArray
{
  uint32_t height;
  uint32_t width;
  /// Image encoding (e.g., "rgb8", "bgr8", "mono8")
  rosidl_runtime_c__String encoding;
  /// Image data
  rosidl_runtime_c__uint8__Sequence data;
} rl_custom_messages__msg__ImageArray;

// Struct for a sequence of rl_custom_messages__msg__ImageArray.
typedef struct rl_custom_messages__msg__ImageArray__Sequence
{
  rl_custom_messages__msg__ImageArray * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} rl_custom_messages__msg__ImageArray__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // RL_CUSTOM_MESSAGES__MSG__DETAIL__IMAGE_ARRAY__STRUCT_H_
