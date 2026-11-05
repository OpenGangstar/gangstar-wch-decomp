/*
 * TouchScreenWin32
 *
 * Original file: TouchScreenWin32.cpp
 * Area:          input
 *
 * This file mirrors the layout of the retail build.  Add the decompiled
 * functions of TouchScreenWin32.cpp here, in the order they appear in the library.
 */

// Recovered translation-unit SDK startup callbacks.
#include "../core/LocalSdkStartupStorage.h"
#include "../core/LocalStartupText.h"
#include "TouchScreenBase.h"

namespace irr {

// Mouse-event prefix used by the retail receiver.
struct SEvent {
    enum EventType { MouseInputEvent = 1 };
    enum MouseEvent { LeftPressed = 0, LeftReleased = 3, MouseMoved = 6 };

    int type;
    unsigned char unknown4[4];
    struct {
        int x;
        int y;
        float wheel;
        int event;
    } mouse;
};

class IEventReceiver {
public:
    virtual ~IEventReceiver() {}
    virtual bool OnEvent(const SEvent& event) = 0;
};

} // namespace irr

extern int __pointerId;

class TouchScreenWin32 : public TouchScreenBase, public irr::IEventReceiver {
public:
    TouchScreenWin32();
    virtual ~TouchScreenWin32();
    virtual bool OnEvent(const irr::SEvent& event);
    virtual short getLeftBound() const __attribute__((used)) { return 0; }
    virtual short getRightBound() const __attribute__((used)) { return 0; }
    virtual short getTopBound() const __attribute__((used)) { return 0; }
    virtual short getBottomBound() const __attribute__((used)) { return 0; }
    virtual long getTouchIDInRegion(const irr::core::rect<float>& region) const;
    virtual bool isRegionPressed(const irr::core::rect<float>& region) const;

    void touchCancelled(float x, float y, int externalId);
    void touchEnded(float x, float y, int externalId);
    void touchMoved(float x, float y, int externalId);
    void touchBegan(float x, float y, int externalId);
};

TouchScreenWin32::TouchScreenWin32()
{
}

TouchScreenWin32::~TouchScreenWin32()
{
}

long TouchScreenWin32::getTouchIDInRegion(const irr::core::rect<float>& region) const
{
    return TouchScreenBase::getTouchIDInRegion(region);
}

bool TouchScreenWin32::isRegionPressed(const irr::core::rect<float>& region) const
{
    return TouchScreenBase::isRegionPressed(region);
}

void TouchScreenWin32::touchCancelled(float x, float y, int externalId)
{
    const long id = getID(externalId);
    Point2D<short> point(static_cast<short>(x), static_cast<short>(y));
    TouchScreenBase::touchCancelled(point, id);
}

void TouchScreenWin32::touchEnded(float x, float y, int externalId)
{
    const long id = getID(externalId);
    Point2D<short> point(static_cast<short>(x), static_cast<short>(y));
    TouchScreenBase::touchEnded(point, id);
}

void TouchScreenWin32::touchMoved(float x, float y, int externalId)
{
    const long id = getID(externalId);
    Point2D<short> point(static_cast<short>(x), static_cast<short>(y));
    TouchScreenBase::touchMoved(point, id);
}

void TouchScreenWin32::touchBegan(float x, float y, int externalId)
{
    const long id = getID(externalId);
    Point2D<short> point(static_cast<short>(x), static_cast<short>(y));
    ConvertCoord(point);
    TouchScreenBase::touchBegan(point, id);
}

bool TouchScreenWin32::OnEvent(const irr::SEvent& event)
{
    static bool isDown = false;
    if (event.type != irr::SEvent::MouseInputEvent)
        return false;

    const int x = event.mouse.x;
    const int y = event.mouse.y;
    switch (event.mouse.event) {
    case irr::SEvent::LeftPressed:
        isDown = true;
        touchBegan(x, y, __pointerId);
        return true;
    case irr::SEvent::MouseMoved:
        if (!isDown)
            return false;
        touchMoved(x, y, __pointerId);
        return true;
    case irr::SEvent::LeftReleased:
        isDown = false;
        touchEnded(x, y, __pointerId);
        return true;
    }
    return false;
}

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
static void _GLOBAL__I__ZN16TouchScreenWin32C2Ev() __attribute__((used));
static void _GLOBAL__I__ZN16TouchScreenWin32C2Ev()
{
    __static_initialization_and_destruction_0(1, 65535);
}
}
