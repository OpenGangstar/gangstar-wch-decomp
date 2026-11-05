OUTPUT_FORMAT("elf32-littlearm")
OUTPUT_ARCH(arm)
INCLUDE build/matches/sdk-startup-ccamerahud/retail-symbols.ld
_ZdlPv = 0x001c42b0;
__aeabi_atexit = 0x001c494c;
__cxa_pure_virtual = 0;
SECTIONS
{
    .sdk_startup_function_0 0x00322ea8 : { *sdk-startup-ccamerahud.o(.text.__tcf_2) }
    .sdk_startup_function_1 0x00322ed8 : { *sdk-startup-ccamerahud.o(.text._Z41__static_initialization_and_destruction_0ii) }
    .sdk_startup_function_2 0x00322f44 : { *sdk-startup-ccamerahud.o(.text._GLOBAL__I__ZN10CCameraHudC2EP11CHudManager) }
    .sdk_startup_storage_0 0x004b9060 (NOLOAD) : { *sdk-startup-ccamerahud.o(.bss._ZN3irr5scene6quake315irrEmptyStringcE) }
    .sdk_startup_storage_1 0x004b9080 (NOLOAD) : { *sdk-startup-ccamerahud.o(.bss._ZN3irr2ps5vHalfE) }
    .hud_entry_0 0x00322c0c : { *sdk-startup-ccamerahud.o(.gnu.linkonce.t._ZNK4IHud9isVisibleEv) }
    .hud_entry_1 0x00322c10 : { *sdk-startup-ccamerahud.o(.gnu.linkonce.t._ZNK4IHud12isWalkingHudEv) }
    .hud_entry_2 0x00322c14 : { *sdk-startup-ccamerahud.o(.text._ZN10CCameraHudC1EP11CHudManager) }
    .hud_entry_3 0x00322c44 : { *sdk-startup-ccamerahud.o(.text._ZN10CCameraHudD1Ev) }
    .ihud_vtable 0x004abd80 : { *sdk-startup-ccamerahud.o(.gnu.linkonce.d.rel.ro._ZTV4IHud) }
    .shared_startup_empty_text 0x0044d91c : { *(.gnu.linkonce.r.localStartupEmptyText) }
    .got 0x004b0048 : { *(.got.plt) . = 0x360; *(.got) }
    .verification 0x00600000 : { *retail-got.o(.text) }
}
ASSERT(SIZEOF(.sdk_startup_storage_0) == 32, "_ZN3irr5scene6quake315irrEmptyStringcE extent");
ASSERT(SIZEOF(.sdk_startup_storage_1) == 12, "_ZN3irr2ps5vHalfE extent");
