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
class IUpdatable;
class IDrawable;
namespace irr { class IEventReceiver; }
namespace std {
template<class T> class allocator;
template<class A,class B,class R> struct binary_function {
 typedef A first_argument_type;typedef B second_argument_type;typedef R result_type;
};
template<class T>struct __stlport_class {typedef T _Type;};
template<class T>struct less:binary_function<T,T,bool>,__stlport_class<less<T> > {
 bool operator()(const T&x,const T&y)const{return x<y;}
};
}
namespace stlp_priv {
struct RegistrationLink {
 RegistrationLink* next;
 RegistrationLink* previous;
 RegistrationLink():next(this),previous(this){}
};
template<class T, class Alloc> class _List_base;
template<> class _List_base<IUpdatable*, std::allocator<IUpdatable*> > {
public:
 RegistrationLink _M_node;
 ~_List_base() { clear(); }
 void clear() __attribute__((weak));
};
template<> class _List_base<IDrawable*, std::allocator<IDrawable*> > {
public:
 RegistrationLink _M_node;
 ~_List_base() { clear(); }
 void clear() __attribute__((weak));
};
template<> class _List_base<irr::IEventReceiver*, std::allocator<irr::IEventReceiver*> > {
public:
 RegistrationLink _M_node;
 ~_List_base() { clear(); }
 void clear() __attribute__((weak));
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
struct ApplicationMonitoredPointerStorage {
 stlp_priv::_Rb_tree_node_base header;
 unsigned int count;
 std::less<void*> compare;
 ApplicationMonitoredPointerStorage(const std::less<void*>& comp=std::less<void*>())
  :count(0),compare(comp) { _M_empty_initialize(); }
 ~ApplicationMonitoredPointerStorage() {
  if(count != 0) {
   _ZN9stlp_priv8_Rb_treeIPvSt4lessIS1_ESt4pairIKS1_PKcENS_10_Select1stIS8_EENS_11_MapTraitsTIS8_EESaIS8_EE8_M_eraseEPNS_18_Rb_tree_node_baseE(this, header._M_parent);
   header._M_left=&header;header._M_parent=0;
   header._M_right=&header;count=0;
  }
 }
 void _M_empty_initialize() {
  header._M_color=false;header._M_parent=0;
  header._M_left=&header;header._M_right=&header;
 }
};
#endif
