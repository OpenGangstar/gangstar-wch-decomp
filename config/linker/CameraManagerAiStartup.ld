OUTPUT_FORMAT("elf32-littlearm")
OUTPUT_ARCH(arm)
INCLUDE build/matches/ai-startup-cameramanager/retail-symbols.ld
_ZdlPv = 0x001c42b0;
__android_log_print = 0x001c4238;
_Znwj = 0x001c4814;
__aeabi_i2f = 0x001c41e4;
__aeabi_fmul = 0x001c4724;
__aeabi_f2iz = 0x001c44cc;
__aeabi_fcmpge = 0x001c4364;
__aeabi_fcmpgt = 0x001c419c;
__aeabi_fcmplt = 0x001c479c;
__aeabi_fcmpeq = 0x001c470c;
__aeabi_fdiv = 0x001c4520;
__aeabi_fadd = 0x001c4154;
__aeabi_fsub = 0x001c4328;
__aeabi_atexit = 0x001c494c;
_ZN32retail_cameramanager_transitions16civPassive_transE = 0x004289dc;
_ZN32retail_cameramanager_transitions17scriptedNpc_transE = 0x00428b08;
_ZN32retail_cameramanager_transitions19civAggressive_transE = 0x00428b38;
_ZN32retail_cameramanager_transitions16gangMember_transE = 0x00428c1c;
_ZN32retail_cameramanager_transitions9cop_transE = 0x00428c28;
_ZN32retail_cameramanager_transitions10swat_transE = 0x00428d60;
_ZN32retail_cameramanager_transitions17civ_vehicle_transE = 0x00428d6c;
_ZN32retail_cameramanager_transitions17cop_vehicle_transE = 0x00428dfc;
_ZN32retail_cameramanager_transitions11guard_transE = 0x00428eb0;
_ZN32retail_cameramanager_transitions22scripted_vehicle_transE = 0x00428f58;
__cxa_pure_virtual = 0;
SECTIONS
{
    .touchable_vtable 0x004ac418 : { *ai-startup-cameramanager.o(.gnu.linkonce.d.rel.ro._ZTV10ITouchable) }
    .manager_touch_release 0x00333094 : { *ai-startup-cameramanager.o(.text._ZN13CameraManager19processTouchReleaseEv) }
    .manager_touch_release_log 0x00428fac : { *ai-startup-cameramanager.o(.rodata.touchReleaseLogText) }
    .manager_tapped_target 0x00332f94 : { *ai-startup-cameramanager.o(.text._ZNK13CameraManager12tappedTargetERKN3irr4core10position2dIiEERKNS1_8vector3dIfEE) }
    .manager_process_touch 0x00332bf0 : { *ai-startup-cameramanager.o(.text._ZN13CameraManager12processTouchEl) }
    .manager_vtable 0x004acc78 : { *ai-startup-cameramanager.o(.data.rel.ro._ZTV13CameraManager) }
    .touch_point_d0 0x00326374 : { *ai-startup-cameramanager.o(.gnu.linkonce.t._ZN7Point2DIsED0Ev) }
    .touch_point_d1 0x00326394 : { *ai-startup-cameramanager.o(.gnu.linkonce.t._ZN7Point2DIsED1Ev) }
    .touch_point_vtable 0x004abf88 : { *ai-startup-cameramanager.o(.gnu.linkonce.d.rel.ro._ZTV7Point2DIsE) }
    .manager_up_vector 0x00332080 : { *ai-startup-cameramanager.o(.text._ZN13CameraManager14updateUpVectorEf) }
    .manager_go_to_side 0x00332144 : { *ai-startup-cameramanager.o(.text._ZN13CameraManager8goToSideEb) }
    .manager_go_behind 0x00332200 : { *ai-startup-cameramanager.o(.text._ZN13CameraManager8goBehindEP11LevelObject) }
    .manager_vector_update 0x00331df4 : { *ai-startup-cameramanager.o(.text._ZN14AnimatableTypeIN3irr4core8vector3dIfEEE6UpdateEf) }
    .manager_enter_mode 0x003322bc : { *ai-startup-cameramanager.o(.text._ZN13CameraManager9enterModeEiP11LevelObjectfi) }
    .manager_mode_table 0x004289c8 : { *ai-startup-cameramanager.o(.rodata._ZN13CameraManager9enterModeEiP11LevelObjectfi) }
    .manager_ctor 0x003323d0 : { *ai-startup-cameramanager.o(.text._ZN13CameraManagerC1EfffP11LevelObject .text._ZN13CameraManagerC2EfffP11LevelObject) }
    .manager_dtor 0x00331d74 : { *ai-startup-cameramanager.o(.text._ZN13CameraManagerD1Ev .text._ZN13CameraManagerD2Ev) }
    .manager_clean 0x00332010 : { *ai-startup-cameramanager.o(.text._ZN13CameraManager5cleanEv) }
    .manager_update_transition 0x0033257c : { *ai-startup-cameramanager.o(.text._ZN13CameraManager16updateTransitionEf) }
    .manager_set_fov 0x00331d8c : { *ai-startup-cameramanager.o(.text._ZN13CameraManager6setFOVEi) }
    .manager_get_fov 0x00331db0 : { *ai-startup-cameramanager.o(.text._ZN13CameraManager6getFOVEv) }
    .manager_get_camera 0x00331dd4 : { *ai-startup-cameramanager.o(.text._ZNK13CameraManager9getCameraEv) }
    .manager_debug 0x00331dd8 : { *ai-startup-cameramanager.o(.text._ZN13CameraManager5debugEPN3irr5video12IVideoDriverE) }
    .manager_scene_camera 0x00331ddc : { *ai-startup-cameramanager.o(.text._ZN13CameraManager14setSceneCameraEP11SceneCamera) }
    .manager_touch_inputs 0x00331de4 : { *ai-startup-cameramanager.o(.text._ZN13CameraManager20setTouchScreenInputsEb) }
    .manager_is_used 0x00331dec : { *ai-startup-cameramanager.o(.text._ZNK13CameraManager6isUsedEv) }
    .manager_get_position 0x00331ff0 : { *ai-startup-cameramanager.o(.text._ZNK13CameraManager11getPositionEv) }
    .manager_get_look_at 0x00332000 : { *ai-startup-cameramanager.o(.text._ZNK13CameraManager9getLookAtEv) }
    .manager_get_instance 0x00332538 : { *ai-startup-cameramanager.o(.text._ZN13CameraManager11getInstanceEv) }
    .manager_singleton 0x004b9cc0 (NOLOAD) : { *ai-startup-cameramanager.o(.bss._ZN13CameraManager4s_cmE) }
    .ai_startup_function_0 0x00331fc0 : { *ai-startup-cameramanager.o(.text.__tcf_3) }
    .ai_startup_function_1 0x00332618 : { *ai-startup-cameramanager.o(.text._Z41__static_initialization_and_destruction_0ii) }
    .ai_startup_function_2 0x0033275c : { *ai-startup-cameramanager.o(.text._GLOBAL__I__ZN13CameraManager4s_cmE) }
    .ai_startup_storage_0 0x004b9cc4 (NOLOAD) : { *ai-startup-cameramanager.o(.bss._ZN3irr5scene6quake315irrEmptyStringcE) }
    .ai_startup_storage_1 0x004b9ce4 (NOLOAD) : { *ai-startup-cameramanager.o(.bss._ZN3irr2ps5vHalfE) }
    .ai_startup_storage_2 0x004b9cf0 (NOLOAD) : { *ai-startup-cameramanager.o(.bss._ZN8gameloft2ai11civ_passiveE) }
    .ai_startup_storage_3 0x004b9cf8 (NOLOAD) : { *ai-startup-cameramanager.o(.bss._ZN8gameloft2ai12npc_scriptedE) }
    .ai_startup_storage_4 0x004b9d00 (NOLOAD) : { *ai-startup-cameramanager.o(.bss._ZN8gameloft2ai13civ_agressiveE) }
    .ai_startup_storage_5 0x004b9d08 (NOLOAD) : { *ai-startup-cameramanager.o(.bss._ZN8gameloft2ai11gang_memberE) }
    .ai_startup_storage_6 0x004b9d10 (NOLOAD) : { *ai-startup-cameramanager.o(.bss._ZN8gameloft2ai3copE) }
    .ai_startup_storage_7 0x004b9d18 (NOLOAD) : { *ai-startup-cameramanager.o(.bss._ZN8gameloft2ai4swatE) }
    .ai_startup_storage_8 0x004b9d20 (NOLOAD) : { *ai-startup-cameramanager.o(.bss._ZN8gameloft2ai11civ_vehicleE) }
    .ai_startup_storage_9 0x004b9d28 (NOLOAD) : { *ai-startup-cameramanager.o(.bss._ZN8gameloft2ai11cop_vehicleE) }
    .ai_startup_storage_10 0x004b9d30 (NOLOAD) : { *ai-startup-cameramanager.o(.bss._ZN8gameloft2ai5guardE) }
    .ai_startup_storage_11 0x004b9d38 (NOLOAD) : { *ai-startup-cameramanager.o(.bss._ZN8gameloft2ai16scripted_vehicleE) }
    .shared_startup_empty_text 0x0044d91c : { *(.gnu.linkonce.r.localStartupEmptyText) }
    .got 0x004b0048 : { *(.got.plt) . = 0x360; *(.got) }
    .verification 0x00600000 : { *retail-got.o(.text) }
}
ASSERT(SIZEOF(.ai_startup_storage_0) == 32, "_ZN3irr5scene6quake315irrEmptyStringcE extent");
ASSERT(SIZEOF(.ai_startup_storage_1) == 12, "_ZN3irr2ps5vHalfE extent");
ASSERT(SIZEOF(.ai_startup_storage_2) == 8, "_ZN8gameloft2ai11civ_passiveE extent");
ASSERT(SIZEOF(.ai_startup_storage_3) == 8, "_ZN8gameloft2ai12npc_scriptedE extent");
ASSERT(SIZEOF(.ai_startup_storage_4) == 8, "_ZN8gameloft2ai13civ_agressiveE extent");
ASSERT(SIZEOF(.ai_startup_storage_5) == 8, "_ZN8gameloft2ai11gang_memberE extent");
ASSERT(SIZEOF(.ai_startup_storage_6) == 8, "_ZN8gameloft2ai3copE extent");
ASSERT(SIZEOF(.ai_startup_storage_7) == 8, "_ZN8gameloft2ai4swatE extent");
ASSERT(SIZEOF(.ai_startup_storage_8) == 8, "_ZN8gameloft2ai11civ_vehicleE extent");
ASSERT(SIZEOF(.ai_startup_storage_9) == 8, "_ZN8gameloft2ai11cop_vehicleE extent");
ASSERT(SIZEOF(.ai_startup_storage_10) == 8, "_ZN8gameloft2ai5guardE extent");
ASSERT(SIZEOF(.ai_startup_storage_11) == 8, "_ZN8gameloft2ai16scripted_vehicleE extent");

ASSERT(SIZEOF(.touchable_vtable) == 24, "ITouchable vtable extent");
