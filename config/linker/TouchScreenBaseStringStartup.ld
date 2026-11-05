OUTPUT_FORMAT("elf32-littlearm")
OUTPUT_ARCH(arm)
INCLUDE build/matches/string-startup-touchscreenbase/retail-symbols.ld
_ZdlPv = 0x001c42b0;
__aeabi_atexit = 0x001c494c;
SECTIONS
{
    .touchscreen_dimension_out 0x0034c5fc : { *string-startup-touchscreenbase.o(.text._ZNK15TouchScreenBase12getDimensionER3RctIsE) }
    .touchscreen_dimension_value 0x0034c6a4 : { *string-startup-touchscreenbase.o(.text._ZNK15TouchScreenBase12getDimensionEv) }
    .string_startup_function_0 0x0034c724 : { *string-startup-touchscreenbase.o(.text.__tcf_0) }
    .string_startup_function_1 0x0034cb10 : { *string-startup-touchscreenbase.o(.text._Z41__static_initialization_and_destruction_0ii) }
    .string_startup_function_2 0x0034cb68 : { *string-startup-touchscreenbase.o(.text._GLOBAL__I__ZN15TouchScreenBase14CLEAN_UP_DELAYE) }
    .touchscreen_rct_d0 0x0034c754 : { *string-startup-touchscreenbase.o(.text._ZN3RctIsED0Ev .gnu.linkonce.t._ZN3RctIsED0Ev) }
    .touchscreen_rct_d1 0x0034c774 : { *string-startup-touchscreenbase.o(.text._ZN3RctIsED1Ev .gnu.linkonce.t._ZN3RctIsED1Ev) }
    .touchscreen_rct_vtable 0x004ad348 : { *string-startup-touchscreenbase.o(.gnu.linkonce.d.rel.ro._ZTV3RctIsE) }
    .string_startup_storage_0 0x004bc060 (NOLOAD) : { *string-startup-touchscreenbase.o(.bss._ZN3irr5scene6quake315irrEmptyStringcE) }
    .shared_startup_empty_text 0x0044d91c : { *(.gnu.linkonce.r.localStartupEmptyText) }
    .got 0x004b0048 : { *(.got.plt) . = 0x360; *(.got) }
    .verification 0x00600000 : { *retail-got.o(.text) }
}
ASSERT(SIZEOF(.string_startup_storage_0) == 32, "_ZN3irr5scene6quake315irrEmptyStringcE extent");
