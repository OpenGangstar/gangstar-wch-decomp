/*
 * CSoundDecoderMSWAV
 *
 * Original file: CSoundDecoderMSWAV.cpp
 * Area:          audio
 *
 * This file mirrors the layout of the retail build.  Add the decompiled
 * functions of CSoundDecoderMSWAV.cpp here, in the order they appear in the library.
 */

#include "ISoundDecoder.h"

class CSoundDecoderMSWAV : public ISoundDecoder {
public:
    virtual ~CSoundDecoderMSWAV();
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
};

int CSoundDecoderMSWAV::GetSamplingRate() const { return decoder->GetSamplingRate(); }
int CSoundDecoderMSWAV::GetChannel() const { return decoder->GetChannel(); }
int CSoundDecoderMSWAV::GetPCMSize() const { return decoder->GetPCMSize(); }
int CSoundDecoderMSWAV::GetNbEffectiveSamples() const { return decoder->GetNbEffectiveSamples(); }
int CSoundDecoderMSWAV::GetTotalSamples() const { return decoder->GetTotalSamples(); }
bool CSoundDecoderMSWAV::HasMoreData() const { return decoder->HasMoreData(); }

int CSoundDecoderMSWAV::Decode(short* output, int count, bool loop)
{
    return decoder->Decode(output, count, loop);
}

void CSoundDecoderMSWAV::GoTo(int position) { decoder->GoTo(position); }
int CSoundDecoderMSWAV::GetNumSamplesPerDecode(int count) { return decoder->GetNumSamplesPerDecode(count); }
