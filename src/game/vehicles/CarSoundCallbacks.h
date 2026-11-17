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
    CarSoundParameters();
    ~CarSoundParameters();

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

class SoundFade;
struct TurboSoundSettings;

// Observed CarSounds prefix.
class CarSounds {
public:
    void Update(CarSoundParameters* parameters);
    void RemoveTurboSounds(TurboSoundSettings* settings);
    static void Clean();
    static CarSoundCallbacks s_SoundCallbacks;
    static void UnregisterCallbacks();
    static void RegisterCallbacks(const CarSoundCallbacks&);
    static void InitOnOffCrossFadeGains(int duration);

private:
    void UpdateStartupSound();
    void UpdateClutchSound();
    int FilterRPMValues(int value);
    float InterpolateLinear(int minimum, int maximum, int value, float lowerGain, float upperGain);
    float InterpolateFlatEnded(int begin, int end, int value, float from, float to);
    void SetRPMFilterCoefficients(float frequency);
    void StopAllSounds();
    void UpdateOffEngineSounds();
    void UpdateOnEngineSounds();
    void UpdateRumbleSound();
    void UpdateTurboSounds();
    static bool s_onOffFadingInitialized;
    static int s_onOffCrossFadeDuration;

    int soundMode;
    unsigned char unknown4[4];
    int load;
    int previousLoad;
    unsigned char unknown16[4];
    float masterVolume;
    int maximumRpm;
    int rpm;
    unsigned char unknown32[4];
    unsigned int soundGear;
    unsigned int previousGear;
    unsigned int unknownGear44;
    unsigned int unknownGear48;
    bool clutchTriggered;
    bool filterRpm;
    unsigned char unknown54[6];
    float filteredRpm;
    float rpmInputCoefficient;
    float rpmFeedbackCoefficient;
    unsigned char unknown72[28];
    SoundFade* onFade;
    unsigned char unknown104[32];
    SoundFade* offFade;
    unsigned char unknown140[4];
    bool rumbleEnabled;
    unsigned char unknown145[31];
    bool startupEnabled;
    bool startupTriggered;
    unsigned char unknown178[2];
    int startupSound;
    int startupChannel;
    float startupGain;
    bool clutchEnabled;
    unsigned char unknown193[3];
    int clutchSoundId;
    int clutchChannel;
    float clutchVolume;
    bool turboEnabled;
    bool useRpmCopyB;
    unsigned char unknown210[2];
    int turboRpm;
    bool useRpmCopyA;
    unsigned char unknown217[3];
    int secondaryTurboRpm;
};

#endif
