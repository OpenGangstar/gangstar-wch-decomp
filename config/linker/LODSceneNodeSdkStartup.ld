OUTPUT_FORMAT("elf32-littlearm")
OUTPUT_ARCH(arm)
INCLUDE build/matches/sdk-startup-lodscenenode/retail-symbols.ld
_ZdlPv = 0x001c42b0;
__aeabi_atexit = 0x001c494c;
__aeabi_ui2f = 0x001c4574;
__aeabi_i2f = 0x001c41e4;
__aeabi_f2uiz = 0x00401034;
__aeabi_fcmplt = 0x001c479c;
__aeabi_fcmpgt = 0x001c419c;
__aeabi_fmul = 0x001c4724;
__cxa_pure_virtual = 0;
SECTIONS
{
    .lod_ctor_base 0x002d2b30 : { *sdk-startup-lodscenenode.o(.text._ZN12LODSceneNodeC2EiRKN3irr4core8vector3dIfEERKNS1_10quaternionES5_) }
    .lod_ctor_complete 0x002d2f50 : { *sdk-startup-lodscenenode.o(.text._ZN12LODSceneNodeC1EiRKN3irr4core8vector3dIfEERKNS1_10quaternionES5_) }
    .lod_add_lod 0x002d2c98 : { *sdk-startup-lodscenenode.o(.text._ZN12LODSceneNode6addLODEPN3irr5scene10ISceneNodeEf) }
    .lod_add_animator 0x002d2c60 : { *sdk-startup-lodscenenode.o(.text._ZN12LODSceneNode11addAnimatorEPN3irr5scene18ISceneNodeAnimatorE) }
    .lod_remove_animators 0x002d2c24 : { *sdk-startup-lodscenenode.o(.text._ZN12LODSceneNode15removeAnimatorsEv) }
    .lod_thunk_d0_ref 0x002d30d0 : { *sdk-startup-lodscenenode.o(.text._ZTv0_n12_N12LODSceneNodeD0Ev) }
    .lod_thunk_d0_attr 0x002d30e4 : { *sdk-startup-lodscenenode.o(.text._ZTv0_n24_N12LODSceneNodeD0Ev) }
    .lod_d0 0x002d30f8 : { *sdk-startup-lodscenenode.o(.text._ZN12LODSceneNodeD0Ev) }
    .lod_thunk_d1_ref 0x002d31ac : { *sdk-startup-lodscenenode.o(.text._ZTv0_n12_N12LODSceneNodeD1Ev) }
    .lod_thunk_d1_attr 0x002d31c0 : { *sdk-startup-lodscenenode.o(.text._ZTv0_n24_N12LODSceneNodeD1Ev) }
    .lod_d1 0x002d31d4 : { *sdk-startup-lodscenenode.o(.text._ZN12LODSceneNodeD1Ev) }
    .lod_d2 0x002d3280 : { *sdk-startup-lodscenenode.o(.text._ZN12LODSceneNodeD2Ev) }
    .lod_vtable 0x004a5e80 : { *(.data.rel.ro._ZTV12LODSceneNode) }
    .lod_scene_node_construction 0x004a5fe0 : { *(.data.rel.ro._ZTC12LODSceneNode0_N3irr5scene10ISceneNodeE) }
    .lod_attributes_construction 0x004a6120 : { *(.data.rel.ro._ZTC12LODSceneNode0_N3irr2io26IAttributeExchangingObjectE) }
    .lod_vtt 0x004a5fc0 : { *(.data.rel.ro._ZTT12LODSceneNode) }
    .attribute_d0 0x0021a8d4 : { *(.gnu.linkonce.t._ZN3irr2io26IAttributeExchangingObjectD0Ev) }
    .attribute_d1 0x0021a91c : { *(.gnu.linkonce.t._ZN3irr2io26IAttributeExchangingObjectD1Ev) }
    .attribute_d2 0x0021a958 : { *(.gnu.linkonce.t._ZN3irr2io26IAttributeExchangingObjectD2Ev) }
    .lod_register 0x002d2e94 : { *sdk-startup-lodscenenode.o(.text._ZN12LODSceneNode19OnRegisterSceneNodeEv) }
    .lod_mesh_bounds 0x002d2ac8 : { *sdk-startup-lodscenenode.o(.text._ZNK12LODSceneNode18GetMeshBoundingBoxEPKN3irr5scene10ISceneNodeE) }
    .lod_transformed_bounds 0x002d2f30 : { *sdk-startup-lodscenenode.o(.text._ZNK12LODSceneNode25getTransformedBoundingBoxEv) }
    .lod_set_rotations 0x002d2bac : { *sdk-startup-lodscenenode.o(.text._ZN12LODSceneNode19setLODNodesRotationERKN3irr4core10quaternionE) }
    .lod_set_positions 0x002d2be8 : { *sdk-startup-lodscenenode.o(.text._ZN12LODSceneNode19setLODNodesPositionERKN3irr4core8vector3dIfEE) }
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
