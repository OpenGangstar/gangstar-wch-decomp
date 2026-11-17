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

// Modified minimal STLport support for the observed achievement queue ABI.
// Adapted from Android STLport _alloc.h, _list.h and _list.c at revision
// e64e7c849b0b659d3e198e4efaed563601e554be. Only allocation and clear remain;
// the observed node-base view replaces unrelated container machinery.
// Allocation failure follows the retail no-exception behavior.
// These SDK helper bytes are verified but excluded from game progress.
#ifndef WCH_META_ACHIEVEMENT_LIST_SUPPORT_H
#define WCH_META_ACHIEVEMENT_LIST_SUPPORT_H

#include "Achievements.h"
#include "../core/NativeAllocator.h"

void* operator new(unsigned int);
extern "C" int puts(const char*);
extern "C" void exit(int);
namespace stlp_priv {
template<class T> struct _List_node {
    AchievementManager::CompletedNodeBase base;
    T _M_data;
};
}
namespace std {
template<class T> T* allocator<T>::allocate(unsigned int count, const void*)
{
    if (count > ~0U / sizeof(T)) {
        puts("out of memory\n");
        exit(1);
    }
    if (count != 0)
        return static_cast<T*>(::operator new(count * sizeof(T)));
    return 0;
}
}
namespace stlp_priv {
template<class T, class Alloc> class _List_base {
public:
    AchievementManager::CompletedNodeBase root;
    void clear();
};
template<class T, class Alloc> void _List_base<T, Alloc>::clear()
{
    AchievementManager::CompletedNodeBase* node = root.next;
    while (node != &root) {
        AchievementManager::CompletedNodeBase* previous = node;
        node = node->next;
        ::operator delete(previous);
    }
    root.next = &root;
    root.prev = &root;
}
}

#endif
