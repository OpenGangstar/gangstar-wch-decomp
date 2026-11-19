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

// Modified: limited native registration-list/map record storage only.
// Layout/constructors follow the licensed STLport records; native container
// algorithms remain imported. No semantic meaning is assigned to comparator padding.
#ifndef WCH_APP_APPLICATION_STORAGE_H
#define WCH_APP_APPLICATION_STORAGE_H
#include "../core/NativeAllocator.h"
class IUpdatable;
class IDrawable;
namespace irr { class IEventReceiver; }
namespace std {
template<class A,class B,class R> struct binary_function {
 typedef A first_argument_type;typedef B second_argument_type;typedef R result_type;
};
template<class A, class B> struct pair;
template<class T>struct less:binary_function<T,T,bool>,__stlport_class<less<T> > {
 bool operator()(const T&x,const T&y)const{return x<y;}
};
}
namespace stlp_priv {
struct RegistrationLink {
 RegistrationLink* next;
 RegistrationLink* previous;
};
// Restricted authentic _alloc.h construction proxy: allocator EBO base and
// by-value POD sentinel copy. Allocation algorithms remain native imports.
template<class Value, class Node, class Alloc> class _STLP_alloc_proxy : public Alloc {
public:
 Value _M_data;
 _STLP_alloc_proxy(const Alloc& allocator, Value value)
  :Alloc(allocator),_M_data(value) {}
};
template<class T> struct _List_node;
template<class T> struct _Rb_tree_node;
template<class T, class Alloc> class _List_base;
template<> class _List_base<IUpdatable*, std::allocator<IUpdatable*> > {
public:
 typedef std::allocator<IUpdatable*> allocator_type;
 typedef _List_node<IUpdatable*> _Node;
 typedef std::allocator<_Node> _Node_allocator_type;
 typedef _STLP_alloc_proxy<RegistrationLink,_Node,_Node_allocator_type> _AllocProxy;
 // Default argument represents list() supplying allocator_type().
 _List_base(const allocator_type& allocator=allocator_type())
  :_M_node(_Node_allocator_type(allocator),RegistrationLink()) { _M_empty_initialize(); }
 ~_List_base() { clear(); }
 void clear() __attribute__((weak));
 void _M_empty_initialize() {
  _M_node._M_data.next=&_M_node._M_data;
  _M_node._M_data.previous=_M_node._M_data.next;
 }
 _AllocProxy _M_node;
};
template<> class _List_base<IDrawable*, std::allocator<IDrawable*> > {
public:
 typedef std::allocator<IDrawable*> allocator_type;
 typedef _List_node<IDrawable*> _Node;
 typedef std::allocator<_Node> _Node_allocator_type;
 typedef _STLP_alloc_proxy<RegistrationLink,_Node,_Node_allocator_type> _AllocProxy;
 // Default argument represents list() supplying allocator_type().
 _List_base(const allocator_type& allocator=allocator_type())
  :_M_node(_Node_allocator_type(allocator),RegistrationLink()) { _M_empty_initialize(); }
 ~_List_base() { clear(); }
 void clear() __attribute__((weak));
 void _M_empty_initialize() {
  _M_node._M_data.next=&_M_node._M_data;
  _M_node._M_data.previous=_M_node._M_data.next;
 }
 _AllocProxy _M_node;
};
template<> class _List_base<irr::IEventReceiver*, std::allocator<irr::IEventReceiver*> > {
public:
 typedef std::allocator<irr::IEventReceiver*> allocator_type;
 typedef _List_node<irr::IEventReceiver*> _Node;
 typedef std::allocator<_Node> _Node_allocator_type;
 typedef _STLP_alloc_proxy<RegistrationLink,_Node,_Node_allocator_type> _AllocProxy;
 // Default argument represents list() supplying allocator_type().
 _List_base(const allocator_type& allocator=allocator_type())
  :_M_node(_Node_allocator_type(allocator),RegistrationLink()) { _M_empty_initialize(); }
 ~_List_base() { clear(); }
 void clear() __attribute__((weak));
 void _M_empty_initialize() {
  _M_node._M_data.next=&_M_node._M_data;
  _M_node._M_data.previous=_M_node._M_data.next;
 }
 _AllocProxy _M_node;
};
struct _Rb_tree_node_base {
 bool _M_color;
 _Rb_tree_node_base* _M_parent;
 _Rb_tree_node_base* _M_left;
 _Rb_tree_node_base* _M_right;
};
}
struct ApplicationMonitoredPointerStorage;
extern "C" void _ZN9stlp_priv8_Rb_treeIPvSt4lessIS1_ESt4pairIKS1_PKcENS_10_Select1stIS8_EENS_11_MapTraitsTIS8_EESaIS8_EE8_M_eraseEPNS_18_Rb_tree_node_baseE(
 ApplicationMonitoredPointerStorage*, stlp_priv::_Rb_tree_node_base*) __attribute__((weak));
// Restricted _Rb_tree_base construction, before derived count/comparator.
struct ApplicationMonitoredPointerHeader {
 typedef std::pair<void* const,const char*> value_type;
 typedef std::allocator<value_type> allocator_type;
 typedef stlp_priv::_Rb_tree_node<value_type> _Node;
 typedef std::allocator<_Node> _Node_allocator_type;
 typedef stlp_priv::_STLP_alloc_proxy<stlp_priv::_Rb_tree_node_base,_Node,_Node_allocator_type> _AllocProxy;
 _AllocProxy _M_header;
 ApplicationMonitoredPointerHeader(const allocator_type& allocator)
  :_M_header(_Node_allocator_type(allocator),stlp_priv::_Rb_tree_node_base()) { _M_empty_initialize(); }
 void _M_empty_initialize() {
  _M_header._M_data._M_color=false;_M_header._M_data._M_parent=0;
  _M_header._M_data._M_left=&_M_header._M_data;_M_header._M_data._M_right=&_M_header._M_data;
 }
};
struct ApplicationMonitoredPointerStorage : ApplicationMonitoredPointerHeader {
 unsigned int count;
 std::less<void*> compare;
 ApplicationMonitoredPointerStorage(const std::less<void*>& comp=std::less<void*>())
  :ApplicationMonitoredPointerHeader(allocator_type()),count(0),compare(comp) {}
 ~ApplicationMonitoredPointerStorage() {
  if(count != 0) {
   _ZN9stlp_priv8_Rb_treeIPvSt4lessIS1_ESt4pairIKS1_PKcENS_10_Select1stIS8_EENS_11_MapTraitsTIS8_EESaIS8_EE8_M_eraseEPNS_18_Rb_tree_node_baseE(this, _M_header._M_data._M_parent);
   _M_header._M_data._M_left=&_M_header._M_data;_M_header._M_data._M_parent=0;
   _M_header._M_data._M_right=&_M_header._M_data;count=0;
  }
 }
};
#endif
