/* Retain the verified navigation helper in every dependent image. */
PROVIDE(__aeabi_fcmpge = 0x001c4364);
SECTIONS
{
 .level_object_can_go_point 0x318be4 : { *level-object.o(.text._ZN11LevelObject12canGoToPointERKN3irr4core8vector3dIfEE) }
}
