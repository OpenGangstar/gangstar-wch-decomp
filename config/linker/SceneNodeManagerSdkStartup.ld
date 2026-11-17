OUTPUT_FORMAT("elf32-littlearm")
OUTPUT_ARCH(arm)
INCLUDE build/matches/sdk-startup-scenenodemanager/retail-symbols.ld
_ZdlPv = 0x001c42b0;
__aeabi_atexit = 0x001c494c;
SECTIONS
{
    .scene_crc_reflect 0x003213f0 : { *sdk-startup-scenenodemanager.o(.text._Z10crcReflectjc) }
    .scene_manager_setup 0x0032141c : { *sdk-startup-scenenodemanager.o(.text._ZN16SceneNodeManager5setupEv) }
    .scene_manager_update 0x00321420 : { *sdk-startup-scenenodemanager.o(.text._ZN16SceneNodeManager6updateEi) }
    .sdk_startup_function_0 0x00322068 : { *sdk-startup-scenenodemanager.o(.text.__tcf_3) }
    .sdk_startup_function_1 0x00321b9c : { *sdk-startup-scenenodemanager.o(.text._Z41__static_initialization_and_destruction_0ii) }
    .sdk_startup_function_2 0x00321c08 : { *sdk-startup-scenenodemanager.o(.text._GLOBAL__I__Z10crcReflectjc) }
    .sdk_startup_storage_0 0x004b8b70 (NOLOAD) : { *sdk-startup-scenenodemanager.o(.bss._ZN3irr5scene6quake315irrEmptyStringcE) }
    .sdk_startup_storage_1 0x004b8b90 (NOLOAD) : { *sdk-startup-scenenodemanager.o(.bss._ZN3irr2ps5vHalfE) }
    .shared_startup_empty_text 0x0044d91c : { *(.gnu.linkonce.r.localStartupEmptyText) }
    .got 0x004b0048 : { *(.got.plt) . = 0x360; *(.got) }
    .verification 0x00600000 : { *retail-got.o(.text) }
}
ASSERT(SIZEOF(.sdk_startup_storage_0) == 32, "_ZN3irr5scene6quake315irrEmptyStringcE extent");
ASSERT(SIZEOF(.sdk_startup_storage_1) == 12, "_ZN3irr2ps5vHalfE extent");
