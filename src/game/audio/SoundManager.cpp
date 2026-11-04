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
#include "CSound.h"
#include "../core/Vector3.h"
#include "CSoundData.h"
#include "../app/NativeMedia.h"
#include "../core/LocalSdkStartupStorage.h"
#include "../core/LocalStartupText.h"

SoundManager* SoundManager::s_soundManager;

SoundManager* SoundManager::getInstance()
{
    if (!s_soundManager)
        s_soundManager = new SoundManager;
    return s_soundManager;
}

void SoundManager::clear()
{
    delete this;
    s_soundManager = 0;
}

void SoundManager::toggleSound()
{
    if (flags & 2)
        unInit();
    else
        init();
}

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
int SoundManager::getNumRadioStations() const { return radio.stationCount; }

extern "C" {
void nativePlaySoundBig(int id, float volume, bool loop);
void nativeSetVolumeBig(int id, float volume);
void nativeStopSoundBig(int id);
void nativeResumeSoundBig(int id);
void nativePauseSoundBig(int id);
}

void SoundManager::playLowFpsMusic(int id, bool loop)
{
    if (flags & 2)
        nativePlaySoundBig(id, playbackVolume, loop);
}

void SoundManager::pauseLowFpsMusic()
{
    if ((flags & 2) && lowFpsSound)
        lowFpsSound->Pause();
}

void SoundManager::_cleanupLowFpsMusic()
{
    if ((flags & 2) && lowFpsSound) {
        delete lowFpsSound;
        delete lowFpsData;
        lowFpsSound = 0;
    }
}

void SoundManager::setLowFpsMusicVolume(float volume)
{
    if ((flags & 2) && lowFpsSound)
        lowFpsSound->SetVolume(volume);
}

void SoundManager::resumeLowFpsMusic()
{
    if ((flags & 2) && lowFpsSound && lowFpsSound->GetStatus() == 1)
        lowFpsSound->Resume();
}

bool SoundManager::isLowFpsMusicPlaying() const
{
    if (lowFpsSound && (lowFpsSound->GetStatus() == 0 || lowFpsSound->GetStatus() == 1)) {
        lowFpsSound->GetStatus();
        return true;
    }
    return false;
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

void SoundManager::playRadio(int station)
{
    if (!(flags & 1)) {
        if (station != -1)
            radioStation = station;
        radioTrack = _getRadioTrack(radioStation);
        nativePlaySoundBig(radioTrack, playbackVolume, false);
        flags |= 1;
    }
}

void SoundManager::stopRadio()
{
    if (flags & 1) {
        stop(radioTrack, soundEntries[radioTrack].channel, 2000);
        flags &= ~1u;
    }
}

void SoundManager::changeRadioStation(int station)
{
    if (flags & 1) {
        stop(radioTrack, soundEntries[radioTrack].channel, 0);
        radioTrack = 124;
        unknown140 = true;
        playEx(124, 0, false, 1.0f, 2000, true, 1.0f, 0);
        unknown140 = false;
        radioStation = station;
    }
}

void SoundManager::lastRadioStation()
{
    if (flags & 1) {
        int station = radioStation - 1;
        if (station < 0)
            station = radio.stationCount - 1;
        changeRadioStation(station);
    }
}

void SoundManager::nextRadioStation()
{
    if (flags & 1) {
        int station = radioStation + 1;
        if (station >= radio.stationCount)
            station = 0;
        changeRadioStation(station);
    }
}

bool SoundManager::isSoundPlaying(int resourceId)
{
    if (flags & 2) {
        int soundId = _getSoundId(resourceId);
        for (int channel = 0; channel < 4; ++channel) {
            CSound* sound = soundSlots[soundId][channel];
            if (sound && static_cast<unsigned int>(sound->GetStatus()) <= 1)
                return true;
        }
    }
    return false;
}

int SoundManager::getNumberOfAllocatedSounds()
{
    int count = 0;
    for (int id = 0; id < soundCount; ++id)
        for (int channel = 0; channel < 4; ++channel)
            if (soundSlots[id][channel])
                ++count;
    return count;
}

bool SoundManager::isSoundPlaying(int resourceId, int channel)
{
    if (flags & 2) {
        int soundId = _getSoundId(resourceId);
        CSound* sound = soundSlots[soundId][channel];
        if (sound) {
            int status = sound->GetStatus();
            bool playing = false;
            if (status == 0 || status == 1)
                playing = true;
            return playing;
        }
    }
    return false;
}

void SoundManager::setPitch(int resourceId, int channel, float pitch)
{
    if (flags & 2) {
        int soundId = _getSoundId(resourceId);
        CSound* sound = soundSlots[soundId][channel];
        if (sound)
            sound->SetPitch(pitch);
    }
}

void SoundManager::setSourcePos(int resourceId, int channel,
                                const irr::core::vector3d<float>& position)
{
    if (flags & 2) {
        int soundId = _getSoundId(resourceId);
        CSound* sound = soundSlots[soundId][channel];
        if (sound)
            sound->SetPosition(position);
    }
}

namespace irr { namespace core {
template<class Scalar, class T>
vector3d<T> operator*(Scalar scalar, const vector3d<T>& vector) __attribute__((weak));
} }

irr::core::vector3d<float> SoundManager::convertVisual3DToSound3D(
    const irr::core::vector3d<float>& position)
{
    return 0.01f * position;
}

bool SoundManager::playEx(int id, const irr::core::vector3d<float>*, bool loop,
                          float volume, int, bool, float, void (*)())
{
    if (flags & 2) {
        float gain;
        if (soundEntries[id].type & 0x400000)
            gain = volume * playbackVolume;
        else
            gain = volume * effectsPlaybackVolume;
        nativePlaySoundBig(id, gain, loop);
    }
    return true;
}

void SoundManager::setPitchCallback(int id, int channel, float pitch)
{
    if (channel >= 0)
        getInstance()->setPitch(id, channel, pitch);
}

void SoundManager::setVolumeCallback(int id, int channel, float volume)
{
    if (channel >= 0) {
        SoundManager* manager = getInstance();
        float gain = volume * 0.01f * getInstance()->effectsPlaybackVolume;
        manager->setVolume(id, channel, gain);
    }
}

void SoundManager::stopSoundCallback(int id, int channel)
{
    if (channel >= 0) {
        getInstance()->setVolume(id, channel, 0.0f);
        getInstance()->stop(id, channel, 0);
    }
}

bool SoundManager::isSoundPlayingCallback(int id, int channel)
{
    if (channel >= 0)
        return getInstance()->isSoundPlaying(id, channel);
    return false;
}

int SoundManager::s_soundsPlaying;

void soundEndCallback()
{
    if (SoundManager::s_soundsPlaying > 0)
        SoundManager::getInstance()->endCutscene();
}

bool SoundManager::playSoundCallback(int id, bool loop, float volume, float pitch)
{
    SoundManager* manager = getInstance();
    float gain = volume * 0.01f * getInstance()->effectsPlaybackVolume;
    return manager->playEx(id, 0, loop, gain, 0, pitch != 0.0f, 1.0f, 0);
}

SoundManager::~SoundManager()
{
    unInit();
    delete[] soundEntries;
    for (int i = 0; i < 4; ++i)
        delete[] soundSlots[i];
    delete[] soundSlots;
    delete[] trackFrequencies;
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
