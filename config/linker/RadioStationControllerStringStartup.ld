OUTPUT_FORMAT("elf32-littlearm")
OUTPUT_ARCH(arm)
INCLUDE build/matches/string-startup-radiostationcontroller/retail-symbols.ld
_ZdlPv = 0x001c42b0;
__aeabi_atexit = 0x001c494c;
_ZdaPv = 0x001c461c;
_Znaj = 0x001c3ff8;
__aeabi_idivmod = 0x001c4934;
SECTIONS
{
    .string_startup_function_0 0x00352038 : { *string-startup-radiostationcontroller.o(.text.__tcf_0) }
    .string_startup_function_1 0x00352244 : { *string-startup-radiostationcontroller.o(.text._Z41__static_initialization_and_destruction_0ii) }
    .string_startup_function_2 0x0035229c : { *string-startup-radiostationcontroller.o(.text._GLOBAL__I__ZN22RadioStationControllerC2Ev) }
    .string_startup_storage_0 0x004bc1d0 (NOLOAD) : { *string-startup-radiostationcontroller.o(.bss._ZN3irr5scene6quake315irrEmptyStringcE) }
    .shared_startup_empty_text 0x0044d91c : { *(.gnu.linkonce.r.localStartupEmptyText) }
    .got 0x004b0048 : { *(.got.plt) . = 0x360; *(.got) }
    .verification 0x00600000 : { *retail-got.o(.text) }
    .radio_function_0 0x00352068 : { *string-startup-radiostationcontroller.o(.text._ZN22RadioStationController14selectRandomAdEv) }
    .radio_function_2 0x00352144 : { *string-startup-radiostationcontroller.o(.text._ZN22RadioStationControllerD1Ev .text._ZN22RadioStationControllerD2Ev) }
    .radio_function_3 0x003521d4 : { *string-startup-radiostationcontroller.o(.text._ZN7Structs12RadioStation4ReadER10DataStream) }
}
ASSERT(SIZEOF(.string_startup_storage_0) == 32, "_ZN3irr5scene6quake315irrEmptyStringcE extent");
