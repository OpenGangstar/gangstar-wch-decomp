#ifndef WCH_AUDIO_CSOUND_H
#define WCH_AUDIO_CSOUND_H

namespace irr { namespace core { template<class T> class vector3d; } }

class CSoundData;

class ALSourcesPool {
public:
    ALSourcesPool(int, int);
    ~ALSourcesPool();
};

class CSound {
public:
    CSound();
    CSound(CSoundData* data);
    virtual ~CSound();
    virtual void Play(bool loop, float volume, int fade);
    virtual void Stop(int fade);
    virtual void Pause();
    virtual void Resume();
    virtual void SetPosition(const irr::core::vector3d<float>& position);
    virtual void Update(int elapsed);
    virtual void SetVolume(float volume);
    virtual void SetPitch(float pitch);

    void Init(CSoundData* data);
    void InitALSource();
    static void InitStaticParameters(ALSourcesPool* pool);
    void UnInit();
    int GetStatus() const;
    void _performFade(int elapsed);
    void QueueStreamBuffer(char* data, int buffer, int length);
    int GetProcessedBuffer();
    CSoundData* GetSoundData();
    float GetAbsoluteVolume() const;

    static ALSourcesPool* s_pALSourcesPool;

private:
    friend class StreamingSound;

    CSoundData* data;
    bool unknown8;
    bool unknown9;
    float volume;
    int status;
    int unknown20;
    int unknown24;
    int unknown28;
    int fadeActive;
    int fadeRemaining;
    int fadeDuration;
    int unknown44;
};

#endif
