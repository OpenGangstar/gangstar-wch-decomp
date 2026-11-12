OUTPUT_FORMAT("elf32-littlearm")
OUTPUT_ARCH(arm)
INCLUDE build/matches/vehicle-cleanup/retail-symbols.ld
_ZdlPv = 0x001c42b0;
strcmp = 0x001c4658;
puts = 0x001c41b4;
SECTIONS
{
    .vehicle_stop 0x00309eac : { *(.text._ZN7Vehicle4StopEv) }
    .vehicle_immobilize 0x0030a230 : { *(.text._ZN7Vehicle10immobilizeEv) }
    .vehicle_accelerate 0x00307d30 : { *(.text._ZN7Vehicle10accelerateEf) }
    .vehicle_brake 0x00307d48 : { *(.text._ZN7Vehicle5brakeEf) }
    .vehicle_turn 0x00307d60 : { *(.text._ZN7Vehicle4turnEbf) }
    .vehicle_set_driver 0x00308e48 : { *(.text._ZN7Vehicle9setDriverEP9Character) }
    .vehicle_reset_driver 0x0030a1fc : { *(.text._ZN7Vehicle11resetDriverEv) }
    .vehicle_reset_collisions 0x0030a5c4 : { *(.text._ZN7Vehicle15resetCollisionsEv) }
    .vehicle_photographed 0x00307b20 : { *(.text._ZN7Vehicle12photographedEv) }
    .vehicle_clear_photographed 0x00307b30 : { *(.text._ZN7Vehicle17clearPhotographedEv) }
    .vehicle_is_photographed 0x00307b44 : { *(.text._ZNK7Vehicle14isPhotographedEv) }
    .vehicle_show_wheels 0x00309078 : { *(.text._ZN7Vehicle10showWheelsEv) }
    .vehicle_hide_wheels 0x003090b0 : { *(.text._ZN7Vehicle10hideWheelsEv) }
    .vehicle_no_animators_message 0x0041f4b0 : { *(.rodata.*noAnimatorsMessage*) }
    .vehicle_no_timeline_message 0x0041f4d4 : { *(.rodata.*noTimelineMessage*) }
    .vehicle_no_callback_timeline_message 0x0041f4f0 : { *(.rodata.*noCallbackTimelineMessage*) }
    .vehicle_close_left_door_clip 0x0041f514 : { *(.rodata.*closeLeftDoorClip*) }
    .vehicle_close_right_door_clip 0x0041f528 : { *(.rodata.*closeRightDoorClip*) }
    .vehicle_exit_low_left_clip 0x0041f540 : { *(.rodata.*exitLowLeftClip*) }
    .vehicle_exit_low_right_clip 0x0041f558 : { *(.rodata.*exitLowRightClip*) }
    .vehicle_exit_high_left_clip 0x0041f570 : { *(.rodata.*exitHighLeftClip*) }
    .vehicle_exit_high_right_clip 0x0041f588 : { *(.rodata.*exitHighRightClip*) }
    .vehicle_closed_idle_clip 0x0041f5a0 : { *(.rodata.*closedIdleClip*) }
    .vehicle_opened_idle_clip 0x0041f5b0 : { *(.rodata.*openedIdleClip*) }
    .vehicle_animation_transition 0x003098ec : { *(.text._Z19aTransitionCallbackPN3irr5scene19ITimelineControllerEPv) }
    .vehicle_callback 0x003099a0 : { *(.text._Z15VehicleCallBackPN3irr5scene19ITimelineControllerEPv) }
    .vehicle_start_anim 0x003095d4 : { *(.text._ZN7Vehicle9startAnimEPN3irr5scene18ISceneNodeAnimatorEb) }
    .vehicle_is_current_anim 0x003097c4 : { *(.text._ZN7Vehicle13isCurrentAnimEPKc) }
    .vehicle_get_timeline 0x003097f4 : { *(.text._ZN7Vehicle11getTimelineEPN3irr5scene10ISceneNodeE) }
    .vehicle_play_current_anim 0x00309828 : { *(.text._ZN7Vehicle20playCurAnimFromStartEv) }
    .vehicle_set_transition_callback 0x00309854 : { *(.text._ZN7Vehicle21setTransitionCallbackEPN3irr5scene10ISceneNodeE) }
    .vehicle_set_anim 0x00309890 : { *(.text._ZN7Vehicle7setAnimEPKcbf) }
    .vehicle_low_enter_clip 0x0041def8 : { *(.rodata.*lowVehicleEnterClip*) }
    .vehicle_is_low_vehicle 0x00308ef0 : { *(.text._ZN7Vehicle12isLowVehicleEv) }
    .vehicle_get_seated_animation 0x00308f1c : { *(.text._ZN7Vehicle18getSeatedAnimationEv) }
    .vehicle_get_right_thrown_animation 0x00308f34 : { *(.text._ZN7Vehicle23getRightThrownAnimationEv) }
    .vehicle_get_left_thrown_animation 0x00308f4c : { *(.text._ZN7Vehicle22getLeftThrownAnimationEv) }
    .vehicle_get_right_throw_animation 0x00308f64 : { *(.text._ZN7Vehicle22getRightThrowAnimationEv) }
    .vehicle_get_left_throw_animation 0x00308f7c : { *(.text._ZN7Vehicle21getLeftThrowAnimationEv) }
    .vehicle_get_right_eject_animation 0x00308f94 : { *(.text._ZN7Vehicle22getRightEjectAnimationEv) }
    .vehicle_get_left_eject_animation 0x00308fa4 : { *(.text._ZN7Vehicle21getLeftEjectAnimationEv) }
    .vehicle_get_right_exit_animation 0x00308fb4 : { *(.text._ZN7Vehicle21getRightExitAnimationEv) }
    .vehicle_get_left_exit_animation 0x00308fcc : { *(.text._ZN7Vehicle20getLeftExitAnimationEv) }
    .vehicle_get_right_close_door_from_inside_animation 0x00308fe4 : { *(.text._ZN7Vehicle36getRightCloseDoorFromInsideAnimationEv) }
    .vehicle_get_left_close_door_from_inside_animation 0x00308ffc : { *(.text._ZN7Vehicle35getLeftCloseDoorFromInsideAnimationEv) }
    .vehicle_get_right_enter_animation 0x00309014 : { *(.text._ZN7Vehicle22getRightEnterAnimationEv) }
    .vehicle_get_left_enter_animation 0x0030902c : { *(.text._ZN7Vehicle21getLeftEnterAnimationEv) }
    .vehicle_set_door_anim 0x0030a52c : { *(.text._ZN7Vehicle11setDoorAnimEPKcb) }
    .vehicle_close_door 0x0030a58c : { *(.text._ZN7Vehicle9closeDoorEb) }
    .vehicle_skinning 0x00309170 : { *(.text._ZN7Vehicle14enableSkinningEb) }
    .vehicle_backface_culling 0x00308044 : { *(.text._ZN7Vehicle21enableBackfaceCullingEb) }
    .vehicle_on_door_closed 0x003138d4 : { *(.text._ZN7Vehicle12onDoorClosedEv) }
    .vehicle_open_door_inside 0x003139f8 : { *(.text._ZN7Vehicle18openDoorFromInsideEb) }
    .vehicle_open_door 0x00313a7c : { *(.text._ZN7Vehicle8openDoorEb) }
    .vehicle_open_door_clip 0x0041dee8 : { *(.rodata.*openDoorClip*) }
    .vehicle_door_callback 0x00313954 : { *(.text._Z22doorTransitionCallbackPN3irr5scene19ITimelineControllerEPv) }
    .vehicle_close_door_clip 0x0041f704 : { *(.rodata.*closeDoorClip*) }
    .vehicle_exit_car_clip 0x0041f79c : { *(.rodata.*exitCarClip*) }
    .vehicle_left_door 0x00307e40 : { *(.text._ZNK7Vehicle10isLeftDoorEPKN3irr5scene10ISceneNodeE) }
    .vehicle_door_opened 0x00307e58 : { *(.text._ZNK7Vehicle12isDoorOpenedEb) }
    .vehicle_door_closed 0x00307e78 : { *(.text._ZNK7Vehicle12isDoorClosedEb) }
    .vehicle_door_anim 0x00307e94 : { *(.text._ZNK7Vehicle10isDoorAnimEPKcb) }
    .vehicle_shift_weight 0x00307e10 : { *(.text._ZN7Vehicle12_shiftWeightERN3irr4core8vector3dIfEEf) }
    .vehicle_enter_anim 0x00307e14 : { *(.text._ZNK7Vehicle12getEnterAnimEv) }
    .vehicle_exit_anim 0x00307e1c : { *(.text._ZNK7Vehicle11getExitAnimEv) }
    .vehicle_close_door_anim 0x00307e24 : { *(.text._ZNK7Vehicle16getCloseDoorAnimEv) }
    .vehicle_interior 0x00307e2c : { *(.text._ZN7Vehicle14toggleInteriorEb) }
    .vehicle_notify_targeted 0x00307f1c : { *(.text._ZN7Vehicle15_notifyTargetedEbP9Character) }
    .vehicle_add_turbo 0x00307f90 : { *(.text._ZN7Vehicle14AddTurboSoundsEv) }
    .vehicle_init_4cyl 0x00307f94 : { *(.text._ZN7Vehicle19Init4CylTurboSoundsEv) }
    .vehicle_init_superbike 0x00307f98 : { *(.text._ZN7Vehicle19InitSuperbikeSoundsEv) }
    .vehicle_init_v12 0x00307f9c : { *(.text._ZN7Vehicle24InitV12LamborghiniSoundsEv) }
    .vehicle_set_stolen 0x00307fa0 : { *(.text._ZN7Vehicle16setHasBeenStolenEv) }
    .vehicle_get_stolen 0x00307fac : { *(.text._ZN7Vehicle16getHasBeenStolenEv) }
    .vehicle_unique_id 0x00307fb4 : { *(.text._ZN7Vehicle11getUniqueIdEv) }
    .vehicle_get_path 0x00307f28 : { *(.text._ZNK7Vehicle15getPathToFollowEv) }
    .vehicle_set_waypoint 0x00307f30 : { *(.text._ZN7Vehicle18setCurrentWaypointEi) }
    .vehicle_get_waypoint 0x00307f38 : { *(.text._ZNK7Vehicle18getCurrentWaypointEv) }
    .vehicle_loop_path 0x00307f40 : { *(.text._ZN7Vehicle16loopPathToFollowEb) }
    .vehicle_set_path 0x00307f68 : { *(.text._ZN7Vehicle15setPathToFollowEPK4Path) }
    .vehicle_is_looping 0x00307f84 : { *(.text._ZNK7Vehicle23isLoopingOnPathToFollowEv) }
    .vehicle_cleanup_0 0x00308014 : { *vehicle-cleanup.o(.text.__tcf_4) }
    .vehicle_cleanup_1 0x00308210 : { *vehicle-cleanup.o(.text.__tcf_3) }
    .vehicle_cleanup_2 0x0030b5dc : { *vehicle-cleanup.o(.text.__tcf_1) }
    .vehicle_cleanup_3 0x0030b624 : { *vehicle-cleanup.o(.text.__tcf_2) }
    .vehicle_empty_string 0x004b8724 (NOLOAD) : { *vehicle-cleanup.o(.bss._ZN3irr5scene6quake315irrEmptyStringcE) }
    .got 0x004b0048 : { *(.got.plt) . = 0x360; *(.got) }
    .verification 0x00600000 : { *retail-got.o(.text) }
}
ASSERT(SIZEOF(.vehicle_empty_string) == 32, "Vehicle empty string extent");
