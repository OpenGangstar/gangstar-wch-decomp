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
#include "../core/IrrlichtDevice.h"
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

#include "../core/Array.h"
#include "../core/VideoDriver.h"
namespace {
struct TrailUpdateVertex {
    irr::core::vector3d<float> position;
    irr::core::vector3d<float> normal;
    irr::video::SColor color;
    float textureCoordinates[2];
};

struct TrailMeshBuffer : irr::scene::IMeshBuffer {
    unsigned char unknown4[116];
    irr::core::array<TrailUpdateVertex> vertices;
    irr::core::array<unsigned short> indices;
};
}

void Trail::Update()
{
    activePointCount = 0;
    for (int i = 0; i < trailPointCount; ++i) {
        points[i].remainingLife = irr::core::max_(points[i].remainingLife - 1, 0);
        if (points[i].remainingLife <= 0)
            break;
        ++activePointCount;
    }

    const int activeIndexCount = activePointCount * 6 - 6;
    if (activeIndexCount > 0) {
        TrailMeshBuffer* buffer = static_cast<TrailMeshBuffer*>(static_cast<irr::scene::IMeshSceneNode*>(meshSceneNode)->getMesh()->getMeshBuffer(0));
        if (static_cast<unsigned int>(activeIndexCount) > buffer->indices.allocated)
            buffer->indices.reallocate(activeIndexCount);
        buffer->indices.used = activeIndexCount;
        for (int i = 0; i < activeIndexCount; ++i)
            buffer->indices.data[i] = indices[i];

        for (int i = 0, vertexOffset = 0; i < trailPointCount; ++i, vertexOffset += 2 * sizeof(TrailUpdateVertex)) {
            const unsigned char alpha = static_cast<unsigned char>(static_cast<float>(points[i].remainingLife) / trailLifetime * 192.0f);
            reinterpret_cast<TrailUpdateVertex*>(reinterpret_cast<char*>(buffer->vertices.data) + vertexOffset)->color.a = alpha;
            reinterpret_cast<TrailUpdateVertex*>(reinterpret_cast<char*>(buffer->vertices.data) + vertexOffset)[1].color.a = alpha;
        }
        meshSceneNode->setVisible(true);
    } else {
        meshSceneNode->setVisible(false);
    }
}



// Integrate with the shared trail mesh vertex/buffer view if available.
#include "Trail.h"
#include "../core/Color.h"
#include "../core/MeshBufferInterfaces.h"
#include "../core/MeshSceneInterfaces.h"

extern "C" float sqrtf(float value);
extern const float g_trailTexOffsetY[3][2] __attribute__((visibility("hidden")));
const float g_trailTexOffsetY[3][2] = {
    {0.0f, 1.0f},
    {0.25f, 0.5f},
    {0.5f, 0.75f}
};

namespace {
struct TrailBuildVertexView {
    irr::core::vector3d<float> position;
    irr::core::vector3d<float> normal;
    irr::video::SColor color;
    float u;
    float v;
};
struct TrailBuildMeshBufferView {
    unsigned char unknown0[120];
    TrailBuildVertexView* vertices;
};
}

void Trail::BuildPoint(int index, bool transparent)
{
    typedef irr::core::vector3d<float> Vector;
    Vector direction;
    if (index == 0)
        direction = points[0].left - points[1].left;
    else
        direction = points[index - 1].left - points[index].left;
    direction.normalize();

    const Vector& lateral = points[index].right;
    Vector normal;
    normal.X = (-direction.Y * lateral.Z) + (direction.Z * lateral.Y);
    normal.Y = (-direction.Z * lateral.X) + (lateral.Z * direction.X);
    normal.Z = (lateral.Y * -direction.X) + (direction.Y * lateral.X);
    normal.normalize();

    const float halfWidth = 0.5f * segmentWidth;
    const float offsetX = halfWidth * normal.X;
    const float offsetY = halfWidth * normal.Y;
    const float offsetZ = halfWidth * normal.Z;
    const Vector& center = points[index].left;
    const float centerX = center.X;
    const float leftX = centerX - offsetX;
    const float centerY = center.Y;
    const float leftY = centerY - offsetY;
    const float centerZ = center.Z;
    const float rightX = offsetX + centerX;
    const float rightY = offsetY + centerY;
    float length = 0.0f;
    if (index != activePointCount) {
        const Vector& next = points[index + 1].left;
        const float dx = centerX - next.X;
        const float dy = centerY - next.Y;
        const float dz = centerZ - next.Z;
        length += sqrtf(dx * dx + dy * dy + dz * dz);
    }

    irr::scene::IMeshBuffer* buffer =
        static_cast<irr::scene::IMeshSceneNode*>(meshSceneNode)->getMesh()->getMeshBuffer(0);
    TrailBuildMeshBufferView* mesh = reinterpret_cast<TrailBuildMeshBufferView*>(buffer);
    float leftU = 0.0f;
    float rightU = 0.0f;
    if (index != 0) {
        leftU = rightU = 0.0f;
    } else {
        TrailBuildVertexView* vertices = mesh->vertices;
        leftU = length + vertices[2].u;
        rightU = length + vertices[3].u;
    }

    const int leftIndex = 2 * index;
    const int rightIndex = leftIndex + 1;
    mesh->vertices[leftIndex].position.X = leftX;
    mesh->vertices[leftIndex].position.Y = leftY;
    mesh->vertices[leftIndex].position.Z = centerZ - offsetZ;
    *reinterpret_cast<unsigned int*>(&mesh->vertices[leftIndex].color) =
        *reinterpret_cast<const unsigned int*>(unknown64);
    mesh->vertices[rightIndex].position.X = rightX;
    mesh->vertices[rightIndex].position.Y = rightY;
    mesh->vertices[rightIndex].position.Z = offsetZ + centerZ;
    *reinterpret_cast<unsigned int*>(&mesh->vertices[rightIndex].color) =
        *reinterpret_cast<const unsigned int*>(unknown64);
    if (transparent) {
        mesh->vertices[leftIndex].u = 0.0f;
        mesh->vertices[leftIndex].v = 0.0f;
        mesh->vertices[rightIndex].u = 0.0f;
        mesh->vertices[rightIndex].v = 0.0f;
        mesh->vertices[rightIndex].color.a = 0;
        mesh->vertices[leftIndex].color.a = 0;
    } else {
        mesh->vertices[leftIndex].u = leftU;
        mesh->vertices[leftIndex].v = 1.0f - g_trailTexOffsetY[trailMode][1];
        mesh->vertices[rightIndex].u = rightU;
        mesh->vertices[rightIndex].v = 1.0f - g_trailTexOffsetY[trailMode][0];
    }
}


namespace irr {
namespace video {
struct S3DVertex {
    core::vector3d<float> position;
    core::vector3d<float> normal;
    SColor color;
    float textureCoordinates[2];
};
}
namespace scene {
template <class Vertex>
struct CMeshBuffer : IMeshBuffer, virtual IReferenceCounted {
    CMeshBuffer() __attribute__((weak));
    unsigned char unknown4[116];
    core::array<Vertex> vertices;
    core::array<unsigned short> indices;
    unsigned char unknown160[24];
};

struct SMesh : IMesh, virtual IReferenceCounted {
    unsigned char unknown4[32];
    core::array<IMeshBuffer*> meshBuffers;
    unsigned char unknown56[24];
};
}
}

extern "C" void _ZN3irr5scene5SMeshC1Ev(irr::scene::SMesh*) __attribute__((weak));

namespace trail_assets {
extern const char meshName[] __attribute__((visibility("hidden")));
extern const char texturePath[] __attribute__((visibility("hidden")));
}

void Trail::CreateMeshSceneNode()
{
    using namespace irr;
    scene::CMeshBuffer<video::S3DVertex>* buffer = new scene::CMeshBuffer<video::S3DVertex>();
    const unsigned int usedVertices = vertexCount;
    if (usedVertices > buffer->vertices.allocated)
        buffer->vertices.reallocate(usedVertices);
    buffer->vertices.used = usedVertices;

    indices = new unsigned short[indexCount];
    int i = 1;
    int index = 6;
    unsigned short vertex = 0;
    for (; i < trailPointCount; ++i, index += 6) {
        const unsigned short following = static_cast<unsigned short>(i) << 1;
        const unsigned short right = vertex + 1;
        indices[index - 6] = vertex;
        indices[index - 5] = right;
        indices[index - 4] = following;
        indices[index - 3] = vertex + 3;
        indices[index - 2] = following;
        indices[index - 1] = right;
        vertex += 2;
    }

    scene::SMesh* mesh = static_cast<scene::SMesh*>(::operator new(sizeof(scene::SMesh)));
    _ZN3irr5scene5SMeshC1Ev(mesh);
    scene::IMeshBuffer* meshBuffer = buffer;
    ++buffer->references;
    mesh->meshBuffers.push_back(meshBuffer);
    buffer->drop();

    scene::ISceneManager* sceneManager = Application::GetInstance()->GetDevice()->getSceneManager();
    meshSceneNode = sceneManager->addMeshSceneNode(mesh, 0, -1,
        core::vector3d<float>(), core::vector3d<float>(), core::vector3d<float>(1.0f, 1.0f, 1.0f), false);
    mesh->drop();
    if (meshSceneNode) {
        sceneManager->getRootSceneNode()->addChild(meshSceneNode);
        meshSceneNode->setName(trail_assets::meshName);
        meshSceneNode->setMaterialType(static_cast<video::E_MATERIAL_TYPE>(25));
        meshSceneNode->setMaterialFlag(video::MaterialFlag256, false);
        meshSceneNode->setMaterialFlag(video::MaterialFlag128, true);
        meshSceneNode->setMaterialFlag(video::MaterialFlag16, false);
        meshSceneNode->setMaterialFlag(video::MaterialFlag2, false);
        meshSceneNode->setAutomaticCulling(scene::EAC_OFF);
        meshSceneNode->setVisible(false);
        video::ITexture* texture = Application::GetInstance()->GetDevice()->getVideoDriver()->getTexture(trail_assets::texturePath);
        meshSceneNode->setMaterialTexture(0, texture);
    }
}







typedef char CheckVertex36[sizeof(irr::video::S3DVertex)==36?1:-1];
typedef char CheckBuffer196[sizeof(irr::scene::CMeshBuffer<irr::video::S3DVertex>)==196?1:-1];
typedef char CheckMesh92[sizeof(irr::scene::SMesh)==92?1:-1];
