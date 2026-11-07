/*
 * Vehicle
 *
 * Original file: Vehicle.cpp
 * Area:          vehicles
 *
 * This file mirrors the layout of the retail build.  Add the decompiled
 * functions of Vehicle.cpp here, in the order they appear in the library.
 */

#include "Vehicle.h"
#include "../core/LocalStringStartupStorage.h"

void Vehicle::_shiftWeight(irr::core::vector3d<float>&, float)
{
}

const char* Vehicle::getEnterAnim() const { return enterAnim; }
const char* Vehicle::getExitAnim() const { return exitAnim; }
const char* Vehicle::getCloseDoorAnim() const { return closeDoorAnim; }

void Vehicle::toggleInterior(bool visible)
{
    interior->setVisible(visible);
}

bool Vehicle::isLeftDoor(const irr::scene::ISceneNode* door) const
{
    return leftDoor == door;
}

bool Vehicle::isDoorOpened(bool left) const
{
    return !(left ? leftDoorClosed : rightDoorClosed);
}

bool Vehicle::isDoorClosed(bool left) const
{
    return left ? leftDoorClosed : rightDoorClosed;
}

bool Vehicle::isDoorAnim(const char* name, bool left) const
{
    irr::scene::ISceneNodeAnimator* animator = left ? leftDoorAnimator : rightDoorAnimator;
    const int clip = animator->getAnimationClipIndex(name);
    return clip == animator->getTimelineCtrl()->getCurrentClipIndex();
}

void Vehicle::_notifyTargeted(bool targeted, Character* source)
{
    if (targeted)
        targetingCharacter = source;
}

const Path* Vehicle::getPathToFollow() const
{
    return pathToFollow;
}

void Vehicle::setCurrentWaypoint(int waypoint)
{
    currentWaypoint = waypoint;
}

int Vehicle::getCurrentWaypoint() const
{
    return currentWaypoint;
}

void Vehicle::loopPathToFollow(bool loop)
{
    if (loop)
        flags344 |= 0x04000000u;
    else
        flags344 &= ~0x04000000u;
}

void Vehicle::setPathToFollow(const Path* path)
{
    currentWaypoint = 0;
    pathToFollow = path;
    loopPathToFollow(false);
}

bool Vehicle::isLoopingOnPathToFollow() const
{
    return (flags344 & 0x04000000u) != 0;
}

void Vehicle::AddTurboSounds() {}
void Vehicle::Init4CylTurboSounds() {}
void Vehicle::InitSuperbikeSounds() {}
void Vehicle::InitV12LamborghiniSounds() {}

void Vehicle::setHasBeenStolen() { hasBeenStolen = true; }
bool Vehicle::getHasBeenStolen() { return hasBeenStolen; }
int Vehicle::getUniqueId() { return vehicleIndex - 12335; }

void operator delete(void*) throw();

extern "C" {
static void __tcf_4() __attribute__((used));
static void __tcf_4()
{
    irr::scene::quake3::LocalStringStorage& value = irr::scene::quake3::irrEmptyStringc;
    if (!value.reference && value.array && value.array != value.inlineBuffer)
        ::operator delete(value.array);
}
}

extern "C" {
extern unsigned char _ZZN12CGameFactory11getInstanceEvE2gf[];
extern unsigned char _ZZN11CCarFactory11getInstanceEvE2cf[];
extern unsigned char _ZZN9AIManager11getInstanceEvE3aim[];

void _ZN12CGameFactoryD1Ev(void*) __attribute__((weak));
void _ZN11CCarFactoryD1Ev(void*) __attribute__((weak));
void _ZN9AIManagerD1Ev(void*);

static void __tcf_3() __attribute__((used));
static void __tcf_3()
{
    _ZN9AIManagerD1Ev(_ZZN9AIManager11getInstanceEvE3aim);
}

static void __tcf_1() __attribute__((used));
static void __tcf_1()
{
    _ZN12CGameFactoryD1Ev(_ZZN12CGameFactory11getInstanceEvE2gf);
}

static void __tcf_2() __attribute__((used));
static void __tcf_2()
{
    _ZN11CCarFactoryD1Ev(_ZZN11CCarFactory11getInstanceEvE2cf);
}
}
