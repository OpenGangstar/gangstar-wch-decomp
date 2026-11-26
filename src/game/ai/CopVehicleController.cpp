/*
 * CopVehicleController
 *
 * Original file: CopVehicleController.cpp
 * Area:          ai
 *
 * This file mirrors the layout of the retail build.  Add the decompiled
 * functions of CopVehicleController.cpp here, in the order they appear in the library.
 */

#include "VehicleController.h"
#include "../app/Application.h"
#include "../core/EventManager.h"

class LevelObject;
class CopVehicleController : public VehicleController {
public:
    CopVehicleController(Vehicle* vehicle, const gameloft::ai::Transition& transition,
        gameloft::ai::StateID state);
    virtual ~CopVehicleController();
    virtual void onEvent(const IEvent*, const EventManager*);
    virtual void switchState(gameloft::ai::StateID);
    static void pursue(Vehicle* value, LevelObject* target);

private:
    int unknown28;
};

CopVehicleController::CopVehicleController(Vehicle* vehicle,
    const gameloft::ai::Transition& transition, gameloft::ai::StateID state)
    : VehicleController(vehicle, transition, state), unknown28(0)
{
    EventManager* events = Application::GetInstance()->GetEventManager();
    events->attach(16, this);
    events->attach(23, this);
    events->attach(24, this);
    events->attach(22, this);
}

CopVehicleController::~CopVehicleController()
{
    EventManager* events = Application::GetInstance()->GetEventManager();
    events->detach(16, this);
    events->detach(23, this);
    events->detach(24, this);
    events->detach(22, this);
}

// Recovered translation-unit SDK and AI startup callbacks.
#include "../core/LocalStartupStorage.h"
#include "../missions/WantedLevelManagerSingleton.h"
#include "../core/LocalStartupText.h"

void operator delete(void*) throw();
extern "C" {
static void __tcf_5() __attribute__((used));
}

// Scoped imports distinguish the original TU-local transition tables.
namespace retail_copvehiclecontroller_transitions {
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
        new (gameloft::ai::civ_passive) gameloft::ai::LocalTransitionList(retail_copvehiclecontroller_transitions::civPassive_trans, 75);
        new (gameloft::ai::npc_scripted) gameloft::ai::LocalTransitionList(retail_copvehiclecontroller_transitions::scriptedNpc_trans, 12);
        new (gameloft::ai::civ_agressive) gameloft::ai::LocalTransitionList(retail_copvehiclecontroller_transitions::civAggressive_trans, 57);
        new (gameloft::ai::gang_member) gameloft::ai::LocalTransitionList(retail_copvehiclecontroller_transitions::gangMember_trans, 3);
        new (gameloft::ai::cop) gameloft::ai::LocalTransitionList(retail_copvehiclecontroller_transitions::cop_trans, 78);
        new (gameloft::ai::swat) gameloft::ai::LocalTransitionList(retail_copvehiclecontroller_transitions::swat_trans, 3);
        new (gameloft::ai::civ_vehicle) gameloft::ai::LocalTransitionList(retail_copvehiclecontroller_transitions::civ_vehicle_trans, 36);
        new (gameloft::ai::cop_vehicle) gameloft::ai::LocalTransitionList(retail_copvehiclecontroller_transitions::cop_vehicle_trans, 45);
        new (gameloft::ai::guard) gameloft::ai::LocalTransitionList(retail_copvehiclecontroller_transitions::guard_trans, 42);
        new (gameloft::ai::scripted_vehicle) gameloft::ai::LocalTransitionList(retail_copvehiclecontroller_transitions::scripted_vehicle_trans, 21);
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
static void _GLOBAL__I__ZN20CopVehicleControllerC2EP7VehicleRKN8gameloft2ai10TransitionENS3_7StateIDE() __attribute__((used));
static void _GLOBAL__I__ZN20CopVehicleControllerC2EP7VehicleRKN8gameloft2ai10TransitionENS3_7StateIDE()
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

#include "../vehicles/Vehicle.h"
#include "../characters/PlayerTest.h"
void CopVehicleController::switchState(gameloft::ai::StateID next)
{
    VehicleController::switchState(next);
    switch (next) {
    case 2:
        vehicle->wait(5);
        break;
    case 4:
        vehicle->freeze();
        break;
    case 8: {
        vehicle->flags344 &= ~0x100u;
        vehicle->flags344 &= ~0x80u;
        Vehicle* value = vehicle;
        if (value->aiTarget) {
            value->unknown776 = value->unknown188;
            value->flags344 |= 0x1000u;
        }
        break;
    }
    case 10:
        vehicle->driveToLocation(static_cast<SavePositionInterface&>(*PlayerTest::GetPlayer()).GetPosition(), true);
        break;
    }
}

#include "../characters/Character.h"
#include "../ai/NPC.h"
#include "../characters/PlayerEvent.h"
#include "../characters/NPCVehicleEvent.h"
#include "../vehicles/VehicleEvents.h" // overlay
#include "../world/GameObjectManager.h"
extern "C" long lrand48();
namespace {
struct CopDriverView {
    void* vtable;
    unsigned int flags;
};
}
extern "C" void _ZN20EvVehicleDeactivatedD1Ev(void*) __attribute__((weak));
extern "C" void* const _ZTV6IEvent[];
extern "C" void* const _ZTV20EvVehicleDeactivated[];
namespace {
// File-local view of the inlined IEvent(21) -> EvVehicleDeactivated construction.
struct CopEventView {
    void* const* vtable;
    int eventID;
    CopEventView(int id) : vtable(&_ZTV6IEvent[2]), eventID(id) {}
};
struct CopDeactivatedView : CopEventView {
    Vehicle* vehicle;
    CopDeactivatedView(Vehicle* value) : CopEventView(21), vehicle(value) { vtable = &_ZTV20EvVehicleDeactivated[2]; }
};
}
extern "C" void _ZN7Vehicle9stopSirenEv(Vehicle*) __attribute__((weak));
inline void CopVehicleController::pursue(Vehicle* value, LevelObject* target)
{
    value->aiTarget = target;
    value->flags344 |= 0x2000u;
    unsigned int mask;
    if (!(lrand48() & 1))
        mask = 0x100000u;
    else
        mask = 0x200000u;
    value->flags344 |= mask;
}
static inline void raiseWantedLevel(WantedLevelManager* manager, const int level)
{
    if (manager->unknown8 < level) {
        manager->unknown8 = level;
        manager->_processWantedLevel();
    }
}
void CopVehicleController::onEvent(const IEvent* event, const EventManager* manager)
{
    VehicleController::onEvent(event, manager);
    WantedLevelManager* (*getWanted)() = WantedLevelManager::getInstance;
    int wanted = getWanted()->unknown8;
    switch (event->getEventID()) {
    case 23:
        if (wanted > 0) {
            if (wanted > 2)
                unknown28 = 3;
            else
                unknown28 = wanted;
        } else
            unknown28 = 0;
        if (wanted > 0) {
            PlayerTest* player = PlayerTest::GetPlayer();
            if ((player->flags240 & 0x400u) && static_cast<SavePositionInterface*>(player)->getVehicle()) {
                Vehicle* value = vehicle;
                pursue(value, static_cast<SavePrimaryInterface*>(PlayerTest::GetPlayer())->getVehicle());
            } else {
                Vehicle* value = vehicle;
                pursue(value, reinterpret_cast<LevelObject*>(static_cast<SavePositionInterface*>(PlayerTest::GetPlayer())));
            }
            break;
        }
    case 24:
        unknown28 = 0;
        vehicle->clearOnAlert();
        switchState(static_cast<gameloft::ai::StateID>(1));
        break;
    case 19: {
        const EvNPCVehicle* change = static_cast<const EvNPCVehicle*>(event);
        Vehicle* affected = const_cast<Vehicle*>(change->getVehicle());
        Vehicle* mine = vehicle;
        if (affected != mine)
            break;
        switch (change->getType()) {
        case 5:
            if (state == 1) {
                _ZN7Vehicle9stopSirenEv(affected);
                affected->unknown776 = *reinterpret_cast<const float*>(affected->unknown780);
                affected->flags344 &= ~0x5000u;
            }
            break;
        case 23: {
            PlayerTest* player = PlayerTest::GetPlayer();
            LevelObject* last = player->unknown312 ? player->unknown312 : player->unknown368;
            if (last == affected && PlayerTest::GetPlayer()->unknown372)
                break;
            Character* driver = vehicle->driver;
            if (*reinterpret_cast<const unsigned int*>(&vehicle->driver) && !(reinterpret_cast<const CopDriverView*>(driver)->flags & 0x80u)) {
                driver->disable();
                vehicle->setDriver(0);
            }
            GameObjectManager::s_gom->spawnNPCInVehicle(vehicle, 48, -1)->getOutOfVehicle(true, false);
            vehicle->clearOnAlert();
            vehicle->flags344 = 0;
            EventManager* events = Application::GetInstance()->GetEventManager();
            CopDeactivatedView notice(vehicle);
            events->raise(*reinterpret_cast<const IEvent*>(&notice));
            _ZN20EvVehicleDeactivatedD1Ev(&notice);
            break;
        }
        }
        break;
    }
    case 22:
        switch (static_cast<const EvPlayer*>(event)->getState()) {
        case 2:
            if ((static_cast<SavePositionInterface&>(*PlayerTest::GetPlayer()).GetPosition() - vehicle->GetPosition()).getLengthSQ() <= 9000000.0f) {
                raiseWantedLevel(getWanted(), 1);
                Vehicle* value = vehicle;
                if (value->aiTarget) {
                    value->unknown776 = value->unknown188;
                    value->flags344 |= 0x1000u;
                }
            }
            break;
        case 9:
            if (wanted > 0)
                vehicle->aiTarget = static_cast<SavePrimaryInterface*>(PlayerTest::GetPlayer())->getVehicle();
            break;
        case 10:
            if (wanted > 0)
                vehicle->aiTarget = reinterpret_cast<LevelObject*>(static_cast<SavePositionInterface*>(PlayerTest::GetPlayer()));
            break;
        case 11:
            unknown28 = 0;
            vehicle->clearOnAlert();
            switchState(static_cast<gameloft::ai::StateID>(1));
            break;
        }
        break;
    }
}
