#ifndef WCH_AUDIO_STATICSOUNDPOOL_H
#define WCH_AUDIO_STATICSOUNDPOOL_H

class StaticSound;
class CSoundData;

class CStaticSoundsPool {
public:
    CStaticSoundsPool(int capacity, int initialCount);
    ~CStaticSoundsPool();
    StaticSound* GetStaticSound(CSoundData* data);
    void ReleaseStaticSound(StaticSound* decoder);

private:
    StaticSound** slots;
    int capacity;
    int initialCount;
    int firstFree;
    int lastUsed;
    int* state;
};


#endif
