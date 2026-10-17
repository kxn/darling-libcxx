//===----------------------------------------------------------------------===//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//===----------------------------------------------------------------------===//

#ifndef DARLING_LIBCPP_EXPECTED_EXCEPTION_H
#define DARLING_LIBCPP_EXPECTED_EXCEPTION_H
#include <exception>

// Only the runtime base class is needed here. Clients use their SDK's complete
// expected<T,E> header. Keep the upstream class layout and key function, while
// supporting the older libc++ build headers and their visibility macros.
#ifndef _LIBCPP_HIDE_FROM_ABI_VIRTUAL
#define _LIBCPP_HIDE_FROM_ABI_VIRTUAL _LIBCPP_HIDDEN
#endif
_LIBCPP_BEGIN_NAMESPACE_STD
template <class _Err> class bad_expected_access;
template <>
class _LIBCPP_EXPORTED_FROM_ABI bad_expected_access<void> : public exception {
protected:
  _LIBCPP_HIDE_FROM_ABI bad_expected_access() noexcept                                      = default;
  _LIBCPP_HIDE_FROM_ABI bad_expected_access(const bad_expected_access&) noexcept            = default;
  _LIBCPP_HIDE_FROM_ABI bad_expected_access(bad_expected_access&&) noexcept                 = default;
  _LIBCPP_HIDE_FROM_ABI bad_expected_access& operator=(const bad_expected_access&) noexcept = default;
  _LIBCPP_HIDE_FROM_ABI bad_expected_access& operator=(bad_expected_access&&) noexcept      = default;
  _LIBCPP_HIDE_FROM_ABI_VIRTUAL ~bad_expected_access() override                             = default;
public:
  const char* what() const noexcept override;
};
_LIBCPP_END_NAMESPACE_STD
#endif
