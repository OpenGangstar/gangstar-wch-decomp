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
#include "CameraVariants.h"
#include "SceneCamera.h"
#include "../app/Application.h"
#include "../characters/Character.h"
#include "../hud/CHudManager.h"

CameraManager* CameraManager::s_cm;

static const float radiansPerDegree = 3.14159265358979323846f / 180.0f;

CameraManager::~CameraManager()
{
}

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

template<>
void AnimatableType<irr::core::vector3d<float> >::Update(float elapsed)
{
    switch (interpolationMode) {
    case 1:
        if (duration > 0.0f)
            progress += elapsed / duration;
        if (progress > 1.0f || duration == 0.0f)
            progress = 1.0f;
        break;
    case 2:
        if (duration > 0.0f)
            progress += elapsed / duration;
        if (progress > 1.0f || duration == 0.0f)
            progress = 0.0f;
        break;
    case 3:
        if (interpolate) {
            if (duration > 0.0f)
                progress += elapsed / duration;
            if (progress > 1.0f || duration == 0.0f) {
                interpolate = false;
                progress = 1.0f;
            }
        } else {
            if (duration > 0.0f)
                progress -= elapsed / duration;
            if (progress < 0.0f || duration == 0.0f) {
                interpolate = true;
                progress = 0.0f;
            }
        }
        break;
    default:
        return;
    }
    current = start + (end - start) * progress;
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

void CameraManager::clean()
{
    delete followCamera;
    delete lockCamera;
    delete vehicleCamera;
    delete fpsCamera;
    delete this;
    s_cm = 0;
}

void CameraManager::goToSide(bool left)
{
    const irr::core::vector3d<float> position = vehicleCamera->getPosition();
    const irr::core::vector3d<float> lookAt = vehicleCamera->getLookAt();
    vehicleCamera->goToSide(left);
    positionTransition.begin(position, vehicleCamera->getPosition(), 0.3f);
    targetTransition.begin(lookAt, vehicleCamera->getLookAt(), 0.3f);
}

void CameraManager::goBehind(LevelObject* object)
{
    const irr::core::vector3d<float> position = followCamera->getPosition();
    const irr::core::vector3d<float> lookAt = followCamera->getLookAt();
    followCamera->goBehind(object);
    positionTransition.begin(position, followCamera->getPosition(), 0.3f);
    targetTransition.begin(lookAt, followCamera->getLookAt(), 0.3f);
}

void CameraManager::enterMode(int newMode, LevelObject* newTarget, float transition, int flags)
{
    flag154 = false;
    flag155 = false;
    mode = newMode;
    target = newTarget;
    touch = 0;

    const irr::core::vector3d<float> position = currentCamera->getPosition();
    const irr::core::vector3d<float> lookAt = currentCamera->getLookAt();
    currentCamera->exit();
    switch (mode) {
    case 0: currentCamera = followCamera; break;
    case 1: currentCamera = lockCamera; break;
    case 2: currentCamera = vehicleCamera; break;
    case 3: currentCamera = sceneCamera; break;
    case 4: currentCamera = fpsCamera; break;
    }
    currentCamera->init(target, flags);
    positionTransition.begin(position, currentCamera->getPosition(), transition);
    targetTransition.begin(lookAt, currentCamera->getLookAt(), transition);
}

CameraManager::CameraManager(float nearDistance, float farDistance, float fov, LevelObject* target)
    : touch(0), mode(0), touchTarget(0)
{
    touchScreenInputs = false;
    used = false;
    flag154 = false;
    flag155 = false;
    touchX = 0;
    touchY = 0;
    value164 = 0;
    value168 = 0;
    sceneCamera = 0;

    Application* app = Application::GetInstance();
    cameraNode = app->GetDevice()->getSceneManager()->addCameraSceneNode(
        0, irr::core::vector3d<float>(), irr::core::vector3d<float>(0.0f, 0.0f, 100.0f), -1);
    cameraNode->setNearValue(nearDistance);
    cameraNode->setFarValue(farDistance);
    cameraNode->setFOV(fov);
    cameraNode->setUpVector(irr::core::vector3d<float>(0.0f, 0.0f, 1.0f));
    followCamera = new FollowCamera(static_cast<Character*>(target));
    lockCamera = new LockCamera(target);
    vehicleCamera = new VehicleCamera(target);
    fpsCamera = new FPSCamera;
    currentCamera = followCamera;
    app->GetHudManager()->cameraManager = this;
}

CameraManager* CameraManager::getInstance()
{
    if (!s_cm)
        s_cm = new CameraManager(50.0f, 8000.0f, 50.0f * radiansPerDegree, 0);
    return s_cm;
}

bool CameraManager::updateTransition(float elapsed)
{
    if (!(positionTransition.progress >= 1.0f && targetTransition.progress >= 1.0f)) {
        positionTransition.Update(elapsed);
        cameraNode->setPosition(irr::core::vector3d<float>(positionTransition.current));
        cameraNode->updateAbsolutePosition(false);
        targetTransition.Update(elapsed);
        cameraNode->setTarget(irr::core::vector3d<float>(targetTransition.current));
        return true;
    }
    currentCamera->enter();
    return false;
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
