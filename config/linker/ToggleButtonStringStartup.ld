OUTPUT_FORMAT("elf32-littlearm")
OUTPUT_ARCH(arm)
INCLUDE build/matches/string-startup-togglebutton/retail-symbols.ld
_ZdlPv = 0x001c42b0;
__aeabi_atexit = 0x001c494c;
SECTIONS
{
    .toggle_ctor 0x0032c384 : { *(.text._ZN12ToggleButtonC1EP7ASpriteii .text._ZN12ToggleButtonC2EP7ASpriteii) }
    .toggle_delete_thunk 0x0032c284 : { *(.gnu.linkonce.t._ZN12ToggleButtonD0Ev) }
    .toggle_dtor_thunk 0x0032c2d0 : { *(.gnu.linkonce.t._ZN12ToggleButtonD1Ev) }
    .toggle_vtable 0x004ac830 : { *(.data.rel.ro._ZTV12ToggleButton) }
    .toggle_press 0x0032c234 : { *(.gnu.linkonce.t._ZN12ToggleButton12processTouchEl) }
    .toggle_release 0x0032c368 : { *(.text._ZN12ToggleButton19processTouchReleaseEv) }
    .toggle_draw 0x0032c328 : { *(.text._ZNK12ToggleButton6draw2dEv) }
    .toggle_release_thunk 0x0032c354 : { *(.text._ZThn8_N12ToggleButton19processTouchReleaseEv) }
    .toggle_draw_thunk 0x0032c314 : { *(.text._ZThn4_NK12ToggleButton6draw2dEv) }
    .string_startup_function_0 0x0032c254 : { *string-startup-togglebutton.o(.text.__tcf_0) }
    .string_startup_function_1 0x0032c3c4 : { *string-startup-togglebutton.o(.text._Z41__static_initialization_and_destruction_0ii) }
    .string_startup_function_2 0x0032c41c : { *string-startup-togglebutton.o(.text._GLOBAL__I__ZN12ToggleButtonC2EP7ASpriteii) }
    .string_startup_storage_0 0x004b97e0 (NOLOAD) : { *string-startup-togglebutton.o(.bss._ZN3irr5scene6quake315irrEmptyStringcE) }
    .shared_startup_empty_text 0x0044d91c : { *(.gnu.linkonce.r.localStartupEmptyText) }
    .got 0x004b0048 : { *(.got.plt) . = 0x360; *(.got) }
    .verification 0x00600000 : { *retail-got.o(.text) }
}
ASSERT(SIZEOF(.string_startup_storage_0) == 32, "_ZN3irr5scene6quake315irrEmptyStringcE extent");
