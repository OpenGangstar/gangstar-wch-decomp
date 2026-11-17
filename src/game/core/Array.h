#ifndef WCH_CORE_ARRAY_H
#define WCH_CORE_ARRAY_H

// Observed fork storage/call view only; not a general container implementation.
// Item's TU initializes and cleans up its static instance explicitly.
namespace irr { namespace core {
template<class T> class irrAllocator;
template<class T, class Alloc = irrAllocator<T> > class array {
public:
    T* data;
    unsigned int allocated;
    unsigned int used;
    bool free_when_destroyed;
    bool is_sorted;
    unsigned int unknown16;
    void reallocate(unsigned int size) __attribute__((weak));
    void insert(const T& value, unsigned int index) __attribute__((weak));
    void push_back(const T& value) __attribute__((weak));
};
} }

#endif
