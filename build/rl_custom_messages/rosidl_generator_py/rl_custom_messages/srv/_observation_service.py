# generated from rosidl_generator_py/resource/_idl.py.em
# with input from rl_custom_messages:srv/ObservationService.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

# Member 'motor_action'
# Member 'sound_action'
import numpy  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_ObservationService_Request(type):
    """Metaclass of message 'ObservationService_Request'."""

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
                'rl_custom_messages.srv.ObservationService_Request')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__observation_service__request
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__observation_service__request
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__observation_service__request
            cls._TYPE_SUPPORT = module.type_support_msg__srv__observation_service__request
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__observation_service__request

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class ObservationService_Request(metaclass=Metaclass_ObservationService_Request):
    """Message class 'ObservationService_Request'."""

    __slots__ = [
        '_motor_action',
        '_sound_action',
    ]

    _fields_and_field_types = {
        'motor_action': 'int32[12]',
        'sound_action': 'int32[1]',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.Array(rosidl_parser.definition.BasicType('int32'), 12),  # noqa: E501
        rosidl_parser.definition.Array(rosidl_parser.definition.BasicType('int32'), 1),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        if 'motor_action' not in kwargs:
            self.motor_action = numpy.zeros(12, dtype=numpy.int32)
        else:
            self.motor_action = numpy.array(kwargs.get('motor_action'), dtype=numpy.int32)
            assert self.motor_action.shape == (12, )
        if 'sound_action' not in kwargs:
            self.sound_action = numpy.zeros(1, dtype=numpy.int32)
        else:
            self.sound_action = numpy.array(kwargs.get('sound_action'), dtype=numpy.int32)
            assert self.sound_action.shape == (1, )

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
        if all(self.motor_action != other.motor_action):
            return False
        if all(self.sound_action != other.sound_action):
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def motor_action(self):
        """Message field 'motor_action'."""
        return self._motor_action

    @motor_action.setter
    def motor_action(self, value):
        if isinstance(value, numpy.ndarray):
            assert value.dtype == numpy.int32, \
                "The 'motor_action' numpy.ndarray() must have the dtype of 'numpy.int32'"
            assert value.size == 12, \
                "The 'motor_action' numpy.ndarray() must have a size of 12"
            self._motor_action = value
            return
        if __debug__:
            from collections.abc import Sequence
            from collections.abc import Set
            from collections import UserList
            from collections import UserString
            assert \
                ((isinstance(value, Sequence) or
                  isinstance(value, Set) or
                  isinstance(value, UserList)) and
                 not isinstance(value, str) and
                 not isinstance(value, UserString) and
                 len(value) == 12 and
                 all(isinstance(v, int) for v in value) and
                 all(val >= -2147483648 and val < 2147483648 for val in value)), \
                "The 'motor_action' field must be a set or sequence with length 12 and each value of type 'int' and each integer in [-2147483648, 2147483647]"
        self._motor_action = numpy.array(value, dtype=numpy.int32)

    @builtins.property
    def sound_action(self):
        """Message field 'sound_action'."""
        return self._sound_action

    @sound_action.setter
    def sound_action(self, value):
        if isinstance(value, numpy.ndarray):
            assert value.dtype == numpy.int32, \
                "The 'sound_action' numpy.ndarray() must have the dtype of 'numpy.int32'"
            assert value.size == 1, \
                "The 'sound_action' numpy.ndarray() must have a size of 1"
            self._sound_action = value
            return
        if __debug__:
            from collections.abc import Sequence
            from collections.abc import Set
            from collections import UserList
            from collections import UserString
            assert \
                ((isinstance(value, Sequence) or
                  isinstance(value, Set) or
                  isinstance(value, UserList)) and
                 not isinstance(value, str) and
                 not isinstance(value, UserString) and
                 len(value) == 1 and
                 all(isinstance(v, int) for v in value) and
                 all(val >= -2147483648 and val < 2147483648 for val in value)), \
                "The 'sound_action' field must be a set or sequence with length 1 and each value of type 'int' and each integer in [-2147483648, 2147483647]"
        self._sound_action = numpy.array(value, dtype=numpy.int32)


# Import statements for member types

# already imported above
# import builtins

# already imported above
# import rosidl_parser.definition


class Metaclass_ObservationService_Response(type):
    """Metaclass of message 'ObservationService_Response'."""

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
                'rl_custom_messages.srv.ObservationService_Response')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__observation_service__response
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__observation_service__response
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__observation_service__response
            cls._TYPE_SUPPORT = module.type_support_msg__srv__observation_service__response
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__observation_service__response

            from rl_custom_messages.msg import RangeArray
            if RangeArray.__class__._TYPE_SUPPORT is None:
                RangeArray.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class ObservationService_Response(metaclass=Metaclass_ObservationService_Response):
    """Message class 'ObservationService_Response'."""

    __slots__ = [
        '_range_data',
    ]

    _fields_and_field_types = {
        'range_data': 'rl_custom_messages/RangeArray',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.NamespacedType(['rl_custom_messages', 'msg'], 'RangeArray'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        from rl_custom_messages.msg import RangeArray
        self.range_data = kwargs.get('range_data', RangeArray())

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
        if self.range_data != other.range_data:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def range_data(self):
        """Message field 'range_data'."""
        return self._range_data

    @range_data.setter
    def range_data(self, value):
        if __debug__:
            from rl_custom_messages.msg import RangeArray
            assert \
                isinstance(value, RangeArray), \
                "The 'range_data' field must be a sub message of type 'RangeArray'"
        self._range_data = value


class Metaclass_ObservationService(type):
    """Metaclass of service 'ObservationService'."""

    _TYPE_SUPPORT = None

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('rl_custom_messages')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'rl_custom_messages.srv.ObservationService')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._TYPE_SUPPORT = module.type_support_srv__srv__observation_service

            from rl_custom_messages.srv import _observation_service
            if _observation_service.Metaclass_ObservationService_Request._TYPE_SUPPORT is None:
                _observation_service.Metaclass_ObservationService_Request.__import_type_support__()
            if _observation_service.Metaclass_ObservationService_Response._TYPE_SUPPORT is None:
                _observation_service.Metaclass_ObservationService_Response.__import_type_support__()


class ObservationService(metaclass=Metaclass_ObservationService):
    from rl_custom_messages.srv._observation_service import ObservationService_Request as Request
    from rl_custom_messages.srv._observation_service import ObservationService_Response as Response

    def __init__(self):
        raise NotImplementedError('Service classes can not be instantiated')
