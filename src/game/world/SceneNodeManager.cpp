/*
 * SceneNodeManager
 *
 * Original file: SceneNodeManager.cpp
 * Area:          world
 *
 * This file mirrors the layout of the retail build.  Add the decompiled
 * functions of SceneNodeManager.cpp here, in the order they appear in the library.
 */

// Recovered translation-unit SDK startup callbacks.
#include "../core/LocalSdkStartupStorage.h"
#include "../core/LocalStartupText.h"
#include "SceneNodeManager.h"
#include "../core/NativeStdio.h"

unsigned int crcReflect(unsigned int value, char bits)
{
    unsigned int result = 0;
    for (int index = 1; index <= bits; ++index) {
        if (value & 1u)
            result |= 1u << (bits - index);
        value >>= 1;
    }
    return result;
}

void SceneNodeManager::setup()
{
}

void SceneNodeManager::update(int elapsed)
{
    if (updateInterval > 0) {
        updateTimeRemaining -= elapsed;
        if (updateTimeRemaining < 0)
            updateTimeRemaining = updateInterval;
    }
}

SceneNodeManager::Pool::Pool(const char* poolName, irr::collada::CColladaFactory* poolFactory, int poolSize)
    : name(0), factory(poolFactory), size(poolSize), unknown12(0), unknown16(0),
      unknown20(0), nodesBegin(0), nodesEnd(0), nodesCapacity(0)
{
    name = new char[strlen(poolName) + 1];
    strcpy(name, poolName);
}

SceneNodeManager::SceneNodeManager()
    : poolIndexSize(0), poolIndexCompareState(false), poolsBegin(0), poolsEnd(0),
      poolsCapacity(0)
{
    updateInterval = 10000;
    updateTimeRemaining = 10000;
    for (unsigned int index = 0; index < 256; ++index) {
        crcTable[index] = crcReflect(index, 8) << 24;
        for (int bit = 0; bit < 8; ++bit)
            crcTable[index] = (crcTable[index] << 1) ^
                ((crcTable[index] & 0x80000000u) ? 0x04c11db7u : 0);
        crcTable[index] = crcReflect(crcTable[index], 32);
    }
}

void operator delete(void*) throw();
extern "C" {
static void __tcf_3() __attribute__((used));
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
        __aeabi_atexit(0, reinterpret_cast<void (*)(void*)>(__tcf_3), &__dso_handle);
        new (irr::ps::vHalf) irr::ps::LocalVector3(0.5f, 0.5f, 0.5f);
    }
}

extern "C" {
static void _GLOBAL__I__Z10crcReflectjc() __attribute__((used));
static void _GLOBAL__I__Z10crcReflectjc()
{
    __static_initialization_and_destruction_0(1, 65535);
}
}

extern "C" {
static void __tcf_3()
{
    irr::scene::quake3::LocalStringStorage& value = irr::scene::quake3::irrEmptyStringc;
    if (!value.reference && value.array && value.array != value.inlineBuffer)
        ::operator delete(value.array);
}
}
