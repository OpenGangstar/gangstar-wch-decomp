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
#include "TargetMarkerSingleton.h"
#include "../characters/AnimObject.h"
#include "../world/LevelObject.h"

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

// Imported STLport allocator for the retail tracking node specialization.
extern "C" void* allocateTrackingNode(void*, unsigned int, const void*)
    __asm__("_ZNSaIN9stlp_priv10_List_nodeIN7MiniMap15TrackableObjectEEEE8allocateEjPKv")
    __attribute__((weak));

void MiniMap::registerForMapTracking(LevelObject* object, bool flag)
{
    if (object->unknown44 == -1)
        return;

    TrackingLink* const end = &trackedObjects;
    for (TrackingLink* link = trackedObjects.next; end != link; link = link->next) {
        if (__builtin_expect(static_cast<TrackingNode*>(link)->object == object, 0))
            return;
    }

    AnimObject* marker = new AnimObject;
    marker->sprite = sprite;
    marker->SetAnim(object->unknown44);

    TrackingNode* node = static_cast<TrackingNode*>(allocateTrackingNode(end, 1, 0));
    node->flag = flag;
    node->marker = marker;
    node->object = object;
    TrackingLink* previous = trackedObjects.previous;
    node->next = end;
    node->previous = previous;
    previous->next = node;
    trackedObjects.previous = node;
}

void MiniMap::deregisterForMapTracking(LevelObject* object)
{
    if (object->unknown44 == -1)
        return;

    for (TrackingLink* link = trackedObjects.next; link != &trackedObjects; link = link->next) {
        TrackingNode* node = static_cast<TrackingNode*>(link);
        if (__builtin_expect(node->object == object, 0)) {
            delete node->marker;
            TrackingLink* next = node->next;
            TrackingLink* previous = node->previous;
            previous->next = next;
            next->previous = previous;
            delete node;
            return;
        }
    }
}

MiniMap::~MiniMap()
{
    TrackingLink* link = trackedObjects.next;
    TrackingLink* const end = &trackedObjects;
    if (link != end) {
        do {
            delete static_cast<TrackingNode*>(link)->marker;
            link = link->next;
        } while (link != end);
    }
    clearTrackedObjects(link);
}

void MiniMap::update(double)
{
    if (!followedObject || !(flags & 1))
        return;

    const float speed = followedObject->GetSpeed();
    if (speed <= minimumSpeed)
        scale = minimumScale;
    else if (speed < maximumSpeed)
        scale = minimumScale + (maximumScale - minimumScale)
            * ((speed - minimumSpeed) / (maximumSpeed - minimumSpeed));
    else
        scale = maximumScale;

    TrackingLink* const end = &trackedObjects;
    for (TrackingLink* link = trackedObjects.next; link != end; link = link->next) {
        TrackingNode* node = static_cast<TrackingNode*>(link);
        if (node->flag)
            node->marker->UpdateFrame();
    }
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
