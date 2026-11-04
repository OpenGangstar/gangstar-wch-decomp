/*
 * Irrlicht
 *
 * Original file: Irrlicht.cpp
 * Area:          app
 *
 * This file mirrors the layout of the retail build.  Add the decompiled
 * functions of Irrlicht.cpp here, in the order they appear in the library.
 */

#include "../core/Matrix4.h"
#include "../core/PlacementNew.h"

namespace irr {
enum MemHint { DefaultMemHint = 0 };
namespace core { extern matrix4 IdentityMatrix; }
}

void IrrFree(void*);
void* IrrAlloc(unsigned int, irr::MemHint);
void* IrrAlloc(unsigned int, irr::MemHint, int, const char*, int);

void operator delete[](void* pointer, irr::MemHint, int, const char*, int) throw() { IrrFree(pointer); }
void operator delete(void* pointer, irr::MemHint, int, const char*, int) throw() { IrrFree(pointer); }
extern "C" int irr_free(void* pointer) { IrrFree(pointer); return 0; }
void operator delete[](void* pointer, irr::MemHint) throw() { IrrFree(pointer); }
void operator delete(void* pointer, irr::MemHint) throw() { IrrFree(pointer); }
void* operator new[](unsigned int size, irr::MemHint hint, int type, const char* file, int line)
{
    return IrrAlloc(size, hint, type, file, line);
}
void* operator new(unsigned int size, irr::MemHint hint, int type, const char* file, int line)
{
    return IrrAlloc(size, hint, type, file, line);
}
extern "C" void* irr_malloc(unsigned int size) { return IrrAlloc(size, irr::DefaultMemHint); }
void* operator new[](unsigned int size, irr::MemHint hint) { return IrrAlloc(size, hint); }
void* operator new(unsigned int size, irr::MemHint hint) { return IrrAlloc(size, hint); }

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
        new (&irr::core::IdentityMatrix) irr::core::matrix4;
    }
}

extern "C" {
static void _GLOBAL__I__ZnwjN3irr7MemHintE() __attribute__((used));
static void _GLOBAL__I__ZnwjN3irr7MemHintE()
{
    __static_initialization_and_destruction_0(1, 65535);
}
}
