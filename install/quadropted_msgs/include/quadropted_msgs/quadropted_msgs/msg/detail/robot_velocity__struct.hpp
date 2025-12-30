// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from quadropted_msgs:msg/RobotVelocity.idl
// generated code does not contain a copyright notice

#ifndef QUADROPTED_MSGS__MSG__DETAIL__ROBOT_VELOCITY__STRUCT_HPP_
#define QUADROPTED_MSGS__MSG__DETAIL__ROBOT_VELOCITY__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'cmd_vel'
#include "geometry_msgs/msg/detail/twist__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__quadropted_msgs__msg__RobotVelocity __attribute__((deprecated))
#else
# define DEPRECATED__quadropted_msgs__msg__RobotVelocity __declspec(deprecated)
#endif

namespace quadropted_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct RobotVelocity_
{
  using Type = RobotVelocity_<ContainerAllocator>;

  explicit RobotVelocity_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : cmd_vel(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->robot_id = 0;
    }
  }

  explicit RobotVelocity_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : cmd_vel(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->robot_id = 0;
    }
  }

  // field types and members
  using _robot_id_type =
    uint16_t;
  _robot_id_type robot_id;
  using _cmd_vel_type =
    geometry_msgs::msg::Twist_<ContainerAllocator>;
  _cmd_vel_type cmd_vel;

  // setters for named parameter idiom
  Type & set__robot_id(
    const uint16_t & _arg)
  {
    this->robot_id = _arg;
    return *this;
  }
  Type & set__cmd_vel(
    const geometry_msgs::msg::Twist_<ContainerAllocator> & _arg)
  {
    this->cmd_vel = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    quadropted_msgs::msg::RobotVelocity_<ContainerAllocator> *;
  using ConstRawPtr =
    const quadropted_msgs::msg::RobotVelocity_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<quadropted_msgs::msg::RobotVelocity_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<quadropted_msgs::msg::RobotVelocity_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      quadropted_msgs::msg::RobotVelocity_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<quadropted_msgs::msg::RobotVelocity_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      quadropted_msgs::msg::RobotVelocity_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<quadropted_msgs::msg::RobotVelocity_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<quadropted_msgs::msg::RobotVelocity_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<quadropted_msgs::msg::RobotVelocity_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__quadropted_msgs__msg__RobotVelocity
    std::shared_ptr<quadropted_msgs::msg::RobotVelocity_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__quadropted_msgs__msg__RobotVelocity
    std::shared_ptr<quadropted_msgs::msg::RobotVelocity_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const RobotVelocity_ & other) const
  {
    if (this->robot_id != other.robot_id) {
      return false;
    }
    if (this->cmd_vel != other.cmd_vel) {
      return false;
    }
    return true;
  }
  bool operator!=(const RobotVelocity_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct RobotVelocity_

// alias to use template instance with default allocator
using RobotVelocity =
  quadropted_msgs::msg::RobotVelocity_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace quadropted_msgs

#endif  // QUADROPTED_MSGS__MSG__DETAIL__ROBOT_VELOCITY__STRUCT_HPP_
