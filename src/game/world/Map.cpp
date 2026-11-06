/*
 * Map
 *
 * Original file: Map.cpp
 * Area:          world
 *
 * This file mirrors the layout of the retail build.  Add the decompiled
 * functions of Map.cpp here, in the order they appear in the library.
 */

#include "Map.h"
#include "../app/Application.h"
#include "../core/SceneNode.h"
#include "../core/VideoDriver.h"

void Map::clean()
{
    if (texture) {
        Application::GetInstance()->GetDevice()->getVideoDriver()->removeTexture(texture);
        texture = 0;
    }
}

Map::~Map()
{
    clean();
}

Map::Map()
    : texture(0), offsetX(0.0f), offsetY(0.0f),
      unknown20(0), unknown24(0), unknown28(0), unknown32(0), unknown36(0), unknown40(0),
      minX(0.0f), minY(0.0f), maxX(0.0f), maxY(0.0f), unknown60(0.0f), unknown64(0.0f)
{
    setMap(DefaultMap);
}

// Recovered translation-unit SDK startup callbacks.
#include "../core/LocalSdkStartupStorage.h"
#include "../core/LocalStartupText.h"

void operator delete(void*) throw();
extern "C" {
static void __tcf_3() __attribute__((used));
}

extern void* __dso_handle;
extern "C" {
int __aeabi_atexit(void*, void (*)(void*), void*);
void* _ZN3irr4core6stringIcNS0_12irrAllocatorIcEEEaSIcEERS4_PKT_(void*, const char*) __attribute__((weak));
}

extern "C" {
static void __tcf_3()
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
        __aeabi_atexit(0, reinterpret_cast<void (*)(void*)>(__tcf_3), &__dso_handle);
        new (irr::ps::vHalf) irr::ps::LocalVector3(0.5f, 0.5f, 0.5f);
    }
}

extern "C" {
static void _GLOBAL__I__ZN3MapC2Ev() __attribute__((used));
static void _GLOBAL__I__ZN3MapC2Ev()
{
    __static_initialization_and_destruction_0(1, 65535);
}
}
