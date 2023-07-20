// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from rl_custom_messages:srv/ObservationService.idl
// generated code does not contain a copyright notice
#include "rl_custom_messages/srv/detail/observation_service__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"

bool
rl_custom_messages__srv__ObservationService_Request__init(rl_custom_messages__srv__ObservationService_Request * msg)
{
  if (!msg) {
    return false;
  }
  // motor_action
  // sound_action
  return true;
}

void
rl_custom_messages__srv__ObservationService_Request__fini(rl_custom_messages__srv__ObservationService_Request * msg)
{
  if (!msg) {
    return;
  }
  // motor_action
  // sound_action
}

bool
rl_custom_messages__srv__ObservationService_Request__are_equal(const rl_custom_messages__srv__ObservationService_Request * lhs, const rl_custom_messages__srv__ObservationService_Request * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // motor_action
  for (size_t i = 0; i < 12; ++i) {
    if (lhs->motor_action[i] != rhs->motor_action[i]) {
      return false;
    }
  }
  // sound_action
  for (size_t i = 0; i < 1; ++i) {
    if (lhs->sound_action[i] != rhs->sound_action[i]) {
      return false;
    }
  }
  return true;
}

bool
rl_custom_messages__srv__ObservationService_Request__copy(
  const rl_custom_messages__srv__ObservationService_Request * input,
  rl_custom_messages__srv__ObservationService_Request * output)
{
  if (!input || !output) {
    return false;
  }
  // motor_action
  for (size_t i = 0; i < 12; ++i) {
    output->motor_action[i] = input->motor_action[i];
  }
  // sound_action
  for (size_t i = 0; i < 1; ++i) {
    output->sound_action[i] = input->sound_action[i];
  }
  return true;
}

rl_custom_messages__srv__ObservationService_Request *
rl_custom_messages__srv__ObservationService_Request__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  rl_custom_messages__srv__ObservationService_Request * msg = (rl_custom_messages__srv__ObservationService_Request *)allocator.allocate(sizeof(rl_custom_messages__srv__ObservationService_Request), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(rl_custom_messages__srv__ObservationService_Request));
  bool success = rl_custom_messages__srv__ObservationService_Request__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
rl_custom_messages__srv__ObservationService_Request__destroy(rl_custom_messages__srv__ObservationService_Request * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    rl_custom_messages__srv__ObservationService_Request__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
rl_custom_messages__srv__ObservationService_Request__Sequence__init(rl_custom_messages__srv__ObservationService_Request__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  rl_custom_messages__srv__ObservationService_Request * data = NULL;

  if (size) {
    data = (rl_custom_messages__srv__ObservationService_Request *)allocator.zero_allocate(size, sizeof(rl_custom_messages__srv__ObservationService_Request), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = rl_custom_messages__srv__ObservationService_Request__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        rl_custom_messages__srv__ObservationService_Request__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
rl_custom_messages__srv__ObservationService_Request__Sequence__fini(rl_custom_messages__srv__ObservationService_Request__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      rl_custom_messages__srv__ObservationService_Request__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

rl_custom_messages__srv__ObservationService_Request__Sequence *
rl_custom_messages__srv__ObservationService_Request__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  rl_custom_messages__srv__ObservationService_Request__Sequence * array = (rl_custom_messages__srv__ObservationService_Request__Sequence *)allocator.allocate(sizeof(rl_custom_messages__srv__ObservationService_Request__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = rl_custom_messages__srv__ObservationService_Request__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
rl_custom_messages__srv__ObservationService_Request__Sequence__destroy(rl_custom_messages__srv__ObservationService_Request__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    rl_custom_messages__srv__ObservationService_Request__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
rl_custom_messages__srv__ObservationService_Request__Sequence__are_equal(const rl_custom_messages__srv__ObservationService_Request__Sequence * lhs, const rl_custom_messages__srv__ObservationService_Request__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!rl_custom_messages__srv__ObservationService_Request__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
rl_custom_messages__srv__ObservationService_Request__Sequence__copy(
  const rl_custom_messages__srv__ObservationService_Request__Sequence * input,
  rl_custom_messages__srv__ObservationService_Request__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(rl_custom_messages__srv__ObservationService_Request);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    rl_custom_messages__srv__ObservationService_Request * data =
      (rl_custom_messages__srv__ObservationService_Request *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!rl_custom_messages__srv__ObservationService_Request__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          rl_custom_messages__srv__ObservationService_Request__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!rl_custom_messages__srv__ObservationService_Request__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `range_data`
#include "rl_custom_messages/msg/detail/range_array__functions.h"

bool
rl_custom_messages__srv__ObservationService_Response__init(rl_custom_messages__srv__ObservationService_Response * msg)
{
  if (!msg) {
    return false;
  }
  // range_data
  if (!rl_custom_messages__msg__RangeArray__init(&msg->range_data)) {
    rl_custom_messages__srv__ObservationService_Response__fini(msg);
    return false;
  }
  return true;
}

void
rl_custom_messages__srv__ObservationService_Response__fini(rl_custom_messages__srv__ObservationService_Response * msg)
{
  if (!msg) {
    return;
  }
  // range_data
  rl_custom_messages__msg__RangeArray__fini(&msg->range_data);
}

bool
rl_custom_messages__srv__ObservationService_Response__are_equal(const rl_custom_messages__srv__ObservationService_Response * lhs, const rl_custom_messages__srv__ObservationService_Response * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // range_data
  if (!rl_custom_messages__msg__RangeArray__are_equal(
      &(lhs->range_data), &(rhs->range_data)))
  {
    return false;
  }
  return true;
}

bool
rl_custom_messages__srv__ObservationService_Response__copy(
  const rl_custom_messages__srv__ObservationService_Response * input,
  rl_custom_messages__srv__ObservationService_Response * output)
{
  if (!input || !output) {
    return false;
  }
  // range_data
  if (!rl_custom_messages__msg__RangeArray__copy(
      &(input->range_data), &(output->range_data)))
  {
    return false;
  }
  return true;
}

rl_custom_messages__srv__ObservationService_Response *
rl_custom_messages__srv__ObservationService_Response__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  rl_custom_messages__srv__ObservationService_Response * msg = (rl_custom_messages__srv__ObservationService_Response *)allocator.allocate(sizeof(rl_custom_messages__srv__ObservationService_Response), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(rl_custom_messages__srv__ObservationService_Response));
  bool success = rl_custom_messages__srv__ObservationService_Response__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
rl_custom_messages__srv__ObservationService_Response__destroy(rl_custom_messages__srv__ObservationService_Response * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    rl_custom_messages__srv__ObservationService_Response__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
rl_custom_messages__srv__ObservationService_Response__Sequence__init(rl_custom_messages__srv__ObservationService_Response__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  rl_custom_messages__srv__ObservationService_Response * data = NULL;

  if (size) {
    data = (rl_custom_messages__srv__ObservationService_Response *)allocator.zero_allocate(size, sizeof(rl_custom_messages__srv__ObservationService_Response), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = rl_custom_messages__srv__ObservationService_Response__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        rl_custom_messages__srv__ObservationService_Response__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
rl_custom_messages__srv__ObservationService_Response__Sequence__fini(rl_custom_messages__srv__ObservationService_Response__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      rl_custom_messages__srv__ObservationService_Response__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

rl_custom_messages__srv__ObservationService_Response__Sequence *
rl_custom_messages__srv__ObservationService_Response__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  rl_custom_messages__srv__ObservationService_Response__Sequence * array = (rl_custom_messages__srv__ObservationService_Response__Sequence *)allocator.allocate(sizeof(rl_custom_messages__srv__ObservationService_Response__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = rl_custom_messages__srv__ObservationService_Response__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
rl_custom_messages__srv__ObservationService_Response__Sequence__destroy(rl_custom_messages__srv__ObservationService_Response__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    rl_custom_messages__srv__ObservationService_Response__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
rl_custom_messages__srv__ObservationService_Response__Sequence__are_equal(const rl_custom_messages__srv__ObservationService_Response__Sequence * lhs, const rl_custom_messages__srv__ObservationService_Response__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!rl_custom_messages__srv__ObservationService_Response__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
rl_custom_messages__srv__ObservationService_Response__Sequence__copy(
  const rl_custom_messages__srv__ObservationService_Response__Sequence * input,
  rl_custom_messages__srv__ObservationService_Response__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(rl_custom_messages__srv__ObservationService_Response);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    rl_custom_messages__srv__ObservationService_Response * data =
      (rl_custom_messages__srv__ObservationService_Response *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!rl_custom_messages__srv__ObservationService_Response__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          rl_custom_messages__srv__ObservationService_Response__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!rl_custom_messages__srv__ObservationService_Response__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
