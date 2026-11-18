PROVIDE(memset = 0x001c45d4);
PROVIDE(memcpy = 0x001c4190);
PROVIDE(__aeabi_i2f = 0x001c41e4);
PROVIDE(__aeabi_fmul = 0x001c4724);
PROVIDE(__aeabi_fadd = 0x001c4154);
OUTPUT_FORMAT("elf32-littlearm")
OUTPUT_ARCH(arm)
INCLUDE build/matches/sdk-startup-targetmarker/retail-symbols.ld
_ZdlPv = 0x001c42b0;
__aeabi_atexit = 0x001c494c;
SECTIONS
{
    .target_marker_draw 0x0032be74 : { *sdk-startup-targetmarker.o(.text._ZNK12TargetMarker4drawEv) }
    .target_marker_destroy 0x0032be20 : { *sdk-startup-targetmarker.o(.text._ZN12TargetMarkerD1Ev .text._ZN12TargetMarkerD2Ev) }
    .target_marker_init 0x0032be24 : { *sdk-startup-targetmarker.o(.text._ZN12TargetMarker4initEP7ASpriteii) }
    .target_marker_construct 0x0032be5c : { *sdk-startup-targetmarker.o(.text._ZN12TargetMarkerC1Ev .text._ZN12TargetMarkerC2Ev) }
    .sdk_startup_function_0 0x0032be2c : { *sdk-startup-targetmarker.o(.text.__tcf_3) }
    .sdk_startup_function_1 0x0032c1b4 : { *sdk-startup-targetmarker.o(.text._Z41__static_initialization_and_destruction_0ii) }
    .sdk_startup_function_2 0x0032c220 : { *sdk-startup-targetmarker.o(.text._GLOBAL__I__ZN12TargetMarkerC2Ev) }
    .sdk_startup_storage_0 0x004b97b4 (NOLOAD) : { *sdk-startup-targetmarker.o(.bss._ZN3irr5scene6quake315irrEmptyStringcE) }
    .sdk_startup_storage_1 0x004b97d4 (NOLOAD) : { *sdk-startup-targetmarker.o(.bss._ZN3irr2ps5vHalfE) }
    .shared_startup_empty_text 0x0044d91c : { *(.gnu.linkonce.r.localStartupEmptyText) }
    .got 0x004b0048 : { *(.got.plt) . = 0x360; *(.got) }
    .verification 0x00600000 : { *retail-got.o(.text) }
}
ASSERT(SIZEOF(.sdk_startup_storage_0) == 32, "_ZN3irr5scene6quake315irrEmptyStringcE extent");
ASSERT(SIZEOF(.sdk_startup_storage_1) == 12, "_ZN3irr2ps5vHalfE extent");
