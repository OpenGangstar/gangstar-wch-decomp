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


// Modified: restricted STLport IUpdatable list iterator/remove/erase subset.
// Existing native _List_base sentinel and _List_node storage are reused.
#ifndef WCH_APP_APPLICATION_LIST_ITERATOR_H
#define WCH_APP_APPLICATION_LIST_ITERATOR_H
namespace std {
template<class T> struct _Const_traits;
template<class T> struct _Nonconst_traits {
    typedef T* pointer;
    typedef T& reference;
    typedef _Nonconst_traits<T> _NonConstTraits;
    typedef _Const_traits<T> _ConstTraits;
};
template<class T> struct _Const_traits {
    typedef const T* pointer;
    typedef const T& reference;
    typedef _Nonconst_traits<T> _NonConstTraits;
    typedef _Const_traits<T> _ConstTraits;
};
template<class T> inline void _Destroy(T* pointer) { pointer->~T(); }
}
namespace stlp_priv {
struct _List_iterator_base {
    RegistrationLink* _M_node;
    _List_iterator_base(RegistrationLink* x) : _M_node(x) {}
    void _M_incr() { _M_node = _M_node->next; }
    void _M_decr() { _M_node = _M_node->previous; }
};
template<class T, class Traits> struct _List_iterator : public _List_iterator_base {
    typedef typename Traits::reference reference;
    typedef _List_iterator<T, Traits> _Self;
    typedef _List_iterator<T, typename Traits::_NonConstTraits> iterator;
    typedef _List_iterator<T, typename Traits::_ConstTraits> const_iterator;
    typedef _List_node<T> _Node;
    explicit _List_iterator(RegistrationLink* x) : _List_iterator_base(x) {}
    _List_iterator() : _List_iterator_base(0) {}
    _List_iterator(const iterator& x) : _List_iterator_base(x._M_node) {}
    reference operator*() const { return static_cast<_Node*>(this->_M_node)->value; }
    _Self& operator++() { this->_M_incr(); return *this; }
    bool operator==(const_iterator y) const { return this->_M_node == y._M_node; }
    bool operator!=(const_iterator y) const { return this->_M_node != y._M_node; }
};
}

#endif
