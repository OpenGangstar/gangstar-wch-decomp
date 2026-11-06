OUTPUT_FORMAT("elf32-littlearm")
OUTPUT_ARCH(arm)
INCLUDE build/matches/sdk-startup-wantedmeter/retail-symbols.ld
_ZdlPv = 0x001c42b0;
__aeabi_atexit = 0x001c494c;
__cxa_guard_acquire = 0x001c4958;
__cxa_guard_release = 0x001c46c4;
SECTIONS
{
    .wanted_singleton 0x002dba04 : { *sdk-startup-wantedmeter.o(.gnu.linkonce.t._ZN18WantedLevelManager11getInstanceEv) }
    .wanted_cleanup 0x0032c834 : { *sdk-startup-wantedmeter.o(.text.__tcf_0) }
    .wanted_guard 0x004b6728 (NOLOAD) : { *sdk-startup-wantedmeter.o(.gnu.linkonce.b._ZGVZN18WantedLevelManager11getInstanceEvE3wlm) }
    .wanted_instance 0x004b6a98 (NOLOAD) : { *sdk-startup-wantedmeter.o(.gnu.linkonce.b._ZZN18WantedLevelManager11getInstanceEvE3wlm) }
    .sdk_startup_function_0 0x0032c7b8 : { *sdk-startup-wantedmeter.o(.text.__tcf_3) }
    .sdk_startup_function_1 0x0032ca70 : { *sdk-startup-wantedmeter.o(.text._Z41__static_initialization_and_destruction_0ii) }
    .sdk_startup_function_2 0x0032cadc : { *sdk-startup-wantedmeter.o(.text._GLOBAL__I__ZN11WantedMeterC2EP7ASpritei) }
    .sdk_startup_storage_0 0x004b982c (NOLOAD) : { *sdk-startup-wantedmeter.o(.bss._ZN3irr5scene6quake315irrEmptyStringcE) }
    .sdk_startup_storage_1 0x004b984c (NOLOAD) : { *sdk-startup-wantedmeter.o(.bss._ZN3irr2ps5vHalfE) }
    .shared_startup_empty_text 0x0044d91c : { *(.gnu.linkonce.r.localStartupEmptyText) }
    .got 0x004b0048 : { *(.got.plt) . = 0x360; *(.got) }
    .verification 0x00600000 : { *retail-got.o(.text) }
}
ASSERT(SIZEOF(.sdk_startup_storage_0) == 32, "_ZN3irr5scene6quake315irrEmptyStringcE extent");
ASSERT(SIZEOF(.sdk_startup_storage_1) == 12, "_ZN3irr2ps5vHalfE extent");
