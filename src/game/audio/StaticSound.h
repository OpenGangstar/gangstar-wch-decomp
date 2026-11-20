#ifndef WCH_AUDIO_STATICSOUND_H
#define WCH_AUDIO_STATICSOUND_H

#include "CSound.h"

class StaticSound : public CSound {
public:
    StaticSound();
    StaticSound(CSoundData* soundData);
    virtual ~StaticSound();
    virtual void Stop(int fade);
    void Init(CSoundData* soundData);
    void UnInit();
};


#endif
