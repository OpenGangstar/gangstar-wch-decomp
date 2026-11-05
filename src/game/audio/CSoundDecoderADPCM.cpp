/*
 * CSoundDecoderADPCM
 *
 * Original file: CSoundDecoderADPCM.cpp
 * Area:          audio
 *
 * This file mirrors the layout of the retail build.  Add the decompiled
 * functions of CSoundDecoderADPCM.cpp here, in the order they appear in the library.
 */

#include "AdpcmState.h"
#include "ISoundDecoder.h"
#include "../core/NativeStdio.h"

class CSoundDecoderADPCM : public ISoundDecoder {
public:
    CSoundDecoderADPCM(const char* name);
    virtual ~CSoundDecoderADPCM();
    virtual int Decode(short* output, int count, bool loop);
    virtual void GoTo(int position);

private:
    AdpcmState* state;
    NativeFile* file;
    unsigned char* buffer;
    int bufferSize;
};

extern "C" short _ZN12AdpcmDecoder11DecodeAdpcmEiP10AdpcmState(int code, AdpcmState* state)
    __attribute__((weak));

static const char readMode[] __attribute__((section(".rodata.adpcm_read_mode"))) = "rb";

inline int ISoundDecoder::GetNumSamplesPerDecode(int count) { return count; }
inline int ISoundDecoder::GetSamplingRate() const { return -1; }
inline int ISoundDecoder::GetChannel() const { return -1; }
inline int ISoundDecoder::GetPCMSize() const { return -1; }
inline int ISoundDecoder::GetNbEffectiveSamples() const { return -1; }
inline int ISoundDecoder::GetTotalSamples() const { return -1; }
inline bool ISoundDecoder::HasMoreData() const { return false; }

void CSoundDecoderADPCM::GoTo(int)
{
    fseek(file, 40, 0);
    delete state;
    state = 0;
}

inline ISoundDecoder::~ISoundDecoder() {}

int CSoundDecoderADPCM::Decode(short* output, int count, bool loop)
{
    if (!state) {
        state = new AdpcmState;
        fread(state, 4, 1, file);
    }
    unsigned int bytesRead = fread(buffer, 1, count / 2, file);
    int samplesRead = bytesRead * 2;
    const unsigned char* input = buffer;
    while (bytesRead--) {
        *output++ = _ZN12AdpcmDecoder11DecodeAdpcmEiP10AdpcmState(*input & 15, state);
        *output = output[-1];
        ++output;
        *output++ = _ZN12AdpcmDecoder11DecodeAdpcmEiP10AdpcmState((*input >> 4) & 15, state);
        *output = output[-1];
        ++output;
        ++input;
    }
    if (loop && count > samplesRead)
        GoTo(0);
    return samplesRead;
}

CSoundDecoderADPCM::CSoundDecoderADPCM(const char* name)
    : state(0), file(0), buffer(0), bufferSize(4096)
{
    file = fopen(name, readMode);
    buffer = new unsigned char[bufferSize];
    char header[16];
    char format[8];
    char data[16];
    fread(header, sizeof(header), 1, file);
    fread(format, sizeof(format), 1, file);
    fread(data, sizeof(data), 1, file);
}

void operator delete(void*) throw();

CSoundDecoderADPCM::~CSoundDecoderADPCM()
{
    fclose(file);
    ::operator delete(buffer);
    delete state;
}
