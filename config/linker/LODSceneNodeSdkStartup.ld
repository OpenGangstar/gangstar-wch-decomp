OUTPUT_FORMAT("elf32-littlearm")
OUTPUT_ARCH(arm)
INCLUDE build/matches/sdk-startup-lodscenenode/retail-symbols.ld
_ZdlPv = 0x001c42b0;
__aeabi_atexit = 0x001c494c;
__aeabi_ui2f = 0x001c4574;
__aeabi_i2f = 0x001c41e4;
SECTIONS
{
    .lod_bounds 0x002d2b10 : { *sdk-startup-lodscenenode.o(.text._ZNK12LODSceneNode14getBoundingBoxEv) }
    .lod_render 0x002d2998 : { *sdk-startup-lodscenenode.o(.text._ZN12LODSceneNode6renderEPv) }
    .lod_get_level 0x002d299c : { *sdk-startup-lodscenenode.o(.text._ZNK12LODSceneNode11getLODLevelEv) }
    .lod_compute 0x002d29a4 : { *sdk-startup-lodscenenode.o(.text._ZN12LODSceneNode10ComputeLODEj) }
    .lod_animate 0x002d29a8 : { *sdk-startup-lodscenenode.o(.text._ZN12LODSceneNode9OnAnimateEj) }
    .lod_max_distance 0x002d29c0 : { *sdk-startup-lodscenenode.o(.text._ZN12LODSceneNode14setMaxDistanceEi) }
    .lod_get_type 0x002d29d8 : { *sdk-startup-lodscenenode.o(.text._ZNK12LODSceneNode7getTypeEv) }
    .sdk_startup_function_0 0x002d30a0 : { *sdk-startup-lodscenenode.o(.text.__tcf_2) }
    .sdk_startup_function_1 0x002d3020 : { *sdk-startup-lodscenenode.o(.text._Z41__static_initialization_and_destruction_0ii) }
    .sdk_startup_function_2 0x002d308c : { *sdk-startup-lodscenenode.o(.text._GLOBAL__I__ZN12LODSceneNodeC2EiRKN3irr4core8vector3dIfEERKNS1_10quaternionES5_) }
    .sdk_startup_storage_0 0x004b6730 (NOLOAD) : { *sdk-startup-lodscenenode.o(.bss._ZN3irr5scene6quake315irrEmptyStringcE) }
    .sdk_startup_storage_1 0x004b6750 (NOLOAD) : { *sdk-startup-lodscenenode.o(.bss._ZN3irr2ps5vHalfE) }
    .shared_startup_empty_text 0x0044d91c : { *(.gnu.linkonce.r.localStartupEmptyText) }
    .got 0x004b0048 : { *(.got.plt) . = 0x360; *(.got) }
    .verification 0x00600000 : { *retail-got.o(.text) }
}
ASSERT(SIZEOF(.sdk_startup_storage_0) == 32, "_ZN3irr5scene6quake315irrEmptyStringcE extent");
ASSERT(SIZEOF(.sdk_startup_storage_1) == 12, "_ZN3irr2ps5vHalfE extent");
