/*
 * VehicleCamera
 *
 * Original file: VehicleCamera.cpp
 * Area:          vehicles
 *
 * This file mirrors the layout of the retail build.  Add the decompiled
 * functions of VehicleCamera.cpp here, in the order they appear in the library.
 */

// Recovered translation-unit SDK and AI startup callbacks.
#include "../core/LocalStartupStorage.h"
#include "../core/LocalStartupText.h"
#include "../core/CameraVariants.h"
#include "../core/Quaternion.h"
#include "Vehicle.h"

extern "C" float acosf(float);

void VehicleCamera::debug(irr::video::IVideoDriver*)
{
}

void VehicleCamera::updateAngles(int horizontal, int vertical)
{
    updateCameraInputRates(horizontal, vertical, yawRate, pitchRate);
}

void VehicleCamera::enter()
{
    if (!entered) {
        vehicle->onCameraEnter();
        entered = true;
    }
}

VehicleCamera::~VehicleCamera()
{
}

VehicleCamera::VehicleCamera(LevelObject* owner)
    : yawRate(0.0f), pitchRate(0.0f), entered(false)
{
    init(owner, 0);
}

void VehicleCamera::init(LevelObject* owner, int)
{
    entered = false;
    vehicle = static_cast<Vehicle*>(owner);
    if (vehicle && vehicle->sceneNode) {
        distance = static_cast<float>(vehicle->cameraSideDistance);
        previousHeight = owner->GetPosition().Z;

        const irr::core::vector3d<float> front = vehicle->GetFront();
        vector40 = front * static_cast<float>(vehicle->cameraLookAhead);
        vector40.Z = static_cast<float>(vehicle->cameraLookHeight);
        setLookAt(vehicle->GetPosition() + vector40);

        const irr::core::vector3d<float> back = -vehicle->GetFront();
        vector52 = back * static_cast<float>(vehicle->cameraSideDistance);
        vector52.Z = static_cast<float>(vehicle->cameraPositionHeight);
        setPosition(vehicle->GetPosition() + vector52);
    }
    previousSpeed = 0.0f;
}

void operator delete(void*) throw();
extern "C" {
static void __tcf_3() __attribute__((used));
}

// Scoped imports distinguish the original TU-local transition tables.
namespace retail_vehiclecamera_transitions {
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
        new (gameloft::ai::civ_passive) gameloft::ai::LocalTransitionList(retail_vehiclecamera_transitions::civPassive_trans, 75);
        new (gameloft::ai::npc_scripted) gameloft::ai::LocalTransitionList(retail_vehiclecamera_transitions::scriptedNpc_trans, 12);
        new (gameloft::ai::civ_agressive) gameloft::ai::LocalTransitionList(retail_vehiclecamera_transitions::civAggressive_trans, 57);
        new (gameloft::ai::gang_member) gameloft::ai::LocalTransitionList(retail_vehiclecamera_transitions::gangMember_trans, 3);
        new (gameloft::ai::cop) gameloft::ai::LocalTransitionList(retail_vehiclecamera_transitions::cop_trans, 78);
        new (gameloft::ai::swat) gameloft::ai::LocalTransitionList(retail_vehiclecamera_transitions::swat_trans, 3);
        new (gameloft::ai::civ_vehicle) gameloft::ai::LocalTransitionList(retail_vehiclecamera_transitions::civ_vehicle_trans, 36);
        new (gameloft::ai::cop_vehicle) gameloft::ai::LocalTransitionList(retail_vehiclecamera_transitions::cop_vehicle_trans, 45);
        new (gameloft::ai::guard) gameloft::ai::LocalTransitionList(retail_vehiclecamera_transitions::guard_trans, 42);
        new (gameloft::ai::scripted_vehicle) gameloft::ai::LocalTransitionList(retail_vehiclecamera_transitions::scripted_vehicle_trans, 21);
    }
}

extern "C" {
static void _GLOBAL__I__ZN13VehicleCameraC2EP11LevelObject() __attribute__((used));
static void _GLOBAL__I__ZN13VehicleCameraC2EP11LevelObject()
{
    __static_initialization_and_destruction_0(1, 65535);
}
}

void VehicleCamera::updatePosition(float elapsed, const irr::core::vector3d<float>& pivot,
    float distance, irr::core::vector3d<float>& yawAxis,
    irr::core::vector3d<float>&, float, float)
{
    irr::core::vector3d<float> direction = position - pivot;
    direction.normalize();
    acosf(direction.dotProduct(yawAxis));

    irr::core::quaternion rotation;
    rotation.fromAngleAxis(elapsed * yawRate, yawAxis);
    rotation.normalize();
    yawRate = 0.0f;
    direction = position - pivot;
    direction.normalize();
    position = (rotation * direction) * distance + pivot;
}

#include "../world/LevelObject.h"
irr::core::vector3d<float> VehicleCamera::getFacing() const
{
    irr::core::vector3d<float> facing;
    if (vehicle) {
        facing = vehicle->GetPosition() - position;
        const irr::core::vector3d<float> up(0.0f, 0.0f, 1.0f);
        facing = up.crossProduct(facing);
        facing = facing.normalize();
    }
    return facing;
}
