__aeabi_fadd = 0x001c4154;
__aeabi_f2iz = 0x001c44cc;
__aeabi_idivmod = 0x001c4934;
__aeabi_i2f = 0x001c41e4;
__aeabi_fsub = 0x001c4328;
__aeabi_fmul = 0x001c4724;
__aeabi_fcmplt = 0x001c479c;
__aeabi_fcmpgt = 0x001c419c;
__aeabi_f2d = 0x001c48f8;
__aeabi_d2f = 0x001c4310;
__aeabi_fcmple = 0x001c43ac;
sqrt = 0x001c401c;
acosf = 0x001c4694;
INCLUDE config/linker/PhysicAttributesResetSections.ld
SECTIONS
{
    .character_clean_physic 0x002f2fe0 : { *ai-startup-character.o(.text._ZN9Character11cleanPhysicEv) }
    .character_on_despawn 0x002f2a0c : { *ai-startup-character.o(.text._ZN9Character9OnDespawnEv) }
    .character_on_spawn 0x002f2bb4 : { *ai-startup-character.o(.text._ZN9Character7OnSpawnEv) }
    .character_free_blood_objects 0x002f185c : { *ai-startup-character.o(.text._ZN9Character16freeBloodObjectsEv) }
    .character_load_blood_objects 0x002f18b4 : { *ai-startup-character.o(.text._ZN9Character16loadBloodObjectsEPKcS1_) }
    .character_blood_splash_callback 0x002f2c34 : { *ai-startup-character.o(.text._Z23BloodSplashAnimCallbackPN3irr5scene19ITimelineControllerEPv) }
    .character_show_blood_splash 0x002f30d4 : { *ai-startup-character.o(.text._ZN9Character15showBloodSplashEN3irr4core8vector3dIfEES3_) }
    .character_blood_splash_pool 0x004b53ac : { *ai-startup-character.o(.data._ZN9Character13s_bloodsplashE) }
    .character_blood_splash_node 0x004b7dd4 (NOLOAD) : { *ai-startup-character.o(.bss._ZN9Character13m_bloodSplashE) }
    .character_remove_blood_puddle 0x002f172c : { *ai-startup-character.o(.text._ZN9Character17removeBloodPuddleEv) }
    .character_show_blood_puddle 0x002f2cd8 : { *ai-startup-character.o(.text._ZN9Character15showBloodPuddleEN3irr4core8vector3dIfEE) }
    .character_blood_puddle_pool 0x004b53a8 : { *ai-startup-character.o(.data._ZN9Character13s_bloodpuddleE) }
    .character_blood_enabled 0x004b53b0 : { *ai-startup-character.o(.data._ZN9Character11b_isBloodOnE) }
    .character_is_player 0x002f1998 : { *ai-startup-character.o(.text._ZNK9Character8isPlayerEv) }
    .character_combat_to_idle 0x002f27c8 : { *ai-startup-character.o(.text._ZN9Character18goFromCombatToIdleEv) }
    .character_combat_to_idle_table 0x0041bd3c : { *ai-startup-character.o(.rodata._ZN9Character18goFromCombatToIdleEv) }
    .character_switch_weapon 0x002f28ec : { *ai-startup-character.o(.text._ZN9Character12switchWeaponEv) }
    .character_reload_weapon_animation 0x002f1f9c : { *ai-startup-character.o(.text._ZN9Character24setReloadWeaponAnimationEi) }
    .character_reload_weapon_table 0x0041bcd0 : { *ai-startup-character.o(.rodata._ZN9Character24setReloadWeaponAnimationEi) }
    .character_check_weapon_reload 0x002f207c : { *ai-startup-character.o(.text._ZN9Character20checkForWeaponReloadEv) }
    .character_reset_collisions 0x002f3090 : { *ai-startup-character.o(.text._ZN9Character15resetCollisionsEv) }
    .character_update_physic 0x002f14b4 : { *ai-startup-character.o(.text._ZN9Character12updatePhysicEi) }
    .character_update_scene_node 0x002f14b8 : { *ai-startup-character.o(.text._ZN9Character15updateSceneNodeEi) }
    .character_walk_to_target 0x002f16c4 : { *ai-startup-character.o(.text._ZN9Character12walkToTargetEv) }
    .character_stop 0x002f1d3c : { *ai-startup-character.o(.text._ZN9Character4StopEv) }
    .character_on_rocket_launched 0x002f1d78 : { *ai-startup-character.o(.text._ZN9Character16onRocketLaunchedEv) }
    .character_set_turn_direction 0x002f2118 : { *ai-startup-character.o(.text._ZN9Character16setTurnDirectionEN3irr4core8vector3dIfEE) }
    .character_check_destination 0x002f2134 : { *ai-startup-character.o(.text._ZN9Character16CheckDestinationEv) }
    .character_switch_animation 0x002f6af0 : { *ai-startup-character.o(.text._ZN9Character15switchAnimationEv) }
    .character_timed_turn 0x002f22d4 : { *ai-startup-character.o(.text._ZN9Character10turnTowardEN3irr4core8vector3dIfEEf) }
    .character_target_in_range 0x002f3d40 : { *ai-startup-character.o(.text._ZN9Character15isTargetInRangeEff) }
    .character_turn_toward_object 0x002f3bd4 : { *ai-startup-character.o(.text._ZN9Character16turnTowardTargetEP11LevelObjectf) }
    .character_is_facing_target 0x002f3b08 : { *ai-startup-character.o(.text._ZN9Character14isFacingTargetEP11LevelObject) }
    .character_turn_to_target 0x002f3d18 : { *ai-startup-character.o(.text._ZN9Character16turnTowardTargetEf) }
    .character_run_to_location 0x002f3fa4 : { *ai-startup-character.o(.text._ZN9Character13runToLocationERKN3irr4core8vector3dIfEE) }
    .character_walk_to_location 0x002f400c : { *ai-startup-character.o(.text._ZN9Character14walkToLocationERKN3irr4core8vector3dIfEE) }
    .character_get_spawn_type 0x002f1448 : { *ai-startup-character.o(.text._ZN9Character12getSpawnTypeEv) }
    .character_set_spawn_type 0x002f1450 : { *ai-startup-character.o(.text._ZN9Character12setSpawnTypeEi) }
    .character_set_target 0x002f147c : { *ai-startup-character.o(.text._ZN9Character9SetTargetEP11LevelObject) }
    .character_get_skin_mesh 0x002f1484 : { *ai-startup-character.o(.text._ZN9Character11getSkinMeshEv) }
    .character_get_max_health 0x002f146c : { *ai-startup-character.o(.text._ZNK9Character12getMaxHealthEv) }
    .character_get_health 0x002f1474 : { *ai-startup-character.o(.text._ZNK9Character9getHealthEv) }
    .character_is_dying 0x002f15a0 : { *ai-startup-character.o(.text._ZN9Character7isDyingEv) }
    .character_is_dead 0x002f1f1c : { *ai-startup-character.o(.text._ZN9Character6isDeadEv) }
    .character_clean_timeline_controller 0x002f14c0 : { *ai-startup-character.o(.text._ZN9Character23cleanTimelineControllerEv) }
    .character_set_animation_by_name 0x002f14f8 : { *ai-startup-character.o(.text._ZN9Character12setAnimationEPKcibbb) }
    .character_set_next_animation_by_name 0x002f1f44 : { *ai-startup-character.o(.text._ZN9Character16setNextAnimationEPKcibbb) }
    .character_timeline_controller 0x004b7db4 (NOLOAD) : { *ai-startup-character.o(.bss._ZN9Character20s_timelineControllerE) }
    .character_is_animation_last_frame 0x002f15bc : { *ai-startup-character.o(.text._ZNK9Character20isAnimationLastFrameEf) }
    .character_set_next_animation 0x002f1f34 : { *ai-startup-character.o(.text._ZN9Character16setNextAnimationEiibbb) }
    .character_can_interrupt_animation 0x002f148c : { *ai-startup-character.o(.text._ZN9Character25canAnimationBeInterruptedEi) }
    .character_set_animation_speed_multiplier 0x002f14f0 : { *ai-startup-character.o(.text._ZN9Character27setAnimationSpeedMultiplierEi) }
    .character_reset_animation 0x002f1560 : { *ai-startup-character.o(.text._ZN9Character14resetAnimationEv) }
    .character_is_in_flinch_animation 0x002f165c : { *ai-startup-character.o(.text._ZN9Character19isInFlinchAnimationEv) }
    .character_is_in_hit_by_car_animation 0x002f1674 : { *ai-startup-character.o(.text._ZN9Character21isInHitByCarAnimationEv) }
    .character_is_current_animation 0x002f156c : { *ai-startup-character.o(.text._ZN9Character18isCurrentAnimationEi) }
    .character_is_down 0x002f1580 : { *ai-startup-character.o(.text._ZN9Character6isDownEv) }
    .character_go_idle 0x002f1cfc : { *ai-startup-character.o(.text._ZN9Character8goToIdleEv) }
    .character_get_vehicle 0x002f1458 : { *ai-startup-character.o(.text._ZNK9Character10getVehicleEv) }
    .character_get_lock_target 0x002f1460 : { *ai-startup-character.o(.text._ZNK9Character13getLockTargetEv) }
    .character_get_camera_offset 0x002f1468 : { *ai-startup-character.o(.text._ZNK9Character15getCameraOffsetEv) }
    .character_set_vehicle 0x002f14ac : { *ai-startup-character.o(.text._ZN9Character10setVehicleEP7Vehicle) }
    .character_set_lock_target 0x002f1630 : { *ai-startup-character.o(.text._ZN9Character13setLockTargetEPS_) }
    .character_set_camera_offset 0x002f1770 : { *ai-startup-character.o(.text._ZN9Character15setCameraOffsetERKN3irr4core8vector3dIfEE) }
    .character_set_destination 0x002f2104 : { *ai-startup-character.o(.text._ZN9Character14setDestinationERKN3irr4core8vector3dIfEEi) }
}
