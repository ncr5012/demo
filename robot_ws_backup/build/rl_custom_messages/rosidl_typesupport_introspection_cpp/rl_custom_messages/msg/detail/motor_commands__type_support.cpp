// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from rl_custom_messages:msg/MotorCommands.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "rl_custom_messages/msg/detail/motor_commands__struct.hpp"
#include "rosidl_typesupport_introspection_cpp/field_types.hpp"
#include "rosidl_typesupport_introspection_cpp/identifier.hpp"
#include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
#include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace rl_custom_messages
{

namespace msg
{

namespace rosidl_typesupport_introspection_cpp
{

void MotorCommands_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) rl_custom_messages::msg::MotorCommands(_init);
}

void MotorCommands_fini_function(void * message_memory)
{
  auto typed_message = static_cast<rl_custom_messages::msg::MotorCommands *>(message_memory);
  typed_message->~MotorCommands();
}

size_t size_function__MotorCommands__commands(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<int32_t> *>(untyped_member);
  return member->size();
}

const void * get_const_function__MotorCommands__commands(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<int32_t> *>(untyped_member);
  return &member[index];
}

void * get_function__MotorCommands__commands(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<int32_t> *>(untyped_member);
  return &member[index];
}

void fetch_function__MotorCommands__commands(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const int32_t *>(
    get_const_function__MotorCommands__commands(untyped_member, index));
  auto & value = *reinterpret_cast<int32_t *>(untyped_value);
  value = item;
}

void assign_function__MotorCommands__commands(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<int32_t *>(
    get_function__MotorCommands__commands(untyped_member, index));
  const auto & value = *reinterpret_cast<const int32_t *>(untyped_value);
  item = value;
}

void resize_function__MotorCommands__commands(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<int32_t> *>(untyped_member);
  member->resize(size);
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember MotorCommands_message_member_array[1] = {
  {
    "commands",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_INT32,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(rl_custom_messages::msg::MotorCommands, commands),  // bytes offset in struct
    nullptr,  // default value
    size_function__MotorCommands__commands,  // size() function pointer
    get_const_function__MotorCommands__commands,  // get_const(index) function pointer
    get_function__MotorCommands__commands,  // get(index) function pointer
    fetch_function__MotorCommands__commands,  // fetch(index, &value) function pointer
    assign_function__MotorCommands__commands,  // assign(index, value) function pointer
    resize_function__MotorCommands__commands  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers MotorCommands_message_members = {
  "rl_custom_messages::msg",  // message namespace
  "MotorCommands",  // message name
  1,  // number of fields
  sizeof(rl_custom_messages::msg::MotorCommands),
  MotorCommands_message_member_array,  // message members
  MotorCommands_init_function,  // function to initialize message memory (memory has to be allocated)
  MotorCommands_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t MotorCommands_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &MotorCommands_message_members,
  get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace msg

}  // namespace rl_custom_messages


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<rl_custom_messages::msg::MotorCommands>()
{
  return &::rl_custom_messages::msg::rosidl_typesupport_introspection_cpp::MotorCommands_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, rl_custom_messages, msg, MotorCommands)() {
  return &::rl_custom_messages::msg::rosidl_typesupport_introspection_cpp::MotorCommands_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
