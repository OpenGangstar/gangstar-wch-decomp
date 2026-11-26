OUTPUT_FORMAT("elf32-littlearm")
OUTPUT_ARCH(arm)
INCLUDE build/matches/string-startup-radiostationcontroller/retail-symbols.ld
_ZdlPv = 0x001c42b0;
__aeabi_atexit = 0x001c494c;
_ZdaPv = 0x001c461c;
_Znaj = 0x001c3ff8;
PROVIDE(_Znwj = 0x001c4814);
PROVIDE(__stack_chk_fail = 0x001c42e0);
__aeabi_idivmod = 0x001c4934;
SECTIONS
{
    .radio_selection_0 0x003520c0 : { *string-startup-radiostationcontroller.o(.text._ZN22RadioStationController18selectRandomJingleEi) }
    .radio_selection_1 0x003522b0 : { *string-startup-radiostationcontroller.o(.text._ZN22RadioStationController16selectRandomSongEi) }

    .string_startup_function_0 0x00352038 : { *string-startup-radiostationcontroller.o(.text.__tcf_0) }
    .string_startup_function_1 0x00352244 : { *string-startup-radiostationcontroller.o(.text._Z41__static_initialization_and_destruction_0ii) }
    .string_startup_function_2 0x0035229c : { *string-startup-radiostationcontroller.o(.text._GLOBAL__I__ZN22RadioStationControllerC2Ev) }
    .string_startup_storage_0 0x004bc1d0 (NOLOAD) : { *string-startup-radiostationcontroller.o(.bss._ZN3irr5scene6quake315irrEmptyStringcE) }
    .shared_startup_empty_text 0x0044d91c : { *(.gnu.linkonce.r.localStartupEmptyText) }
    .got 0x004b0048 : { *(.got.plt) . = 0x360; *(.got) }
    .verification 0x00600000 : { *retail-got.o(.text) }
    .radio_function_0 0x00352068 : { *string-startup-radiostationcontroller.o(.text._ZN22RadioStationController14selectRandomAdEv) }
    .radio_ctor 0x00352334 : { *string-startup-radiostationcontroller.o(.text._ZN22RadioStationControllerC1Ev .text._ZN22RadioStationControllerC2Ev) }
    .radio_ctor_station_paths 0x00436328 : { *string-startup-radiostationcontroller.o(.rodata.str1.4) }
    .radio_ctor_c968 0x00436350 : { *string-startup-radiostationcontroller.o(.rodata._ZZN22RadioStationControllerC1EvE*C.11) }
    .radio_ctor_c965 0x00436360 : { *string-startup-radiostationcontroller.o(.rodata._ZZN22RadioStationControllerC1EvE*C.8) }
    .radio_data_stream_d1 0x002d3654 : { *string-startup-radiostationcontroller.o(.gnu.linkonce.t._ZN10DataStreamD1Ev) }
    .radio_function_2 0x00352144 : { *string-startup-radiostationcontroller.o(.text._ZN22RadioStationControllerD1Ev .text._ZN22RadioStationControllerD2Ev) }
    .radio_function_3 0x003521d4 : { *string-startup-radiostationcontroller.o(.text._ZN7Structs12RadioStation4ReadER10DataStream) }
}
ASSERT(SIZEOF(.string_startup_storage_0) == 32, "_ZN3irr5scene6quake315irrEmptyStringcE extent");
