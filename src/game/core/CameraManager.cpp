/*
 * CameraManager
 *
 * Original file: CameraManager.cpp
 * Area:          core
 *
 * This file mirrors the layout of the retail build.  Add the decompiled
 * functions of CameraManager.cpp here, in the order they appear in the library.
 */

// Recovered translation-unit SDK and AI startup callbacks.
#include "../core/LocalStartupStorage.h"
#include "../core/LocalStartupText.h"
#include "Camera.h"
#include "CameraManager.h"

CameraManager* CameraManager::s_cm;

static const float radiansPerDegree = 3.14159265358979323846f / 180.0f;

void CameraManager::setFOV(int degrees)
{
    cameraNode->setFOV(degrees * radiansPerDegree);
}

int CameraManager::getFOV()
{
    const float degreesPerRadian = 57.2957763671875f;
    return static_cast<int>(cameraNode->getFOV() * degreesPerRadian);
}

irr::scene::ICameraSceneNode* CameraManager::getCamera() const
{
    return cameraNode;
}

void CameraManager::debug(irr::video::IVideoDriver*)
{
}

void CameraManager::setSceneCamera(SceneCamera* scene)
{
    sceneCamera = scene;
}

void CameraManager::setTouchScreenInputs(bool enabled)
{
    touchScreenInputs = enabled;
}

bool CameraManager::isUsed() const
{
    return used;
}

void operator delete(void*) throw();
extern "C" {
static void __tcf_3() __attribute__((used));
}

// Scoped imports distinguish the original TU-local transition tables.
namespace retail_cameramanager_transitions {
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

const irr::core::vector3d<float>& CameraManager::getPosition() const
{
    return currentCamera->getPosition();
}

const irr::core::vector3d<float>& CameraManager::getLookAt() const
{
    return currentCamera->getLookAt();
}

CameraManager* CameraManager::getInstance()
{
    if (!s_cm)
        s_cm = new CameraManager(50.0f, 8000.0f, 50.0f * radiansPerDegree, 0);
    return s_cm;
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
        new (gameloft::ai::civ_passive) gameloft::ai::LocalTransitionList(retail_cameramanager_transitions::civPassive_trans, 75);
        new (gameloft::ai::npc_scripted) gameloft::ai::LocalTransitionList(retail_cameramanager_transitions::scriptedNpc_trans, 12);
        new (gameloft::ai::civ_agressive) gameloft::ai::LocalTransitionList(retail_cameramanager_transitions::civAggressive_trans, 57);
        new (gameloft::ai::gang_member) gameloft::ai::LocalTransitionList(retail_cameramanager_transitions::gangMember_trans, 3);
        new (gameloft::ai::cop) gameloft::ai::LocalTransitionList(retail_cameramanager_transitions::cop_trans, 78);
        new (gameloft::ai::swat) gameloft::ai::LocalTransitionList(retail_cameramanager_transitions::swat_trans, 3);
        new (gameloft::ai::civ_vehicle) gameloft::ai::LocalTransitionList(retail_cameramanager_transitions::civ_vehicle_trans, 36);
        new (gameloft::ai::cop_vehicle) gameloft::ai::LocalTransitionList(retail_cameramanager_transitions::cop_vehicle_trans, 45);
        new (gameloft::ai::guard) gameloft::ai::LocalTransitionList(retail_cameramanager_transitions::guard_trans, 42);
        new (gameloft::ai::scripted_vehicle) gameloft::ai::LocalTransitionList(retail_cameramanager_transitions::scripted_vehicle_trans, 21);
    }
}

extern "C" {
static void _GLOBAL__I__ZN13CameraManager4s_cmE() __attribute__((used));
static void _GLOBAL__I__ZN13CameraManager4s_cmE()
{
    __static_initialization_and_destruction_0(1, 65535);
}
}
