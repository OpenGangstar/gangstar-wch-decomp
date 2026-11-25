PROVIDE(puts = 0x001c41b4);
PROVIDE(abort = 0x001c42d4);
OUTPUT_FORMAT("elf32-littlearm")
OUTPUT_ARCH(arm)
INCLUDE build/matches/sdk-startup-stringmanager/retail-symbols.ld
_ZdlPv = 0x001c42b0;
__aeabi_atexit = 0x001c494c;
memset = 0x001c45d4;
strlen = 0x001c48bc;
nativeStrlen = 0x001c48bc;
SECTIONS
{
    .string_unload_pack_sheet 0x0034b5a4 : { *sdk-startup-stringmanager.o(.text._ZN13StringManager15unloadPackSheetEjj) }
    .string_load_styles 0x0034bd50 : { *sdk-startup-stringmanager.o(.text._ZN13StringManager10loadStylesEPKc) }
    .string_style_default 0x00435fac : { *sdk-startup-stringmanager.o(.rodata._ZZN13StringManager10loadStylesEPKcE4C.* .rodata.C.*) }
    .string_data_stream_d1 0x002d3654 : { *sdk-startup-stringmanager.o(.text._ZN10DataStreamD1Ev .gnu.linkonce.t._ZN10DataStreamD1Ev) }
    .string_manager_d1 0x0034be9c : { *sdk-startup-stringmanager.o(.text._ZN13StringManagerD1Ev .text._ZN13StringManagerD2Ev) }
    .string_manager_d0 0x0034bf8c : { *sdk-startup-stringmanager.o(.text._ZN13StringManagerD0Ev) }
    .string_manager_vtable 0x004ad2c8 : { *sdk-startup-stringmanager.o(.data.rel.ro._ZTV13StringManager) }
 .string_out_of_range 0x34b6f4 : { *sdk-startup-stringmanager.o(.text._ZSt24__stl_throw_out_of_rangePKc .gnu.linkonce.t._ZSt24__stl_throw_out_of_rangePKc) }

    .string_get_text 0x0034bb5c : { *sdk-startup-stringmanager.o(.text._ZNK13StringManager9getStringEi) }
    .text_style_read 0x0034b648 : { *sdk-startup-stringmanager.o(.text._ZN7Structs9TextStyle4ReadER10DataStream) }
    .string_manager_ctor 0x0034b744 : { *sdk-startup-stringmanager.o(.text._ZN13StringManagerC1Ev .text._ZN13StringManagerC2Ev) }
    .string_pack_load 0x0034bb9c : { *sdk-startup-stringmanager.o(.text._ZN13StringManager8loadPackEj) }
    .string_reverse 0x0034b350 : { *sdk-startup-stringmanager.o(.text._Z6strRevPc) }
    .string_search_set 0x0034b374 : { *sdk-startup-stringmanager.o(.text._Z7strchrsPcPKc) }
    .pack_loaded 0x0034b2c4 : { *sdk-startup-stringmanager.o(.text._ZNK13StringManager12isPackLoadedEj) }
    .sheet_loaded 0x0034b2d8 : { *sdk-startup-stringmanager.o(.text._ZNK13StringManager17isPackSheetLoadedEjj) }
    .pack_count 0x0034b2f0 : { *sdk-startup-stringmanager.o(.text._ZNK13StringManager21getNumberOfLoadedPackEv) }
    .pack_switch 0x0034b314 : { *sdk-startup-stringmanager.o(.text._ZN13StringManager10switchPackEj) }
    .pack_unload 0x0034b618 : { *sdk-startup-stringmanager.o(.text._ZN13StringManager10unloadPackEj) }
    .sdk_startup_function_0 0x0034bc50 : { *sdk-startup-stringmanager.o(.text.__tcf_2) }
    .sdk_startup_function_1 0x0034bbd0 : { *sdk-startup-stringmanager.o(.text._Z41__static_initialization_and_destruction_0ii) }
    .sdk_startup_function_2 0x0034bc3c : { *sdk-startup-stringmanager.o(.text._GLOBAL__I__ZN13StringManager9LANGUAGESE) }
    .sdk_startup_storage_0 0x004bb7a8 (NOLOAD) : { *sdk-startup-stringmanager.o(.bss._ZN3irr5scene6quake315irrEmptyStringcE) }
    .sdk_startup_storage_1 0x004bb7c8 (NOLOAD) : { *sdk-startup-stringmanager.o(.bss._ZN3irr2ps5vHalfE) }
    .shared_startup_empty_text 0x0044d91c : { *(.gnu.linkonce.r.localStartupEmptyText) }
    .got 0x004b0048 : { *(.got.plt) . = 0x360; *(.got) }
    .verification 0x00600000 : { *retail-got.o(.text) }
}
ASSERT(SIZEOF(.sdk_startup_storage_0) == 32, "_ZN3irr5scene6quake315irrEmptyStringcE extent");
ASSERT(SIZEOF(.sdk_startup_storage_1) == 12, "_ZN3irr2ps5vHalfE extent");

memmove = 0x001c40ac;
_ZdaPv = 0x001c461c;
ASSERT(SIZEOF(.string_manager_d1) == 240, "native StringManager D1/D2 span");
ASSERT(SIZEOF(.string_manager_d0) == 248, "native StringManager D0 span");

_Znwj = 0x001c4814;
__stack_chk_fail = 0x001c42e0;
ASSERT(SIZEOF(.string_load_styles) == 332, "native loadStyles span");
ASSERT(SIZEOF(.string_style_default) == 40, "native TextStyle default extent");
ASSERT(SIZEOF(.string_unload_pack_sheet) == 116, "Native StringManager unloadPackSheet extent with alignment padding");
