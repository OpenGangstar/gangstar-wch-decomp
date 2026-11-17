/*
 * MissionConditionDriveWell
 *
 * Original file: MissionConditionDriveWell.cpp
 * Area:          missions
 *
 * This file mirrors the layout of the retail build.  Add the decompiled
 * functions of MissionConditionDriveWell.cpp here, in the order they appear in the library.
 */

// Recovered translation-unit SDK and AI startup callbacks.
#include "../core/NativeStdio.h"
#include "../hud/SpyGauge.h"
#include "../app/Application.h"
#include "../hud/CHudManager.h"
#include "../vehicles/Vehicle.h"
#include "IMissionCondition.h"
#include "../core/LocalStartupStorage.h"
#include "WantedLevelManagerSingleton.h"
#include "../core/LocalStartupText.h"

void operator delete(void*) throw();
extern "C" {
static void __tcf_4() __attribute__((used));
}

// Scoped imports distinguish the original TU-local transition tables.
namespace retail_missionconditiondrivewell_transitions {
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
        new (gameloft::ai::civ_passive) gameloft::ai::LocalTransitionList(retail_missionconditiondrivewell_transitions::civPassive_trans, 75);
        new (gameloft::ai::npc_scripted) gameloft::ai::LocalTransitionList(retail_missionconditiondrivewell_transitions::scriptedNpc_trans, 12);
        new (gameloft::ai::civ_agressive) gameloft::ai::LocalTransitionList(retail_missionconditiondrivewell_transitions::civAggressive_trans, 57);
        new (gameloft::ai::gang_member) gameloft::ai::LocalTransitionList(retail_missionconditiondrivewell_transitions::gangMember_trans, 3);
        new (gameloft::ai::cop) gameloft::ai::LocalTransitionList(retail_missionconditiondrivewell_transitions::cop_trans, 78);
        new (gameloft::ai::swat) gameloft::ai::LocalTransitionList(retail_missionconditiondrivewell_transitions::swat_trans, 3);
        new (gameloft::ai::civ_vehicle) gameloft::ai::LocalTransitionList(retail_missionconditiondrivewell_transitions::civ_vehicle_trans, 36);
        new (gameloft::ai::cop_vehicle) gameloft::ai::LocalTransitionList(retail_missionconditiondrivewell_transitions::cop_vehicle_trans, 45);
        new (gameloft::ai::guard) gameloft::ai::LocalTransitionList(retail_missionconditiondrivewell_transitions::guard_trans, 42);
        new (gameloft::ai::scripted_vehicle) gameloft::ai::LocalTransitionList(retail_missionconditiondrivewell_transitions::scripted_vehicle_trans, 21);
    }
}

extern "C" {
static void _GLOBAL__I__ZN25MissionConditionDriveWellC2EP7Vehicle() __attribute__((used));
static void _GLOBAL__I__ZN25MissionConditionDriveWellC2EP7Vehicle()
{
    __static_initialization_and_destruction_0(1, 65535);
}
}

class Vehicle;

class MissionConditionDriveWell : public IMissionCondition {
public:
    explicit MissionConditionDriveWell(Vehicle* vehicle);
    virtual ~MissionConditionDriveWell();
    virtual bool evaluate(int elapsed);
    virtual void draw();

private:
    Vehicle* vehicle;
    int vehicleHealth;
    int wantedLevel;
    float remainingScore;
    float speedPenalty;
    float jumpPenalty;
    float driftPenalty;
    float wantedOvertimePenalty;
};

void MissionConditionDriveWell::draw()
{
}

MissionConditionDriveWell::MissionConditionDriveWell(Vehicle* vehicle)
    : vehicle(vehicle)
{
    vehicleHealth = vehicle->getHealth();
    wantedLevel = WantedLevelManager::getInstance()->unknown8;
    remainingScore = 1000.0f;
    speedPenalty = 0.0f;
    jumpPenalty = 0.0f;
    driftPenalty = 0.0f;
    wantedOvertimePenalty = 0.0f;
    Application::GetInstance()->GetHudManager()->showSpyGauge(true);
    Application::GetInstance()->GetHudManager()->useDriveWellBGInSpyGauge();
}

MissionConditionDriveWell::~MissionConditionDriveWell()
{
    Application::GetInstance()->GetHudManager()->showSpyGauge(false);
    Application::GetInstance()->GetHudManager()->useSpyBGInSpyGauge();
}

bool MissionConditionDriveWell::evaluate(int elapsed)
{
    const int health = vehicle->getHealth();
    if (health != vehicleHealth) {
        if (health < vehicleHealth) {
            const float penalty = (vehicleHealth - health) * 5;
            if (penalty > 0.0f) {
                printf("Health penalty: %.02f)\n", penalty);
                remainingScore -= penalty;
            }
        }
        vehicleHealth = health;
    }

    if (vehicle->unknown511 & 2) {
        vehicle->unknown511 &= ~2;
        printf("Run-over pedestrian penalty: %.02f)\n", 20.0);
        remainingScore -= 20.0f;
    }

    if (vehicle->GetSpeed() > 75.0f) {
        const float penalty = (elapsed * 25) / 1000.0f;
        if (penalty > 0.0f) {
            speedPenalty += penalty;
            remainingScore -= penalty;
        }
    } else if (speedPenalty > 0.0f) {
        printf("Speed penalty: %.02f\n", speedPenalty);
        speedPenalty = 0.0f;
    }

    if (!vehicle->unknown506 && !vehicle->unknown507 &&
        !vehicle->unknown508 && !vehicle->unknown509) {
        const float penalty = (elapsed * 50) / 1000.0f;
        if (penalty > 0.0f) {
            jumpPenalty += penalty;
            remainingScore -= penalty;
        }
    } else if (jumpPenalty > 0.0f) {
        printf("Jump penalty: %.02f\n", jumpPenalty);
        jumpPenalty = 0.0f;
    }

    if (vehicle->skidAmount > 0.0f) {
        const float penalty = (elapsed * 50) / 1000.0f;
        if (penalty > 0.0f) {
            driftPenalty += penalty;
            remainingScore -= penalty;
        }
    } else if (driftPenalty > 0.0f) {
        printf("Drift penalty: %.02f\n", driftPenalty);
        driftPenalty = 0.0f;
    }

    const int currentWantedLevel = WantedLevelManager::getInstance()->unknown8;
    if (currentWantedLevel) {
        const float scaledElapsed = elapsed * 10;
        const float penalty = scaledElapsed / 1000.0f;
        if (penalty > 0.0f) {
            wantedOvertimePenalty += penalty;
            remainingScore += scaledElapsed / -1000.0f;
        }
    } else if (wantedOvertimePenalty > 0.0f) {
        printf("Wanted level penalty (OT): %.02f\n", wantedOvertimePenalty);
        wantedOvertimePenalty = 0.0f;
    }

    const int previousWantedLevel = wantedLevel;
    if (currentWantedLevel != previousWantedLevel) {
        if (currentWantedLevel > previousWantedLevel) {
            const float penalty = (currentWantedLevel - previousWantedLevel) * 100;
            if (penalty > 0.0f) {
                printf("Wanted level penalty (gain): %.02f\n", penalty);
                remainingScore -= penalty;
            }
        }
        wantedLevel = currentWantedLevel;
    }

    Application::GetInstance()->GetHudManager()->spyGauge->setPercentage(
        (1000.0f - remainingScore) / 1000.0f);
    return remainingScore >= 0.0f;
}
