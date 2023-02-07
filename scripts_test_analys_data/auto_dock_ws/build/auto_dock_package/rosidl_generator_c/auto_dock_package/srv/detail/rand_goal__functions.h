// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from auto_dock_package:srv/RandGoal.idl
// generated code does not contain a copyright notice

#ifndef AUTO_DOCK_PACKAGE__SRV__DETAIL__RAND_GOAL__FUNCTIONS_H_
#define AUTO_DOCK_PACKAGE__SRV__DETAIL__RAND_GOAL__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "auto_dock_package/msg/rosidl_generator_c__visibility_control.h"

#include "auto_dock_package/srv/detail/rand_goal__struct.h"

/// Initialize srv/RandGoal message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * auto_dock_package__srv__RandGoal_Request
 * )) before or use
 * auto_dock_package__srv__RandGoal_Request__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_auto_dock_package
bool
auto_dock_package__srv__RandGoal_Request__init(auto_dock_package__srv__RandGoal_Request * msg);

/// Finalize srv/RandGoal message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_auto_dock_package
void
auto_dock_package__srv__RandGoal_Request__fini(auto_dock_package__srv__RandGoal_Request * msg);

/// Create srv/RandGoal message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * auto_dock_package__srv__RandGoal_Request__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_auto_dock_package
auto_dock_package__srv__RandGoal_Request *
auto_dock_package__srv__RandGoal_Request__create();

/// Destroy srv/RandGoal message.
/**
 * It calls
 * auto_dock_package__srv__RandGoal_Request__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_auto_dock_package
void
auto_dock_package__srv__RandGoal_Request__destroy(auto_dock_package__srv__RandGoal_Request * msg);

/// Check for srv/RandGoal message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_auto_dock_package
bool
auto_dock_package__srv__RandGoal_Request__are_equal(const auto_dock_package__srv__RandGoal_Request * lhs, const auto_dock_package__srv__RandGoal_Request * rhs);

/// Copy a srv/RandGoal message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_auto_dock_package
bool
auto_dock_package__srv__RandGoal_Request__copy(
  const auto_dock_package__srv__RandGoal_Request * input,
  auto_dock_package__srv__RandGoal_Request * output);

/// Initialize array of srv/RandGoal messages.
/**
 * It allocates the memory for the number of elements and calls
 * auto_dock_package__srv__RandGoal_Request__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_auto_dock_package
bool
auto_dock_package__srv__RandGoal_Request__Sequence__init(auto_dock_package__srv__RandGoal_Request__Sequence * array, size_t size);

/// Finalize array of srv/RandGoal messages.
/**
 * It calls
 * auto_dock_package__srv__RandGoal_Request__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_auto_dock_package
void
auto_dock_package__srv__RandGoal_Request__Sequence__fini(auto_dock_package__srv__RandGoal_Request__Sequence * array);

/// Create array of srv/RandGoal messages.
/**
 * It allocates the memory for the array and calls
 * auto_dock_package__srv__RandGoal_Request__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_auto_dock_package
auto_dock_package__srv__RandGoal_Request__Sequence *
auto_dock_package__srv__RandGoal_Request__Sequence__create(size_t size);

/// Destroy array of srv/RandGoal messages.
/**
 * It calls
 * auto_dock_package__srv__RandGoal_Request__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_auto_dock_package
void
auto_dock_package__srv__RandGoal_Request__Sequence__destroy(auto_dock_package__srv__RandGoal_Request__Sequence * array);

/// Check for srv/RandGoal message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_auto_dock_package
bool
auto_dock_package__srv__RandGoal_Request__Sequence__are_equal(const auto_dock_package__srv__RandGoal_Request__Sequence * lhs, const auto_dock_package__srv__RandGoal_Request__Sequence * rhs);

/// Copy an array of srv/RandGoal messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_auto_dock_package
bool
auto_dock_package__srv__RandGoal_Request__Sequence__copy(
  const auto_dock_package__srv__RandGoal_Request__Sequence * input,
  auto_dock_package__srv__RandGoal_Request__Sequence * output);

/// Initialize srv/RandGoal message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * auto_dock_package__srv__RandGoal_Response
 * )) before or use
 * auto_dock_package__srv__RandGoal_Response__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_auto_dock_package
bool
auto_dock_package__srv__RandGoal_Response__init(auto_dock_package__srv__RandGoal_Response * msg);

/// Finalize srv/RandGoal message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_auto_dock_package
void
auto_dock_package__srv__RandGoal_Response__fini(auto_dock_package__srv__RandGoal_Response * msg);

/// Create srv/RandGoal message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * auto_dock_package__srv__RandGoal_Response__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_auto_dock_package
auto_dock_package__srv__RandGoal_Response *
auto_dock_package__srv__RandGoal_Response__create();

/// Destroy srv/RandGoal message.
/**
 * It calls
 * auto_dock_package__srv__RandGoal_Response__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_auto_dock_package
void
auto_dock_package__srv__RandGoal_Response__destroy(auto_dock_package__srv__RandGoal_Response * msg);

/// Check for srv/RandGoal message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_auto_dock_package
bool
auto_dock_package__srv__RandGoal_Response__are_equal(const auto_dock_package__srv__RandGoal_Response * lhs, const auto_dock_package__srv__RandGoal_Response * rhs);

/// Copy a srv/RandGoal message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_auto_dock_package
bool
auto_dock_package__srv__RandGoal_Response__copy(
  const auto_dock_package__srv__RandGoal_Response * input,
  auto_dock_package__srv__RandGoal_Response * output);

/// Initialize array of srv/RandGoal messages.
/**
 * It allocates the memory for the number of elements and calls
 * auto_dock_package__srv__RandGoal_Response__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_auto_dock_package
bool
auto_dock_package__srv__RandGoal_Response__Sequence__init(auto_dock_package__srv__RandGoal_Response__Sequence * array, size_t size);

/// Finalize array of srv/RandGoal messages.
/**
 * It calls
 * auto_dock_package__srv__RandGoal_Response__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_auto_dock_package
void
auto_dock_package__srv__RandGoal_Response__Sequence__fini(auto_dock_package__srv__RandGoal_Response__Sequence * array);

/// Create array of srv/RandGoal messages.
/**
 * It allocates the memory for the array and calls
 * auto_dock_package__srv__RandGoal_Response__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_auto_dock_package
auto_dock_package__srv__RandGoal_Response__Sequence *
auto_dock_package__srv__RandGoal_Response__Sequence__create(size_t size);

/// Destroy array of srv/RandGoal messages.
/**
 * It calls
 * auto_dock_package__srv__RandGoal_Response__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_auto_dock_package
void
auto_dock_package__srv__RandGoal_Response__Sequence__destroy(auto_dock_package__srv__RandGoal_Response__Sequence * array);

/// Check for srv/RandGoal message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_auto_dock_package
bool
auto_dock_package__srv__RandGoal_Response__Sequence__are_equal(const auto_dock_package__srv__RandGoal_Response__Sequence * lhs, const auto_dock_package__srv__RandGoal_Response__Sequence * rhs);

/// Copy an array of srv/RandGoal messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_auto_dock_package
bool
auto_dock_package__srv__RandGoal_Response__Sequence__copy(
  const auto_dock_package__srv__RandGoal_Response__Sequence * input,
  auto_dock_package__srv__RandGoal_Response__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // AUTO_DOCK_PACKAGE__SRV__DETAIL__RAND_GOAL__FUNCTIONS_H_
