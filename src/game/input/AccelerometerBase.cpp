/*
 * AccelerometerBase
 *
 * Original file: AccelerometerBase.cpp
 * Area:          input
 *
 * This file mirrors the layout of the retail build.  Add the decompiled
 * functions of AccelerometerBase.cpp here, in the order they appear in the library.
 */

// Recovered translation-unit SDK startup callbacks.
#include "../core/LocalSdkStartupStorage.h"
#include "../core/LocalStartupText.h"
#include "../core/GameEventMethods.h"
#include "AccelerometerBase.h"
#include "../core/Logs.h"

AccelerometerBase::AccelerometerBase()
{
    x = y = z = 0.0f;
    angleX = angleY = angleZ = 0.0f;
    _calcAngles();
    clear();
}

AccelerometerBase::~AccelerometerBase()
{
}

void AccelerometerBase::update(double)
{
    clear();
}

void AccelerometerBase::clear()
{
    baselineX = x;
    baselineY = y;
    baselineZ = z;
    minX = maxX = z;
}

static const char traceCategory[] = "AccelerometerBase";

void AccelerometerBase::_trace(const char* message) const
{
    Logs::trace(traceCategory, message);
}

// Event declarations for the recovered destructor and vtable layout.
class EvAcceleration : public IEvent {
public:
    virtual ~EvAcceleration() __attribute__((used)) {}
};

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
static void _GLOBAL__I__ZN17AccelerometerBaseC2Ev() __attribute__((used));
static void _GLOBAL__I__ZN17AccelerometerBaseC2Ev()
{
    __static_initialization_and_destruction_0(1, 65535);
}
}
