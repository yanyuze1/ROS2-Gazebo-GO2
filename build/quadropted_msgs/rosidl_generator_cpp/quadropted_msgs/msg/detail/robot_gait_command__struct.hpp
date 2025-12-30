// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from quadropted_msgs:msg/RobotGaitCommand.idl
// generated code does not contain a copyright notice

#ifndef QUADROPTED_MSGS__MSG__DETAIL__ROBOT_GAIT_COMMAND__STRUCT_HPP_
#define QUADROPTED_MSGS__MSG__DETAIL__ROBOT_GAIT_COMMAND__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__quadropted_msgs__msg__RobotGaitCommand __attribute__((deprecated))
#else
# define DEPRECATED__quadropted_msgs__msg__RobotGaitCommand __declspec(deprecated)
#endif

namespace quadropted_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct RobotGaitCommand_
{
  using Type = RobotGaitCommand_<ContainerAllocator>;

  explicit RobotGaitCommand_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->robot_id = 0;
      this->gait_type = 0;
      this->body_height = 0.0f;
      this->leg_height = 0.0f;
    }
  }

  explicit RobotGaitCommand_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->robot_id = 0;
      this->gait_type = 0;
      this->body_height = 0.0f;
      this->leg_height = 0.0f;
    }
  }

  // field types and members
  using _robot_id_type =
    uint16_t;
  _robot_id_type robot_id;
  using _gait_type_type =
    uint16_t;
  _gait_type_type gait_type;
  using _body_height_type =
    float;
  _body_height_type body_height;
  using _leg_height_type =
    float;
  _leg_height_type leg_height;

  // setters for named parameter idiom
  Type & set__robot_id(
    const uint16_t & _arg)
  {
    this->robot_id = _arg;
    return *this;
  }
  Type & set__gait_type(
    const uint16_t & _arg)
  {
    this->gait_type = _arg;
    return *this;
  }
  Type & set__body_height(
    const float & _arg)
  {
    this->body_height = _arg;
    return *this;
  }
  Type & set__leg_height(
    const float & _arg)
  {
    this->leg_height = _arg;
    return *this;
  }

  // constant declarations
  static constexpr uint16_t GAIT_TYPE_IDLE =
    0u;
  static constexpr uint16_t GAIT_TYPE_TROT =
    1u;
  static constexpr uint16_t GAIT_TYPE_TROT_RUN =
    2u;
  static constexpr uint16_t GAIT_TYPE_CLIMB_STAIR =
    3u;
  static constexpr uint16_t GAIT_TYPE_TROT_OBST =
    4u;

  // pointer types
  using RawPtr =
    quadropted_msgs::msg::RobotGaitCommand_<ContainerAllocator> *;
  using ConstRawPtr =
    const quadropted_msgs::msg::RobotGaitCommand_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<quadropted_msgs::msg::RobotGaitCommand_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<quadropted_msgs::msg::RobotGaitCommand_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      quadropted_msgs::msg::RobotGaitCommand_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<quadropted_msgs::msg::RobotGaitCommand_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      quadropted_msgs::msg::RobotGaitCommand_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<quadropted_msgs::msg::RobotGaitCommand_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<quadropted_msgs::msg::RobotGaitCommand_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<quadropted_msgs::msg::RobotGaitCommand_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__quadropted_msgs__msg__RobotGaitCommand
    std::shared_ptr<quadropted_msgs::msg::RobotGaitCommand_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__quadropted_msgs__msg__RobotGaitCommand
    std::shared_ptr<quadropted_msgs::msg::RobotGaitCommand_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const RobotGaitCommand_ & other) const
  {
    if (this->robot_id != other.robot_id) {
      return false;
    }
    if (this->gait_type != other.gait_type) {
      return false;
    }
    if (this->body_height != other.body_height) {
      return false;
    }
    if (this->leg_height != other.leg_height) {
      return false;
    }
    return true;
  }
  bool operator!=(const RobotGaitCommand_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct RobotGaitCommand_

// alias to use template instance with default allocator
using RobotGaitCommand =
  quadropted_msgs::msg::RobotGaitCommand_<std::allocator<void>>;

// constant definitions
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint16_t RobotGaitCommand_<ContainerAllocator>::GAIT_TYPE_IDLE;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint16_t RobotGaitCommand_<ContainerAllocator>::GAIT_TYPE_TROT;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint16_t RobotGaitCommand_<ContainerAllocator>::GAIT_TYPE_TROT_RUN;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint16_t RobotGaitCommand_<ContainerAllocator>::GAIT_TYPE_CLIMB_STAIR;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint16_t RobotGaitCommand_<ContainerAllocator>::GAIT_TYPE_TROT_OBST;
#endif  // __cplusplus < 201703L

}  // namespace msg

}  // namespace quadropted_msgs

#endif  // QUADROPTED_MSGS__MSG__DETAIL__ROBOT_GAIT_COMMAND__STRUCT_HPP_
