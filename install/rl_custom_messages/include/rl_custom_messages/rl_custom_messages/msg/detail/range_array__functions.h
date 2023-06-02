// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from rl_custom_messages:msg/RangeArray.idl
// generated code does not contain a copyright notice

#ifndef RL_CUSTOM_MESSAGES__MSG__DETAIL__RANGE_ARRAY__FUNCTIONS_H_
#define RL_CUSTOM_MESSAGES__MSG__DETAIL__RANGE_ARRAY__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "rl_custom_messages/msg/rosidl_generator_c__visibility_control.h"

#include "rl_custom_messages/msg/detail/range_array__struct.h"

/// Initialize msg/RangeArray message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * rl_custom_messages__msg__RangeArray
 * )) before or use
 * rl_custom_messages__msg__RangeArray__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_rl_custom_messages
bool
rl_custom_messages__msg__RangeArray__init(rl_custom_messages__msg__RangeArray * msg);

/// Finalize msg/RangeArray message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_rl_custom_messages
void
rl_custom_messages__msg__RangeArray__fini(rl_custom_messages__msg__RangeArray * msg);

/// Create msg/RangeArray message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * rl_custom_messages__msg__RangeArray__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_rl_custom_messages
rl_custom_messages__msg__RangeArray *
rl_custom_messages__msg__RangeArray__create();

/// Destroy msg/RangeArray message.
/**
 * It calls
 * rl_custom_messages__msg__RangeArray__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_rl_custom_messages
void
rl_custom_messages__msg__RangeArray__destroy(rl_custom_messages__msg__RangeArray * msg);

/// Check for msg/RangeArray message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_rl_custom_messages
bool
rl_custom_messages__msg__RangeArray__are_equal(const rl_custom_messages__msg__RangeArray * lhs, const rl_custom_messages__msg__RangeArray * rhs);

/// Copy a msg/RangeArray message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_rl_custom_messages
bool
rl_custom_messages__msg__RangeArray__copy(
  const rl_custom_messages__msg__RangeArray * input,
  rl_custom_messages__msg__RangeArray * output);

/// Initialize array of msg/RangeArray messages.
/**
 * It allocates the memory for the number of elements and calls
 * rl_custom_messages__msg__RangeArray__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_rl_custom_messages
bool
rl_custom_messages__msg__RangeArray__Sequence__init(rl_custom_messages__msg__RangeArray__Sequence * array, size_t size);

/// Finalize array of msg/RangeArray messages.
/**
 * It calls
 * rl_custom_messages__msg__RangeArray__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_rl_custom_messages
void
rl_custom_messages__msg__RangeArray__Sequence__fini(rl_custom_messages__msg__RangeArray__Sequence * array);

/// Create array of msg/RangeArray messages.
/**
 * It allocates the memory for the array and calls
 * rl_custom_messages__msg__RangeArray__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_rl_custom_messages
rl_custom_messages__msg__RangeArray__Sequence *
rl_custom_messages__msg__RangeArray__Sequence__create(size_t size);

/// Destroy array of msg/RangeArray messages.
/**
 * It calls
 * rl_custom_messages__msg__RangeArray__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_rl_custom_messages
void
rl_custom_messages__msg__RangeArray__Sequence__destroy(rl_custom_messages__msg__RangeArray__Sequence * array);

/// Check for msg/RangeArray message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_rl_custom_messages
bool
rl_custom_messages__msg__RangeArray__Sequence__are_equal(const rl_custom_messages__msg__RangeArray__Sequence * lhs, const rl_custom_messages__msg__RangeArray__Sequence * rhs);

/// Copy an array of msg/RangeArray messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_rl_custom_messages
bool
rl_custom_messages__msg__RangeArray__Sequence__copy(
  const rl_custom_messages__msg__RangeArray__Sequence * input,
  rl_custom_messages__msg__RangeArray__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // RL_CUSTOM_MESSAGES__MSG__DETAIL__RANGE_ARRAY__FUNCTIONS_H_
