/*
 * CControlManager
 *
 * Original file: CControlManager.cpp
 * Area:          input
 *
 * This file mirrors the layout of the retail build.  Add the decompiled
 * functions of CControlManager.cpp here, in the order they appear in the library.
 */

// Recovered translation-unit SDK and AI startup callbacks.
#include "CControlManager.h"
#include "COnFootControlHandler.h"
#include "CDrivingControlHandler.h"
#include "SniperControlHandler.h"
#include "../characters/PlayerTest.h"
#include "../core/SceneNode.h"
#include "../core/IrrlichtDevice.h"
#include "../characters/Character.h"
#include "../core/CameraManager.h"
#include "../hud/CHudManager.h"
#include "../hud/MiniMap.h"
#include "../hud/MenuManager.h"
#include "../scripting/ScriptManager.h"
#include "../combat/WeaponManager.h"
#include "../combat/Weapon.h"
#include "../vehicles/Vehicle.h"
#include "../audio/Radio.h"
#include "../ui/ToggleButton.h"
#include "../core/LocalStartupStorage.h"
#include "../core/LocalStartupText.h"
#include "../ui/VirtualButtonEvent.h"

void operator delete(void*) throw();
extern "C" {
static void __tcf_3() __attribute__((used));
}

// Scoped imports distinguish the original TU-local transition tables.
namespace retail_ccontrolmanager_transitions {
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
bool _ZN9Character6isDownEv(void*) __attribute__((weak));
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
        new (gameloft::ai::civ_passive) gameloft::ai::LocalTransitionList(retail_ccontrolmanager_transitions::civPassive_trans, 75);
        new (gameloft::ai::npc_scripted) gameloft::ai::LocalTransitionList(retail_ccontrolmanager_transitions::scriptedNpc_trans, 12);
        new (gameloft::ai::civ_agressive) gameloft::ai::LocalTransitionList(retail_ccontrolmanager_transitions::civAggressive_trans, 57);
        new (gameloft::ai::gang_member) gameloft::ai::LocalTransitionList(retail_ccontrolmanager_transitions::gangMember_trans, 3);
        new (gameloft::ai::cop) gameloft::ai::LocalTransitionList(retail_ccontrolmanager_transitions::cop_trans, 78);
        new (gameloft::ai::swat) gameloft::ai::LocalTransitionList(retail_ccontrolmanager_transitions::swat_trans, 3);
        new (gameloft::ai::civ_vehicle) gameloft::ai::LocalTransitionList(retail_ccontrolmanager_transitions::civ_vehicle_trans, 36);
        new (gameloft::ai::cop_vehicle) gameloft::ai::LocalTransitionList(retail_ccontrolmanager_transitions::cop_vehicle_trans, 45);
        new (gameloft::ai::guard) gameloft::ai::LocalTransitionList(retail_ccontrolmanager_transitions::guard_trans, 42);
        new (gameloft::ai::scripted_vehicle) gameloft::ai::LocalTransitionList(retail_ccontrolmanager_transitions::scripted_vehicle_trans, 21);
    }
}

extern "C" {
static void _GLOBAL__I__ZN15CControlManager16s_sniperTutorialE() __attribute__((used));
static void _GLOBAL__I__ZN15CControlManager16s_sniperTutorialE()
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

CControlManager::~CControlManager()
{
    delete onFootHandler;
    onFootHandler = 0;
    delete drivingHandler;
    drivingHandler = 0;
    delete sniperHandler;
    sniperHandler = 0;
}

void CControlManager::update()
{
    if (ScriptManager::getInstance()->isInCinematic())
        return;
    PlayerTest* player = PlayerTest::GetPlayer();
    if (activeHandler == sniperHandler) {
        Character* character = reinterpret_cast<Character*>(&static_cast<SavePositionInterface&>(*player));
        if (static_cast<int>(player->flags240 << 17) < 0 || (player->flags240 & 0x2000)
            || character->getHealth() <= 0 || _ZN9Character6isDownEv(character))
            exitSniping(!ScriptManager::getInstance()->isInCinematic());
    }
    unsigned int now = Application::GetInstance()->GetDevice()->getTimer()->getRealTime();
    if (activeHandler != onFootHandler)
        return;
    if (!player->targetLocked && player->combatMode && now >= combatTimestamp + 5000) {
        exitCombat();
        reinterpret_cast<Character*>(&static_cast<SavePositionInterface&>(*player))->goFromCombatToIdle();
    }
    int weapon = player->getWeapon()->getWeaponType();
    if (weapon == 0) {
        unknown45 = now <= unknown28[2] + 500;
        if (static_cast<int>(player->flags240 << 3) < 0)
            return;
        if (!unknown28[3]) {
            // One-byte store of true. Written as a memset so the unfolded
            // builtin call reaches branch prediction (call heuristic) like
            // retail; it still expands to a single strb.
            __builtin_memset(&static_cast<COnFootControlHandler*>(activeHandler)->unknown12, true, 1);
            return;
        }
        if (unknown44) {
            Application::GetInstance()->GetEventManager()->raise(EvVirtualButton(EvVirtualButton::Released, static_cast<EvVButton::ButtonType::Type>(0)));
            return;
        }
        unknown44 = true;
        Application::GetInstance()->GetEventManager()->raise(EvVirtualButton(EvVirtualButton::Pressed, static_cast<EvVButton::ButtonType::Type>(0)));
    } else if (unknown28[0]) {
        if (now >= unknown28[0] + 250 || unknown46) {
            static_cast<COnFootControlHandler*>(activeHandler)->unknown12 = true;
            unknown28[0] = 0;
        }
    }
}

void CControlManager::setCameraProxy(GS3DStuff* proxy)
{
    cameraProxy = proxy;
}

void CControlManager::lock()
{
    if (activeHandler == onFootHandler)
        onFootHandler->releaseKeyboardKeys();
    if (activeHandler == drivingHandler)
        drivingHandler->releaseKeyboardKeys();
    locked = true;
}

bool CControlManager::isLocked() const
{
    return locked;
}

void CControlManager::unlock()
{
    if (activeHandler == onFootHandler)
        static_cast<COnFootControlHandler*>(activeHandler)->unknown12 = true;
    locked = false;
}

void CControlManager::exitCombat()
{
    PlayerTest::GetPlayer()->combatMode = false;
}

void CControlManager::init()
{
    static_cast<COnFootControlHandler*>(onFootHandler)->init();
    static_cast<CDrivingControlHandler*>(drivingHandler)->init();
    static_cast<SniperControlHandler*>(sniperHandler)->init();
    drivingHandler->deactivate();
    sniperHandler->deactivate();
    activeHandler = onFootHandler;
    activeHandler->activate();
}

CControlManager::CControlManager()
{
    unknown44 = false;
    unknown45 = false;
    activeHandler = 0;
    onFootHandler = 0;
    drivingHandler = 0;
    sniperHandler = 0;
    locked = false;
    combatTimestamp = 0;
    unknown28[0] = 0;
    unknown28[1] = 0;
    unknown28[2] = 0;
    unknown28[3] = 0;
    unknown46 = false;
    onFootHandler = new COnFootControlHandler(this);
    drivingHandler = new CDrivingControlHandler(this);
    sniperHandler = new SniperControlHandler(this);
    init();
}

void CControlManager::enterCombat()
{
    unsigned int now = Application::GetInstance()->GetDevice()->getTimer()->getRealTime();
    if (now >= combatTimestamp + 5000)
        combatTimestamp = now;
    PlayerTest::GetPlayer()->combatMode = true;
}

namespace {
inline __attribute__((always_inline)) void restoreWalkingCamera(CameraManager* camera, LevelObject* target)
{
    camera->enterMode(0, target, 0.3f, 0);
}
}

void CControlManager::exitSniping(bool restoreCamera)
{
    if (activeHandler == sniperHandler) {
        lock();
        Application::GetInstance()->GetHudManager()->walking();
        PlayerTest* player = PlayerTest::GetPlayer();
        Character* character = reinterpret_cast<Character*>(&static_cast<SavePositionInterface&>(*player));
        character->goFromCombatToIdle();
        if (restoreCamera) {
            CameraManager* camera = CameraManager::getInstance();
            restoreWalkingCamera(camera, player ? character : 0);
        }
        activeHandler->deactivate();
        activeHandler = onFootHandler;
        activeHandler->activate();
        unlock();
    }
}

void CControlManager::exitCar(bool restoreCamera)
{
    Application* application = Application::GetInstance();
    application->GetHudManager()->walking();
    activeHandler->deactivate();
    PlayerTest* player = PlayerTest::GetPlayer();
    CHudManager* hud = application->GetHudManager();
    LevelObject* target = reinterpret_cast<LevelObject*>(static_cast<SavePositionInterface*>(player));
    MiniMap* minimap = static_cast<MiniMap*>(hud->minimap);
    if (minimap)
        minimap->setFollowedObject(target);
    if (restoreCamera) {
        CameraManager* camera = CameraManager::getInstance();
        restoreWalkingCamera(camera, reinterpret_cast<LevelObject*>(static_cast<SavePositionInterface*>(player)));
    }
    activeHandler = onFootHandler;
    activeHandler->activate();
}

void CControlManager::enterCar(bool changeCamera)
{
    Application* application = Application::GetInstance();
    activeHandler->deactivate();
    PlayerTest* player = PlayerTest::GetPlayer();
    player->startDriving();
    CHudManager* hud = application->GetHudManager();
    if (static_cast<SavePrimaryInterface*>(player)->getVehicle()->flags344 & 0x800000) {
        hud->radioToggle->toggled = true;
        hud->radio->radioFlags &= ~1u;
    } else {
        hud->radioToggle->toggled = false;
        hud->radio->radioFlags |= 1u;
    }
    application->GetHudManager()->driving();
    hud = application->GetHudManager();
    Vehicle* vehicle = static_cast<SavePrimaryInterface*>(player)->getVehicle();
    MiniMap* minimap = static_cast<MiniMap*>(hud->minimap);
    if (minimap)
        minimap->setFollowedObject(vehicle);
    if (changeCamera) {
        CameraManager* camera = CameraManager::getInstance();
        camera->enterMode(2, static_cast<SavePrimaryInterface*>(player)->getVehicle(), 0.1f, 0);
    }
    activeHandler = drivingHandler;
    activeHandler->activate();
}

namespace {
const char tutorialMenu[] __attribute__((section(".rodata.control_manager_tutorial"))) = "Tutorial";
}

void CControlManager::enterSniping(bool changeCamera)
{
    Application::GetInstance()->GetHudManager()->sniping();
    PlayerTest* player = PlayerTest::GetPlayer();
    Character* character = reinterpret_cast<Character*>(&static_cast<SavePositionInterface&>(*player));
    character->goToCombatIdle();
    if (changeCamera) {
        CameraManager* camera = CameraManager::getInstance();
        camera->enterMode(4, player ? character : 0, 0.3f, 0);
    }
    activeHandler->deactivate();
    activeHandler = sniperHandler;
    activeHandler->activate();
    if (!ScriptManager::getInstance()->unknown78)
        return;

    bool* shown;
    int tutorialId;
    const int weapon = Application::GetInstance()->GetWeaponManager()->getCurrentWeapon()->getWeaponType();
    if (weapon == 8) {
        shown = &s_sniperTutorial;
        tutorialId = 12422;
    } else if (weapon == 9) {
        shown = &s_cameraTutorial;
        tutorialId = 12424;
    } else {
        return;
    }
    if (!*shown) {
        *shown = true;
        MenuManager::getInstance()->setTutorialIds(tutorialId, 12423);
        if (MenuManager::getInstance()->getDepth() > 0)
            MenuManager::getInstance()->popAll(false);
        MenuManager::getInstance()->push(tutorialMenu, true);
    }
}
