OUTPUT_FORMAT("elf32-littlearm")
OUTPUT_ARCH(arm)
INCLUDE build/matches/string-startup-trailmgr/retail-symbols.ld
_ZdlPv = 0x001c42b0;
__aeabi_atexit = 0x001c494c;
SECTIONS
{
    .trail_mgr_ctor 0x00348f94 : { *string-startup-trailmgr.o(.text._ZN8TrailMgrC1Ev .text._ZN8TrailMgrC2Ev) }
    .trail_mgr_update 0x003490f8 : { *string-startup-trailmgr.o(.text._ZN8TrailMgr6UpdateEv) }
    .trail_mgr_alloc_trail 0x00349230 : { *string-startup-trailmgr.o(.text._ZN8TrailMgr10AllocTrailEv) }
    .trail_mgr_free_trail 0x00349050 : { *string-startup-trailmgr.o(.text._ZN8TrailMgr9FreeTrailEP5Trail) }
    .string_startup_function_0 0x00349088 : { *string-startup-trailmgr.o(.text.__tcf_0) }
    .string_startup_function_1 0x003492a8 : { *string-startup-trailmgr.o(.text._Z41__static_initialization_and_destruction_0ii) }
    .string_startup_function_2 0x00349300 : { *string-startup-trailmgr.o(.text._GLOBAL__I__ZN8TrailMgrC2Ev) }
    .string_startup_storage_0 0x004bb6e8 (NOLOAD) : { *string-startup-trailmgr.o(.bss._ZN3irr5scene6quake315irrEmptyStringcE) }
    .shared_startup_empty_text 0x0044d91c : { *(.gnu.linkonce.r.localStartupEmptyText) }
    .got 0x004b0048 : { *(.got.plt) . = 0x360; *(.got) }
    .verification 0x00600000 : { *retail-got.o(.text) }
}
ASSERT(SIZEOF(.string_startup_storage_0) == 32, "_ZN3irr5scene6quake315irrEmptyStringcE extent");
