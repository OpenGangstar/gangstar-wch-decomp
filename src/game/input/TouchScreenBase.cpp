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
#include "../core/Rect.h"
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

TouchScreenBase::TouchScreenBase()
{
    enabled = true;
    slotCount = 0;
    currentTime = 0.0;
}

TouchScreenBase::~TouchScreenBase()
{
    clear();
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
static const char moveMessage[] = "Finger movement detected";

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

void TouchScreenBase::update(double elapsed)
{
    currentTime = elapsed;
    for (int i = 0; i < 8; ++i) {
        _TouchPointInfo& slot = points[i];
        if (!slot.hasPoints && slot.lastTouchTime + 0.5 < currentTime) {
            if (slot.active) {
                slot.active = false;
                slot.externalId = -1;
                if (slotCount == i)
                    slotCount = i - 1;
            }
        } else if (slot.active) {
            slotCount = i + 1;
        }
    }
}

void TouchScreenBase::touchMoved(const Point2D<short>& point, long id)
{
    _trace(moveMessage);
    _TouchPointInfo& slot = points[id];
    if (!slot.active)
        return;

    slot.previous = slot.current;
    slot.current = point;
    slot.lastTouchTime = currentTime;
    ++slot.numPoints;

    const short firstX = slot.first.x;
    const short currentX = slot.current.x;
    const int firstY = slot.first.y;
    const int currentY = slot.current.y;
    const int dx = firstX - currentX;
    const int dy = firstY - currentY;
    if (dx * dx + dy * dy >= 144 && slot.swipeDirection == 0) {
        if (firstX < currentX)
            slot.swipeDirection = 2;
        else
            slot.swipeDirection = 1;
    }
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

int TouchScreenBase::getNumPoints(long id) const
{
    int count = 0;
    if (points[id].active && points[id].hasPoints)
        count = points[id].numPoints;
    return count;
}

int TouchScreenBase::getSwipeDirection(long id) const
{
    if (points[id].active && points[id].hasPoints)
        return points[id].swipeDirection;
    return 0;
}

long TouchScreenBase::getID(long externalId)
{
    long freeSlot = -1;
    for (long i = 0; i < 8; ++i) {
        if (points[i].externalId == externalId)
            return i;
        if (!points[i].active && freeSlot == -1)
            freeSlot = i;
    }

    // A new external ID requires a free touch slot.
    points[freeSlot].externalId = externalId;
    return freeSlot;
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

static inline bool containsTouchPoint(const irr::core::rect<float>& region,
                                      const Point2D<short>& point)
{
    const float x = point.x;
    const float y = point.y;
    const float left = region.UpperLeftCorner.X;
    if (!(x >= left))
        return false;
    const float top = region.UpperLeftCorner.Y;
    if (!(y >= top))
        return false;
    const float right = region.LowerRightCorner.X;
    if (!(x <= right))
        return false;
    const float bottom = region.LowerRightCorner.Y;
    return y <= bottom;
}

long TouchScreenBase::getTouchIDInitiatedInRegion(const irr::core::rect<float>& region) const
{
    for (int i = 0; i < slotCount; ++i) {
        const _TouchPointInfo& slot = points[i];
        if (containsTouchPoint(region, slot.first) && slot.hasPoints && slot.active)
            return i;
    }
    return -1;
}

bool TouchScreenBase::isRegionPressed(const irr::core::rect<float>& region) const
{
    for (int i = 0; i < slotCount; ++i) {
        const _TouchPointInfo& slot = points[i];
        if (containsTouchPoint(region, slot.current) && slot.hasPoints && slot.active)
            return true;
    }
    return false;
}

long TouchScreenBase::getTouchIDInRegion(const irr::core::rect<float>& region) const
{
    for (int i = 0; i < slotCount; ++i) {
        const _TouchPointInfo& slot = points[i];
        if (containsTouchPoint(region, slot.current) && slot.hasPoints && slot.active)
            return i;
    }
    return -1;
}

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
