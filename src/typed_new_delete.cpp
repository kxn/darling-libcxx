//===----------------------------------------------------------------------===//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//===----------------------------------------------------------------------===//

#include <new>
#include <cstddef>

namespace std { enum class __type_descriptor_t : unsigned long long; }

// The legacy allocator has no type partitions. Preserve its replacement
// operators, new_handler, exception, zero-size and array allocation semantics.
// Do not claim the descriptor enforces allocation isolation on this backend.
__attribute__((weak, visibility("default")))
void* operator new(std::size_t size, std::__type_descriptor_t) {
    return ::operator new(size);
}

__attribute__((weak, visibility("default")))
void* operator new[](std::size_t size, std::__type_descriptor_t) {
    return ::operator new[](size);
}

__attribute__((weak, visibility("default")))
void operator delete(void* pointer, std::__type_descriptor_t) noexcept {
    ::operator delete(pointer);
}

__attribute__((weak, visibility("default")))
void operator delete[](void* pointer, std::__type_descriptor_t) noexcept {
    ::operator delete[](pointer);
}
