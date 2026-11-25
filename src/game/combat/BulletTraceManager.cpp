/*
 * BulletTraceManager
 *
 * Original file: BulletTraceManager.cpp
 * Area:          combat
 *
 * This file mirrors the layout of the retail build.  Add the decompiled
 * functions of BulletTraceManager.cpp here, in the order they appear in the library.
 */

#include "BulletTraceManager.h"
#include "../core/Collada.h"
#include "../app/Application.h"
#include "../core/Geometry.h"
#include "../core/SceneNode.h"
#include "../core/IrrlichtDevice.h"
#include "../core/LocalSdkStartupStorage.h"
#include "../core/VideoDriver.h"

// Accessed native offsets only; not the full scene-node hierarchy or extent.
struct BulletTraceObservedLayout {
    unsigned char unknown0[280];
    irr::scene::ISceneManager* sceneManager;
    unsigned char unknown284[460];
    int activeTraces;
    unsigned char unknown748[1004];
    irr::scene::ISceneNode** impacts;
};
typedef char BulletTracePrefixExtent[sizeof(BulletTraceObservedLayout) == 1756 ? 1 : -1];

irr::scene::ISceneNode** BulletTraceManager::getImpacts()
{
    return reinterpret_cast<BulletTraceObservedLayout*>(this)->impacts;
}

void BulletTraceManager::OnRegisterSceneNode()
{
    BulletTraceObservedLayout* state = reinterpret_cast<BulletTraceObservedLayout*>(this);
    if (state->activeTraces > 0) {
        // The native primary scene-node base is at offset zero.
        irr::scene::ISceneNode* node = reinterpret_cast<irr::scene::ISceneNode*>(this);
        irr::scene::E_CULLING_TYPE culling = node->getAutomaticCulling();
        node->setAutomaticCulling(irr::scene::EAC_OFF);
        state->sceneManager->registerNodeForRendering(node, 0, 0, irr::scene::RenderPass6);
        node->setAutomaticCulling(culling);
    }
}

const irr::core::aabbox3d<float>& BulletTraceManager::getBoundingBox() const
{
    static irr::core::aabbox3d<float> EmptyBox(irr::core::vector3d<float>(0, 0, 0));
    return EmptyBox;
}

void WepaonAnimCallback(irr::scene::ITimelineController*, void*);

void BulletTraceManager::OnAnimate(unsigned int)
{
    for (int i = 0; i < activeTraces; ++i) {
        traces[i].current += traces[i].progress;
        if (traces[i].current > 1.0f) {
            if (traces[i].showImpact) {
                impacts[i]->setVisible(true);
                impacts[i]->setPosition(traces[i].direction);
                irr::core::quaternion rotation;
                irr::core::vector3d<float> axis(1, 0, 0);
                rotation.rotationFromTo(traces[i].end, axis);
                impacts[i]->setRotation(rotation);
                impacts[i]->updateAbsolutePosition(true);
                irr::scene::ITimelineController* controller =
                    (*impacts[i]->getAnimators().begin())->getTimelineCtrl();
                if (controller) {
                    controller->setLoop(false);
                    controller->jumpTo(controller->startTime);
                    void (*callback)(irr::scene::ITimelineController*, void*) = WepaonAnimCallback;
                    void* data = impacts[i];
                    controller->callback = callback;
                    controller->callbackData = data;
                }
            }
            traces[i] = traces[activeTraces - 1];
            --activeTraces;
            --i;
        }
    }
}

extern "C" long lrand48();
void BulletTraceManager::PlayBulletTrace(const irr::core::vector3d<float>& start,
    const irr::core::vector3d<float>& target, bool flag,
    const irr::core::vector3d<float>& impact)
{
    if (activeTraces < 8) {
        BulletTraceRecord& trace = traces[activeTraces];
        trace.start = start;
        trace.direction = target;
        trace.end = impact;
        trace.showImpact = !flag;
        float length = (trace.direction-trace.start).getLength();
        trace.progress = 250.0f / length;
        trace.rate = 400.0f / length;
        trace.current = trace.rate + (-0.01f * trace.progress) * (lrand48() % 100);
        if (trace.current + trace.progress > 1.0f)
            trace.current = trace.rate - trace.progress;
        ++activeTraces;
    }
}

void BulletTraceManager::render(void*)
{
    irr::scene::ISceneManager* const& manager = reinterpret_cast<BulletTraceObservedLayout*>(this)->sceneManager;
    irr::core::vector3d<float> camera = manager->getActiveCamera()->getAbsolutePosition();
    manager->getVideoDriver()->setMaterial(material);
    manager->getVideoDriver()->setTransform(irr::video::ETS_WORLD, irr::core::matrix4());
    for (int i = 0; i < activeTraces; ++i) {
        irr::core::vector3d<float> head = irr::core::lerp(traces[i].start, traces[i].direction, traces[i].current);
        irr::core::vector3d<float> tail = irr::core::lerp(traces[i].start, traces[i].direction, traces[i].current - traces[i].rate);
        irr::core::vector3d<float> view = camera - head;
        irr::core::vector3d<float> along = tail - head;
        // along x view: preserve the native multiply/add order for floating point.
        irr::core::vector3d<float> side(
            -view.Y * along.Z + view.Z * along.Y,
            -view.Z * along.X + view.X * along.Z,
            -view.X * along.Y + view.Y * along.X);
        side.normalize();
        side *= 3.0f;
        vertices[i * 3].position = head;
        vertices[i * 3 + 1].position = head + side;
        vertices[i * 3 + 2].position = tail;
    }
    manager->getVideoDriver()->drawVertexPrimitiveList(vertices, indices, 0,
        activeTraces * 3, activeTraces, irr::video::EVT_STANDARD,
        irr::scene::EPT_TRIANGLES, irr::video::EIT_16BIT, 0);
}

void operator delete(void*) throw();
extern void* __dso_handle;
extern "C" {
int __aeabi_atexit(void*, void (*)(void*), void*);
void* _ZN3irr4core6stringIcNS0_12irrAllocatorIcEEEaSIcEERS4_PKT_(void*, const char*) __attribute__((weak));
static void __tcf_2(void*) __attribute__((used));
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
        _ZN3irr4core6stringIcNS0_12irrAllocatorIcEEEaSIcEERS4_PKT_(&value, "");
        __aeabi_atexit(0, __tcf_2, &__dso_handle);
        new (irr::ps::vHalf) irr::ps::LocalVector3(0.5f, 0.5f, 0.5f);
    }
}

extern "C" {
static void _GLOBAL__I__ZN18BulletTraceManagerC2Ev() __attribute__((used));
static void _GLOBAL__I__ZN18BulletTraceManagerC2Ev()
{
    __static_initialization_and_destruction_0(1, 65535);
}
static void __tcf_2(void*)
{
    irr::scene::quake3::LocalStringStorage& value = irr::scene::quake3::irrEmptyStringc;
    if (!value.reference && value.array && value.array != value.inlineBuffer)
        ::operator delete(value.array);
}
}

typedef char BulletTraceSceneExtent[sizeof(irr::scene::ISceneNode) == 340 ? 1 : -1];
typedef char BulletTraceExtent[sizeof(BulletTraceManager) == 1768 ? 1 : -1];

static const char impactAsset[] __attribute__((section(".rodata.bullet_impact_asset"))) = "./beretta_flash.bdae";
void* operator new[](unsigned int);
BulletTraceManager::BulletTraceManager()
    : irr::scene::ISceneNode(-1, irr::core::vector3d<float>(0,0,0), irr::core::quaternion(), irr::core::vector3d<float>(1,1,1)), activeTraces(0)
{
    material.setFlag(irr::video::MaterialFlag2,false);
    material.setFlag(irr::video::MaterialFlag256,false);
    material.setType(13);
    material.setFlag(irr::video::MaterialFlag512,false);
    material.setFlag(irr::video::MaterialFlag1024,false);
    irr::video::SColor gray;
    gray.a = 255; gray.b = 170; gray.g = 170; gray.r = 170;
    irr::video::SColor green;
    green.a = 255; green.b = 119; green.g = 119; green.r = 0;
    for(int i=0;i<24;++i) {
        indices[i]=i;
        vertices[i]=BulletTraceVertex(irr::core::vector3d<float>(0,0,0),irr::core::vector3d<float>(0,0,0),i%3==2?green:gray,0,0);
    }
    impacts=new irr::scene::ISceneNode*[8];
    for(int i=0;i<8;++i) {
        impacts[i]=irr::collada::CColladaDatabase::constructScene(impactAsset,true,&irr::collada::CColladaDatabase::DefaultFactory);
        impacts[i]->setVisible(false);
        Application::GetInstance()->GetDevice()->getSceneManager()->getRootSceneNode()->addChild(impacts[i]);
    }
}

BulletTraceManager::~BulletTraceManager()
{
    for (int i = 0; i < 8; ++i) impacts[i]->drop();
    delete[] impacts;
}
