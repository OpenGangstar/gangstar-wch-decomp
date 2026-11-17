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

struct CarSoundParameters {
    int mode;
    bool trigger;
    unsigned char unknown5[3];
    int rpm;
    int load;
    unsigned int gear;
    float scale;
    int rpmCopyA;
    int rpmCopyB;
};

// Partial call interface. This does not assert a CarSounds instance layout.
class CarSounds {
public:
    void Update(CarSoundParameters* parameters);
    static CarSoundCallbacks s_SoundCallbacks;
    static void UnregisterCallbacks();
    static void RegisterCallbacks(const CarSoundCallbacks&);
};

#endif
