#ifndef WCH_AUDIO_CSOUNDDECODERMSADPCM_H
#define WCH_AUDIO_CSOUNDDECODERMSADPCM_H

#include "AdpcmState.h"
#include "ISoundDecoder.h"
#include "WavHeaders.h"

class CSoundDecoderMSADPCM : public ISoundDecoder {
public:
    CSoundDecoderMSADPCM();
    CSoundDecoderMSADPCM(__sFILE* input, RiffHeader* riff, FormatHeader* format);
    virtual ~CSoundDecoderMSADPCM();
    void Init(__sFILE* stream, RiffHeader* riffHeader, FormatHeader* formatHeader);
    void UnInit();
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
    AdpcmState left;
    AdpcmState right;
    __sFILE* stream;
    unsigned char* buffer;
    unsigned int bufferSize;
    unsigned int field24;
    unsigned int channelIndex;
    unsigned int samplesRemaining;
    RiffHeader* riffHeader;
    FormatHeader* formatHeader;
    struct {
        char id[4];
        unsigned int size;
        unsigned int samples;
    } fact;
    struct {
        char id[4];
        unsigned int size;
    } data;
    unsigned int pcmSize;
    unsigned int effectiveSamples;
    unsigned int samplesPerBlock;
    unsigned char blockHeaderSize;
    unsigned int position;
    bool ended;
    unsigned int flags;
};


class CMSAdpcmPool {
public:
    CMSAdpcmPool(int capacity, int initialCount);
    ~CMSAdpcmPool();
    CSoundDecoderMSADPCM* GetMSADPCMDecoder(__sFILE* stream, RiffHeader* riffHeader, FormatHeader* formatHeader);
    void ReleaseMSADPCMDecoder(CSoundDecoderMSADPCM* decoder);

private:
    CSoundDecoderMSADPCM** slots;
    int capacity;
    int initialCount;
    int firstFree;
    int lastUsed;
    int* state;
};


#endif
