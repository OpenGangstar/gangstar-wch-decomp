PROVIDE(memset = 0x001c45d4);
PROVIDE(__aeabi_dcmplt = 0x001c4244);
PROVIDE(__aeabi_ui2d = 0x1c4208);
PROVIDE(__aeabi_dmul = 0x1c4298);
PROVIDE(__aeabi_d2f = 0x1c4310);
PROVIDE(__aeabi_f2d = 0x1c48f8);
PROVIDE(__aeabi_fcmple = 0x001c43ac);
_ZdaPv = 0x001c461c;
acosf = 0x1c4694;
PROVIDE(sqrtf = 0x001c4184);
OUTPUT_FORMAT("elf32-littlearm")
OUTPUT_ARCH(arm)
INCLUDE build/matches/vehicle-cleanup/retail-symbols.ld
__cxa_guard_acquire = 0x001c4958;
__cxa_guard_release = 0x001c46c4;
__aeabi_atexit = 0x001c494c;
lrand48 = 0x001c4664;
__aeabi_idivmod = 0x001c4934;
memcpy = 0x001c4190;
_Znaj = 0x001c3ff8;
_Znwj = 0x001c4814;
atoi = 0x001c4880;
__stack_chk_fail = 0x001c42e0;
_ZN21GameFactoryProperties9billboardE = 0x004144b8;
_ZN8gameloft7vehicle13gear_profiles8profilesE = 0x004b8810;
sqrt = 0x001c401c;
__aeabi_d2f = 0x001c4310;
__aeabi_fcmpgt = 0x001c419c;
__aeabi_fcmpeq = 0x001c470c;
_ZdlPv = 0x001c42b0;
strcmp = 0x001c4658;
puts = 0x001c41b4;
__aeabi_fcmpge = 0x001c4364;
__aeabi_fcmplt = 0x001c479c;
__aeabi_fdiv = 0x001c4520;
__aeabi_ui2f = 0x001c4574;
__aeabi_i2f = 0x001c41e4;
__aeabi_f2iz = 0x001c44cc;
__aeabi_f2d = 0x001c48f8;
__aeabi_fmul = 0x001c4724;
__aeabi_fadd = 0x001c4154;
__aeabi_fsub = 0x001c4328;
__cxa_pure_virtual = 0;
__cxa_pure_virtual = 0;
SECTIONS
{
    .vehicle_is_door_clear 0x0030a730 : { *vehicle-cleanup.o(.text._ZNK7Vehicle11isDoorClearEbP6b2Body) }
    .vehicle_physic_info_ctor 0x00319dd0 : { *vehicle-cleanup.o(.text._ZN10PhysicInfoC1Ev .text._ZN10PhysicInfoC2Ev .gnu.linkonce.t._ZN10PhysicInfoC1Ev .gnu.linkonce.t._ZN10PhysicInfoC2Ev) }
    ASSERT(SIZEOF(.vehicle_physic_info_ctor) == 96, "PhysicInfo native96 extent")
    .vehicle_process_ai_flags 0x00312080 : { *vehicle-cleanup.o(.text._ZN7Vehicle15_processAIFlagsEv) }
    .vehicle_update 0x00313b00 : { *vehicle-cleanup.o(.text._ZN7Vehicle6UpdateEi) }
    .vehicle_load 0x0030ff40 : { *vehicle-cleanup.o(.text._ZN7Vehicle4LoadERKN7Structs3CarE) }
    .vehicle_load_explosion_asset 0x0041f714 : { *vehicle-cleanup.o(.rodata.*vehicleLoadExplosionAssetE) }
    .vehicle_setup_scene_node 0x00309a4c : { *vehicle-cleanup.o(.text._ZN7Vehicle14setupSceneNodeEiPN3irr5scene10ISceneNodeEiPPv) }
    .vehicle_play_drive_sfx 0x00312d18 : { *vehicle-cleanup.o(.text._ZN7Vehicle12playDriveSfxEj) }
    .vehicle_drop_scene_node 0x00309f0c : { *vehicle-cleanup.o(.text._ZN7Vehicle13dropSceneNodeEv) }
    .vehicle_on_despawn 0x00310e74 : { *vehicle-cleanup.o(.text._ZN7Vehicle9OnDespawnEv) }
    ASSERT(SIZEOF(.vehicle_on_despawn) == 308, "Native Vehicle OnDespawn extent")
    .vehicle_disable 0x00310fa8 : { *vehicle-cleanup.o(.text._ZN7Vehicle7disableEv) }
    ASSERT(SIZEOF(.vehicle_disable) == 416, "Native Vehicle disable extent")
 .vehicle_d1 0x00311498 : { *vehicle-cleanup.o(.text._ZN7VehicleD1Ev) }
 ASSERT(SIZEOF(.vehicle_d1) == 580, "Vehicle D1 exact native input")
 ASSERT(ADDR(.vehicle_d1) + SIZEOF(.vehicle_d1) == 0x003116dc, "Vehicle D1 native end")
 .vehicle_d0 0x00311250 : { *vehicle-cleanup.o(.text._ZN7VehicleD0Ev) }
 ASSERT(SIZEOF(.vehicle_d0) == 584, "Vehicle D0 exact native input")
 ASSERT(ADDR(.vehicle_d0) + SIZEOF(.vehicle_d0) == 0x00311498, "Vehicle D0 native end")
 .vehicle_vtable 0x004ab1f8 : { *vehicle-cleanup.o(.data.rel.ro._ZTV7Vehicle) }
 ASSERT(SIZEOF(.vehicle_vtable) == 192, "Vehicle table complete input")
 ASSERT(ADDR(.vehicle_vtable) + SIZEOF(.vehicle_vtable) == 0x004ab2b8, "Vehicle table native end")

 .vehicle_explode 0x003130a0 : { *vehicle-cleanup.o(.text._ZN7Vehicle7explodeEv) }
 ASSERT(SIZEOF(.vehicle_explode) == 740, "Vehicle explode exact native extent")

 .vehicle_collision 0x313384 : { *vehicle-cleanup.o(.text._ZN7Vehicle9collisionEN3irr4core8vector3dIfEEi) }
 ASSERT(SIZEOF(.vehicle_collision) == 1360, "Vehicle collision native extent")

 .vehicle_step_physic 0x3116dc : { *(.text._ZN7Vehicle10stepPhysicEv) }
 .ctor_family_8 0x30a954 : { *(.text._ZN7VehicleC1Ei) }
 .ctor_table_8 0x4ab050 : { *(.data.rel.ro._ZTV13IMapTrackable .gnu.linkonce.d.rel.ro._ZTV13IMapTrackable .rodata._ZTV13IMapTrackable) }

 .skin_family_0 0x21a958 : { *(.gnu.linkonce.t._ZN3irr2io26IAttributeExchangingObjectD2Ev) }
 .skin_family_1 0x21a91c : { *(.gnu.linkonce.t._ZN3irr2io26IAttributeExchangingObjectD1Ev) }
 .skin_family_2 0x21a8d4 : { *(.gnu.linkonce.t._ZN3irr2io26IAttributeExchangingObjectD0Ev) }
 .skin_family_3 0x2a5080 : { *(.gnu.linkonce.t._ZN3irr7collada21CSkinnedMeshSceneNodeD2Ev) }
 .skin_family_4 0x2a4ff0 : { *(.gnu.linkonce.t._ZN3irr7collada21CSkinnedMeshSceneNodeD1Ev) }
 .skin_family_5 0x2a51d4 : { *(.gnu.linkonce.t._ZN3irr7collada21CSkinnedMeshSceneNodeD0Ev) }
 .skin_family_6 0x311f8c : { *(.gnu.linkonce.t._ZN26CustomSkinnedMeshSceneNodeD1Ev) }
 .skin_family_7 0x311ef0 : { *(.gnu.linkonce.t._ZN26CustomSkinnedMeshSceneNodeD0Ev) }
 .skin_family_8 0x257f78 : { *(.gnu.linkonce.t._ZN3irr5scene14IMeshSceneNodeD1Ev) }
 .skin_family_9 0x257ee4 : { *(.gnu.linkonce.t._ZN3irr5scene14IMeshSceneNodeD0Ev) }
 .skin_table_1 0x4ab390 : { *(.data.rel.ro._ZTV26CustomSkinnedMeshSceneNode .gnu.linkonce.d.rel.ro._ZTV26CustomSkinnedMeshSceneNode .rodata._ZTV26CustomSkinnedMeshSceneNode) }
 .skin_table_2 0x4ab348 : { *(.data.rel.ro._ZTT26CustomSkinnedMeshSceneNode .gnu.linkonce.d.rel.ro._ZTT26CustomSkinnedMeshSceneNode .rodata._ZTT26CustomSkinnedMeshSceneNode) }
 .skin_table_11 0x4ab4e8 : { *(.data.rel.ro._ZTC26CustomSkinnedMeshSceneNode0_N3irr7collada21CSkinnedMeshSceneNodeE .gnu.linkonce.d.rel.ro._ZTC26CustomSkinnedMeshSceneNode0_N3irr7collada21CSkinnedMeshSceneNodeE .rodata._ZTC26CustomSkinnedMeshSceneNode0_N3irr7collada21CSkinnedMeshSceneNodeE) }
 .skin_table_12 0x4ab640 : { *(.data.rel.ro._ZTC26CustomSkinnedMeshSceneNode0_N3irr5scene21CColladaMeshSceneNodeE .gnu.linkonce.d.rel.ro._ZTC26CustomSkinnedMeshSceneNode0_N3irr5scene21CColladaMeshSceneNodeE .rodata._ZTC26CustomSkinnedMeshSceneNode0_N3irr5scene21CColladaMeshSceneNodeE) }
 .skin_table_13 0x4ab798 : { *(.data.rel.ro._ZTC26CustomSkinnedMeshSceneNode0_N3irr5scene14IMeshSceneNodeE .gnu.linkonce.d.rel.ro._ZTC26CustomSkinnedMeshSceneNode0_N3irr5scene14IMeshSceneNodeE .rodata._ZTC26CustomSkinnedMeshSceneNode0_N3irr5scene14IMeshSceneNodeE) }
 .skin_table_14 0x4ab8e8 : { *(.data.rel.ro._ZTC26CustomSkinnedMeshSceneNode0_N3irr5scene10ISceneNodeE .gnu.linkonce.d.rel.ro._ZTC26CustomSkinnedMeshSceneNode0_N3irr5scene10ISceneNodeE .rodata._ZTC26CustomSkinnedMeshSceneNode0_N3irr5scene10ISceneNodeE) }
 .skin_table_15 0x4aba28 : { *(.data.rel.ro._ZTC26CustomSkinnedMeshSceneNode0_N3irr2io26IAttributeExchangingObjectE .gnu.linkonce.d.rel.ro._ZTC26CustomSkinnedMeshSceneNode0_N3irr2io26IAttributeExchangingObjectE .rodata._ZTC26CustomSkinnedMeshSceneNode0_N3irr2io26IAttributeExchangingObjectE) }
 .skin_table_16 0x48a050 : { *(.data.rel.ro._ZTVN3irr5scene14IMeshSceneNodeE .gnu.linkonce.d.rel.ro._ZTVN3irr5scene14IMeshSceneNodeE .rodata._ZTVN3irr5scene14IMeshSceneNodeE) }
 .skin_table_17 0x48a1a0 : { *(.data.rel.ro._ZTTN3irr5scene14IMeshSceneNodeE .gnu.linkonce.d.rel.ro._ZTTN3irr5scene14IMeshSceneNodeE .rodata._ZTTN3irr5scene14IMeshSceneNodeE) }
 .skin_table_18 0x48a1c0 : { *(.data.rel.ro._ZTCN3irr5scene14IMeshSceneNodeE0_NS0_10ISceneNodeE .gnu.linkonce.d.rel.ro._ZTCN3irr5scene14IMeshSceneNodeE0_NS0_10ISceneNodeE .rodata._ZTCN3irr5scene14IMeshSceneNodeE0_NS0_10ISceneNodeE) }
 .skin_table_19 0x48a300 : { *(.data.rel.ro._ZTCN3irr5scene14IMeshSceneNodeE0_NS_2io26IAttributeExchangingObjectE .gnu.linkonce.d.rel.ro._ZTCN3irr5scene14IMeshSceneNodeE0_NS_2io26IAttributeExchangingObjectE .rodata._ZTCN3irr5scene14IMeshSceneNodeE0_NS_2io26IAttributeExchangingObjectE) }

    .vehicle_startup_wrapper 0x0030b59c : { *vehicle-cleanup.o(.text._GLOBAL__I__ZN7Vehicle19s_smallImpactSoundsE) }
    .vehicle_grab_scene_node 0x00310498 : { *(.text._ZN7Vehicle13grabSceneNodeEiPPPv) }
    .vehicle_light00_asset 0x0041f72c : { *(.rodata.*vehicleLight00Asset*) }
    .vehicle_light01_asset 0x0041f740 : { *(.rodata.*vehicleLight01Asset*) }
    .vehicle_cop_lights_asset 0x0041f754 : { *(.rodata.*vehicleCopLightsAsset*) }
    .vehicle_light01_node 0x0041f764 : { *(.rodata.*vehicleLight01Node*) }
    .vehicle_light02_node 0x0041f778 : { *(.rodata.*vehicleLight02Node*) }
    .vehicle_cop_lights_node 0x0041f78c : { *(.rodata.*vehicleCopLightsNode*) }
    .vehicle_yaw 0x0030949c : { *(.text._ZN7Vehicle4_yawEf) }
    .vehicle_roll 0x00309504 : { *(.text._ZN7Vehicle5_rollEf) }
    .vehicle_pitch 0x0030956c : { *(.text._ZN7Vehicle6_pitchEf) }
    .vehicle_setYaw 0x0030a054 : { *(.text._ZN7Vehicle7_setYawEf) }
    .vehicle_setRoll 0x0030a0d0 : { *(.text._ZN7Vehicle8_setRollEf) }
    .vehicle_setPitch 0x0030a14c : { *(.text._ZN7Vehicle9_setPitchEf) }
    .vehicle_adjust_traction 0x003099dc : { *(.text._ZN7Vehicle15_adjustTractionEP6b2Bodyf) }
    .vehicle_remove_wheel_collisions 0x0030a604 : { *(.text._ZN7Vehicle21removeWheelCollisionsEv) }
    .vehicle_load_explosion 0x00309044 : { *(.text._ZN7Vehicle13loadExplosionEPKc) }
    .EvVehicleDeactivated_d0 0x00310d7c : { *(.gnu.linkonce.t._ZN20EvVehicleDeactivatedD0Ev) }
    .EvVehicleDeactivated_d1 0x00310da8 : { *(.gnu.linkonce.t._ZN20EvVehicleDeactivatedD1Ev) }
    .EvVehicleDeactivated_vtable 0x004ab2b8 : { *(.gnu.linkonce.d.rel.ro._ZTV20EvVehicleDeactivated) }
    .EvVehicleDestroyed_d0 0x00311200 : { *(.gnu.linkonce.t._ZN18EvVehicleDestroyedD0Ev) }
    .EvVehicleDestroyed_d1 0x0031122c : { *(.gnu.linkonce.t._ZN18EvVehicleDestroyedD1Ev) }
    .EvVehicleDestroyed_vtable 0x004ab2d0 : { *(.gnu.linkonce.d.rel.ro._ZTV18EvVehicleDestroyed) }
    .vehicle_base_event_id 0x002d3c34 : { *(.gnu.linkonce.t._ZNK6IEvent10getEventIDEv) }
    .vehicle_base_event_delete 0x002d4074 : { *(.gnu.linkonce.t._ZN6IEventD0Ev) }
    .vehicle_base_event_dtor 0x002d4094 : { *(.gnu.linkonce.t._ZN6IEventD1Ev) }
    .vehicle_base_event_vtable 0x004a6198 : { *(.gnu.linkonce.d.rel.ro._ZTV6IEvent) }
    .custom_skin_transformed_bounds 0x00307fc4 : { *(.text._ZNK26CustomSkinnedMeshSceneNode25getTransformedBoundingBoxEv) }
    .vehicle_play_siren 0x00312020 : { *(.text._ZN7Vehicle9playSirenEv) }
    .vehicle_tag_for_kill 0x0030a8f4 : { *(.text._ZN7Vehicle10tagForKillEb) }
    .vehicle_velocity_direction 0x00311cdc : { *(.text._ZN7Vehicle11getVelDirecEv) }
    .vehicle_shift_gears 0x00311da8 : { *(.text._ZN7Vehicle11_shiftGearsEj) }
    .vehicle_spawn 0x0030bbbc : { *(.text._ZN7Vehicle7OnSpawnEv) }
    .vehicle_init 0x0030fedc : { *(.text._ZN7Vehicle4initEv) }
    .vehicle_enable 0x0030bb64 : { *(.text._ZN7Vehicle6enableEv) }
    .vehicle_initialize_driver 0x0030a8bc : { *(.text._ZN7Vehicle16initializeDriverEv) }
    .custom_skin_bounds 0x00307b00 : { *(.text._ZNK26CustomSkinnedMeshSceneNode14getBoundingBoxEv) }
    .custom_skin_ctor 0x00309230 : { *(.text._ZN26CustomSkinnedMeshSceneNodeC1EPN3irr5scene12IColladaMeshEPNS0_7collada14IRootSceneNodeEPNS4_5SNodeEiRKNS0_4core8vector3dIfEERKNS9_10quaternionESD_) }
    .car_create_morph 0x003092b4 : { *(.text._ZN11CCarFactory11createMorphERKN3irr7collada16CColladaDatabaseEPNS1_11SControllerE) }
    .car_morph_d0 0x00311e40 : { *(.gnu.linkonce.t._ZN16CCarMorphingMeshD0Ev) }
    .car_morph_d1 0x00311e9c : { *(.gnu.linkonce.t._ZN16CCarMorphingMeshD1Ev) }
    .car_morph_vtt 0x004aba70 : { *(.data.rel.ro._ZTT16CCarMorphingMesh) }
    .car_morph_vtable 0x004aba90 : { *(.data.rel.ro._ZTV16CCarMorphingMesh) }
    .car_morph_base_vtable 0x004abaf0 : { *(.data.rel.ro._ZTC16CCarMorphingMesh0_N3irr7collada20CColladaMorphingMeshE) }
    .car_morph_collada_vtable 0x004abb50 : { *(.data.rel.ro._ZTC16CCarMorphingMesh0_N3irr5scene12IColladaMeshE) }
    .car_morph_mesh_vtable 0x004abbb0 : { *(.data.rel.ro._ZTC16CCarMorphingMesh0_N3irr5scene5IMeshE) }
    .car_morph_prepare 0x00309338 : { *(.text._ZN16CCarMorphingMesh27onPrepareBufferForRenderingEN3irr5scene12IColladaMesh21E_PREPARE_BUFFER_STEPEPNS0_5video12IVideoDriverEj) }
    .car_factory_create_skin 0x00309358 : { *(.text._ZN11CCarFactory14createSkinNodeERKN3irr7collada16CColladaDatabaseEPNS0_5scene12IColladaMeshEPNS1_14IRootSceneNodeEPv) }
    .car_factory_create_node 0x0030a6a0 : { *(.text._ZN11CCarFactory10createNodeERKN3irr7collada16CColladaDatabaseEPNS1_5SNodeE) }
    .car_factory_singleton 0x003081b4 : { *(.gnu.linkonce.t._ZN11CCarFactory11getInstanceEv) }
    .car_factory_guard 0x004b672c (NOLOAD) : { *(.gnu.linkonce.b._ZGVZN11CCarFactory11getInstanceEvE2cf) }
    .car_factory_instance 0x004b8880 (NOLOAD) : { *(.gnu.linkonce.b._ZZN11CCarFactory11getInstanceEvE2cf) }
    .car_factory_delete 0x0030b5b0 : { *(.gnu.linkonce.t._ZN11CCarFactoryD0Ev) }
    .car_factory_destructor 0x0030b600 : { *(.gnu.linkonce.t._ZN11CCarFactoryD1Ev) }
    .car_factory_vtable 0x004ab2e8 : { *(.gnu.linkonce.d.rel.ro._ZTV11CCarFactory .data.rel.ro._ZTV11CCarFactory) }
    .vehicle_notify_hit_despawn 0x0030a310 : { *(.text._ZN7Vehicle21notifyHitNPCofDespawnEv) }
    .vehicle_clean 0x00310dcc : { *(.text._ZN7Vehicle5cleanEv) }
    .vehicle_target_cleanup 0x00310880 : { *(.text._ZN7Vehicle22cleanupTargetDetectionEv) }
    .vehicle_clear_alert 0x003108d4 : { *(.text._ZN7Vehicle12clearOnAlertEv) }
    .vehicle_camera_enter 0x0030a378 : { *(.text._ZN7Vehicle13onCameraEnterEv) }
    .vehicle_percent_skid 0x00307d7c : { *(.text._ZN7Vehicle21_calculatePercentSkidEf) }
    .vehicle_marker_type 0x00307b9c : { *(.text._ZN7Vehicle13getMarkerTypeEv) }
    .vehicle_marker_type_thunk 0x00307b88 : { *(.text._ZThn52_N7Vehicle13getMarkerTypeEv .gnu.linkonce.t._ZThn52_N7Vehicle13getMarkerTypeEv) }
    .vehicle_stop_siren 0x00308170 : { *(.text._ZN7Vehicle9stopSirenEv) }
    .vehicle_sound_register 0x003083a4 : { *(.text._ZN7Vehicle26RegisterCarSoundsCallbacksEv) }
    .vehicle_sound_unregister 0x00308398 : { *(.text._ZN7Vehicle28UnRegisterCarSoundsCallbacksEv) }
    .vehicle_get_speed 0x00307ba4 : { *(.text._ZNK7Vehicle8GetSpeedEv) }
    .vehicle_warm_up 0x0030a1c8 : { *(.text._ZN7Vehicle6WarmUpEv) }
    .vehicle_reset_previous_position 0x00309d2c : { *(.text._ZN7Vehicle16resetPreviousPosEv) }
    .vehicle_check_destination 0x00309428 : { *(.text._ZN7Vehicle16CheckDestinationEv) }
    .vehicle_flee 0x003093c4 : { *(.text._ZN7Vehicle4fleeERKN3irr4core8vector3dIfEE) }
    .vehicle_drive_to_location 0x003093f0 : { *(.text._ZN7Vehicle15driveToLocationERKN3irr4core8vector3dIfEEb) }
    .vehicle_wait 0x00307ed4 : { *(.text._ZN7Vehicle4waitEi) }
    .vehicle_freeze 0x00307f04 : { *(.text._ZN7Vehicle6freezeEv) }
    .vehicle_set_position 0x0030bc4c : { *(.text._ZN7Vehicle11SetPositionERKN3irr4core8vector3dIfEE) }
    .vehicle_set_rotation 0x0030b648 : { *(.text._ZN7Vehicle11SetRotationERKN3irr4core10quaternionE) }
    .vehicle_reset_state 0x00309dec : { *(.text._ZN7Vehicle12resetVehicleEv) }
    .vehicle_destroy_wheels 0x00309e68 : { *(.text._ZN7Vehicle13DestroyWheelsEv) }
    .vehicle_stop 0x00309eac : { *(.text._ZN7Vehicle4StopEv) }
    .vehicle_immobilize 0x0030a230 : { *(.text._ZN7Vehicle10immobilizeEv) }
    .vehicle_mobilize 0x0030a3e4 : { *(.text._ZN7Vehicle8mobilizeEv) }
    .vehicle_cleanup_sounds 0x003090e8 : { *(.text._ZN7Vehicle14_cleanupSoundsEv) }
    .vehicle_debug 0x0030b12c : { *(.text._ZN7Vehicle5debugEPN3irr5video12IVideoDriverE) }
    .vehicle_tire_trails 0x00309600 : { *(.text._ZN7Vehicle19UpdateCarTireTrailsEii) }
    .vehicle_tire_trails_init 0x0041feb0 : { *(.rodata._ZZN7Vehicle19UpdateCarTireTrailsEiiE*C.*) }
    .vehicle_repair 0x0030b9a4 : { *(.text._ZN7Vehicle6repairEv) }
    .vehicle_start_driving 0x00311148 : { *(.text._ZN7Vehicle12startDrivingEv) }
    .vehicle_play_horn 0x00312fb8 : { *(.text._ZN7Vehicle8playHornEv) }
    .vehicle_play_horn_tables 0x0041f7ac : { *(.rodata._ZN7Vehicle8playHornEv) }
    .vehicle_stop_driving 0x00309188 : { *(.text._ZN7Vehicle11stopDrivingEv) }
    .vehicle_clean_targets 0x0030a490 : { *(.text._ZN7Vehicle12cleanTargetsEv) }
    .vehicle_adjust_engine_pitch 0x00307bcc : { *(.text._ZN7Vehicle18_adjustEnginePitchEj) }
    .vehicle_update_car_sounds 0x0030822c : { *(.text._ZN7Vehicle15UpdateCarSoundsEv) }
    .vehicle_nearest_door_dummy 0x0030b22c : { *(.text._ZN7Vehicle19getNearestDoorDummyEN3irr4core8vector3dIfEE) }
    .vehicle_accelerate 0x00307d30 : { *(.text._ZN7Vehicle10accelerateEf) }
    .vehicle_brake 0x00307d48 : { *(.text._ZN7Vehicle5brakeEf) }
    .vehicle_turn 0x00307d60 : { *(.text._ZN7Vehicle4turnEbf) }
    .vehicle_set_driver 0x00308e48 : { *(.text._ZN7Vehicle9setDriverEP9Character) }
    .vehicle_reset_driver 0x0030a1fc : { *(.text._ZN7Vehicle11resetDriverEv) }
    .vehicle_reset_collisions 0x0030a5c4 : { *(.text._ZN7Vehicle15resetCollisionsEv) }
    .vehicle_skin_mesh 0x00307b18 : { *(.text._ZN7Vehicle11getSkinMeshEv) }
    .vehicle_get_spawn_type 0x00307b50 : { *(.text._ZN7Vehicle12getSpawnTypeEv) }
    .vehicle_set_spawn_type 0x00307b58 : { *(.text._ZN7Vehicle12setSpawnTypeEi) }
    .vehicle_get_max_health 0x00307b60 : { *(.text._ZNK7Vehicle12getMaxHealthEv) }
    .vehicle_get_health 0x00307b68 : { *(.text._ZNK7Vehicle9getHealthEv) }
    .vehicle_is_dead 0x00307b70 : { *(.text._ZN7Vehicle6isDeadEv) }
    .vehicle_post_explosion 0x0030a2ac : { *(.text._ZN7Vehicle13postExplosionEv) }
    .vehicle_explosion_callback 0x0030a2d0 : { *(.text._Z28VehicleExplosionAnimCallbackPN3irr5scene19ITimelineControllerEPv) }
    .vehicle_shot_reaction 0x00308e80 : { *(.text._ZN7Vehicle7shootedEiP11LevelObject) }
    .vehicle_apply_damage 0x0030a2e0 : { *(.text._ZN7Vehicle11applyDamageEiP11LevelObjectb) }
    .vehicle_photographed 0x00307b20 : { *(.text._ZN7Vehicle12photographedEv) }
    .vehicle_clear_photographed 0x00307b30 : { *(.text._ZN7Vehicle17clearPhotographedEv) }
    .vehicle_is_photographed 0x00307b44 : { *(.text._ZNK7Vehicle14isPhotographedEv) }
    .vehicle_show_wheels 0x00309078 : { *(.text._ZN7Vehicle10showWheelsEv) }
    .vehicle_hide_wheels 0x003090b0 : { *(.text._ZN7Vehicle10hideWheelsEv) }
    .vehicle_no_animators_message 0x0041f4b0 : { *(.rodata.*noAnimatorsMessage*) }
    .vehicle_setup_names 0x0041f5c0 : { *vehicle-cleanup.o(.rodata.*vehicleSetupDoorFrontLeftE) *vehicle-cleanup.o(.rodata.*vehicleSetupDoorFrontRightE) *vehicle-cleanup.o(.rodata.*vehicleSetupBodySkinE) *vehicle-cleanup.o(.rodata.*vehicleSetupInteriorE) *vehicle-cleanup.o(.rodata.*vehicleSetupTextureE) *vehicle-cleanup.o(.rodata.*vehicleSetupDamageTextureE) *vehicle-cleanup.o(.rodata.*vehicleSetupWheelFrontLeftE) *vehicle-cleanup.o(.rodata.*vehicleSetupWheelFrontRightE) *vehicle-cleanup.o(.rodata.*vehicleSetupWheelBackLeftE) *vehicle-cleanup.o(.rodata.*vehicleSetupWheelBackRightE) *vehicle-cleanup.o(.rodata.*vehicleSetupBodyNodeE) *vehicle-cleanup.o(.rodata.*vehicleSetupSmokeDummyE) *vehicle-cleanup.o(.rodata.*vehicleSetupSmokeEffectE) *vehicle-cleanup.o(.rodata.*vehicleSetupFireEffectE) }
    .vehicle_setup_shadow_name 0x0041bcc4 : { *vehicle-cleanup.o(.rodata.*vehicleSetupShadowNodeE) }
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
    .vehicle_mesh 0x00307bc8 : { *(.text._ZN7Vehicle7getMeshEv) }
    .vehicle_is_high_vehicle 0x00308ec4 : { *(.text._ZN7Vehicle11isHiVehicleEv) }
    .vehicle_high_enter_clip 0x0041df0c : { *(.rodata.*highVehicleEnterClip*) }
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
    .vehicle_mesh_bounds 0x003091e8 : { *(.text._ZNK7Vehicle18GetMeshBoundingBoxEPKN3irr5scene10ISceneNodeE) }
    .vehicle_skinning 0x00309170 : { *(.text._ZN7Vehicle14enableSkinningEb) }
    .vehicle_reset_lights 0x0030805c : { *(.text._ZN7Vehicle12_resetLightsEv) }
    .vehicle_rent 0x00308128 : { *(.text._ZN7Vehicle4rentEb) }
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
    .vehicle_init_v8_z06 0x0030840c : { *(.text._ZN7Vehicle15InitV8Z06SoundsEv) }
    .vehicle_init_v6_turbo 0x00308700 : { *(.text._ZN7Vehicle17InitV6TurboSoundsEv) }
    .vehicle_init_v6_na 0x00308998 : { *(.text._ZN7Vehicle14InitV6naSoundsEv) }
    .vehicle_init_4cyl_na 0x00308bb0 : { *(.text._ZN7Vehicle16Init4CylNaSoundsEv) }
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
    .vehicle_cleanup_3 0x0030b624 : { *vehicle-cleanup.o(.text.__tcf_0) }
    .vehicle_empty_string 0x004b8724 (NOLOAD) : { *vehicle-cleanup.o(.bss._ZN3irr5scene6quake315irrEmptyStringcE) }
    .got 0x004b0048 : { *(.got.plt) . = 0x360; *(.got) }
    .verification 0x00600000 : { *retail-got.o(.text) }
    .verification_constants : { *(.rodata.*photographedFlag*) }
    .verification_unused_morph_dtor : { *(.gnu.linkonce.t._ZN16CCarMorphingMeshD2Ev) }
}
ASSERT(SIZEOF(.vehicle_empty_string) == 32, "Vehicle empty string extent");
