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
// Modified: restricted observed pointer-vector interface; allocation, overflow
// and base destruction remain external retail implementations.

#ifndef WCH_CORE_POINTER_VECTOR_H
#define WCH_CORE_POINTER_VECTOR_H
#include "PlacementNew.h"
#include "NativeAllocator.h"

// Observed STLport pointer-vector interface only. Allocation, base destruction
// and overflow remain retail calls; this is not a general STL replacement.
namespace std { struct __true_type {}; }
namespace stlp_priv {
template<class T, class Alloc> class _Vector_base {
public:
    _Vector_base() : first(0), last(0), limit(0) {}
    ~_Vector_base() __attribute__((weak));
protected:
    T* first;
    T* last;
    T* limit;
};
}
namespace std {
template<class T> inline void _Copy_Construct(T* target, const T& value) {
    new (static_cast<void*>(target)) T(value);
}
template<class T, class Alloc = allocator<T> >
class vector : public stlp_priv::_Vector_base<T, Alloc> {
public:
    typedef unsigned int size_type;
    typedef T* iterator;
    vector() {}
    iterator begin() { return this->first; }
    iterator end() { return this->last; }
    void clear() { if (this->first != this->last) this->last = this->first; }
    size_type size() const { return size_type(this->last - this->first); }
    T& operator[](size_type index) { return *(begin() + index); }
    void resize(size_type size, const T& value) __attribute__((weak));
    void push_back(const T& value) {
        if (this->last != this->limit) {
            _Copy_Construct(this->last, value);
            ++this->last;
        } else {
            _M_insert_overflow(this->last, value, __true_type(), 1, true);
        }
    }
    void _M_insert_overflow(T*, const T&, const __true_type&, unsigned int, bool)
        __attribute__((weak));
};
}

#endif
