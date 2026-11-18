OUTPUT_FORMAT("elf32-littlearm")
OUTPUT_ARCH(arm)
INCLUDE build/matches/sdk-startup-sniperhud/retail-symbols.ld
_ZdlPv = 0x001c42b0;
__aeabi_atexit = 0x001c494c;
SECTIONS
{
    .recovered_sdk_startup_sniperhud_325adc 0x00325adc : { *sdk-startup-sniperhud.o(.text._ZN10CSniperHudC1EP11CHudManager .gnu.linkonce.t._ZN10CSniperHudC1EP11CHudManager .text._ZN10CSniperHudC2EP11CHudManager .gnu.linkonce.t._ZN10CSniperHudC2EP11CHudManager) }
    .recovered_sdk_startup_sniperhud_325b0c 0x00325b0c : { *sdk-startup-sniperhud.o(.text._ZN10CSniperHudD1Ev .gnu.linkonce.t._ZN10CSniperHudD1Ev .text._ZN10CSniperHudD2Ev .gnu.linkonce.t._ZN10CSniperHudD2Ev) }
    .recovered_sdk_startup_sniperhud_325b24 0x00325b24 : { *sdk-startup-sniperhud.o(.text._ZN10CSniperHud4showEv .gnu.linkonce.t._ZN10CSniperHud4showEv) }
    .recovered_sdk_startup_sniperhud_325c78 0x00325c78 : { *sdk-startup-sniperhud.o(.text._ZN10CSniperHud4hideEv .gnu.linkonce.t._ZN10CSniperHud4hideEv) }
    .sdk_startup_sniperhud_vtable 0x004abde0 : { *sdk-startup-sniperhud.o(.data.rel.ro._ZTV10CSniperHud) }

    .sdk_startup_function_0 0x00325d4c : { *sdk-startup-sniperhud.o(.text.__tcf_2) }
    .sdk_startup_function_1 0x00325d7c : { *sdk-startup-sniperhud.o(.text._Z41__static_initialization_and_destruction_0ii) }
    .sdk_startup_function_2 0x00325de8 : { *sdk-startup-sniperhud.o(.text._GLOBAL__I__ZN10CSniperHudC2EP11CHudManager) }
    .sdk_startup_storage_0 0x004b91b0 (NOLOAD) : { *sdk-startup-sniperhud.o(.bss._ZN3irr5scene6quake315irrEmptyStringcE) }
    .sdk_startup_storage_1 0x004b91d0 (NOLOAD) : { *sdk-startup-sniperhud.o(.bss._ZN3irr2ps5vHalfE) }
    .shared_startup_empty_text 0x0044d91c : { *(.gnu.linkonce.r.localStartupEmptyText) }
    .got 0x004b0048 : { *(.got.plt) . = 0x360; *(.got) }
    .verification 0x00600000 : { *retail-got.o(.text) }
}
ASSERT(SIZEOF(.sdk_startup_storage_0) == 32, "_ZN3irr5scene6quake315irrEmptyStringcE extent");
ASSERT(SIZEOF(.sdk_startup_storage_1) == 12, "_ZN3irr2ps5vHalfE extent");
