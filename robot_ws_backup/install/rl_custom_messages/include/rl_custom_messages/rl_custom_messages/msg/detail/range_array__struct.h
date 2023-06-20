// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from rl_custom_messages:msg/RangeArray.idl
// generated code does not contain a copyright notice

#ifndef RL_CUSTOM_MESSAGES__MSG__DETAIL__RANGE_ARRAY__STRUCT_H_
#define RL_CUSTOM_MESSAGES__MSG__DETAIL__RANGE_ARRAY__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in msg/RangeArray in the package rl_custom_messages.
/**
  * RangeArray.msg
 */
typedef struct rl_custom_messages__msg__RangeArray
{
  double range_left;
  double range_front;
  double range_right;
  double range_back;
} rl_custom_messages__msg__RangeArray;

// Struct for a sequence of rl_custom_messages__msg__RangeArray.
typedef struct rl_custom_messages__msg__RangeArray__Sequence
{
  rl_custom_messages__msg__RangeArray * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} rl_custom_messages__msg__RangeArray__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // RL_CUSTOM_MESSAGES__MSG__DETAIL__RANGE_ARRAY__STRUCT_H_
