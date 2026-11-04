#ifndef WCH_AUDIO_SOUND_MANAGER_H
#define WCH_AUDIO_SOUND_MANAGER_H

namespace irr { namespace core { template<class T> class vector3d; } }

// Partial call interface and observed byte at 140; not a complete manager.
class SoundManager {
public:
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
    void stopAllMusic();
    void stopAllSounds();
    void pauseAllSounds();
    void stopLowFpsMusic();
    void stop(int id, int channel, int flags);
    void resume(int id);
    void pause(int id);

    struct SoundEntry {
        int type;
        unsigned char unknown4[8];
    };

    unsigned char unknown0[56];
    unsigned int flags;
    unsigned char unknown60[24];
    SoundEntry* soundEntries;
    unsigned char unknown88[16];
    int resourceIdBase;
    unsigned char unknown108[28];
    int radioStationCount;
    bool unknown140;
};

#endif
