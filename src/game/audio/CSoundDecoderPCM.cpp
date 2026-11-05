/*
 * CSoundDecoderPCM
 *
 * Original file: CSoundDecoderPCM.cpp
 * Area:          audio
 *
 * This file mirrors the layout of the retail build.  Add the decompiled
 * functions of CSoundDecoderPCM.cpp here, in the order they appear in the library.
 */

#include "ISoundDecoder.h"
#include "../core/NativeStdio.h"

struct __sFILE;
struct RiffHeader;

struct FormatHeader {
    char id[4];
    unsigned int size;
    unsigned short tag;
    unsigned short channels;
    unsigned int sampleRate;
    unsigned int bytesPerSecond;
    unsigned short blockAlignment;
    unsigned short bitsPerSample;
};

class CSoundDecoderPCM : public ISoundDecoder {
public:
    CSoundDecoderPCM();
    CSoundDecoderPCM(__sFILE* input, RiffHeader* riff, FormatHeader* format);
    virtual ~CSoundDecoderPCM();
    void Init(__sFILE* stream, RiffHeader* riffHeader, FormatHeader* formatHeader);
    void UnInit();
    virtual int Decode(short* output, int count, bool loop);
    virtual void GoTo(int position);
    virtual int GetSamplingRate() const __attribute__((weak));
    virtual int GetChannel() const __attribute__((weak));
    virtual int GetPCMSize() const __attribute__((weak));
    virtual int GetNbEffectiveSamples() const __attribute__((weak));
    virtual int GetTotalSamples() const __attribute__((weak));
    virtual bool HasMoreData() const __attribute__((weak));

private:
    __sFILE* stream;
    RiffHeader* riffHeader;
    FormatHeader* formatHeader;
    struct {
        char id[4];
        unsigned int size;
    } data;
    unsigned int position;
};

int CSoundDecoderPCM::GetSamplingRate() const { return formatHeader->sampleRate; }
int CSoundDecoderPCM::GetChannel() const { return formatHeader->channels; }
int CSoundDecoderPCM::GetPCMSize() const { return data.size; }
int CSoundDecoderPCM::GetNbEffectiveSamples() const { return data.size / formatHeader->blockAlignment; }
int CSoundDecoderPCM::GetTotalSamples() const { return data.size / formatHeader->blockAlignment; }
bool CSoundDecoderPCM::HasMoreData() const { return position < data.size; }

CSoundDecoderPCM::CSoundDecoderPCM() : data(), position(0)
{
    riffHeader = 0;
    formatHeader = 0;
    stream = 0;
}

void CSoundDecoderPCM::UnInit() {}

class CPcmPool {
public:
    CPcmPool(int capacity, int initialCount);
    ~CPcmPool();
    CSoundDecoderPCM* GetPCMDecoder(__sFILE* stream, RiffHeader* riffHeader, FormatHeader* formatHeader);
    void ReleasePCMDecoder(CSoundDecoderPCM* decoder);

private:
    CSoundDecoderPCM** slots;
    int capacity;
    int initialCount;
    int firstFree;
    int lastUsed;
    int* state;
};

CPcmPool::~CPcmPool()
{
    for (int i = 0; i < capacity; ++i)
        delete slots[i];
    delete[] slots;
    slots = 0;
    delete[] state;
}

CPcmPool::CPcmPool(int maxCount, int preallocate)
    : capacity(maxCount), initialCount(preallocate)
{
    slots = new CSoundDecoderPCM*[maxCount];
    state = new int[maxCount];
    int i = 0;
    for (; i < preallocate; ++i) {
        state[i] = 0;
        slots[i] = new CSoundDecoderPCM;
    }
    for (int i = preallocate; i < maxCount; ++i) {
        state[i] = -1;
        slots[i] = 0;
    }
    firstFree = 0;
    lastUsed = -1;
}

void CPcmPool::ReleasePCMDecoder(CSoundDecoderPCM* data)
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

void CSoundDecoderPCM::GoTo(int)
{
    fseek(reinterpret_cast<NativeFile*>(stream), 44, 0);
    position = 0;
}

int CSoundDecoderPCM::Decode(short* output, int count, bool loop)
{
    unsigned int offset = position;
    unsigned int bytes = count * formatHeader->blockAlignment;
    if (offset + bytes >= data.size)
        bytes = data.size - offset;
    unsigned int read = fread(output, 1, bytes, reinterpret_cast<NativeFile*>(stream));
    position += read;
    unsigned int alignment = formatHeader->blockAlignment;
    if (loop && position >= data.size)
        GoTo(0);
    return read / alignment;
}

void CSoundDecoderPCM::Init(__sFILE* input, RiffHeader* riff, FormatHeader* format)
{
    stream = input;
    position = 0;
    riffHeader = riff;
    formatHeader = format;
    fread(&data, sizeof(data), 1, reinterpret_cast<NativeFile*>(input));
}

CSoundDecoderPCM* CPcmPool::GetPCMDecoder(__sFILE* stream, RiffHeader* riffHeader, FormatHeader* formatHeader)
{
    if (firstFree >= capacity)
        return 0;
    if (state[firstFree] == -1)
        slots[firstFree] = new CSoundDecoderPCM;
    CSoundDecoderPCM* data = slots[firstFree];
    state[firstFree] = 1;
    if (firstFree > lastUsed)
        lastUsed = firstFree;
    int i = firstFree + 1;
    while (i < capacity && state[i] == 1)
        ++i;
    firstFree = i;
    data->Init(stream, riffHeader, formatHeader);
    return data;
}

CSoundDecoderPCM::CSoundDecoderPCM(__sFILE* input, RiffHeader* riff, FormatHeader* format)
    : stream(input), riffHeader(riff), formatHeader(format), data(), position(0)
{
    fread(&data, sizeof(data), 1, reinterpret_cast<NativeFile*>(input));
}

CSoundDecoderPCM::~CSoundDecoderPCM() {}
