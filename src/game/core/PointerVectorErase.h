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


// Modified: restricted authentic STLport pointer-copy and destruction traits.
// Source commit e64e7c849b0b659d3e198e4efaed563601e554be; not a retail-version claim.
#ifndef WCH_CORE_POINTER_VECTOR_ERASE_H
#define WCH_CORE_POINTER_VECTOR_ERASE_H
extern "C" void* memmove(void*, const void*, unsigned int);
namespace std {
struct __false_type {};
template<class T> struct __type_traits {
    typedef __false_type has_trivial_assignment_operator;
    typedef __false_type has_trivial_destructor;
};
template<class T> struct __type_traits<T*> {
    typedef __true_type has_trivial_assignment_operator;
    typedef __true_type has_trivial_destructor;
};
template<class Iterator, class T>
inline void __destroy_range_aux(Iterator first, Iterator last, T*, const __false_type&) {
    for (; first != last; ++first) (&*first)->~T();
}
template<class Iterator, class T>
inline void __destroy_range_aux(Iterator, Iterator, T*, const __true_type&) {}
template<class Iterator, class T>
inline void __destroy_range(Iterator first, Iterator last, T* value) {
    typedef typename __type_traits<T>::has_trivial_destructor Trivial;
    __destroy_range_aux(first, last, value, Trivial());
}
template<class T>
inline void _Destroy_Range(T* first, T* last) {
    __destroy_range(first, last, static_cast<T*>(0));
}
}
namespace stlp_priv {
inline void* __copy_trivial(const void* first, const void* last, void* result) {
    unsigned int n = static_cast<const char*>(last) - static_cast<const char*>(first);
    return n ? static_cast<void*>(static_cast<char*>(memmove(result, first, n)) + n) : result;
}
template<class Input, class Output>
inline Output __copy_ptrs(Input first, Input last, Output result, const std::__true_type&) {
    return static_cast<Output>(__copy_trivial(first, last, result));
}
template<class Input, class Output>
inline Output __copy_ptrs(Input first, Input last, Output result, const std::__false_type&);
}
#endif
