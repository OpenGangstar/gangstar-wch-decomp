OUTPUT_FORMAT("elf32-littlearm")
OUTPUT_ARCH(arm)
__aeabi_idiv = 0x001c43dc;
INCLUDE build/matches/ai-startup-playertest/retail-symbols.ld
_ZdlPv = 0x001c42b0;
__aeabi_atexit = 0x001c494c;
_ZN29retail_playertest_transitions16civPassive_transE = 0x0041e340;
_ZN29retail_playertest_transitions17scriptedNpc_transE = 0x0041e46c;
_ZN29retail_playertest_transitions19civAggressive_transE = 0x0041e49c;
_ZN29retail_playertest_transitions16gangMember_transE = 0x0041e580;
_ZN29retail_playertest_transitions9cop_transE = 0x0041e58c;
_ZN29retail_playertest_transitions10swat_transE = 0x0041e6c4;
_ZN29retail_playertest_transitions17civ_vehicle_transE = 0x0041e6d0;
_ZN29retail_playertest_transitions17cop_vehicle_transE = 0x0041e760;
_ZN29retail_playertest_transitions11guard_transE = 0x0041e814;
_ZN29retail_playertest_transitions22scripted_vehicle_transE = 0x0041e8bc;
__cxa_guard_acquire = 0x001c4958;
__cxa_guard_release = 0x001c46c4;
memset = 0x001c45d4;
memcpy = 0x001c4190;
__aeabi_fdiv = 0x001c4520;
INCLUDE config/linker/CharacterStateSections.ld
INCLUDE config/linker/CHudManagerWeaponSections.ld
INCLUDE config/linker/NPCTargetEventSections.ld
_ZdlPv = 0x001c42b0;
SECTIONS
{
    .player_just_stole_car 0x00301758 : { *ai-startup-playertest.o(.text._ZN10PlayerTest12justStoleCarEP7Vehicle) }
    .player_jump_finished 0x003017ec : { *ai-startup-playertest.o(.text._ZN10PlayerTest12jumpFinishedEv) }
    .player_drift_finished 0x00301820 : { *ai-startup-playertest.o(.text._ZN10PlayerTest13driftFinishedEv) }
    .player_stop 0x00301a3c : { *ai-startup-playertest.o(.text._ZN10PlayerTest4StopEv) }
    .player_closest_shop 0x00301090 : { *ai-startup-playertest.o(.text._ZN10PlayerTest14setClosestShopEP4Shop) }
    .npc_vehicle_base_delete 0x002d4074 : { *(.gnu.linkonce.t._ZN6IEventD0Ev) }
    .npc_vehicle_base_dtor 0x002d4094 : { *(.gnu.linkonce.t._ZN6IEventD1Ev) }
    .npc_vehicle_base_id 0x002d3c34 : { *(.gnu.linkonce.t._ZNK6IEvent10getEventIDEv) }
    .npc_vehicle_base_vtable 0x004a6198 : { *(.gnu.linkonce.d.rel.ro._ZTV6IEvent) }
    .npc_vehicle_event_delete 0x00303a68 : { *(.gnu.linkonce.t._ZN12EvNPCVehicleD0Ev .text._ZN12EvNPCVehicleD0Ev) }
    .npc_vehicle_event_dtor 0x00303a94 : { *(.gnu.linkonce.t._ZN12EvNPCVehicleD1Ev .text._ZN12EvNPCVehicleD1Ev) }
    .npc_vehicle_event_vtable 0x004ab060 : { *(.gnu.linkonce.d.rel.ro._ZTV12EvNPCVehicle .data.rel.ro._ZTV12EvNPCVehicle) }
    .player_get_player 0x00300dc8 : { *ai-startup-playertest.o(.text._ZN10PlayerTest9GetPlayerEv) }
    .player_singleton 0x004b80e8 (NOLOAD) : { *ai-startup-playertest.o(.bss._ZN10PlayerTest8s_playerE) }
    .ai_manager_singleton 0x002dbae8 : { *ai-startup-character.o(.gnu.linkonce.t._ZN9AIManager11getInstanceEv) }
    .ai_manager_cleanup 0x002f1a14 : { *ai-startup-character.o(.text.__tcf_0) }
    .ai_manager_guard 0x004b6a90 (NOLOAD) : { *ai-startup-character.o(.gnu.linkonce.b._ZGVZN9AIManager11getInstanceEvE3aim) }
    .ai_manager_instance 0x004b6ae8 (NOLOAD) : { *ai-startup-character.o(.gnu.linkonce.b._ZZN9AIManager11getInstanceEvE3aim) }
    .player_lock_weapon_switch 0x00300e6c : { *ai-startup-playertest.o(.text._ZN10PlayerTest16lockSwitchWeaponEv) }
    .player_get_target 0x00300db8 : { *ai-startup-playertest.o(.text._ZN10PlayerTest10_GetTargetEv) }
    .player_marker_type 0x00300d7c : { *ai-startup-playertest.o(.text._ZN10PlayerTest13getMarkerTypeEv) }
    .player_hide_mesh 0x00300d84 : { *ai-startup-playertest.o(.text._ZN10PlayerTest8hideMeshEv) }
    .player_show_mesh 0x00301594 : { *ai-startup-playertest.o(.text._ZN10PlayerTest8showMeshEv) }
    .player_toggle_lock 0x00301358 : { *ai-startup-playertest.o(.text._ZN10PlayerTest10toggleLockEv) }
    .player_target_cancelled 0x00301568 : { *ai-startup-playertest.o(.text._ZN10PlayerTest17onTargetCancelledEv) }
    .player_resume_attacking 0x003015b8 : { *ai-startup-playertest.o(.text._ZN10PlayerTest15resumeAttackingEv) }
    .player_get_vehicle_thunk 0x0030121c : { *ai-startup-playertest.o(.text._ZThn4_NK10PlayerTest10getVehicleEv) }
    .player_get_vehicle 0x00301230 : { *ai-startup-playertest.o(.text._ZNK10PlayerTest10getVehicleEv) }
    .player_get_weapon_thunk 0x00301730 : { *ai-startup-playertest.o(.text._ZThn4_NK10PlayerTest9getWeaponEv) }
    .player_get_weapon 0x00301744 : { *ai-startup-playertest.o(.text._ZNK10PlayerTest9getWeaponEv) }
    .player_run_thunk 0x003014d8 : { *ai-startup-playertest.o(.text._ZThn4_N10PlayerTest13runToLocationERKN3irr4core8vector3dIfEE) }
    .player_run 0x003014ec : { *ai-startup-playertest.o(.text._ZN10PlayerTest13runToLocationERKN3irr4core8vector3dIfEE) }
    .player_walk_thunk 0x00301520 : { *ai-startup-playertest.o(.text._ZThn4_N10PlayerTest14walkToLocationERKN3irr4core8vector3dIfEE) }
    .player_walk 0x00301534 : { *ai-startup-playertest.o(.text._ZN10PlayerTest14walkToLocationERKN3irr4core8vector3dIfEE) }
    .player_hide_anims 0x00300da4 : { *ai-startup-playertest.o(.text._ZN10PlayerTest12hideAllAnimsEv) }
    .player_restart_anim 0x003010d4 : { *ai-startup-playertest.o(.text._ZN10PlayerTest20playCurAnimFromStartEv) }
    .player_add_cash 0x00301388 : { *ai-startup-playertest.o(.text._ZN10PlayerTest7addCashEii) }
    .player_sub_cash 0x0030189c : { *ai-startup-playertest.o(.text._ZN10PlayerTest7subCashEi) }
    .player_set_cash 0x00300dec : { *ai-startup-playertest.o(.text._ZN10PlayerTest7setCashEi) }
    .player_ambient_sound 0x00300e0c : { *ai-startup-playertest.o(.text._ZNK10PlayerTest15getAmbientSoundEv) }
    .player_drift_distance 0x00300e2c : { *ai-startup-playertest.o(.text._ZN10PlayerTest23addCurrentDriftDistanceEf) }
    .player_jump_distance 0x00300e4c : { *ai-startup-playertest.o(.text._ZN10PlayerTest22addCurrentJumpDistanceEf) }
    .player_add_photo_target 0x00300f48 : { *ai-startup-playertest.o(.text._ZN10PlayerTest14addPhotoTargetEP11LevelObject) }
    .player_clear_photo_targets 0x00301060 : { *ai-startup-playertest.o(.text._ZN10PlayerTest17clearPhotoTargetsEv) }
    .player_init_move_to 0x00300dc0 : { *ai-startup-playertest.o(.text._ZN10PlayerTest10initMoveToEPK7Vehicle) }
    .player_set_rich_as_croesus 0x00300ddc : { *ai-startup-playertest.o(.text._ZN10PlayerTest13richAsCroesusEb) }
    .player_get_rich_as_croesus 0x00300de4 : { *ai-startup-playertest.o(.text._ZNK10PlayerTest15isRichAsCroesusEv) }
    .player_unlock_weapon_switch 0x00300e78 : { *ai-startup-playertest.o(.text._ZN10PlayerTest18unlockSwitchWeaponEv) }
    .player_switch_weapon 0x003016b4 : { *ai-startup-playertest.o(.text._ZN10PlayerTest12switchWeaponEb) }
    .wanted_singleton 0x002dba04 : { *ai-startup-playertest.o(.gnu.linkonce.t._ZN18WantedLevelManager11getInstanceEv) }
    .wanted_cleanup 0x003010b8 : { *ai-startup-playertest.o(.text.__tcf_1) }
    .wanted_guard 0x004b6728 (NOLOAD) : { *ai-startup-playertest.o(.gnu.linkonce.b._ZGVZN18WantedLevelManager11getInstanceEvE3wlm) }
    .wanted_instance 0x004b6a98 (NOLOAD) : { *ai-startup-playertest.o(.gnu.linkonce.b._ZZN18WantedLevelManager11getInstanceEvE3wlm) }
    .map_singleton 0x002dbb58 : { *ai-startup-playertest.o(.gnu.linkonce.t._ZN3Map11getInstanceEv) }
    .map_cleanup 0x3010e4 : { *ai-startup-playertest.o(.text.__tcf_0) }
    .map_guard 0x004b6a94 (NOLOAD) : { *ai-startup-playertest.o(.gnu.linkonce.b._ZGVZN3Map11getInstanceEvE3map) }
    .map_instance 0x004b6b00 (NOLOAD) : { *ai-startup-playertest.o(.gnu.linkonce.b._ZZN3Map11getInstanceEvE3map) }
    .ai_startup_function_0 0x00301030 : { *ai-startup-playertest.o(.text.__tcf_5) }
    .ai_startup_function_1 0x00301f98 : { *ai-startup-playertest.o(.text._Z41__static_initialization_and_destruction_0ii) }
    .ai_startup_function_2 0x003020dc : { *ai-startup-playertest.o(.text._GLOBAL__I__ZN10PlayerTest10switchAnimEv) }
    .ai_startup_storage_0 0x004b80ec (NOLOAD) : { *ai-startup-playertest.o(.bss._ZN3irr5scene6quake315irrEmptyStringcE) }
    .ai_startup_storage_1 0x004b810c (NOLOAD) : { *ai-startup-playertest.o(.bss._ZN3irr2ps5vHalfE) }
    .ai_startup_storage_2 0x004b8118 (NOLOAD) : { *ai-startup-playertest.o(.bss._ZN8gameloft2ai11civ_passiveE) }
    .ai_startup_storage_3 0x004b8120 (NOLOAD) : { *ai-startup-playertest.o(.bss._ZN8gameloft2ai12npc_scriptedE) }
    .ai_startup_storage_4 0x004b8128 (NOLOAD) : { *ai-startup-playertest.o(.bss._ZN8gameloft2ai13civ_agressiveE) }
    .ai_startup_storage_5 0x004b8130 (NOLOAD) : { *ai-startup-playertest.o(.bss._ZN8gameloft2ai11gang_memberE) }
    .ai_startup_storage_6 0x004b8138 (NOLOAD) : { *ai-startup-playertest.o(.bss._ZN8gameloft2ai3copE) }
    .ai_startup_storage_7 0x004b8140 (NOLOAD) : { *ai-startup-playertest.o(.bss._ZN8gameloft2ai4swatE) }
    .ai_startup_storage_8 0x004b8148 (NOLOAD) : { *ai-startup-playertest.o(.bss._ZN8gameloft2ai11civ_vehicleE) }
    .ai_startup_storage_9 0x004b8150 (NOLOAD) : { *ai-startup-playertest.o(.bss._ZN8gameloft2ai11cop_vehicleE) }
    .ai_startup_storage_10 0x004b8158 (NOLOAD) : { *ai-startup-playertest.o(.bss._ZN8gameloft2ai5guardE) }
    .ai_startup_storage_11 0x004b8160 (NOLOAD) : { *ai-startup-playertest.o(.bss._ZN8gameloft2ai16scripted_vehicleE) }
    .shared_startup_empty_text 0x0044d91c : { *(.gnu.linkonce.r.localStartupEmptyText) }
    .got 0x004b0048 : { *(.got.plt) . = 0x360; *(.got) }
    .verification 0x00600000 : { *retail-got.o(.text) }
    /* Character's TU-local startup is verified in its own image. */
    /DISCARD/ : { *ai-startup-character.o(*) *ai-startup-physicattributes.o(*) }
    /* Only the HUD weapon entry points are needed in this image. */
    /DISCARD/ : { *hud-manager-helpers.o(*) }
    /DISCARD/ : { *ai-startup-npc.o(*) }
}
ASSERT(SIZEOF(.ai_startup_storage_0) == 32, "_ZN3irr5scene6quake315irrEmptyStringcE extent");
ASSERT(SIZEOF(.ai_startup_storage_1) == 12, "_ZN3irr2ps5vHalfE extent");
ASSERT(SIZEOF(.ai_startup_storage_2) == 8, "_ZN8gameloft2ai11civ_passiveE extent");
ASSERT(SIZEOF(.ai_startup_storage_3) == 8, "_ZN8gameloft2ai12npc_scriptedE extent");
ASSERT(SIZEOF(.ai_startup_storage_4) == 8, "_ZN8gameloft2ai13civ_agressiveE extent");
ASSERT(SIZEOF(.ai_startup_storage_5) == 8, "_ZN8gameloft2ai11gang_memberE extent");
ASSERT(SIZEOF(.ai_startup_storage_6) == 8, "_ZN8gameloft2ai3copE extent");
ASSERT(SIZEOF(.ai_startup_storage_7) == 8, "_ZN8gameloft2ai4swatE extent");
ASSERT(SIZEOF(.ai_startup_storage_8) == 8, "_ZN8gameloft2ai11civ_vehicleE extent");
ASSERT(SIZEOF(.ai_startup_storage_9) == 8, "_ZN8gameloft2ai11cop_vehicleE extent");
ASSERT(SIZEOF(.ai_startup_storage_10) == 8, "_ZN8gameloft2ai5guardE extent");
ASSERT(SIZEOF(.ai_startup_storage_11) == 8, "_ZN8gameloft2ai16scripted_vehicleE extent");
