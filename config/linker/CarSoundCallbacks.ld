OUTPUT_FORMAT("elf32-littlearm")
OUTPUT_ARCH(arm)
INCLUDE build/matches/car-sound-callbacks/retail-symbols.ld
__aeabi_atexit = 0x001c494c;
__aeabi_fmul = 0x001c4724;
_Znaj = 0x001c3ff8;
__aeabi_fadd = 0x001c4154;
__aeabi_i2f = 0x001c41e4;
__aeabi_dmul = 0x001c4298;
__aeabi_d2f = 0x001c4310;
__aeabi_dadd = 0x001c4394;
sin = 0x001c4478;
__aeabi_fdiv = 0x001c4520;
__aeabi_f2d = 0x001c48f8;
SECTIONS
{
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
