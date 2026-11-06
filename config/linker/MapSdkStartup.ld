OUTPUT_FORMAT("elf32-littlearm")
OUTPUT_ARCH(arm)
INCLUDE build/matches/sdk-startup-map/retail-symbols.ld
_ZdlPv = 0x001c42b0;
__aeabi_atexit = 0x001c494c;
SECTIONS
{
    .map_clean 0x00328b10 : { *sdk-startup-map.o(.text._ZN3Map5cleanEv) }
    .map_construct 0x00328c14 : { *sdk-startup-map.o(.text._ZN3MapC1Ev .text._ZN3MapC2Ev) }
    .map_destroy 0x00328b34 : { *sdk-startup-map.o(.text._ZN3MapD1Ev .text._ZN3MapD2Ev) }
    .sdk_startup_function_0 0x00328ae0 : { *sdk-startup-map.o(.text.__tcf_3) }
    .sdk_startup_function_1 0x00328d78 : { *sdk-startup-map.o(.text._Z41__static_initialization_and_destruction_0ii) }
    .sdk_startup_function_2 0x00328de4 : { *sdk-startup-map.o(.text._GLOBAL__I__ZN3MapC2Ev) }
    .sdk_startup_storage_0 0x004b9544 (NOLOAD) : { *sdk-startup-map.o(.bss._ZN3irr5scene6quake315irrEmptyStringcE) }
    .sdk_startup_storage_1 0x004b9564 (NOLOAD) : { *sdk-startup-map.o(.bss._ZN3irr2ps5vHalfE) }
    .shared_startup_empty_text 0x0044d91c : { *(.gnu.linkonce.r.localStartupEmptyText) }
    .got 0x004b0048 : { *(.got.plt) . = 0x360; *(.got) }
    .verification 0x00600000 : { *retail-got.o(.text) }
}
ASSERT(SIZEOF(.sdk_startup_storage_0) == 32, "_ZN3irr5scene6quake315irrEmptyStringcE extent");
ASSERT(SIZEOF(.sdk_startup_storage_1) == 12, "_ZN3irr2ps5vHalfE extent");
