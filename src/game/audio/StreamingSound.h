#ifndef WCH_AUDIO_STREAMINGSOUND_H
#define WCH_AUDIO_STREAMINGSOUND_H

#include "CSound.h"

class ISoundDecoder;
class CSoundBuffers;
class CMSWavPool;

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


#endif
