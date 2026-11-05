/*
 * TouchScreenBase
 *
 * Original file: TouchScreenBase.cpp
 * Area:          input
 *
 * This file mirrors the layout of the retail build.  Add the decompiled
 * functions of TouchScreenBase.cpp here, in the order they appear in the library.
 */

// Recovered translation-unit SDK string startup callbacks.
#include "../core/LocalStringStartupStorage.h"
#include "../core/LocalStartupText.h"
#include "../core/Rct.h"
#include "../rendering/GS3DStuff.h"
#include "TouchScreenBase.h"

void operator delete(void*) throw();
extern "C" {
static void __tcf_0() __attribute__((used));
}

extern void* __dso_handle;
extern "C" {
int __aeabi_atexit(void*, void (*)(void*), void*);
void* _ZN3irr4core6stringIcNS0_12irrAllocatorIcEEEaSIcEERS4_PKT_(void*, const char*) __attribute__((weak));
}

void TouchScreenBase::ConvertCoord(Point2D<short>& point)
{
    switch (GS3DStuff::s_orientation) {
    case 1: {
        const short x = point.x;
        point.x = 480 - point.y;
        point.y = x;
        break;
    }
    case 3: {
        const short x = point.x;
        point.x = point.y;
        point.y = 320 - x;
        break;
    }
    case 2:
        point.x = 480 - point.x;
        point.y = 320 - point.y;
        break;
    }
}

void TouchScreenBase::clear()
{
    for (int i = 0; i < 8; ++i)
        points[i].active = false;
}

void TouchScreenBase::clearTouchPoint(long id)
{
    points[id].active = false;
}

static const char releaseMessage[] = "Finger removal detected";
static const char cancelMessage[] = "INTERRUPTED";

void TouchScreenBase::touchEnded(const Point2D<short>& point, long id)
{
    _trace(releaseMessage);
    touchCancelled(point, id);
}

void TouchScreenBase::touchCancelled(const Point2D<short>&, long id)
{
    _trace(cancelMessage);
    points[id].active = false;
    points[id].externalId = -1;
    if (slotCount - 1 == id)
        --slotCount;
}

void TouchScreenBase::_trace(const char*) const
{
}

Point2D<short>* TouchScreenBase::getTouchPoint(long id)
{
    if (points[id].active && points[id].hasPoints)
        return &points[id].current;
    return 0;
}

Point2D<short>* TouchScreenBase::getFirstTouchPoint(long id)
{
    if (points[id].active && points[id].hasPoints)
        return &points[id].first;
    return 0;
}

int TouchScreenBase::getSwipeDirection(long id) const
{
    if (points[id].active && points[id].hasPoints)
        return points[id].swipeDirection;
    return 0;
}

void TouchScreenBase::enable()
{
    enabled = true;
}

void TouchScreenBase::disable()
{
    enabled = false;
}

bool TouchScreenBase::isEnabled() const
{
    return enabled;
}

void TouchScreenBase::getDimension(Rct<short>& result) const
{
    const short left = getLeftBound();
    const short top = getTopBound();
    const short right = getRightBound();
    const short bottom = getBottomBound();

    result.left = left;
    result.top = top;
    result.right = right;
    result.bottom = bottom;
}

template<class T>
inline Rct<T>::Rct(T left, T top, T right, T bottom)
    : left(left), top(top), right(right), bottom(bottom)
{
    _validate();
}

Rct<short> TouchScreenBase::getDimension() const
{
    const short left = getLeftBound();
    const short top = getTopBound();
    const short right = getRightBound();
    const short bottom = getBottomBound();

    return Rct<short>(left, top, right, bottom);
}

extern "C" {
static void __tcf_0()
{
    irr::scene::quake3::LocalStringStorage& value = irr::scene::quake3::irrEmptyStringc;
    if (!value.reference && value.array && value.array != value.inlineBuffer)
        ::operator delete(value.array);
}
}

template struct Rct<short>;

inline TouchScreenBase::_TouchPointInfo::~_TouchPointInfo()
{
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
        __aeabi_atexit(0, reinterpret_cast<void (*)(void*)>(__tcf_0), &__dso_handle);
    }
}

extern "C" {
static void _GLOBAL__I__ZN15TouchScreenBase14CLEAN_UP_DELAYE() __attribute__((used));
static void _GLOBAL__I__ZN15TouchScreenBase14CLEAN_UP_DELAYE()
{
    __static_initialization_and_destruction_0(1, 65535);
}
}
