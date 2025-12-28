// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from quadropted_msgs:msg/RobotModeCommand.idl
// generated code does not contain a copyright notice

#ifndef QUADROPTED_MSGS__MSG__DETAIL__ROBOT_MODE_COMMAND__STRUCT_HPP_
#define QUADROPTED_MSGS__MSG__DETAIL__ROBOT_MODE_COMMAND__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__quadropted_msgs__msg__RobotModeCommand __attribute__((deprecated))
#else
# define DEPRECATED__quadropted_msgs__msg__RobotModeCommand __declspec(deprecated)
#endif

namespace quadropted_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct RobotModeCommand_
{
  using Type = RobotModeCommand_<ContainerAllocator>;

  explicit RobotModeCommand_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->mode = "";
      this->robot_id = 0;
    }
  }

  explicit RobotModeCommand_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : mode(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->mode = "";
      this->robot_id = 0;
    }
  }

  // field types and members
  using _mode_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _mode_type mode;
  using _robot_id_type =
    uint16_t;
  _robot_id_type robot_id;

  // setters for named parameter idiom
  Type & set__mode(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->mode = _arg;
    return *this;
  }
  Type & set__robot_id(
    const uint16_t & _arg)
  {
    this->robot_id = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    quadropted_msgs::msg::RobotModeCommand_<ContainerAllocator> *;
  using ConstRawPtr =
    const quadropted_msgs::msg::RobotModeCommand_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<quadropted_msgs::msg::RobotModeCommand_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<quadropted_msgs::msg::RobotModeCommand_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      quadropted_msgs::msg::RobotModeCommand_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<quadropted_msgs::msg::RobotModeCommand_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      quadropted_msgs::msg::RobotModeCommand_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<quadropted_msgs::msg::RobotModeCommand_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<quadropted_msgs::msg::RobotModeCommand_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<quadropted_msgs::msg::RobotModeCommand_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__quadropted_msgs__msg__RobotModeCommand
    std::shared_ptr<quadropted_msgs::msg::RobotModeCommand_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__quadropted_msgs__msg__RobotModeCommand
    std::shared_ptr<quadropted_msgs::msg::RobotModeCommand_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const RobotModeCommand_ & other) const
  {
    if (this->mode != other.mode) {
      return false;
    }
    if (this->robot_id != other.robot_id) {
      return false;
    }
    return true;
  }
  bool operator!=(const RobotModeCommand_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct RobotModeCommand_

// alias to use template instance with default allocator
using RobotModeCommand =
  quadropted_msgs::msg::RobotModeCommand_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace quadropted_msgs

#endif  // QUADROPTED_MSGS__MSG__DETAIL__ROBOT_MODE_COMMAND__STRUCT_HPP_
