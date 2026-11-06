/* ScriptManager queries and script registration at retail addresses. */
PROVIDE(_Znwj = 0x001c4814);
PROVIDE(__cxa_guard_acquire = 0x001c4958);
PROVIDE(__cxa_guard_release = 0x001c46c4);
SECTIONS
{
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
}
