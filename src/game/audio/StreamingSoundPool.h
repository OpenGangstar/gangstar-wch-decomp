#ifndef WCH_AUDIO_STREAMINGSOUNDPOOL_H
#define WCH_AUDIO_STREAMINGSOUNDPOOL_H

class StreamingSound;
class CSoundData;

class CStreamingPool {
public:
    CStreamingPool(int capacity, int initialCount);
    ~CStreamingPool();
    StreamingSound* GetStreamingSound(CSoundData* data);
    void ReleaseStreamingSound(StreamingSound* decoder);

private:
    StreamingSound** slots;
    int capacity;
    int initialCount;
    int firstFree;
    int lastUsed;
    int* state;
};


#endif
