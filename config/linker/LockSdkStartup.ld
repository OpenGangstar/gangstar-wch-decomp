OUTPUT_FORMAT("elf32-littlearm")
OUTPUT_ARCH(arm)
INCLUDE build/matches/sdk-startup-lock/retail-symbols.ld
_ZdlPv = 0x001c42b0;
_Znwj = 0x001c4814;
__aeabi_atexit = 0x001c494c;
SECTIONS
{
    .sdk_startup_function_0 0x002fd024 : { *sdk-startup-lock.o(.text.__tcf_2) }
    .lock_clean 0x002fd054 : { *sdk-startup-lock.o(.text._ZN4Lock5cleanEv) }
    .lock_get_instance 0x002fd1cc : { *sdk-startup-lock.o(.text._ZN4Lock11getInstanceEv) }
    .lock_set_target 0x002fd204 : { *sdk-startup-lock.o(.text._ZN4Lock9setTargetEP11LevelObject) }
    .sdk_startup_function_1 0x002fd3c0 : { *sdk-startup-lock.o(.text._Z41__static_initialization_and_destruction_0ii) }
    .sdk_startup_function_2 0x002fd42c : { *sdk-startup-lock.o(.text._GLOBAL__I__ZN4Lock6s_lockE) }
    .sdk_startup_storage_0 0x004b8010 (NOLOAD) : { *sdk-startup-lock.o(.bss._ZN3irr5scene6quake315irrEmptyStringcE) }
    .lock_singleton_pointer 0x004b800c (NOLOAD) : { *sdk-startup-lock.o(.bss._ZN4Lock6s_lockE) }
    .sdk_startup_storage_1 0x004b8030 (NOLOAD) : { *sdk-startup-lock.o(.bss._ZN3irr2ps5vHalfE) }
    .shared_startup_empty_text 0x0044d91c : { *(.gnu.linkonce.r.localStartupEmptyText) }
    .lock_resource 0x0041d8c0 : { *sdk-startup-lock.o(.rodata.lock_resource) }
    .got 0x004b0048 : { *(.got.plt) . = 0x360; *(.got) }
    .verification 0x00600000 : { *retail-got.o(.text) }
}
ASSERT(SIZEOF(.sdk_startup_storage_0) == 32, "_ZN3irr5scene6quake315irrEmptyStringcE extent");
ASSERT(SIZEOF(.sdk_startup_storage_1) == 12, "_ZN3irr2ps5vHalfE extent");
ASSERT(SIZEOF(.lock_singleton_pointer) == 4, "_ZN4Lock6s_lockE extent");
