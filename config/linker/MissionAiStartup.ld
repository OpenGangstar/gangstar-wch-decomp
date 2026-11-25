OUTPUT_FORMAT("elf32-littlearm")
OUTPUT_ARCH(arm)
INCLUDE build/matches/ai-startup-mission/retail-symbols.ld
_ZdlPv = 0x001c42b0;
_ZdaPv = 0x001c461c;
_Znaj = 0x001c3ff8;
_Znwj = 0x001c4814;
memset = 0x001c45d4;
strcmp = 0x001c4658;
strcpy = 0x001c3fd4;
__aeabi_idiv = 0x001c43dc;
__stack_chk_fail = 0x001c42e0;
__aeabi_atexit = 0x001c494c;
_ZN26retail_mission_transitions16civPassive_transE = 0x0042a72c;
_ZN26retail_mission_transitions17scriptedNpc_transE = 0x0042a858;
_ZN26retail_mission_transitions19civAggressive_transE = 0x0042a888;
_ZN26retail_mission_transitions16gangMember_transE = 0x0042a96c;
_ZN26retail_mission_transitions9cop_transE = 0x0042a978;
_ZN26retail_mission_transitions10swat_transE = 0x0042aab0;
_ZN26retail_mission_transitions17civ_vehicle_transE = 0x0042aabc;
_ZN26retail_mission_transitions17cop_vehicle_transE = 0x0042ab4c;
_ZN26retail_mission_transitions11guard_transE = 0x0042ac00;
_ZN26retail_mission_transitions22scripted_vehicle_transE = 0x0042aca8;
__cxa_guard_acquire = 0x001c4958;
__cxa_guard_release = 0x001c46c4;
SECTIONS
{
    .mission_update 0x003365f0 : { *ai-startup-mission.o(.text._ZN7Mission6updateEi) }
    .mission_update_table 0x0042a714 : { *ai-startup-mission.o(.rodata._ZN7Mission6updateEi) }
 .mission_constructor 0x003360c0 : { *ai-startup-mission.o(.text._ZN7MissionC1Ev .text._ZN7MissionC2Ev) }
    .mission_draw 0x0033620c : { *ai-startup-mission.o(.text._ZN7Mission4drawEv) }
    .mission_message 0x00336344 : { *ai-startup-mission.o(.text._ZN7Mission7messageEi) }
    .mission_start 0x003363d0 : { *ai-startup-mission.o(.text._ZN7Mission5startEii) }
    .mission_load 0x00335e60 : { *ai-startup-mission.o(.text._ZN7Mission4loadEPKc) }
    .mission_deleting_destructor 0x00335f90 : { *ai-startup-mission.o(.text._ZN7MissionD0Ev) }
    .mission_destructor 0x0033602c : { *ai-startup-mission.o(.text._ZN7MissionD2Ev .text._ZN7MissionD1Ev) }
    .mission_frame_module_rect 0x00336140 : { *ai-startup-mission.o(.text._Z18getFrameModuleRectP7ASpriteiii) }
    .mission_end 0x00336960 : { *ai-startup-mission.o(.text._ZN7Mission3endEv) }
    .mission_vtable 0x004ace00 : { *ai-startup-mission.o(.data.rel.ro._ZTV7Mission) }
    .mission_load_initializer 0x0042acfc : { *ai-startup-mission.o(.rodata._ZZN7Mission4loadEPKcE*) }
    .mission_data_stream_dtor 0x002d3654 : { *ai-startup-mission.o(.text._ZN10DataStreamD1Ev .gnu.linkonce.t._ZN10DataStreamD1Ev) }
    .mission_fail 0x00335d8c : { *ai-startup-mission.o(.text._ZN7Mission4failEv) }
    .mission_idle 0x003365a4 : { *ai-startup-mission.o(.text._ZN7Mission4idleEv) }
    .wanted_singleton 0x002dba04 : { *ai-startup-mission.o(.gnu.linkonce.t._ZN18WantedLevelManager11getInstanceEv) }
    .wanted_cleanup 0x00335df0 : { *ai-startup-mission.o(.text.__tcf_0) }
    .wanted_guard 0x004b6728 (NOLOAD) : { *ai-startup-mission.o(.gnu.linkonce.b._ZGVZN18WantedLevelManager11getInstanceEvE3wlm) }
    .wanted_instance 0x004b6a98 (NOLOAD) : { *ai-startup-mission.o(.gnu.linkonce.b._ZZN18WantedLevelManager11getInstanceEvE3wlm) }
    .mission_set_text 0x00335c10 : { *ai-startup-mission.o(.text._ZN7Mission14setTextToPrintEi) }
    .mission_lookup 0x00335c18 : { *ai-startup-mission.o(.text._ZNK7Mission7missionEi) }
    .mission_last_objective 0x00335c34 : { *ai-startup-mission.o(.text._ZNK7Mission20getLastObjectiveTextEv) }
    .mission_current_message 0x00335c48 : { *ai-startup-mission.o(.text._ZNK7Mission17getCurrentMessageEv) }
    .mission_register_condition 0x00335c4c : { *ai-startup-mission.o(.text._ZN7Mission17registerConditionEP17IMissionCondition) }
    .mission_clear_conditions 0x00335c64 : { *ai-startup-mission.o(.text._ZN7Mission15clearConditionsEv) }
    .mission_state 0x00335c98 : { *ai-startup-mission.o(.text._ZNK7Mission8getStateEv) }
    .mission_failure_cause 0x00335c9c : { *ai-startup-mission.o(.text._ZNK7Mission12failureCauseEv) }
    .mission_failure_count 0x00335ca4 : { *ai-startup-mission.o(.text._ZNK7Mission12failureCountEv) }
    .mission_skip_fade 0x00335cac : { *ai-startup-mission.o(.text._ZN7Mission11skipFadeOutEv) }
    .mission_resume_fade 0x00335cb4 : { *ai-startup-mission.o(.text._ZN7Mission13resumeFadeOutEv) }
    .mission_set_failure_count 0x00335cbc : { *ai-startup-mission.o(.text._ZN7Mission15setFailureCountEi) }
    .mission_read 0x00335e0c : { *ai-startup-mission.o(.gnu.linkonce.t._ZN7Structs7Mission4ReadER10DataStream) }
    .mission_objective 0x003363bc : { *ai-startup-mission.o(.text._ZN7Mission9objectiveEib) }
    .mission_rct_validate 0x00335cc4 : { *ai-startup-mission.o(.text._ZN3RctIiE9_validateEv .gnu.linkonce.t._ZN3RctIiE9_validateEv) }
    .ai_startup_function_0 0x00335d24 : { *ai-startup-mission.o(.text.__tcf_4) }
    .ai_startup_function_1 0x00336808 : { *ai-startup-mission.o(.text._Z41__static_initialization_and_destruction_0ii) }
    .ai_startup_function_2 0x0033694c : { *ai-startup-mission.o(.text._GLOBAL__I__Z18getFrameModuleRectP7ASpriteiii) }
    .mission_rct_1 0x00335d54 : { *ai-startup-mission.o(.text._ZN3RctIiED0Ev .gnu.linkonce.t._ZN3RctIiED0Ev) }
    .mission_rct_2 0x00335d74 : { *ai-startup-mission.o(.text._ZN3RctIiED1Ev .gnu.linkonce.t._ZN3RctIiED1Ev) }
    .mission_rct_vtable 0x004ace10 : { *ai-startup-mission.o(.data.rel.ro._ZTV3RctIiE .gnu.linkonce.d._ZTV3RctIiE .gnu.linkonce.d.rel.ro._ZTV3RctIiE .rodata._ZTV3RctIiE .gnu.linkonce.r._ZTV3RctIiE) }
    .ai_startup_storage_0 0x004b9f88 (NOLOAD) : { *ai-startup-mission.o(.bss._ZN3irr5scene6quake315irrEmptyStringcE) }
    .ai_startup_storage_1 0x004b9fa8 (NOLOAD) : { *ai-startup-mission.o(.bss._ZN3irr2ps5vHalfE) }
    .ai_startup_storage_2 0x004b9fb4 (NOLOAD) : { *ai-startup-mission.o(.bss._ZN8gameloft2ai11civ_passiveE) }
    .ai_startup_storage_3 0x004b9fbc (NOLOAD) : { *ai-startup-mission.o(.bss._ZN8gameloft2ai12npc_scriptedE) }
    .ai_startup_storage_4 0x004b9fc4 (NOLOAD) : { *ai-startup-mission.o(.bss._ZN8gameloft2ai13civ_agressiveE) }
    .ai_startup_storage_5 0x004b9fcc (NOLOAD) : { *ai-startup-mission.o(.bss._ZN8gameloft2ai11gang_memberE) }
    .ai_startup_storage_6 0x004b9fd4 (NOLOAD) : { *ai-startup-mission.o(.bss._ZN8gameloft2ai3copE) }
    .ai_startup_storage_7 0x004b9fdc (NOLOAD) : { *ai-startup-mission.o(.bss._ZN8gameloft2ai4swatE) }
    .ai_startup_storage_8 0x004b9fe4 (NOLOAD) : { *ai-startup-mission.o(.bss._ZN8gameloft2ai11civ_vehicleE) }
    .ai_startup_storage_9 0x004b9fec (NOLOAD) : { *ai-startup-mission.o(.bss._ZN8gameloft2ai11cop_vehicleE) }
    .ai_startup_storage_10 0x004b9ff4 (NOLOAD) : { *ai-startup-mission.o(.bss._ZN8gameloft2ai5guardE) }
    .ai_startup_storage_11 0x004b9ffc (NOLOAD) : { *ai-startup-mission.o(.bss._ZN8gameloft2ai16scripted_vehicleE) }
    .shared_startup_empty_text 0x0044d91c : { *(.gnu.linkonce.r.localStartupEmptyText) }
    .got 0x004b0048 : { *(.got.plt) . = 0x360; *(.got) }
    .verification 0x00600000 : { *retail-got.o(.text) }
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

ASSERT(ADDR(.mission_constructor)==0x003360c0,"Mission ctor native start");
ASSERT(SIZEOF(.mission_constructor)==128,"Mission ctor native128 extent");
ASSERT(ADDR(.mission_constructor)+SIZEOF(.mission_constructor)==0x00336140,"Mission ctor actual next compiled neighbor");
ASSERT(SIZEOF(.mission_message) == 120, "Mission::message native span");
