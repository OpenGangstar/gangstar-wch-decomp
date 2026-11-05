/*
 * CSoundDecoderMSWAV
 *
 * Original file: CSoundDecoderMSWAV.cpp
 * Area:          audio
 *
 * This file mirrors the layout of the retail build.  Add the decompiled
 * functions of CSoundDecoderMSWAV.cpp here, in the order they appear in the library.
 */

#include "CSoundDecoderMSADPCM.h"
#include "CSoundDecoderPCM.h"
#include "../core/NativeStdio.h"

static const char wavReadMode[] __attribute__((section(".rodata.wav_read_mode"))) = "rb";
static const char unknownWavFormat[] __attribute__((section(".rodata.wav_unknown_format"))) =
    "CSoundDecoderMSWAV::CSoundDecoderMSWAV: asked to decompess unknown format: %i\n";

class CSoundDecoderMSWAV : public ISoundDecoder {
public:
    CSoundDecoderMSWAV();
    CSoundDecoderMSWAV(const char* filename);
    virtual ~CSoundDecoderMSWAV();
    void Init(const char* filename);
    void UnInit();
    static void InitStaticParameters(CPcmPool* pcmPool, CMSAdpcmPool* adpcmPool);
    virtual int Decode(short* output, int count, bool loop);
    virtual void GoTo(int position);
    virtual int GetNumSamplesPerDecode(int count);
    virtual int GetSamplingRate() const __attribute__((weak));
    virtual int GetChannel() const __attribute__((weak));
    virtual int GetPCMSize() const __attribute__((weak));
    virtual int GetNbEffectiveSamples() const __attribute__((weak));
    virtual int GetTotalSamples() const __attribute__((weak));
    virtual bool HasMoreData() const __attribute__((weak));

private:
    ISoundDecoder* decoder;
    NativeFile* file;
    RiffHeader riff;
    FormatHeader format;

    static CPcmPool* s_msPcmPool;
    static CMSAdpcmPool* s_msAdpcmPool;
};

int CSoundDecoderMSWAV::GetSamplingRate() const { return decoder->GetSamplingRate(); }
int CSoundDecoderMSWAV::GetChannel() const { return decoder->GetChannel(); }
int CSoundDecoderMSWAV::GetPCMSize() const { return decoder->GetPCMSize(); }
int CSoundDecoderMSWAV::GetNbEffectiveSamples() const { return decoder->GetNbEffectiveSamples(); }
int CSoundDecoderMSWAV::GetTotalSamples() const { return decoder->GetTotalSamples(); }
bool CSoundDecoderMSWAV::HasMoreData() const { return decoder->HasMoreData(); }

CSoundDecoderMSWAV::CSoundDecoderMSWAV()
    : file(0), riff(), format()
{
}

CPcmPool* CSoundDecoderMSWAV::s_msPcmPool;
CMSAdpcmPool* CSoundDecoderMSWAV::s_msAdpcmPool;

void CSoundDecoderMSWAV::InitStaticParameters(CPcmPool* pcmPool, CMSAdpcmPool* adpcmPool)
{
    s_msPcmPool = pcmPool;
    s_msAdpcmPool = adpcmPool;
}

int CSoundDecoderMSWAV::Decode(short* output, int count, bool loop)
{
    return decoder->Decode(output, count, loop);
}

void CSoundDecoderMSWAV::GoTo(int position) { decoder->GoTo(position); }
int CSoundDecoderMSWAV::GetNumSamplesPerDecode(int count) { return decoder->GetNumSamplesPerDecode(count); }

class CMSWavPool {
public:
    CMSWavPool(int capacity, int initialCount);
    ~CMSWavPool();
    CSoundDecoderMSWAV* GetMSWAVDecoder(const char* filename);
    void ReleaseMSWAVDecoder(CSoundDecoderMSWAV* decoder);

private:
    CSoundDecoderMSWAV** slots;
    int capacity;
    int initialCount;
    int firstFree;
    int lastUsed;
    int* state;
};

CMSWavPool::~CMSWavPool()
{
    for (int i = 0; i < capacity; ++i)
        delete slots[i];
    delete[] slots;
    slots = 0;
    delete[] state;
}

CMSWavPool::CMSWavPool(int maxCount, int preallocate)
    : capacity(maxCount), initialCount(preallocate)
{
    slots = new CSoundDecoderMSWAV*[maxCount];
    state = new int[maxCount];
    int i = 0;
    for (; i < preallocate; ++i) {
        state[i] = 0;
        slots[i] = new CSoundDecoderMSWAV;
    }
    for (int i = preallocate; i < maxCount; ++i) {
        state[i] = -1;
        slots[i] = 0;
    }
    firstFree = 0;
    lastUsed = -1;
}

void CSoundDecoderMSWAV::UnInit()
{
    if (format.tag == 17)
        s_msAdpcmPool->ReleaseMSADPCMDecoder(static_cast<CSoundDecoderMSADPCM*>(decoder));
    else if (format.tag == 1)
        s_msPcmPool->ReleasePCMDecoder(static_cast<CSoundDecoderPCM*>(decoder));
    if (file)
        fclose(file);
}

void CMSWavPool::ReleaseMSWAVDecoder(CSoundDecoderMSWAV* data)
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

void CSoundDecoderMSWAV::Init(const char* filename)
{
    file = fopen(filename, wavReadMode);
    fread(&riff, sizeof(riff), 1, file);
    fread(&format, sizeof(format), 1, file);
    switch (format.tag) {
    case 1:
        decoder = s_msPcmPool->GetPCMDecoder(reinterpret_cast<__sFILE*>(file), &riff, &format);
        break;
    case 17:
        decoder = s_msAdpcmPool->GetMSADPCMDecoder(reinterpret_cast<__sFILE*>(file), &riff, &format);
        break;
    default:
        printf(unknownWavFormat, format.tag);
    }
}

CSoundDecoderMSWAV* CMSWavPool::GetMSWAVDecoder(const char* filename)
{
    if (firstFree >= capacity)
        return 0;
    if (state[firstFree] == -1)
        slots[firstFree] = new CSoundDecoderMSWAV;
    CSoundDecoderMSWAV* data = slots[firstFree];
    state[firstFree] = 1;
    if (firstFree > lastUsed)
        lastUsed = firstFree;
    int i = firstFree + 1;
    while (i < capacity && state[i] == 1)
        ++i;
    firstFree = i;
    data->Init(filename);
    return data;
}

CSoundDecoderMSWAV::CSoundDecoderMSWAV(const char* filename)
    : file(0), riff(), format()
{
    file = fopen(filename, wavReadMode);
    fread(&riff, sizeof(riff), 1, file);
    fread(&format, sizeof(format), 1, file);
    switch (format.tag) {
    case 1:
        decoder = new CSoundDecoderPCM(reinterpret_cast<__sFILE*>(file), &riff, &format);
        break;
    case 17:
        decoder = new CSoundDecoderMSADPCM(reinterpret_cast<__sFILE*>(file), &riff, &format);
        break;
    default:
        printf(unknownWavFormat, format.tag);
    }
}

CSoundDecoderMSWAV::~CSoundDecoderMSWAV()
{
    if (file)
        fclose(file);
}
