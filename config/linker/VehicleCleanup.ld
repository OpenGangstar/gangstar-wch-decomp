OUTPUT_FORMAT("elf32-littlearm")
OUTPUT_ARCH(arm)
INCLUDE build/matches/vehicle-cleanup/retail-symbols.ld
_ZdlPv = 0x001c42b0;
SECTIONS
{
    .vehicle_set_door_anim 0x0030a52c : { *(.text._ZN7Vehicle11setDoorAnimEPKcb) }
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
