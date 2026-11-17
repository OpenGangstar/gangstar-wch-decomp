/*
 *
 * Copyright (c) 1994
 * Hewlett-Packard Company
 *
 * Copyright (c) 1996,1997
 * Silicon Graphics Computer Systems, Inc.
 *
 * Copyright (c) 1997
 * Moscow Center for SPARC Technology
 *
 * Copyright (c) 1999
 * Boris Fomitchev
 *
 * This material is provided "as is", with absolutely no warranty expressed
 * or implied. Any use is at your own risk.
 *
 * Permission to use or copy this software for any purpose is hereby granted
 * without fee, provided the above notices are retained on all copies.
 * Permission to modify the code and to distribute modified code is granted,
 * provided the above notices are retained, and a notice that the code was
 * modified is included with the above copyright notice.
 *
 */
// Modified: shared declaration of the observed STLport allocator interface.
#ifndef WCH_CORE_NATIVE_ALLOCATOR_H
#define WCH_CORE_NATIVE_ALLOCATOR_H

namespace std {
template<class T> class allocator {
public:
    T* allocate(unsigned int count, const void* hint = 0);
};
}

#endif
