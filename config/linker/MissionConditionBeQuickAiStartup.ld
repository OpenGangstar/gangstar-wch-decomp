OUTPUT_FORMAT("elf32-littlearm")
OUTPUT_ARCH(arm)
INCLUDE build/matches/ai-startup-missionconditionbequick/retail-symbols.ld
_ZdlPv = 0x001c42b0;
__aeabi_atexit = 0x001c494c;
_ZN42retail_missionconditionbequick_transitions16civPassive_transE = 0x0042ad30;
_ZN42retail_missionconditionbequick_transitions17scriptedNpc_transE = 0x0042ae5c;
_ZN42retail_missionconditionbequick_transitions19civAggressive_transE = 0x0042ae8c;
_ZN42retail_missionconditionbequick_transitions16gangMember_transE = 0x0042af70;
_ZN42retail_missionconditionbequick_transitions9cop_transE = 0x0042af7c;
_ZN42retail_missionconditionbequick_transitions10swat_transE = 0x0042b0b4;
_ZN42retail_missionconditionbequick_transitions17civ_vehicle_transE = 0x0042b0c0;
_ZN42retail_missionconditionbequick_transitions17cop_vehicle_transE = 0x0042b150;
_ZN42retail_missionconditionbequick_transitions11guard_transE = 0x0042b204;
_ZN42retail_missionconditionbequick_transitions22scripted_vehicle_transE = 0x0042b2ac;
__cxa_pure_virtual = 0;
sprintf = 0x001c46ac;
__stack_chk_fail = 0x001c42e0;
__aeabi_idiv = 0x001c43dc;
__aeabi_idivmod = 0x001c4934;
SECTIONS
{
    .bequick_evaluate 0x00336af8 : { *ai-startup-missionconditionbequick.o(.text._ZN23MissionConditionBeQuick8evaluateEi) }
    .bequick_delete 0x00336d44 : { *ai-startup-missionconditionbequick.o(.text._ZN23MissionConditionBeQuickD0Ev) }
    .bequick_destroy 0x00336d84 : { *ai-startup-missionconditionbequick.o(.text._ZN23MissionConditionBeQuickD1Ev .text._ZN23MissionConditionBeQuickD2Ev) }
    .bequick_format 0x0042ad20 : { *ai-startup-missionconditionbequick.o(.rodata.str1.4 .rodata.str1.1) }
    .bequick_vtable 0x004ace20 : { *ai-startup-missionconditionbequick.o(.data.rel.ro._ZTV23MissionConditionBeQuick) }
    .mission_condition_00336a6c 0x00336a6c : { *ai-startup-missionconditionbequick.o(.gnu.linkonce.t._ZNK17IMissionCondition5causeEv) }
    .mission_condition_00336a74 0x00336a74 : { *ai-startup-missionconditionbequick.o(.text._ZN23MissionConditionBeQuickC1Ei .text._ZN23MissionConditionBeQuickC2Ei) }
    .mission_condition_00336a8c 0x00336a8c : { *ai-startup-missionconditionbequick.o(.text._ZN23MissionConditionBeQuick4drawEv) }
    .mission_condition_00336ac0 0x00336ac0 : { *ai-startup-missionconditionbequick.o(.gnu.linkonce.t._ZN17IMissionConditionD0Ev) }
    .mission_condition_00336ae0 0x00336ae0 : { *ai-startup-missionconditionbequick.o(.gnu.linkonce.t._ZN17IMissionConditionD1Ev) }
    .mission_condition_base_vtable 0x004ace40 : { *ai-startup-missionconditionbequick.o(.data.rel.ro._ZTV17IMissionCondition .gnu.linkonce.d.rel.ro._ZTV17IMissionCondition .rodata._ZTV17IMissionCondition) }
    .ai_startup_function_0 0x00336a90 : { *ai-startup-missionconditionbequick.o(.text.__tcf_3) }
    .ai_startup_function_1 0x00336bec : { *ai-startup-missionconditionbequick.o(.text._Z41__static_initialization_and_destruction_0ii) }
    .ai_startup_function_2 0x00336d30 : { *ai-startup-missionconditionbequick.o(.text._GLOBAL__I__ZN23MissionConditionBeQuickC2Ei) }
    .ai_startup_storage_0 0x004ba004 (NOLOAD) : { *ai-startup-missionconditionbequick.o(.bss._ZN3irr5scene6quake315irrEmptyStringcE) }
    .ai_startup_storage_1 0x004ba024 (NOLOAD) : { *ai-startup-missionconditionbequick.o(.bss._ZN3irr2ps5vHalfE) }
    .ai_startup_storage_2 0x004ba030 (NOLOAD) : { *ai-startup-missionconditionbequick.o(.bss._ZN8gameloft2ai11civ_passiveE) }
    .ai_startup_storage_3 0x004ba038 (NOLOAD) : { *ai-startup-missionconditionbequick.o(.bss._ZN8gameloft2ai12npc_scriptedE) }
    .ai_startup_storage_4 0x004ba040 (NOLOAD) : { *ai-startup-missionconditionbequick.o(.bss._ZN8gameloft2ai13civ_agressiveE) }
    .ai_startup_storage_5 0x004ba048 (NOLOAD) : { *ai-startup-missionconditionbequick.o(.bss._ZN8gameloft2ai11gang_memberE) }
    .ai_startup_storage_6 0x004ba050 (NOLOAD) : { *ai-startup-missionconditionbequick.o(.bss._ZN8gameloft2ai3copE) }
    .ai_startup_storage_7 0x004ba058 (NOLOAD) : { *ai-startup-missionconditionbequick.o(.bss._ZN8gameloft2ai4swatE) }
    .ai_startup_storage_8 0x004ba060 (NOLOAD) : { *ai-startup-missionconditionbequick.o(.bss._ZN8gameloft2ai11civ_vehicleE) }
    .ai_startup_storage_9 0x004ba068 (NOLOAD) : { *ai-startup-missionconditionbequick.o(.bss._ZN8gameloft2ai11cop_vehicleE) }
    .ai_startup_storage_10 0x004ba070 (NOLOAD) : { *ai-startup-missionconditionbequick.o(.bss._ZN8gameloft2ai5guardE) }
    .ai_startup_storage_11 0x004ba078 (NOLOAD) : { *ai-startup-missionconditionbequick.o(.bss._ZN8gameloft2ai16scripted_vehicleE) }
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
