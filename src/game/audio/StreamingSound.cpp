/*
 * StreamingSound
 *
 * Original file: StreamingSound.cpp
 * Area:          audio
 *
 * This file mirrors the layout of the retail build.  Add the decompiled
 * functions of StreamingSound.cpp here, in the order they appear in the library.
 */

#include "CSound.h"
#include "ISoundDecoder.h"

class CSoundBuffers;
class CMSWavPool;

class StreamingSound : public CSound {
public:
    StreamingSound(int bufferSize);
    virtual ~StreamingSound();
    virtual void Play(bool loop, float volume, int fade);
    virtual void Update(int elapsed);
    static void InitStaticParameters(CSoundBuffers* buffers, CMSWavPool* wavPool);
    void SaturateBuffersAndFlush();
    void Init(CSoundData* soundData);
    void UnInit();

private:
    ISoundDecoder* decoder;
    int bufferSize;
    char* buffers[5];
    int bufferLengths[5];
    unsigned int flags;
    int queuedBuffers;
    int ownedBuffers;
    static CSoundBuffers* s_pBuffersPool;
    static CMSWavPool* s_pMsWavPool;
};

CSoundBuffers* StreamingSound::s_pBuffersPool;
CMSWavPool* StreamingSound::s_pMsWavPool;

void StreamingSound::InitStaticParameters(CSoundBuffers* buffers, CMSWavPool* wavPool)
{
    s_pBuffersPool = buffers;
    s_pMsWavPool = wavPool;
}

void StreamingSound::SaturateBuffersAndFlush() {}
void StreamingSound::Update(int) {}

StreamingSound::StreamingSound(int size)
    : decoder(0), bufferSize(size), flags(0), queuedBuffers(0), ownedBuffers(0)
{
    if (!s_pBuffersPool)
        for (int i = 0; i < 5; ++i)
            buffers[i] = new char[bufferSize];
}

class CStreamingPool {
public:
    CStreamingPool(int capacity, int initialCount);
    ~CStreamingPool();
    StreamingSound* GetStreamingSound(CSoundData* data);
    void ReleaseStreamingSound(StreamingSound* decoder);

private:
    StreamingSound** slots;
    int capacity;
    int initialCount;
    int firstFree;
    int lastUsed;
    int* state;
};


CStreamingPool::~CStreamingPool()
{
    for (int i = 0; i < capacity; ++i)
        delete slots[i];
    delete[] slots;
    slots = 0;
    delete[] state;
}

CStreamingPool::CStreamingPool(int maxCount, int preallocate)
    : capacity(maxCount), initialCount(preallocate)
{
    slots = new StreamingSound*[maxCount];
    state = new int[maxCount];
    int i = 0;
    for (; i < preallocate; ++i) {
        state[i] = 0;
        slots[i] = new StreamingSound(32656);
    }
    for (int i = preallocate; i < maxCount; ++i) {
        state[i] = -1;
        slots[i] = 0;
    }
    firstFree = 0;
    lastUsed = -1;
}

void CStreamingPool::ReleaseStreamingSound(StreamingSound* data)
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

StreamingSound* CStreamingPool::GetStreamingSound(CSoundData* soundData)
{
    if (firstFree >= capacity)
        return 0;
    if (state[firstFree] == -1)
        slots[firstFree] = new StreamingSound(32656);
    StreamingSound* data = slots[firstFree];
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
static void _GLOBAL__I__ZN14StreamingSound14s_pBuffersPoolE() __attribute__((used));
static void _GLOBAL__I__ZN14StreamingSound14s_pBuffersPoolE()
{
    __static_initialization_and_destruction_0(1, 65535);
}
}
