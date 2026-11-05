/*
 * StaticSound
 *
 * Original file: StaticSound.cpp
 * Area:          audio
 *
 * This file mirrors the layout of the retail build.  Add the decompiled
 * functions of StaticSound.cpp here, in the order they appear in the library.
 */

#include "CSound.h"

class StaticSound : public CSound {
public:
    StaticSound();
    StaticSound(CSoundData* soundData);
    virtual ~StaticSound();
    virtual void Stop(int fade);
    void Init(CSoundData* soundData);
    void UnInit();
};

void StaticSound::Stop(int fade) { CSound::Stop(fade); }
void StaticSound::UnInit() { CSound::UnInit(); }
void StaticSound::Init(CSoundData* soundData) { CSound::Init(soundData); }
StaticSound::~StaticSound() {}
StaticSound::StaticSound(CSoundData* soundData) : CSound(soundData) {}
StaticSound::StaticSound() {}

class CStaticSoundsPool {
public:
    CStaticSoundsPool(int capacity, int initialCount);
    ~CStaticSoundsPool();
    StaticSound* GetStaticSound(CSoundData* data);
    void ReleaseStaticSound(StaticSound* decoder);

private:
    StaticSound** slots;
    int capacity;
    int initialCount;
    int firstFree;
    int lastUsed;
    int* state;
};


CStaticSoundsPool::~CStaticSoundsPool()
{
    for (int i = 0; i < capacity; ++i)
        delete slots[i];
    delete[] slots;
    slots = 0;
    delete[] state;
}

CStaticSoundsPool::CStaticSoundsPool(int maxCount, int preallocate)
    : capacity(maxCount), initialCount(preallocate)
{
    slots = new StaticSound*[maxCount];
    state = new int[maxCount];
    int i = 0;
    for (; i < preallocate; ++i) {
        state[i] = 0;
        slots[i] = new StaticSound;
    }
    for (int i = preallocate; i < maxCount; ++i) {
        state[i] = -1;
        slots[i] = 0;
    }
    firstFree = 0;
    lastUsed = -1;
}

void CStaticSoundsPool::ReleaseStaticSound(StaticSound* data)
{
    if (!data)
        return;
    data->UnInit();
    int index = -1;
    for (int i = 0; i <= lastUsed && index < 0; ++i)
        if (slots[i] == data)
            index = i;
    if (index < 0)
        return;
    if (firstFree > index)
        firstFree = index;
    if (index == lastUsed) {
        --lastUsed;
        while (lastUsed >= 0 && state[lastUsed] != 1)
            --lastUsed;
    }
    state[index] = 0;
}

StaticSound* CStaticSoundsPool::GetStaticSound(CSoundData* soundData)
{
    if (firstFree >= capacity)
        return 0;
    if (state[firstFree] == -1)
        slots[firstFree] = new StaticSound;
    StaticSound* data = slots[firstFree];
    state[firstFree] = 1;
    if (firstFree > lastUsed)
        lastUsed = firstFree;
    int i = firstFree + 1;
    while (i < capacity && state[i] == 1)
        ++i;
    firstFree = i;
    data->Init(soundData);
    return data;
}

// Recovered translation-unit SDK string startup callbacks.
#include "../core/LocalStringStartupStorage.h"
#include "../core/LocalStartupText.h"

void operator delete(void*) throw();
extern "C" {
static void __tcf_0() __attribute__((used));
}

extern void* __dso_handle;
extern "C" {
int __aeabi_atexit(void*, void (*)(void*), void*);
void* _ZN3irr4core6stringIcNS0_12irrAllocatorIcEEEaSIcEERS4_PKT_(void*, const char*) __attribute__((weak));
}

extern "C" {
static void __tcf_0()
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
        __aeabi_atexit(0, reinterpret_cast<void (*)(void*)>(__tcf_0), &__dso_handle);
    }
}

extern "C" {
static void _GLOBAL__I__ZN11StaticSoundC2Ev() __attribute__((used));
static void _GLOBAL__I__ZN11StaticSoundC2Ev()
{
    __static_initialization_and_destruction_0(1, 65535);
}
}
