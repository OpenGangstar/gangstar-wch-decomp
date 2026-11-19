// Copyright (C) 2002-2008 Nikolaus Gebhardt
// Altered excerpt of Irrlicht 1.4.2 irrArray.h: restricted native storage and release accessors only.
// This software is provided 'as-is', without any express or implied
// warranty. In no event will the authors be held liable for any damages
// arising from the use of this software.
// Permission is granted to anyone to use this software for any purpose,
// including commercial applications, and to alter it and redistribute it
// freely, subject to the following restrictions:
// 1. The origin of this software must not be misrepresented; you must not
// claim that you wrote the original software. If you use this software
// in a product, an acknowledgement in the product documentation would be
// appreciated but is not required.
// 2. Altered source versions must be clearly marked as such, and must not be
// misrepresented as being the original software.
// 3. This notice may not be removed or altered from any source distribution.
#ifndef WCH_CORE_ARRAY_H
#define WCH_CORE_ARRAY_H

// Observed fork storage/call view only; not a general container implementation.
// Item's TU initializes and cleans up its static instance explicitly.
namespace irr { namespace core {
template<class T> class irrAllocator;
template<class T, class Alloc = irrAllocator<T> > class array {
public:
    T* data;
    unsigned int allocated;
    unsigned int used;
    bool free_when_destroyed;
    bool is_sorted;
    unsigned int unknown16;
    // Genuine release-mode Irrlicht accessors; ownership and allocation remain native.
    T& operator[](unsigned int index) { return data[index]; }
    unsigned int size() const { return used; }
    void reallocate(unsigned int size) __attribute__((weak));
    void insert(const T& value, unsigned int index) __attribute__((weak));
    void push_back(const T& value) __attribute__((weak));
};
} }

#endif
