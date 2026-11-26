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
#include "Geometry.h"
#include "Rect.h"
#include "SceneCamera.h"
#include "Quaternion.h"
#include "Lock.h"
#include "../app/Application.h"
#include "IrrlichtDevice.h"
#include "../characters/Character.h"
#include "../characters/PlayerTest.h"
#include "../hud/CHudManager.h"
#include "../hud/MenuManager.h"
#include "../input/TouchScreenBase.h"
#include "../scripting/ScriptManager.h"
#include "../vehicles/Vehicle.h"
#include "../audio/SoundManager.h"
#include "../combat/Explosion.h"
#include "../world/LevelObject.h"
#include "../world/GameObjectManager.h"

extern "C" int __android_log_print(int priority, const char* tag, const char* format, ...);

static const char touchReleaseLogText[] = "CameraManager::processTouchRelease()";

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

void CameraManager::updateUpVector(float angle)
{
    const irr::core::vector3d<float>& lookAt = getLookAt();
    irr::core::vector3d<float> direction = lookAt - getPosition();
    direction.normalize();
    irr::core::quaternion rotation;
    rotation.fromAngleAxis(angle, direction);
    cameraNode->setUpVector(rotation * irr::core::vector3d<float>(0.0f, 0.0f, 1.0f));
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
    : touch(0), mode(0), lastTapTime(0)
{
    touchScreenInputs = false;
    used = false;
    flag154 = false;
    flag155 = false;
    touchPoint.X = 0;
    touchPoint.Y = 0;
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
    app->GetHudManager()->defaultReceiver = this;
}

void CameraManager::processTouch(long id)
{
    if (!touchScreenInputs || mode == 4 || MenuManager::getInstance()->consumedCursors() ||
        ScriptManager::getInstance()->isInCinematic())
        return;

    TouchScreenBase* screen = Application::GetInstance()->GetTouchScreen();
    const unsigned int now = Application::GetInstance()->GetDevice()->getTimer()->getRealTime();
    if (!touch)
        touch = now;

    if (id != -1) {
        const Point2D<short> displacement = screen->getTouchDisplacement(id);
        const short horizontal = displacement.x;
        const short vertical = displacement.y;
        if (!flag154) {
            flag154 = true;
            value164 = 0;
            value168 = 0;
        }
        value164 += horizontal < 0 ? -horizontal : horizontal;
        value168 += vertical < 0 ? -vertical : vertical;
        if (currentCamera == followCamera)
            followCamera->updateAngles(2 * horizontal, vertical);
        if (currentCamera == vehicleCamera)
            vehicleCamera->updateAngles(horizontal, vertical);
    }
    if (const Point2D<short>* point = screen->getTouchPoint(id)) {
        touchPoint.X = point->x;
        touchPoint.Y = point->y;
    }
    used = true;
}

namespace {
// LevelObject prefix used by the click test; CameraManager is not a friend.
struct ClickObjectFields {
    void* methods;
    unsigned int flags;
    LevelObject* previous;
    LevelObject* next;
    irr::scene::ISceneNode* sceneNode;
};
inline ClickObjectFields& clickFields(LevelObject* object)
{
    return *reinterpret_cast<ClickObjectFields*>(object);
}
// Irrlicht 1.4.2 vector3d scalar division.
inline irr::core::vector3d<float> divideVector(const irr::core::vector3d<float>& value, const float v)
{
    float i = (float)1.0 / v;
    return irr::core::vector3d<float>(value.X * i, value.Y * i, value.Z * i);
}
// Irrlicht 1.4.2 aabbox3d subset: edge constructor and getCenter.
struct ClickBox {
    ClickBox() {}
    ClickBox(const irr::core::vector3d<float>& minimum, const irr::core::vector3d<float>& maximum)
        : MinEdge(minimum), MaxEdge(maximum) {}
    irr::core::vector3d<float> getCenter() const { return divideVector(MinEdge + MaxEdge, 2); }
    irr::core::vector3d<float> MinEdge, MaxEdge;
};
}
extern "C" bool _ZNK3irr4core8aabbox3dIfE18intersectsWithLineERKNS0_6line3dIfEE(
    const ClickBox* box, const irr::core::line3d<float>& ray) __attribute__((weak));

inline bool intersectsWithLine(const ClickBox& box, const irr::core::line3d<float>& ray)
{
    return _ZNK3irr4core8aabbox3dIfE18intersectsWithLineERKNS0_6line3dIfEE(&box, ray);
}

namespace {
// Padded bounding-box test of one candidate's mesh against the ray.
inline bool clickTest(irr::scene::ISceneNode* mesh, bool transformed, float padding,
                      const irr::core::line3d<float>& ray)
{
    using irr::core::aabbox3d;
    using irr::core::vector3d;
    ClickBox box;
    vector3d<float> minEdge;
    float maxX, maxY, maxZ;
    if (!transformed) {
        const aabbox3d<float>& source = mesh->getBoundingBox();
        minEdge.X = source.MinEdge.X;
        minEdge.Y = source.MinEdge.Y;
        minEdge.Z = source.MinEdge.Z;
        maxX = source.MaxEdge.X;
        maxY = source.MaxEdge.Y;
        maxZ = source.MaxEdge.Z;
    } else {
        const aabbox3d<float>& source = mesh->getTransformedBoundingBox();
        minEdge.X = source.MinEdge.X;
        minEdge.Y = source.MinEdge.Y;
        minEdge.Z = source.MinEdge.Z;
        maxX = source.MaxEdge.X;
        maxY = source.MaxEdge.Y;
        maxZ = source.MaxEdge.Z;
    }
    box = ClickBox(vector3d<float>(minEdge.X, minEdge.Y, minEdge.Z),
                              vector3d<float>(maxX, maxY, maxZ));
    const vector3d<float> center = box.getCenter();
    vector3d<float> lower = box.MinEdge - center;
    const vector3d<float> minimum = lower.normalize() * padding + box.MinEdge;
    vector3d<float> upper = box.MaxEdge - center;
    const vector3d<float> maximum = box.MaxEdge + upper.normalize() * padding;
    return intersectsWithLine(ClickBox(minimum, maximum), ray);
}
}

LevelObject* CameraManager::getClickedTarget(irr::core::line3d<float> ray, bool primary) const
{
    using irr::core::aabbox3d;
    using irr::core::vector3d;
    LevelObject* object = GameObjectManager::s_gom->GetFirst(0);
    while (object) {
        if (primary && LevelObject::s_type[object->getObjectType()] != 5) {
            object = clickFields(object).next;
            continue;
        }
        if (!object->isEnabled() || !clickFields(object).sceneNode || !clickFields(object).sceneNode->isVisible() ||
            !object->isVisibleOnScreen() || !(clickFields(object).flags & 4) || object->isDead()) {
            object = clickFields(object).next;
            continue;
        }

        irr::scene::ISceneNode* mesh = static_cast<irr::scene::ISceneNode*>(object->getSkinMesh());
        if (!mesh) {
            object = clickFields(object).next;
            continue;
        }
        float padding = object->GetPosition().getDistanceFromSQ(ray.start) / 40000.0f;
        if (LevelObject::s_type[object->getObjectType()] == 5 &&
            (PlayerTest::GetPlayer()->flags240 & 0xfe))
            padding += padding;

        if (clickTest(mesh, LevelObject::s_type[object->getObjectType()] == 3, padding, ray))
            break;
        object = clickFields(object).next;
    }
    return object;
}

LevelObject* CameraManager::tappedTarget(const irr::core::position2d<int>& point,
                                        const irr::core::vector3d<float>&) const
{
    const irr::core::position2d<int> cursor(point);
    irr::scene::ISceneCollisionManager* collision =
        Application::GetInstance()->GetDevice()->getSceneManager()->getSceneCollisionManager();
    const irr::core::line3d<float> ray =
        collision->getRayFromScreenCoordinates(cursor, CameraManager::getInstance()->getCamera());
    irr::core::vector3d<float> direction = ray.end - ray.start;
    direction.normalize();

    LevelObject* result = getClickedTarget(ray, true);
    if (!result)
        result = getClickedTarget(ray, false);
    if (result && result->isDead())
        result = 0;
    return result;
}

void CameraManager::processTouchRelease()
{
    __android_log_print(4, touchReleaseLogText, touchReleaseLogText);
    if (!touchScreenInputs || MenuManager::getInstance()->consumedCursors() ||
        ScriptManager::getInstance()->isInCinematic())
        return;

    if (touch) {
        if (Application::GetInstance()->GetDevice()->getTimer()->getRealTime() - touch > 499 ||
            value164 > 9 || value168 > 9) {
            flag155 = true;
            flag154 = false;
        } else {
            flag154 = false;
            const unsigned int now = Application::GetInstance()->GetDevice()->getTimer()->getRealTime();
            if (now - lastTapTime <= 499) {
                if (mode == 2) {
                    Lock::getInstance()->setTarget(0);
                    if (static_cast<SavePrimaryInterface*>(PlayerTest::GetPlayer())->getVehicle()) {
                        const int direction =
                            static_cast<SavePrimaryInterface*>(PlayerTest::GetPlayer())->getVehicle()->getVelDirec();
                        if (!direction) {
                            CameraManager::getInstance()->enterMode(
                                2, static_cast<SavePrimaryInterface*>(PlayerTest::GetPlayer())->getVehicle(),
                                0.3f, direction);
                        }
                    }
                } else {
                    PlayerTest::GetPlayer()->_SetTarget(0, true);
                }
            } else {
                LevelObject* hit = tappedTarget(touchPoint, currentCamera->getPosition());
                if (mode == 2) {
                    Lock::getInstance()->setTarget(hit);
                } else if (target == reinterpret_cast<LevelObject*>(
                               static_cast<SavePositionInterface*>(PlayerTest::GetPlayer()))) {
                    if (hit) {
                        if (hit == PlayerTest::GetPlayer()->_GetTarget())
                            PlayerTest::GetPlayer()->_SetTarget(0, true);
                        else
                            PlayerTest::GetPlayer()->_SetTarget(hit, true);
                    } else if (PlayerTest::GetPlayer()->_GetTarget()) {
                        PlayerTest::GetPlayer()->_SetTarget(0, true);
                    }
                }
            }
            lastTapTime = now;
        }
        touch = 0;
    }
    used = false;
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


extern "C" long lrand48(void);
extern "C" void _ZN12FollowCamera14updatePositionEfRKN3irr4core8vector3dIfEEfRS3_S6_ff(
    FollowCamera*, float, const irr::core::vector3d<float>&, float,
    irr::core::vector3d<float>&, irr::core::vector3d<float>&, float, float);
extern "C" void _ZN13VehicleCamera14updatePositionEfRKN3irr4core8vector3dIfEEfRS3_S6_ff(
    VehicleCamera*, float, const irr::core::vector3d<float>&, float,
    irr::core::vector3d<float>&, irr::core::vector3d<float>&, float, float);
extern "C" irr::core::vector3d<float> _ZNK12FollowCamera9getFacingEv(const FollowCamera*);

void CameraManager::update(float dt)
{
    float elapsed = dt * 0.001f;
    if (!updateTransition(elapsed)) {
        currentCamera->update(elapsed);
        SoundManager::getInstance()->setListenerPos(currentCamera->getPosition(),
            currentCamera->getLookAt(), irr::core::vector3d<float>(0.0f, 0.0f, 1.0f));
        if (mode == 3)
            return;
        if ((flag154 || flag155) && (mode == 0 || mode == 2)) {
            irr::core::vector3d<float> up(0.0f, 0.0f, 1.0f);
            const irr::core::vector3d<float>& lookAt = currentCamera->getLookAt();
            const irr::core::vector3d<float>& position = currentCamera->getPosition();
            irr::core::vector3d<float> side(lookAt.X - position.X, lookAt.Y - position.Y, 0.0f);
            side.normalize();
            side.rotateXYBy(90.0, irr::core::vector3d<float>(0.0f, 0.0f, 0.0f));
            side.normalize();
            if (!flag154 && flag155)
                elapsed = 0.0f;
            Camera* const camera = currentCamera;
            FollowCamera* const follow = followCamera;
            if (camera == follow)
                _ZN12FollowCamera14updatePositionEfRKN3irr4core8vector3dIfEEfRS3_S6_ff(followCamera,
                    elapsed, target->GetPosition(),
                    currentCamera->getPosition().getDistanceFrom(target->GetPosition()),
                    up, side, 80.0f, 45.0f);
            if (currentCamera == vehicleCamera)
                _ZN13VehicleCamera14updatePositionEfRKN3irr4core8vector3dIfEEfRS3_S6_ff(vehicleCamera,
                    elapsed, target->GetPosition(),
                    currentCamera->getPosition().getDistanceFrom(target->GetPosition()),
                    up, side, 80.0f, 45.0f);
        }
        {
        float shakeY = 0.0f, shakeZ = 0.0f;
        float shakeX = 0.0f;
        float* const shakeXView = &shakeX;
        float* shakeYPointer = &shakeY;
        float* const* const shakeYView = &shakeYPointer;
        if (Explosion::s_cameraShakeTimer > 0.0f) {
            Explosion::s_cameraShakeTimer -= elapsed * 1000.0f;
            if (Explosion::s_cameraShakeTimer < 0.0f)
                Explosion::s_cameraShakeTimer = 0.0f;
            const float amount = 100.0f * Explosion::s_cameraShakeTimer / 1000.0f;
            const int x = lrand48();
            const int y = lrand48();
            const int z = lrand48();
            const float fx = (x % 100) / 100.0f;
            const float fy = (y % 100) / 100.0f;
            const float fz = (z % 100) / 100.0f;
            *shakeXView = amount * fx;
            **shakeYView = amount * fy;
            shakeZ = amount * fz;
        }
        cameraNode->setPosition(currentCamera->getPosition() + irr::core::vector3d<float>(*shakeXView, **shakeYView, shakeZ));
        if (flag154 || flag155) {
            const irr::core::vector3d<float> axis(0.0f, 0.0f, 1.0f);
            if (currentCamera == followCamera)
                static_cast<Character*>(target)->setCameraOffset(
                    axis.crossProduct(_ZNK12FollowCamera9getFacingEv(followCamera)));
            flag155 = false;
        }
        cameraNode->setTarget(currentCamera->getLookAt() + irr::core::vector3d<float>(*shakeXView, **shakeYView, shakeZ));
        }
    }
    cameraNode->updateAbsolutePosition(false);
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
