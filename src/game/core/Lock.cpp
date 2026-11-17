/*
 * Lock
 *
 * Original file: Lock.cpp
 * Area:          core
 *
 * This file mirrors the layout of the retail build.  Add the decompiled
 * functions of Lock.cpp here, in the order they appear in the library.
 */

// Recovered translation-unit SDK startup callbacks.
#include "../core/LocalSdkStartupStorage.h"
#include "../core/LocalStartupText.h"
#include "Lock.h"
#include "Vector3.h"
#include "../rendering/CustomBillboardSceneNode.h"
#include "../world/LevelObject.h"

void operator delete(void*) throw();
extern "C" {
static void __tcf_2() __attribute__((used));
}

extern void* __dso_handle;
extern "C" {
int __aeabi_atexit(void*, void (*)(void*), void*);
void* _ZN3irr4core6stringIcNS0_12irrAllocatorIcEEEaSIcEERS4_PKT_(void*, const char*) __attribute__((weak));
}

extern "C" {
static void __tcf_2()
{
    irr::scene::quake3::LocalStringStorage& value = irr::scene::quake3::irrEmptyStringc;
    if (!value.reference && value.array && value.array != value.inlineBuffer)
        ::operator delete(value.array);
}
}

Lock* Lock::s_lock;

void Lock::clean()
{
    if (s_lock) {
        delete s_lock;
        s_lock = 0;
    }
}

static const char lockResource[] __attribute__((section(".rodata.lock_resource"))) = "./sfx_lock.bdae";

Lock* Lock::getInstance()
{
    if (!s_lock)
        s_lock = new Lock(lockResource, 0, true);
    return s_lock;
}

void Lock::setTarget(LevelObject* object)
{
    target = object;
    if (object) {
        if (LevelObject::s_type[object->getObjectType()] == 3) {
            billboard->setScale(irr::core::vector3d<float>(2.0f, 2.0f, 2.0f));
            billboard->setParentOffsetZ(100);
        } else {
            billboard->setScale(irr::core::vector3d<float>(1.0f, 1.0f, 1.0f));
            billboard->setParentOffsetZ(0);
        }
        billboard->setParent(target->sceneNode);
    } else {
        billboard->setParent(0);
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
        __aeabi_atexit(0, reinterpret_cast<void (*)(void*)>(__tcf_2), &__dso_handle);
        new (irr::ps::vHalf) irr::ps::LocalVector3(0.5f, 0.5f, 0.5f);
    }
}

extern "C" {
static void _GLOBAL__I__ZN4Lock6s_lockE() __attribute__((used));
static void _GLOBAL__I__ZN4Lock6s_lockE()
{
    __static_initialization_and_destruction_0(1, 65535);
}
}
