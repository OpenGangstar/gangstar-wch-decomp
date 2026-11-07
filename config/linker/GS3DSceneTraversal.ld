SECTIONS {
    .gs_find_mesh_plane 0x004144e8 : { *gs3d-stuff.o(.rodata.*planeNodeMarker*) }
    .gs_find_mesh_jump 0x004144f0 : { *gs3d-stuff.o(.rodata.*jumpNodeMarker*) }
    .gs_set_culling 0x002dc078 : { *gs3d-stuff.o(.text._ZN9GS3DStuff10SetCullingEPN3irr5scene10ISceneNodeENS1_14E_CULLING_TYPEE) }
    .gs_set_material_texture 0x002dc134 : { *gs3d-stuff.o(.text._ZN9GS3DStuff18SetMaterialTextureEPN3irr5scene10ISceneNodeEPNS0_5video8ITextureE) }
    .gs_find_a_mesh 0x002dc174 : { *gs3d-stuff.o(.text._ZN9GS3DStuff9FindAMeshEPN3irr5scene10ISceneNodeE) }
    .gs_set_visibility 0x002dc038 : { *gs3d-stuff.o(.text._ZN9GS3DStuff13SetVisibilityEPN3irr5scene10ISceneNodeEb) }
    .gs_set_material_type 0x002dc0a4 : { *gs3d-stuff.o(.text._ZN9GS3DStuff15SetMaterialTypeEPN3irr5scene10ISceneNodeENS0_5video15E_MATERIAL_TYPEE) }
    .gs_set_material_flag 0x002dc0ec : { *gs3d-stuff.o(.text._ZN9GS3DStuff15SetMaterialFlagEPN3irr5scene10ISceneNodeENS0_5video15E_MATERIAL_FLAGEb) }
}
