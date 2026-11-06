/*
 * MiniMap
 *
 * Original file: MiniMap.cpp
 * Area:          hud
 *
 * This file mirrors the layout of the retail build.  Add the decompiled
 * functions of MiniMap.cpp here, in the order they appear in the library.
 */

#include "MiniMap.h"
#include "../characters/AnimObject.h"

// Imported STLport list operation for the retail TrackableObject specialization.
extern "C" void clearTrackedObjects(void*)
    __asm__("_ZN9stlp_priv10_List_baseIN7MiniMap15TrackableObjectESaIS2_EE5clearEv")
    __attribute__((weak));

void MiniMap::deregisterAllForMapTracking()
{
    TrackingLink* const end = &trackedObjects;
    TrackingLink* link = trackedObjects.next;
    if (end != link) {
        do {
            delete static_cast<TrackingNode*>(link)->marker;
            link = link->next;
        } while (end != link);
    }
    clearTrackedObjects(&trackedObjects);
}

// Recovered translation-unit SDK startup callbacks.
#include "../core/LocalSdkStartupStorage.h"
#include "../core/LocalStartupText.h"

void operator delete(void*) throw();
extern "C" {
static void __tcf_5() __attribute__((used));
}

extern void* __dso_handle;
extern "C" {
int __aeabi_atexit(void*, void (*)(void*), void*);
void* _ZN3irr4core6stringIcNS0_12irrAllocatorIcEEEaSIcEERS4_PKT_(void*, const char*) __attribute__((weak));
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
        __aeabi_atexit(0, reinterpret_cast<void (*)(void*)>(__tcf_5), &__dso_handle);
        new (irr::ps::vHalf) irr::ps::LocalVector3(0.5f, 0.5f, 0.5f);
    }
}

extern "C" {
static void _GLOBAL__I__ZN7MiniMapC2EP7ASpriteiiii() __attribute__((used));
static void _GLOBAL__I__ZN7MiniMapC2EP7ASpriteiiii()
{
    __static_initialization_and_destruction_0(1, 65535);
}
}

extern "C" {
static void __tcf_5()
{
    irr::scene::quake3::LocalStringStorage& value = irr::scene::quake3::irrEmptyStringc;
    if (!value.reference && value.array && value.array != value.inlineBuffer)
        ::operator delete(value.array);
}
}
