/* Retain the verified navigation helper in every dependent image. */
PROVIDE(__aeabi_fcmpge = 0x001c4364);
SECTIONS
{
    .level_can_go_to_point 0x00317fb4 : { *level-object.o(.text._ZN11LevelObject12canGoToPointERKN3irr4core8vector3dIfEERS3_S6_) }
    .level_cast_ray 0x003179d4 : { *level-object.o(.text._ZN11LevelObject7CastRayERKN3irr4core8vector3dIfEES5_RS3_S6_RPS_b) }
 .level_object_can_go_point 0x318be4 : { *level-object.o(.text._ZN11LevelObject12canGoToPointERKN3irr4core8vector3dIfEE) }
}
