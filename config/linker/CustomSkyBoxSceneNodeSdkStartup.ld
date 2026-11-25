OUTPUT_FORMAT("elf32-littlearm")
OUTPUT_ARCH(arm)
INCLUDE build/matches/sdk-startup-customskyboxscenenode/retail-symbols.ld
_ZdlPv = 0x001c42b0;
__aeabi_atexit = 0x001c494c;
_Znwj = 0x001c4814;
__aeabi_fmul = 0x001c4724;
__cxa_pure_virtual = 0;
SECTIONS
{
    .skybox_sun_name 0x0041d1e0 : { *sdk-startup-customskyboxscenenode.o(.rodata.str1.4) }
    .skybox_material_ctor 0x0020e7ec : { *sdk-startup-customskyboxscenenode.o(.text._ZN3irr5video9SMaterialC1Ev .gnu.linkonce.t._ZN3irr5video9SMaterialC1Ev) }
    .skybox_ctor_c2 0x002faab8 : { *sdk-startup-customskyboxscenenode.o(.text._ZN21CustomSkyBoxSceneNodeC2EPN3irr5video8ITextureEPNS0_5scene10ISceneNodeEi) }
    .skybox_ctor_c1 0x002f96e8 : { *sdk-startup-customskyboxscenenode.o(.text._ZN21CustomSkyBoxSceneNodeC1EPN3irr5video8ITextureEPNS0_5scene10ISceneNodeEi) }
    .skybox_set_sky_color 0x002f84c8 : { *sdk-startup-customskyboxscenenode.o(.text._ZN21CustomSkyBoxSceneNode11setSkyColorEb) }
    .skybox_dtor_0 0x002fbee8 : { *sdk-startup-customskyboxscenenode.o(.text._ZN21CustomSkyBoxSceneNodeD1Ev .gnu.linkonce.t._ZN21CustomSkyBoxSceneNodeD1Ev) }
    .skybox_dtor_1 0x002fbe28 : { *sdk-startup-customskyboxscenenode.o(.text._ZN21CustomSkyBoxSceneNodeD0Ev .gnu.linkonce.t._ZN21CustomSkyBoxSceneNodeD0Ev) }
    .skybox_dtor_2 0x002fbe00 : { *sdk-startup-customskyboxscenenode.o(.text._ZTv0_n12_N21CustomSkyBoxSceneNodeD0Ev .gnu.linkonce.t._ZTv0_n12_N21CustomSkyBoxSceneNodeD0Ev) }
    .skybox_dtor_3 0x002fbe14 : { *sdk-startup-customskyboxscenenode.o(.text._ZTv0_n24_N21CustomSkyBoxSceneNodeD0Ev .gnu.linkonce.t._ZTv0_n24_N21CustomSkyBoxSceneNodeD0Ev) }
    .skybox_dtor_4 0x002fbec0 : { *sdk-startup-customskyboxscenenode.o(.text._ZTv0_n12_N21CustomSkyBoxSceneNodeD1Ev .gnu.linkonce.t._ZTv0_n12_N21CustomSkyBoxSceneNodeD1Ev) }
    .skybox_dtor_5 0x002fbed4 : { *sdk-startup-customskyboxscenenode.o(.text._ZTv0_n24_N21CustomSkyBoxSceneNodeD1Ev .gnu.linkonce.t._ZTv0_n24_N21CustomSkyBoxSceneNodeD1Ev) }
    .skybox_dtor_6 0x0021a8d4 : { *sdk-startup-customskyboxscenenode.o(.text._ZN3irr2io26IAttributeExchangingObjectD0Ev .gnu.linkonce.t._ZN3irr2io26IAttributeExchangingObjectD0Ev) }
    .skybox_dtor_7 0x0021a91c : { *sdk-startup-customskyboxscenenode.o(.text._ZN3irr2io26IAttributeExchangingObjectD1Ev .gnu.linkonce.t._ZN3irr2io26IAttributeExchangingObjectD1Ev) }
    .skybox_dtor_8 0x0021a958 : { *sdk-startup-customskyboxscenenode.o(.text._ZN3irr2io26IAttributeExchangingObjectD2Ev .gnu.linkonce.t._ZN3irr2io26IAttributeExchangingObjectD2Ev) }
    .skybox_dtor_9 0x0020f09c : { *sdk-startup-customskyboxscenenode.o(.text._ZN3irr5video14SMaterialLayerD1Ev .gnu.linkonce.t._ZN3irr5video14SMaterialLayerD1Ev) }
    .skybox_dtor_10 0x002f9590 : { *sdk-startup-customskyboxscenenode.o(.text._ZN21CustomSkyBoxSceneNode6renderEPv .gnu.linkonce.t._ZN21CustomSkyBoxSceneNode6renderEPv) }
    .skybox_vtable 0x004aa988 : { *sdk-startup-customskyboxscenenode.o(.data.rel.ro._ZTV21CustomSkyBoxSceneNode .gnu.linkonce.d.rel.ro._ZTV21CustomSkyBoxSceneNode) }
    .skybox_vtt 0x004aaad0 : { *sdk-startup-customskyboxscenenode.o(.data.rel.ro._ZTT21CustomSkyBoxSceneNode .gnu.linkonce.d.rel.ro._ZTT21CustomSkyBoxSceneNode) }
    .skybox_scene_node_construction 0x004aaaf0 : { *sdk-startup-customskyboxscenenode.o(.data.rel.ro._ZTC21CustomSkyBoxSceneNode0_N3irr5scene10ISceneNodeE .gnu.linkonce.d.rel.ro._ZTC21CustomSkyBoxSceneNode0_N3irr5scene10ISceneNodeE) }
    .skybox_attributes_construction 0x004aac30 : { *sdk-startup-customskyboxscenenode.o(.data.rel.ro._ZTC21CustomSkyBoxSceneNode0_N3irr2io26IAttributeExchangingObjectE .gnu.linkonce.d.rel.ro._ZTC21CustomSkyBoxSceneNode0_N3irr2io26IAttributeExchangingObjectE) }
    /DISCARD/ : { *(.text._ZN21CustomSkyBoxSceneNodeD2Ev) }
    .skybox_register 0x002f8494 : { *(.text._ZN21CustomSkyBoxSceneNode19OnRegisterSceneNodeEv) }
    .skybox_clone 0x002faa60 : { *(.text._ZN21CustomSkyBoxSceneNode5cloneEPN3irr5scene10ISceneNodeEPNS1_13ISceneManagerE) }
    .type_value 0x002f8478 : { *sdk-startup-customskyboxscenenode.o(.text._ZNK21CustomSkyBoxSceneNode7getTypeEv) }
    .bounds 0x002f8480 : { *sdk-startup-customskyboxscenenode.o(.text._ZNK21CustomSkyBoxSceneNode14getBoundingBoxEv) }
    .material 0x002f8488 : { *sdk-startup-customskyboxscenenode.o(.text._ZN21CustomSkyBoxSceneNode11getMaterialEj) }
    .material_count 0x002f8490 : { *sdk-startup-customskyboxscenenode.o(.text._ZNK21CustomSkyBoxSceneNode16getMaterialCountEv) }
    .sdk_startup_function_0 0x002f9560 : { *sdk-startup-customskyboxscenenode.o(.text.__tcf_2) }
    .sdk_startup_function_1 0x002f94e0 : { *sdk-startup-customskyboxscenenode.o(.text._Z41__static_initialization_and_destruction_0ii) }
    .sdk_startup_function_2 0x002f954c : { *sdk-startup-customskyboxscenenode.o(.text._GLOBAL__I__ZN21CustomSkyBoxSceneNodeC2EPN3irr5video8ITextureEPNS0_5scene10ISceneNodeEi) }
    .sdk_startup_storage_0 0x004b7f00 (NOLOAD) : { *sdk-startup-customskyboxscenenode.o(.bss._ZN3irr5scene6quake315irrEmptyStringcE) }
    .sdk_startup_storage_1 0x004b7f20 (NOLOAD) : { *sdk-startup-customskyboxscenenode.o(.bss._ZN3irr2ps5vHalfE) }
    .shared_startup_empty_text 0x0044d91c : { *(.gnu.linkonce.r.localStartupEmptyText) }
    .got 0x004b0048 : { *(.got.plt) . = 0x360; *(.got) }
    .verification 0x00600000 : { *retail-got.o(.text) }
}
ASSERT(SIZEOF(.sdk_startup_storage_0) == 32, "_ZN3irr5scene6quake315irrEmptyStringcE extent");
ASSERT(SIZEOF(.sdk_startup_storage_1) == 12, "_ZN3irr2ps5vHalfE extent");
