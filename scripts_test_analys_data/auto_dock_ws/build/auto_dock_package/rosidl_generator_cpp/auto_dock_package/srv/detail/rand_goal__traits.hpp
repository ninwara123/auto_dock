// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from auto_dock_package:srv/RandGoal.idl
// generated code does not contain a copyright notice

#ifndef AUTO_DOCK_PACKAGE__SRV__DETAIL__RAND_GOAL__TRAITS_HPP_
#define AUTO_DOCK_PACKAGE__SRV__DETAIL__RAND_GOAL__TRAITS_HPP_

#include "auto_dock_package/srv/detail/rand_goal__struct.hpp"
#include <rosidl_runtime_cpp/traits.hpp>
#include <stdint.h>
#include <type_traits>

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<auto_dock_package::srv::RandGoal_Request>()
{
  return "auto_dock_package::srv::RandGoal_Request";
}

template<>
inline const char * name<auto_dock_package::srv::RandGoal_Request>()
{
  return "auto_dock_package/srv/RandGoal_Request";
}

template<>
struct has_fixed_size<auto_dock_package::srv::RandGoal_Request>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<auto_dock_package::srv::RandGoal_Request>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<auto_dock_package::srv::RandGoal_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'position'
#include "geometry_msgs/msg/detail/point__traits.hpp"

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<auto_dock_package::srv::RandGoal_Response>()
{
  return "auto_dock_package::srv::RandGoal_Response";
}

template<>
inline const char * name<auto_dock_package::srv::RandGoal_Response>()
{
  return "auto_dock_package/srv/RandGoal_Response";
}

template<>
struct has_fixed_size<auto_dock_package::srv::RandGoal_Response>
  : std::integral_constant<bool, has_fixed_size<geometry_msgs::msg::Point>::value> {};

template<>
struct has_bounded_size<auto_dock_package::srv::RandGoal_Response>
  : std::integral_constant<bool, has_bounded_size<geometry_msgs::msg::Point>::value> {};

template<>
struct is_message<auto_dock_package::srv::RandGoal_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<auto_dock_package::srv::RandGoal>()
{
  return "auto_dock_package::srv::RandGoal";
}

template<>
inline const char * name<auto_dock_package::srv::RandGoal>()
{
  return "auto_dock_package/srv/RandGoal";
}

template<>
struct has_fixed_size<auto_dock_package::srv::RandGoal>
  : std::integral_constant<
    bool,
    has_fixed_size<auto_dock_package::srv::RandGoal_Request>::value &&
    has_fixed_size<auto_dock_package::srv::RandGoal_Response>::value
  >
{
};

template<>
struct has_bounded_size<auto_dock_package::srv::RandGoal>
  : std::integral_constant<
    bool,
    has_bounded_size<auto_dock_package::srv::RandGoal_Request>::value &&
    has_bounded_size<auto_dock_package::srv::RandGoal_Response>::value
  >
{
};

template<>
struct is_service<auto_dock_package::srv::RandGoal>
  : std::true_type
{
};

template<>
struct is_service_request<auto_dock_package::srv::RandGoal_Request>
  : std::true_type
{
};

template<>
struct is_service_response<auto_dock_package::srv::RandGoal_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // AUTO_DOCK_PACKAGE__SRV__DETAIL__RAND_GOAL__TRAITS_HPP_
