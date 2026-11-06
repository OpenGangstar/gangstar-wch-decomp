OUTPUT_FORMAT("elf32-littlearm")
OUTPUT_ARCH(arm)
INCLUDE build/matches/sdk-startup-minimap/retail-symbols.ld
_ZdlPv = 0x001c42b0;
__aeabi_atexit = 0x001c494c;
SECTIONS
{
    .minimap_deregister 0x00329564 : { *sdk-startup-minimap.o(.text._ZN7MiniMap27deregisterAllForMapTrackingEv) }
    .sdk_startup_function_0 0x003298cc : { *sdk-startup-minimap.o(.text.__tcf_5) }
    .sdk_startup_function_1 0x0032984c : { *sdk-startup-minimap.o(.text._Z41__static_initialization_and_destruction_0ii) }
    .sdk_startup_function_2 0x003298b8 : { *sdk-startup-minimap.o(.text._GLOBAL__I__ZN7MiniMapC2EP7ASpriteiiii) }
    .sdk_startup_storage_0 0x004b95ec (NOLOAD) : { *sdk-startup-minimap.o(.bss._ZN3irr5scene6quake315irrEmptyStringcE) }
    .sdk_startup_storage_1 0x004b960c (NOLOAD) : { *sdk-startup-minimap.o(.bss._ZN3irr2ps5vHalfE) }
    .shared_startup_empty_text 0x0044d91c : { *(.gnu.linkonce.r.localStartupEmptyText) }
    .got 0x004b0048 : { *(.got.plt) . = 0x360; *(.got) }
    .verification 0x00600000 : { *retail-got.o(.text) }
}
ASSERT(SIZEOF(.sdk_startup_storage_0) == 32, "_ZN3irr5scene6quake315irrEmptyStringcE extent");
ASSERT(SIZEOF(.sdk_startup_storage_1) == 12, "_ZN3irr2ps5vHalfE extent");
