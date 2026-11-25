OUTPUT_FORMAT("elf32-littlearm")
OUTPUT_ARCH(arm)
INCLUDE build/matches/string-startup-trailmgr/retail-symbols.ld
_ZdlPv = 0x001c42b0;
_ZdaPv = 0x001c461c;
_Znaj = 0x001c3ff8;
_Znwj = 0x001c4814;
memset = 0x001c45d4;
__aeabi_atexit = 0x001c494c;
SECTIONS
{
    .trail_alloc_list 0x00348fb4 : { *string-startup-trailmgr.o(.text._ZN8TrailMgr14AllocTrailListEPP5Traili) }
    .trail_render 0x00349270 : { *string-startup-trailmgr.o(.text._ZN8TrailMgr6RenderEv) }
    .trail_mgr_ctor 0x00348f94 : { *string-startup-trailmgr.o(.text._ZN8TrailMgrC1Ev .text._ZN8TrailMgrC2Ev) }
    .trail_mgr_dtor 0x003490dc : { *string-startup-trailmgr.o(.text._ZN8TrailMgrD1Ev .text._ZN8TrailMgrD2Ev) }
    .trail_mgr_delete 0x003490b8 : { *string-startup-trailmgr.o(.text._ZN8TrailMgrD0Ev) }
    .trail_mgr_vtable 0x004ad298 : { *string-startup-trailmgr.o(.data.rel.ro._ZTV8TrailMgr) }
    .trail_mgr_segment_width 0x00349120 : { *string-startup-trailmgr.o(.text._ZN8TrailMgr15SetSegmentWidthEf) }
    .trail_mgr_cleanup 0x00349148 : { *string-startup-trailmgr.o(.text._ZN8TrailMgr7CleanUpEv) }
    .trail_mgr_init 0x00349188 : { *string-startup-trailmgr.o(.text._ZN8TrailMgr4InitEiiiiff) }
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
ASSERT(SIZEOF(.trail_render) == 56, "Native TrailMgr Render extent");
ASSERT(SIZEOF(.trail_alloc_list) == 156, "Native TrailMgr AllocTrailList extent with alignment padding");
