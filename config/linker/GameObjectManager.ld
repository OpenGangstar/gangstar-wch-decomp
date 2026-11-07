OUTPUT_FORMAT("elf32-littlearm")
OUTPUT_ARCH(arm)
ENTRY(_ZN17GameObjectManagerC1Ev)
INCLUDE build/matches/game-object-manager/retail-symbols.ld
memset = 0x001c45d4;
__aeabi_fmul = 0x001c4724;
_ZdlPv = 0x001c42b0;
strcmp = 0x001c4658;
__aeabi_atexit = 0x001c494c;
_Znaj = 0x001c3ff8;
_Znwj = 0x001c4814;
_ZdaPv = 0x001c461c;
__aeabi_i2f = 0x001c41e4;
strlen = 0x001c48bc;
__stack_chk_fail = 0x001c42e0;
__cxa_pure_virtual = 0;
memcpy = 0x001c4190;
strncasecmp = 0x001c42c8;
fopen = 0x001c45bc;
fclose = 0x001c4628;
printf = 0x001c4058;
fprintf = 0x001c4388;
strcpy = 0x001c3fd4;
vprintf = 0x001c43c4;
__aeabi_f2d = 0x001c48f8;
sprintf = 0x001c46ac;
remove = 0x001c41d8;
ftell = 0x001c45f8;
fseek = 0x001c43f4;
fwrite = 0x001c47e4;
fread = 0x001c4598;
__cxa_guard_acquire = 0x001c4958;
__cxa_guard_release = 0x001c46c4;
strstr = 0x001c446c;
strchr = 0x001c48e0;
atoi = 0x001c4880;
puts = 0x001c41b4;

_ZN24retail_level_transitions16civPassive_transE = 0x00420498;
_ZN24retail_level_transitions17scriptedNpc_transE = 0x004205c4;
_ZN24retail_level_transitions19civAggressive_transE = 0x004205f4;
_ZN24retail_level_transitions16gangMember_transE = 0x004206d8;
_ZN24retail_level_transitions9cop_transE = 0x004206e4;
_ZN24retail_level_transitions10swat_transE = 0x0042081c;
_ZN24retail_level_transitions17civ_vehicle_transE = 0x00420828;
_ZN24retail_level_transitions17cop_vehicle_transE = 0x004208b8;
_ZN24retail_level_transitions11guard_transE = 0x0042096c;
_ZN24retail_level_transitions22scripted_vehicle_transE = 0x00420a14;
__aeabi_fsub = 0x001c4328;
__aeabi_fadd = 0x001c4154;
sqrt = 0x001c401c;
__aeabi_d2f = 0x001c4310;
__aeabi_fcmple = 0x001c43ac;
__aeabi_fdiv = 0x001c4520;
__aeabi_fcmpgt = 0x001c419c;
__aeabi_fcmpeq = 0x001c470c;
__aeabi_fcmplt = 0x001c479c;
_ZN36retail_gameobjectmanager_transitions16civPassive_transE = 0x0041fec8;
_ZN36retail_gameobjectmanager_transitions17scriptedNpc_transE = 0x0041fff4;
_ZN36retail_gameobjectmanager_transitions19civAggressive_transE = 0x00420024;
_ZN36retail_gameobjectmanager_transitions16gangMember_transE = 0x00420108;
_ZN36retail_gameobjectmanager_transitions9cop_transE = 0x00420114;
_ZN36retail_gameobjectmanager_transitions10swat_transE = 0x0042024c;
_ZN36retail_gameobjectmanager_transitions17civ_vehicle_transE = 0x00420258;
_ZN36retail_gameobjectmanager_transitions17cop_vehicle_transE = 0x004202e8;
_ZN36retail_gameobjectmanager_transitions11guard_transE = 0x0042039c;
_ZN36retail_gameobjectmanager_transitions22scripted_vehicle_transE = 0x00420444;
_ZN26retail_wrapper_transitions16civPassive_transE = 0x00413508;
_ZN26retail_wrapper_transitions17scriptedNpc_transE = 0x00413634;
_ZN26retail_wrapper_transitions19civAggressive_transE = 0x00413664;
_ZN26retail_wrapper_transitions16gangMember_transE = 0x00413748;
_ZN26retail_wrapper_transitions9cop_transE = 0x00413754;
_ZN26retail_wrapper_transitions10swat_transE = 0x0041388c;
_ZN26retail_wrapper_transitions17civ_vehicle_transE = 0x00413898;
_ZN26retail_wrapper_transitions17cop_vehicle_transE = 0x00413928;
_ZN26retail_wrapper_transitions11guard_transE = 0x004139dc;
_ZN26retail_wrapper_transitions22scripted_vehicle_transE = 0x00413a84;
_ZN28retail_gs3dstuff_transitions16civPassive_transE = 0x0041467c;
_ZN28retail_gs3dstuff_transitions17scriptedNpc_transE = 0x004147a8;
_ZN28retail_gs3dstuff_transitions19civAggressive_transE = 0x004147d8;
_ZN28retail_gs3dstuff_transitions16gangMember_transE = 0x004148bc;
_ZN28retail_gs3dstuff_transitions9cop_transE = 0x004148c8;
_ZN28retail_gs3dstuff_transitions10swat_transE = 0x00414a00;
_ZN28retail_gs3dstuff_transitions17civ_vehicle_transE = 0x00414a0c;
_ZN28retail_gs3dstuff_transitions17cop_vehicle_transE = 0x00414a9c;
_ZN28retail_gs3dstuff_transitions11guard_transE = 0x00414b50;
_ZN28retail_gs3dstuff_transitions22scripted_vehicle_transE = 0x00414bf8;
INCLUDE config/linker/GS3DSceneTraversal.ld
SECTIONS {
    .ai_manager_singleton 0x002dbae8 : { *gs3d-stuff.o(.gnu.linkonce.t._ZN9AIManager11getInstanceEv) }
    .ai_manager_cleanup 0x002dbb3c : { *gs3d-stuff.o(.text.__tcf_3) }
    .ai_manager_guard 0x004b6a90 (NOLOAD) : { *gs3d-stuff.o(.gnu.linkonce.b._ZGVZN9AIManager11getInstanceEvE3aim) }
    .ai_manager_instance 0x004b6ae8 (NOLOAD) : { *gs3d-stuff.o(.gnu.linkonce.b._ZZN9AIManager11getInstanceEvE3aim) }
    .wanted_singleton 0x002dba04 : { *gs3d-stuff.o(.gnu.linkonce.t._ZN18WantedLevelManager11getInstanceEv) }
    .wanted_cleanup 0x002dba58 : { *gs3d-stuff.o(.text.__tcf_2) }
    .wanted_guard 0x004b6728 (NOLOAD) : { *gs3d-stuff.o(.gnu.linkonce.b._ZGVZN18WantedLevelManager11getInstanceEvE3wlm) }
    .wanted_instance 0x004b6a98 (NOLOAD) : { *gs3d-stuff.o(.gnu.linkonce.b._ZZN18WantedLevelManager11getInstanceEvE3wlm) }
    .map_singleton 0x002dbb58 : { *gs3d-stuff.o(.gnu.linkonce.t._ZN3Map11getInstanceEv) }
    .map_cleanup 0x002dbbac : { *gs3d-stuff.o(.text.__tcf_1) }
    .map_guard 0x004b6a94 (NOLOAD) : { *gs3d-stuff.o(.gnu.linkonce.b._ZGVZN3Map11getInstanceEvE3map) }
    .map_instance 0x004b6b00 (NOLOAD) : { *gs3d-stuff.o(.gnu.linkonce.b._ZZN3Map11getInstanceEvE3map) }
    .level_get_speed 0x2f1430 : { *level-object.o(.text._ZNK11LevelObject8GetSpeedEv .gnu.linkonce.t._ZNK11LevelObject8GetSpeedEv) }
    .level_get_material_id 0x316830 : { *level-object.o(.text._ZNK11LevelObject8GetMatIDEv .gnu.linkonce.t._ZNK11LevelObject8GetMatIDEv) }
    .level_get_triangle_id 0x317824 : { *level-object.o(.text._ZNK11LevelObject8GetTriIDEv .gnu.linkonce.t._ZNK11LevelObject8GetTriIDEv) }
    .level_hook_photo 0x2f1438 : { *level-object.o(.text._ZN11LevelObject12photographedEv .gnu.linkonce.t._ZN11LevelObject12photographedEv) }
    .level_hook_clear_photo 0x2f143c : { *level-object.o(.text._ZN11LevelObject17clearPhotographedEv .gnu.linkonce.t._ZN11LevelObject17clearPhotographedEv) }
    .level_hook_set_spawn 0x2f74cc : { *level-object.o(.text._ZN11LevelObject12setSpawnTypeEi .gnu.linkonce.t._ZN11LevelObject12setSpawnTypeEi) }
    .level_hook_damage 0x2f74fc : { *level-object.o(.text._ZN11LevelObject11applyDamageEiPS_b .gnu.linkonce.t._ZN11LevelObject11applyDamageEiPS_b) }
    .level_hook_anim_speed 0x2f7500 : { *level-object.o(.text._ZN11LevelObject27setAnimationSpeedMultiplierEi .gnu.linkonce.t._ZN11LevelObject27setAnimationSpeedMultiplierEi) }
    .level_hook_next_named 0x2f7508 : { *level-object.o(.text._ZN11LevelObject16setNextAnimationEPKcibbb .gnu.linkonce.t._ZN11LevelObject16setNextAnimationEPKcibbb) }
    .level_hook_next_id 0x2f750c : { *level-object.o(.text._ZN11LevelObject16setNextAnimationEiibbb .gnu.linkonce.t._ZN11LevelObject16setNextAnimationEiibbb) }
    .level_hook_shot 0x2f7510 : { *level-object.o(.text._ZN11LevelObject7shootedEiPS_ .gnu.linkonce.t._ZN11LevelObject7shootedEiPS_) }
    .level_hook_stop 0x316838 : { *level-object.o(.text._ZN11LevelObject4StopEv .gnu.linkonce.t._ZN11LevelObject4StopEv) }
    .level_hook_setup_node 0x316844 : { *level-object.o(.text._ZN11LevelObject14setupSceneNodeEiPN3irr5scene10ISceneNodeEiPPv .gnu.linkonce.t._ZN11LevelObject14setupSceneNodeEiPN3irr5scene10ISceneNodeEiPPv) }
    .level_hook_debug 0x316848 : { *level-object.o(.text._ZN11LevelObject5debugEPN3irr5video12IVideoDriverE .gnu.linkonce.t._ZN11LevelObject5debugEPN3irr5video12IVideoDriverE) }
    .level_hook_init 0x3168ac : { *level-object.o(.text._ZN11LevelObject4initEv .gnu.linkonce.t._ZN11LevelObject4initEv) }
    .level_hook_clean 0x3168b0 : { *level-object.o(.text._ZN11LevelObject5cleanEv .gnu.linkonce.t._ZN11LevelObject5cleanEv) }
    .level_base_photo 0x2f1440 : { *level-object.o(.text._ZNK11LevelObject14isPhotographedEv .gnu.linkonce.t._ZNK11LevelObject14isPhotographedEv) }
    .level_base_health_max 0x2f74ec : { *level-object.o(.text._ZNK11LevelObject12getMaxHealthEv .gnu.linkonce.t._ZNK11LevelObject12getMaxHealthEv) }
    .level_base_health 0x2f74f0 : { *level-object.o(.text._ZNK11LevelObject9getHealthEv .gnu.linkonce.t._ZNK11LevelObject9getHealthEv) }
    .level_base_dead 0x2f74f4 : { *level-object.o(.text._ZN11LevelObject6isDeadEv .gnu.linkonce.t._ZN11LevelObject6isDeadEv) }
    .level_base_skin 0x2f74f8 : { *level-object.o(.text._ZN11LevelObject11getSkinMeshEv .gnu.linkonce.t._ZN11LevelObject11getSkinMeshEv) }
    .level_sight 0x00317380 : { *level-object.o(.text._ZN11LevelObject17canSeeLevelObjectEPS_RN3irr4core8vector3dIfEE) }
    .level_base_type 0x002f74d0 : { *level-object.o(.text._ZN11LevelObject12getSpawnTypeEv .gnu.linkonce.t._ZN11LevelObject12getSpawnTypeEv) }
    .level_visible 0x0031696c : { *level-object.o(.text._ZN11LevelObject17isVisibleOnScreenEv) }
    .level_range 0x003169b4 : { *level-object.o(.text._ZN11LevelObject13isWithinRangeEf) }
    .level_string_cleanup 0x003168b4 : { *level-object.o(.text.__tcf_3) }
    .level_startup 0x0031787c : { *level-object.o(.text._Z41__static_initialization_and_destruction_0ii) }
    .level_startup_wrapper 0x003179c0 : { *level-object.o(.text._GLOBAL__I__ZN11LevelObject12s_highlightsE) }
    .level_startup_string 0x004b8a38 (NOLOAD) : { *level-object.o(.bss._ZN3irr5scene6quake315irrEmptyStringcE) }
    .level_startup_half 0x004b8a58 (NOLOAD) : { *level-object.o(.bss._ZN3irr2ps5vHalfE) }
    .level_startup_record_0 0x004b8a64 (NOLOAD) : { *level-object.o(.bss._ZN8gameloft2ai11civ_passiveE) }
    .level_startup_record_1 0x004b8a6c (NOLOAD) : { *level-object.o(.bss._ZN8gameloft2ai12npc_scriptedE) }
    .level_startup_record_2 0x004b8a74 (NOLOAD) : { *level-object.o(.bss._ZN8gameloft2ai13civ_agressiveE) }
    .level_startup_record_3 0x004b8a7c (NOLOAD) : { *level-object.o(.bss._ZN8gameloft2ai11gang_memberE) }
    .level_startup_record_4 0x004b8a84 (NOLOAD) : { *level-object.o(.bss._ZN8gameloft2ai3copE) }
    .level_startup_record_5 0x004b8a8c (NOLOAD) : { *level-object.o(.bss._ZN8gameloft2ai4swatE) }
    .level_startup_record_6 0x004b8a94 (NOLOAD) : { *level-object.o(.bss._ZN8gameloft2ai11civ_vehicleE) }
    .level_startup_record_7 0x004b8a9c (NOLOAD) : { *level-object.o(.bss._ZN8gameloft2ai11cop_vehicleE) }
    .level_startup_record_8 0x004b8aa4 (NOLOAD) : { *level-object.o(.bss._ZN8gameloft2ai5guardE) }
    .level_startup_record_9 0x004b8aac (NOLOAD) : { *level-object.o(.bss._ZN8gameloft2ai16scripted_vehicleE) }


    .level_highlight_load 0x00316a84 : { *level-object.o(.text._ZN11LevelObject14loadHighlightsEPKc) }
    .level_factory_cleanup 0x003168e4 : { *level-object.o(.text.__tcf_0) }

    .level_destructor_delete 0x00317240 : { *level-object.o(.text._ZN11LevelObjectD0Ev) }
    .level_destructor 0x003172e4 : { *level-object.o(.text._ZN11LevelObjectD1Ev .text._ZN11LevelObjectD2Ev) }
    .level_highlight_free 0x00316908 : { *level-object.o(.text._ZN11LevelObject14freeHighlightsEv) }
    .level_setup 0x003167e0 : { *level-object.o(.text._ZN11LevelObject5setupEv) }

    .level_load 0x00316fec : { *level-object.o(.text._ZN11LevelObject4LoadERKN7Structs15GameObjectBasicEPN3irr7collada15CColladaFactoryE) }
    .level_name 0x00316940 : { *level-object.o(.text._ZN11LevelObject7SetNameEPKc) }
    .level_metatype 0x00316a50 : { *level-object.o(.text._ZN11LevelObject11GetMetatypeEv) }

    .object_spawn_file 0x00315c60 : { *game-object-manager.o(.text._ZN17GameObjectManager15LoadSpawnPointsEPKc) }
    .object_load_file 0x00315d40 : { *game-object-manager.o(.text._ZN17GameObjectManager4LoadEPc) }

    .gs_enter 0x002dbef8 : { *gs3d-stuff.o(.text._ZN9GS3DStuff4ctorEPK12StateMachine) }
    .gs_wakeup 0x002dc32c : { *gs3d-stuff.o(.text._ZN9GS3DStuff6wakeupEPK12StateMachine) }
    .gs_resume 0x002dc360 : { *gs3d-stuff.o(.text._ZN9GS3DStuff6resumeEPK12StateMachine) }
    .gs_last_time 0x004b698c (NOLOAD) : { *gs3d-stuff.o(.bss._ZN9GS3DStuff8lastTimeE) }
    .gs_code_2 0x002dac98 : { *gs3d-stuff.o(.gnu.linkonce.t._ZN9StateBase4ctorEPK12StateMachine) }
    .gs_code_3 0x002dac9c : { *gs3d-stuff.o(.gnu.linkonce.t._ZN9StateBase4dtorEPK12StateMachine) }
    .gs_code_4 0x002daca0 : { *gs3d-stuff.o(.gnu.linkonce.t._ZN9StateBase5pauseEPK12StateMachine) }
    .gs_code_5 0x002daca4 : { *gs3d-stuff.o(.gnu.linkonce.t._ZN9StateBase6resumeEPK12StateMachine) }
    .gs_code_6 0x002daca8 : { *gs3d-stuff.o(.gnu.linkonce.t._ZN9StateBase6updateEP12StateMachine) }
    .gs_code_7 0x002dacac : { *gs3d-stuff.o(.gnu.linkonce.t._ZN9StateBase4drawEPK12StateMachine) }
    .gs_code_8 0x002dacb0 : { *gs3d-stuff.o(.gnu.linkonce.t._ZN9StateBase6draw2dEPK12StateMachine) }
    .gs_code_9 0x002dacb4 : { *gs3d-stuff.o(.gnu.linkonce.t._ZN9StateBase5sleepEPK12StateMachine) }
    .gs_code_10 0x002dacb8 : { *gs3d-stuff.o(.gnu.linkonce.t._ZN9StateBase6wakeupEPK12StateMachine) }
    .gs_code_11 0x002dacbc : { *gs3d-stuff.o(.gnu.linkonce.t._ZN9StateBase10isDrawableEv) }
    .gs_code_12 0x002dacc0 : { *gs3d-stuff.o(.gnu.linkonce.t._ZN9StateBase8isKindOfEi) }
    .gs_code_15 0x002dacc4 : { *gs3d-stuff.o(.gnu.linkonce.t._ZN9GS3DStuff10isDrawableEv) }
    .gs_code_16 0x002dacc8 : { *gs3d-stuff.o(.gnu.linkonce.t._ZN9GS3DStuff8isKindOfEi) }
    .gs_code_26 0x002dacd8 : { *gs3d-stuff.o(.text._ZN9GS3DStuff16GetBulletManagerEv) }
    .gs_code_27 0x002dacec : { *gs3d-stuff.o(.text._ZN9GS3DStuff11GetTrailMgrEv) }
    .gs_code_28 0x002dad00 : { *gs3d-stuff.o(.text._ZN9GS3DStuff17OptimizeHierarchyEPN3irr5scene10ISceneNodeE) }
    .gs_code_29 0x002dad04 : { *gs3d-stuff.o(.text._ZN9GS3DStuff4dtorEPK12StateMachine) }
    .gs_code_30 0x002dad08 : { *gs3d-stuff.o(.text._ZN9GS3DStuff9getSkyBoxEv) }
    .gs_code_31 0x002dad1c : { *gs3d-stuff.o(.text._ZN9GS3DStuff16getSkyBoxTextureEv) }
    .gs_code_32 0x002dad30 : { *gs3d-stuff.o(.text._ZN9GS3DStuff20getTextureNameSuffixEv) }
    .gs_code_33 0x002dad44 : { *gs3d-stuff.o(.text._ZN9GS3DStuff15getSceneOctTreeEv) }
    .gs_code_34 0x002dad58 : { *gs3d-stuff.o(.text._ZN9GS3DStuff6draw2dEPK12StateMachine) }
    .gs_code_14 0x002db4b4 : { *gs3d-stuff.o(.gnu.linkonce.t._ZN14IEventReceiverD0Ev) }
    .gs_code_13 0x002db4d4 : { *gs3d-stuff.o(.gnu.linkonce.t._ZN14IEventReceiverD1Ev) }
    .gs_code_1 0x002db4ec : { *gs3d-stuff.o(.gnu.linkonce.t._ZN9StateBaseD0Ev) }
    .gs_code_0 0x002db50c : { *gs3d-stuff.o(.gnu.linkonce.t._ZN9StateBaseD1Ev) }
    .gs_code_25 0x002db524 : { *gs3d-stuff.o(.text._ZN7Structs23PhonePerformanceProfile4ReadER10DataStream) }
    .gs_code_22 0x002db998 : { *gs3d-stuff.o(.text._ZN9GS3DStuff4drawEPK12StateMachine) }
    .gs_code_23 0x002dba74 : { *gs3d-stuff.o(.text._ZThn4_N9GS3DStuff7onEventEPK6IEventPK12EventManager) }
    .gs_code_24 0x002dba88 : { *gs3d-stuff.o(.text._ZN9GS3DStuff7onEventEPK6IEventPK12EventManager) }
    .gs_code_17 0x002dc6d8 : { *gs3d-stuff.o(.text._ZN9GS3DStuffC1Ev) }
    .gs_code_20 0x002e0524 : { *gs3d-stuff.o(.text._ZThn4_N9GS3DStuffD0Ev) }
    .gs_code_21 0x002e0538 : { *gs3d-stuff.o(.text._ZN9GS3DStuffD0Ev) }
    .gs_code_18 0x002e058c : { *gs3d-stuff.o(.text._ZThn4_N9GS3DStuffD1Ev) }
    .gs_code_19 0x002e05a0 : { *gs3d-stuff.o(.text._ZN9GS3DStuffD1Ev) }
    .gs_state_vtable 0x004a8b60 : { *gs3d-stuff.o(.gnu.linkonce.d.rel.ro._ZTV9StateBase) }
    .gs_receiver_vtable 0x004a8b48 : { *gs3d-stuff.o(.gnu.linkonce.d.rel.ro._ZTV14IEventReceiver) }
    .gs_scene_vtable 0x004a8a70 : { *gs3d-stuff.o(.data.rel.ro._ZTV9GS3DStuff) }
    .gs_event_format 0x00435e90 : { *gs3d-stuff.o(.rodata.gs_event_format) }
    .gs_touch_event 0x004144a4 : { *gs3d-stuff.o(.rodata.gs_touch_event) }
    .gs_global_4b6978 0x004b6978 (NOLOAD) : { *gs3d-stuff.o(.bss._ZN9GS3DStuff15s_bulletManagerE) }
    .gs_global_4b697c 0x004b697c (NOLOAD) : { *gs3d-stuff.o(.bss._ZN9GS3DStuff10s_TrailMgrE) }
    .gs_global_4b6998 0x004b6998 (NOLOAD) : { *gs3d-stuff.o(.bss._ZN9GS3DStuff6skyBoxE) }
    .gs_global_4b699c 0x004b699c (NOLOAD) : { *gs3d-stuff.o(.bss._ZN9GS3DStuff13skyBoxTextureE) }
    .gs_global_4b6988 0x004b6988 (NOLOAD) : { *gs3d-stuff.o(.bss._ZN9GS3DStuff12sceneOcttreeE) }
    .gs_global_4b69e4 0x004b69e4 (NOLOAD) : { *gs3d-stuff.o(.bss._ZN9GS3DStuff25s_phonePerformanceProfileE) }
    .factory_d0 0x002db450 : { *gs3d-stuff.o(.gnu.linkonce.t._ZN12CGameFactoryD0Ev) }
    .factory_d1 0x002dd048 : { *gs3d-stuff.o(.gnu.linkonce.t._ZN12CGameFactoryD1Ev .gnu.linkonce.t._ZN12CGameFactoryD2Ev) }
    .factory_singleton 0x002db9a8 : { *gs3d-stuff.o(.gnu.linkonce.t._ZN12CGameFactory11getInstanceEv .text._ZN12CGameFactory11getInstanceEv) }
    .factory_create 0x002dbf58 : { *gs3d-stuff.o(.gnu.linkonce.t._ZN12CGameFactory10createNodeERKN3irr7collada16CColladaDatabaseEPNS1_5SNodeE) }
    .factory_cleanup 0x002dd06c : { *gs3d-stuff.o(.text.__tcf_0) }
    .factory_property 0x002db740 : { *gs3d-stuff.o(.text._ZN9GS3DStuff11getPropertyEPKvPKcPc) }
    .factory_vtable 0x004a8ae8 : { *gs3d-stuff.o(.gnu.linkonce.d.rel.ro._ZTV12CGameFactory) }
    .factory_billboard_text 0x004144b8 : { *gs3d-stuff.o(.rodata.game_factory_billboard) }
    .factory_guard 0x004b6724 (NOLOAD) : { *gs3d-stuff.o(.gnu.linkonce.b._ZGVZN12CGameFactory11getInstanceEvE2gf) }
    .factory_instance 0x004b6b4c (NOLOAD) : { *gs3d-stuff.o(.gnu.linkonce.b._ZZN12CGameFactory11getInstanceEvE2gf) }
    .object_dispatch 0x00315674 : { *game-object-manager.o(.text._ZN17GameObjectManager14LoadGameObjectER10DataStream) }
    .object_factory_cleanup 0x00314f7c : { *game-object-manager.o(.text.__tcf_0) }

    .resstream_text 0x0034ef4c : {
        *res-stream.o(.text._ZN9ResStreamC1Ei .text._ZN9ResStreamC2Ei)
        *res-stream.o(.text._ZN9ResStreamC1Ev .text._ZN9ResStreamC2Ev)
        *res-stream.o(.text._ZN9ResStreamC1EPKci .text._ZN9ResStreamC2EPKci)
    }
    .resdep_text 0x0034eb7c : {
        *file-stream.o(.text._ZNK10FileStream7IsValidEv .gnu.linkonce.t._ZNK10FileStream7IsValidEv)
        *file-stream.o(.text._ZN10FileStream4SizeEv)
        *file-stream.o(.text._ZN10FileStream6UnloadEPv)
        *file-stream.o(.text._ZN10FileStream6DeleteEPKc)
        *file-stream.o(.text._ZNK10FileStream4TellEv)
        *file-stream.o(.text._ZN10FileStream4SeekEii)
        *file-stream.o(.text._ZN10FileStream5WriteEPKvi)
        *file-stream.o(.text._ZN10FileStream4ReadEPvi)
        *file-stream.o(.text._ZN10FileStream5CloseEv)
        *file-stream.o(.text._ZN10FileStreamD1Ev .text._ZN10FileStreamD2Ev)
        *file-stream.o(.text._ZN10FileStream4OpenEPKci)
        *file-stream.o(.text._ZN10FileStream6CreateEPKc)
        *file-stream.o(.text._ZN10FileStreamC2Ev .text._ZN10FileStreamC1Ev)
        *file-stream.o(.text._ZN10FileStream5ExistEPKc)
        *file-stream.o(.text._ZN10FileStreamC2EPKci .text._ZN10FileStreamC1EPKci)
        *file-stream.o(.text._ZN10FileStream4LoadEPKcPi)
        *file-stream.o(.text._ZN10FileStreamD0Ev)
    }
    .resdep_modes 0x004014f0 : { *file-stream.o(.rodata.readMode .rodata.appendMode) }
    .resdep_rodata 0x004361d4 : {
        *file-stream.o(.rodata.deleteFormat .rodata.updateMode .rodata.createMode .rodata.errorOpen)
    }
    .resdep_vtable 0x004ad668 : { *file-stream.o(.data.rel.ro._ZTV10FileStream) }
    .resdep_pathtext 0x002d2818 : { *path-name.o(.text._Z21ekd_makestringfile255PKcPc) }
    .resdep_debugtext 0x002d1494 : {
        *debug-log.o(.text._Z14ekd_debug_initv)
        *debug-log.o(.text._Z13ekd_debug_outPKcf)
        *debug-log.o(.text._Z13ekd_debug_outPKci)
        *debug-log.o(.text._Z13ekd_debug_outPKcPc)
        *debug-log.o(.text._Z13ekd_debug_outPKc)
        *debug-log.o(.text._Z7dbg_outPcz)
    }
    .resdep_debugrodata 0x004130ec : {
        . = 0x0; *debug-log.o(.rodata.logName)
        . = 0x10; *debug-log.o(.rodata.writeMode)
        . = 0x14; *debug-log.o(.rodata.errorInit)
        . = 0x40; *debug-log.o(.rodata.appendMode)
        . = 0x44; *debug-log.o(.rodata.errorFloat)
        . = 0x88; *debug-log.o(.rodata.errorInt)
        . = 0xcc; *debug-log.o(.rodata.errorString)
        . = 0x110; *debug-log.o(.rodata.errorText)
    }
    .resdep_debugbss 0x004b65f4 : { *debug-log.o(.bss.ekd_isHasInit) }
    .metatype_load 0x00315b4c : { *game-object-manager.o(.text._ZN17GameObjectManager13LoadMetatypesEv) }
    .metatype_filename 0x0041feb4 : { *game-object-manager.o(.rodata.str1.*) }

    .bufferstream_text 0x0034e2dc : {
        *buffer-stream.o(.text._ZNK12BufferStream4TellEv)
        *buffer-stream.o(.text._ZNK12BufferStream6GetPtrEv)
        *buffer-stream.o(.text._ZN12BufferStream8GetBytesEi)
        *buffer-stream.o(.text._ZN12BufferStream4ReadEPvi)
        *buffer-stream.o(.text._ZN12BufferStream10ReadStringEPPc)
        *buffer-stream.o(.text._ZN12BufferStream5CloseEv)
        *buffer-stream.o(.text._ZN12BufferStream13ReserveBufferEi)
        *buffer-stream.o(.text._ZN12BufferStream5WriteER6Streami)
        *buffer-stream.o(.text._ZN12BufferStream4SeekEii)
        *buffer-stream.o(.text._ZN12BufferStream5WriteEPKvi)
        *buffer-stream.o(.text._ZN12BufferStream4OpenEiiPv)
        *buffer-stream.o(.text._ZN12BufferStream4OpenEiiPvb)
        *buffer-stream.o(.text._ZN12BufferStreamD1Ev .text._ZN12BufferStreamD2Ev)
        *buffer-stream.o(.text._ZN12BufferStreamC1EiiPv .text._ZN12BufferStreamC2EiiPv)
        *buffer-stream.o(.text._ZN12BufferStreamC1EiiPvb .text._ZN12BufferStreamC2EiiPvb)
        *buffer-stream.o(.text._ZN12BufferStreamC2Ev .text._ZN12BufferStreamC1Ev)
        *buffer-stream.o(.text._ZN12BufferStreamD0Ev)
    }
    .bufferstream_vtable 0x004ad608 : { *buffer-stream.o(.data.rel.ro) }
    .metatype_create 0x00315968 : { *game-object-manager.o(.text._ZN17GameObjectManager28CreateGameObjectFromMetatypeEi) }
    .metatype_spawn 0x00315a14 : { *game-object-manager.o(.text._ZN17GameObjectManager15SpawnGameObjectEi) }
    .metatype_lookup 0x00315a40 : { *game-object-manager.o(.text._ZN17GameObjectManager19GetMetatypeFromNameEPKc) }

    .streamvtable 0x004ad6c8 : { */stream.o(.data.rel.ro) }

    .streamtext 0x0034efe4 : {
        */stream.o(.text._ZN6StreamC1Ev .text._ZN6StreamC2Ev)
        */stream.o(.text._ZN6Stream5CloseEv)
        */stream.o(.text._ZN6Stream4ReadEv)
        */stream.o(.text._ZN6Stream5WriteEc)
        */stream.o(.text._ZN6Stream5WriteERS_i)
        */stream.o(.text._ZN6Stream4PeekEPvi)
        */stream.o(.text._ZN6StreamD0Ev .gnu.linkonce.t._ZN6StreamD0Ev)
        */stream.o(.text._ZN6StreamD1Ev .text._ZN6StreamD2Ev .gnu.linkonce.t._ZN6StreamD1Ev .gnu.linkonce.t._ZN6StreamD2Ev)
    }

    .datastream_vtable 0x004ad638 : { *data-stream.o(.data.rel.ro) }

    .datastream_text 0x0034e7b0 : {
        *data-stream.o(.text._Z11IsBigEndianv)
        *data-stream.o(.text._ZN10DataStream4ReadEPvi)
        *data-stream.o(.text._ZN10DataStream5WriteEPKvi)
        *data-stream.o(.text._ZN10DataStream4SeekEii)
        *data-stream.o(.text._ZNK10DataStream4TellEv)
        *data-stream.o(.text._ZN10DataStream4SkipEi)
        *data-stream.o(.text._ZN10DataStream17ReadUnsignedShortEv)
        *data-stream.o(.text._ZN10DataStream9ReadShortEv)
        *data-stream.o(.text._ZN10DataStream9ReadFloatEv)
        *data-stream.o(.text._ZN10DataStream7ReadUTFEPci)
        *data-stream.o(.text._ZN10DataStream5Peek1Ev)
        *data-stream.o(.text._ZN10DataStreamD0Ev .gnu.linkonce.t._ZN10DataStreamD0Ev)
        *data-stream.o(.text._ZN10DataStream9WriteByteEi)
        *data-stream.o(.text._ZN10DataStream12WriteBooleanEb)
        *data-stream.o(.text._ZN10DataStream16ReadUnsignedByteEv)
        *data-stream.o(.text._ZN10DataStream8ReadByteEv)
        *data-stream.o(.text._ZN10DataStream11ReadBooleanEv)
        *data-stream.o(.text._ZN10DataStream7ReadIntEv)
        *data-stream.o(.text._ZN10DataStream21ReadAndAllocateStringEv)
        *data-stream.o(.text._ZN10DataStream10ReadStringEPci)
        *data-stream.o(.text._ZN10DataStream5Peek4Ev)
        *data-stream.o(.text._ZN10DataStream10WriteFloatEf)
        *data-stream.o(.text._ZN10DataStream8WriteIntEi)
        *data-stream.o(.text._ZN10DataStream5Peek2Ev)
        *data-stream.o(.text._ZN10DataStream10WriteShortEi)
        *data-stream.o(.text._ZN10DataStream8WriteUTFEPKc)
        *data-stream.o(.text._ZN10DataStreamC1ER6StreamNS_6endianE .text._ZN10DataStreamC2ER6StreamNS_6endianE)
    }

    .datastream_destructor 0x002d3654 : { *(.text._ZN10DataStreamD1Ev .gnu.linkonce.t._ZN10DataStreamD1Ev) }

    .record_12 0x00315628 : { *game-object-manager.o(.text._ZN7Structs4Path4ReadER10DataStream .gnu.linkonce.t._ZN7Structs4Path4ReadER10DataStream) }
    .record_11 0x003155c4 : { *game-object-manager.o(.text._ZN7Structs10SpawnPoint4ReadER10DataStream .gnu.linkonce.t._ZN7Structs10SpawnPoint4ReadER10DataStream) }
    .record_10 0x00315584 : { *game-object-manager.o(.text._ZN7Structs10Checkpoint4ReadER10DataStream .gnu.linkonce.t._ZN7Structs10Checkpoint4ReadER10DataStream) }
    .record_9 0x00315500 : { *game-object-manager.o(.text._ZN7Structs11SceneCamera4ReadER10DataStream .gnu.linkonce.t._ZN7Structs11SceneCamera4ReadER10DataStream) }
    .record_8 0x00315484 : { *game-object-manager.o(.text._ZN7Structs6Weapon4ReadER10DataStream .gnu.linkonce.t._ZN7Structs6Weapon4ReadER10DataStream) }
    .record_7 0x0031544c : { *game-object-manager.o(.text._ZN7Structs4Item4ReadER10DataStream .gnu.linkonce.t._ZN7Structs4Item4ReadER10DataStream) }
    .record_6 0x0031541c : { *game-object-manager.o(.text._ZN7Structs6Marker4ReadER10DataStream .gnu.linkonce.t._ZN7Structs6Marker4ReadER10DataStream) }
    .record_5 0x003153a4 : { *game-object-manager.o(.text._ZN7Structs3NPC4ReadER10DataStream .gnu.linkonce.t._ZN7Structs3NPC4ReadER10DataStream) }
    .record_4 0x00315354 : { *game-object-manager.o(.text._ZN7Structs6Rocket4ReadER10DataStream .gnu.linkonce.t._ZN7Structs6Rocket4ReadER10DataStream) }
    .record_3 0x00315164 : { *game-object-manager.o(.text._ZN7Structs7Vehicle4ReadER10DataStream .gnu.linkonce.t._ZN7Structs7Vehicle4ReadER10DataStream) }
    .record_2 0x003150f0 : { *game-object-manager.o(.text._ZN7Structs15GameObjectBasic4ReadER10DataStream .gnu.linkonce.t._ZN7Structs15GameObjectBasic4ReadER10DataStream) }
    .record_1 0x003150d4 : { *game-object-manager.o(.text._ZN7Structs16GameObjectHeader4ReadER10DataStream .gnu.linkonce.t._ZN7Structs16GameObjectHeader4ReadER10DataStream) }
    .record_0 0x003150b0 : { *game-object-manager.o(.text._ZN7Structs8SVector34ReadER10DataStream .gnu.linkonce.t._ZN7Structs8SVector34ReadER10DataStream) }
    .gom_global 0x004b88b0 (NOLOAD) : { *game-object-manager.o(.bss._ZN17GameObjectManager5s_gomE) }
    .gom_vtable 0x004abc40 : { *game-object-manager.o(.data.rel.ro._ZTV17GameObjectManager .gnu.linkonce.d.rel.ro._ZTV17GameObjectManager) }

    .gom_12 0x003166f8 : { *game-object-manager.o(.text._ZN17GameObjectManagerD1Ev .text._ZN17GameObjectManagerD2Ev) }
    .gom_11 0x00316648 : { *game-object-manager.o(.text._ZN17GameObjectManagerD0Ev) }
    .gom_10 0x00315f04 : { *game-object-manager.o(.text._ZN17GameObjectManager16RemoveAndDestroyEP11LevelObject) }
    .gom_9 0x00315edc : { *game-object-manager.o(.text._ZN17GameObjectManager5SetupEv) }
    .gom_8 0x00315e5c : { *game-object-manager.o(.text._ZN17GameObjectManagerC2Ev .text._ZN17GameObjectManagerC1Ev) }
    .gom_7 0x00315068 : { *game-object-manager.o(.text._ZNK17GameObjectManager19GetGameObjectByNameEPKcb) }
    .gom_6 0x0031502c : { *game-object-manager.o(.text._ZN17GameObjectManager3AddEP11LevelObjecti) }
    .gom_5 0x00314ff4 : { *game-object-manager.o(.text._ZN17GameObjectManager8GetFirstEi) }
    .gom_4 0x00314fa0 : { *game-object-manager.o(.text._ZN17GameObjectManager5ClearEv) }
    .gom_3 0x00314f24 : { *game-object-manager.o(.text._ZN17GameObjectManager13getObjectListEi) }
    .gom_2 0x00314f14 : { *game-object-manager.o(.text._ZN17GameObjectManager6RemoveEP11LevelObject) }
    .gom_1 0x00314f00 : { *game-object-manager.o(.text._ZN17GameObjectManager22RemoveGameObjectOfTypeEi) }
    .gom_0 0x00314eec : { *game-object-manager.o(.text._ZN17GameObjectManager19AddGameObjectOfTypeEi) }
    .gol_empty 0x004b8884 (NOLOAD) : { *game-object-list.o(.bss._ZN3irr5scene6quake315irrEmptyStringcE) }
    .gol_half 0x004b88a4 (NOLOAD) : { *game-object-list.o(.bss._ZN3irr2ps5vHalfE) }

.gol_vtable__ZTV22IterationConditionName 0x004abc00 : { *game-object-list.o(.data.rel.ro._ZTV22IterationConditionName .gnu.linkonce.d.rel.ro._ZTV22IterationConditionName) }
    .gol_vtable__ZTV14GameObjectList 0x004abc10 : { *game-object-list.o(.data.rel.ro._ZTV14GameObjectList .gnu.linkonce.d.rel.ro._ZTV14GameObjectList) }
    .gol_20 0x00314ed8 : { *game-object-list.o(.text._GLOBAL__I__ZN14GameObjectListC2Ev) }
    .gol_19 0x00314e6c : { *game-object-list.o(.text._Z41__static_initialization_and_destruction_0ii) }
    .gol_18 0x00314e4c : { *game-object-list.o(.text._ZNK22IterationConditionName11IsRespectedER11LevelObjecti) }
    .gol_17 0x00314db8 : { *game-object-list.o(.text._ZNK14GameObjectList19GetGameObjectByNameEPKcbb) }
    .gol_16 0x00314d4c : { *game-object-list.o(.text._ZNK14GameObjectList8FillListERK18IterationConditioniPP11LevelObjectRib) }
    .gol_15 0x00314cf8 : { *game-object-list.o(.text._ZNK14GameObjectList9ForEachIfER15ForEachFunctionRK18IterationConditionb) }
    .gol_14 0x00314cb4 : { *game-object-list.o(.text._ZNK14GameObjectList8GetFirstERK18IterationConditionbPi) }
    .gol_13 0x00314c7c : { *game-object-list.o(.text._ZNK14GameObjectList7GetNextERK18IterationConditionPK11LevelObjectbPi) }
    .gol_12 0x00314c54 : { *game-object-list.o(.text._ZNK14GameObjectList7ForEachER15ForEachFunctionb) }
    .gol_11 0x00314c28 : { *game-object-list.o(.text._ZN14GameObjectList17UpdateGameObjectsEib) }
    .gol_10 0x00314c08 : { *game-object-list.o(.text._ZN14GameObjectListD2Ev .text._ZN14GameObjectListD1Ev) }
    .gol_9 0x00314be0 : { *game-object-list.o(.text._ZN14GameObjectListD0Ev) }
    .gol_8 0x00314bb8 : { *game-object-list.o(.text._ZN14GameObjectList5ClearEv) }
    .gol_7 0x00314b88 : { *game-object-list.o(.text.__tcf_2) }
    .gol_6 0x00314b84 : { *game-object-list.o(.text._ZNK14GameObjectList8GetFirstEv) }
    .gol_5 0x00314b64 : { *game-object-list.o(.text._ZN14GameObjectList16RemoveAndDestroyEP11LevelObject) }
    .gol_4 0x00314b28 : { *game-object-list.o(.text._ZN14GameObjectList6RemoveEP11LevelObject) }
    .gol_3 0x00314b0c : { *game-object-list.o(.text._ZN14GameObjectList3AddEP11LevelObjectb) }
    .gol_2 0x00314aec : { *game-object-list.o(.text._ZN14GameObjectList11InsertAfterEP11LevelObjectS1_) }
    .gol_1 0x00314ad4 : { *game-object-list.o(.text._ZNK14GameObjectList4SizeEv) }
    .gol_0 0x00314ab8 : { *game-object-list.o(.text._ZN14GameObjectListC1Ev .text._ZN14GameObjectListC2Ev) }
    .level_drop 0x00316e1c : { *level-object.o(.text._ZN11LevelObject13dropSceneNodeEv) }
    .level_enable 0x00316f54 : { *level-object.o(.text._ZN11LevelObject6enableEv) }
    .level_disable 0x00316e80 : { *level-object.o(.text._ZN11LevelObject7disableEv) }
    .level_enabled 0x0031683c : { *level-object.o(.text._ZNK11LevelObject9isEnabledEv) }
    .level_transform_6 0x00317854 : { *level-object.o(.text._ZNK11LevelObject8GetRightEv) }
    .level_transform_5 0x0031782c : { *level-object.o(.text._ZNK11LevelObject8GetFrontEv) }
    .level_transform_4 0x00316bc4 : { *level-object.o(.text._ZN11LevelObject11SetRotationERKN3irr4core8vector3dIfEE) }
    .level_transform_3 0x00316898 : { *level-object.o(.text._ZNK11LevelObject11GetRotationEv) }
    .level_transform_2 0x00316880 : { *level-object.o(.text._ZN11LevelObject11SetRotationERKN3irr4core10quaternionE) }
    .level_transform_1 0x00316860 : { *level-object.o(.text._ZN11LevelObject11SetPositionERKN3irr4core8vector3dIfEE) }
    .level_transform_0 0x0031684c : { *level-object.o(.text._ZNK11LevelObject11GetPositionEv) }
    .level_highlight 0x00316d08 : { *level-object.o(.text._ZN11LevelObject13showHighlightEi) }
    .level_grab 0x00316c28 : { *level-object.o(.text._ZN11LevelObject13grabSceneNodeEiPPPv) }
    .level_warmup 0x003167dc : { *level-object.o(.text._ZN11LevelObject6WarmUpEv) }
    .level_despawn 0x0031780c : { *level-object.o(.text._ZN11LevelObject9OnDespawnEv) }
    .level_spawn 0x00317818 : { *level-object.o(.text._ZN11LevelObject7OnSpawnEv) }
    .level_vtable 0x004abc58 : { *level-object.o(.data.rel.ro._ZTV11LevelObject .gnu.linkonce.d.rel.ro._ZTV11LevelObject) }
    .text 0x003167a4 : { *level-object.o(.text._ZN11LevelObjectC1Ei .text._ZN11LevelObjectC2Ei) }
    .levelobject_update 0x00316cc0 : { *level-object.o(.text._ZN11LevelObject6UpdateEi) }
    .got 0x004b0048 : { *(.got.plt) . = 0x360; *(.got) }
    .verification 0x00600000 : { *retail-got.o(.text) }
    .module_startup_game_object_manager_function_0 0x00314f4c : { *game-object-manager.o(.text.__tcf_4) }
    .module_startup_game_object_manager_function_1 0x00316420 : { *game-object-manager.o(.text._Z41__static_initialization_and_destruction_0ii) }
    .module_startup_game_object_manager_function_2 0x00316564 : { *game-object-manager.o(.text._GLOBAL__I__ZN17GameObjectManagerC2Ev) }
    .module_startup_game_object_manager_storage_0 0x004b88b4 (NOLOAD) : { *game-object-manager.o(.bss._ZN3irr5scene6quake315irrEmptyStringcE) }
    .module_startup_game_object_manager_storage_1 0x004b88d4 (NOLOAD) : { *game-object-manager.o(.bss._ZN3irr2ps5vHalfE) }
    .module_startup_game_object_manager_storage_2 0x004b88e0 (NOLOAD) : { *game-object-manager.o(.bss._ZN8gameloft2ai11civ_passiveE) }
    .module_startup_game_object_manager_storage_3 0x004b88e8 (NOLOAD) : { *game-object-manager.o(.bss._ZN8gameloft2ai12npc_scriptedE) }
    .module_startup_game_object_manager_storage_4 0x004b88f0 (NOLOAD) : { *game-object-manager.o(.bss._ZN8gameloft2ai13civ_agressiveE) }
    .module_startup_game_object_manager_storage_5 0x004b88f8 (NOLOAD) : { *game-object-manager.o(.bss._ZN8gameloft2ai11gang_memberE) }
    .module_startup_game_object_manager_storage_6 0x004b8900 (NOLOAD) : { *game-object-manager.o(.bss._ZN8gameloft2ai3copE) }
    .module_startup_game_object_manager_storage_7 0x004b8908 (NOLOAD) : { *game-object-manager.o(.bss._ZN8gameloft2ai4swatE) }
    .module_startup_game_object_manager_storage_8 0x004b8910 (NOLOAD) : { *game-object-manager.o(.bss._ZN8gameloft2ai11civ_vehicleE) }
    .module_startup_game_object_manager_storage_9 0x004b8918 (NOLOAD) : { *game-object-manager.o(.bss._ZN8gameloft2ai11cop_vehicleE) }
    .module_startup_game_object_manager_storage_10 0x004b8920 (NOLOAD) : { *game-object-manager.o(.bss._ZN8gameloft2ai5guardE) }
    .module_startup_game_object_manager_storage_11 0x004b8928 (NOLOAD) : { *game-object-manager.o(.bss._ZN8gameloft2ai16scripted_vehicleE) }

.module_startup_path_name_function_0 0x002d2624 : { *path-name.o(.text.__tcf_4) }
    .module_startup_path_name_function_1 0x002d2840 : { *path-name.o(.text._Z41__static_initialization_and_destruction_0ii) }
    .module_startup_path_name_function_2 0x002d2984 : { *path-name.o(.text._GLOBAL__I_mouseLButtHeld) }
    .module_startup_path_name_storage_0 0x004b66a0 (NOLOAD) : { *path-name.o(.bss._ZN3irr5scene6quake315irrEmptyStringcE) }
    .module_startup_path_name_storage_1 0x004b66c0 (NOLOAD) : { *path-name.o(.bss._ZN3irr2ps5vHalfE) }
    .module_startup_path_name_storage_2 0x004b66cc (NOLOAD) : { *path-name.o(.bss._ZN8gameloft2ai11civ_passiveE) }
    .module_startup_path_name_storage_3 0x004b66d4 (NOLOAD) : { *path-name.o(.bss._ZN8gameloft2ai12npc_scriptedE) }
    .module_startup_path_name_storage_4 0x004b66dc (NOLOAD) : { *path-name.o(.bss._ZN8gameloft2ai13civ_agressiveE) }
    .module_startup_path_name_storage_5 0x004b66e4 (NOLOAD) : { *path-name.o(.bss._ZN8gameloft2ai11gang_memberE) }
    .module_startup_path_name_storage_6 0x004b66ec (NOLOAD) : { *path-name.o(.bss._ZN8gameloft2ai3copE) }
    .module_startup_path_name_storage_7 0x004b66f4 (NOLOAD) : { *path-name.o(.bss._ZN8gameloft2ai4swatE) }
    .module_startup_path_name_storage_8 0x004b66fc (NOLOAD) : { *path-name.o(.bss._ZN8gameloft2ai11civ_vehicleE) }
    .module_startup_path_name_storage_9 0x004b6704 (NOLOAD) : { *path-name.o(.bss._ZN8gameloft2ai11cop_vehicleE) }
    .module_startup_path_name_storage_10 0x004b670c (NOLOAD) : { *path-name.o(.bss._ZN8gameloft2ai5guardE) }
    .module_startup_path_name_storage_11 0x004b6714 (NOLOAD) : { *path-name.o(.bss._ZN8gameloft2ai16scripted_vehicleE) }

    .shared_startup_empty_text 0x0044d91c : { *(.gnu.linkonce.r.localStartupEmptyText) }
    .gs3d_startup_function_0 0x002dd090 : { *gs3d-stuff.o(.text.__tcf_9) }
    .gs3d_startup_function_1 0x002dcec4 : { *gs3d-stuff.o(.text._Z41__static_initialization_and_destruction_0ii) }
    .gs3d_startup_function_2 0x002dd034 : { *gs3d-stuff.o(.text._GLOBAL__I__ZN9GS3DStuff15s_bulletManagerE) }
    .gs3d_startup_function_3 0x002df604 : { *gs3d-stuff.o(.text.__tcf_10) }
    .gs3d_startup_storage_0 0x004b69f0 (NOLOAD) : { *gs3d-stuff.o(.bss._ZN3irr5scene6quake315irrEmptyStringcE) }
    .gs3d_startup_storage_1 0x004b6a10 (NOLOAD) : { *gs3d-stuff.o(.bss._ZN8gameloft2ai11civ_passiveE) }
    .gs3d_startup_storage_2 0x004b6a18 (NOLOAD) : { *gs3d-stuff.o(.bss._ZN8gameloft2ai12npc_scriptedE) }
    .gs3d_startup_storage_3 0x004b6a20 (NOLOAD) : { *gs3d-stuff.o(.bss._ZN8gameloft2ai13civ_agressiveE) }
    .gs3d_startup_storage_4 0x004b6a28 (NOLOAD) : { *gs3d-stuff.o(.bss._ZN8gameloft2ai11gang_memberE) }
    .gs3d_startup_storage_5 0x004b6a30 (NOLOAD) : { *gs3d-stuff.o(.bss._ZN8gameloft2ai3copE) }
    .gs3d_startup_storage_6 0x004b6a38 (NOLOAD) : { *gs3d-stuff.o(.bss._ZN8gameloft2ai4swatE) }
    .gs3d_startup_storage_7 0x004b6a40 (NOLOAD) : { *gs3d-stuff.o(.bss._ZN8gameloft2ai11civ_vehicleE) }
    .gs3d_startup_storage_8 0x004b6a48 (NOLOAD) : { *gs3d-stuff.o(.bss._ZN8gameloft2ai11cop_vehicleE) }
    .gs3d_startup_storage_9 0x004b6a50 (NOLOAD) : { *gs3d-stuff.o(.bss._ZN8gameloft2ai5guardE) }
    .gs3d_startup_storage_10 0x004b6a58 (NOLOAD) : { *gs3d-stuff.o(.bss._ZN8gameloft2ai16scripted_vehicleE) }
    .gs3d_startup_storage_11 0x004b6a60 (NOLOAD) : { *gs3d-stuff.o(.bss._ZN3irr2ps5vHalfE) }
    .gs3d_startup_storage_12 0x004b69a0 (NOLOAD) : { *gs3d-stuff.o(.bss._ZN9GS3DStuff11lightsNodesE) }
}
ASSERT(SIZEOF(.module_startup_game_object_manager_storage_0) == 32, "game-object-manager _ZN3irr5scene6quake315irrEmptyStringcE extent");
ASSERT(SIZEOF(.module_startup_game_object_manager_storage_1) == 12, "game-object-manager _ZN3irr2ps5vHalfE extent");
ASSERT(SIZEOF(.module_startup_game_object_manager_storage_2) == 8, "game-object-manager _ZN8gameloft2ai11civ_passiveE extent");
ASSERT(SIZEOF(.module_startup_game_object_manager_storage_3) == 8, "game-object-manager _ZN8gameloft2ai12npc_scriptedE extent");
ASSERT(SIZEOF(.module_startup_game_object_manager_storage_4) == 8, "game-object-manager _ZN8gameloft2ai13civ_agressiveE extent");
ASSERT(SIZEOF(.module_startup_game_object_manager_storage_5) == 8, "game-object-manager _ZN8gameloft2ai11gang_memberE extent");
ASSERT(SIZEOF(.module_startup_game_object_manager_storage_6) == 8, "game-object-manager _ZN8gameloft2ai3copE extent");
ASSERT(SIZEOF(.module_startup_game_object_manager_storage_7) == 8, "game-object-manager _ZN8gameloft2ai4swatE extent");
ASSERT(SIZEOF(.module_startup_game_object_manager_storage_8) == 8, "game-object-manager _ZN8gameloft2ai11civ_vehicleE extent");
ASSERT(SIZEOF(.module_startup_game_object_manager_storage_9) == 8, "game-object-manager _ZN8gameloft2ai11cop_vehicleE extent");
ASSERT(SIZEOF(.module_startup_game_object_manager_storage_10) == 8, "game-object-manager _ZN8gameloft2ai5guardE extent");
ASSERT(SIZEOF(.module_startup_game_object_manager_storage_11) == 8, "game-object-manager _ZN8gameloft2ai16scripted_vehicleE extent");
ASSERT(SIZEOF(.module_startup_path_name_storage_0) == 32, "path-name _ZN3irr5scene6quake315irrEmptyStringcE extent");
ASSERT(SIZEOF(.module_startup_path_name_storage_1) == 12, "path-name _ZN3irr2ps5vHalfE extent");
ASSERT(SIZEOF(.module_startup_path_name_storage_2) == 8, "path-name _ZN8gameloft2ai11civ_passiveE extent");
ASSERT(SIZEOF(.module_startup_path_name_storage_3) == 8, "path-name _ZN8gameloft2ai12npc_scriptedE extent");
ASSERT(SIZEOF(.module_startup_path_name_storage_4) == 8, "path-name _ZN8gameloft2ai13civ_agressiveE extent");
ASSERT(SIZEOF(.module_startup_path_name_storage_5) == 8, "path-name _ZN8gameloft2ai11gang_memberE extent");
ASSERT(SIZEOF(.module_startup_path_name_storage_6) == 8, "path-name _ZN8gameloft2ai3copE extent");
ASSERT(SIZEOF(.module_startup_path_name_storage_7) == 8, "path-name _ZN8gameloft2ai4swatE extent");
ASSERT(SIZEOF(.module_startup_path_name_storage_8) == 8, "path-name _ZN8gameloft2ai11civ_vehicleE extent");
ASSERT(SIZEOF(.module_startup_path_name_storage_9) == 8, "path-name _ZN8gameloft2ai11cop_vehicleE extent");
ASSERT(SIZEOF(.module_startup_path_name_storage_10) == 8, "path-name _ZN8gameloft2ai5guardE extent");
ASSERT(SIZEOF(.module_startup_path_name_storage_11) == 8, "path-name _ZN8gameloft2ai16scripted_vehicleE extent");
ASSERT(SIZEOF(.gs3d_startup_storage_0) == 32, "GS3DStuff _ZN3irr5scene6quake315irrEmptyStringcE extent");
ASSERT(SIZEOF(.gs3d_startup_storage_1) == 8, "GS3DStuff _ZN8gameloft2ai11civ_passiveE extent");
ASSERT(SIZEOF(.gs3d_startup_storage_2) == 8, "GS3DStuff _ZN8gameloft2ai12npc_scriptedE extent");
ASSERT(SIZEOF(.gs3d_startup_storage_3) == 8, "GS3DStuff _ZN8gameloft2ai13civ_agressiveE extent");
ASSERT(SIZEOF(.gs3d_startup_storage_4) == 8, "GS3DStuff _ZN8gameloft2ai11gang_memberE extent");
ASSERT(SIZEOF(.gs3d_startup_storage_5) == 8, "GS3DStuff _ZN8gameloft2ai3copE extent");
ASSERT(SIZEOF(.gs3d_startup_storage_6) == 8, "GS3DStuff _ZN8gameloft2ai4swatE extent");
ASSERT(SIZEOF(.gs3d_startup_storage_7) == 8, "GS3DStuff _ZN8gameloft2ai11civ_vehicleE extent");
ASSERT(SIZEOF(.gs3d_startup_storage_8) == 8, "GS3DStuff _ZN8gameloft2ai11cop_vehicleE extent");
ASSERT(SIZEOF(.gs3d_startup_storage_9) == 8, "GS3DStuff _ZN8gameloft2ai5guardE extent");
ASSERT(SIZEOF(.gs3d_startup_storage_10) == 8, "GS3DStuff _ZN8gameloft2ai16scripted_vehicleE extent");
ASSERT(SIZEOF(.gs3d_startup_storage_11) == 12, "GS3DStuff _ZN3irr2ps5vHalfE extent");
ASSERT(SIZEOF(.gs3d_startup_storage_12) == 20, "GS3DStuff _ZN9GS3DStuff11lightsNodesE extent");
