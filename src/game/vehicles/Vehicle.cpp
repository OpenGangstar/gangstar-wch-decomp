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
