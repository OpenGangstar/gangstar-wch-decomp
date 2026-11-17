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
