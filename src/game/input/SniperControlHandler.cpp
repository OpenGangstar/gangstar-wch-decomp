/*
 * SniperControlHandler
 *
 * Original file: SniperControlHandler.cpp
 * Area:          input
 *
 * This file mirrors the layout of the retail build.  Add the decompiled
 * functions of SniperControlHandler.cpp here, in the order they appear in the library.
 */

// Recovered translation-unit SDK and AI startup callbacks.
#include "SniperControlHandler.h"
#include "../ui/VirtualButtonEvent.h"
#include "CControlManager.h"
#include "../characters/PlayerTest.h"
#include "../app/Application.h"
#include "../core/SceneNode.h"
#include "../core/IrrlichtDevice.h"
#include "../core/LocalStartupStorage.h"
#include "../core/LocalStartupText.h"

void operator delete(void*) throw();
extern "C" {
static void __tcf_5() __attribute__((used));
}

// Scoped imports distinguish the original TU-local transition tables.
namespace retail_snipercontrolhandler_transitions {
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
        __aeabi_atexit(0, reinterpret_cast<void (*)(void*)>(__tcf_5), &__dso_handle);
        new (irr::ps::vHalf) irr::ps::LocalVector3(0.5f, 0.5f, 0.5f);
        new (gameloft::ai::civ_passive) gameloft::ai::LocalTransitionList(retail_snipercontrolhandler_transitions::civPassive_trans, 75);
        new (gameloft::ai::npc_scripted) gameloft::ai::LocalTransitionList(retail_snipercontrolhandler_transitions::scriptedNpc_trans, 12);
        new (gameloft::ai::civ_agressive) gameloft::ai::LocalTransitionList(retail_snipercontrolhandler_transitions::civAggressive_trans, 57);
        new (gameloft::ai::gang_member) gameloft::ai::LocalTransitionList(retail_snipercontrolhandler_transitions::gangMember_trans, 3);
        new (gameloft::ai::cop) gameloft::ai::LocalTransitionList(retail_snipercontrolhandler_transitions::cop_trans, 78);
        new (gameloft::ai::swat) gameloft::ai::LocalTransitionList(retail_snipercontrolhandler_transitions::swat_trans, 3);
        new (gameloft::ai::civ_vehicle) gameloft::ai::LocalTransitionList(retail_snipercontrolhandler_transitions::civ_vehicle_trans, 36);
        new (gameloft::ai::cop_vehicle) gameloft::ai::LocalTransitionList(retail_snipercontrolhandler_transitions::cop_vehicle_trans, 45);
        new (gameloft::ai::guard) gameloft::ai::LocalTransitionList(retail_snipercontrolhandler_transitions::guard_trans, 42);
        new (gameloft::ai::scripted_vehicle) gameloft::ai::LocalTransitionList(retail_snipercontrolhandler_transitions::scripted_vehicle_trans, 21);
    }
}

extern "C" {
static void _GLOBAL__I__ZN20SniperControlHandlerC2EP15CControlManager() __attribute__((used));
static void _GLOBAL__I__ZN20SniperControlHandlerC2EP15CControlManager()
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

SniperControlHandler::~SniperControlHandler()
{
    SniperControlHandler::deactivate();
}

void SniperControlHandler::deactivate()
{
    updateOnFootEvents<&EventManager::detach>();
}

void SniperControlHandler::activate()
{
    updateOnFootEvents<&EventManager::attach>();
}

void SniperControlHandler::releaseKeyboardKeys()
{
}

void SniperControlHandler::handleStickMove(EvStickMove*) {}

void SniperControlHandler::handleStickReleased(bool) {}

inline __attribute__((always_inline)) void SniperControlHandler::resetInput()
{
    unknown12 = 0;
}

void SniperControlHandler::init()
{
    resetInput();
}

SniperControlHandler::SniperControlHandler(CControlManager* manager) : controlManager(manager)
{
    resetInput();
}

void SniperControlHandler::handleExitSightReleased()
{
    controlManager->exitSniping(true);
}

void SniperControlHandler::handleAttackReleased()
{
    resetInput();
    CControlManager* manager = controlManager;
    manager->combatTimestamp = Application::GetInstance()->GetDevice()->getTimer()->getRealTime();
}

void SniperControlHandler::handleAttackHeld()
{
    unknown12 = 2;
    CControlManager* manager = controlManager;
    manager->combatTimestamp = Application::GetInstance()->GetDevice()->getTimer()->getRealTime();
    PlayerTest::GetPlayer()->attack(false);
}

void SniperControlHandler::handleAttackPressed()
{
    unknown12 = 1;
    CControlManager* manager = controlManager;
    manager->combatTimestamp = Application::GetInstance()->GetDevice()->getTimer()->getRealTime();
    PlayerTest::GetPlayer()->attack(false);
    controlManager->enterCombat();
}

void SniperControlHandler::onEvent(const IEvent* event, const EventManager*)
{
    if (controlManager->isLocked())
        return;

    switch (event->getEventID()) {
    case 0:
        onKeyboardEvent(event);
        break;
    case 7:
        handleStickMove(reinterpret_cast<EvStickMove*>(const_cast<IEvent*>(event)));
        break;
    case 8:
        handleStickReleased(false);
        break;
    case 13: {
        const EvVirtualButton* button = static_cast<const EvVirtualButton*>(event);
        if (button->getButtonType() == 0) {
            switch (button->getAction()) {
            case EvVirtualButton::Pressed: handleAttackPressed(); break;
            case EvVirtualButton::Held: handleAttackHeld(); break;
            case EvVirtualButton::Released: handleAttackReleased(); break;
            default: break;
            }
        } else if (button->getButtonType() == 10 && button->getAction() == EvVirtualButton::Released) {
            handleExitSightReleased();
        }
        break;
    }
    }
}


#include "../characters/Character.h"
#include "../core/CameraManager.h"
#include "../core/CameraVariants.h"
#include "../core/Quaternion.h"

struct SniperKeyboardEvent {
    unsigned char unknown0[12];
    int key;
    bool pressed;
};
struct SniperCameraFields {
    unsigned char unknown0[40];
    FPSCamera* fpsCamera;
};
extern "C" void _ZN9Character4showEv(Character*);
extern "C" void _ZN9Character4hideEv(Character*);

static int fov = 50;

static inline FPSCamera* sniperCamera()
{
    return reinterpret_cast<SniperCameraFields*>(CameraManager::getInstance())->fpsCamera;
}

void SniperControlHandler::onKeyboardEvent(const IEvent* event)
{
    const SniperKeyboardEvent* keyboard = reinterpret_cast<const SniperKeyboardEvent*>(event);
    if (keyboard->pressed) {
        PlayerTest* player = PlayerTest::GetPlayer();
        switch (keyboard->key) {
        case 'Q':
        case 133:
            if (fov > 6)
                sniperCamera()->zoom(fov--);
            break;
        case 'F':
            if (unknown12 == 1)
                handleAttackHeld();
            else
                handleAttackPressed();
            break;
        case 'E':
        case 134:
            if (fov < 50)
                sniperCamera()->zoom(fov++);
            break;
        case '4':
            player->showMesh();
            _ZN9Character4showEv(&reinterpret_cast<Character&>(static_cast<SavePositionInterface&>(*player)));
            break;
        case '3':
            player->hideMesh();
            _ZN9Character4hideEv(&reinterpret_cast<Character&>(static_cast<SavePositionInterface&>(*player)));
            break;
        case '2':
            CameraManager::getInstance()->enterMode(0, reinterpret_cast<Character*>(static_cast<SavePositionInterface*>(player)), 0.3f, 0);
            break;
        case '1':
            CameraManager::getInstance()->enterMode(4, reinterpret_cast<Character*>(static_cast<SavePositionInterface*>(player)), 0.3f, 0);
            break;
        case 40:
        case 'S':
            sniperCamera()->incVerticalAngle(-1.0f);
            break;
        case 38:
        case 'W':
            sniperCamera()->incVerticalAngle(1.0f);
            break;
        case 37:
        case 'A': {
            Character& character = reinterpret_cast<Character&>(static_cast<SavePositionInterface&>(*player));
            character.SetRotation(character.GetRotation() * irr::core::quaternion(0.0f, 0.0f, -0.0174532925199433f));
            break;
        }
        case 39:
        case 'D': {
            Character& character = reinterpret_cast<Character&>(static_cast<SavePositionInterface&>(*player));
            character.SetRotation(character.GetRotation() * irr::core::quaternion(0.0f, 0.0f, 0.0174532925199433f));
            break;
        }
        }
    } else {
        switch (keyboard->key) {
        case 'F':
            handleAttackReleased();
            break;
        }
    }
}
