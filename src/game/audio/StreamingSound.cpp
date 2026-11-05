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
#include "CSoundData.h"
#include "CSoundDecoderADPCM.h"
#include "CSoundDecoderMSWAV.h"
#include "SoundBuffersPool.h"
#include "../core/NativeStdio.h"
#include "../persistence/FileManager.h"

extern "C" const char* _ZN11FileManager10GetDvdNameEPKc(const char* name) __attribute__((weak));

class StreamingSound : public CSound {
public:
    StreamingSound(int bufferSize);
    StreamingSound(CSoundData* soundData, int decodeRate);
    virtual ~StreamingSound();
    virtual void Play(bool loop, float volume, int fade);
    virtual void Update(int elapsed);
    static void InitStaticParameters(CSoundBuffers* buffers, CMSWavPool* wavPool);
    void SaturateBuffersAndFlush();
    void Init(CSoundData* soundData);
    void UnInit();
    void Flush(int buffer);
    bool UpdateDecoding();
    void _SaturateAndFlushLite();

private:
    ISoundDecoder* decoder;
    int bufferSize;
    char* buffers[5];
    int bufferIndex;
    int samplesPerDecode;
    int decodesPerBuffer;
    int decodedChunks;
    int decodedSamples;
    unsigned int flags;
    int streamState;
    int localBufferCount;
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

void StreamingSound::Play(bool loop, float volume, int fade)
{
    if (status == 2) {
        status = 3;
    } else {
        decoder->GoTo(0);
        SaturateBuffersAndFlush();
        CSound::Play(false, volume, fade);
        if (loop)
            flags |= 1;
        else
            flags &= ~1u;
    }
}

StreamingSound::StreamingSound(int size)
    : decoder(0), bufferSize(size), flags(0), streamState(0), localBufferCount(0)
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

void StreamingSound::UnInit()
{
    if (s_pBuffersPool)
        for (int i = 0; i < 5; ++i)
            s_pBuffersPool->ReleaseSoundBuffer(buffers[i]);

    if (data->format & 0x20000)
        delete decoder;
    else if (data->format & 0x40000)
        s_pMsWavPool->ReleaseMSWAVDecoder(static_cast<CSoundDecoderMSWAV*>(decoder));

    CSound::UnInit();
    flags = 0;
}

StreamingSound::~StreamingSound()
{
    if (!s_pBuffersPool)
        for (int i = 0; i < 5; ++i)
            delete[] buffers[i];

    if (data) {
        if (data->format & 0x20000)
            delete decoder;
        if (localBufferCount)
            for (int i = 0; i < 5; ++i)
                delete[] buffers[i];
    }
}

void StreamingSound::Flush(int buffer)
{
    QueueStreamBuffer(buffers[bufferIndex], buffer, decodedSamples * data->size * 2);
    decodedChunks = 0;
    decodedSamples = 0;
    bufferIndex = (bufferIndex + 1) % 5;
}

bool StreamingSound::UpdateDecoding()
{
    if (decodedChunks < decodesPerBuffer) {
        int samples = decodedSamples;
        int offset = data->size * samples * 2;
        int count = decoder->Decode(reinterpret_cast<short*>(buffers[bufferIndex] + offset),
                                    samplesPerDecode, flags & 1);
        decodedSamples = samples + count;
        ++decodedChunks;
    }
    return decodedChunks >= decodesPerBuffer;
}

void StreamingSound::_SaturateAndFlushLite()
{
    char silence[32656];
    memset(silence, 0, sizeof(silence));
    for (int i = 0; i < 3; ++i)
        QueueStreamBuffer(silence, i, sizeof(silence));
    decodedChunks = 0;
    decodedSamples = 0;
    while (!UpdateDecoding()) {}
    Flush(3);
}

StreamingSound::StreamingSound(CSoundData* soundData, int decodeRate)
    : CSound(soundData), decoder(0), bufferSize(0), bufferIndex(0), flags(0),
      streamState(0), localBufferCount(decodeRate)
{
    const char* name = _ZN11FileManager10GetDvdNameEPKc(FileManager::s_mgr->_GetName(data->sampleRate));
    if (soundData->format & 0x20000)
        decoder = new CSoundDecoderADPCM(name);
    else if (soundData->format & 0x40000)
        decoder = new CSoundDecoderMSWAV(name);

    samplesPerDecode = data->channels / (localBufferCount ? localBufferCount : 22);
    samplesPerDecode = decoder->GetNumSamplesPerDecode(samplesPerDecode);
    decodesPerBuffer = 4;
    bufferSize = samplesPerDecode * data->size * 8;
    for (int i = 0; i < 5; ++i)
        buffers[i] = new char[bufferSize];
    status = 4;
}

void StreamingSound::Init(CSoundData* soundData)
{
    CSound::Init(soundData);
    bufferIndex = 0;
    decoder = 0;
    flags = 0;
    streamState = 0;
    const char* name = _ZN11FileManager10GetDvdNameEPKc(FileManager::s_mgr->_GetName(data->sampleRate));
    if (soundData->format & 0x20000)
        decoder = new CSoundDecoderADPCM(name);
    else if (soundData->format & 0x40000)
        decoder = s_pMsWavPool->GetMSWAVDecoder(name);

    samplesPerDecode = data->channels / 22;
    samplesPerDecode = decoder->GetNumSamplesPerDecode(samplesPerDecode);
    decodesPerBuffer = 4;
    if (s_pBuffersPool)
        for (int i = 0; i < 5; ++i)
            buffers[i] = s_pBuffersPool->GetSoundBuffer();
    status = 4;
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
