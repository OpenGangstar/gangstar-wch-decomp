OUTPUT_FORMAT("elf32-littlearm")
OUTPUT_ARCH(arm)
INCLUDE build/matches/car-sound-callbacks/retail-symbols.ld
__aeabi_atexit = 0x001c494c;
__aeabi_fmul = 0x001c4724;
__aeabi_fsub = 0x001c4328;
__aeabi_f2iz = 0x001c44cc;
_ZdaPv = 0x001c461c;
_ZdlPv = 0x001c42b0;
_Znaj = 0x001c3ff8;
__aeabi_fadd = 0x001c4154;
__aeabi_i2f = 0x001c41e4;
__aeabi_dmul = 0x001c4298;
__aeabi_d2f = 0x001c4310;
__aeabi_dadd = 0x001c4394;
sin = 0x001c4478;
cos = 0x001c4430;
sqrt = 0x001c401c;
__aeabi_dsub = 0x001c4454;
__aeabi_fcmpeq = 0x001c470c;
__aeabi_fdiv = 0x001c4520;
__aeabi_f2d = 0x001c48f8;
SECTIONS
{
    .car_sounds_dtor 0x003502a8 : { *car-sound-callbacks.o(.text._ZN9CarSoundsD1Ev .text._ZN9CarSoundsD2Ev) }
    .car_sounds_ctor 0x0034f2a8 : { *car-sound-callbacks.o(.text._ZN9CarSoundsC1Ev .text._ZN9CarSoundsC2Ev) }
    .car_sounds_stop_all 0x0034f3a4 : { *car-sound-callbacks.o(.text._ZN9CarSounds13StopAllSoundsEv) }
    .car_sounds_rumble 0x0034f9a4 : { *car-sound-callbacks.o(.text._ZN9CarSounds17UpdateRumbleSoundEv) }
    .car_sound_linear 0x0034f360 : { *car-sound-callbacks.o(.text._ZN9CarSounds17InterpolateLinearEiiiff) }
    .car_sound_flat_ended 0x0034fb60 : { *car-sound-callbacks.o(.text._ZN9CarSounds20InterpolateFlatEndedEiiiff) }
    .car_sound_filter_coefficients 0x0034ff88 : { *car-sound-callbacks.o(.text._ZN9CarSounds24SetRPMFilterCoefficientsEf) }
    .car_sound_clean 0x0035020c : { *car-sound-callbacks.o(.text._ZN9CarSounds5CleanEv) }
    .car_sound_remove_turbo 0x0034f358 : { *car-sound-callbacks.o(.text._ZN9CarSounds17RemoveTurboSoundsEP18TurboSoundSettings) }
    .fade_start 0x0034f204 : { *car-sound-callbacks.o(.text._ZN9SoundFade9StartFadeEi) }
    .fade_update 0x0034f250 : { *car-sound-callbacks.o(.text._ZN9SoundFade6UpdateEv) }
    .rpm_filter 0x0034f2dc : { *car-sound-callbacks.o(.text._ZN9CarSounds15FilterRPMValuesEi) }
    .fade_ctor 0x0034f1ec : { *car-sound-callbacks.o(.text._ZN9SoundFadeC1Ev .text._ZN9SoundFadeC2Ev) }
    .fade_dtor 0x0034f1f4 : { *car-sound-callbacks.o(.text._ZN9SoundFadeD1Ev .text._ZN9SoundFadeD2Ev) }
    .fade_count 0x0034f1f8 : { *car-sound-callbacks.o(.text._ZN9SoundFade19GetNbRemainingFadesEv) }
    .fade_state 0x0034f1fc : { *car-sound-callbacks.o(.text._ZN9SoundFade8GetStateEv) }
    .fade_volume 0x0034f200 : { *car-sound-callbacks.o(.text._ZN9SoundFade9GetVolumeEv) }
    .fade_clean 0x003501e8 : { *car-sound-callbacks.o(.text._ZN9SoundFade5CleanEv) }
    .sound_fade_gains 0x00350380 : { *car-sound-callbacks.o(.text._ZN9SoundFade13InitFadeGainsEi) }
    .car_sound_parameters_ctor 0x0034f150 : { *car-sound-callbacks.o(.text._ZN18CarSoundParametersC1Ev .text._ZN18CarSoundParametersC2Ev) }
    .car_sound_parameters_dtor 0x0034f154 : { *car-sound-callbacks.o(.text._ZN18CarSoundParametersD1Ev .text._ZN18CarSoundParametersD2Ev) }
    .car_sound_update 0x0034fdf4 : { *car-sound-callbacks.o(.text._ZN9CarSounds6UpdateEP18CarSoundParameters) }
    .car_sound_crossfade 0x00350440 : { *car-sound-callbacks.o(.text._ZN9CarSounds23InitOnOffCrossFadeGainsEi) }
    .car_sound_startup 0x0034fa8c : { *car-sound-callbacks.o(.text._ZN9CarSounds18UpdateStartupSoundEv) }
    .car_sound_clutch 0x0034f514 : { *car-sound-callbacks.o(.text._ZN9CarSounds17UpdateClutchSoundEv) }
    .car_sound_unregister 0x0034f32c : { *(.text._ZN9CarSounds19UnregisterCallbacksEv) }
    .callback_function_0 0x0034f17c : { *car-sound-callbacks.o(.text._Z18IsSoundPlayingStubii) }
    .callback_function_1 0x0034f180 : { *car-sound-callbacks.o(.text._Z8PlayStubibff) }
    .callback_function_2 0x0034f188 : { *car-sound-callbacks.o(.text._Z8StopStubii) }
    .callback_function_3 0x0034f18c : { *car-sound-callbacks.o(.text._Z12SetPitchStubiif) }
    .callback_function_4 0x0034f190 : { *car-sound-callbacks.o(.text._Z13SetVolumeStubiif) }
    .callback_function_5 0x0034f194 : { *car-sound-callbacks.o(.text._ZN17CarSoundCallbacksC1Ev) }
    .callback_function_7 0x0034f1d0 : { *car-sound-callbacks.o(.text._ZN17CarSoundCallbacksD1Ev) }
    .callback_function_9 0x0034f1d4 : { *car-sound-callbacks.o(.text._ZN17CarSoundCallbacksaSERKS_) }
    .callback_function_10 0x0034f30c : { *car-sound-callbacks.o(.text._ZN9CarSounds17RegisterCallbacksERK17CarSoundCallbacks) }
    .callback_function_11 0x0034faec : { *car-sound-callbacks.o(.text.__tcf_0) }
    .callback_function_12 0x0034fb08 : { *car-sound-callbacks.o(.text._Z41__static_initialization_and_destruction_0ii) }
    .callback_function_13 0x0034fb48 : { *car-sound-callbacks.o(.text._GLOBAL__I__ZN18CarSoundParametersC2Ev) }
    .got 0x004b0048 : { *(.got.plt) . = 0x360; *(.got) }
    .verification 0x00600000 : { *retail-got.o(.text) }
}
