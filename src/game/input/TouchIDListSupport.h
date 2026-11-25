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

// Modified: restricted native TouchIDList ABI view adapted from STLport
// _list.h/_alloc.h. This is not a recovered source wrapper/inheritance claim.
// Only the observed default stateless-allocator path is supplied. Vendor
// allocator, sort and clear implementations remain real native imports.
#ifndef WCH_INPUT_TOUCH_ID_LIST_SUPPORT_H
#define WCH_INPUT_TOUCH_ID_LIST_SUPPORT_H
#include "../core/NativeAllocator.h"
#include "../core/PlacementNew.h"
#include "../app/ApplicationStorage.h"

namespace stlp_priv {
struct _List_node_base {
    _List_node_base* _M_next;
    _List_node_base* _M_prev;
};
template<class T> struct _List_node;
template<> struct _List_node<long> : _List_node_base {
    long _M_data;
};
}
namespace std {
template<> stlp_priv::_List_node<long>* allocator<stlp_priv::_List_node<long> >::allocate(unsigned int, const void*) __attribute__((weak));
}
struct TouchIDList;
extern "C" {
void _ZN9stlp_priv10_List_baseIlSaIlEE5clearEv(TouchIDList*) __attribute__((weak));
void _ZN9stlp_priv7_S_sortIlSaIlESt4lessIlEEEvRSt4listIT_T0_ET1_(TouchIDList&, std::less<long>) __attribute__((weak));
}
namespace touch_id_list_detail {
typedef stlp_priv::_List_node_base NodeBase;
typedef stlp_priv::_List_node<long> Node;
typedef std::allocator<Node> Allocator;
// Adapted _STLP_alloc_proxy: EBO allocator base plus the sentinel value.
struct AllocProxy : Allocator {
    NodeBase _M_data;
    AllocProxy(const Allocator& allocator, NodeBase value)
        : Allocator(allocator), _M_data(value) {}
    Node* allocate(unsigned int count) {
        return static_cast<Allocator&>(*this).allocate(count, 0);
    }
};
struct Iterator {
    NodeBase* _M_node;
    explicit Iterator(NodeBase* node) : _M_node(node) {}
    Iterator() : _M_node(0) {}
    Iterator(const Iterator& other) : _M_node(other._M_node) {}
    long& operator*() const { return static_cast<Node*>(_M_node)->_M_data; }
    Iterator& operator++() { _M_node = _M_node->_M_next; return *this; }
};
struct ConstIterator {
    NodeBase* _M_node;
    explicit ConstIterator(NodeBase* node) : _M_node(node) {}
    ConstIterator(const Iterator& other) : _M_node(other._M_node) {}
    const long& operator*() const { return static_cast<Node*>(_M_node)->_M_data; }
    ConstIterator& operator++() { _M_node = _M_node->_M_next; return *this; }
    bool operator==(ConstIterator other) const { return _M_node == other._M_node; }
    bool operator!=(ConstIterator other) const { return _M_node != other._M_node; }
};
// Adapted STLport input-iterator distance dispatch, preserving its copy boundary.
inline int distance_input(const ConstIterator& first, const ConstIterator& last) {
    int count = 0;
    ConstIterator current(first);
    while (current != last) { ++current; ++count; }
    return count;
}
inline int distance(ConstIterator first, ConstIterator last) {
    return distance_input(first, last);
}
}
struct TouchIDList {
    typedef touch_id_list_detail::NodeBase NodeBase;
    typedef touch_id_list_detail::Node Node;
    typedef touch_id_list_detail::Allocator Allocator;
    typedef touch_id_list_detail::Iterator iterator;
    typedef touch_id_list_detail::ConstIterator const_iterator;

    TouchIDList() : _M_node(Allocator(), NodeBase()) { _M_empty_initialize(); }
    TouchIDList(const TouchIDList& other) : _M_node(Allocator(), NodeBase()) {
        _M_empty_initialize();
        for (const_iterator current = other.begin(); current != other.end(); ++current)
            insert(end(), *current);
    }
    ~TouchIDList() { _ZN9stlp_priv10_List_baseIlSaIlEE5clearEv(this); }
    iterator begin() { return iterator(_M_node._M_data._M_next); }
    const_iterator begin() const { return const_iterator(_M_node._M_data._M_next); }
    iterator end() { return iterator(&_M_node._M_data); }
    const_iterator end() const {
        return const_iterator(const_cast<NodeBase*>(&_M_node._M_data));
    }
    iterator insert(iterator position, const long& value) {
        NodeBase* node = _M_create_node(value);
        NodeBase* next = position._M_node;
        NodeBase* previous = next->_M_prev;
        node->_M_next = next;
        node->_M_prev = previous;
        previous->_M_next = node;
        next->_M_prev = node;
        return iterator(node);
    }
    unsigned int size() const {
        unsigned int result = touch_id_list_detail::distance(begin(), end());
        return result;
    }
    void push_back(const long& value) { insert(end(), value); }
    void sort() {
        _ZN9stlp_priv7_S_sortIlSaIlESt4lessIlEEEvRSt4listIT_T0_ET1_(*this, std::less<long>());
    }
    touch_id_list_detail::AllocProxy _M_node;
private:
    void _M_empty_initialize() {
        _M_node._M_data._M_next = &_M_node._M_data;
        _M_node._M_data._M_prev = _M_node._M_data._M_next;
    }
    NodeBase* _M_create_node(const long& value) {
        Node* node = _M_node.allocate(1);
        new (&node->_M_data) long(value);
        return node;
    }
    TouchIDList& operator=(const TouchIDList&);
};
typedef char TouchListNodeBaseExtent[sizeof(stlp_priv::_List_node_base) == 8 ? 1 : -1];
typedef char TouchListNodeExtent[sizeof(stlp_priv::_List_node<long>) == 12 ? 1 : -1];
typedef char TouchListProxyExtent[sizeof(touch_id_list_detail::AllocProxy) == 8 ? 1 : -1];
typedef char TouchListExtent[sizeof(TouchIDList) == 8 ? 1 : -1];
typedef char TouchListLessExtent[sizeof(std::less<long>) == 1 ? 1 : -1];
typedef char TouchListSentinelOffset[__builtin_offsetof(touch_id_list_detail::AllocProxy, _M_data) == 0 ? 1 : -1];
typedef char TouchListValueOffset[__builtin_offsetof(stlp_priv::_List_node<long>, _M_data) == 8 ? 1 : -1];
#endif
