// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from my_first_package:srv/SetGoal.idl
// generated code does not contain a copyright notice

#ifndef MY_FIRST_PACKAGE__SRV__DETAIL__SET_GOAL__BUILDER_HPP_
#define MY_FIRST_PACKAGE__SRV__DETAIL__SET_GOAL__BUILDER_HPP_

#include "my_first_package/srv/detail/set_goal__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace my_first_package
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
  ::my_first_package::srv::SetGoal_Request position(::my_first_package::srv::SetGoal_Request::_position_type arg)
  {
    msg_.position = std::move(arg);
    return std::move(msg_);
  }

private:
  ::my_first_package::srv::SetGoal_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::my_first_package::srv::SetGoal_Request>()
{
  return my_first_package::srv::builder::Init_SetGoal_Request_position();
}

}  // namespace my_first_package


namespace my_first_package
{

namespace srv
{


}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::my_first_package::srv::SetGoal_Response>()
{
  return ::my_first_package::srv::SetGoal_Response(rosidl_runtime_cpp::MessageInitialization::ZERO);
}

}  // namespace my_first_package

#endif  // MY_FIRST_PACKAGE__SRV__DETAIL__SET_GOAL__BUILDER_HPP_
