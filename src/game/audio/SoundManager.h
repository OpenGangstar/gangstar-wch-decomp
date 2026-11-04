#ifndef WCH_AUDIO_SOUND_MANAGER_H
#define WCH_AUDIO_SOUND_MANAGER_H

namespace irr { namespace core { template<class T> class vector3d; } }

// Partial call interface and observed byte at 140; not a complete manager.
class CSound;
class CSoundData;

class SoundManager {
public:
    SoundManager();
    virtual ~SoundManager();
    static SoundManager* s_soundManager;
    void clear();
    void toggleSound();
    static SoundManager* getInstance() __attribute__((weak));
    bool playEx(int id, const irr::core::vector3d<float>* position, bool flag,
                float value1, int value2, bool flag2, float value3, void (*callback)());
    void init();
    void unInit();
    void useIPodRadio();
    void useBuiltInRadio();
    bool canUseIPod() const;
    void initIPod();
    void cleanupIPod();
    bool iPodIsInitialized() const;
    int getPlaylistCount() const;
    void getPlaylistName(int index, char* name) const;
    int getPlaylistIndexFromString(const char* name) const;
    int getCurPlaylist() const;
    void setPlaylist(int index);
    void setListenerPos(const irr::core::vector3d<float>& position,
                        const irr::core::vector3d<float>& direction,
                        const irr::core::vector3d<float>& up);
    int _getSoundId(int resourceId);
    int _getResId(int soundId);
    int _getSoundType(int soundId);
    void disableMusic();
    void enableMusic();
    int getNumRadioStations() const;
    void setVolume(int id, int channel, float volume);
    static irr::core::vector3d<float> convertVisual3DToSound3D(const irr::core::vector3d<float>& position);
    void setPitch(int resourceId, int channel, float pitch);
    void setSourcePos(int resourceId, int channel, const irr::core::vector3d<float>& position);
    void stopAllMusic();
    void stopAllSounds();
    void pauseAllSounds();
    void stopLowFpsMusic();
    void stop(int id, int channel, int flags);
    void resume(int id);
    void pause(int id);

    void playLowFpsMusic(int id, bool loop);
    void pauseLowFpsMusic();
    void _cleanupLowFpsMusic();
    void setLowFpsMusicVolume(float volume);
    void resumeLowFpsMusic();
    bool isLowFpsMusicPlaying() const;
    void playRadio(int station);
    void stopRadio();
    void changeRadioStation(int station);
    void lastRadioStation();
    void nextRadioStation();
    int _getRadioTrack(int station);

    bool isSoundPlaying(int resourceId);
    bool isSoundPlaying(int resourceId, int channel);
    int getNumberOfAllocatedSounds();

    static bool playSoundCallback(int id, bool loop, float volume, float pitch);
    static int s_soundsPlaying;
    void endCutscene();
    static void setPitchCallback(int id, int channel, float pitch);
    static void setVolumeCallback(int id, int channel, float volume);
    static void stopSoundCallback(int id, int channel);
    static bool isSoundPlayingCallback(int id, int channel);

    struct SoundEntry {
        int type;
        int channel;
        unsigned char unknown8[4];
    };

    unsigned char unknown4[32];
    CSound*** soundSlots;
    CSound* lowFpsSound;
    CSoundData* lowFpsData;
    int radioTrack;
    int radioStation;
    unsigned int flags;
    unsigned char unknown60[24];
    SoundEntry* soundEntries;
    float sfxVolume;
    float playbackVolume;
    float effectsPlaybackVolume;
    int soundCount;
    int resourceIdBase;
    unsigned char unknown108[28];
    int radioStationCount;
    bool unknown140;
    unsigned char unknown141[7];
};

#endif
