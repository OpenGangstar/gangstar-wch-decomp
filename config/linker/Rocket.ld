OUTPUT_FORMAT("elf32-littlearm")
OUTPUT_ARCH(arm)
INCLUDE build/matches/rocket/retail-symbols.ld
_ZdlPv = 0x001c42b0;
_ZdaPv = 0x001c461c;
_Znwj = 0x001c4814;
__aeabi_fmul = 0x001c4724;
__aeabi_fsub = 0x001c4328;
__aeabi_fdiv = 0x001c4520;
__aeabi_fadd = 0x001c4154;
__aeabi_fcmple = 0x001c43ac;
__aeabi_i2f = 0x001c41e4;
__aeabi_atexit = 0x001c494c;
_ZN25retail_rocket_transitions16civPassive_transE = 0x004277cc;
_ZN25retail_rocket_transitions17scriptedNpc_transE = 0x004278f8;
_ZN25retail_rocket_transitions19civAggressive_transE = 0x00427928;
_ZN25retail_rocket_transitions16gangMember_transE = 0x00427a0c;
_ZN25retail_rocket_transitions9cop_transE = 0x00427a18;
_ZN25retail_rocket_transitions10swat_transE = 0x00427b50;
_ZN25retail_rocket_transitions17civ_vehicle_transE = 0x00427b5c;
_ZN25retail_rocket_transitions17cop_vehicle_transE = 0x00427bec;
_ZN25retail_rocket_transitions11guard_transE = 0x00427ca0;
_ZN25retail_rocket_transitions22scripted_vehicle_transE = 0x00427d48;
__aeabi_fcmpeq = 0x001c470c;
SECTIONS
{
    .rocket_launch 0x00330014 : { *rocket.o(.text._ZN6Rocket6launchEN3irr4core8vector3dIfEE) }
    .rocket_polygon_d1 0x002df3f4 : { *rocket.o(.gnu.linkonce.t._ZN12b2PolygonDefD1Ev) }
    .rocket_polygon_d0 0x002df628 : { *rocket.o(.gnu.linkonce.t._ZN12b2PolygonDefD0Ev) }
    .rocket_polygon_table 0x004a8ac8 : { *rocket.o(.gnu.linkonce.d.rel.ro._ZTV12b2PolygonDef) }
    .rocket_shape_d1 0x002db49c : { *rocket.o(.text._ZN10b2ShapeDefD1Ev .gnu.linkonce.t._ZN10b2ShapeDefD1Ev) }
    .rocket_shape_d0 0x002db47c : { *rocket.o(.text._ZN10b2ShapeDefD0Ev .gnu.linkonce.t._ZN10b2ShapeDefD0Ev) }
    .rocket_shape_table 0x004a8ad8 : { *rocket.o(.gnu.linkonce.d.rel.ro._ZTV10b2ShapeDef) }
    .rocket_circle_table 0x004aa168 : { *rocket.o(.gnu.linkonce.d.rel.ro._ZTV11b2CircleDef) }
    .rocket_circle_d1 0x002f4440 : { *rocket.o(.text._ZN11b2CircleDefD1Ev .gnu.linkonce.t._ZN11b2CircleDefD1Ev) }
    .rocket_circle_d0 0x002f462c : { *rocket.o(.text._ZN11b2CircleDefD0Ev .gnu.linkonce.t._ZN11b2CircleDefD0Ev) }
    .rocket_debug 0x0032fac0 : { *rocket.o(.text._ZN6Rocket5debugEPN3irr5video12IVideoDriverE) }
    .rocket_constructor 0x0032fd90 : { *rocket.o(.text._ZN6RocketC1Ei) }
    .rocket_load 0x0032fb18 : { *rocket.o(.text._ZN6Rocket4LoadERKN7Structs6RocketE) }
    .rocket_attach_uid 0x004277b4 : { *rocket.o(.rodata.rocket_attach_uid) }
    .rocket_update 0x0032fde8 : { *rocket.o(.text._ZN6Rocket6UpdateEi) }
    .rocket_explode 0x0032fbd4 : { *rocket.o(.text._ZN6Rocket7explodeEb) }
    .rocket_destructor 0x0032fd14 : { *rocket.o(.text._ZN6RocketD1Ev) }
    .rocket_delete 0x0032fc94 : { *rocket.o(.text._ZN6RocketD0Ev) }
    .rocket_vtable 0x004acaf8 : { *rocket.o(.data.rel.ro._ZTV6Rocket) }
    .level_base_type 0x002f74d0 : { *rocket.o(.text._ZN11LevelObject12getSpawnTypeEv .gnu.linkonce.t._ZN11LevelObject12getSpawnTypeEv) }
    .rocket_string_cleanup 0x0032fac4 : { *rocket.o(.text.__tcf_3) }
    .rocket_factory_cleanup 0x0032faf4 : { *rocket.o(.text.__tcf_1) }
    .rocket_startup 0x0032febc : { *rocket.o(.text._Z41__static_initialization_and_destruction_0ii) }
    .rocket_startup_wrapper 0x00330000 : { *rocket.o(.text._GLOBAL__I__ZN6RocketC2Ei) }
    .rocket_empty_string 0x0044d91c : { *rocket.o(.rodata.str1.4) }
    .rocket_startup_string 0x004b9b2c (NOLOAD) : { *rocket.o(.bss._ZN3irr5scene6quake315irrEmptyStringcE) }
    .rocket_startup_half 0x004b9b4c (NOLOAD) : { *rocket.o(.bss._ZN3irr2ps5vHalfE) }
    .rocket_startup_record_0 0x004b9b58 (NOLOAD) : { *rocket.o(.bss._ZN8gameloft2ai11civ_passiveE) }
    .rocket_startup_record_1 0x004b9b60 (NOLOAD) : { *rocket.o(.bss._ZN8gameloft2ai12npc_scriptedE) }
    .rocket_startup_record_2 0x004b9b68 (NOLOAD) : { *rocket.o(.bss._ZN8gameloft2ai13civ_agressiveE) }
    .rocket_startup_record_3 0x004b9b70 (NOLOAD) : { *rocket.o(.bss._ZN8gameloft2ai11gang_memberE) }
    .rocket_startup_record_4 0x004b9b78 (NOLOAD) : { *rocket.o(.bss._ZN8gameloft2ai3copE) }
    .rocket_startup_record_5 0x004b9b80 (NOLOAD) : { *rocket.o(.bss._ZN8gameloft2ai4swatE) }
    .rocket_startup_record_6 0x004b9b88 (NOLOAD) : { *rocket.o(.bss._ZN8gameloft2ai11civ_vehicleE) }
    .rocket_startup_record_7 0x004b9b90 (NOLOAD) : { *rocket.o(.bss._ZN8gameloft2ai11cop_vehicleE) }
    .rocket_startup_record_8 0x004b9b98 (NOLOAD) : { *rocket.o(.bss._ZN8gameloft2ai5guardE) }
    .rocket_startup_record_9 0x004b9ba0 (NOLOAD) : { *rocket.o(.bss._ZN8gameloft2ai16scripted_vehicleE) }
    .got 0x004b0048 : { *(.got.plt) . = 0x360; *(.got) }
    .verification 0x00600000 : { *retail-got.o(.text) }
}
ASSERT(SIZEOF(.rocket_startup_string) == 32, "Rocket startup string extent");
ASSERT(SIZEOF(.rocket_startup_half) == 12, "Rocket startup half extent");
ASSERT(SIZEOF(.rocket_startup_record_0) == 8, "Rocket startup record_0 extent");
ASSERT(SIZEOF(.rocket_startup_record_1) == 8, "Rocket startup record_1 extent");
ASSERT(SIZEOF(.rocket_startup_record_2) == 8, "Rocket startup record_2 extent");
ASSERT(SIZEOF(.rocket_startup_record_3) == 8, "Rocket startup record_3 extent");
ASSERT(SIZEOF(.rocket_startup_record_4) == 8, "Rocket startup record_4 extent");
ASSERT(SIZEOF(.rocket_startup_record_5) == 8, "Rocket startup record_5 extent");
ASSERT(SIZEOF(.rocket_startup_record_6) == 8, "Rocket startup record_6 extent");
ASSERT(SIZEOF(.rocket_startup_record_7) == 8, "Rocket startup record_7 extent");
ASSERT(SIZEOF(.rocket_startup_record_8) == 8, "Rocket startup record_8 extent");
ASSERT(SIZEOF(.rocket_startup_record_9) == 8, "Rocket startup record_9 extent");
ASSERT(SIZEOF(.rocket_launch) == 744, "Native Rocket launch extent");
