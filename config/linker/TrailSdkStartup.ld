_Znwj = 0x001c4814;
_ZN12trail_assets8meshNameE = 0x00435a30;
_ZN12trail_assets11texturePathE = 0x00435a3c;
OUTPUT_FORMAT("elf32-littlearm")
OUTPUT_ARCH(arm)
INCLUDE build/matches/sdk-startup-trail/retail-symbols.ld
_ZdlPv = 0x001c42b0;
_ZdaPv = 0x001c461c;
_Znaj = 0x001c3ff8;
__aeabi_i2f = 0x001c41e4;
__aeabi_fmul = 0x001c4724;
__aeabi_f2iz = 0x001c44cc;
__aeabi_fsub = 0x001c4328;
__aeabi_fadd = 0x001c4154;
__aeabi_fcmpgt = 0x001c419c;
__aeabi_atexit = 0x001c494c;
PROVIDE(sqrtf = 0x001c4184);
SECTIONS
{
    .trail_build_point 0x00348734 : { *sdk-startup-trail.o(.text._ZN5Trail10BuildPointEib) }
    .trail_tex_offset_y 0x00435a48 : { *sdk-startup-trail.o(.rodata.g_trailTexOffsetY) }
    .trail_mesh 0x00348cfc : { *sdk-startup-trail.o(.text._ZN5Trail19CreateMeshSceneNodeEv) }
    .trail_add_point 0x00348a60 : { *sdk-startup-trail.o(.text._ZN5Trail8AddPointERN3irr4core8vector3dIfEES4_b) }
    .trail_last_added_point 0x003484e4 : { *sdk-startup-trail.o(.text._ZN5Trail17SetLastAddedPointEN3irr4core8vector3dIfEE) }
    .trail_segment_width 0x00348488 : { *sdk-startup-trail.o(.text._ZN5Trail15SetSegmentWidthEf) }
    .trail_render 0x0034848c : { *sdk-startup-trail.o(.text._ZN5Trail6RenderEv) }
    .trail_modify_life 0x00348490 : { *sdk-startup-trail.o(.text._ZN5Trail10ModifyLifeEf) }
    .trail_delete 0x0034854c : { *sdk-startup-trail.o(.text._ZN5TrailD0Ev) }
    .trail_dtor 0x00348574 : { *sdk-startup-trail.o(.text._ZN5TrailD1Ev .text._ZN5TrailD2Ev) }
    .trail_ctor 0x00348594 : { *sdk-startup-trail.o(.text._ZN5TrailC1Ev .text._ZN5TrailC2Ev) }
    .trail_cleanup 0x003484f4 : { *sdk-startup-trail.o(.text._ZN5Trail7CleanUpEv) }
    .trail_init 0x00348ef0 : { *sdk-startup-trail.o(.text._ZN5Trail4InitEiiiff) }
    .trail_update_points 0x00348ba4 : { *sdk-startup-trail.o(.text._ZN5Trail6UpdateERN3irr4core8vector3dIfEES4_b) }
    .trail_vtable 0x004ad288 : { *sdk-startup-trail.o(.data.rel.ro._ZTV5Trail) }
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
ASSERT(SIZEOF(.trail_mesh) == 500, "mesh native500 extent");
ASSERT(ADDR(.trail_mesh)+SIZEOF(.trail_mesh) == 0x00348ef0, "mesh next Init");
