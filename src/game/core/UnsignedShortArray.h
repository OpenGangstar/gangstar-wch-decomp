// Copyright (C) 2002-2008 Nikolaus Gebhardt
// Altered interface excerpt of Irrlicht 1.4.2 irrArray.h: unsigned-short destruction semantics in the observed game fork layout.
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

#ifndef WCH_CORE_UNSIGNED_SHORT_ARRAY_H
#define WCH_CORE_UNSIGNED_SHORT_ARRAY_H

#include "Array.h"

void operator delete(void*) throw();

namespace irr { namespace core {
// Observed unsigned-short specialization of the fork's array deletion interface.
template<> class array<unsigned short, irrAllocator<unsigned short> > {
public:
    unsigned short* data;
    unsigned int allocated;
    unsigned int used;
    bool free_when_destroyed;
    bool is_sorted;
    unsigned int unknown16;
    ~array() { if (free_when_destroyed) ::operator delete(data); }
    void reallocate(unsigned int size) __attribute__((weak));
    void insert(const unsigned short& value, unsigned int index) __attribute__((weak));
    void push_back(const unsigned short& value) __attribute__((weak));
};

} }

#endif
