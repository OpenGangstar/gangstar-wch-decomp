/*
 * FPSCamera
 *
 * Original file: FPSCamera.cpp
 * Area:          core
 *
 * This file mirrors the layout of the retail build.  Add the decompiled
 * functions of FPSCamera.cpp here, in the order they appear in the library.
 */

// Recovered translation-unit SDK and AI startup callbacks.
#include "../core/LocalStartupStorage.h"
#include "../core/LocalStartupText.h"
#include "../core/CameraVariants.h"
#include "Point2D.h"
#include "CameraManager.h"
#include "Quaternion.h"
#include "../app/Application.h"
#include "../characters/PlayerTest.h"
#include "../hud/CHudManager.h"
#include "../input/CControlManager.h"
#include "../world/LevelObject.h"

static inline PlayerTest* getSceneOwner(SavePositionInterface* owner)
{
    PlayerTest* player = 0;
    if (owner)
        player = static_cast<PlayerTest*>(owner);
    return player;
}

void FPSCamera::incVerticalAngle(float delta)
{
    if ((delta > 0.0f && verticalAngle < 30.0f) ||
        (delta < 0.0f && verticalAngle > -55.0f))
        verticalAngle = delta + verticalAngle;
}

void FPSCamera::debug(irr::video::IVideoDriver*)
{
}

void FPSCamera::zoom(int degrees)
{
    if (degrees >= 6 && degrees <= 50)
        CameraManager::getInstance()->setFOV(degrees);
}

void FPSCamera::enter()
{
    if (flag60)
        return;
    Application* app = Application::GetInstance();
    app->GetHudManager()->sniping();
    flag60 = true;
    static_cast<PlayerTest*>(owner)->_SetTarget(0, false);
    static_cast<PlayerTest*>(owner)->hideMesh();
    getSceneOwner(owner)->sceneNode->setVisible(false);
    app->GetControlManager()->unlock();
    verticalAngle = 0.0f;
}

FPSCamera::~FPSCamera()
{
}

void FPSCamera::init(LevelObject* object, int)
{
    owner = reinterpret_cast<SavePositionInterface*>(object);
    if (object) {
        const irr::core::vector3d<float> origin = object->GetPosition();
        const irr::core::matrix4& matrix =
            reinterpret_cast<LevelObject*>(owner)->sceneNode->getAbsoluteTransformation();
        const irr::core::vector3d<float> up(matrix[8], matrix[9], matrix[10]);
        setPosition(up * 75.0f + origin);
        const irr::core::vector3d<float> eyeTarget = reinterpret_cast<LevelObject*>(owner)->GetPosition();
        const irr::core::vector3d<float> front = reinterpret_cast<LevelObject*>(owner)->GetFront();
        setLookAt(front * 300.0f + eyeTarget);
    }
    flag60 = false;
}

void FPSCamera::exit()
{
    Application::GetInstance()->GetControlManager()->exitSniping(false);
    flag60 = false;
    static_cast<PlayerTest*>(owner)->showMesh();
    getSceneOwner(owner)->sceneNode->setVisible(true);
    CameraManager::getInstance()->setFOV(50);
}

FPSCamera::FPSCamera()
    : value36(0), value40(0), value44(0), value48(0),
      value52(50.0f), value56(0.1f)
{
    init(0, 0);
    verticalAngle = 0.0f;
    flag60 = false;
}

extern "C" float sqrtf(float value);

namespace {
// The retail STLport list starts with an embedded sentinel.
struct TouchPointLink {
    TouchPointLink* next;
    TouchPointLink* previous;
    Point2D<short>* point;
};

struct TouchPointListView {
    const TouchPointLink* first;
    const TouchPointLink* last;
};
}

struct FPSCameraScrollFields {
    unsigned char unknown0[44];
    int previousX;
    int previousY;
};
extern "C" void _ZN9FPSCamera6scrollERKSt4listIP7Point2DIsESaIS3_EE(FPSCamera* self, const std::list<Point2D<short>*, std::allocator<Point2D<short>*> >& points)
{
    FPSCameraScrollFields& f = *reinterpret_cast<FPSCameraScrollFields*>(self);
    const TouchPointListView& links = reinterpret_cast<const TouchPointListView&>(points);
    const Point2D<short>* point = links.first->point;
    int y, x;
    x = point->x;
    y = point->y;
    const int dx = f.previousX - x;
    const int oldY = f.previousY;
    const int horizontalFov = CameraManager::getInstance()->getFOV();
    const float verticalScale = CameraManager::getInstance()->getFOV() / 480.0f;

    using irr::core::quaternion;
    Character& player = static_cast<Character&>(*PlayerTest::GetPlayer());
    player.SetRotation(static_cast<Character&>(*PlayerTest::GetPlayer()).GetRotation()
        * quaternion(0.0f, 0.0f, (horizontalFov / 320.0f) * dx * -0.017453292f));

    const float dy = oldY - y;
    const float verticalDelta = verticalScale * dy;
    self->incVerticalAngle(-verticalDelta);
    f.previousX = x;
    f.previousY = y;
}


void FPSCamera::zoom(const std::list<Point2D<short>*, std::allocator<Point2D<short>*> >& points)
{
    const TouchPointListView& links = reinterpret_cast<const TouchPointListView&>(points);
    const Point2D<short>* first = links.first->point;
    const Point2D<short>* last = links.last->point;
    const float y = first->y - last->y;
    const float x = first->x - last->x;
    const int distance = static_cast<int>(sqrtf(x * x + y * y));
    const int difference = distance - value40;
    const int magnitude = difference < 0 ? -difference : difference;
    const float previousFov = value52;

    if (distance > value40) {
        value52 -= magnitude * value56;
        if (value52 < 6.0f)
            value52 = 6.0f;
    } else if (distance < value40) {
        value52 += magnitude * value56;
        if (value52 > 50.0f)
            value52 = 50.0f;
    }
    value40 = distance;
    if (value52 != previousFov)
        zoom(static_cast<int>(value52));
}

void FPSCamera::update(float)
{
    using irr::core::vector3d;
    updateTouchInputs();
    if (!owner)
        return;

    const vector3d<float> origin = reinterpret_cast<LevelObject*>(owner)->GetPosition();
    const irr::core::matrix4& matrix =
        reinterpret_cast<LevelObject*>(owner)->sceneNode->getAbsoluteTransformation();
    const vector3d<float> up(matrix[8], matrix[9], matrix[10]);
    setPosition(up * 75.0f + origin);

    irr::core::quaternion rotation;
    const float angle = 0.017453292f * verticalAngle;
    const vector3d<float> right = reinterpret_cast<LevelObject*>(owner)->GetRight();
    rotation.fromAngleAxis(angle, right);
    rotation.normalize();
    const vector3d<float> eyeTarget = reinterpret_cast<LevelObject*>(owner)->GetPosition();
    const vector3d<float> front = reinterpret_cast<LevelObject*>(owner)->GetFront();
    setLookAt((rotation * front) * 300.0f + eyeTarget);
}

void operator delete(void*) throw();
extern "C" {
static void __tcf_3() __attribute__((used));
}

// Scoped imports distinguish the original TU-local transition tables.
namespace retail_fpscamera_transitions {
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
        new (gameloft::ai::civ_passive) gameloft::ai::LocalTransitionList(retail_fpscamera_transitions::civPassive_trans, 75);
        new (gameloft::ai::npc_scripted) gameloft::ai::LocalTransitionList(retail_fpscamera_transitions::scriptedNpc_trans, 12);
        new (gameloft::ai::civ_agressive) gameloft::ai::LocalTransitionList(retail_fpscamera_transitions::civAggressive_trans, 57);
        new (gameloft::ai::gang_member) gameloft::ai::LocalTransitionList(retail_fpscamera_transitions::gangMember_trans, 3);
        new (gameloft::ai::cop) gameloft::ai::LocalTransitionList(retail_fpscamera_transitions::cop_trans, 78);
        new (gameloft::ai::swat) gameloft::ai::LocalTransitionList(retail_fpscamera_transitions::swat_trans, 3);
        new (gameloft::ai::civ_vehicle) gameloft::ai::LocalTransitionList(retail_fpscamera_transitions::civ_vehicle_trans, 36);
        new (gameloft::ai::cop_vehicle) gameloft::ai::LocalTransitionList(retail_fpscamera_transitions::cop_vehicle_trans, 45);
        new (gameloft::ai::guard) gameloft::ai::LocalTransitionList(retail_fpscamera_transitions::guard_trans, 42);
        new (gameloft::ai::scripted_vehicle) gameloft::ai::LocalTransitionList(retail_fpscamera_transitions::scripted_vehicle_trans, 21);
    }
}

extern "C" {
static void _GLOBAL__I__ZN9FPSCameraC2Ev() __attribute__((used));
static void _GLOBAL__I__ZN9FPSCameraC2Ev()
{
    __static_initialization_and_destruction_0(1, 65535);
}
}
