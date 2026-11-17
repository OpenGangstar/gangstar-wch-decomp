OUTPUT_FORMAT("elf32-littlearm")
OUTPUT_ARCH(arm)
INCLUDE build/matches/sdk-startup-background/retail-symbols.ld
_ZdlPv = 0x001c42b0;
__aeabi_i2d = 0x001c452c;
__aeabi_dadd = 0x001c4394;
__aeabi_d2iz = 0x001c4844;
__aeabi_atexit = 0x001c494c;
SECTIONS
{
    .background_destructor_0 0x003275c8 : { *sdk-startup-background.o(.text._ZThn4_N10BackgroundD0Ev) }
    .background_destructor_1 0x003275dc : { *sdk-startup-background.o(.text._ZN10BackgroundD0Ev) }
    .background_destructor_2 0x0032760c : { *sdk-startup-background.o(.text._ZThn4_N10BackgroundD1Ev) }
    .background_destructor_3 0x00327620 : { *sdk-startup-background.o(.text._ZN10BackgroundD1Ev .text._ZN10BackgroundD2Ev) }
    .background_vtable 0x004ac098 : { *sdk-startup-background.o(.data.rel.ro._ZTV10Background .gnu.linkonce.d.rel.ro._ZTV10Background) }
    .background_update 0x003274f0 : { *sdk-startup-background.o(.text._ZN10Background6updateEd) }
    .background_draw_thunk 0x00327554 : { *sdk-startup-background.o(.text._ZThn4_NK10Background6draw2dEv) }
    .background_draw 0x00327568 : { *sdk-startup-background.o(.text._ZNK10Background6draw2dEv) }
    .background_constructor 0x0032764c : { *sdk-startup-background.o(.text._ZN10BackgroundC1EP7ASpritei .text._ZN10BackgroundC2EP7ASpritei) }
    .sdk_startup_function_0 0x00327524 : { *sdk-startup-background.o(.text.__tcf_2) }
    .sdk_startup_function_1 0x00327684 : { *sdk-startup-background.o(.text._Z41__static_initialization_and_destruction_0ii) }
    .sdk_startup_function_2 0x003276f0 : { *sdk-startup-background.o(.text._GLOBAL__I__ZN10BackgroundC2EP7ASpritei) }
    .sdk_startup_storage_0 0x004b9320 (NOLOAD) : { *sdk-startup-background.o(.bss._ZN3irr5scene6quake315irrEmptyStringcE) }
    .sdk_startup_storage_1 0x004b9340 (NOLOAD) : { *sdk-startup-background.o(.bss._ZN3irr2ps5vHalfE) }
    .shared_startup_empty_text 0x0044d91c : { *(.gnu.linkonce.r.localStartupEmptyText) }
    .got 0x004b0048 : { *(.got.plt) . = 0x360; *(.got) }
    .verification 0x00600000 : { *retail-got.o(.text) }
}
ASSERT(SIZEOF(.sdk_startup_storage_0) == 32, "_ZN3irr5scene6quake315irrEmptyStringcE extent");
ASSERT(SIZEOF(.sdk_startup_storage_1) == 12, "_ZN3irr2ps5vHalfE extent");
