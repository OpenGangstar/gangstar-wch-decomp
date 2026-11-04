OUTPUT_FORMAT("elf32-littlearm")
OUTPUT_ARCH(arm)
INCLUDE build/matches/sdk-startup-csound/retail-symbols.ld
_ZdlPv = 0x001c42b0;
__aeabi_atexit = 0x001c494c;
__aeabi_fmul = 0x001c4724;
__aeabi_i2f = 0x001c41e4;
__aeabi_fdiv = 0x001c4520;
SECTIONS
{
    .sdk_startup_function_0 0x0035092c : { *sdk-startup-csound.o(.text.__tcf_2) }
    .sdk_startup_function_1 0x003509e4 : { *sdk-startup-csound.o(.text._Z41__static_initialization_and_destruction_0ii) }
    .sdk_startup_function_2 0x00350a50 : { *sdk-startup-csound.o(.text._GLOBAL__I__ZN6CSound16s_pALSourcesPoolE) }
    .sdk_startup_storage_0 0x004bc17c (NOLOAD) : { *sdk-startup-csound.o(.bss._ZN3irr5scene6quake315irrEmptyStringcE) }
    .sdk_startup_storage_1 0x004bc19c (NOLOAD) : { *sdk-startup-csound.o(.bss._ZN3irr2ps5vHalfE) }
    .shared_startup_empty_text 0x0044d91c : { *(.gnu.linkonce.r.localStartupEmptyText) }
    .got 0x004b0048 : { *(.got.plt) . = 0x360; *(.got) }
    .verification 0x00600000 : { *retail-got.o(.text) }
    .csound_function_0 0x00350884 : { *sdk-startup-csound.o(.text._ZN6CSoundC2Ev .text._ZN6CSoundC1Ev ) }
    .csound_function_1 0x0035089c : { *sdk-startup-csound.o(.text._ZN6CSoundC2EP10CSoundData .text._ZN6CSoundC1EP10CSoundData ) }
    .csound_function_2 0x003508d0 : { *sdk-startup-csound.o(.text._ZN6CSound4InitEP10CSoundData ) }
    .csound_function_3 0x003508d4 : { *sdk-startup-csound.o(.text._ZN6CSound12InitALSourceEv ) }
    .csound_function_4 0x003508d8 : { *sdk-startup-csound.o(.text._ZN6CSound20InitStaticParametersEP13ALSourcesPool ) }
    .csound_function_5 0x003508ec : { *sdk-startup-csound.o(.text._ZN6CSound6UnInitEv ) }
    .csound_function_6 0x003508f0 : { *sdk-startup-csound.o(.text._ZNK6CSound9GetStatusEv ) }
    .csound_function_7 0x003508f4 : { *sdk-startup-csound.o(.text._ZN6CSound4PlayEbfi ) }
    .csound_function_8 0x003508f8 : { *sdk-startup-csound.o(.text._ZN6CSound4StopEi ) }
    .csound_function_9 0x003508fc : { *sdk-startup-csound.o(.text._ZN6CSound5PauseEv ) }
    .csound_function_10 0x00350900 : { *sdk-startup-csound.o(.text._ZN6CSound6ResumeEv ) }
    .csound_function_11 0x00350904 : { *sdk-startup-csound.o(.text._ZN6CSound11SetPositionERKN3irr4core8vector3dIfEE ) }
    .csound_function_12 0x00350908 : { *sdk-startup-csound.o(.text._ZN6CSound6UpdateEi ) }
    .csound_function_13 0x0035090c : { *sdk-startup-csound.o(.text._ZN6CSound12_performFadeEi ) }
    .csound_function_14 0x00350910 : { *sdk-startup-csound.o(.text._ZN6CSound17QueueStreamBufferEPcii ) }
    .csound_function_15 0x00350914 : { *sdk-startup-csound.o(.text._ZN6CSound18GetProcessedBufferEv ) }
    .csound_function_16 0x00350918 : { *sdk-startup-csound.o(.text._ZN6CSound9SetVolumeEf ) }
    .csound_function_17 0x0035091c : { *sdk-startup-csound.o(.text._ZN6CSound8SetPitchEf ) }
    .csound_function_18 0x00350920 : { *sdk-startup-csound.o(.text._ZN6CSound12GetSoundDataEv ) }
    .csound_function_19 0x00350924 : { *sdk-startup-csound.o(.text._ZN13ALSourcesPoolC1Eii .text._ZN13ALSourcesPoolC2Eii ) }
    .csound_function_20 0x00350928 : { *sdk-startup-csound.o(.text._ZN13ALSourcesPoolD2Ev .text._ZN13ALSourcesPoolD1Ev ) }
    .csound_function_21 0x0035095c : { *sdk-startup-csound.o(.text._ZN6CSoundD0Ev ) }
    .csound_function_22 0x0035097c : { *sdk-startup-csound.o(.text._ZN6CSoundD2Ev .text._ZN6CSoundD1Ev ) }
    .csound_function_23 0x00350994 : { *sdk-startup-csound.o(.text._ZNK6CSound17GetAbsoluteVolumeEv ) }
    .csound_vtable 0x004ad6f8 : { *sdk-startup-csound.o(.gnu.linkonce.d.rel.ro._ZTV6CSound .data.rel.ro._ZTV6CSound) }
    .csound_pool 0x004bc178 (NOLOAD) : { *sdk-startup-csound.o(.bss._ZN6CSound16s_pALSourcesPoolE) }
}
ASSERT(SIZEOF(.sdk_startup_storage_0) == 32, "_ZN3irr5scene6quake315irrEmptyStringcE extent");
ASSERT(SIZEOF(.sdk_startup_storage_1) == 12, "_ZN3irr2ps5vHalfE extent");
