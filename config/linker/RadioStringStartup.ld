OUTPUT_FORMAT("elf32-littlearm")
OUTPUT_ARCH(arm)
INCLUDE build/matches/string-startup-radio/retail-symbols.ld
_ZdlPv = 0x001c42b0;
__aeabi_atexit = 0x001c494c;
_Znwj = 0x001c4814;
SECTIONS
{
    .string_startup_function_0 0x0032a6a4 : { *string-startup-radio.o(.text.__tcf_0) }
    .string_startup_function_1 0x0032a8f4 : { *string-startup-radio.o(.text._Z41__static_initialization_and_destruction_0ii) }
    .string_startup_function_2 0x0032a94c : { *string-startup-radio.o(.text._GLOBAL__I__ZN5RadioC2EP7ASpriteiiiiii) }
    .string_startup_storage_0 0x004b9618 (NOLOAD) : { *string-startup-radio.o(.bss._ZN3irr5scene6quake315irrEmptyStringcE) }
    .radio_method_0 0x0032a660 : { *string-startup-radio.o(.text._ZN5Radio4showEv .gnu.linkonce.t._ZN5Radio4showEv) }
    .radio_method_1 0x0032a714 : { *string-startup-radio.o(.text._ZThn4_N5RadioD0Ev .gnu.linkonce.t._ZN5RadioD0Ev) }
    .radio_method_3 0x0032a774 : { *string-startup-radio.o(.text._ZThn4_N5RadioD1Ev .gnu.linkonce.t._ZN5RadioD1Ev) }
    .radio_method_5 0x0032a7cc : { *string-startup-radio.o(.text._ZThn4_NK5Radio6draw2dEv) }
    .radio_method_6 0x0032a7e0 : { *string-startup-radio.o(.text._ZNK5Radio6draw2dEv) }
    .radio_method_7 0x0032a814 : { *string-startup-radio.o(.text._ZN5RadioC2EP7ASpriteiiiiii .text._ZN5RadioC1EP7ASpriteiiiiii) }
    .radio_method_8 0x0032a878 : { *string-startup-radio.o(.text._ZThn8_N5Radio12processTouchEl) }
    .radio_method_9 0x0032a88c : { *string-startup-radio.o(.text._ZN5Radio12processTouchEl) }
    .radio_swipe_destructor 0x0032a6d4 : { *string-startup-radio.o(.text._ZN11SwipeButtonD1Ev .gnu.linkonce.t._ZN11SwipeButtonD1Ev .text._ZN11SwipeButtonD2Ev .gnu.linkonce.t._ZN11SwipeButtonD2Ev) }
    .radio_vtable 0x004ac530 : { *string-startup-radio.o(.data.rel.ro._ZTV5Radio .gnu.linkonce.d.rel.ro._ZTV5Radio) }
    .shared_startup_empty_text 0x0044d91c : { *(.gnu.linkonce.r.localStartupEmptyText) }
    .got 0x004b0048 : { *(.got.plt) . = 0x360; *(.got) }
    .verification 0x00600000 : { *retail-got.o(.text) }
}
ASSERT(SIZEOF(.string_startup_storage_0) == 32, "_ZN3irr5scene6quake315irrEmptyStringcE extent");
