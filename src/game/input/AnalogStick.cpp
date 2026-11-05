/*
 * AnalogStick
 *
 * Original file: AnalogStick.cpp
 * Area:          input
 *
 * This file mirrors the layout of the retail build.  Add the decompiled
 * functions of AnalogStick.cpp here, in the order they appear in the library.
 */

// Recovered translation-unit SDK startup callbacks.
#include "../core/LocalSdkStartupStorage.h"
#include "../core/LocalStartupText.h"
#include "../core/GameEventMethods.h"
#include "../core/Point2D.h"

// Event declarations for the recovered destructor and vtable layout.
class EvStickMove : public IEvent {
public:
    virtual ~EvStickMove() __attribute__((used)) {}
};

class EvStickReleased : public IEvent {
public:
    virtual ~EvStickReleased() __attribute__((used)) {}
};

class EvUpDownStickMove : public IEvent {
public:
    virtual ~EvUpDownStickMove() __attribute__((used)) {}
};

class EvUpDownStickReleased : public IEvent {
public:
    virtual ~EvUpDownStickReleased() __attribute__((used)) {}
};

class EvLeftRightStickMove : public IEvent {
public:
    virtual ~EvLeftRightStickMove() __attribute__((used)) {}
};

class EvLeftRightStickReleased : public IEvent {
public:
    virtual ~EvLeftRightStickReleased() __attribute__((used)) {}
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

template Point2D<short>::~Point2D();

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
static void _GLOBAL__I__ZN11AnalogStickC2EP7ASpriteii() __attribute__((used));
static void _GLOBAL__I__ZN11AnalogStickC2EP7ASpriteii()
{
    __static_initialization_and_destruction_0(1, 65535);
}
}
