/*
 * Trail
 *
 * Original file: Trail.cpp
 * Area:          world
 *
 * This file mirrors the layout of the retail build.  Add the decompiled
 * functions of Trail.cpp here, in the order they appear in the library.
 */

// Recovered translation-unit SDK startup callbacks.
#include "../core/LocalSdkStartupStorage.h"
#include "../core/LocalStartupText.h"
#include "Trail.h"
#include "../app/Application.h"
#include "../core/SceneNode.h"

namespace {
// Trail cleanup uses retail scene-manager slot 69.
class TrailSceneManager : public irr::scene::ISceneManager {
public:
    virtual void unknown68();
    virtual void addToDeletionQueue(irr::scene::ISceneNode* node);
};
}

Trail::Trail() : trailPointCount(0), lastAddedPoint()
{
    trailLifetime = 600;
    segmentWidth = 25.0f;
    segmentCount = 0;
    triangleCount = 0;
    unknown64[0] = unknown64[1] = unknown64[2] = unknown64[3] = 255;
    vertexCount = 0;
    indexCount = 0;
    points = 0;
    unknown40 = 0;
    activePointCount = 0;
    unknown76 = false;
}

void Trail::CleanUp()
{
    irr::scene::ISceneManager* manager = Application::GetInstance()->GetDevice()->getSceneManager();
    reinterpret_cast<TrailSceneManager*>(manager)->addToDeletionQueue(meshSceneNode);
    trailLifetime = 600;
    segmentWidth = 25.0f;
    trailPointCount = 0;
    segmentCount = 0;
    triangleCount = 0;
    vertexCount = 0;
    indexCount = 0;
    unknown40 = 0;
    activePointCount = 0;
    delete[] points;
    delete[] indices;
    unknown76 = false;
}

Trail::~Trail()
{
    CleanUp();
}

void Trail::ModifyLife(float scale)
{
    activePointCount = 0;
    for (int i = 0; i < trailPointCount && points[i].remainingLife > 0; ++i) {
        points[i].remainingLife = static_cast<int>(points[i].remainingLife * scale);
        ++activePointCount;
    }
}

bool Trail::Init(int pointCount, int mode, int lifetime, float width, float scale)
{
    trailMode = mode;
    trailScaleSquared = scale * scale;
    segmentWidth = width;
    vertexCount = pointCount * 2;
    segmentCount = pointCount - 1;
    trailLifetime = lifetime;
    trailPointCount = pointCount;
    triangleCount = segmentCount * 2;
    indexCount = triangleCount * 3;
    points = new TrailPoint[pointCount];
    meshSceneNode = 0;
    unknown76 = false;
    CreateMeshSceneNode();
    return true;
}

void Trail::SetSegmentWidth(float width)
{
    segmentWidth = width;
}

void Trail::Render()
{
}

void Trail::SetLastAddedPoint(irr::core::vector3d<float> point)
{
    lastAddedPoint = point;
}

void operator delete(void*) throw();
extern "C" {
static void __tcf_2() __attribute__((used));
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
        __aeabi_atexit(0, reinterpret_cast<void (*)(void*)>(__tcf_2), &__dso_handle);
        new (irr::ps::vHalf) irr::ps::LocalVector3(0.5f, 0.5f, 0.5f);
    }
}

extern "C" {
static void _GLOBAL__I__ZN5TrailC2Ev() __attribute__((used));
static void _GLOBAL__I__ZN5TrailC2Ev()
{
    __static_initialization_and_destruction_0(1, 65535);
}
}

extern "C" {
static void __tcf_2()
{
    irr::scene::quake3::LocalStringStorage& value = irr::scene::quake3::irrEmptyStringc;
    if (!value.reference && value.array && value.array != value.inlineBuffer)
        ::operator delete(value.array);
}
}
