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

template<class T>
inline Point2D<T>::Point2D(T x, T y)
    : x(x), y(y)
{
}

class TouchScreenWin32 : public TouchScreenBase {
public:
    void touchCancelled(float x, float y, int externalId);
    void touchEnded(float x, float y, int externalId);
    void touchMoved(float x, float y, int externalId);
    void touchBegan(float x, float y, int externalId);
};

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
