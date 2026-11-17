/*
 * TouchScreenIPhone
 *
 * Original file: TouchScreenIPhone.cpp
 * Area:          input
 *
 * This file mirrors the layout of the retail build.  Add the decompiled
 * functions of TouchScreenIPhone.cpp here, in the order they appear in the library.
 */

// Recovered translation-unit SDK startup callbacks.
#include "../core/LocalSdkStartupStorage.h"
#include "../core/LocalStartupText.h"
#include "../rendering/GS3DStuff.h"
#include "TouchScreenIPhone.h"

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
static void _GLOBAL__I__ZN17TouchScreenIPhoneC2Effff() __attribute__((used));
static void _GLOBAL__I__ZN17TouchScreenIPhoneC2Effff()
{
    __static_initialization_and_destruction_0(1, 65535);
}
}

TouchScreenIPhone::~TouchScreenIPhone()
{
}

bool TouchScreenIPhone::OnEvent(const irr::SEvent& event)
{
    static bool isDown = false;
    if (event.type != irr::SEvent::MouseInputEvent)
        return false;

    Point2D<short> point(static_cast<short>(event.mouse.x), static_cast<short>(event.mouse.y));
    if (GS3DStuff::s_orientation == 1) {
        point.x = 480 - point.x;
        point.y = 320 - point.y;
    }
    switch (event.mouse.event) {
    case irr::SEvent::LeftPressed:
        isDown = true;
        touchBegan(point, 0);
        return true;
    case irr::SEvent::MouseMoved:
        if (!isDown)
            return false;
        touchMoved(point, 0);
        return true;
    case irr::SEvent::LeftReleased:
        isDown = false;
        touchEnded(point, 0);
        return true;
    }
    return false;
}

short TouchScreenIPhone::getLeftBound() const
{
    return left;
}

short TouchScreenIPhone::getRightBound() const
{
    return right;
}

short TouchScreenIPhone::getTopBound() const
{
    return top;
}

short TouchScreenIPhone::getBottomBound() const
{
    return bottom;
}

long TouchScreenIPhone::getTouchIDInRegion(const irr::core::rect<float>& region) const
{
    return TouchScreenBase::getTouchIDInRegion(region);
}

bool TouchScreenIPhone::isRegionPressed(const irr::core::rect<float>& region) const
{
    return TouchScreenBase::isRegionPressed(region);
}

TouchScreenIPhone::TouchScreenIPhone(float left, float top, float right, float bottom)
{
    this->left = static_cast<short>(left);
    this->right = static_cast<short>(right);
    this->top = static_cast<short>(top);
    this->bottom = static_cast<short>(bottom);
}
