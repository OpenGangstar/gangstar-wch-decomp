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
#include "../core/SceneNode.h"
#include "../core/ASprite.h"
#include "../core/EventManager.h"
#include "../core/GameEventMethods.h"
#include "../core/PlacementNew.h"

#include "Wheel.h"

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

void Wheel::draw2d() const
{
    if (!(flags & 1))
        return;
    if (flags & 2) {
        Application::GetInstance()->GetDevice()->getVideoDriver();
        float rotation = displacement;
        if (!positiveDirection)
            rotation = -rotation;
        const SpriteFrame* spriteFrame = sprite->GetFrame(frame);
        const SpriteFrameModule* frameModule = sprite->GetFModule(spriteFrame->firstModule);
        const SpriteModule* module = sprite->GetModule(frameModule->module);
        const float x = (module->width >> 1) + frameModule->x;
        const float y = (module->height >> 1) + frameModule->y;
        irr::core::matrix4 matrix;
        matrix.setRotationRadians(irr::core::vector3d<float>(0, 0, rotation));
        irr::core::vector3d<float> translation(-x, -y, 0);
        matrix.rotateVect(translation);
        matrix.setTranslation(irr::core::vector3d<float>(x, y, 0) + translation);
        ASprite::s_global_transform = matrix;
        sprite->PaintFrame(frame, 0, 0, 0);
        ASprite::s_global_transform = irr::core::matrix4();
    } else {
        HudElement::draw2d();
    }
}
