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
#include "IControlHandler.h"
#include "../vehicles/Vehicle.h"
#include "../characters/PlayerTest.h"
#include "../core/LocalStartupStorage.h"
#include "../core/LocalStartupText.h"
#include "../ai/StateMachine.h"

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

// Recovered virtual interface. The member layout is still incomplete.
class CControlManager;

class CDrivingControlHandler : public IControlHandler {
public:
    virtual ~CDrivingControlHandler();
    virtual void onEvent(const IEvent*, const EventManager*);
    virtual void activate();
    virtual void deactivate() __attribute__((noinline));
    virtual void releaseKeyboardKeys();

private:
    template<bool (EventManager::*operation)(int, IEventReceiver*)>
    inline __attribute__((always_inline)) void updateDrivingEvents();
    CControlManager* controlManager;
    Vehicle* vehicle;
};

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
