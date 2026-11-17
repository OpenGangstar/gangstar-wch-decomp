/*
 * Memory
 *
 * Original file: Memory.cpp
 * Area:          core
 *
 * This file mirrors the layout of the retail build.  Add the decompiled
 * functions of Memory.cpp here, in the order they appear in the library.
 */

// Recovered translation-unit SDK string startup callbacks.
#include "../core/LocalStringStartupStorage.h"
#include "../core/LocalStartupText.h"

void operator delete(void*) throw();
extern "C" {
static void __tcf_0() __attribute__((used));
}

extern void* __dso_handle;
extern "C" {
int __aeabi_atexit(void*, void (*)(void*), void*);
void* _ZN3irr4core6stringIcNS0_12irrAllocatorIcEEEaSIcEERS4_PKT_(void*, const char*) __attribute__((weak));
}

extern "C" {
static void __tcf_0()
{
    irr::scene::quake3::LocalStringStorage& value = irr::scene::quake3::irrEmptyStringc;
    if (!value.reference && value.array && value.array != value.inlineBuffer)
        ::operator delete(value.array);
}
}

static void __static_initialization_and_destruction_0(int initialize, int priority) __attribute__((used));
static void __static_initialization_and_destruction_0(int initialize, int priority)
{
    if (initialize == 1 && priority == 65535) {
        irr::scene::quake3::LocalStringStorage& value = irr::scene::quake3::irrEmptyStringc;
        value.array = 0;
        value.allocated = 0;
        value.used = 0;
        value.reference = false;
        _ZN3irr4core6stringIcNS0_12irrAllocatorIcEEEaSIcEERS4_PKT_(&value, localStartupEmptyText);
        __aeabi_atexit(0, reinterpret_cast<void (*)(void*)>(__tcf_0), &__dso_handle);
    }
}

extern "C" {
static void _GLOBAL__I__Z11CustomAllocj() __attribute__((used));
static void _GLOBAL__I__Z11CustomAllocj()
{
    __static_initialization_and_destruction_0(1, 65535);
}
}

extern "C" void nativeFree(void*);

void CustomFree(void* memory) __attribute__((noinline));

void CustomFree(void* memory)
{
    if (memory)
        nativeFree(memory);
}

void CustomFree(void* buffer);

void SwfFree(void* buffer)
{
    CustomFree(buffer);
}

void CustomFree(void* buffer);

void IrrFree(void* buffer)
{
    CustomFree(buffer);
}

void* CustomAlloc(unsigned int size) __attribute__((noinline));

extern "C" void* nativeMalloc(unsigned int size);

void* CustomAlloc(unsigned int size)
{
    if (size)
        return nativeMalloc(size);
    return 0;
}

namespace swf { enum MemHint { DefaultMemHint = 0 }; }
void* CustomAlloc(unsigned int size);
void* SwfAlloc(unsigned int size, swf::MemHint, const char*, int)
{
    return CustomAlloc(size);
}

void* CustomAlloc(unsigned int size);

void* SwfAlloc(unsigned int size, swf::MemHint)
{
    return CustomAlloc(size);
}

#include "MemHint.h"
void* CustomAlloc(unsigned int size);
void* IrrAlloc(unsigned int size, irr::MemHint)
{
    return CustomAlloc(size);
}

#include "MemHint.h"

void* CustomAlloc(unsigned int size);

void* IrrAlloc(unsigned int size, irr::MemHint, int, const char*, int)
{
    return CustomAlloc(size);
}
