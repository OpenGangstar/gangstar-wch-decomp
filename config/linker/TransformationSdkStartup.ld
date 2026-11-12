OUTPUT_FORMAT("elf32-littlearm")
OUTPUT_ARCH(arm)
INCLUDE build/matches/sdk-startup-transformation/retail-symbols.ld
_ZdlPv = 0x001c42b0;
__aeabi_atexit = 0x001c494c;
__aeabi_fmul = 0x001c4724;
SECTIONS
{
    .transformation_grab_node 0x003078b0 : { *(.text._ZN14Transformation13grabSceneNodeEiPPPv) }
    .transformation_base_spawn_type 0x002f74d0 : { *(.gnu.linkonce.t._ZN11LevelObject12getSpawnTypeEv) }
    .transformation_vtable 0x004ab150 : { *(.data.rel.ro._ZTV14Transformation) }
    .transformation_ctor 0x003079ec : { *(.text._ZN14TransformationC1Ei .text._ZN14TransformationC2Ei) }
    .transformation_dtor 0x0030792c : { *(.text._ZN14TransformationD1Ev .text._ZN14TransformationD2Ev) }
    .transformation_delete 0x00307904 : { *(.text._ZN14TransformationD0Ev) }
    .transformation_set_euler 0x00307980 : { *(.text._ZN14Transformation11SetRotationERKN3irr4core8vector3dIfEE) }
    .transformation_drop_node 0x003078a4 : { *(.text._ZN14Transformation13dropSceneNodeEv) }
    .transformation_right 0x00307808 : { *(.text._ZNK14Transformation8GetRightEv) }
    .transformation_front 0x0030794c : { *(.text._ZNK14Transformation8GetFrontEv) }
    .transformation_material 0x003077e0 : { *(.text._ZNK14Transformation8GetMatIDEv) }
    .transformation_triangle 0x003077e8 : { *(.text._ZNK14Transformation8GetTriIDEv) }
    .transformation_set_rotation 0x003077f0 : { *(.text._ZN14Transformation11SetRotationERKN3irr4core10quaternionE) }
    .transformation_get_rotation 0x00307804 : { *(.text._ZNK14Transformation11GetRotationEv) }
    .transformation_get_position 0x0030783c : { *(.text._ZNK14Transformation11GetPositionEv) }
    .transformation_set_position 0x0030784c : { *(.text._ZN14Transformation11SetPositionERKN3irr4core8vector3dIfEE) }
    .sdk_startup_function_0 0x00307ad0 : { *sdk-startup-transformation.o(.text.__tcf_2) }
    .sdk_startup_function_1 0x00307a2c : { *sdk-startup-transformation.o(.text._Z41__static_initialization_and_destruction_0ii) }
    .sdk_startup_function_2 0x00307a98 : { *sdk-startup-transformation.o(.text._GLOBAL__I__ZN14TransformationC2Ei) }
    .sdk_startup_storage_0 0x004b86f8 (NOLOAD) : { *sdk-startup-transformation.o(.bss._ZN3irr5scene6quake315irrEmptyStringcE) }
    .sdk_startup_storage_1 0x004b8718 (NOLOAD) : { *sdk-startup-transformation.o(.bss._ZN3irr2ps5vHalfE) }
    .shared_startup_empty_text 0x0044d91c : { *(.gnu.linkonce.r.localStartupEmptyText) }
    .got 0x004b0048 : { *(.got.plt) . = 0x360; *(.got) }
    .verification 0x00600000 : { *retail-got.o(.text) }
}
ASSERT(SIZEOF(.sdk_startup_storage_0) == 32, "_ZN3irr5scene6quake315irrEmptyStringcE extent");
ASSERT(SIZEOF(.sdk_startup_storage_1) == 12, "_ZN3irr2ps5vHalfE extent");
