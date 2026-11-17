/*
 * GSLoading
 *
 * Original file: GSLoading.cpp
 * Area:          app
 *
 * This file mirrors the layout of the retail build.  Add the decompiled
 * functions of GSLoading.cpp here, in the order they appear in the library.
 */

#include "GSLoading.h"

#include "../core/LocalStartupStorage.h"

#include "../core/LocalStartupText.h"

void operator delete(void*) throw();
extern "C" {
static void __tcf_4() __attribute__((used));
}

// Scoped imports distinguish the original TU-local transition tables.
namespace retail_gsloading_transitions {
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

extern "C" {
static void __tcf_4()
{
    irr::scene::quake3::LocalStringStorage& value = irr::scene::quake3::irrEmptyStringc;
    if (!value.reference && value.array && value.array != value.inlineBuffer)
        ::operator delete(value.array);
}
}

GSLoading::GSLoading() {}

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
        __aeabi_atexit(0, reinterpret_cast<void (*)(void*)>(__tcf_4), &__dso_handle);
        new (irr::ps::vHalf) irr::ps::LocalVector3(0.5f, 0.5f, 0.5f);
        new (gameloft::ai::civ_passive) gameloft::ai::LocalTransitionList(retail_gsloading_transitions::civPassive_trans, 75);
        new (gameloft::ai::npc_scripted) gameloft::ai::LocalTransitionList(retail_gsloading_transitions::scriptedNpc_trans, 12);
        new (gameloft::ai::civ_agressive) gameloft::ai::LocalTransitionList(retail_gsloading_transitions::civAggressive_trans, 57);
        new (gameloft::ai::gang_member) gameloft::ai::LocalTransitionList(retail_gsloading_transitions::gangMember_trans, 3);
        new (gameloft::ai::cop) gameloft::ai::LocalTransitionList(retail_gsloading_transitions::cop_trans, 78);
        new (gameloft::ai::swat) gameloft::ai::LocalTransitionList(retail_gsloading_transitions::swat_trans, 3);
        new (gameloft::ai::civ_vehicle) gameloft::ai::LocalTransitionList(retail_gsloading_transitions::civ_vehicle_trans, 36);
        new (gameloft::ai::cop_vehicle) gameloft::ai::LocalTransitionList(retail_gsloading_transitions::cop_vehicle_trans, 45);
        new (gameloft::ai::guard) gameloft::ai::LocalTransitionList(retail_gsloading_transitions::guard_trans, 42);
        new (gameloft::ai::scripted_vehicle) gameloft::ai::LocalTransitionList(retail_gsloading_transitions::scripted_vehicle_trans, 21);
    }
}

extern "C" {
static void _GLOBAL__I_m_background() __attribute__((used));
static void _GLOBAL__I_m_background()
{
    __static_initialization_and_destruction_0(1, 65535);
}
}

GSLoading::~GSLoading() {}

bool GSLoading::isGameLoaded()
{
    return s_bGameLoaded;
}

bool GSLoading::s_bGameLoaded = false;

void GSLoading::setGameLoaded(bool loaded)
{
    s_bGameLoaded = loaded;
}

#include "../core/ASprite.h"
#include "../hud/MenuManager.h"
ASprite* m_background = 0;
static const char loadingInterruptSpriteName[] = "./interrupt.bsprite";
void GSLoading::LoadingResumed()
{
    m_background = new ASprite(loadingInterruptSpriteName);
    m_background->unknown33 = false;
    MenuManager::getInstance()->setText(static_cast<MenuManager::eText>(7), 0x5000, 0);
}

#include "../core/ASprite.h"
#include "../hud/MenuManager.h"

extern ASprite* m_background;

void GSLoading::LoadingPaused()
{
    delete m_background;
    m_background = 0;
    MenuManager::getInstance()->setText(static_cast<MenuManager::eText>(7), static_cast<const char*>(0), 0);
}

#include "../app/Application.h"
#include "../core/ASprite.h"
#include "../hud/MenuManager.h"
#include "../input/TouchScreenBase.h"

extern ASprite* m_background;
static const char loadingSplashSprite[] = "./splash.bsprite";

void GSLoading::ctor(const StateMachine*)
{
    Application::GetInstance()->GetTouchScreen()->disable();
    if (!m_background)
        m_background = new ASprite(loadingSplashSprite);
    m_background->unknown33 = false;
    unknown4 = 0;
    unknown8 = 0;
    MenuManager::getInstance()->setText(static_cast<MenuManager::eText>(7), 0x5000, 0);
}

#include "Application.h"
#include "../hud/MenuManager.h"
#include "../input/TouchScreenBase.h"
void GSLoading::dtor(const StateMachine*)
{
    MenuManager::getInstance()->setText(static_cast<MenuManager::eText>(7), -1, 0);
    MenuManager::getInstance()->setText(static_cast<MenuManager::eText>(8), static_cast<const char*>(0), 0);
    s_bGameLoaded = true;
    Application::GetInstance()->GetTouchScreen()->clear();
    Application::GetInstance()->GetTouchScreen()->enable();
}

#include "../app/Application.h"
#include "../ai/StateMachine.h"
#include "../core/NativeStdio.h"
#include "../hud/MenuManager.h"
#include "../input/TouchScreenBase.h"
#include "../rendering/GS3DStuff.h"

template<> GS3DStuff* StateMachine::switchState<GS3DStuff>() __attribute__((weak));
static const char loadingPercentFormat[] = "%i%%";

void GSLoading::update(StateMachine* machine)
{
    if (unknown4 <= 13) {
        char text[8];
        sprintf(text, loadingPercentFormat, unknown8);
        MenuManager::getInstance()->setText(static_cast<MenuManager::eText>(8), text, 0);
        unknown4 = GS3DStuff::load(unknown4, unknown8);
        Application::GetInstance()->GetTouchScreen()->clear();
    } else {
        ++unknown4;
    }
    if (unknown4 == 17)
        machine->switchState<GS3DStuff>();
}

#include "../core/ASprite.h"
#include "../app/Application.h"
#include "../core/VideoDriver.h"
#include "../core/SceneNode.h"

extern ASprite* m_background;

void GSLoading::draw(const StateMachine*)
{
    Application::GetInstance()->GetDevice()->getVideoDriver()->beginScene2D();
    m_background->PaintFrame(0, 0, 0, 0);
    m_background->PaintFrame(1, 0, 0, 0);
    int frame = static_cast<int>(static_cast<float>(static_cast<int>(unknown8)) / 5.0f + 2.0f);
    m_background->PaintFrame(frame, 0, 0, 0);
    Application::GetInstance()->GetDevice()->getVideoDriver()->endScene2D();
}
