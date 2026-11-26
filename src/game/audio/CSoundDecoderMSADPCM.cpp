/*
 * CSoundDecoderMSADPCM
 *
 * Original file: CSoundDecoderMSADPCM.cpp
 * Area:          audio
 *
 * This file mirrors the layout of the retail build.  Add the decompiled
 * functions of CSoundDecoderMSADPCM.cpp here, in the order they appear in the library.
 */

#include "CSoundDecoderMSADPCM.h"
#include "../core/NativeStdio.h"

extern "C" short _ZN12AdpcmDecoder11DecodeAdpcmEiP10AdpcmState(int code, AdpcmState* state)
    __attribute__((weak));


int CSoundDecoderMSADPCM::GetSamplingRate() const { return formatHeader->sampleRate; }
int CSoundDecoderMSADPCM::GetChannel() const { return formatHeader->channels; }
int CSoundDecoderMSADPCM::GetPCMSize() const { return pcmSize; }
bool CSoundDecoderMSADPCM::HasMoreData() const { return !ended; }
int CSoundDecoderMSADPCM::GetNbEffectiveSamples() const { return effectiveSamples; }
int CSoundDecoderMSADPCM::GetTotalSamples() const { return fact.samples; }
void CSoundDecoderMSADPCM::UnInit() {}

int CSoundDecoderMSADPCM::GetNumSamplesPerDecode(int count)
{
    unsigned int remainder = count % samplesPerBlock;
    if (remainder)
        count = count + samplesPerBlock - remainder;
    return count;
}

CMSAdpcmPool::~CMSAdpcmPool()
{
    for (int i = 0; i < capacity; ++i)
        delete slots[i];
    delete[] slots;
    slots = 0;
    delete[] state;
}

CMSAdpcmPool::CMSAdpcmPool(int maxCount, int preallocate)
    : capacity(maxCount), initialCount(preallocate)
{
    slots = new CSoundDecoderMSADPCM*[maxCount];
    state = new int[maxCount];
    int i = 0;
    for (; i < preallocate; ++i) {
        state[i] = 0;
        slots[i] = new CSoundDecoderMSADPCM;
    }
    for (int i = preallocate; i < maxCount; ++i) {
        state[i] = -1;
        slots[i] = 0;
    }
    firstFree = 0;
    lastUsed = -1;
}

void CMSAdpcmPool::ReleaseMSADPCMDecoder(CSoundDecoderMSADPCM* data)
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

void CSoundDecoderMSADPCM::GoTo(int)
{
    fseek(reinterpret_cast<NativeFile*>(stream), formatHeader->size + 40, 0);
    flags |= 1;
    position = 0;
}

void CSoundDecoderMSADPCM::Init(__sFILE* input, RiffHeader* riff, FormatHeader* format)
{
    stream = input;
    formatHeader = format;
    riffHeader = riff;
    channelIndex = 0;
    flags = 1;
    samplesRemaining = 0;
    position = 0;
    ended = false;
    unsigned int extra = format->size;
    if (extra > 16)
        fseek(reinterpret_cast<NativeFile*>(input), extra - 16, 1);
    fread(&fact, sizeof(fact), 1, reinterpret_cast<NativeFile*>(stream));
    fread(&data, sizeof(data), 1, reinterpret_cast<NativeFile*>(stream));
    blockHeaderSize = formatHeader->channels * 4;
    if (formatHeader->channels == 1)
        samplesPerBlock = (formatHeader->blockAlignment - blockHeaderSize) * 2 + 1;
    else
        samplesPerBlock = formatHeader->blockAlignment + 1 - blockHeaderSize;
    pcmSize = ((data.size / formatHeader->blockAlignment) * samplesPerBlock) << 2;
    effectiveSamples = fact.samples;
}

CSoundDecoderMSADPCM::CSoundDecoderMSADPCM()
    : buffer(0), bufferSize(4096), channelIndex(0), samplesRemaining(0),
      fact(), data(), position(0), ended(false), flags(1)
{
    buffer = new unsigned char[bufferSize];
    riffHeader = 0;
    formatHeader = 0;
    stream = 0;
}

CSoundDecoderMSADPCM* CMSAdpcmPool::GetMSADPCMDecoder(__sFILE* stream, RiffHeader* riffHeader, FormatHeader* formatHeader)
{
    if (firstFree >= capacity)
        return 0;
    if (state[firstFree] == -1)
        slots[firstFree] = new CSoundDecoderMSADPCM;
    CSoundDecoderMSADPCM* data = slots[firstFree];
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

CSoundDecoderMSADPCM::CSoundDecoderMSADPCM(__sFILE* input, RiffHeader* riff, FormatHeader* format)
    : stream(input), buffer(0), bufferSize(4096), channelIndex(0), samplesRemaining(0),
      riffHeader(riff), formatHeader(format), fact(), data(), position(0), ended(false), flags(1)
{
    buffer = new unsigned char[bufferSize];
    if (formatHeader->size > 16)
        fseek(reinterpret_cast<NativeFile*>(stream), formatHeader->size - 16, 1);
    fread(&fact, sizeof(fact), 1, reinterpret_cast<NativeFile*>(stream));
    fread(&data, sizeof(data), 1, reinterpret_cast<NativeFile*>(stream));
    FormatHeader* wavFormat = formatHeader;
    unsigned char headerSize = wavFormat->channels * 4;
    blockHeaderSize = headerSize;
    if (wavFormat->channels == 1)
        samplesPerBlock = (wavFormat->blockAlignment - headerSize) * 2 + 1;
    else
        samplesPerBlock = wavFormat->blockAlignment + 1 - headerSize;
    pcmSize = fact.samples * 4;
    effectiveSamples = fact.samples;
}

struct MSAdpcmSizeView {
    char pad[20];
    int bufferSize;
};

struct AdpcmHeader {
    short sample;
    unsigned char index;
};

int CSoundDecoderMSADPCM::Decode(short* output, int count, bool loop)
{
    ended = false;
    unsigned int blocks = count / samplesPerBlock;
    unsigned int bytes = formatHeader->blockAlignment * blocks;
    int toRead;
    if (bytes + position < data.size)
        toRead = bytes;
    else
        toRead = data.size - position;
    int chunk = reinterpret_cast<const MSAdpcmSizeView*>(this)->bufferSize;
    int chunks = toRead / chunk;
    if (toRead > chunk * chunks)
        ++chunks;
    short* left = output;
    short* right = output + 1;
    int decoded = 0;
    while (chunks--) {
        int size = bufferSize;
        int request = toRead;
        if (request > size)
            request = size;
        int got = fread(buffer, 1, request, reinterpret_cast<NativeFile*>(stream));
        position += got;
        const unsigned char* input = buffer;
        int align = formatHeader->blockAlignment;
        int nb = got / align;
        toRead -= size;
        decoded += samplesPerBlock * nb;
        if (formatHeader->channels == 1) {
            unsigned int n = (align + 1 - blockHeaderSize) * nb;
            while (n--) {
                if (flags & 1) {
                    *reinterpret_cast<AdpcmHeader*>(&this->left) = *reinterpret_cast<const AdpcmHeader*>(input);
                    *left = this->left.sample;
                    left += 1;
                    unsigned int header = blockHeaderSize;
                    input += header;
                    samplesRemaining = header;
                    flags &= ~1;
                } else {
                    *left++ = _ZN12AdpcmDecoder11DecodeAdpcmEiP10AdpcmState(*input & 15, &this->left);
                    *left++ = _ZN12AdpcmDecoder11DecodeAdpcmEiP10AdpcmState((*input++ >> 4) & 15, &this->left);
                    if (++samplesRemaining >= formatHeader->blockAlignment)
                        flags |= 1;
                }
            }
        } else {
            int n = samplesPerBlock * nb;
            while (n--) {
                if (flags & 1) {
                    *reinterpret_cast<AdpcmHeader*>(&this->left) = *reinterpret_cast<const AdpcmHeader*>(input);
                    *reinterpret_cast<AdpcmHeader*>(&this->right) = *reinterpret_cast<const AdpcmHeader*>(input + 4);
                    *left = this->left.sample;
                    *right = this->right.sample;
                    left += 2;
                    right += 2;
                    unsigned int header = blockHeaderSize;
                    input += header;
                    samplesRemaining = header;
                    flags &= ~1;
                } else {
                    if (channelIndex < 4) {
                        left[0] = _ZN12AdpcmDecoder11DecodeAdpcmEiP10AdpcmState(*input & 15, &this->left);
                        left += 2;
                        left[0] = _ZN12AdpcmDecoder11DecodeAdpcmEiP10AdpcmState((*input >> 4) & 15, &this->left);
                        left += 2;
                    } else {
                        *right = _ZN12AdpcmDecoder11DecodeAdpcmEiP10AdpcmState(*input & 15, &this->right);
                        right += 2;
                        *right = _ZN12AdpcmDecoder11DecodeAdpcmEiP10AdpcmState((*input >> 4) & 15, &this->right);
                        right += 2;
                    }
                    ++input;
                    ++channelIndex;
                    ++samplesRemaining;
                    if (channelIndex > 7) {
                        channelIndex = 0;
                        if (samplesRemaining >= formatHeader->blockAlignment)
                            flags |= 1;
                    }
                }
            }
        }
    }
    ended = position == data.size;
    if (loop && ended) {
        GoTo(0);
        int rest = fact.samples % count;
        // Retail predicts the leftover-samples return as the unlikely edge.
        if (__builtin_expect(rest != 0, 0))
            return rest;
    }
    return decoded;
}

CSoundDecoderMSADPCM::~CSoundDecoderMSADPCM()
{
    delete[] buffer;
}
