#ifndef WCH_AUDIO_SOUND_BUFFERS_POOL_H
#define WCH_AUDIO_SOUND_BUFFERS_POOL_H

class CSoundBuffers {
public:
    CSoundBuffers(int capacity, int initialCount, int bufferSize);
    ~CSoundBuffers();
    char* GetSoundBuffer();
    void ReleaseSoundBuffer(char* buffer);

private:
    int bufferSize;
    int capacity;
    int initialCount;
    char** slots;
    int* state;
    int firstFree;
    int lastUsed;
};

#endif
