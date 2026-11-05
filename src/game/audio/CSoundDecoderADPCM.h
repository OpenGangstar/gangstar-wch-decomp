#ifndef WCH_AUDIO_CSOUNDDECODERADPCM_H
#define WCH_AUDIO_CSOUNDDECODERADPCM_H

#include "ISoundDecoder.h"

class AdpcmState;
struct NativeFile;

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


#endif
