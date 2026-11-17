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
