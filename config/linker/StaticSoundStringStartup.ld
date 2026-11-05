OUTPUT_FORMAT("elf32-littlearm")
OUTPUT_ARCH(arm)
INCLUDE build/matches/string-startup-staticsound/retail-symbols.ld
_ZdlPv = 0x001c42b0;
__aeabi_atexit = 0x001c494c;
_Znwj = 0x001c4814;
_Znaj = 0x001c3ff8;
_ZdaPv = 0x001c461c;
SECTIONS
{
    .string_startup_function_0 0x00353b50 : { *string-startup-staticsound.o(.text.__tcf_0) }
    .string_startup_function_1 0x00353e18 : { *string-startup-staticsound.o(.text._Z41__static_initialization_and_destruction_0ii) }
    .string_startup_function_2 0x00353e70 : { *string-startup-staticsound.o(.text._GLOBAL__I__ZN11StaticSoundC2Ev) }
    .string_startup_storage_0 0x004bc224 (NOLOAD) : { *string-startup-staticsound.o(.bss._ZN3irr5scene6quake315irrEmptyStringcE) }
    .static_sound_method_0 0x00353b80 : { *string-startup-staticsound.o(.text._ZN17CStaticSoundsPoolD1Ev .text._ZN17CStaticSoundsPoolD2Ev) }
    .static_sound_method_1 0x00353bcc : { *string-startup-staticsound.o(.text._ZN11StaticSound4StopEi) }
    .static_sound_method_2 0x00353bd8 : { *string-startup-staticsound.o(.text._ZN11StaticSound6UnInitEv) }
    .static_sound_method_3 0x00353be4 : { *string-startup-staticsound.o(.text._ZN17CStaticSoundsPool18ReleaseStaticSoundEP11StaticSound) }
    .static_sound_method_4 0x00353c70 : { *string-startup-staticsound.o(.text._ZN11StaticSound4InitEP10CSoundData) }
    .static_sound_method_5 0x00353c7c : { *string-startup-staticsound.o(.text._ZN11StaticSoundD0Ev) }
    .static_sound_method_6 0x00353ca4 : { *string-startup-staticsound.o(.text._ZN11StaticSoundD2Ev .text._ZN11StaticSoundD1Ev) }
    .static_sound_method_7 0x00353cc4 : { *string-startup-staticsound.o(.text._ZN11StaticSoundC2EP10CSoundData .text._ZN11StaticSoundC1EP10CSoundData) }
    .static_sound_method_8 0x00353ce8 : { *string-startup-staticsound.o(.text._ZN11StaticSoundC2Ev .text._ZN11StaticSoundC1Ev) }
    .static_sound_method_9 0x00353d0c : { *string-startup-staticsound.o(.text._ZN17CStaticSoundsPool14GetStaticSoundEP10CSoundData) }
    .static_sound_method_10 0x00353d90 : { *string-startup-staticsound.o(.text._ZN17CStaticSoundsPoolC2Eii .text._ZN17CStaticSoundsPoolC1Eii) }
    .static_sound_vtable 0x004ad868 : { *string-startup-staticsound.o(.data.rel.ro._ZTV11StaticSound .gnu.linkonce.d.rel.ro._ZTV11StaticSound) }
    .shared_startup_empty_text 0x0044d91c : { *(.gnu.linkonce.r.localStartupEmptyText) }
    .got 0x004b0048 : { *(.got.plt) . = 0x360; *(.got) }
    .verification 0x00600000 : { *retail-got.o(.text) }
}
ASSERT(SIZEOF(.string_startup_storage_0) == 32, "_ZN3irr5scene6quake315irrEmptyStringcE extent");
