/*
 * SoundManager
 *
 * Original file: SoundManager.cpp
 * Area:          audio
 *
 * This file mirrors the layout of the retail build.  Add the decompiled
 * functions of SoundManager.cpp here, in the order they appear in the library.
 */

// Recovered translation-unit SDK startup callbacks.
#include "SoundManager.h"
#include "../app/NativeMedia.h"
#include "../core/LocalSdkStartupStorage.h"
#include "../core/LocalStartupText.h"

void SoundManager::init()
{
    if (!(flags & 2))
        flags |= 2;
}

void SoundManager::unInit() {}
void SoundManager::useIPodRadio() {}
void SoundManager::useBuiltInRadio() { flags &= ~32u; }
bool SoundManager::canUseIPod() const { return false; }
void SoundManager::initIPod() {}
void SoundManager::cleanupIPod() {}
bool SoundManager::iPodIsInitialized() const { return false; }
int SoundManager::getPlaylistCount() const { return -1; }
void SoundManager::getPlaylistName(int, char*) const {}
int SoundManager::getPlaylistIndexFromString(const char*) const { return -1; }
int SoundManager::getCurPlaylist() const { return -1; }
void SoundManager::setPlaylist(int) {}
void SoundManager::setListenerPos(const irr::core::vector3d<float>&,
                                  const irr::core::vector3d<float>&,
                                  const irr::core::vector3d<float>&) {}
int SoundManager::_getSoundId(int resourceId) { return resourceId - resourceIdBase; }
int SoundManager::_getResId(int soundId) { return soundId + resourceIdBase; }
int SoundManager::_getSoundType(int soundId) { return soundEntries[soundId].type; }
void SoundManager::disableMusic() { flags |= 256; }
void SoundManager::enableMusic() { flags &= ~256u; }
int SoundManager::getNumRadioStations() const { return radioStationCount; }

extern "C" {
void nativeSetVolumeBig(int id, float volume);
void nativeStopSoundBig(int id);
void nativeResumeSoundBig(int id);
void nativePauseSoundBig(int id);
}

void SoundManager::setVolume(int id, int, float volume)
{
    if (flags & 2)
        nativeSetVolumeBig(id, volume);
}

void SoundManager::stopAllMusic()
{
    if (flags & 2)
        nativeStopAllSounds();
}

void SoundManager::stopAllSounds()
{
    if (flags & 2)
        nativeStopAllSounds();
}

void SoundManager::pauseAllSounds()
{
    if (flags & 2) {
        flags |= 128;
        nativeStopAllSounds();
    }
}

void SoundManager::stopLowFpsMusic()
{
    if (flags & 2)
        nativeStopAllSounds();
}

void SoundManager::stop(int id, int, int)
{
    if (flags & 2)
        nativeStopSoundBig(id);
}

void SoundManager::resume(int id)
{
    if (flags & 2)
        nativeResumeSoundBig(id);
}

void SoundManager::pause(int id)
{
    if (flags & 2)
        nativePauseSoundBig(id);
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
static void _GLOBAL__I__ZN12SoundManager15s_soundsPlayingE() __attribute__((used));
static void _GLOBAL__I__ZN12SoundManager15s_soundsPlayingE()
{
    __static_initialization_and_destruction_0(1, 65535);
}
}

extern "C" {
static void __tcf_2()
{
    irr::scene::quake3::LocalStringStorage& value = irr::scene::quake3::irrEmptyStringc;
    if (!value.reference && value.array && value.array != value.inlineBuffer)
        ::operator delete(value.array);
}
}
