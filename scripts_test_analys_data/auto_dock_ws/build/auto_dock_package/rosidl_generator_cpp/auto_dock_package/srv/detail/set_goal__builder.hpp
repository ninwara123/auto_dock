// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from auto_dock_package:srv/SetGoal.idl
// generated code does not contain a copyright notice

#ifndef AUTO_DOCK_PACKAGE__SRV__DETAIL__SET_GOAL__BUILDER_HPP_
#define AUTO_DOCK_PACKAGE__SRV__DETAIL__SET_GOAL__BUILDER_HPP_

#include "auto_dock_package/srv/detail/set_goal__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace auto_dock_package
{

namespace srv
{

namespace builder
{

class Init_SetGoal_Request_position
{
public:
  Init_SetGoal_Request_position()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::auto_dock_package::srv::SetGoal_Request position(::auto_dock_package::srv::SetGoal_Request::_position_type arg)
  {
    msg_.position = std::move(arg);
    return std::move(msg_);
  }

private:
  ::auto_dock_package::srv::SetGoal_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::auto_dock_package::srv::SetGoal_Request>()
{
  return auto_dock_package::srv::builder::Init_SetGoal_Request_position();
}

}  // namespace auto_dock_package


namespace auto_dock_package
{

namespace srv
{


}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::auto_dock_package::srv::SetGoal_Response>()
{
  return ::auto_dock_package::srv::SetGoal_Response(rosidl_runtime_cpp::MessageInitialization::ZERO);
}

}  // namespace auto_dock_package

#endif  // AUTO_DOCK_PACKAGE__SRV__DETAIL__SET_GOAL__BUILDER_HPP_
