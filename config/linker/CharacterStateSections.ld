SECTIONS
{
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
