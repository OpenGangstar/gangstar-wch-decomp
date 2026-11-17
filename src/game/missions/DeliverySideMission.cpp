/*
 * DeliverySideMission
 *
 * Original file: DeliverySideMission.cpp
 * Area:          missions
 *
 * This file mirrors the layout of the retail build.  Add the decompiled
 * functions of DeliverySideMission.cpp here, in the order they appear in the library.
 */

// Recovered translation-unit SDK startup callbacks.
#include "../characters/PhysicAttributes.h"
#include "SideMissionTimerText.h"
#include "Checkpoint.h"
#include "../core/NativeStdio.h"
#include "SideMission.h"
#include "../core/LocalSdkStartupStorage.h"
#include "../core/LocalStartupText.h"

void operator delete(void*) throw();
extern "C" {
static void __tcf_2() __attribute__((used));
}

extern void* __dso_handle;
extern "C" {
int __aeabi_atexit(void*, void (*)(void*), void*);
void* _ZN3irr4core6stringIcNS0_12irrAllocatorIcEEEaSIcEERS4_PKT_(void*, const char*) __attribute__((weak));
}

extern "C" {
static void __tcf_2()
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
        __aeabi_atexit(0, reinterpret_cast<void (*)(void*)>(__tcf_2), &__dso_handle);
        new (irr::ps::vHalf) irr::ps::LocalVector3(0.5f, 0.5f, 0.5f);
    }
}

extern "C" {
static void _GLOBAL__I__ZN19DeliverySideMissionC2Ev() __attribute__((used));
static void _GLOBAL__I__ZN19DeliverySideMissionC2Ev()
{
    __static_initialization_and_destruction_0(1, 65535);
}
}

class DeliverySideMission : public SideMission {
public:
    DeliverySideMission();
    virtual void begin(irr::core::vector3d<float>, int, int&, float&);
    virtual bool pickUp(irr::core::vector3d<float>, int&, float&, int);
    virtual bool dropOff(irr::core::vector3d<float>);
    virtual void end();
    virtual void clean();
    virtual int getMoneyReward();
    virtual int getGoalMessage();
    virtual int getStartMessage();
    virtual int getEndMessage();
    virtual int getObj1Message();
    virtual int getObj2Message();

private:
    irr::core::array<Checkpoint*> pickupCheckpoints;
    Checkpoint* dropOffCheckpoint;
};

void DeliverySideMission::end()
{
}

int DeliverySideMission::getMoneyReward()
{
    return 2000;
}

int DeliverySideMission::getGoalMessage()
{
    return 0x30f1;
}

int DeliverySideMission::getStartMessage()
{
    return 0x30f0;
}

int DeliverySideMission::getEndMessage()
{
    return 0x30f4;
}

int DeliverySideMission::getObj1Message()
{
    return 0x30f2;
}

int DeliverySideMission::getObj2Message()
{
    return 0x30f3;
}

void DeliverySideMission::clean()
{
    disableCheckpoints(pickupCheckpoints);
    removeCheckpoint(dropOffCheckpoint);
}

DeliverySideMission::DeliverySideMission()
{
    pickupCheckpoints.data = 0;
    pickupCheckpoints.allocated = 0;
    pickupCheckpoints.used = 0;
    pickupCheckpoints.free_when_destroyed = true;
    pickupCheckpoints.is_sorted = true;
    pickupCheckpoints.unknown16 = 1;
    init();
    getCheckpoints(22, pickupCheckpoints);
    dropOffCheckpoint = 0;
}

static const char deliveryMissionTimerFormat[] __attribute__((section(".rodata.delivery_mission_timer_format"))) = "%02d:%02d:%01d";

void DeliverySideMission::begin(irr::core::vector3d<float> position, int level,
                               int& time, float& money)
{
    difficulty = level;
    Checkpoint* checkpoint = enableCheckpoints(pickupCheckpoints, position);
    const int pickupTime = calculateTime(position, checkpoint->GetPosition(), difficulty == 1 ? 150 : 65, difficulty);
    const float pickupMoney = calculateMoney(position, checkpoint->GetPosition(), 50, difficulty);
    time += pickupTime;
    money = pickupMoney;
    position.getDistanceFrom(checkpoint->GetPosition());

    char totalText[8];
    char pickupText[8];
    const int totalTime = time;
    formatSideMissionTime(totalText, deliveryMissionTimerFormat, totalTime);
    formatSideMissionTime(pickupText, deliveryMissionTimerFormat, pickupTime);
}

bool DeliverySideMission::dropOff(irr::core::vector3d<float> position)
{
    if (!isInCheckpointRange(position, dropOffCheckpoint))
        return false;
    removeCheckpoint(dropOffCheckpoint);
    return true;
}

bool DeliverySideMission::pickUp(irr::core::vector3d<float> position, int& time, float& money, int)
{
    if (!isInCheckpointsRange(position, pickupCheckpoints))
        return false;

    disableCheckpoints(pickupCheckpoints);
    float minimum, maximum;
    getRange(minimum, maximum, difficulty, 300, 400, 600, 700);
    unsigned short surface;
    dropOffCheckpoint = addCheckpoint(23, position, minimum, maximum,
        PhysicAttributes::MATERIAL_TYPE_SIDEWALK, surface);
    const int dropOffTime = calculateTime(position, dropOffCheckpoint->GetPosition(), 65, difficulty);
    const float dropOffMoney = calculateMoney(position, dropOffCheckpoint->GetPosition(), 50, difficulty);
    time += dropOffTime;
    money += dropOffMoney;
    position.getDistanceFrom(dropOffCheckpoint->GetPosition());

    char totalText[8];
    char dropOffText[8];
    const int totalTime = time;
    formatSideMissionTime(totalText, deliveryMissionTimerFormat, totalTime);
    formatSideMissionTime(dropOffText, deliveryMissionTimerFormat, dropOffTime);
    return true;
}
