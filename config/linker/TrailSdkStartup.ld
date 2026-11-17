OUTPUT_FORMAT("elf32-littlearm")
OUTPUT_ARCH(arm)
INCLUDE build/matches/sdk-startup-trail/retail-symbols.ld
_ZdlPv = 0x001c42b0;
__aeabi_atexit = 0x001c494c;
SECTIONS
{
    .trail_last_added_point 0x003484e4 : { *sdk-startup-trail.o(.text._ZN5Trail17SetLastAddedPointEN3irr4core8vector3dIfEE) }
    .sdk_startup_function_0 0x00348f64 : { *sdk-startup-trail.o(.text.__tcf_2) }
    .sdk_startup_function_1 0x00348c7c : { *sdk-startup-trail.o(.text._Z41__static_initialization_and_destruction_0ii) }
    .sdk_startup_function_2 0x00348ce8 : { *sdk-startup-trail.o(.text._GLOBAL__I__ZN5TrailC2Ev) }
    .sdk_startup_storage_0 0x004bb6bc (NOLOAD) : { *sdk-startup-trail.o(.bss._ZN3irr5scene6quake315irrEmptyStringcE) }
    .sdk_startup_storage_1 0x004bb6dc (NOLOAD) : { *sdk-startup-trail.o(.bss._ZN3irr2ps5vHalfE) }
    .shared_startup_empty_text 0x0044d91c : { *(.gnu.linkonce.r.localStartupEmptyText) }
    .got 0x004b0048 : { *(.got.plt) . = 0x360; *(.got) }
    .verification 0x00600000 : { *retail-got.o(.text) }
}
ASSERT(SIZEOF(.sdk_startup_storage_0) == 32, "_ZN3irr5scene6quake315irrEmptyStringcE extent");
ASSERT(SIZEOF(.sdk_startup_storage_1) == 12, "_ZN3irr2ps5vHalfE extent");
