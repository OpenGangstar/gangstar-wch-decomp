PROVIDE(__aeabi_i2f = 0x001c41e4);
/* ScriptManager queries and script registration at retail addresses. */
PROVIDE(_Znwj = 0x001c4814);
PROVIDE(__cxa_guard_acquire = 0x001c4958);
PROVIDE(__cxa_guard_release = 0x001c46c4);
PROVIDE(printf = 0x001c4058);
PROVIDE(strcmp = 0x001c4658);
PROVIDE(__stack_chk_fail = 0x001c42e0);
PROVIDE(_Znaj = 0x001c3ff8);
PROVIDE(_ZdaPv = 0x001c461c);
PROVIDE(memset = 0x001c45d4);
SECTIONS
{
    .script_manager_clean_command 0x0033ffc0 : { *script-manager-helpers.o(.text._ZN13ScriptManager12cleanCommandEPN7Structs13ScriptCommandE) }
    .script_manager_clean_command_table 0x0042f28c : { *script-manager-helpers.o(.rodata._ZN13ScriptManager12cleanCommandEPN7Structs13ScriptCommandE) }
    .script_manager_reach_running 0x0033d270 : { *script-manager-helpers.o(.text._ZN13ScriptManager19reachRunningCommandEi) }
    .script_check_screen_press 0x0033f4c8 : { *script-manager-helpers.o(.text._ZN13ScriptManager16checkScreenPressEv) }
    .script_load_command_table 0x0042f098 : { *script-manager-helpers.o(.rodata._ZN13ScriptManager11loadCommandER10DataStream) }
    .script_load_command_c172 0x0042fa34 : { *script-manager-helpers.o(.rodata._ZZN13ScriptManager11loadCommandER10DataStreamE5C.172) }
    .script_load_command_c168 0x0042fa44 : { *script-manager-helpers.o(.rodata._ZZN13ScriptManager11loadCommandER10DataStreamE5C.168) }
    .script_load_command_c149 0x0042fa54 : { *script-manager-helpers.o(.rodata._ZZN13ScriptManager11loadCommandER10DataStreamE5C.149) }
    .script_load_command_c106 0x0042fa64 : { *script-manager-helpers.o(.rodata._ZZN13ScriptManager11loadCommandER10DataStreamE5C.106) }
    .script_load_command_c137 0x0042fa74 : { *script-manager-helpers.o(.rodata._ZZN13ScriptManager11loadCommandER10DataStreamE5C.137) }
    .script_manager_load_command 0x0033ddd4 : { *script-manager-helpers.o(.text._ZN13ScriptManager11loadCommandER10DataStream) }
    ASSERT(SIZEOF(.script_manager_load_command) == 2436, "Native ScriptManager loadCommand extent")
    .script_entry_33ed94 0x0033ed94 : { *script-manager-helpers.o(.text._ZN13ScriptManager9resetGameEbi) }
    .script_entry_33f0f8 0x0033f0f8 : { *script-manager-helpers.o(.text._ZN13ScriptManager10moveObjectEP11LevelObjectS1_) }
    .script_entry_33ef8c 0x0033ef8c : { *script-manager-helpers.o(.text._ZN13ScriptManager10loadScriptEPKcb) }
    .script_entry_33fc00 0x0033fc00 : { *script-manager-helpers.o(.text._ZNK13ScriptManager26getAvailableMissionScriptsERSt6vectorIP6ScriptSaIS2_EE) }
    .script_load_data_stream_dtor 0x002d3654 : { *script-manager-helpers.o(.text._ZN10DataStreamD1Ev .gnu.linkonce.t._ZN10DataStreamD1Ev) }
    .script_entry_33d104 0x0033d104 : { *script-manager-helpers.o(.text._ZN13ScriptManager5pauseEv .gnu.linkonce.t._ZN13ScriptManager5pauseEv) }
    .script_entry_33d140 0x0033d140 : { *script-manager-helpers.o(.text._ZN13ScriptManager12playerDrivesEP7Vehicle .gnu.linkonce.t._ZN13ScriptManager12playerDrivesEP7Vehicle) }
    .script_entry_33d2f4 0x0033d2f4 : { *script-manager-helpers.o(.text._ZNK13ScriptManager8drawFadeEv .gnu.linkonce.t._ZNK13ScriptManager8drawFadeEv) }
    .script_entry_33e954 0x0033e954 : { *script-manager-helpers.o(.text._Z10SafeDeleteI6ScriptEvRPT_ .gnu.linkonce.t._Z10SafeDeleteI6ScriptEvRPT_) }
    .script_entry_33ea88 0x0033ea88 : { *script-manager-helpers.o(.text._ZN13ScriptManager5setupEv .gnu.linkonce.t._ZN13ScriptManager5setupEv) }
    .script_entry_33ec04 0x0033ec04 : { *script-manager-helpers.o(.text._ZN13ScriptManager20rewindRunningScriptsEv .gnu.linkonce.t._ZN13ScriptManager20rewindRunningScriptsEv) }
    .script_entry_33ed18 0x0033ed18 : { *script-manager-helpers.o(.text._ZN13ScriptManager10findObjectEPKcb .gnu.linkonce.t._ZN13ScriptManager10findObjectEPKcb) }
    .script_setup_intro 0x0042eff0 : { *script-manager-helpers.o(.rodata.script_setup_intro) }
    .script_setup_hud 0x0042f000 : { *script-manager-helpers.o(.rodata.script_setup_hud) }
    .script_setup_hud2 0x0042f01c : { *script-manager-helpers.o(.rodata.script_setup_hud2) }
    .script_setup_character 0x0042f038 : { *script-manager-helpers.o(.rodata.script_setup_character) }
    .script_find_player 0x0042f054 : { *script-manager-helpers.o(.rodata.script_find_player) }
    .script_find_me 0x0042f05c : { *script-manager-helpers.o(.rodata.script_find_me) }
    .script_find_warning 0x0042f060 : { *script-manager-helpers.o(.rodata.script_find_warning) }
    .verified_entry_33e9c0 0x0033e9c0 : { *script-manager-helpers.o(.text._ZN13ScriptManager20freezeRunningScriptsEPK6ScriptN10PlayerTest8eContextE) }
    .verified_entry_33ecc0 0x0033ecc0 : { *script-manager-helpers.o(.text._ZN13ScriptManager19unlockFrozenScriptsEv) }
    .script_manager_minimap_tracking 0x0033e974 : { *script-manager-helpers.o(.text._ZN13ScriptManager16displayOnMinimapEP11LevelObjectbb) }
    .script_manager_first_checkpoint 0x0033d1e0 : { *script-manager-helpers.o(.text._ZNK13ScriptManager27getFirstAvailableCheckpointEv) }
    .script_manager_save 0x0033e8fc : { *script-manager-helpers.o(.text._ZN13ScriptManager8saveGameEv) }
    .script_manager_load_missions 0x0033e91c : { *script-manager-helpers.o(.text._ZN13ScriptManager12loadMissionsEPKc) }
    .script_manager_load_save 0x0033ef24 : { *script-manager-helpers.o(.text._ZN13ScriptManager8loadGameEb) }
    .script_manager_load_animation 0x0042f08c : { *script-manager-helpers.o(.rodata.str1.4 .rodata.str1.1) }
    .script_manager_construct 0x0033cfb8 : { *script-manager-helpers.o(.text._ZN13ScriptManagerC1Ev .text._ZN13ScriptManagerC2Ev) }
    .script_manager_instance 0x0033d360 : { *script-manager-helpers.o(.text._ZN13ScriptManager11getInstanceEv) }
    .script_manager_instance_cleanup 0x0033e7d0 : { *script-manager-helpers.o(.text.__tcf_0) }
    .script_manager_instance_guard 0x004ba618 (NOLOAD) : { *script-manager-helpers.o(.bss._ZGVZN13ScriptManager11getInstanceEvE6scrmgr) }
    .script_manager_instance_storage 0x004ba61c (NOLOAD) : { *script-manager-helpers.o(.bss._ZZN13ScriptManager11getInstanceEvE6scrmgr) }
    .script_manager_delete_revive 0x0033e794 : { *script-manager-helpers.o(.gnu.linkonce.t._Z10SafeDeleteI6ReviveEvRPT_) }
    .script_manager_destroy 0x0033e7b4 : { *script-manager-helpers.o(.text._ZN13ScriptManagerD1Ev .text._ZN13ScriptManagerD2Ev) }
    .script_manager_respawn 0x0033e7ec : { *script-manager-helpers.o(.text._ZN13ScriptManager22respawnFromBustedOrDieEb) }
    .script_manager_tagged 0x0033cfec : { *script-manager-helpers.o(.text._ZN13ScriptManager12taggedKilledEv) }
    .script_manager_print 0x0033d004 : { *script-manager-helpers.o(.text._ZN13ScriptManager12printCommandERKN7Structs13ScriptCommandE) }
    .script_manager_add 0x0033d008 : { *script-manager-helpers.o(.text._ZN13ScriptManager9addScriptEP6Script) }
    .script_manager_find 0x0033d020 : { *script-manager-helpers.o(.text._ZNK13ScriptManager10findScriptEi) }
    .script_manager_blocking 0x0033d03c : { *script-manager-helpers.o(.text._ZNK13ScriptManager26areBlockingCommandsSkippedEv) }
    .script_manager_cinematic 0x0033d04c : { *script-manager-helpers.o(.text._ZNK13ScriptManager13isInCinematicEv) }
    .script_manager_skip_visible 0x0033d070 : { *script-manager-helpers.o(.text._ZNK13ScriptManager19isSkipButtonVisibleEv) }
    .script_manager_failure 0x0033d090 : { *script-manager-helpers.o(.text._ZN13ScriptManager15getFailureCauseEv) }
    .script_reader_WaitWantedLevel 0x0033d424 : { *script-manager-helpers.o(.gnu.linkonce.t._ZN7Structs15WaitWantedLevel4ReadER10DataStream) }
    .script_reader_WaitStolen 0x0033d440 : { *script-manager-helpers.o(.gnu.linkonce.t._ZN7Structs10WaitStolen4ReadER10DataStream) }
    .script_reader_WaitShot 0x0033d45c : { *script-manager-helpers.o(.gnu.linkonce.t._ZN7Structs8WaitShot4ReadER10DataStream) }
    .script_reader_WaitPathEnded 0x0033d478 : { *script-manager-helpers.o(.gnu.linkonce.t._ZN7Structs13WaitPathEnded4ReadER10DataStream) }
    .script_reader_WaitKilled 0x0033d494 : { *script-manager-helpers.o(.gnu.linkonce.t._ZN7Structs10WaitKilled4ReadER10DataStream) }
    .script_reader_WaitForStop 0x0033d4d4 : { *script-manager-helpers.o(.gnu.linkonce.t._ZN7Structs11WaitForStop4ReadER10DataStream) }
    .script_reader_WaitForLock 0x0033d4f0 : { *script-manager-helpers.o(.gnu.linkonce.t._ZN7Structs11WaitForLock4ReadER10DataStream) }
    .script_reader_WaitCheckpoint 0x0033d530 : { *script-manager-helpers.o(.gnu.linkonce.t._ZN7Structs14WaitCheckpoint4ReadER10DataStream) }
    .script_reader_Wait 0x0033d574 : { *script-manager-helpers.o(.gnu.linkonce.t._ZN7Structs4Wait4ReadER10DataStream) }
    .script_reader_UnlockShop 0x0033d5b4 : { *script-manager-helpers.o(.gnu.linkonce.t._ZN7Structs10UnlockShop4ReadER10DataStream) }
    .script_reader_UnlockScript 0x0033d5d0 : { *script-manager-helpers.o(.gnu.linkonce.t._ZN7Structs12UnlockScript4ReadER10DataStream) }
    .script_reader_TagForKill 0x0033d5ec : { *script-manager-helpers.o(.gnu.linkonce.t._ZN7Structs10TagForKill4ReadER10DataStream) }
    .script_reader_StopSfx 0x0033d608 : { *script-manager-helpers.o(.gnu.linkonce.t._ZN7Structs7StopSfx4ReadER10DataStream) }
    .script_reader_StopObject 0x0033d624 : { *script-manager-helpers.o(.gnu.linkonce.t._ZN7Structs10StopObject4ReadER10DataStream) }
    .script_reader_StopMusic 0x0033d640 : { *script-manager-helpers.o(.gnu.linkonce.t._ZN7Structs9StopMusic4ReadER10DataStream) }
    .script_reader_StartRace 0x0033d688 : { *script-manager-helpers.o(.gnu.linkonce.t._ZN7Structs9StartRace4ReadER10DataStream) }
    .script_reader_SetWantedLevel 0x0033d6f4 : { *script-manager-helpers.o(.gnu.linkonce.t._ZN7Structs14SetWantedLevel4ReadER10DataStream) }
    .script_reader_SetPhotoTarget 0x0033d710 : { *script-manager-helpers.o(.gnu.linkonce.t._ZN7Structs14SetPhotoTarget4ReadER10DataStream) }
    .script_reader_SetMe 0x0033d72c : { *script-manager-helpers.o(.gnu.linkonce.t._ZN7Structs5SetMe4ReadER10DataStream) }
    .script_reader_SetDecal 0x0033d748 : { *script-manager-helpers.o(.gnu.linkonce.t._ZN7Structs8SetDecal4ReadER10DataStream) }
    .script_reader_Release 0x0033d7d8 : { *script-manager-helpers.o(.gnu.linkonce.t._ZN7Structs7Release4ReadER10DataStream) }
    .script_reader_RaiseWantedLevel 0x0033d7f4 : { *script-manager-helpers.o(.gnu.linkonce.t._ZN7Structs16RaiseWantedLevel4ReadER10DataStream) }
    .script_reader_PlaySfx 0x0033d858 : { *script-manager-helpers.o(.gnu.linkonce.t._ZN7Structs7PlaySfx4ReadER10DataStream) }
    .script_reader_PlayScript 0x0033d874 : { *script-manager-helpers.o(.gnu.linkonce.t._ZN7Structs10PlayScript4ReadER10DataStream) }
    .script_reader_PlayMusic 0x0033d890 : { *script-manager-helpers.o(.gnu.linkonce.t._ZN7Structs9PlayMusic4ReadER10DataStream) }
    .script_reader_MissionStart 0x0033d93c : { *script-manager-helpers.o(.gnu.linkonce.t._ZN7Structs12MissionStart4ReadER10DataStream) }
    .script_reader_MissionObjective 0x0033d958 : { *script-manager-helpers.o(.gnu.linkonce.t._ZN7Structs16MissionObjective4ReadER10DataStream) }
    .script_reader_LockShop 0x0033d974 : { *script-manager-helpers.o(.gnu.linkonce.t._ZN7Structs8LockShop4ReadER10DataStream) }
    .script_reader_LockScript 0x0033d990 : { *script-manager-helpers.o(.gnu.linkonce.t._ZN7Structs10LockScript4ReadER10DataStream) }
    .script_reader_LimitToWeapon 0x0033d9ac : { *script-manager-helpers.o(.gnu.linkonce.t._ZN7Structs13LimitToWeapon4ReadER10DataStream) }
    .script_reader_KillNPC 0x0033d9c8 : { *script-manager-helpers.o(.gnu.linkonce.t._ZN7Structs7KillNPC4ReadER10DataStream) }
    .script_reader_HudHighlight 0x0033d9e4 : { *script-manager-helpers.o(.gnu.linkonce.t._ZN7Structs12HudHighlight4ReadER10DataStream) }
    .script_reader_GiveWeapon 0x0033da00 : { *script-manager-helpers.o(.gnu.linkonce.t._ZN7Structs10GiveWeapon4ReadER10DataStream) }
    .script_reader_FlagAsInRace 0x0033da1c : { *script-manager-helpers.o(.gnu.linkonce.t._ZN7Structs12FlagAsInRace4ReadER10DataStream) }
    .script_reader_FadeOut 0x0033da38 : { *script-manager-helpers.o(.gnu.linkonce.t._ZN7Structs7FadeOut4ReadER10DataStream) }
    .script_reader_FadeIn 0x0033da54 : { *script-manager-helpers.o(.gnu.linkonce.t._ZN7Structs6FadeIn4ReadER10DataStream) }
    .script_reader_DropWantedLevel 0x0033da94 : { *script-manager-helpers.o(.gnu.linkonce.t._ZN7Structs15DropWantedLevel4ReadER10DataStream) }
    .script_reader_Disable 0x0033dab0 : { *script-manager-helpers.o(.gnu.linkonce.t._ZN7Structs7Disable4ReadER10DataStream) }
    .script_reader_DestroyCar 0x0033daf8 : { *script-manager-helpers.o(.gnu.linkonce.t._ZN7Structs10DestroyCar4ReadER10DataStream) }
    .script_reader_DebugScript 0x0033db14 : { *script-manager-helpers.o(.gnu.linkonce.t._ZN7Structs11DebugScript4ReadER10DataStream) }
    .script_reader_CamDefault 0x0033dbc0 : { *script-manager-helpers.o(.gnu.linkonce.t._ZN7Structs10CamDefault4ReadER10DataStream) }
    .script_reader_BeQuick 0x0033dbdc : { *script-manager-helpers.o(.gnu.linkonce.t._ZN7Structs7BeQuick4ReadER10DataStream) }
    .script_reader_AttackAsGood 0x0033dc20 : { *script-manager-helpers.o(.gnu.linkonce.t._ZN7Structs12AttackAsGood4ReadER10DataStream) }
    .script_reader_AttackAsBad 0x0033dc3c : { *script-manager-helpers.o(.gnu.linkonce.t._ZN7Structs11AttackAsBad4ReadER10DataStream) }
    .script_reader_ActorStopFollow 0x0033dccc : { *script-manager-helpers.o(.gnu.linkonce.t._ZN7Structs15ActorStopFollow4ReadER10DataStream) }
    .script_reader_ActorLoopPath 0x0033dd30 : { *script-manager-helpers.o(.gnu.linkonce.t._ZN7Structs13ActorLoopPath4ReadER10DataStream) }
    .script_reader_ActorGetOut 0x0033dd4c : { *script-manager-helpers.o(.gnu.linkonce.t._ZN7Structs11ActorGetOut4ReadER10DataStream) }
    .script_reader_WaitIfNotPhotographed 0x0033d4b0 : { *script-manager-helpers.o(.gnu.linkonce.t._ZN7Structs21WaitIfNotPhotographed4ReadER10DataStream) }
    .script_reader_WaitEscape 0x0033d50c : { *script-manager-helpers.o(.gnu.linkonce.t._ZN7Structs10WaitEscape4ReadER10DataStream) }
    .script_reader_VehicleChasePlayer 0x0033d590 : { *script-manager-helpers.o(.gnu.linkonce.t._ZN7Structs18VehicleChasePlayer4ReadER10DataStream) }
    .script_reader_StayWithin 0x0033d65c : { *script-manager-helpers.o(.gnu.linkonce.t._ZN7Structs10StayWithin4ReadER10DataStream) }
    .script_reader_SpyTarget 0x0033d6a4 : { *script-manager-helpers.o(.gnu.linkonce.t._ZN7Structs9SpyTarget4ReadER10DataStream) }
    .script_reader_ShowTutorial 0x0033d6d0 : { *script-manager-helpers.o(.gnu.linkonce.t._ZN7Structs12ShowTutorial4ReadER10DataStream) }
    .script_reader_SetAnimSpeed 0x0033d764 : { *script-manager-helpers.o(.gnu.linkonce.t._ZN7Structs12SetAnimSpeed4ReadER10DataStream) }
    .script_reader_SetAnim2 0x0033d788 : { *script-manager-helpers.o(.gnu.linkonce.t._ZN7Structs8SetAnim24ReadER10DataStream) }
    .script_reader_SetAnim 0x0033d7b4 : { *script-manager-helpers.o(.gnu.linkonce.t._ZN7Structs7SetAnim4ReadER10DataStream) }
    .script_reader_ProtectNPC 0x0033d810 : { *script-manager-helpers.o(.gnu.linkonce.t._ZN7Structs10ProtectNPC4ReadER10DataStream) }
    .script_reader_ProtectCar 0x0033d834 : { *script-manager-helpers.o(.gnu.linkonce.t._ZN7Structs10ProtectCar4ReadER10DataStream) }
    .script_reader_PlaceItem 0x0033d8ac : { *script-manager-helpers.o(.gnu.linkonce.t._ZN7Structs9PlaceItem4ReadER10DataStream) }
    .script_reader_PhotographQuickly 0x0033d8d0 : { *script-manager-helpers.o(.gnu.linkonce.t._ZN7Structs17PhotographQuickly4ReadER10DataStream) }
    .script_reader_NPCWeapon 0x0033d8f4 : { *script-manager-helpers.o(.gnu.linkonce.t._ZN7Structs9NPCWeapon4ReadER10DataStream) }
    .script_reader_MoveTo 0x0033d918 : { *script-manager-helpers.o(.gnu.linkonce.t._ZN7Structs6MoveTo4ReadER10DataStream) }
    .script_reader_Enable 0x0033da70 : { *script-manager-helpers.o(.gnu.linkonce.t._ZN7Structs6Enable4ReadER10DataStream) }
    .script_reader_Dialog 0x0033dacc : { *script-manager-helpers.o(.gnu.linkonce.t._ZN7Structs6Dialog4ReadER10DataStream) }
    .script_reader_CarSetSpeed 0x0033db30 : { *script-manager-helpers.o(.gnu.linkonce.t._ZN7Structs11CarSetSpeed4ReadER10DataStream) }
    .script_reader_CarSetPath 0x0033db54 : { *script-manager-helpers.o(.gnu.linkonce.t._ZN7Structs10CarSetPath4ReadER10DataStream) }
    .script_reader_CarDriveTo 0x0033db78 : { *script-manager-helpers.o(.gnu.linkonce.t._ZN7Structs10CarDriveTo4ReadER10DataStream) }
    .script_reader_CamSet 0x0033db9c : { *script-manager-helpers.o(.gnu.linkonce.t._ZN7Structs6CamSet4ReadER10DataStream) }
    .script_reader_AddRacer 0x0033dc58 : { *script-manager-helpers.o(.gnu.linkonce.t._ZN7Structs8AddRacer4ReadER10DataStream) }
    .script_reader_ActorWalkTo 0x0033dc84 : { *script-manager-helpers.o(.gnu.linkonce.t._ZN7Structs11ActorWalkTo4ReadER10DataStream) }
    .script_reader_ActorWalkPath 0x0033dca8 : { *script-manager-helpers.o(.gnu.linkonce.t._ZN7Structs13ActorWalkPath4ReadER10DataStream) }
    .script_reader_ActorRunTo 0x0033dce8 : { *script-manager-helpers.o(.gnu.linkonce.t._ZN7Structs10ActorRunTo4ReadER10DataStream) }
    .script_reader_ActorRunPath 0x0033dd0c : { *script-manager-helpers.o(.gnu.linkonce.t._ZN7Structs12ActorRunPath4ReadER10DataStream) }
    .script_reader_ActorGetIn 0x0033dd68 : { *script-manager-helpers.o(.gnu.linkonce.t._ZN7Structs10ActorGetIn4ReadER10DataStream) }
    .script_reader_ActorFollow 0x0033dd8c : { *script-manager-helpers.o(.gnu.linkonce.t._ZN7Structs11ActorFollow4ReadER10DataStream) }
    .script_reader_ActorAttack 0x0033ddb0 : { *script-manager-helpers.o(.gnu.linkonce.t._ZN7Structs11ActorAttack4ReadER10DataStream) }
    .script_reader_WaitCheckpointCar 0x0033d54c : { *script-manager-helpers.o(.gnu.linkonce.t._ZN7Structs17WaitCheckpointCar4ReadER10DataStream) }
    .script_reader_SetUsUpTheBomb 0x0033dbf8 : { *script-manager-helpers.o(.gnu.linkonce.t._ZN7Structs14SetUsUpTheBomb4ReadER10DataStream) }
    .script_manager_finishReviveAnims 0x0033d0f0 : { *script-manager-helpers.o(.text._ZN13ScriptManager17finishReviveAnimsEv) }
    .script_manager_missionIdle 0x0033d2e0 : { *script-manager-helpers.o(.text._ZN13ScriptManager11missionIdleEv) }
    .script_manager_drawCinematicBars 0x0033d350 : { *script-manager-helpers.o(.text._ZNK13ScriptManager17drawCinematicBarsEv) }
    .script_manager_missionResumeFadeOut 0x0033e818 : { *script-manager-helpers.o(.text._ZN13ScriptManager20missionResumeFadeOutEv) }
    .script_manager_missionSkipFadeOut 0x0033e82c : { *script-manager-helpers.o(.text._ZN13ScriptManager18missionSkipFadeOutEv) }
    .script_manager_missionSetFailureCount 0x0033e840 : { *script-manager-helpers.o(.text._ZN13ScriptManager22missionSetFailureCountEi) }
    .script_manager_missionClearConditions 0x0033e854 : { *script-manager-helpers.o(.text._ZN13ScriptManager22missionClearConditionsEv) }
    .script_manager_missionFail 0x0033e8ac : { *script-manager-helpers.o(.text._ZN13ScriptManager11missionFailEv) }
    .script_manager_message 0x0033e8c0 : { *script-manager-helpers.o(.text._ZN13ScriptManager7messageEi) }
    .script_manager_missionObjective 0x0033e8d4 : { *script-manager-helpers.o(.text._ZN13ScriptManager16missionObjectiveEib) }
    .script_manager_missionStart 0x0033e8e8 : { *script-manager-helpers.o(.text._ZN13ScriptManager12missionStartEii) }
    .script_manager_missionOver 0x0033e888 : { *script-manager-helpers.o(.text._ZN13ScriptManager11missionOverEv) }
    .script_manager_missionRegisterCondition 0x0033e868 : { *script-manager-helpers.o(.text._ZN13ScriptManager24missionRegisterConditionEP17IMissionCondition) }
    .script_manager_resumeBlockingCommands 0x0033d3d0 : { *script-manager-helpers.o(.text._ZN13ScriptManager22resumeBlockingCommandsEv) }
    .script_manager_hideSkipButton 0x0033d194 : { *script-manager-helpers.o(.text._ZN13ScriptManager14hideSkipButtonEv) }
    .script_manager_showSkipButton 0x0033d1b8 : { *script-manager-helpers.o(.text._ZN13ScriptManager14showSkipButtonEv) }
    .script_manager_skipCutscene 0x0033d3f0 : { *script-manager-helpers.o(.text._ZN13ScriptManager12skipCutsceneEv) }
    .script_manager_unload 0x0033fcb0 : { *script-manager-helpers.o(.text._ZN13ScriptManager6unloadEv) }
    .script_manager_tearDown 0x0033fda8 : { *script-manager-helpers.o(.text._ZN13ScriptManager8tearDownEv) }
    .script_manager_draw 0x0033fe70 : { *script-manager-helpers.o(.text._ZN13ScriptManager4drawEv) }
}
