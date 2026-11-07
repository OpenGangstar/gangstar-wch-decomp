SECTIONS {
    .gs_shape_def_delete 0x002db47c : { *gs3d-stuff.o(.gnu.linkonce.t._ZN10b2ShapeDefD0Ev) }
    .gs_shape_def_dtor 0x002db49c : { *gs3d-stuff.o(.gnu.linkonce.t._ZN10b2ShapeDefD1Ev) }
    .gs_polygon_def_dtor 0x002df3f4 : { *gs3d-stuff.o(.gnu.linkonce.t._ZN12b2PolygonDefD1Ev) }
    .gs_polygon_def_delete 0x002df628 : { *gs3d-stuff.o(.gnu.linkonce.t._ZN12b2PolygonDefD0Ev) }
    .gs_polygon_def_vtable 0x004a8ac8 : { *gs3d-stuff.o(.gnu.linkonce.d.rel.ro._ZTV12b2PolygonDef) }
    .gs_shape_def_vtable 0x004a8ad8 : { *gs3d-stuff.o(.gnu.linkonce.d.rel.ro._ZTV10b2ShapeDef) }
    .gs_set_material_type_condition 0x002dc41c : { *gs3d-stuff.o(.text._ZN9GS3DStuff24SetMaterialTypeConditionEPN3irr5scene10ISceneNodeENS0_5video15E_MATERIAL_TYPEEPNS4_8ITextureE) }
    .gs_collision_body_def_dtor 0x002db304 : { *gs3d-stuff.o(.gnu.linkonce.t._ZN16CollisionBodyDefD1Ev) }
    .gs_octree_dtor 0x002dd6e0 : { *gs3d-stuff.o(.gnu.linkonce.t._ZN11OctTreeAABBD1Ev) }
    .gs_octree_calculate_polys 0x002dd5a8 : { *gs3d-stuff.o(.gnu.linkonce.t._ZN11OctTreeAABB14calculatePolysERKN3irr4core8aabbox3dIfEEPNS1_5arrayIP16CollisionBodyDefNS1_12irrAllocatorIS8_EEEEPNS6_IP10SpawnPointNS9_ISE_EEEEPNS6_IPNS0_5scene10ISceneNodeENS9_ISK_EEEE) }
    .gs_octree_build_roots 0x002dbbc8 : { *gs3d-stuff.o(.gnu.linkonce.t._ZN11OctTreeAABB14BuildRootNodesEPN3irr5scene10ISceneNodeEPNS0_4core5arrayIPNS_8RootNodeENS4_12irrAllocatorIS7_EEEE) }
    .gs_add_renderables 0x002dc20c : { *gs3d-stuff.o(.text._ZN9GS3DStuff14AddRenderablesEPN3irr5scene10ISceneNodeERNS0_4core5arrayIS3_NS4_12irrAllocatorIS3_EEEENS1_16ESCENE_NODE_TYPEE) }
    .gs_octree_spawn_point_nodes 0x002db7a4 : { *gs3d-stuff.o(.text._ZN11OctTreeAABB20BuildSpawnPointNodesEPN3irr4core5arrayIPNS_8RootNodeENS1_12irrAllocatorIS4_EEEE .gnu.linkonce.t._ZN11OctTreeAABB20BuildSpawnPointNodesEPN3irr4core5arrayIPNS_8RootNodeENS1_12irrAllocatorIS4_EEEE) }
    .gs_octree_count_renderables 0x002db88c : { *gs3d-stuff.o(.text._ZN11OctTreeAABB20CountRenderableNodesEPN3irr5scene10ISceneNodeE .gnu.linkonce.t._ZN11OctTreeAABB20CountRenderableNodesEPN3irr5scene10ISceneNodeE) }
    .gs_octree_root_dtor 0x002db3f4 : { *gs3d-stuff.o(.text._ZN11OctTreeAABB8RootNodeD1Ev .gnu.linkonce.t._ZN11OctTreeAABB8RootNodeD1Ev) }
    .gs_delete_octree_root 0x002db420 : { *gs3d-stuff.o(.text._Z10SafeDeleteIN11OctTreeAABB8RootNodeEEvRPT_ .gnu.linkonce.t._Z10SafeDeleteIN11OctTreeAABB8RootNodeEEvRPT_) }
    .gs_delete_spawn_array 0x002dd61c : { *gs3d-stuff.o(.text._Z10SafeDeleteIN3irr4core5arrayIP10SpawnPointNS1_12irrAllocatorIS4_EEEEEvRPT_ .gnu.linkonce.t._Z10SafeDeleteIN3irr4core5arrayIP10SpawnPointNS1_12irrAllocatorIS4_EEEEEvRPT_) }
    .gs_delete_octree_root_array 0x002dd644 : { *gs3d-stuff.o(.text._Z10SafeDeleteIN3irr4core5arrayIPN11OctTreeAABB8RootNodeENS1_12irrAllocatorIS5_EEEEEvRPT_ .gnu.linkonce.t._Z10SafeDeleteIN3irr4core5arrayIPN11OctTreeAABB8RootNodeENS1_12irrAllocatorIS5_EEEEEvRPT_) }
    .gs_octree_node_dtor 0x002dd66c : { *gs3d-stuff.o(.text._ZN11OctTreeAABB15OctTreeAABBNodeD1Ev .gnu.linkonce.t._ZN11OctTreeAABB15OctTreeAABBNodeD1Ev) }
    .gs_delete_octree_node 0x002dd6b0 : { *gs3d-stuff.o(.text._Z10SafeDeleteIN11OctTreeAABB15OctTreeAABBNodeEEvRPT_ .gnu.linkonce.t._Z10SafeDeleteIN11OctTreeAABB15OctTreeAABBNodeEEvRPT_) }
    .gs_delete_octree 0x002dd750 : { *gs3d-stuff.o(.text._Z10SafeDeleteI11OctTreeAABBEvRPT_ .gnu.linkonce.t._Z10SafeDeleteI11OctTreeAABBEvRPT_) }
    .gs_delete_scene_node_array 0x002db1a0 : { *gs3d-stuff.o(.text._Z10SafeDeleteIN3irr4core5arrayIPNS0_5scene10ISceneNodeENS1_12irrAllocatorIS5_EEEEEvRPT_ .gnu.linkonce.t._Z10SafeDeleteIN3irr4core5arrayIPNS0_5scene10ISceneNodeENS1_12irrAllocatorIS5_EEEEEvRPT_) }
    .gs_delete_polygon_def_array 0x002db28c : { *gs3d-stuff.o(.text._Z10SafeDeleteIN3irr4core5arrayIP12b2PolygonDefNS1_12irrAllocatorIS4_EEEEEvRPT_ .gnu.linkonce.t._Z10SafeDeleteIN3irr4core5arrayIP12b2PolygonDefNS1_12irrAllocatorIS4_EEEEEvRPT_) }
    .gs_delete_body_def_array 0x002db2b4 : { *gs3d-stuff.o(.text._Z10SafeDeleteIN3irr4core5arrayIP9b2BodyDefNS1_12irrAllocatorIS4_EEEEEvRPT_ .gnu.linkonce.t._Z10SafeDeleteIN3irr4core5arrayIP9b2BodyDefNS1_12irrAllocatorIS4_EEEEEvRPT_) }
    .gs_delete_body_array 0x002db2dc : { *gs3d-stuff.o(.text._Z10SafeDeleteIN3irr4core5arrayIP6b2BodyNS1_12irrAllocatorIS4_EEEEEvRPT_ .gnu.linkonce.t._Z10SafeDeleteIN3irr4core5arrayIP6b2BodyNS1_12irrAllocatorIS4_EEEEEvRPT_) }
    .gs_delete_collision_body_def 0x002db3c4 : { *gs3d-stuff.o(.text._Z10SafeDeleteI16CollisionBodyDefEvRPT_ .gnu.linkonce.t._Z10SafeDeleteI16CollisionBodyDefEvRPT_) }
    .gs_collision_body_def_ctor 0x002db83c : { *gs3d-stuff.o(.text._ZN16CollisionBodyDefC1Ev .gnu.linkonce.t._ZN16CollisionBodyDefC1Ev) }
    .gs_free_game_data 0x002dbfe4 : { *gs3d-stuff.o(.text._ZN9GS3DStuff12freeGameDataEPN3irr5scene10ISceneNodeE .gnu.linkonce.t._ZN9GS3DStuff12freeGameDataEPN3irr5scene10ISceneNodeE) }
    .gs_delete_collision_def_array 0x002de8ec : { *gs3d-stuff.o(.text._Z10SafeDeleteIN3irr4core5arrayIP16CollisionBodyDefNS1_12irrAllocatorIS4_EEEEEvRPT_ .gnu.linkonce.t._Z10SafeDeleteIN3irr4core5arrayIP16CollisionBodyDefNS1_12irrAllocatorIS4_EEEEEvRPT_) }
    .gs_clean_node_pivot 0x004144f8 : { *gs3d-stuff.o(.rodata.*pivotNodeMarker*) }
    .gs_clean_node 0x002dc2cc : { *gs3d-stuff.o(.text._ZN9GS3DStuff9CleanNodeEPN3irr5scene10ISceneNodeE) }
    .gs_set_sky_color 0x002dbac8 : { *gs3d-stuff.o(.text._ZN9GS3DStuff11setSkyColorEb) }
    .gs_find_mesh_plane 0x004144e8 : { *gs3d-stuff.o(.rodata.*planeNodeMarker*) }
    .gs_find_mesh_jump 0x004144f0 : { *gs3d-stuff.o(.rodata.*jumpNodeMarker*) }
    .gs_set_culling 0x002dc078 : { *gs3d-stuff.o(.text._ZN9GS3DStuff10SetCullingEPN3irr5scene10ISceneNodeENS1_14E_CULLING_TYPEE) }
    .gs_set_material_texture 0x002dc134 : { *gs3d-stuff.o(.text._ZN9GS3DStuff18SetMaterialTextureEPN3irr5scene10ISceneNodeEPNS0_5video8ITextureE) }
    .gs_find_a_mesh 0x002dc174 : { *gs3d-stuff.o(.text._ZN9GS3DStuff9FindAMeshEPN3irr5scene10ISceneNodeE) }
    .gs_set_visibility 0x002dc038 : { *gs3d-stuff.o(.text._ZN9GS3DStuff13SetVisibilityEPN3irr5scene10ISceneNodeEb) }
    .gs_set_material_type 0x002dc0a4 : { *gs3d-stuff.o(.text._ZN9GS3DStuff15SetMaterialTypeEPN3irr5scene10ISceneNodeENS0_5video15E_MATERIAL_TYPEE) }
    .gs_set_material_flag 0x002dc0ec : { *gs3d-stuff.o(.text._ZN9GS3DStuff15SetMaterialFlagEPN3irr5scene10ISceneNodeENS0_5video15E_MATERIAL_FLAGEb) }
}
