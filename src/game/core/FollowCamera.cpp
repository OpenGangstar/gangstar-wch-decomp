/*
 * FollowCamera
 *
 * Original file: FollowCamera.cpp
 * Area:          core
 *
 * This file mirrors the layout of the retail build.  Add the decompiled
 * functions of FollowCamera.cpp here, in the order they appear in the library.
 */

// Recovered translation-unit SDK and AI startup callbacks.
#include "../core/LocalStartupStorage.h"
#include "../core/LocalStartupText.h"
#include "../core/CameraVariants.h"
#include "../characters/PhysicAttributes.h"
#include "../characters/Character.h"
#include "Quaternion.h"

extern "C" float acosf(float);

static inline __attribute__((always_inline))
irr::core::vector3d<float> followCameraOffset(const irr::core::vector3d<float>& facing)
{
    const irr::core::vector3d<float> up(0.0f, 0.0f, 1.0f);
    return irr::core::vector3d<float>(
        -facing.Y * up.Z + facing.Z * up.Y,
        -facing.Z * up.X + facing.X * up.Z,
        -facing.X * up.Y + facing.Y * up.X);
}

void FollowCamera::init(LevelObject* target, int mode)
{
    owner = static_cast<Character*>(target);
    if (owner) {
        setLookAt(owner->GetPosition());
        previousHeight = owner->GetPosition().Z;
        if (physics) {
            physics->SetPhysicInfo(*owner->getPhysicAttributes()->info, 0);
            previousHeight = physics->GetHeight(owner->GetPosition(), 0, false);
        }
        lookAt.Z = previousHeight + 180.0f;

        if (mode == 0)
            setPosition(owner->GetPosition() - owner->GetFront() * 450.0f);
        else if (mode == 1)
            setPosition(owner->GetPosition() - (-owner->GetFront()) * 450.0f);
        position.Z = owner->GetPosition().Z + 150.0f;
        owner->setCameraOffset(followCameraOffset(getFacing()));
    }
    flag32 = false;
    physics->SetIsOnGround(0, false);
}

void FollowCamera::goBehind(LevelObject* object)
{
    if (!object)
        return;

    setLookAt(owner->GetPosition());
    lookAt.Z = owner->GetPosition().Z + 180.0f;

    irr::core::vector3d<float> direction = object->GetPosition() - owner->GetPosition();
    direction.normalize();
    setPosition(owner->GetPosition() - direction * 450.0f);
    position.Z = owner->GetPosition().Z + 150.0f;
}

void FollowCamera::debug(irr::video::IVideoDriver*)
{
}

void FollowCamera::updateAngles(int horizontal, int vertical)
{
    updateCameraInputRates(horizontal, vertical, yawRate, pitchRate);
}

FollowCamera::~FollowCamera()
{
    delete physics;
}

FollowCamera::FollowCamera(Character* owner)
    : yawRate(0.0f), pitchRate(0.0f)
{
    physics = new PhysicAttributes(1, 0);
    init(owner, 0);
}

void operator delete(void*) throw();
extern "C" {
static void __tcf_3() __attribute__((used));
}

// Scoped imports distinguish the original TU-local transition tables.
namespace retail_followcamera_transitions {
extern const unsigned int civPassive_trans[] __attribute__((visibility("hidden")));
extern const unsigned int scriptedNpc_trans[] __attribute__((visibility("hidden")));
extern const unsigned int civAggressive_trans[] __attribute__((visibility("hidden")));
extern const unsigned int gangMember_trans[] __attribute__((visibility("hidden")));
extern const unsigned int cop_trans[] __attribute__((visibility("hidden")));
extern const unsigned int swat_trans[] __attribute__((visibility("hidden")));
extern const unsigned int civ_vehicle_trans[] __attribute__((visibility("hidden")));
extern const unsigned int cop_vehicle_trans[] __attribute__((visibility("hidden")));
extern const unsigned int guard_trans[] __attribute__((visibility("hidden")));
extern const unsigned int scripted_vehicle_trans[] __attribute__((visibility("hidden")));
}

extern void* __dso_handle;
extern "C" {
int __aeabi_atexit(void*, void (*)(void*), void*);
void* _ZN3irr4core6stringIcNS0_12irrAllocatorIcEEEaSIcEERS4_PKT_(void*, const char*) __attribute__((weak));
}

extern "C" {
static void __tcf_3()
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
        __aeabi_atexit(0, reinterpret_cast<void (*)(void*)>(__tcf_3), &__dso_handle);
        new (irr::ps::vHalf) irr::ps::LocalVector3(0.5f, 0.5f, 0.5f);
        new (gameloft::ai::civ_passive) gameloft::ai::LocalTransitionList(retail_followcamera_transitions::civPassive_trans, 75);
        new (gameloft::ai::npc_scripted) gameloft::ai::LocalTransitionList(retail_followcamera_transitions::scriptedNpc_trans, 12);
        new (gameloft::ai::civ_agressive) gameloft::ai::LocalTransitionList(retail_followcamera_transitions::civAggressive_trans, 57);
        new (gameloft::ai::gang_member) gameloft::ai::LocalTransitionList(retail_followcamera_transitions::gangMember_trans, 3);
        new (gameloft::ai::cop) gameloft::ai::LocalTransitionList(retail_followcamera_transitions::cop_trans, 78);
        new (gameloft::ai::swat) gameloft::ai::LocalTransitionList(retail_followcamera_transitions::swat_trans, 3);
        new (gameloft::ai::civ_vehicle) gameloft::ai::LocalTransitionList(retail_followcamera_transitions::civ_vehicle_trans, 36);
        new (gameloft::ai::cop_vehicle) gameloft::ai::LocalTransitionList(retail_followcamera_transitions::cop_vehicle_trans, 45);
        new (gameloft::ai::guard) gameloft::ai::LocalTransitionList(retail_followcamera_transitions::guard_trans, 42);
        new (gameloft::ai::scripted_vehicle) gameloft::ai::LocalTransitionList(retail_followcamera_transitions::scripted_vehicle_trans, 21);
    }
}

extern "C" {
static void _GLOBAL__I__ZN12FollowCameraC2EP9Character() __attribute__((used));
static void _GLOBAL__I__ZN12FollowCameraC2EP9Character()
{
    __static_initialization_and_destruction_0(1, 65535);
}
}

void FollowCamera::updatePosition(float elapsed, const irr::core::vector3d<float>& pivot,
    float distance, irr::core::vector3d<float>& yawAxis,
    irr::core::vector3d<float>& pitchAxis, float maximumPitch, float minimumPitch)
{
    const float degreesPerRadian = 57.2957763671875f;
    irr::core::vector3d<float> direction = position - pivot;
    direction.normalize();
    const float previousPitch = acosf(direction.dotProduct(yawAxis));
    const float pitchStep = elapsed * pitchRate;
    const float pitch = pitchStep * degreesPerRadian + previousPitch * degreesPerRadian;
    if ((pitch >= minimumPitch || pitchStep > 0.0f) &&
        (pitch <= maximumPitch || pitchStep < 0.0f)) {
        irr::core::quaternion rotation;
        rotation.fromAngleAxis(pitchStep, pitchAxis);
        rotation.normalize();
        pitchRate = 0.0f;
        position = (rotation * direction) * distance + pivot;
    }

    irr::core::quaternion rotation;
    rotation.fromAngleAxis(elapsed * yawRate, yawAxis);
    rotation.normalize();
    yawRate = 0.0f;
    direction = position - pivot;
    direction.normalize();
    position = (rotation * direction) * distance + pivot;
}

#include "../characters/Character.h"
irr::core::vector3d<float> FollowCamera::getFacing() const
{
    irr::core::vector3d<float> facing;
    if (owner) {
        facing = owner->GetPosition() - position;
        const irr::core::vector3d<float> up(0.0f, 0.0f, 1.0f);
        facing = up.crossProduct(facing);
        facing = facing.normalize();
    }
    return facing;
}
