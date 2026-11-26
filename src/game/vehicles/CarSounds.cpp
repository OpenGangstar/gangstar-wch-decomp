/*
 * CarSounds
 *
 * Original file: CarSounds.cpp
 * Area:          vehicles
 *
 * This file mirrors the layout of the retail build.  Add the decompiled
 * functions of CarSounds.cpp here, in the order they appear in the library.
 */

#include "CarSoundCallbacks.h"
#include "../core/PlacementNew.h"

class SoundFade {
public:
    SoundFade();
    ~SoundFade();
    int GetNbRemainingFades();
    float GetVolume();
    static void Clean();
    static void InitFadeGains(int frames);
    static int s_nbFadeFrames;
    static float* s_fadeGains;
    int GetState();
    void StartFade(int state);
    void Update();
private:
    float gain;
    int remainingFrames;
    int fadeState;
};

SoundFade::SoundFade()
{
    fadeState = 0;
    remainingFrames = 0;
}

CarSoundSettings::CarSoundSettings()
{
    auxiliaryTurboIds = 0;
    onEngineIds = 0;
    onEngineReferenceRpm = 0;
    onEngineLowerRpm = 0;
    onEngineUpperRpm = 0;
    offEngineIds = 0;
    offEngineReferenceRpm = 0;
    offEngineLowerRpm = 0;
    offEngineUpperRpm = 0;
    auxiliaryTurboThresholds = 0;
}

CarSoundSettings::~CarSoundSettings()
{
    delete[] onEngineIds;
    delete[] onEngineReferenceRpm;
    delete[] onEngineLowerRpm;
    delete[] onEngineUpperRpm;
    delete[] offEngineIds;
    delete[] offEngineReferenceRpm;
    delete[] offEngineLowerRpm;
    delete[] offEngineUpperRpm;
    delete[] auxiliaryTurboIds;
    delete[] auxiliaryTurboThresholds;
}

TurboSoundSettings::TurboSoundSettings()
{
    auxiliaryTurboIds = 0;
    auxiliaryTurboThresholds = 0;
}

TurboSoundSettings::~TurboSoundSettings()
{
    delete[] auxiliaryTurboIds;
    delete[] auxiliaryTurboThresholds;
}

CarSounds::~CarSounds()
{
    StopAllSounds();
    if (engineSoundsEnabled) {
        delete[] onEngineIds;
        delete[] onEngineChannels;
        if (engineArray88)
            ::operator delete[](engineArray88);
        if (engineArray92)
            ::operator delete[](engineArray92);
        if (engineArray96)
            ::operator delete[](engineArray96);
        delete onFade;
        delete[] offEngineIds;
        delete[] offEngineChannels;
        if (engineArray124)
            ::operator delete[](engineArray124);
        if (engineArray128)
            ::operator delete[](engineArray128);
        if (engineArray132)
            ::operator delete[](engineArray132);
        delete offFade;
    }
    if (turboEnabled) {
        delete[] auxiliaryTurboIds;
        delete[] auxiliaryTurboChannels;
        if (turboArray284)
            ::operator delete[](turboArray284);
    }
}

SoundFade::~SoundFade()
{
}

int SoundFade::GetNbRemainingFades()
{
    return remainingFrames;
}

int SoundFade::GetState()
{
    return fadeState;
}

float SoundFade::GetVolume()
{
    return gain;
}

void SoundFade::Clean()
{
    delete[] s_fadeGains;
    s_fadeGains = 0;
}

void CarSounds::Clean()
{
    SoundFade::Clean();
    UnregisterCallbacks();
}

void CarSounds::RemoveTurboSounds(TurboSoundSettings*)
{
    turboEnabled = false;
}

CarSounds::CarSounds()
{
    engineArray128 = 0;
    engineArray132 = 0;
    auxiliaryTurboIds = 0;
    auxiliaryTurboChannels = 0;
    engineSoundsEnabled = false;
    soundMode = 0;
    onEngineIds = 0;
    onEngineChannels = 0;
    engineArray88 = 0;
    engineArray92 = 0;
    engineArray96 = 0;
    offEngineIds = 0;
    offEngineChannels = 0;
    engineArray124 = 0;
    turboArray284 = 0;
}

void CarSounds::StopAllSounds()
{
    if (engineSoundsEnabled) {
        for (int i = 0; i < onEngineCount; ++i) {
            if (onEngineChannels[i] >= 0) {
                s_SoundCallbacks.stop(onEngineIds[i], onEngineChannels[i]);
                onEngineChannels[i] = -1;
            }
        }
        for (int i = 0; i < offEngineCount; ++i) {
            if (offEngineChannels[i] >= 0) {
                s_SoundCallbacks.stop(offEngineIds[i], offEngineChannels[i]);
                offEngineChannels[i] = -1;
            }
        }
    }
    if (startupEnabled && startupChannel >= 0) {
        s_SoundCallbacks.stop(startupSound, startupChannel);
        startupChannel = -1;
    }
    if (rumbleEnabled && rumbleChannel >= 0) {
        s_SoundCallbacks.stop(rumbleSoundId, rumbleChannel);
        rumbleChannel = -1;
    }
    if (clutchEnabled && clutchChannel >= 0) {
        s_SoundCallbacks.stop(clutchSoundId, clutchChannel);
        clutchChannel = -1;
    }
    if (turboEnabled) {
        if (turboChannel >= 0) {
            s_SoundCallbacks.stop(turboSoundId, turboChannel);
            turboChannel = -1;
        }
        if (secondaryTurboChannel >= 0) {
            s_SoundCallbacks.stop(secondaryTurboSoundId, secondaryTurboChannel);
            secondaryTurboChannel = -1;
        }
        for (int i = 0; i < auxiliaryTurboCount; ++i) {
            if (auxiliaryTurboChannels[i] >= 0) {
                s_SoundCallbacks.stop(auxiliaryTurboIds[i], auxiliaryTurboChannels[i]);
                auxiliaryTurboChannels[i] = -1;
            }
        }
    }
}

void CarSounds::UpdateRumbleSound()
{
    if ((rumbleOffThrottleOnly && load > 0) || rpm <= rumbleMinimumRpm || rpm >= rumbleMaximumRpm) {
        s_SoundCallbacks.stop(rumbleSoundId, rumbleChannel);
        rumbleChannel = -1;
        return;
    }

    const float fullVolume = masterVolume * rumbleVolume;
    const float volume = rpm <= rumbleRampEndRpm
        ? InterpolateLinear(rumbleMinimumRpm, rumbleRampEndRpm, rpm, 0.0f, fullVolume)
        : fullVolume;

    float pitch = 1.0f;
    if (rumbleVariablePitch)
        pitch = static_cast<float>(rpm) / static_cast<float>(rumbleReferenceRpm);
    if (!s_SoundCallbacks.isSoundPlaying(rumbleSoundId, rumbleChannel)) {
        rumbleChannel = s_SoundCallbacks.play(rumbleSoundId, true, volume, pitch);
    } else {
        s_SoundCallbacks.setVolume(rumbleSoundId, rumbleChannel, volume);
        s_SoundCallbacks.setPitch(rumbleSoundId, rumbleChannel, pitch);
    }
}

void SoundFade::StartFade(int state)
{
    if (remainingFrames == 0) {
        fadeState = state;
        if (state == 1) {
            gain = s_fadeGains[1];
            remainingFrames = s_nbFadeFrames;
        } else if (state == 2) {
            const int frames = s_nbFadeFrames;
            const float nextGain = s_fadeGains[frames];
            remainingFrames = frames;
            gain = nextGain;
        }
    }
}

void SoundFade::Update()
{
    if (--remainingFrames >= 0) {
        switch (fadeState) {
        case 1:
            gain = s_fadeGains[s_nbFadeFrames - remainingFrames + 1];
            break;
        case 2:
            gain = s_fadeGains[remainingFrames];
            break;
        }
    } else {
        remainingFrames = 0;
        fadeState = 0;
    }
}

extern "C" float __aeabi_fmul(float, float);

int CarSounds::FilterRPMValues(int value)
{
    const float input = __aeabi_fmul(static_cast<float>(value), rpmInputCoefficient);
    const float feedback = __aeabi_fmul(rpmFeedbackCoefficient, filteredRpm);
    filteredRpm = input - feedback;
    return static_cast<int>(filteredRpm);
}

extern "C" double sin(double radians);
extern "C" double cos(double radians);
extern "C" double sqrt(double value);

float CarSounds::InterpolateLinear(int minimum, int maximum, int value, float lowerGain, float upperGain)
{
    return static_cast<float>(value - minimum) *
        ((upperGain - lowerGain) / static_cast<float>(maximum - minimum)) + lowerGain;
}

float CarSounds::InterpolateFlatEnded(int begin, int end, int value, float from, float to)
{
    if (to != from) {
        const float difference = to - from;
        const float ratio = static_cast<float>(value - begin) / static_cast<float>(end - begin);
        const float angle = ratio * 3.14159265358979323846f;
        const float weight = static_cast<float>((1.0 - cos(static_cast<double>(angle))) * 0.5);
        from += difference * weight;
    }
    return from;
}

void CarSounds::SetRPMFilterCoefficients(float frequency)
{
    const float pi = 3.14159265358979323846f;
    const float factor = static_cast<float>(2.0 - cos(frequency * pi));
    rpmFeedbackCoefficient = static_cast<float>(sqrt(factor * factor - 1.0f) - factor);
    rpmInputCoefficient = rpmFeedbackCoefficient + 1.0f;
    filteredRpm = 0.0f;
}

CarSoundParameters::CarSoundParameters()
{
}

CarSoundParameters::~CarSoundParameters()
{
}

void SoundFade::InitFadeGains(int frames)
{
    s_nbFadeFrames = frames;
    const float pi = 3.14159265358979323846f;
    frames += 2;
    const float step = pi / static_cast<float>(frames - 1);
    s_fadeGains = new float[frames];
    float angle = -pi * 0.5f;
    for (int i = 0; i < frames; ++i) {
        s_fadeGains[i] = static_cast<float>((sin(static_cast<double>(angle)) + 1.0) * 0.5);
        angle += step;
    }
}

void CarSounds::UpdateOffEngineSounds()
{
    int previousUpper;
    int id;
    int channel;
    int reference;
    int lower;
    int upper;
    int nextLower;
    int minimum;
    int maximum;
    int margin;
    int* lowers;
    bool playing;
    float pitch;
    float volume;
    float gain;
    int i;
    int engineRpm;
    const int state = offFade->GetState();
    const int remaining = offFade->GetNbRemainingFades();
    if (state == 2 && remaining == 0) {
        for (i = 0; i < offEngineCount; ++i) {
            s_SoundCallbacks.stop(offEngineIds[i], offEngineChannels[i]);
            offEngineChannels[i] = -1;
            offEngineActive = 0;
        }
    } else if (state == 1 && remaining == s_onOffCrossFadeDuration) {
        offEngineActive = 1;
    }
    if (offEngineActive != 1)
        return;

    if (state == 0)
        gain = offEngineGain * masterVolume;
    else
        gain = offEngineGain * masterVolume * offFade->GetVolume();

    previousUpper = 0;
    for (i = 0; i < offEngineCount; ++i) {
        id = offEngineIds[i];
        channel = offEngineChannels[i];
        reference = static_cast<int*>(engineArray124)[i];
        lowers = static_cast<int*>(engineArray128);
        lower = lowers[i];
        upper = static_cast<int*>(engineArray132)[i];
        if (i < offEngineCount - 1)
            nextLower = lowers[i + 1];
        else
            nextLower = maximumRpm;
        margin = rpmMargin;
        minimum = lower - margin;
        maximum = upper + margin;
        playing = s_SoundCallbacks.isSoundPlaying(id, channel);
        if (playing && ((engineRpm = rpm) < minimum || engineRpm > maximum)) {
            s_SoundCallbacks.stop(id, channel);
            offEngineChannels[i] = -1;
        } else if (playing || ((engineRpm = rpm) >= lower && engineRpm <= upper)) {
            pitch = static_cast<float>(engineRpm) / static_cast<float>(reference);
            if (engineRpm < lower)
                volume = 0.0f;
            else if (engineRpm < previousUpper)
                volume = InterpolateLinear(lower, previousUpper, engineRpm, 0.0f, gain);
            else if (engineRpm < nextLower)
                volume = gain;
            else if (engineRpm < upper)
                volume = InterpolateLinear(nextLower, upper, engineRpm, gain, 0.0f);
            else
                volume = 0.0f;
            if (!playing) {
                offEngineChannels[i] = s_SoundCallbacks.play(id, true, volume, pitch);
            } else {
                s_SoundCallbacks.setVolume(id, channel, volume);
                s_SoundCallbacks.setPitch(id, channel, pitch);
            }
        }
        previousUpper = upper;
    }
}

void CarSounds::Update(CarSoundParameters* parameters)
{
    soundMode = parameters->mode;
    if (soundMode == 1) {
        masterVolume = parameters->scale;
        const unsigned int gear = parameters->gear;
        clutchTriggered = false;
        soundGear = gear;
        if (soundGear != previousGear && soundGear != unknownGear44 && soundGear != unknownGear48 &&
            previousGear != unknownGear44 && previousGear != unknownGear48) {
            clutchTriggered = true;
        }

        rpm = parameters->rpm;
        if (rpm < 0)
            rpm = 0;
        else if (rpm > maximumRpm)
            rpm = maximumRpm;
        if (filterRpm)
            rpm = FilterRPMValues(rpm);

        if (useRpmCopyB)
            turboRpm = parameters->rpmCopyB;
        else
            turboRpm = rpm;
        if (useRpmCopyA)
            secondaryTurboRpm = parameters->rpmCopyA;
        else
            secondaryTurboRpm = rpm;

        load = parameters->load;
        const int offFadeState = offFade->GetState();
        const int onFadeState = onFade->GetState();
        if (previousLoad == 0 && load > 0) {
            if (offFadeState == 0)
                offFade->StartFade(2);
            if (onFadeState == 0)
                onFade->StartFade(1);
        } else if (previousLoad > 0 && load == 0) {
            if (offFadeState == 0)
                offFade->StartFade(1);
            if (onFadeState == 0)
                onFade->StartFade(2);
        } else {
            offFade->Update();
            onFade->Update();
        }

        UpdateOffEngineSounds();
        UpdateOnEngineSounds();
        if (rumbleEnabled)
            UpdateRumbleSound();
        startupTriggered = parameters->trigger;
        if (startupEnabled && startupTriggered)
            UpdateStartupSound();
        if (clutchEnabled)
            UpdateClutchSound();
        turboRpm = parameters->rpmCopyB;
        if (turboEnabled)
            UpdateTurboSounds();
        previousLoad = load;
        previousGear = parameters->gear;
    } else if (soundMode == 2) {
        StopAllSounds();
        soundMode = 0;
    }
}

void CarSounds::InitOnOffCrossFadeGains(int duration)
{
    s_onOffFadingInitialized = true;
    s_onOffCrossFadeDuration = duration;
    if (s_onOffCrossFadeDuration < 0)
        s_onOffCrossFadeDuration = 0;
    else if (s_onOffCrossFadeDuration > 10)
        s_onOffCrossFadeDuration = 10;
    SoundFade::InitFadeGains(s_onOffCrossFadeDuration);
}

void CarSounds::Init(CarSoundSettings* settings)
{
    maximumRpm = settings->maximumRpm;
    rpm = settings->initialRpm;
    load = settings->initialLoad;
    previousLoad = 1 - load;
    unknown32 = 0;
    rpmMargin = 20;
    if (!s_onOffFadingInitialized)
        InitOnOffCrossFadeGains(s_onOffCrossFadeDuration);
    unknownGear44 = settings->unknownGear16;
    unknownGear48 = settings->unknownGear20;
    previousGear = soundGear = settings->initialGear;
    clutchTriggered = false;
    filterRpm = settings->filterRpm;
    filterFrequency = settings->filterFrequency;
    if (filterRpm)
        SetRPMFilterCoefficients(filterFrequency);

    onEngineCount = settings->onEngineCount;
    onEngineGain = settings->onEngineGain;
    onEngineIds = new int[onEngineCount];
    onEngineChannels = new int[onEngineCount];
    engineArray88 = new int[onEngineCount];
    engineArray92 = new int[onEngineCount];
    engineArray96 = new int[onEngineCount];
    for (int i = 0; i < onEngineCount; ++i) {
        onEngineIds[i] = settings->onEngineIds[i];
        onEngineChannels[i] = -1;
        static_cast<int*>(engineArray88)[i] = settings->onEngineReferenceRpm[i];
        static_cast<int*>(engineArray92)[i] = settings->onEngineLowerRpm[i];
        static_cast<int*>(engineArray96)[i] = settings->onEngineUpperRpm[i];
    }
    onFade = new SoundFade;
    onEngineActive = 0;

    offEngineCount = settings->offEngineCount;
    offEngineGain = settings->offEngineGain;
    offEngineIds = new int[offEngineCount];
    offEngineChannels = new int[offEngineCount];
    engineArray124 = new int[offEngineCount];
    engineArray128 = new int[offEngineCount];
    engineArray132 = new int[offEngineCount];
    for (int i = 0; i < offEngineCount; ++i) {
        offEngineIds[i] = settings->offEngineIds[i];
        offEngineChannels[i] = -1;
        static_cast<int*>(engineArray124)[i] = settings->offEngineReferenceRpm[i];
        static_cast<int*>(engineArray128)[i] = settings->offEngineLowerRpm[i];
        static_cast<int*>(engineArray132)[i] = settings->offEngineUpperRpm[i];
    }
    offFade = new SoundFade;
    offEngineActive = 0;

    rumbleEnabled = settings->rumbleEnabled;
    if (rumbleEnabled) {
        rumbleOffThrottleOnly = settings->rumbleOffThrottleOnly;
        rumbleVariablePitch = settings->rumbleVariablePitch;
        rumbleSoundId = settings->rumbleSoundId;
        rumbleChannel = -1;
        rumbleVolume = settings->rumbleVolume;
        rumbleReferenceRpm = settings->rumbleReferenceRpm;
        rumbleRampEndRpm = settings->rumbleRampEndRpm;
        rumbleMinimumRpm = settings->rumbleMinimumRpm;
        rumbleMaximumRpm = settings->rumbleMaximumRpm;
    }

    startupEnabled = settings->startupEnabled;
    if (startupEnabled) {
        startupTriggered = false;
        startupSound = settings->startupSound;
        startupChannel = -1;
        startupGain = settings->startupGain;
    }

    clutchEnabled = settings->clutchEnabled;
    if (clutchEnabled) {
        clutchSoundId = settings->clutchSoundId;
        clutchChannel = -1;
        clutchVolume = settings->clutchVolume;
    }

    turboEnabled = settings->turboEnabled;
    if (turboEnabled) {
        useRpmCopyB = settings->useRpmCopyB;
        if (useRpmCopyB) {
            turboRpm = settings->turboInitialRpm;
            turboMaximumRpm = settings->turboRpm156;
            turboMinimumRpm = settings->turboRpm160;
            turboReferenceRpm = settings->turboRpm148;
            secondaryTurboMaximumRpm = settings->turboRpm172;
            secondaryTurboMinimumRpm = settings->turboRpm176;
        } else {
            turboRpm = rpm;
            turboReferenceRpm = static_cast<int>(static_cast<float>(maximumRpm) * 0.3f);
            turboMaximumRpm = static_cast<int>(static_cast<float>(maximumRpm) * 0.6f);
            turboMinimumRpm = static_cast<int>(static_cast<float>(maximumRpm) * 0.08f);
            secondaryTurboMaximumRpm = maximumRpm;
            secondaryTurboMinimumRpm = 0;
        }
        turboSoundId = settings->turboSoundId;
        turboChannel = -1;
        turboPitchMix = 1.0f - settings->turboBasePitch;
        turboGain = settings->turboGain;
        secondaryTurboSoundId = settings->secondaryTurboSoundId;
        secondaryTurboChannel = -1;
        secondaryTurboGain = settings->secondaryTurboGain;

        auxiliaryTurboCount = settings->auxiliaryTurboCount;
        auxiliaryTurboIds = new int[auxiliaryTurboCount];
        auxiliaryTurboChannels = new int[auxiliaryTurboCount];
        for (int i = 0; i < auxiliaryTurboCount; ++i) {
            auxiliaryTurboIds[i] = settings->auxiliaryTurboIds[i];
            auxiliaryTurboChannels[i] = -1;
        }

        const int rpmCount = auxiliaryTurboCount + 1;
        turboArray284 = new int[rpmCount];
        useRpmCopyA = settings->useRpmCopyA;
        if (useRpmCopyA) {
            secondaryTurboRpm = settings->secondaryTurboInitialRpm;
            for (int i = 0; i < rpmCount; ++i)
                turboArray284[i] = settings->auxiliaryTurboThresholds[i];
        } else {
            secondaryTurboRpm = rpm;
            turboArray284[0] = 0;
            turboArray284[auxiliaryTurboCount] = maximumRpm;
            const int step = static_cast<int>(static_cast<float>(maximumRpm) / static_cast<float>(auxiliaryTurboCount));
            for (int i = auxiliaryTurboCount - 1; i != 0; --i)
                turboArray284[i] = turboArray284[i + 1] - step;
        }
        auxiliaryTurboGain = settings->auxiliaryTurboGain;
    }
    engineSoundsEnabled = true;
}

void CarSounds::UpdateStartupSound()
{
    const float volume = masterVolume;
    const float gain = startupGain;
    if (!s_SoundCallbacks.isSoundPlaying(startupSound, startupChannel))
        startupChannel = s_SoundCallbacks.play(startupSound, false, volume * gain, 1.0f);
}

void CarSounds::UpdateClutchSound()
{
    if (clutchTriggered)
        clutchChannel = s_SoundCallbacks.play(clutchSoundId, false, masterVolume * clutchVolume, 1.0f);
}

bool IsSoundPlayingStub(int, int) { return false; }
int PlayStub(int, bool, float, float) { return -1; }
void StopStub(int, int) {}
void SetPitchStub(int, int, float) {}
void SetVolumeStub(int, int, float) {}

CarSoundCallbacks::CarSoundCallbacks()
    : isSoundPlaying(IsSoundPlayingStub), play(PlayStub), stop(StopStub),
      setPitch(SetPitchStub), setVolume(SetVolumeStub)
{
}

CarSoundCallbacks::~CarSoundCallbacks() {}

CarSoundCallbacks& CarSoundCallbacks::operator=(const CarSoundCallbacks& other)
{
    isSoundPlaying = other.isSoundPlaying;
    play = other.play;
    stop = other.stop;
    setPitch = other.setPitch;
    setVolume = other.setVolume;
    return *this;
}

void CarSounds::RegisterCallbacks(const CarSoundCallbacks& value)
{
    s_SoundCallbacks = value;
}

extern void* __dso_handle;
extern "C" int __aeabi_atexit(void*, void (*)(void*), void*);
extern "C" {
static void __tcf_0() __attribute__((used));
static void __tcf_0()
{
    CarSounds::s_SoundCallbacks.~CarSoundCallbacks();
}
}

static void __static_initialization_and_destruction_0(int initialize, int priority) __attribute__((used));
static void __static_initialization_and_destruction_0(int initialize, int priority)
{
    if (initialize == 1 && priority == 65535) {
        new (&CarSounds::s_SoundCallbacks) CarSoundCallbacks();
        __aeabi_atexit(0, reinterpret_cast<void (*)(void*)>(__tcf_0), &__dso_handle);
    }
}

extern "C" {
static void _GLOBAL__I__ZN18CarSoundParametersC2Ev() __attribute__((used));
static void _GLOBAL__I__ZN18CarSoundParametersC2Ev()
{
    __static_initialization_and_destruction_0(1, 65535);
}
}

void CarSounds::UnregisterCallbacks()
{
    CarSoundCallbacks callbacks;
    s_SoundCallbacks = callbacks;
}

void CarSounds::AddTurboSounds(TurboSoundSettings* settings)
{
    if (!engineSoundsEnabled)
        return;

    turboEnabled = true;
    useRpmCopyB = settings->customPrimaryRpm;
    if (useRpmCopyB) {
        turboRpm = settings->primaryRpm;
        turboMaximumRpm = settings->primaryRpm244;
        turboMinimumRpm = settings->primaryRpm248;
        turboReferenceRpm = settings->primaryRpm236;
        secondaryTurboMaximumRpm = settings->primaryRpm264;
        secondaryTurboMinimumRpm = settings->primaryRpm268;
    } else {
        turboRpm = rpm;
        turboReferenceRpm = static_cast<int>(static_cast<float>(maximumRpm) * 0.3f);
        turboMaximumRpm = static_cast<int>(static_cast<float>(maximumRpm) * 0.6f);
        turboMinimumRpm = static_cast<int>(static_cast<float>(maximumRpm) * 0.08f);
        secondaryTurboMaximumRpm = maximumRpm;
        secondaryTurboMinimumRpm = 0;
    }
    turboSoundId = settings->primarySoundId;
    turboChannel = -1;
    turboPitchMix = 1.0f - settings->blend;
    turboGain = settings->primaryGain;
    secondaryTurboSoundId = settings->secondarySoundId;
    secondaryTurboChannel = -1;
    secondaryTurboGain = settings->secondaryGain;

    auxiliaryTurboCount = settings->auxiliaryCount;
    auxiliaryTurboIds = new int[auxiliaryTurboCount];
    auxiliaryTurboChannels = new int[auxiliaryTurboCount];
    for (int i = 0; i < auxiliaryTurboCount; ++i) {
        auxiliaryTurboIds[i] = settings->auxiliaryTurboIds[i];
        auxiliaryTurboChannels[i] = -1;
    }

    const int rpmCount = auxiliaryTurboCount + 1;
    turboArray284 = new int[rpmCount];
    useRpmCopyA = settings->customSecondaryRpm;
    if (useRpmCopyA) {
        secondaryTurboRpm = settings->secondaryRpm;
        for (int i = 0; i < rpmCount; ++i)
            turboArray284[i] = settings->auxiliaryTurboThresholds[i];
    } else {
        secondaryTurboRpm = rpm;
        turboArray284[0] = 0;
        turboArray284[auxiliaryTurboCount] = maximumRpm;
        const int step = static_cast<int>(static_cast<float>(maximumRpm) / static_cast<float>(auxiliaryTurboCount));
        for (int i = auxiliaryTurboCount - 1; i != 0; --i)
            turboArray284[i] = turboArray284[i + 1] - step;
    }
    auxiliaryTurboGain = settings->auxiliaryTurboGain;
}

void CarSounds::UpdateOnEngineSounds()
{
    int previousUpper;
    int id;
    int channel;
    int reference;
    int lower;
    int upper;
    int nextLower;
    int minimum;
    int maximum;
    int margin;
    int* lowers;
    bool playing;
    float pitch;
    float volume;
    float gain;
    int i;
    int engineRpm;
    const int state = onFade->GetState();
    const int remaining = onFade->GetNbRemainingFades();
    if (state == 2 && remaining == 0) {
        for (i = 0; i < onEngineCount; ++i) {
            s_SoundCallbacks.stop(onEngineIds[i], onEngineChannels[i]);
            onEngineChannels[i] = -1;
            onEngineActive = 0;
        }
    } else if (state == 1 && remaining == s_onOffCrossFadeDuration) {
        onEngineActive = 1;
    }
    if (onEngineActive != 1)
        return;

    if (state == 0)
        gain = onEngineGain * masterVolume;
    else
        gain = onEngineGain * masterVolume * onFade->GetVolume();

    previousUpper = 0;
    for (i = 0; i < onEngineCount; ++i) {
        id = onEngineIds[i];
        channel = onEngineChannels[i];
        reference = static_cast<int*>(engineArray88)[i];
        lowers = static_cast<int*>(engineArray92);
        lower = lowers[i];
        upper = static_cast<int*>(engineArray96)[i];
        if (i < onEngineCount - 1)
            nextLower = lowers[i + 1];
        else
            nextLower = maximumRpm;
        margin = rpmMargin;
        minimum = lower - margin;
        maximum = upper + margin;
        playing = s_SoundCallbacks.isSoundPlaying(id, channel);
        if (playing && ((engineRpm = rpm) < minimum || engineRpm > maximum)) {
            s_SoundCallbacks.stop(id, channel);
            onEngineChannels[i] = -1;
        } else if (playing || ((engineRpm = rpm) >= lower && engineRpm <= upper)) {
            pitch = static_cast<float>(engineRpm) / static_cast<float>(reference);
            if (engineRpm < lower)
                volume = 0.0f;
            else if (engineRpm < previousUpper)
                volume = InterpolateLinear(lower, previousUpper, engineRpm, 0.0f, gain);
            else if (engineRpm < nextLower)
                volume = gain;
            else if (engineRpm < upper)
                volume = InterpolateLinear(nextLower, upper, engineRpm, gain, 0.0f);
            else
                volume = 0.0f;
            if (!playing) {
                onEngineChannels[i] = s_SoundCallbacks.play(id, true, volume, pitch);
            } else {
                s_SoundCallbacks.setVolume(id, channel, volume);
                s_SoundCallbacks.setPitch(id, channel, pitch);
            }
        }
        previousUpper = upper;
    }
}


void CarSounds::UpdateTurboSounds()
{
    const float primaryGain = masterVolume * turboGain;
    float volume;
    if (turboRpm > turboMaximumRpm)
        volume = primaryGain;
    else if (turboRpm > turboMinimumRpm)
        volume = InterpolateFlatEnded(turboMinimumRpm, turboMaximumRpm, turboRpm, 0.0f, primaryGain);
    else
        volume = 0.0f;
    const float ratio = static_cast<float>(turboRpm) / static_cast<float>(turboReferenceRpm);
    const float pitchOffset = (1.0f - ratio) * turboPitchMix;
    const float pitch = ratio + pitchOffset;
    if (!s_SoundCallbacks.isSoundPlaying(turboSoundId, turboChannel)) {
        turboChannel = s_SoundCallbacks.play(turboSoundId, true, volume, pitch);
    } else {
        s_SoundCallbacks.setVolume(turboSoundId, turboChannel, volume);
        s_SoundCallbacks.setPitch(turboSoundId, turboChannel, pitch);
    }

    const float secondaryGain = masterVolume * secondaryTurboGain;
    if (turboRpm > secondaryTurboMaximumRpm)
        volume = secondaryGain;
    else if (turboRpm > secondaryTurboMinimumRpm)
        volume = InterpolateFlatEnded(secondaryTurboMinimumRpm, secondaryTurboMaximumRpm, turboRpm, 0.0f, secondaryGain);
    else
        volume = 0.0f;
    if (!s_SoundCallbacks.isSoundPlaying(secondaryTurboSoundId, secondaryTurboChannel))
        secondaryTurboChannel = s_SoundCallbacks.play(secondaryTurboSoundId, true, volume, 1.0f);
    else
        s_SoundCallbacks.setVolume(secondaryTurboSoundId, secondaryTurboChannel, volume);

    if (clutchTriggered || (load == 0 && previousLoad != 0)) {
        int index = 1;
        int threshold = turboArray284[index];
        while (threshold < secondaryTurboRpm && index <= auxiliaryTurboCount) {
            ++index;
            threshold = turboArray284[index];
        }
        if (secondaryTurboRpm > turboArray284[0] && secondaryTurboRpm < turboArray284[auxiliaryTurboCount]) {
            const int id = auxiliaryTurboIds[index - 1];
            const float volumeScale = masterVolume;
            const float gain = auxiliaryTurboGain;
            if (!s_SoundCallbacks.isSoundPlaying(id, auxiliaryTurboChannels[index - 1]))
                auxiliaryTurboChannels[index - 1] = s_SoundCallbacks.play(id, false, volumeScale * gain, 1.0f);
        }
    }
}
