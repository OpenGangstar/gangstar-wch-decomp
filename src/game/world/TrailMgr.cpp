/*
 * TrailMgr
 *
 * Original file: TrailMgr.cpp
 * Area:          world
 *
 * This file mirrors the layout of the retail build.  Add the decompiled
 * functions of TrailMgr.cpp here, in the order they appear in the library.
 */

// Recovered translation-unit SDK string startup callbacks.
#include "../core/LocalStringStartupStorage.h"
#include "../core/LocalStartupText.h"
#include "TrailMgr.h"
#include "Trail.h"
#include "../core/NativeStdio.h"

TrailMgr::TrailMgr() : trails(0), allocated(0), trailCount(0)
{
}

static inline bool IsTrailDead(Trail* trail)
{
    return trail->points[0].remainingLife <= 0;
}

bool TrailMgr::AllocTrailList(Trail** list, int count)
{
    int found = 0;
    int i;
    if (!trails)
        return false;
    for (i = 0; i < trailCount; ++i) {
        Trail* trail = trails[i];
        if (trail && !allocated[i] && IsTrailDead(trail)) {
            list[found] = trail;
            allocated[i] = true;
            ++found;
        }
    }
    if (found != count) {
        int j = 0;
        for (i = 0; i < trailCount && j < count && list[j]; ++i) {
            if (list[j] == trails[i]) {
                allocated[i] = false;
                ++j;
            }
        }
        return false;
    }
    return true;
}

TrailMgr::~TrailMgr()
{
    trailCount = 0;
}

void TrailMgr::SetSegmentWidth(float width)
{
    for (int i = 0; i < trailCount; ++i) {
        Trail* trail = trails[i];
        if (trail)
            trail->SetSegmentWidth(width);
    }
}

void TrailMgr::CleanUp()
{
    for (int i = 0; i < trailCount; ++i)
        delete trails[i];

    delete[] allocated;
    delete[] trails;
}

bool TrailMgr::Init(int count, int pointCount, int mode, int lifetime, float width, float scale)
{
    allocated = new bool[count];
    memset(allocated, 0, count);
    trails = new Trail*[count];
    if (!trails)
        return false;

    trailCount = count;
    memset(trails, 0, count * sizeof(Trail*));
    trailMode = mode;
    trailScale = scale;
    for (int i = 0; i < trailCount; ++i) {
        trails[i] = new Trail();
        if (!trails[i] || !trails[i]->Init(pointCount, mode, lifetime, width, scale))
            return false;
    }
    return true;
}

Trail* TrailMgr::AllocTrail()
{
    for (int i = 0; i < trailCount; ++i) {
        if (trails[i] && !allocated[i] && trails[i]->points[0].remainingLife <= 0) {
            allocated[i] = true;
            char* const slots = reinterpret_cast<char*>(trails);
            const unsigned int offset = i * sizeof(Trail*);
            return *reinterpret_cast<Trail**>(slots + offset);
        }
    }
    return 0;
}

void TrailMgr::Update()
{
    for (int i = 0; i < trailCount; ++i) {
        Trail* trail = trails[i];
        if (trail)
            trail->Update();
    }
}

void TrailMgr::FreeTrail(Trail* trail)
{
    for (int i = 0; i < trailCount; ++i) {
        if (trails[i] == trail) {
            allocated[i] = false;
            return;
        }
    }
}

void TrailMgr::Render()
{
    for (int i = 0; i < trailCount; ++i) {
        Trail* trail = trails[i];
        if (trail && !IsTrailDead(trail))
            trail->Render();
    }
}

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
static void _GLOBAL__I__ZN8TrailMgrC2Ev() __attribute__((used));
static void _GLOBAL__I__ZN8TrailMgrC2Ev()
{
    __static_initialization_and_destruction_0(1, 65535);
}
}
