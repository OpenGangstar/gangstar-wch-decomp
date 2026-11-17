/*
 * Wheel
 *
 * Original file: Wheel.cpp
 * Area:          vehicles
 *
 * This file mirrors the layout of the retail build.  Add the decompiled
 * functions of Wheel.cpp here, in the order they appear in the library.
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
static void _GLOBAL__I__ZN5WheelC2EP7ASpritei() __attribute__((used));
static void _GLOBAL__I__ZN5WheelC2EP7ASpritei()
{
    __static_initialization_and_destruction_0(1, 65535);
}
}

#include "../app/Application.h"
#include "../input/TouchScreenBase.h"
#include "../hud/HudElement.h"
#include "../core/EventManager.h"
#include "../core/GameEventMethods.h"
#include "../core/PlacementNew.h"

class Wheel : public HudElement {
public:
    Wheel(ASprite*, int);
    virtual ~Wheel();
    virtual void update(double);
    virtual void setHand(bool);
    virtual void processTouch(long);
    virtual void processTouchRelease();
    virtual void draw2d() const;
private:
    bool positiveDirection;
    float displacement;
};

Wheel::~Wheel()
{
}

void Wheel::update(double)
{
    if (flags & 1u) {
        TouchScreenBase* screen = Application::GetInstance()->GetTouchScreen();
        const irr::core::rect<float>& region =
            reinterpret_cast<const irr::core::rect<float>&>(touchRegion);
        const long id = screen->getTouchIDInitiatedInRegion(region);
        if (id != -1)
            processTouch(id);
        else
            processTouchRelease();
    }
}


class EvWheelReleased : public IEvent {
public:
    EvWheelReleased(bool direction, float movement)
        : positiveDirection(direction), displacement(movement)
    {
        eventID = 15;
    }
    virtual ~EvWheelReleased() __attribute__((used));
private:
    bool positiveDirection;
    float displacement;
};

inline EvWheelReleased::~EvWheelReleased()
{
}

extern "C" void _ZN15EvWheelReleasedD1Ev(void*) __attribute__((weak));

void Wheel::processTouchRelease()
{
    if (flags & 1u) {
        if (flags & 2u) {
            EventManager* events = Application::GetInstance()->GetEventManager();
            unsigned int storage[sizeof(EvWheelReleased) / sizeof(unsigned int)];
            EvWheelReleased* event = new (storage) EvWheelReleased(positiveDirection, displacement);
            events->raise(*event);
            _ZN15EvWheelReleasedD1Ev(event);
        }
        flags &= ~2u;
    }
}

class EvWheelTurn : public IEvent {
public:
    virtual ~EvWheelTurn() __attribute__((used));
};

inline EvWheelTurn::~EvWheelTurn()
{
}

void Wheel::setHand(bool) {}
