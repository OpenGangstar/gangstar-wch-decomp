OUTPUT_FORMAT("elf32-littlearm")
OUTPUT_ARCH(arm)
ENTRY(_ZN4Item24resetAchievementCountersEv)
INCLUDE build/matches/item/retail-symbols.ld
memset = 0x001c45d4;
__aeabi_fmul = 0x001c4724;
__aeabi_i2f = 0x001c41e4;
_ZdaPv = 0x001c461c;
strlen = 0x001c48bc;
strcpy = 0x001c3fd4;
_Znaj = 0x001c3ff8;
_ZdlPv = 0x001c42b0;
_Znwj = 0x001c4814;
__cxa_guard_acquire = 0x001c4958;
__cxa_guard_release = 0x001c46c4;
__aeabi_atexit = 0x001c494c;
strstr = 0x001c446c;
strchr = 0x001c48e0;
memcpy = 0x001c4190;
atoi = 0x001c4880;
__stack_chk_fail = 0x001c42e0;
__cxa_pure_virtual = 0;
printf = 0x001c4058;
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
__aeabi_f2d = 0x001c48f8;
sqrt = 0x001c401c;
__aeabi_d2f = 0x001c4310;
__aeabi_fcmple = 0x001c43ac;
__aeabi_fdiv = 0x001c4520;
__aeabi_fcmpgt = 0x001c419c;
__aeabi_fcmpeq = 0x001c470c;
__aeabi_fcmplt = 0x001c479c;
_ZN23retail_item_transitions16civPassive_transE = 0x0041d2f0;
_ZN23retail_item_transitions17scriptedNpc_transE = 0x0041d41c;
_ZN23retail_item_transitions19civAggressive_transE = 0x0041d44c;
_ZN23retail_item_transitions16gangMember_transE = 0x0041d530;
_ZN23retail_item_transitions9cop_transE = 0x0041d53c;
_ZN23retail_item_transitions10swat_transE = 0x0041d674;
_ZN23retail_item_transitions17civ_vehicle_transE = 0x0041d680;
_ZN23retail_item_transitions17cop_vehicle_transE = 0x0041d710;
_ZN23retail_item_transitions11guard_transE = 0x0041d7c4;
_ZN23retail_item_transitions22scripted_vehicle_transE = 0x0041d86c;
s_billboardFactory = ADDR(.item_factory_storage);
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
    .level_base_type 0x002f74d0 : { *level-object.o(.text._ZN11LevelObject12getSpawnTypeEv .gnu.linkonce.t._ZN11LevelObject12getSpawnTypeEv) }
    .level_sight 0x00317380 : { *level-object.o(.text._ZN11LevelObject17canSeeLevelObjectEPS_RN3irr4core8vector3dIfEE) }
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
    .datadestructor 0x002d3654 : { *data-stream.o(.text._ZN10DataStreamD1Ev .gnu.linkonce.t._ZN10DataStreamD1Ev) }
    .datatext 0x0034e7b0 : {
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
    .datavtable 0x004ad638 : { *data-stream.o(.data.rel.ro) }
    .streamtext 0x0034efe4 : {
        *stream.o(.text._ZN6StreamC1Ev .text._ZN6StreamC2Ev)
        *stream.o(.text._ZN6Stream5CloseEv)
        *stream.o(.text._ZN6Stream4ReadEv)
        *stream.o(.text._ZN6Stream5WriteEc)
        *stream.o(.text._ZN6Stream5WriteERS_i)
        *stream.o(.text._ZN6Stream4PeekEPvi)
        *stream.o(.text._ZN6StreamD0Ev .gnu.linkonce.t._ZN6StreamD0Ev)
        *stream.o(.text._ZN6StreamD1Ev .text._ZN6StreamD2Ev .gnu.linkonce.t._ZN6StreamD1Ev .gnu.linkonce.t._ZN6StreamD2Ev)
    }
    .streamvtable 0x004ad6c8 : { *stream.o(.data.rel.ro) }
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
    .level_highlight_load 0x00316a84 : { *level-object.o(.text._ZN11LevelObject14loadHighlightsEPKc) }
    .level_factory_cleanup 0x003168e4 : { *level-object.o(.text.__tcf_0) }

    .level_setup 0x003167e0 : { *level-object.o(.text._ZN11LevelObject5setupEv) }

    .level_destructor_delete 0x00317240 : { *level-object.o(.text._ZN11LevelObjectD0Ev) }
    .level_destructor 0x003172e4 : { *level-object.o(.text._ZN11LevelObjectD1Ev .text._ZN11LevelObjectD2Ev) }
    .level_highlight_free 0x00316908 : { *level-object.o(.text._ZN11LevelObject14freeHighlightsEv) }

    .level_name 0x00316940 : { *level-object.o(.text._ZN11LevelObject7SetNameEPKc) }
    .level_metatype 0x00316a50 : { *level-object.o(.text._ZN11LevelObject11GetMetatypeEv) }

    .level_load 0x00316fec : { *level-object.o(.text._ZN11LevelObject4LoadERKN7Structs15GameObjectBasicEPN3irr7collada15CColladaFactoryE) }

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
    .item_reset 0x002fc100 : { *item.o(.text._ZN4Item24resetAchievementCountersEv) }
    .item_debug 0x002fc120 : { *item.o(.text._ZN4Item5debugEPN3irr5video12IVideoDriverE) }
    .item_unlock 0x002fc124 : { *item.o(.text._ZN4Item6unlockEv) }
    .item_unlocked 0x002fc12c : { *item.o(.text._ZNK4Item8unlockedEv) }
    .item_id 0x002fc140 : { *item.o(.text._ZNK4Item5getIdEv) }
    .item_health 0x004b7f70 : { *item.o(.bss._ZN4Item16s_numHealthCrateE) }
    .item_armor 0x004b7f74 : { *item.o(.bss._ZN4Item14s_numArmorVestE) }
    .item_position 0x002fc298 : { *item.o(.text._ZN4Item11SetPositionERKN3irr4core8vector3dIfEE) }
    .item_warmup 0x002fc2b0 : { *item.o(.text._ZN4Item6WarmUpEv) }
    .item_drop 0x002fc370 : { *item.o(.text._ZN4Item13dropSceneNodeEv) }
    .item_delete 0x002fc39c : { *item.o(.text._ZN4ItemD0Ev) }
    .item_destructor 0x002fc3c4 : { *item.o(.text._ZN4ItemD1Ev .text._ZN4ItemD2Ev) }
    .item_constructor 0x002fc3e4 : { *item.o(.text._ZN4ItemC1Ei .text._ZN4ItemC2Ei) }
    .item_billboard_create 0x002fc25c : { *item.o(.text._ZN21CGameBillboardFactory11createSceneERKN3irr7collada16CColladaDatabaseE .gnu.linkonce.t._ZN21CGameBillboardFactory11createSceneERKN3irr7collada16CColladaDatabaseE) }
    .item_billboard_delete 0x002fce60 : { *item.o(.text._ZN21CGameBillboardFactoryD0Ev .gnu.linkonce.t._ZN21CGameBillboardFactoryD0Ev) }
    .item_billboard_destructor 0x002fceb0 : { *item.o(.text._ZN21CGameBillboardFactoryD1Ev .text._ZN21CGameBillboardFactoryD2Ev .gnu.linkonce.t._ZN21CGameBillboardFactoryD1Ev .gnu.linkonce.t._ZN21CGameBillboardFactoryD2Ev) }
    .item_billboard_vtable 0x004aad20 : { *item.o(.data.rel.ro._ZTV21CGameBillboardFactory .gnu.linkonce.d.rel.ro._ZTV21CGameBillboardFactory) }
    .item_placed_array 0x004b7f78 (NOLOAD) : { *item.o(.bss._ZN4Item13s_placedItemsE) }
    .item_startup_string 0x004b7f8c (NOLOAD) : { *item.o(.bss._ZN3irr5scene6quake315irrEmptyStringcE) }
    .item_startup_half 0x004b7fac (NOLOAD) : { *item.o(.bss._ZN3irr2ps5vHalfE) }
    .item_factory_storage 0x004b8008 (NOLOAD) : { *item.o(.bss.s_billboardFactoryStorage) }
    .item_startup_record_0 0x004b7fb8 (NOLOAD) : { *item.o(.bss._ZN8gameloft2ai11civ_passiveE) }
    .item_startup_record_1 0x004b7fc0 (NOLOAD) : { *item.o(.bss._ZN8gameloft2ai12npc_scriptedE) }
    .item_startup_record_2 0x004b7fc8 (NOLOAD) : { *item.o(.bss._ZN8gameloft2ai13civ_agressiveE) }
    .item_startup_record_3 0x004b7fd0 (NOLOAD) : { *item.o(.bss._ZN8gameloft2ai11gang_memberE) }
    .item_startup_record_4 0x004b7fd8 (NOLOAD) : { *item.o(.bss._ZN8gameloft2ai3copE) }
    .item_startup_record_5 0x004b7fe0 (NOLOAD) : { *item.o(.bss._ZN8gameloft2ai4swatE) }
    .item_startup_record_6 0x004b7fe8 (NOLOAD) : { *item.o(.bss._ZN8gameloft2ai11civ_vehicleE) }
    .item_startup_record_7 0x004b7ff0 (NOLOAD) : { *item.o(.bss._ZN8gameloft2ai11cop_vehicleE) }
    .item_startup_record_8 0x004b7ff8 (NOLOAD) : { *item.o(.bss._ZN8gameloft2ai5guardE) }
    .item_startup_record_9 0x004b8000 (NOLOAD) : { *item.o(.bss._ZN8gameloft2ai16scripted_vehicleE) }
    .item_string_cleanup 0x002fc22c : { *item.o(.text.__tcf_4) }
    .item_factory_cleanup 0x002fced4 : { *item.o(.text.__tcf_5) }
    .item_array_cleanup 0x002fc144 : { *item.o(.text.__tcf_6) }
    .item_startup 0x002fccb8 : { *item.o(.text._Z41__static_initialization_and_destruction_0ii) }
    .item_startup_wrapper 0x002fce4c : { *item.o(.text._GLOBAL__I__ZN4Item16s_numHealthCrateE) }
    .item_setup_node 0x002fc2e4 : { *item.o(.text._ZN4Item14setupSceneNodeEiPN3irr5scene10ISceneNodeEiPPv) }
    .item_collectible_glow 0x0041d1f0 : { *item.o(.rodata.item_collectible_glow) }
    .item_badge_glow 0x0041d20c : { *item.o(.rodata.item_badge_glow) }
    .item_badge_scene 0x0041d224 : { *item.o(.rodata.item_badge_scene) }
    .item_collectible_scene 0x0041d238 : { *item.o(.rodata.item_collectible_scene) }
    .item_remove_placed 0x002fc424 : { *item.o(.text._ZN4Item20removeAllPlacedItemsEv) }
    .item_place 0x002fc5d0 : { *item.o(.text._ZN4Item5placeEiN3irr4core8vector3dIfEE) }
    .item_place_switch 0x0041d278 : { *item.o(.rodata._ZN4Item5placeEiN3irr4core8vector3dIfEE) }
    .item_spawn_drop 0x002fc850 : { *item.o(.text._ZN4Item4dropEiN3irr4core8vector3dIfEEi) }
    .item_hide 0x002fc518 : { *item.o(.text._ZN4Item4hideEv) }
    .item_show 0x002fc56c : { *item.o(.text._ZN4Item4showEv) }
    .item_lock 0x002fc67c : { *item.o(.text._ZN4Item4lockEv) }
    .item_load 0x002fc6bc : { *item.o(.text._ZN4Item4LoadERKN7Structs4ItemE) }
    .item_grab 0x002fcbdc : { *item.o(.text._ZN4Item13grabSceneNodeEiPPPv) }
    .item_vtable 0x004aac78 : { *item.o(.data.rel.ro._ZTV4Item) }
    .item_add_ammo 0x002fc908 : { *item.o(.text._ZN4Item7addAmmoEii) }
    .item_pickup 0x002fcff8 : { *item.o(.text._ZN4Item6pickupEv) }
    .item_sound 0x002fcef8 : { *item.o(.text._ZN4Item15playPickupSoundEv) }
    .item_sound_switch 0x0041d2c8 : { *item.o(.rodata._ZN4Item15playPickupSoundEv) }
    .item_update 0x002fc748 : { *item.o(.text._ZN4Item6UpdateEi) }
    .item_animate 0x002fcb9c : { *item.o(.text._ZN4Item7animateEbbb) }
    .item_add_weapon 0x002fc940 : { *item.o(.text._ZN4Item9addWeaponEi) }
    .item_usable 0x002fc494 : { *item.o(.text._ZN4Item8isUsableEv) }
    .item_usable_switch 0x0041d250 : { *item.o(.rodata._ZN4Item8isUsableEv) }
    .item_add 0x002fca3c : { *item.o(.text._ZN4Item3addEv) }
    .item_add_switch 0x0041d2a0 : { *item.o(.rodata._ZN4Item3addEv) }
    .got 0x004b0048 : { *(.got.plt) . = 0x360; *(.got) }
    .verification 0x00600000 : { *retail-got.o(.text) }
    /* Local callback numbering differs in this partial translation unit. */
    .item_factory_singleton_cleanup 0x002fce8c : { *item.o(.text.__tcf_0) }
    .item_wanted_singleton_cleanup 0x002fc27c : { *item.o(.text.__tcf_2) }
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
