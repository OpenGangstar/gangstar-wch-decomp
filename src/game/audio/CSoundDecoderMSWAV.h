#ifndef WCH_AUDIO_CSOUNDDECODERMSWAV_H
#define WCH_AUDIO_CSOUNDDECODERMSWAV_H

#include "ISoundDecoder.h"
#include "WavHeaders.h"

struct NativeFile;
class CPcmPool;
class CMSAdpcmPool;

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


#endif
