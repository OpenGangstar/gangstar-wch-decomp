OUTPUT_FORMAT("elf32-littlearm")
OUTPUT_ARCH(arm)
INCLUDE build/matches/sdk-startup-minimap/retail-symbols.ld
_ZdlPv = 0x001c42b0;
__aeabi_atexit = 0x001c494c;
_Znwj = 0x001c4814;
__aeabi_fadd = 0x001c4154;
__aeabi_fsub = 0x001c4328;
__aeabi_fcmple = 0x001c43ac;
__aeabi_fdiv = 0x001c4520;
__aeabi_fmul = 0x001c4724;
__aeabi_fcmplt = 0x001c479c;
__cxa_guard_acquire = 0x001c4958;
__cxa_guard_release = 0x001c46c4;
SECTIONS
{
    /* Keep the emitted copy in Thumb call range. The MenuManager_Map profile checks the selected retail copy. */
    .target_marker_singleton 0x002e6660 : { *sdk-startup-minimap.o(.gnu.linkonce.t._ZN12TargetMarker11getInstanceEv) }
    .target_marker_cleanup 0x0032945c : { *sdk-startup-minimap.o(.text.__tcf_0) }
    .target_marker_guard 0x004b7bd4 (NOLOAD) : { *sdk-startup-minimap.o(.gnu.linkonce.b._ZGVZN12TargetMarker11getInstanceEvE3map) }
    .target_marker_storage 0x004b7c54 (NOLOAD) : { *sdk-startup-minimap.o(.gnu.linkonce.b._ZZN12TargetMarker11getInstanceEvE3map) }
    .minimap_update 0x003294b8 : { *sdk-startup-minimap.o(.text._ZN7MiniMap6updateEd) }
    .minimap_delete_thunk 0x0032973c : { *sdk-startup-minimap.o(.text._ZThn4_N7MiniMapD0Ev) }
    .minimap_delete 0x00329750 : { *sdk-startup-minimap.o(.text._ZN7MiniMapD0Ev) }
    .minimap_destroy_thunk 0x003297c8 : { *sdk-startup-minimap.o(.text._ZThn4_N7MiniMapD1Ev) }
    .minimap_destroy 0x003297dc : { *sdk-startup-minimap.o(.text._ZN7MiniMapD1Ev .text._ZN7MiniMapD2Ev) }
    .minimap_vtable 0x004ac4b0 : { *sdk-startup-minimap.o(.data.rel.ro._ZTV7MiniMap) }
    .minimap_deregister_one 0x003296f8 : { *sdk-startup-minimap.o(.text._ZN7MiniMap24deregisterForMapTrackingEP11LevelObject) }
    .minimap_register 0x00329678 : { *sdk-startup-minimap.o(.text._ZN7MiniMap22registerForMapTrackingEP11LevelObjectb) }
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
ASSERT(SIZEOF(.target_marker_guard) == 4, "TargetMarker singleton guard extent");
ASSERT(SIZEOF(.target_marker_storage) == 28, "TargetMarker singleton storage extent");
