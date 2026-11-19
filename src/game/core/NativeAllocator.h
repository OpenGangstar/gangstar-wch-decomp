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
// Modified: shared observed STLport allocator interface; authentic empty
// construction, EBO recognition and rebind support are retained from _alloc.h.
#ifndef WCH_CORE_NATIVE_ALLOCATOR_H
#define WCH_CORE_NATIVE_ALLOCATOR_H

namespace std {
// Centralized existing STLport recognition tag; adds no data.
template<class T> struct __stlport_class { typedef T _Type; };
template<class T> class allocator : public __stlport_class<allocator<T> > {
public:
    typedef T value_type;
    typedef T* pointer;
    typedef const T* const_pointer;
    typedef T& reference;
    typedef const T& const_reference;
    typedef unsigned int size_type;
    typedef int difference_type;
    template<class U> struct rebind { typedef allocator<U> other; };
    allocator() throw() {}
    template<class U> allocator(const allocator<U>&) throw() {}
    allocator(const allocator<T>&) throw() {}
    ~allocator() throw() {}
    T* allocate(unsigned int count, const void* hint = 0);
};
}

#endif
