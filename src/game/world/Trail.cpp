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
#include "../core/MeshSceneInterfaces.h"
#include "../core/MeshBufferInterfaces.h"

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
    // Trail cleanup uses retail scene-manager slot 69.
    manager->addToDeletionQueue(meshSceneNode);
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

bool Trail::Update(irr::core::vector3d<float>& left, irr::core::vector3d<float>& right, bool force)
{
    if (activePointCount > 1) {
        const irr::core::vector3d<float> delta(left.X - lastAddedPoint.X, left.Y - lastAddedPoint.Y, 0.0f);
        if (!force && !(delta.getLengthSQ() > trailScaleSquared)) {
            points[0].remainingLife = trailLifetime;
            points[0].left = left;
            points[0].right = right;
            BuildPoint(0, false);
            return false;
        }
        if (unknown76) {
            AddPoint(lastAddedPoint, right, true);
            AddPoint(left, right, true);
            AddPoint(left, right, false);
            unknown76 = false;
            return true;
        }
    }
    AddPoint(left, right, false);
    return true;
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

namespace {
struct TrailVertex {
    irr::core::vector3d<float> position;
    irr::core::vector3d<float> normal;
    unsigned int color;
    float u;
    float v;

    void operator=(const TrailVertex& other)
    {
        position = other.position;
        normal = other.normal;
        color = other.color;
        u = other.u;
        v = other.v;
    }
};

struct TrailMeshBufferView {
    unsigned char unknown0[120];
    TrailVertex* vertices;
};
}

void Trail::AddPoint(irr::core::vector3d<float>& left,
    irr::core::vector3d<float>& right, bool buildFlag)
{
    irr::scene::IMeshBuffer* buffer =
        static_cast<irr::scene::IMeshSceneNode*>(meshSceneNode)->getMesh()->getMeshBuffer(0);
    TrailMeshBufferView* mesh = reinterpret_cast<TrailMeshBufferView*>(buffer);
    lastAddedPoint = left;

    for (int i = trailPointCount - 1; i > 0; --i) {
        points[i] = points[i - 1];
        const int current = 2 * i;
        const int previous = current - 2;
        mesh->vertices[current] = mesh->vertices[previous];
        const int destination = current + 1;
        const int source = current - 1;
        mesh->vertices[destination] = mesh->vertices[source];
    }

    points[0].remainingLife = trailLifetime;
    points[0].left = left;
    points[0].right = right;
    ++activePointCount;
    if (activePointCount > trailPointCount)
        activePointCount = trailPointCount;
    if (activePointCount == 2)
        BuildPoint(1, buildFlag);
    if (activePointCount > 1)
        BuildPoint(0, buildFlag);
}
