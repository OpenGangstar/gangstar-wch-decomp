/*
 * GS3DStuff
 *
 * Original file: GS3DStuff.cpp
 * Area:          rendering
 *
 * This file mirrors the layout of the retail build.  Add the decompiled
 * functions of GS3DStuff.cpp here, in the order they appear in the library.
 */

#include "GS3DStuff.h"
#include "../core/LocalStartupStorage.h"
#include "../core/LocalStartupText.h"
#include "../app/CGameFactory.h"
#include "CustomBillboardSceneNode.h"
#include "../core/NativeStdio.h"
#include "../core/Lock.h"
#include "../app/Application.h"
#include "../persistence/DataStream.h"
#include "../input/TouchScreenBase.h"
#include "../audio/SoundManager.h"
#include "../characters/PlayerTest.h"
#include "../hud/CHudManager.h"
#include "../core/EventManager.h"

bool GS3DStuff::getProperty(const void* properties, const char* name, char* output)
{
    if (!properties) return false;
    const char* text = *static_cast<const char* const*>(properties);
    const char* found = strstr(text, name);
    if (!found) return false;
    const char* end = strchr(found, ';');
    if (!end) {
        end = strchr(found, '\n');
        if (!end) end = text + strlen(text);
    }
    const char* value = strchr(found, '=') + 1;
    int length = end - value;
    memcpy(output, value, length);
    output[length + 1] = 0;
    return true;
}

namespace GameFactoryProperties {
const char billboard[] __attribute__((section(".rodata.game_factory_billboard"))) = "billboard";
}


BulletTraceManager* GS3DStuff::s_bulletManager;
TrailMgr* GS3DStuff::s_TrailMgr;
irr::scene::ISceneNode* GS3DStuff::skyBox;
irr::video::ITexture* GS3DStuff::skyBoxTexture;
OctTreeAABB* GS3DStuff::sceneOcttree;
Structs::PhonePerformanceProfile GS3DStuff::s_phonePerformanceProfile;
unsigned int GS3DStuff::lastTime;

// Only the touch-screen and event-manager words at 44 and 56 are observed here.
struct ApplicationEventView {
    unsigned char unknown0[44];
    TouchScreenBase* touchScreen;
    unsigned char unknown48[8];
    EventManager* eventManager;
};

GS3DStuff::GS3DStuff() : unknownFlag20(false), drawable(false), unknown24(0) {}
GS3DStuff::~GS3DStuff()
{
    reinterpret_cast<ApplicationEventView*>(Application::GetInstance())->eventManager->detach(4, this);
}

void GS3DStuff::draw(const StateMachine*)
{
    Lock::getInstance()->render();
}

void GS3DStuff::ctor(const StateMachine*)
{
    SoundManager* sound = SoundManager::getInstance();
    int ambientSound = PlayerTest::GetPlayer()->getAmbientSound();
    sound->unknown140 = true;
    sound->playEx(ambientSound, 0, true, 1.0f, 0, true, 1.0f, 0);
    sound->unknown140 = false;
    Application::GetInstance()->GetHudManager()->show();
    reinterpret_cast<ApplicationEventView*>(Application::GetInstance())->touchScreen->clear();
}

void GS3DStuff::wakeup(const StateMachine*)
{
    lastTime = Application::GetInstance()->GetDevice()->getTimer()->getRealTime();
    reinterpret_cast<ApplicationEventView*>(Application::GetInstance())->touchScreen->clear();
}

void GS3DStuff::resume(const StateMachine*)
{
    lastTime = Application::GetInstance()->GetDevice()->getTimer()->getRealTime();
    reinterpret_cast<ApplicationEventView*>(Application::GetInstance())->touchScreen->clear();
}

static const char eventFormat[] __attribute__((section(".rodata.gs_event_format"))) = "%i\n";
static const char touchEventText[] __attribute__((section(".rodata.gs_touch_event"))) = "TOUCHSCREEN_PRESS";

void GS3DStuff::onEvent(const IEvent* event, const EventManager*)
{
    printf(eventFormat, event->getEventID());
    switch (event->getEventID()) {
    case 4: puts(touchEventText); break;
    }
}

void Structs::PhonePerformanceProfile::Read(DataStream& stream)
{
    unknown0 = stream.ReadInt();
    unknown4 = stream.ReadInt();
    textureNameSuffix = stream.ReadAndAllocateString();
}


BulletTraceManager* GS3DStuff::GetBulletManager() { return s_bulletManager; }
TrailMgr* GS3DStuff::GetTrailMgr() { return s_TrailMgr; }
irr::scene::ISceneNode* GS3DStuff::OptimizeHierarchy(irr::scene::ISceneNode*) { return 0; }
void GS3DStuff::dtor(const StateMachine*) {}
irr::scene::ISceneNode* GS3DStuff::getSkyBox() { return skyBox; }
irr::video::ITexture* GS3DStuff::getSkyBoxTexture() { return skyBoxTexture; }
char* GS3DStuff::getTextureNameSuffix() { return s_phonePerformanceProfile.textureNameSuffix; }
OctTreeAABB* GS3DStuff::getSceneOctTree() { return sceneOcttree; }
void GS3DStuff::draw2d(const StateMachine*) {}

struct GS3DLightNodes {
    void* data;
    unsigned int allocated;
    unsigned int used;
    bool ownsData;
    bool sorted;
    unsigned int reserved;
};

GS3DLightNodes GS3DStuff::lightsNodes;

void operator delete(void*) throw();
extern "C" {
static void __tcf_9() __attribute__((used));
static void __tcf_10() __attribute__((used));
static void __tcf_9()
{
    irr::scene::quake3::LocalStringStorage& value = irr::scene::quake3::irrEmptyStringc;
    if (!value.reference && value.array && value.array != value.inlineBuffer)
        ::operator delete(value.array);
}
}

// Scoped imports distinguish the original TU-local transition tables.
namespace retail_gs3dstuff_transitions {
extern const unsigned int civPassive_trans[] __attribute__((visibility("hidden")));
extern const unsigned int scriptedNpc_trans[] __attribute__((visibility("hidden")));
extern const unsigned int civAggressive_trans[] __attribute__((visibility("hidden")));
extern const unsigned int gangMember_trans[] __attribute__((visibility("hidden")));
extern const unsigned int cop_trans[] __attribute__((visibility("hidden")));
extern const unsigned int swat_trans[] __attribute__((visibility("hidden")));
extern const unsigned int civ_vehicle_trans[] __attribute__((visibility("hidden")));
extern const unsigned int cop_vehicle_trans[] __attribute__((visibility("hidden")));
extern const unsigned int guard_trans[] __attribute__((visibility("hidden")));
extern const unsigned int scripted_vehicle_trans[] __attribute__((visibility("hidden")));
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
        __aeabi_atexit(0, reinterpret_cast<void (*)(void*)>(__tcf_9), &__dso_handle);
        new (gameloft::ai::civ_passive) gameloft::ai::LocalTransitionList(retail_gs3dstuff_transitions::civPassive_trans, 75);
        new (gameloft::ai::npc_scripted) gameloft::ai::LocalTransitionList(retail_gs3dstuff_transitions::scriptedNpc_trans, 12);
        new (gameloft::ai::civ_agressive) gameloft::ai::LocalTransitionList(retail_gs3dstuff_transitions::civAggressive_trans, 57);
        new (gameloft::ai::gang_member) gameloft::ai::LocalTransitionList(retail_gs3dstuff_transitions::gangMember_trans, 3);
        new (gameloft::ai::cop) gameloft::ai::LocalTransitionList(retail_gs3dstuff_transitions::cop_trans, 78);
        new (gameloft::ai::swat) gameloft::ai::LocalTransitionList(retail_gs3dstuff_transitions::swat_trans, 3);
        new (gameloft::ai::civ_vehicle) gameloft::ai::LocalTransitionList(retail_gs3dstuff_transitions::civ_vehicle_trans, 36);
        new (gameloft::ai::cop_vehicle) gameloft::ai::LocalTransitionList(retail_gs3dstuff_transitions::cop_vehicle_trans, 45);
        new (gameloft::ai::guard) gameloft::ai::LocalTransitionList(retail_gs3dstuff_transitions::guard_trans, 42);
        new (gameloft::ai::scripted_vehicle) gameloft::ai::LocalTransitionList(retail_gs3dstuff_transitions::scripted_vehicle_trans, 21);
        new (irr::ps::vHalf) irr::ps::LocalVector3(0.5f, 0.5f, 0.5f);
        GS3DLightNodes& nodes = GS3DStuff::lightsNodes;
        nodes.data = 0;
        nodes.allocated = 0;
        nodes.used = 0;
        nodes.ownsData = true;
        nodes.sorted = true;
        nodes.reserved = 1;
        __aeabi_atexit(0, reinterpret_cast<void (*)(void*)>(__tcf_10), &__dso_handle);
    }
}

extern "C" {
static void _GLOBAL__I__ZN9GS3DStuff15s_bulletManagerE() __attribute__((used));
static void _GLOBAL__I__ZN9GS3DStuff15s_bulletManagerE()
{
    __static_initialization_and_destruction_0(1, 65535);
}
}

extern "C" {
static void __tcf_10()
{
    GS3DLightNodes& nodes = GS3DStuff::lightsNodes;
    if (nodes.ownsData)
        ::operator delete(nodes.data);
}
}
