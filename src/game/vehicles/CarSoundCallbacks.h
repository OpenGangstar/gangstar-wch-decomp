#ifndef WCH_VEHICLES_CAR_SOUND_CALLBACKS_H
#define WCH_VEHICLES_CAR_SOUND_CALLBACKS_H

struct CarSoundCallbacks {
    bool (*isSoundPlaying)(int, int);
    int (*play)(int, bool, float, float);
    void (*stop)(int, int);
    void (*setPitch)(int, int, float);
    void (*setVolume)(int, int, float);

    CarSoundCallbacks();
    ~CarSoundCallbacks();
    CarSoundCallbacks& operator=(const CarSoundCallbacks&);
};

// Only the static callback interface is recovered here, not an instance layout.
class CarSounds {
public:
    static CarSoundCallbacks s_SoundCallbacks;
    static void UnregisterCallbacks();
    static void RegisterCallbacks(const CarSoundCallbacks&);
};

#endif
