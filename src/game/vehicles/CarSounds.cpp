/*
 * CarSounds
 *
 * Original file: CarSounds.cpp
 * Area:          vehicles
 *
 * This file mirrors the layout of the retail build.  Add the decompiled
 * functions of CarSounds.cpp here, in the order they appear in the library.
 */

#include "CarSoundCallbacks.h"
#include "../core/PlacementNew.h"

bool IsSoundPlayingStub(int, int) { return false; }
int PlayStub(int, bool, float, float) { return -1; }
void StopStub(int, int) {}
void SetPitchStub(int, int, float) {}
void SetVolumeStub(int, int, float) {}

CarSoundCallbacks::CarSoundCallbacks()
    : isSoundPlaying(IsSoundPlayingStub), play(PlayStub), stop(StopStub),
      setPitch(SetPitchStub), setVolume(SetVolumeStub)
{
}

CarSoundCallbacks::~CarSoundCallbacks() {}

CarSoundCallbacks& CarSoundCallbacks::operator=(const CarSoundCallbacks& other)
{
    isSoundPlaying = other.isSoundPlaying;
    play = other.play;
    stop = other.stop;
    setPitch = other.setPitch;
    setVolume = other.setVolume;
    return *this;
}

void CarSounds::RegisterCallbacks(const CarSoundCallbacks& value)
{
    s_SoundCallbacks = value;
}

extern void* __dso_handle;
extern "C" int __aeabi_atexit(void*, void (*)(void*), void*);
extern "C" {
static void __tcf_0() __attribute__((used));
static void __tcf_0()
{
    CarSounds::s_SoundCallbacks.~CarSoundCallbacks();
}
}

static void __static_initialization_and_destruction_0(int initialize, int priority) __attribute__((used));
static void __static_initialization_and_destruction_0(int initialize, int priority)
{
    if (initialize == 1 && priority == 65535) {
        new (&CarSounds::s_SoundCallbacks) CarSoundCallbacks();
        __aeabi_atexit(0, reinterpret_cast<void (*)(void*)>(__tcf_0), &__dso_handle);
    }
}

extern "C" {
static void _GLOBAL__I__ZN18CarSoundParametersC2Ev() __attribute__((used));
static void _GLOBAL__I__ZN18CarSoundParametersC2Ev()
{
    __static_initialization_and_destruction_0(1, 65535);
}
}

void CarSounds::UnregisterCallbacks()
{
    CarSoundCallbacks callbacks;
    s_SoundCallbacks = callbacks;
}
