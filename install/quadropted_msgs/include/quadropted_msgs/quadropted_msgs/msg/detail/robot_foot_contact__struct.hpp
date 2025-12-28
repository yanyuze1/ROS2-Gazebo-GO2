// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from quadropted_msgs:msg/RobotFootContact.idl
// generated code does not contain a copyright notice

#ifndef QUADROPTED_MSGS__MSG__DETAIL__ROBOT_FOOT_CONTACT__STRUCT_HPP_
#define QUADROPTED_MSGS__MSG__DETAIL__ROBOT_FOOT_CONTACT__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__quadropted_msgs__msg__RobotFootContact __attribute__((deprecated))
#else
# define DEPRECATED__quadropted_msgs__msg__RobotFootContact __declspec(deprecated)
#endif

namespace quadropted_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct RobotFootContact_
{
  using Type = RobotFootContact_<ContainerAllocator>;

  explicit RobotFootContact_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      std::fill<typename std::array<bool, 4>::iterator, bool>(this->contacts.begin(), this->contacts.end(), false);
    }
  }

  explicit RobotFootContact_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : contacts(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      std::fill<typename std::array<bool, 4>::iterator, bool>(this->contacts.begin(), this->contacts.end(), false);
    }
  }

  // field types and members
  using _contacts_type =
    std::array<bool, 4>;
  _contacts_type contacts;

  // setters for named parameter idiom
  Type & set__contacts(
    const std::array<bool, 4> & _arg)
  {
    this->contacts = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    quadropted_msgs::msg::RobotFootContact_<ContainerAllocator> *;
  using ConstRawPtr =
    const quadropted_msgs::msg::RobotFootContact_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<quadropted_msgs::msg::RobotFootContact_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<quadropted_msgs::msg::RobotFootContact_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      quadropted_msgs::msg::RobotFootContact_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<quadropted_msgs::msg::RobotFootContact_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      quadropted_msgs::msg::RobotFootContact_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<quadropted_msgs::msg::RobotFootContact_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<quadropted_msgs::msg::RobotFootContact_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<quadropted_msgs::msg::RobotFootContact_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__quadropted_msgs__msg__RobotFootContact
    std::shared_ptr<quadropted_msgs::msg::RobotFootContact_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__quadropted_msgs__msg__RobotFootContact
    std::shared_ptr<quadropted_msgs::msg::RobotFootContact_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const RobotFootContact_ & other) const
  {
    if (this->contacts != other.contacts) {
      return false;
    }
    return true;
  }
  bool operator!=(const RobotFootContact_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct RobotFootContact_

// alias to use template instance with default allocator
using RobotFootContact =
  quadropted_msgs::msg::RobotFootContact_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace quadropted_msgs

#endif  // QUADROPTED_MSGS__MSG__DETAIL__ROBOT_FOOT_CONTACT__STRUCT_HPP_
