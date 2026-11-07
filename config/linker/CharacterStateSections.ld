__aeabi_fadd = 0x001c4154;
__aeabi_f2iz = 0x001c44cc;
__aeabi_idivmod = 0x001c4934;
__aeabi_i2f = 0x001c41e4;
SECTIONS
{
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
