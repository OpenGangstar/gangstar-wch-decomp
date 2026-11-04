/*
 * CSound
 *
 * Original file: CSound.cpp
 * Area:          audio
 *
 * This file mirrors the layout of the retail build.  Add the decompiled
 * functions of CSound.cpp here, in the order they appear in the library.
 */

#include "CSound.h"
#include "SoundManager.h"

ALSourcesPool* CSound::s_pALSourcesPool;

CSound::CSound() {}

CSound::CSound(CSoundData* soundData)
    : data(soundData), unknown8(false), unknown9(true), status(4),
      unknown20(0), unknown24(0), unknown28(0), fadeActive(0),
      fadeRemaining(0), fadeDuration(0), unknown44(0)
{
}

void CSound::Init(CSoundData*) {}
void CSound::InitALSource() {}
void CSound::InitStaticParameters(ALSourcesPool* pool) { s_pALSourcesPool = pool; }
void CSound::UnInit() {}
int CSound::GetStatus() const { return status; }
void CSound::Play(bool, float, int) {}
void CSound::Stop(int) {}
void CSound::Pause() {}
void CSound::Resume() {}
void CSound::SetPosition(const irr::core::vector3d<float>&) {}
void CSound::Update(int) {}
void CSound::_performFade(int) {}
void CSound::QueueStreamBuffer(char*, int, int) {}
int CSound::GetProcessedBuffer() { return 0; }
void CSound::SetVolume(float) {}
void CSound::SetPitch(float) {}
CSoundData* CSound::GetSoundData() { return data; }

ALSourcesPool::ALSourcesPool(int, int) {}
ALSourcesPool::~ALSourcesPool() {}

CSound::~CSound() {}

float CSound::GetAbsoluteVolume() const
{
    float gain = volume * SoundManager::getInstance()->sfxVolume;
    if (fadeActive)
        gain = (float)fadeRemaining * gain / (float)fadeDuration;
    return gain;
}

// Recovered translation-unit SDK startup callbacks.
#include "../core/LocalSdkStartupStorage.h"
#include "../core/LocalStartupText.h"

void operator delete(void*) throw();
extern "C" {
static void __tcf_2() __attribute__((used));
}

extern void* __dso_handle;
extern "C" {
int __aeabi_atexit(void*, void (*)(void*), void*);
void* _ZN3irr4core6stringIcNS0_12irrAllocatorIcEEEaSIcEERS4_PKT_(void*, const char*) __attribute__((weak));
}

extern "C" {
static void __tcf_2()
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
        __aeabi_atexit(0, reinterpret_cast<void (*)(void*)>(__tcf_2), &__dso_handle);
        new (irr::ps::vHalf) irr::ps::LocalVector3(0.5f, 0.5f, 0.5f);
    }
}

extern "C" {
static void _GLOBAL__I__ZN6CSound16s_pALSourcesPoolE() __attribute__((used));
static void _GLOBAL__I__ZN6CSound16s_pALSourcesPoolE()
{
    __static_initialization_and_destruction_0(1, 65535);
}
}
