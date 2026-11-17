__cxa_pure_virtual = 0;
OUTPUT_FORMAT("elf32-littlearm")
OUTPUT_ARCH(arm)
INCLUDE build/matches/sdk-startup-custombillboardscenenode/retail-symbols.ld
_ZdlPv = 0x001c42b0;
__aeabi_atexit = 0x001c494c;
SECTIONS
{
    .billboard_render 0x002f7a20 : { *(.text._ZN24CustomBillboardSceneNode6renderEv) }
    .billboard_set_parent 0x002f79e4 : { *(.text._ZN24CustomBillboardSceneNode9setParentEPN3irr5scene10ISceneNodeE) }
    .billboard_func_0 0x2f8404 : { *sdk-startup-custombillboardscenenode.o(.text._ZN24CustomBillboardSceneNodeD1Ev .gnu.linkonce.t._ZN24CustomBillboardSceneNodeD1Ev) }
    .billboard_func_1 0x2f8350 : { *sdk-startup-custombillboardscenenode.o(.text._ZN24CustomBillboardSceneNodeD0Ev .gnu.linkonce.t._ZN24CustomBillboardSceneNodeD0Ev) }
    .billboard_func_2 0x2f8314 : { *sdk-startup-custombillboardscenenode.o(.text._ZTv0_n12_N24CustomBillboardSceneNodeD0Ev .gnu.linkonce.t._ZTv0_n12_N24CustomBillboardSceneNodeD0Ev) }
    .billboard_func_3 0x2f8328 : { *sdk-startup-custombillboardscenenode.o(.text._ZTv0_n24_N24CustomBillboardSceneNodeD0Ev .gnu.linkonce.t._ZTv0_n24_N24CustomBillboardSceneNodeD0Ev) }
    .billboard_func_4 0x2f833c : { *sdk-startup-custombillboardscenenode.o(.text._ZThn100_N24CustomBillboardSceneNodeD0Ev .gnu.linkonce.t._ZThn100_N24CustomBillboardSceneNodeD0Ev) }
    .billboard_func_5 0x2f83c8 : { *sdk-startup-custombillboardscenenode.o(.text._ZTv0_n12_N24CustomBillboardSceneNodeD1Ev .gnu.linkonce.t._ZTv0_n12_N24CustomBillboardSceneNodeD1Ev) }
    .billboard_func_6 0x2f83dc : { *sdk-startup-custombillboardscenenode.o(.text._ZTv0_n24_N24CustomBillboardSceneNodeD1Ev .gnu.linkonce.t._ZTv0_n24_N24CustomBillboardSceneNodeD1Ev) }
    .billboard_func_7 0x2f83f0 : { *sdk-startup-custombillboardscenenode.o(.text._ZThn100_N24CustomBillboardSceneNodeD1Ev .gnu.linkonce.t._ZThn100_N24CustomBillboardSceneNodeD1Ev) }
    .billboard_func_8 0x21a8d4 : { *sdk-startup-custombillboardscenenode.o(.text._ZN3irr2io26IAttributeExchangingObjectD0Ev .gnu.linkonce.t._ZN3irr2io26IAttributeExchangingObjectD0Ev) }
    .billboard_func_9 0x21a91c : { *sdk-startup-custombillboardscenenode.o(.text._ZN3irr2io26IAttributeExchangingObjectD1Ev .gnu.linkonce.t._ZN3irr2io26IAttributeExchangingObjectD1Ev) }
    .billboard_func_10 0x21a958 : { *sdk-startup-custombillboardscenenode.o(.text._ZN3irr2io26IAttributeExchangingObjectD2Ev .gnu.linkonce.t._ZN3irr2io26IAttributeExchangingObjectD2Ev) }
    .billboard_table_0 0x4aa228 : { *sdk-startup-custombillboardscenenode.o(.data.rel.ro._ZTV24CustomBillboardSceneNode .gnu.linkonce.d.rel.ro._ZTV24CustomBillboardSceneNode) }
    .billboard_table_1 0x4aa3a8 : { *sdk-startup-custombillboardscenenode.o(.data.rel.ro._ZTT24CustomBillboardSceneNode .gnu.linkonce.d.rel.ro._ZTT24CustomBillboardSceneNode) }
    .billboard_table_2 0x4aa3f8 : { *sdk-startup-custombillboardscenenode.o(.data.rel.ro._ZTC24CustomBillboardSceneNode0_N3irr7collada14CRootSceneNodeE .gnu.linkonce.d.rel.ro._ZTC24CustomBillboardSceneNode0_N3irr7collada14CRootSceneNodeE) }
    .billboard_table_3 0x4aa570 : { *sdk-startup-custombillboardscenenode.o(.data.rel.ro._ZTC24CustomBillboardSceneNode100_N3irr7collada10CSceneNodeE .gnu.linkonce.d.rel.ro._ZTC24CustomBillboardSceneNode100_N3irr7collada10CSceneNodeE) }
    .billboard_table_4 0x4aa6b8 : { *sdk-startup-custombillboardscenenode.o(.data.rel.ro._ZTC24CustomBillboardSceneNode100_N3irr5scene15CEmptySceneNodeE .gnu.linkonce.d.rel.ro._ZTC24CustomBillboardSceneNode100_N3irr5scene15CEmptySceneNodeE) }
    .billboard_table_5 0x4aa800 : { *sdk-startup-custombillboardscenenode.o(.data.rel.ro._ZTC24CustomBillboardSceneNode100_N3irr5scene10ISceneNodeE .gnu.linkonce.d.rel.ro._ZTC24CustomBillboardSceneNode100_N3irr5scene10ISceneNodeE) }
    .billboard_table_6 0x4aa940 : { *sdk-startup-custombillboardscenenode.o(.data.rel.ro._ZTC24CustomBillboardSceneNode100_N3irr2io26IAttributeExchangingObjectE .gnu.linkonce.d.rel.ro._ZTC24CustomBillboardSceneNode100_N3irr2io26IAttributeExchangingObjectE) }
    /DISCARD/ : { *(.text._ZN24CustomBillboardSceneNodeD2Ev) }
    .sdk_startup_function_0 0x002f7a24 : { *sdk-startup-custombillboardscenenode.o(.text.__tcf_2) }
    .billboard_set_length 0x002f7a54 : { *sdk-startup-custombillboardscenenode.o(.text._ZN24CustomBillboardSceneNode9setLengthEj) }
    .billboard_material_type 0x002f7c70 : { *sdk-startup-custombillboardscenenode.o(.text._ZN24CustomBillboardSceneNode23setChildrenMaterialTypeEPN3irr5scene10ISceneNodeENS0_5video15E_MATERIAL_TYPEE) }
    .billboard_material_flag 0x002f7ca8 : { *sdk-startup-custombillboardscenenode.o(.text._ZN24CustomBillboardSceneNode23setChildrenMaterialFlagEPN3irr5scene10ISceneNodeENS0_5video15E_MATERIAL_FLAGEb) }
    .sdk_startup_function_1 0x002f7dd0 : { *sdk-startup-custombillboardscenenode.o(.text._Z41__static_initialization_and_destruction_0ii) }
    .sdk_startup_function_2 0x002f7e3c : { *sdk-startup-custombillboardscenenode.o(.text._GLOBAL__I__ZN24CustomBillboardSceneNodeC2ERKN3irr7collada16CColladaDatabaseEPNS1_5SNodeE) }
    .sdk_startup_storage_0 0x004b7ed4 (NOLOAD) : { *sdk-startup-custombillboardscenenode.o(.bss._ZN3irr5scene6quake315irrEmptyStringcE) }
    .sdk_startup_storage_1 0x004b7ef4 (NOLOAD) : { *sdk-startup-custombillboardscenenode.o(.bss._ZN3irr2ps5vHalfE) }
    .shared_startup_empty_text 0x0044d91c : { *(.gnu.linkonce.r.localStartupEmptyText) }
    .got 0x004b0048 : { *(.got.plt) . = 0x360; *(.got) }
    .verification 0x00600000 : { *retail-got.o(.text) }
}
ASSERT(SIZEOF(.sdk_startup_storage_0) == 32, "_ZN3irr5scene6quake315irrEmptyStringcE extent");
ASSERT(SIZEOF(.sdk_startup_storage_1) == 12, "_ZN3irr2ps5vHalfE extent");
