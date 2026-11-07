OUTPUT_FORMAT("elf32-littlearm")
OUTPUT_ARCH(arm)
INCLUDE build/matches/vehicle-cleanup/retail-symbols.ld
_ZdlPv = 0x001c42b0;
SECTIONS
{
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
