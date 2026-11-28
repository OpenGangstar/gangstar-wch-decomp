__aeabi_fmul = 0x001c4724;
OUTPUT_FORMAT("elf32-littlearm")
OUTPUT_ARCH(arm)
INCLUDE build/matches/sdk-startup-scenecamera/retail-symbols.ld
_ZdlPv = 0x001c42b0;
__aeabi_atexit = 0x001c494c;
INCLUDE config/linker/SceneCameraGS3DProvider.ld
__aeabi_i2f = 0x001c41e4;
SECTIONS
{
    .gs_add_xref 0x002deebc : { *gs3d-stuff.o(.text._ZN9GS3DStuff7AddXRefEPN3irr5scene10ISceneNodeE) }
    .gs_update_visibility 0x002dd7e0 : { *gs3d-stuff.o(.text._ZN9GS3DStuff16updateVisibilityEj) }
    .gs_create_static_bodies 0x002ddf78 : { *gs3d-stuff.o(.text._ZN9GS3DStuff18CreateStaticBodiesEPN3irr5scene10ISceneNodeES3_S3_S3_) }
    .gs_create_static_bodies_id 0x004b6a8c (NOLOAD) : { *gs3d-stuff.o(.bss._ZZN9GS3DStuff18CreateStaticBodiesEPN3irr5scene10ISceneNodeES3_S3_S3_E2ID) }
    .gs_get_polys_iter 0x002dd33c : { *gs3d-stuff.o(.text._ZNK11OctTreeAABB15OctTreeAABBNode12getPolysIterERKN3irr4core8aabbox3dIfEEPNS2_5arrayIP16CollisionBodyDefNS2_12irrAllocatorIS9_EEEEPNS7_IP10SpawnPointNSA_ISF_EEEEPNS7_IPNS1_5scene10ISceneNodeENSA_ISL_EEEE) }
    .gs_draw_body 0x002dc958 : { *gs3d-stuff.o(.text._ZN9GS3DStuff8DrawBodyEP6b2BodyN3irr5video6SColorE) }
    .scene_camera_load 0x00334fe8 : { *sdk-startup-scenecamera.o(.text._ZN11SceneCamera4LoadERKN7Structs11SceneCameraE) }
    ASSERT(SIZEOF(.scene_camera_load) == 96, "SceneCamera Load native96 strict extent")
    .scene_factory_cleanup 0x00334ef0 : { *sdk-startup-scenecamera.o(.text.__tcf_0) }
    ASSERT(SIZEOF(.scene_factory_cleanup) == 36, "SceneCamera actual cleanup native36 extent")
    .scene_camera_init 0x00334ee4 : { *sdk-startup-scenecamera.o(.text._ZN11SceneCamera4initEP11LevelObjecti) }
    .scene_camera_vtable 0x004acd10 : { *sdk-startup-scenecamera.o(.data.rel.ro._ZTV11SceneCamera) }
    .scene_camera_base_spawn_type 0x002f74d0 : { *(.gnu.linkonce.t._ZN11LevelObject12getSpawnTypeEv) }
    .scene_camera_debug 0x00334ee8 : { *sdk-startup-scenecamera.o(.text._ZN11SceneCamera5debugEPN3irr5video12IVideoDriverE) }
    .scene_camera_update 0x00334eec : { *sdk-startup-scenecamera.o(.text._ZN11SceneCamera6updateEf) }
    .scene_camera_ctor 0x00334fa0 : { *sdk-startup-scenecamera.o(.text._ZN11SceneCameraC1Ei .text._ZN11SceneCameraC2Ei) }
    .scene_camera_dtor 0x00334f70 : { *sdk-startup-scenecamera.o(.text._ZN11SceneCameraD1Ev .text._ZN11SceneCameraD2Ev) }
    .scene_camera_delete 0x00334f28 : { *sdk-startup-scenecamera.o(.text._ZN11SceneCameraD0Ev) }
    .scene_camera_dtor_thunk 0x00334f5c : { *sdk-startup-scenecamera.o(.text._ZThn28_N11SceneCameraD1Ev) }
    .scene_camera_delete_thunk 0x00334f14 : { *sdk-startup-scenecamera.o(.text._ZThn28_N11SceneCameraD0Ev) }
    .sdk_startup_function_0 0x003350c8 : { *sdk-startup-scenecamera.o(.text.__tcf_2) }
    .sdk_startup_function_1 0x00335048 : { *sdk-startup-scenecamera.o(.text._Z41__static_initialization_and_destruction_0ii) }
    .sdk_startup_function_2 0x003350b4 : { *sdk-startup-scenecamera.o(.text._GLOBAL__I__ZN11SceneCameraC2Ei) }
    .sdk_startup_storage_0 0x004b9ee0 (NOLOAD) : { *sdk-startup-scenecamera.o(.bss._ZN3irr5scene6quake315irrEmptyStringcE) }
    .sdk_startup_storage_1 0x004b9f00 (NOLOAD) : { *sdk-startup-scenecamera.o(.bss._ZN3irr2ps5vHalfE) }
    .shared_startup_empty_text 0x0044d91c : { *(.gnu.linkonce.r.localStartupEmptyText) }
    .got 0x004b0048 : { *(.got.plt) . = 0x360; *(.got) }
    .verification 0x00600000 : { *retail-got.o(.text)
        *gs3d-stuff.o(.rodata.*15colladaMeshNodeE)
        *gs3d-stuff.o(.rodata.*21visibilityColladaMeshE .rodata.*21visibilityColladaSkinE .rodata.*16visibilitySkyBoxE .rodata.*17visibilityUnknownE)
        *gs3d-stuff.o(.rodata.*18colladaSkinnedNodeE)
        *gs3d-stuff.o(.rodata.*7lodNodeE)
 }
}
ASSERT(SIZEOF(.sdk_startup_storage_0) == 32, "_ZN3irr5scene6quake315irrEmptyStringcE extent");
ASSERT(SIZEOF(.sdk_startup_storage_1) == 12, "_ZN3irr2ps5vHalfE extent");
INCLUDE config/linker/GS3DLoadSections.ld
ASSERT(ADDR(.gs_load) == 0x002dfb14, "load native placement");
ASSERT(SIZEOF(.gs_load) == 2576, "load native extent");
ASSERT(SIZEOF(.gs_load_switch) == 56, "load switch extent");
ASSERT(SIZEOF(.gs_load_weights) == 56, "load weights extent");
