// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from auto_dock_package:srv/RandGoal.idl
// generated code does not contain a copyright notice

#ifndef AUTO_DOCK_PACKAGE__SRV__DETAIL__RAND_GOAL__BUILDER_HPP_
#define AUTO_DOCK_PACKAGE__SRV__DETAIL__RAND_GOAL__BUILDER_HPP_

#include "auto_dock_package/srv/detail/rand_goal__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace auto_dock_package
{

namespace srv
{


}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::auto_dock_package::srv::RandGoal_Request>()
{
  return ::auto_dock_package::srv::RandGoal_Request(rosidl_runtime_cpp::MessageInitialization::ZERO);
}

}  // namespace auto_dock_package


namespace auto_dock_package
{

namespace srv
{

namespace builder
{

class Init_RandGoal_Response_position
{
public:
  Init_RandGoal_Response_position()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::auto_dock_package::srv::RandGoal_Response position(::auto_dock_package::srv::RandGoal_Response::_position_type arg)
  {
    msg_.position = std::move(arg);
    return std::move(msg_);
  }

private:
  ::auto_dock_package::srv::RandGoal_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::auto_dock_package::srv::RandGoal_Response>()
{
  return auto_dock_package::srv::builder::Init_RandGoal_Response_position();
}

}  // namespace auto_dock_package

#endif  // AUTO_DOCK_PACKAGE__SRV__DETAIL__RAND_GOAL__BUILDER_HPP_
