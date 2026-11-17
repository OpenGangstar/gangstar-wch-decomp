/*
 * AccelerometerWin32
 *
 * Original file: AccelerometerWin32.cpp
 * Area:          input
 *
 * This file mirrors the layout of the retail build.  Add the decompiled
 * functions of AccelerometerWin32.cpp here, in the order they appear in the library.
 */

// Recovered translation-unit SDK startup callbacks.
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
static void _GLOBAL__I__ZN18AccelerometerWin32C2Ev() __attribute__((used));
static void _GLOBAL__I__ZN18AccelerometerWin32C2Ev()
{
    __static_initialization_and_destruction_0(1, 65535);
}
}

#include "AccelerometerBase.h"
#include "TouchScreenMouseEvent.h"

class AccelerometerWin32 : public AccelerometerBase, public irr::IEventReceiver {
public:
    AccelerometerWin32();
    virtual ~AccelerometerWin32();
    virtual bool OnEvent(const irr::SEvent& event);
    void setWide(bool value);

private:
    bool wide;
};

AccelerometerWin32::AccelerometerWin32()
{
    wide = false;
}

AccelerometerWin32::~AccelerometerWin32()
{
}

void AccelerometerWin32::setWide(bool value)
{
    if (value)
        moved(-0.5f, 0.0f, 0.0f);
    else
        moved(0.0f, -0.5f, 0.0f);
    wide = value;
}
