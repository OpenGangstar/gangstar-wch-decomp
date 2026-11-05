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
#include "../core/NativeStdio.h"

class CPcmPool;
class CMSAdpcmPool;

class CSoundDecoderMSWAV : public ISoundDecoder {
public:
    CSoundDecoderMSWAV();
    virtual ~CSoundDecoderMSWAV();
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
    char riffId[4];
    unsigned int riffSize;
    char waveId[4];
    char formatId[4];
    unsigned int formatSize;
    unsigned short formatTag;
    unsigned short channels;
    unsigned int sampleRate;
    unsigned int bytesPerSecond;
    unsigned short blockAlignment;
    unsigned short bitsPerSample;

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
    : file(0), riffId(), riffSize(0), waveId(), formatId(), formatSize(0),
      formatTag(0), channels(0), sampleRate(0), bytesPerSecond(0),
      blockAlignment(0), bitsPerSample(0)
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


CSoundDecoderMSWAV::~CSoundDecoderMSWAV()
{
    if (file)
        fclose(file);
}
