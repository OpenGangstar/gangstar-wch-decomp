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
#include "Quaternion.h"

extern "C" float acosf(float);

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
    void updatePosition(float elapsed, const irr::core::vector3d<float>& pivot,
        float distance, irr::core::vector3d<float>& yawAxis,
        irr::core::vector3d<float>& pitchAxis, float maximumPitch, float minimumPitch);
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

void FreeLookCamera::updatePosition(float elapsed, const irr::core::vector3d<float>& pivot,
    float distance, irr::core::vector3d<float>& yawAxis,
    irr::core::vector3d<float>& pitchAxis, float maximumPitch, float minimumPitch)
{
    const float degreesPerRadian = 57.2957763671875f;
    irr::core::vector3d<float> direction = position - pivot;
    direction.normalize();
    const float previousPitch = acosf(direction.dotProduct(yawAxis));
    const float pitchStep = elapsed * verticalAngle;
    const float pitch = pitchStep * degreesPerRadian + previousPitch * degreesPerRadian;
    if (pitch >= minimumPitch && pitch <= maximumPitch) {
        irr::core::quaternion rotation;
        rotation.fromAngleAxis(pitchStep, pitchAxis);
        rotation.normalize();
        verticalAngle = 0.0f;
        position = (rotation * direction) * distance + pivot;
    }

    irr::core::quaternion rotation;
    rotation.fromAngleAxis(elapsed * horizontalAngle, yawAxis);
    rotation.normalize();
    horizontalAngle = 0.0f;
    direction = position - pivot;
    direction.normalize();
    position = (rotation * direction) * distance + pivot;
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
