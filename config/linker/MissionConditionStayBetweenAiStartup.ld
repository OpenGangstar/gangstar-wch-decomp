OUTPUT_FORMAT("elf32-littlearm")
OUTPUT_ARCH(arm)
INCLUDE build/matches/ai-startup-missionconditionstaybetween/retail-symbols.ld
_ZdlPv = 0x001c42b0;
__aeabi_atexit = 0x001c494c;
_ZN46retail_missionconditionstaybetween_transitions16civPassive_transE = 0x0042d0e0;
_ZN46retail_missionconditionstaybetween_transitions17scriptedNpc_transE = 0x0042d20c;
_ZN46retail_missionconditionstaybetween_transitions19civAggressive_transE = 0x0042d23c;
_ZN46retail_missionconditionstaybetween_transitions16gangMember_transE = 0x0042d320;
_ZN46retail_missionconditionstaybetween_transitions9cop_transE = 0x0042d32c;
_ZN46retail_missionconditionstaybetween_transitions10swat_transE = 0x0042d464;
_ZN46retail_missionconditionstaybetween_transitions17civ_vehicle_transE = 0x0042d470;
_ZN46retail_missionconditionstaybetween_transitions17cop_vehicle_transE = 0x0042d500;
_ZN46retail_missionconditionstaybetween_transitions11guard_transE = 0x0042d5b4;
_ZN46retail_missionconditionstaybetween_transitions22scripted_vehicle_transE = 0x0042d65c;
__cxa_pure_virtual = 0;
__aeabi_fsub = 0x001c4328;
__aeabi_fadd = 0x001c4154;
__aeabi_fmul = 0x001c4724;
__aeabi_fdiv = 0x001c4520;
__aeabi_f2d = 0x001c48f8;
__aeabi_d2f = 0x001c4310;
__aeabi_fcmpgt = 0x001c419c;
__aeabi_fcmplt = 0x001c479c;
sqrt = 0x001c401c;
INCLUDE config/linker/ApplicationEventSections.ld
SECTIONS
{
    .stay_between_evaluate 0x00337db8 : { *ai-startup-missionconditionstaybetween.o(.text._ZN27MissionConditionStayBetween8evaluateEi) }
    .stay_between_d0 0x00338094 : { *ai-startup-missionconditionstaybetween.o(.text._ZN27MissionConditionStayBetweenD0Ev) }
    .stay_between_d1 0x00338110 : { *ai-startup-missionconditionstaybetween.o(.text._ZN27MissionConditionStayBetweenD1Ev .text._ZN27MissionConditionStayBetweenD2Ev) }
    .stay_between_thunk_d0 0x00338080 : { *ai-startup-missionconditionstaybetween.o(.text._ZThn4_N27MissionConditionStayBetweenD0Ev) }
    .stay_between_thunk_d1 0x003380fc : { *ai-startup-missionconditionstaybetween.o(.text._ZThn4_N27MissionConditionStayBetweenD1Ev) }
    .stay_between_vtable 0x004acf00 : { *ai-startup-missionconditionstaybetween.o(.data.rel.ro._ZTV27MissionConditionStayBetween) }
    .receiver_d0 0x002db4b4 : { *(.gnu.linkonce.t._ZN14IEventReceiverD0Ev) }
    .receiver_d1 0x002db4d4 : { *(.gnu.linkonce.t._ZN14IEventReceiverD1Ev) }
    .receiver_vtable 0x004a8b48 : { *(.gnu.linkonce.d.rel.ro._ZTV14IEventReceiver) }
    .stay_between_ctor 0x00337eb4 : { *ai-startup-missionconditionstaybetween.o(.text._ZN27MissionConditionStayBetweenC1EP11LevelObjectff .text._ZN27MissionConditionStayBetweenC2EP11LevelObjectff) }
    .on_event 0x00337d5c : { *ai-startup-missionconditionstaybetween.o(.text._ZN27MissionConditionStayBetween7onEventEPK6IEventPK12EventManager) }
    .on_event_thunk 0x00337d48 : { *ai-startup-missionconditionstaybetween.o(.text._ZThn4_N27MissionConditionStayBetween7onEventEPK6IEventPK12EventManager) }
    .condition_draw 0x00337d44 : { *ai-startup-missionconditionstaybetween.o(.text._ZN27MissionConditionStayBetween4drawEv) }
    .ai_startup_function_0 0x00337d88 : { *ai-startup-missionconditionstaybetween.o(.text.__tcf_3) }
    .ai_startup_function_1 0x00337f28 : { *ai-startup-missionconditionstaybetween.o(.text._Z41__static_initialization_and_destruction_0ii) }
    .ai_startup_function_2 0x0033806c : { *ai-startup-missionconditionstaybetween.o(.text._GLOBAL__I__ZN27MissionConditionStayBetweenC2EP11LevelObjectff) }
    .ai_startup_storage_0 0x004ba2ec (NOLOAD) : { *ai-startup-missionconditionstaybetween.o(.bss._ZN3irr5scene6quake315irrEmptyStringcE) }
    .ai_startup_storage_1 0x004ba30c (NOLOAD) : { *ai-startup-missionconditionstaybetween.o(.bss._ZN3irr2ps5vHalfE) }
    .ai_startup_storage_2 0x004ba318 (NOLOAD) : { *ai-startup-missionconditionstaybetween.o(.bss._ZN8gameloft2ai11civ_passiveE) }
    .ai_startup_storage_3 0x004ba320 (NOLOAD) : { *ai-startup-missionconditionstaybetween.o(.bss._ZN8gameloft2ai12npc_scriptedE) }
    .ai_startup_storage_4 0x004ba328 (NOLOAD) : { *ai-startup-missionconditionstaybetween.o(.bss._ZN8gameloft2ai13civ_agressiveE) }
    .ai_startup_storage_5 0x004ba330 (NOLOAD) : { *ai-startup-missionconditionstaybetween.o(.bss._ZN8gameloft2ai11gang_memberE) }
    .ai_startup_storage_6 0x004ba338 (NOLOAD) : { *ai-startup-missionconditionstaybetween.o(.bss._ZN8gameloft2ai3copE) }
    .ai_startup_storage_7 0x004ba340 (NOLOAD) : { *ai-startup-missionconditionstaybetween.o(.bss._ZN8gameloft2ai4swatE) }
    .ai_startup_storage_8 0x004ba348 (NOLOAD) : { *ai-startup-missionconditionstaybetween.o(.bss._ZN8gameloft2ai11civ_vehicleE) }
    .ai_startup_storage_9 0x004ba350 (NOLOAD) : { *ai-startup-missionconditionstaybetween.o(.bss._ZN8gameloft2ai11cop_vehicleE) }
    .ai_startup_storage_10 0x004ba358 (NOLOAD) : { *ai-startup-missionconditionstaybetween.o(.bss._ZN8gameloft2ai5guardE) }
    .ai_startup_storage_11 0x004ba360 (NOLOAD) : { *ai-startup-missionconditionstaybetween.o(.bss._ZN8gameloft2ai16scripted_vehicleE) }
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
