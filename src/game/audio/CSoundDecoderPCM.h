#ifndef WCH_AUDIO_CSOUNDDECODERPCM_H
#define WCH_AUDIO_CSOUNDDECODERPCM_H

#include "ISoundDecoder.h"
#include "WavHeaders.h"

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


#endif
