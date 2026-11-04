OUTPUT_FORMAT("elf32-littlearm")
OUTPUT_ARCH(arm)
INCLUDE build/matches/string-startup-csounddata/retail-symbols.ld
_ZdlPv = 0x001c42b0;
__aeabi_atexit = 0x001c494c;
_Znaj = 0x001c3ff8;
_Znwj = 0x001c4814;
_ZdaPv = 0x001c461c;
SECTIONS
{
    .string_startup_function_0 0x00350b40 : { *string-startup-csounddata.o(.text.__tcf_0) }
    .string_startup_function_1 0x00350d20 : { *string-startup-csounddata.o(.text._Z41__static_initialization_and_destruction_0ii) }
    .string_startup_function_2 0x00350d78 : { *string-startup-csounddata.o(.text._GLOBAL__I__ZN10CSoundDataC2Ev) }
    .string_startup_storage_0 0x004bc1a8 (NOLOAD) : { *string-startup-csounddata.o(.bss._ZN3irr5scene6quake315irrEmptyStringcE) }
    .shared_startup_empty_text 0x0044d91c : { *(.gnu.linkonce.r.localStartupEmptyText) }
    .got 0x004b0048 : { *(.got.plt) . = 0x360; *(.got) }
    .verification 0x00600000 : { *retail-got.o(.text) }
    .csounddata_function_0 0x00350a64 : { *string-startup-csounddata.o(.text._ZN10CSoundDataC1Ev .text._ZN10CSoundDataC2Ev) }
    .csounddata_function_1 0x00350a80 : { *string-startup-csounddata.o(.text._ZN10CSoundDataC1EiiiiPcib .text._ZN10CSoundDataC2EiiiiPcib) }
    .csounddata_function_2 0x00350aac : { *string-startup-csounddata.o(.text._ZN10CSoundData4InitEiiiiPci) }
    .csounddata_function_3 0x00350ab0 : { *string-startup-csounddata.o(.text._ZN10CSoundData6UnInitEv) }
    .csounddata_function_4 0x00350b70 : { *string-startup-csounddata.o(.text._ZN10CSoundDataD0Ev) }
    .csounddata_function_5 0x00350b90 : { *string-startup-csounddata.o(.text._ZN10CSoundDataD2Ev .text._ZN10CSoundDataD1Ev) }
    .csounddata_vtable 0x004ad728 : { *string-startup-csounddata.o(.gnu.linkonce.d.rel.ro._ZTV10CSoundData .data.rel.ro._ZTV10CSoundData) }
    .csounddata_pool_0 0x00350ab4 : { *string-startup-csounddata.o(.text._ZN14CSoundDataPool16ReleaseSoundDataEP10CSoundData) }
    .csounddata_pool_1 0x00350ba8 : { *string-startup-csounddata.o(.text._ZN14CSoundDataPool12GetSoundDataEiiiiPci) }
    .csounddata_pool_2 0x00350c4c : { *string-startup-csounddata.o(.text._ZN14CSoundDataPoolD1Ev .text._ZN14CSoundDataPoolD2Ev) }
    .csounddata_pool_3 0x00350c98 : { *string-startup-csounddata.o(.text._ZN14CSoundDataPoolC1Eii .text._ZN14CSoundDataPoolC2Eii) }
}
ASSERT(SIZEOF(.string_startup_storage_0) == 32, "_ZN3irr5scene6quake315irrEmptyStringcE extent");
