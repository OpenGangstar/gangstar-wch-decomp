/*
 * CDrivingControlHandler
 *
 * Original file: CDrivingControlHandler.cpp
 * Area:          input
 *
 * This file mirrors the layout of the retail build.  Add the decompiled
 * functions of CDrivingControlHandler.cpp here, in the order they appear in the library.
 */

// Recovered translation-unit SDK and AI startup callbacks.
#include "CDrivingControlHandler.h"
#include "../core/CameraManager.h"
#include "../vehicles/Vehicle.h"
#include "../characters/PlayerTest.h"
#include "../core/LocalStartupStorage.h"
#include "../core/LocalStartupText.h"
#include "../ai/StateMachine.h"
#include "../scripting/ScriptManager.h"
#include "../audio/SoundManager.h"
#include "../meta/Race.h"
#include "../ui/VirtualButtonEvent.h"
#include "../ui/GSInGameMenu.h"
#include "../hud/CHudManager.h"
#include "../app/Application.h"
#include "../core/SceneNode.h"
#include "../core/Quaternion.h"
#include "../core/CameraVariants.h"
#include "../characters/PhysicAttributes.h"
#include "../rendering/GS3DStuff.h"
#include "CControlManager.h"

void operator delete(void*) throw();
extern "C" {
static void __tcf_4() __attribute__((used));
}

// Scoped imports distinguish the original TU-local transition tables.
namespace retail_cdrivingcontrolhandler_transitions {
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
        new (gameloft::ai::civ_passive) gameloft::ai::LocalTransitionList(retail_cdrivingcontrolhandler_transitions::civPassive_trans, 75);
        new (gameloft::ai::npc_scripted) gameloft::ai::LocalTransitionList(retail_cdrivingcontrolhandler_transitions::scriptedNpc_trans, 12);
        new (gameloft::ai::civ_agressive) gameloft::ai::LocalTransitionList(retail_cdrivingcontrolhandler_transitions::civAggressive_trans, 57);
        new (gameloft::ai::gang_member) gameloft::ai::LocalTransitionList(retail_cdrivingcontrolhandler_transitions::gangMember_trans, 3);
        new (gameloft::ai::cop) gameloft::ai::LocalTransitionList(retail_cdrivingcontrolhandler_transitions::cop_trans, 78);
        new (gameloft::ai::swat) gameloft::ai::LocalTransitionList(retail_cdrivingcontrolhandler_transitions::swat_trans, 3);
        new (gameloft::ai::civ_vehicle) gameloft::ai::LocalTransitionList(retail_cdrivingcontrolhandler_transitions::civ_vehicle_trans, 36);
        new (gameloft::ai::cop_vehicle) gameloft::ai::LocalTransitionList(retail_cdrivingcontrolhandler_transitions::cop_vehicle_trans, 45);
        new (gameloft::ai::guard) gameloft::ai::LocalTransitionList(retail_cdrivingcontrolhandler_transitions::guard_trans, 42);
        new (gameloft::ai::scripted_vehicle) gameloft::ai::LocalTransitionList(retail_cdrivingcontrolhandler_transitions::scripted_vehicle_trans, 21);
    }
}

extern "C" {
static void _GLOBAL__I__ZN22CDrivingControlHandlerC2EP15CControlManager() __attribute__((used));
static void _GLOBAL__I__ZN22CDrivingControlHandlerC2EP15CControlManager()
{
    __static_initialization_and_destruction_0(1, 65535);
}
}

CDrivingControlHandler::~CDrivingControlHandler()
{
    CDrivingControlHandler::deactivate();
}

template<bool (EventManager::*operation)(int, IEventReceiver*)>
inline __attribute__((always_inline)) void CDrivingControlHandler::updateDrivingEvents()
{
    EventManager* events = Application::GetInstance()->GetEventManager();
    (events->*operation)(9, this);
    (events->*operation)(11, this);
    (events->*operation)(14, this);
    (events->*operation)(13, this);
    (events->*operation)(0, this);
    (events->*operation)(6, this);
}

void CDrivingControlHandler::activate()
{
    vehicle = static_cast<SavePrimaryInterface*>(PlayerTest::GetPlayer())->getVehicle();
    updateDrivingEvents<&EventManager::attach>();
}

void CDrivingControlHandler::deactivate()
{
    updateDrivingEvents<&EventManager::detach>();
}

void CDrivingControlHandler::releaseKeyboardKeys()
{
    if (vehicle) {
        vehicle->unknown984 = 0.0f;
        vehicle->unknown988 = 0.0f;
    }
}

void CDrivingControlHandler::init()
{
    vehicle = 0;
    unknown16 = false;
    unknown24[0] = 0.0f;
    unknown24[1] = 0.0f;
    unknown24[2] = 0.0f;
    unknown24[3] = 0.0f;
    unknown24[4] = 0.0f;
    unknown24[5] = 0.0f;
    unknown17 = true;
    unknown20 = -1;
}

CDrivingControlHandler::CDrivingControlHandler(CControlManager* manager) : controlManager(manager)
{
    vehicle = 0;
    unknown16 = false;
    unknown17 = true;
    unknown24[0] = 0.0f;
    unknown24[1] = 0.0f;
    unknown24[2] = 0.0f;
    unknown24[3] = 0.0f;
    unknown24[4] = 0.0f;
    unknown24[5] = 0.0f;
    unknown20 = -1;
}

void CDrivingControlHandler::handleAttackReleased()
{
}

void CDrivingControlHandler::handleAttackHeld()
{
    vehicle->shoot();
}

void CDrivingControlHandler::handleAttackPressed()
{
    vehicle->shoot();
}

void CDrivingControlHandler::handleWeaponSwitched()
{
    PlayerTest::GetPlayer()->switchWeapon(false);
}

void CDrivingControlHandler::disableAccelerometer()
{
    unknown16 = false;
    releaseKeyboardKeys();
    if (vehicle)
        vehicle->unknown992 = 0.0f;
    CameraManager::getInstance()->updateUpVector(0.0f);
}


extern "C" float fabsf(float);
extern "C" float sqrtf(float);
extern "C" float atan2f(float, float);

struct VehicleRepairVisualParams {
    unsigned char unknown0[12];
    float frontWeight;
    unsigned char unknown16[4];
    float backWeight;
};

struct VehicleRepairVisualState {
    unsigned char unknown0[60];
    VehicleRepairVisualParams* params;
    unsigned char unknown64[24];
    bool dirty;

    void setFrontWeight(float weight)
    {
        const float clamped = weight > 1.0f ? 1.0f : weight;
        if (clamped != params->frontWeight) {
            params->frontWeight = clamped;
            dirty = true;
        }
    }
    void setBackWeight(float weight)
    {
        const float clamped = weight > 1.0f ? 1.0f : weight;
        if (clamped != params->backWeight) {
            params->backWeight = clamped;
            dirty = true;
        }
    }
};

struct DrivingKeyboardEvent : public IEvent {
    unsigned int character;
    int key;
    bool pressed;
};

struct DrivingAccelerometerEvent : public IEvent {
    float x;
    float y;
    float z;
};

struct DrivingStickEvent : public IEvent {
    bool positive;
    float distance;
};

struct DrivingVehicleCameraView {
    unsigned char unknown0[32];
    float distance;
};

struct DrivingCameraManagerView {
    unsigned char unknown0[32];
    DrivingVehicleCameraView* vehicleCamera;
};

struct DrivingRadioToggleView {
    unsigned char unknown0[64];
    bool toggled;
};

template<> GSInGameMenu* StateMachine::pushState<GSInGameMenu>() __attribute__((weak));

void CDrivingControlHandler::onEvent(const IEvent* event, const EventManager*)
{
    Race* race = static_cast<Race*>(ScriptManager::getInstance()->getRace());
    if (controlManager->isLocked() || ScriptManager::getInstance()->isInCinematic()
        || (race && race->getState() == 1)) {
        if (event->getEventID() == 13) {
            const EvVirtualButton* button = static_cast<const EvVirtualButton*>(event);
            if (button->getButtonType() == 18 && button->getAction() == EvVirtualButton::Released) {
                SoundManager* sound = SoundManager::getInstance();
                sound->unknown140 = true;
                sound->playEx(214, 0, false, 1.0f, 0, true, 1.0f, 0);
                sound->unknown140 = false;
                ScriptManager::getInstance()->skipCutscene();
                ScriptManager::getInstance()->screenPressed = false;
            }
        }
        return;
    }

    // Case 6 precedes case 0 in source: the RTL order fixes reload's
    // round-robin spill-register choices in the accelerometer case and tail.
    switch (event->getEventID()) {
    case 6:
        if (unknown16) {
            event->getEventID();
            const DrivingAccelerometerEvent* accel = static_cast<const DrivingAccelerometerEvent*>(event);
            const float x = accel->x;
            const float y = accel->y;
            const float z = accel->z;
            float steer = (fabsf(x) - 0.05f) * (1.0f / 0.95f) * 3.0f;
            if (steer > 1.0f)
                steer = 1.0f;
            if (GS3DStuff::s_orientation == 1)
                steer = -steer;
            if (x > 0.05f)
                vehicle->unknown992 = steer;
            else if (x < -0.05f)
                vehicle->unknown992 = -steer;
            else
                vehicle->unknown992 = 0.0f;
            const irr::core::vector3d<float> current(x * 0.3f, y * 0.3f, z * 0.3f);
            const irr::core::vector3d<float> previous(0.7f * unknown24[0], 0.7f * unknown24[1], 0.7f * unknown24[2]);
            const float gravityZ = current.Z + previous.Z;
            unknown24[0] = current.X + previous.X;
            unknown24[1] = current.Y + previous.Y;
            unknown24[2] = gravityZ;
            const irr::core::vector3d<float> gravity(unknown24[0], unknown24[1], gravityZ);
            const irr::core::vector3d<float> delta = irr::core::vector3d<float>(x, y, z) - gravity;
            unknown24[3] = delta.X;
            unknown24[4] = delta.Y;
            unknown24[5] = delta.Z;
            float angle = atan2f(gravity.X, sqrtf(gravity.Y * gravity.Y + gravity.Z * gravity.Z));
            if (GS3DStuff::s_orientation == 1)
                angle = -angle;
            const float tilt = angle * 0.5f;
            CameraManager::getInstance()->updateUpVector(-tilt);
        }
        break;
    case 0: {
        static float backWeight;
        static float frontWeight;
        const DrivingKeyboardEvent* keyboard = static_cast<const DrivingKeyboardEvent*>(event);
        if (!keyboard->pressed) {
            switch (keyboard->key) {
            case 37:
            case 'A':
                vehicle->unknown992 = 0.0f;
                vehicle->unknown988 = -0.5f;
                break;
            case 38:
            case 'W':
                vehicle->unknown988 = 0.0f;
                break;
            case 39:
            case 'D':
                vehicle->unknown992 = 0.0f;
                vehicle->unknown988 = 0.5f;
                break;
            case 40:
            case 'S':
                vehicle->unknown984 = -1.0f;
                break;
            case '1':
                vehicle->repair();
                break;
            case '2':
                frontWeight += 0.05;
                if (frontWeight > 1.0f)
                    frontWeight = 1.0f;
                vehicle->repairVisualState->setFrontWeight(frontWeight);
                break;
            case '3':
                backWeight -= 0.05;
                if (backWeight < 0.0f)
                    backWeight = 0.0f;
                vehicle->repairVisualState->setBackWeight(backWeight);
                break;
            case '4':
                backWeight += 0.05;
                if (backWeight > 1.0f)
                    backWeight = 1.0f;
                vehicle->repairVisualState->setBackWeight(backWeight);
                break;
            case 'E':
                static_cast<SavePrimaryInterface*>(PlayerTest::GetPlayer())->getVehicle()->health = 0;
                break;
            case 'I': {
                vehicle->getMesh()->setVisible(!vehicle->getMesh()->isVisible());
                Vehicle* const visibilityVehicle = vehicle;
                if (visibilityVehicle->getMesh()->isVisible())
                    visibilityVehicle->unknown4 |= 2;
                else {
                    // Branch-likelihood hint only: Thumb has no prefetch pattern, so this
                    // emits no code; PRED_CALL lowers this arm's frequency so bb-reorder
                    // places it after the radio-off arm, as in retail.
                    __builtin_prefetch(visibilityVehicle);
                    visibilityVehicle->unknown4 &= ~2;
                }
                PlayerTest::GetPlayer()->sceneNode->setVisible(true);
                break;
            }
            case 131:
                if (--unknown20 < 0)
                    unknown20 = 4;
                switch (unknown20) {
                case 0:
                    reinterpret_cast<DrivingCameraManagerView*>(CameraManager::getInstance())->vehicleCamera->distance = vehicle->cameraMinDistance;
                    break;
                case 1:
                    reinterpret_cast<DrivingCameraManagerView*>(CameraManager::getInstance())->vehicleCamera->distance = vehicle->cameraSideDistance;
                    break;
                }
                break;
            case 132:
                if (++unknown20 > 4)
                    unknown20 = 0;
                switch (unknown20) {
                case 0:
                    reinterpret_cast<DrivingCameraManagerView*>(CameraManager::getInstance())->vehicleCamera->distance = vehicle->cameraMinDistance;
                    break;
                case 1:
                    reinterpret_cast<DrivingCameraManagerView*>(CameraManager::getInstance())->vehicleCamera->distance = vehicle->cameraSideDistance;
                    break;
                }
                break;
            case 134:
                switch (unknown20) {
                case 0: {
                    const int distance = ++vehicle->cameraMinDistance;
                    reinterpret_cast<DrivingCameraManagerView*>(CameraManager::getInstance())->vehicleCamera->distance = distance;
                    break;
                }
                case 1: {
                    const int distance = ++vehicle->cameraSideDistance;
                    reinterpret_cast<DrivingCameraManagerView*>(CameraManager::getInstance())->vehicleCamera->distance = distance;
                    break;
                }
                case 2:
                    ++vehicle->cameraPositionHeight;
                    break;
                case 3:
                    ++vehicle->cameraLookHeight;
                    break;
                case 4:
                    ++vehicle->cameraLookAhead;
                    break;
                }
                break;
            case 133:
                switch (unknown20) {
                case 0: {
                    const int distance = --vehicle->cameraMinDistance;
                    reinterpret_cast<DrivingCameraManagerView*>(CameraManager::getInstance())->vehicleCamera->distance = distance;
                    break;
                }
                case 1: {
                    const int distance = --vehicle->cameraSideDistance;
                    reinterpret_cast<DrivingCameraManagerView*>(CameraManager::getInstance())->vehicleCamera->distance = distance;
                    break;
                }
                case 2:
                    --vehicle->cameraPositionHeight;
                    break;
                case 3:
                    --vehicle->cameraLookHeight;
                    break;
                case 4:
                    --vehicle->cameraLookAhead;
                    break;
                }
                break;
            }
        } else {
            switch (keyboard->key) {
            case 37:
            case 'A':
            case 39:
            case 'D':
                vehicle->unknown988 = 0.0f;
                break;
            case 38:
            case 'W':
            case 40:
            case 'S':
                vehicle->unknown984 = 0.0f;
                break;
            }
        }
        break;
    }
    case 9: {
        const DrivingStickEvent* stick = static_cast<const DrivingStickEvent*>(event);
        vehicle->turn(stick->positive, stick->distance);
        break;
    }
    case 14: {
        const DrivingStickEvent* stick = static_cast<const DrivingStickEvent*>(event);
        vehicle->turn(stick->positive, stick->distance);
        break;
    }
    case 11: {
        const DrivingStickEvent* stick = static_cast<const DrivingStickEvent*>(event);
        if (stick->positive)
            vehicle->accelerate(stick->distance);
        else
            vehicle->brake(stick->distance);
        break;
    }
    case 13: {
        const EvVirtualButton* button = static_cast<const EvVirtualButton*>(event);
        switch (button->getButtonType()) {
        case 0:
            switch (button->getAction()) {
            case EvVirtualButton::Pressed:
                handleAttackPressed();
                break;
            case EvVirtualButton::Held:
                handleAttackHeld();
                break;
            case EvVirtualButton::Released:
                handleAttackReleased();
                break;
            default:
                break;
            }
            break;
        case 2:
            if (button->getAction() == EvVirtualButton::Released) {
                Vehicle* car = vehicle;
                if (!car->unknown510) {
                    irr::core::vector3d<float> left = car->leftDoor->getAbsolutePosition();
                    if (car->canGoToPoint(left)) {
                        CameraManager::getInstance()->updateUpVector(0.0f);
                        PlayerTest::GetPlayer()->stopDriving(static_cast<playertest::PlayerCarState::ePlayerCarState>(6), true);
                    } else {
                        Vehicle* other = vehicle;
                        irr::core::vector3d<float> right = other->rightDoor->getAbsolutePosition();
                        if (other->canGoToPoint(right)) {
                            CameraManager::getInstance()->updateUpVector(0.0f);
                            PlayerTest::GetPlayer()->stopDriving(static_cast<playertest::PlayerCarState::ePlayerCarState>(6), false);
                        } else {
                            PlayerTest* player = PlayerTest::GetPlayer();
                            player->stopDriving(playertest::PlayerCarState::MovingOut, true);
                            const unsigned short material = PhysicAttributes::MATERIAL_TYPE_SIDEWALK;
                            unsigned short surface;
                            irr::core::vector3d<float> destination = PhysicAttributes::GetRandomDestination(
                                material, surface, vehicle->GetPosition(), 0.0f, 0.0f);
                            player->SetPosition(destination);
                            irr::core::quaternion rotation;
                            const irr::core::vector3d<float>& up = irr::core::vector3d<float>(0, 0, 1);
                            const irr::core::matrix4& matrix = player->sceneNode->getAbsoluteTransformation();
                            rotation.rotationFromTo(up, irr::core::vector3d<float>(matrix[8], matrix[9], matrix[10]));
                            player->SetRotation(rotation * player->GetRotation());
                            player->physicAttributes->Init(material, surface, player->GetPosition());
                            destination.Z = player->physicAttributes->GetHeight(destination, 0, false);
                            player->SetPosition(destination);
                            player->_SetTarget(0, true);
                            player->goToIdle();
                        }
                    }
                }
            }
            break;
        case 4:
            vehicle->accelerate(1.0f);
            break;
        case 5:
            vehicle->brake(1.0f);
            break;
        case 6:
            if (button->getAction() == EvVirtualButton::Released)
                handleWeaponSwitched();
            break;
        case 7:
            if (button->getAction() == EvVirtualButton::Released) {
                SoundManager::getInstance()->pauseAllSounds();
                StateMachine::getInstance()->pushState<GSInGameMenu>();
            }
            break;
        case 8:
            if (button->getAction() == EvVirtualButton::Released) {
                if (reinterpret_cast<DrivingRadioToggleView*>(Application::GetInstance()->GetHudManager()->radioToggle)->toggled) {
                    SoundManager::getInstance()->playRadio(-1);
                    static_cast<SavePrimaryInterface*>(PlayerTest::GetPlayer())->getVehicle()->flags344 |= 0x800000;
                } else {
                    SoundManager::getInstance()->stopRadio();
                    static_cast<SavePrimaryInterface*>(PlayerTest::GetPlayer())->getVehicle()->flags344 &= ~0x800000;
                }
            }
            break;
        case 9:
            if (button->getAction() == EvVirtualButton::Pressed)
                SoundManager::getInstance()->nextRadioStation();
            break;
        }
        break;
    }
    }
}
