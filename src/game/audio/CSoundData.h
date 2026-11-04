#ifndef WCH_AUDIO_CSOUND_DATA_H
#define WCH_AUDIO_CSOUND_DATA_H

class CSoundData {
public:
    CSoundData();
    CSoundData(int format, int sampleRate, int channels, int size,
               char* samples, int, bool);
    virtual ~CSoundData();
    void Init(int, int, int, int, char*, int);
    void UnInit();

    int format;
    int sampleRate;
    int channels;
    int size;
    char* samples;
    int references;
};

class CSoundDataPool {
public:
    CSoundDataPool(int capacity, int initialCount);
    ~CSoundDataPool();
    CSoundData* GetSoundData(int format, int rate, int channels, int size,
                             char* samples, int flags);
    void ReleaseSoundData(CSoundData* data);

private:
    CSoundData** slots;
    int capacity;
    int initialCount;
    int firstFree;
    int lastUsed;
    int* state;
};

#endif
