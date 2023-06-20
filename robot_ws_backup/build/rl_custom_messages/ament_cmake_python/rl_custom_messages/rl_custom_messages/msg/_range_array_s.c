// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from rl_custom_messages:msg/RangeArray.idl
// generated code does not contain a copyright notice
#define NPY_NO_DEPRECATED_API NPY_1_7_API_VERSION
#include <Python.h>
#include <stdbool.h>
#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-function"
#endif
#include "numpy/ndarrayobject.h"
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif
#include "rosidl_runtime_c/visibility_control.h"
#include "rl_custom_messages/msg/detail/range_array__struct.h"
#include "rl_custom_messages/msg/detail/range_array__functions.h"


ROSIDL_GENERATOR_C_EXPORT
bool rl_custom_messages__msg__range_array__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[47];
    {
      char * class_name = NULL;
      char * module_name = NULL;
      {
        PyObject * class_attr = PyObject_GetAttrString(_pymsg, "__class__");
        if (class_attr) {
          PyObject * name_attr = PyObject_GetAttrString(class_attr, "__name__");
          if (name_attr) {
            class_name = (char *)PyUnicode_1BYTE_DATA(name_attr);
            Py_DECREF(name_attr);
          }
          PyObject * module_attr = PyObject_GetAttrString(class_attr, "__module__");
          if (module_attr) {
            module_name = (char *)PyUnicode_1BYTE_DATA(module_attr);
            Py_DECREF(module_attr);
          }
          Py_DECREF(class_attr);
        }
      }
      if (!class_name || !module_name) {
        return false;
      }
      snprintf(full_classname_dest, sizeof(full_classname_dest), "%s.%s", module_name, class_name);
    }
    assert(strncmp("rl_custom_messages.msg._range_array.RangeArray", full_classname_dest, 46) == 0);
  }
  rl_custom_messages__msg__RangeArray * ros_message = _ros_message;
  {  // range_left
    PyObject * field = PyObject_GetAttrString(_pymsg, "range_left");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->range_left = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // range_front
    PyObject * field = PyObject_GetAttrString(_pymsg, "range_front");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->range_front = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // range_right
    PyObject * field = PyObject_GetAttrString(_pymsg, "range_right");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->range_right = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // range_back
    PyObject * field = PyObject_GetAttrString(_pymsg, "range_back");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->range_back = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * rl_custom_messages__msg__range_array__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of RangeArray */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("rl_custom_messages.msg._range_array");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "RangeArray");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  rl_custom_messages__msg__RangeArray * ros_message = (rl_custom_messages__msg__RangeArray *)raw_ros_message;
  {  // range_left
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->range_left);
    {
      int rc = PyObject_SetAttrString(_pymessage, "range_left", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // range_front
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->range_front);
    {
      int rc = PyObject_SetAttrString(_pymessage, "range_front", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // range_right
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->range_right);
    {
      int rc = PyObject_SetAttrString(_pymessage, "range_right", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // range_back
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->range_back);
    {
      int rc = PyObject_SetAttrString(_pymessage, "range_back", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}
