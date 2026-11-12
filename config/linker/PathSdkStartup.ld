OUTPUT_FORMAT("elf32-littlearm")
OUTPUT_ARCH(arm)
INCLUDE build/matches/sdk-startup-path/retail-symbols.ld
_ZdlPv = 0x001c42b0;
__aeabi_atexit = 0x001c494c;
_ZdaPv = 0x001c461c;
SECTIONS
{
    .path_ctor 0x00300c8c : { *(.text._ZN4PathC1Ei .text._ZN4PathC2Ei) }
    .path_dtor 0x00300b98 : { *(.text._ZN4PathD1Ev .text._ZN4PathD2Ev) }
    .path_delete 0x00300b64 : { *(.text._ZN4PathD0Ev) }
    .path_vtable 0x004aae88 : { *(.data.rel.ro._ZTV4Path) }
    .path_base_spawn_type 0x002f74d0 : { *(.gnu.linkonce.t._ZN11LevelObject12getSpawnTypeEv) }
    .path_size 0x00300b10 : { *(.text._ZNK4Path7getSizeEv) }
    .path_waypoint 0x00300b14 : { *(.text._ZNK4Path11getWaypointEiRN3irr4core8vector3dIfEE) }
    .path_factory_cleanup 0x00300b40 : { *sdk-startup-path.o(.text.__tcf_1) }
    .sdk_startup_function_0 0x00300d4c : { *sdk-startup-path.o(.text.__tcf_2) }
    .sdk_startup_function_1 0x00300ccc : { *sdk-startup-path.o(.text._Z41__static_initialization_and_destruction_0ii) }
    .sdk_startup_function_2 0x00300d38 : { *sdk-startup-path.o(.text._GLOBAL__I__ZN4PathC2Ei) }
    .sdk_startup_storage_0 0x004b80bc (NOLOAD) : { *sdk-startup-path.o(.bss._ZN3irr5scene6quake315irrEmptyStringcE) }
    .sdk_startup_storage_1 0x004b80dc (NOLOAD) : { *sdk-startup-path.o(.bss._ZN3irr2ps5vHalfE) }
    .shared_startup_empty_text 0x0044d91c : { *(.gnu.linkonce.r.localStartupEmptyText) }
    .got 0x004b0048 : { *(.got.plt) . = 0x360; *(.got) }
    .verification 0x00600000 : { *retail-got.o(.text) }
}
ASSERT(SIZEOF(.sdk_startup_storage_0) == 32, "_ZN3irr5scene6quake315irrEmptyStringcE extent");
ASSERT(SIZEOF(.sdk_startup_storage_1) == 12, "_ZN3irr2ps5vHalfE extent");
