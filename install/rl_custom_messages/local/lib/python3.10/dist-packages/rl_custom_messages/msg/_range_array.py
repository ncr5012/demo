# generated from rosidl_generator_py/resource/_idl.py.em
# with input from rl_custom_messages:msg/RangeArray.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import math  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_RangeArray(type):
    """Metaclass of message 'RangeArray'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
    }

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('rl_custom_messages')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'rl_custom_messages.msg.RangeArray')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__range_array
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__range_array
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__range_array
            cls._TYPE_SUPPORT = module.type_support_msg__msg__range_array
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__range_array

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class RangeArray(metaclass=Metaclass_RangeArray):
    """Message class 'RangeArray'."""

    __slots__ = [
        '_range_left',
        '_range_front',
        '_range_right',
        '_range_back',
    ]

    _fields_and_field_types = {
        'range_left': 'double',
        'range_front': 'double',
        'range_right': 'double',
        'range_back': 'double',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.range_left = kwargs.get('range_left', float())
        self.range_front = kwargs.get('range_front', float())
        self.range_right = kwargs.get('range_right', float())
        self.range_back = kwargs.get('range_back', float())

    def __repr__(self):
        typename = self.__class__.__module__.split('.')
        typename.pop()
        typename.append(self.__class__.__name__)
        args = []
        for s, t in zip(self.__slots__, self.SLOT_TYPES):
            field = getattr(self, s)
            fieldstr = repr(field)
            # We use Python array type for fields that can be directly stored
            # in them, and "normal" sequences for everything else.  If it is
            # a type that we store in an array, strip off the 'array' portion.
            if (
                isinstance(t, rosidl_parser.definition.AbstractSequence) and
                isinstance(t.value_type, rosidl_parser.definition.BasicType) and
                t.value_type.typename in ['float', 'double', 'int8', 'uint8', 'int16', 'uint16', 'int32', 'uint32', 'int64', 'uint64']
            ):
                if len(field) == 0:
                    fieldstr = '[]'
                else:
                    assert fieldstr.startswith('array(')
                    prefix = "array('X', "
                    suffix = ')'
                    fieldstr = fieldstr[len(prefix):-len(suffix)]
            args.append(s[1:] + '=' + fieldstr)
        return '%s(%s)' % ('.'.join(typename), ', '.join(args))

    def __eq__(self, other):
        if not isinstance(other, self.__class__):
            return False
        if self.range_left != other.range_left:
            return False
        if self.range_front != other.range_front:
            return False
        if self.range_right != other.range_right:
            return False
        if self.range_back != other.range_back:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def range_left(self):
        """Message field 'range_left'."""
        return self._range_left

    @range_left.setter
    def range_left(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'range_left' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'range_left' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._range_left = value

    @builtins.property
    def range_front(self):
        """Message field 'range_front'."""
        return self._range_front

    @range_front.setter
    def range_front(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'range_front' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'range_front' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._range_front = value

    @builtins.property
    def range_right(self):
        """Message field 'range_right'."""
        return self._range_right

    @range_right.setter
    def range_right(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'range_right' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'range_right' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._range_right = value

    @builtins.property
    def range_back(self):
        """Message field 'range_back'."""
        return self._range_back

    @range_back.setter
    def range_back(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'range_back' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'range_back' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._range_back = value
