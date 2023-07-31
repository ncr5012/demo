// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from rl_custom_messages:srv/EmotionService.idl
// generated code does not contain a copyright notice

#ifndef RL_CUSTOM_MESSAGES__SRV__DETAIL__EMOTION_SERVICE__FUNCTIONS_H_
#define RL_CUSTOM_MESSAGES__SRV__DETAIL__EMOTION_SERVICE__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "rl_custom_messages/msg/rosidl_generator_c__visibility_control.h"

#include "rl_custom_messages/srv/detail/emotion_service__struct.h"

/// Initialize srv/EmotionService message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * rl_custom_messages__srv__EmotionService_Request
 * )) before or use
 * rl_custom_messages__srv__EmotionService_Request__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_rl_custom_messages
bool
rl_custom_messages__srv__EmotionService_Request__init(rl_custom_messages__srv__EmotionService_Request * msg);

/// Finalize srv/EmotionService message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_rl_custom_messages
void
rl_custom_messages__srv__EmotionService_Request__fini(rl_custom_messages__srv__EmotionService_Request * msg);

/// Create srv/EmotionService message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * rl_custom_messages__srv__EmotionService_Request__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_rl_custom_messages
rl_custom_messages__srv__EmotionService_Request *
rl_custom_messages__srv__EmotionService_Request__create();

/// Destroy srv/EmotionService message.
/**
 * It calls
 * rl_custom_messages__srv__EmotionService_Request__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_rl_custom_messages
void
rl_custom_messages__srv__EmotionService_Request__destroy(rl_custom_messages__srv__EmotionService_Request * msg);

/// Check for srv/EmotionService message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_rl_custom_messages
bool
rl_custom_messages__srv__EmotionService_Request__are_equal(const rl_custom_messages__srv__EmotionService_Request * lhs, const rl_custom_messages__srv__EmotionService_Request * rhs);

/// Copy a srv/EmotionService message.
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
rl_custom_messages__srv__EmotionService_Request__copy(
  const rl_custom_messages__srv__EmotionService_Request * input,
  rl_custom_messages__srv__EmotionService_Request * output);

/// Initialize array of srv/EmotionService messages.
/**
 * It allocates the memory for the number of elements and calls
 * rl_custom_messages__srv__EmotionService_Request__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_rl_custom_messages
bool
rl_custom_messages__srv__EmotionService_Request__Sequence__init(rl_custom_messages__srv__EmotionService_Request__Sequence * array, size_t size);

/// Finalize array of srv/EmotionService messages.
/**
 * It calls
 * rl_custom_messages__srv__EmotionService_Request__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_rl_custom_messages
void
rl_custom_messages__srv__EmotionService_Request__Sequence__fini(rl_custom_messages__srv__EmotionService_Request__Sequence * array);

/// Create array of srv/EmotionService messages.
/**
 * It allocates the memory for the array and calls
 * rl_custom_messages__srv__EmotionService_Request__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_rl_custom_messages
rl_custom_messages__srv__EmotionService_Request__Sequence *
rl_custom_messages__srv__EmotionService_Request__Sequence__create(size_t size);

/// Destroy array of srv/EmotionService messages.
/**
 * It calls
 * rl_custom_messages__srv__EmotionService_Request__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_rl_custom_messages
void
rl_custom_messages__srv__EmotionService_Request__Sequence__destroy(rl_custom_messages__srv__EmotionService_Request__Sequence * array);

/// Check for srv/EmotionService message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_rl_custom_messages
bool
rl_custom_messages__srv__EmotionService_Request__Sequence__are_equal(const rl_custom_messages__srv__EmotionService_Request__Sequence * lhs, const rl_custom_messages__srv__EmotionService_Request__Sequence * rhs);

/// Copy an array of srv/EmotionService messages.
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
rl_custom_messages__srv__EmotionService_Request__Sequence__copy(
  const rl_custom_messages__srv__EmotionService_Request__Sequence * input,
  rl_custom_messages__srv__EmotionService_Request__Sequence * output);

/// Initialize srv/EmotionService message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * rl_custom_messages__srv__EmotionService_Response
 * )) before or use
 * rl_custom_messages__srv__EmotionService_Response__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_rl_custom_messages
bool
rl_custom_messages__srv__EmotionService_Response__init(rl_custom_messages__srv__EmotionService_Response * msg);

/// Finalize srv/EmotionService message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_rl_custom_messages
void
rl_custom_messages__srv__EmotionService_Response__fini(rl_custom_messages__srv__EmotionService_Response * msg);

/// Create srv/EmotionService message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * rl_custom_messages__srv__EmotionService_Response__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_rl_custom_messages
rl_custom_messages__srv__EmotionService_Response *
rl_custom_messages__srv__EmotionService_Response__create();

/// Destroy srv/EmotionService message.
/**
 * It calls
 * rl_custom_messages__srv__EmotionService_Response__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_rl_custom_messages
void
rl_custom_messages__srv__EmotionService_Response__destroy(rl_custom_messages__srv__EmotionService_Response * msg);

/// Check for srv/EmotionService message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_rl_custom_messages
bool
rl_custom_messages__srv__EmotionService_Response__are_equal(const rl_custom_messages__srv__EmotionService_Response * lhs, const rl_custom_messages__srv__EmotionService_Response * rhs);

/// Copy a srv/EmotionService message.
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
rl_custom_messages__srv__EmotionService_Response__copy(
  const rl_custom_messages__srv__EmotionService_Response * input,
  rl_custom_messages__srv__EmotionService_Response * output);

/// Initialize array of srv/EmotionService messages.
/**
 * It allocates the memory for the number of elements and calls
 * rl_custom_messages__srv__EmotionService_Response__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_rl_custom_messages
bool
rl_custom_messages__srv__EmotionService_Response__Sequence__init(rl_custom_messages__srv__EmotionService_Response__Sequence * array, size_t size);

/// Finalize array of srv/EmotionService messages.
/**
 * It calls
 * rl_custom_messages__srv__EmotionService_Response__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_rl_custom_messages
void
rl_custom_messages__srv__EmotionService_Response__Sequence__fini(rl_custom_messages__srv__EmotionService_Response__Sequence * array);

/// Create array of srv/EmotionService messages.
/**
 * It allocates the memory for the array and calls
 * rl_custom_messages__srv__EmotionService_Response__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_rl_custom_messages
rl_custom_messages__srv__EmotionService_Response__Sequence *
rl_custom_messages__srv__EmotionService_Response__Sequence__create(size_t size);

/// Destroy array of srv/EmotionService messages.
/**
 * It calls
 * rl_custom_messages__srv__EmotionService_Response__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_rl_custom_messages
void
rl_custom_messages__srv__EmotionService_Response__Sequence__destroy(rl_custom_messages__srv__EmotionService_Response__Sequence * array);

/// Check for srv/EmotionService message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_rl_custom_messages
bool
rl_custom_messages__srv__EmotionService_Response__Sequence__are_equal(const rl_custom_messages__srv__EmotionService_Response__Sequence * lhs, const rl_custom_messages__srv__EmotionService_Response__Sequence * rhs);

/// Copy an array of srv/EmotionService messages.
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
rl_custom_messages__srv__EmotionService_Response__Sequence__copy(
  const rl_custom_messages__srv__EmotionService_Response__Sequence * input,
  rl_custom_messages__srv__EmotionService_Response__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // RL_CUSTOM_MESSAGES__SRV__DETAIL__EMOTION_SERVICE__FUNCTIONS_H_
