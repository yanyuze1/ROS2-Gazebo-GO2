# generated from rosidl_generator_py/resource/_idl.py.em
# with input from quadropted_msgs:msg/RobotGaitCommand.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import math  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_RobotGaitCommand(type):
    """Metaclass of message 'RobotGaitCommand'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
        'GAIT_TYPE_IDLE': 0,
        'GAIT_TYPE_TROT': 1,
        'GAIT_TYPE_TROT_RUN': 2,
        'GAIT_TYPE_CLIMB_STAIR': 3,
        'GAIT_TYPE_TROT_OBST': 4,
    }

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('quadropted_msgs')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'quadropted_msgs.msg.RobotGaitCommand')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__robot_gait_command
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__robot_gait_command
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__robot_gait_command
            cls._TYPE_SUPPORT = module.type_support_msg__msg__robot_gait_command
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__robot_gait_command

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
            'GAIT_TYPE_IDLE': cls.__constants['GAIT_TYPE_IDLE'],
            'GAIT_TYPE_TROT': cls.__constants['GAIT_TYPE_TROT'],
            'GAIT_TYPE_TROT_RUN': cls.__constants['GAIT_TYPE_TROT_RUN'],
            'GAIT_TYPE_CLIMB_STAIR': cls.__constants['GAIT_TYPE_CLIMB_STAIR'],
            'GAIT_TYPE_TROT_OBST': cls.__constants['GAIT_TYPE_TROT_OBST'],
        }

    @property
    def GAIT_TYPE_IDLE(self):
        """Message constant 'GAIT_TYPE_IDLE'."""
        return Metaclass_RobotGaitCommand.__constants['GAIT_TYPE_IDLE']

    @property
    def GAIT_TYPE_TROT(self):
        """Message constant 'GAIT_TYPE_TROT'."""
        return Metaclass_RobotGaitCommand.__constants['GAIT_TYPE_TROT']

    @property
    def GAIT_TYPE_TROT_RUN(self):
        """Message constant 'GAIT_TYPE_TROT_RUN'."""
        return Metaclass_RobotGaitCommand.__constants['GAIT_TYPE_TROT_RUN']

    @property
    def GAIT_TYPE_CLIMB_STAIR(self):
        """Message constant 'GAIT_TYPE_CLIMB_STAIR'."""
        return Metaclass_RobotGaitCommand.__constants['GAIT_TYPE_CLIMB_STAIR']

    @property
    def GAIT_TYPE_TROT_OBST(self):
        """Message constant 'GAIT_TYPE_TROT_OBST'."""
        return Metaclass_RobotGaitCommand.__constants['GAIT_TYPE_TROT_OBST']


class RobotGaitCommand(metaclass=Metaclass_RobotGaitCommand):
    """
    Message class 'RobotGaitCommand'.

    Constants:
      GAIT_TYPE_IDLE
      GAIT_TYPE_TROT
      GAIT_TYPE_TROT_RUN
      GAIT_TYPE_CLIMB_STAIR
      GAIT_TYPE_TROT_OBST
    """

    __slots__ = [
        '_robot_id',
        '_gait_type',
        '_body_height',
        '_leg_height',
    ]

    _fields_and_field_types = {
        'robot_id': 'uint16',
        'gait_type': 'uint16',
        'body_height': 'float',
        'leg_height': 'float',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('uint16'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint16'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.robot_id = kwargs.get('robot_id', int())
        self.gait_type = kwargs.get('gait_type', int())
        self.body_height = kwargs.get('body_height', float())
        self.leg_height = kwargs.get('leg_height', float())

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
        if self.robot_id != other.robot_id:
            return False
        if self.gait_type != other.gait_type:
            return False
        if self.body_height != other.body_height:
            return False
        if self.leg_height != other.leg_height:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def robot_id(self):
        """Message field 'robot_id'."""
        return self._robot_id

    @robot_id.setter
    def robot_id(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'robot_id' field must be of type 'int'"
            assert value >= 0 and value < 65536, \
                "The 'robot_id' field must be an unsigned integer in [0, 65535]"
        self._robot_id = value

    @builtins.property
    def gait_type(self):
        """Message field 'gait_type'."""
        return self._gait_type

    @gait_type.setter
    def gait_type(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'gait_type' field must be of type 'int'"
            assert value >= 0 and value < 65536, \
                "The 'gait_type' field must be an unsigned integer in [0, 65535]"
        self._gait_type = value

    @builtins.property
    def body_height(self):
        """Message field 'body_height'."""
        return self._body_height

    @body_height.setter
    def body_height(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'body_height' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'body_height' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._body_height = value

    @builtins.property
    def leg_height(self):
        """Message field 'leg_height'."""
        return self._leg_height

    @leg_height.setter
    def leg_height(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'leg_height' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'leg_height' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._leg_height = value
