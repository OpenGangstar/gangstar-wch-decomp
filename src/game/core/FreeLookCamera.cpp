/*
 * FreeLookCamera
 *
 * Original file: FreeLookCamera.cpp
 * Area:          core
 *
 * This file mirrors the layout of the retail build.  Add the decompiled
 * functions of FreeLookCamera.cpp here, in the order they appear in the library.
 */

// Recovered translation-unit SDK startup callbacks.
#include "../core/LocalSdkStartupStorage.h"
#include "../core/LocalStartupText.h"
#include "Camera.h"

class FreeLookCamera : public Camera {
public:
    FreeLookCamera();
    ~FreeLookCamera();
    virtual void init(LevelObject* target, int mode);
    virtual void update(float elapsed);
    virtual void debug(irr::video::IVideoDriver* driver);
    void updateHorizontalAngle(int extent, int delta, float elapsed);
    void updateVerticalAngle(int extent, int delta, float elapsed);
    void setPosition(const irr::core::vector3d<float>& value);
private:
    float horizontalAngle;
    float verticalAngle;
};

void FreeLookCamera::init(LevelObject*, int)
{
}

void FreeLookCamera::update(float)
{
}

void FreeLookCamera::debug(irr::video::IVideoDriver*)
{
}

void FreeLookCamera::updateHorizontalAngle(int extent, int delta, float elapsed)
{
    horizontalAngle += (static_cast<float>(delta) * (static_cast<float>(extent) / 480.0f * 100.0f)) * elapsed;
}

void FreeLookCamera::updateVerticalAngle(int extent, int delta, float elapsed)
{
    verticalAngle = (static_cast<float>(delta) * (static_cast<float>(extent) / 320.0f * 100.0f)) * elapsed;
}

FreeLookCamera::~FreeLookCamera()
{
}

FreeLookCamera::FreeLookCamera() : horizontalAngle(0.0f), verticalAngle(0.0f)
{
}

void FreeLookCamera::setPosition(const irr::core::vector3d<float>& value)
{
    position = value;
    horizontalAngle = 0.0f;
    verticalAngle = 0.0f;
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
static void _GLOBAL__I__ZN14FreeLookCameraC2Ev() __attribute__((used));
static void _GLOBAL__I__ZN14FreeLookCameraC2Ev()
{
    __static_initialization_and_destruction_0(1, 65535);
}
}
