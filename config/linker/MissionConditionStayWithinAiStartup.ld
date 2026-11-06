OUTPUT_FORMAT("elf32-littlearm")
OUTPUT_ARCH(arm)
INCLUDE build/matches/ai-startup-missionconditionstaywithin/retail-symbols.ld
_ZdlPv = 0x001c42b0;
__aeabi_atexit = 0x001c494c;
_ZN45retail_missionconditionstaywithin_transitions16civPassive_transE = 0x0042d6b0;
_ZN45retail_missionconditionstaywithin_transitions17scriptedNpc_transE = 0x0042d7dc;
_ZN45retail_missionconditionstaywithin_transitions19civAggressive_transE = 0x0042d80c;
_ZN45retail_missionconditionstaywithin_transitions16gangMember_transE = 0x0042d8f0;
_ZN45retail_missionconditionstaywithin_transitions9cop_transE = 0x0042d8fc;
_ZN45retail_missionconditionstaywithin_transitions10swat_transE = 0x0042da34;
_ZN45retail_missionconditionstaywithin_transitions17civ_vehicle_transE = 0x0042da40;
_ZN45retail_missionconditionstaywithin_transitions17cop_vehicle_transE = 0x0042dad0;
_ZN45retail_missionconditionstaywithin_transitions11guard_transE = 0x0042db84;
_ZN45retail_missionconditionstaywithin_transitions22scripted_vehicle_transE = 0x0042dc2c;
__aeabi_idiv = 0x001c43dc;
SECTIONS
{
    .stay_within_00338174 0x00338174 : { *ai-startup-missionconditionstaywithin.o(.text._ZN26MissionConditionStayWithin4drawEv) }
    .stay_within_003381a8 0x003381a8 : { *ai-startup-missionconditionstaywithin.o(.text._ZN26MissionConditionStayWithinC1EP11LevelObjectii .text._ZN26MissionConditionStayWithinC2EP11LevelObjectii) }
    .stay_within_00338570 0x00338570 : { *ai-startup-missionconditionstaywithin.o(.text._ZN26MissionConditionStayWithinD0Ev) }
    .stay_within_003385d8 0x003385d8 : { *ai-startup-missionconditionstaywithin.o(.text._ZN26MissionConditionStayWithinD1Ev .text._ZN26MissionConditionStayWithinD2Ev) }
    .stay_within_vtable 0x004acf38 : { *ai-startup-missionconditionstaywithin.o(.data.rel.ro._ZTV26MissionConditionStayWithin) }
    .ai_startup_function_0 0x00338178 : { *ai-startup-missionconditionstaywithin.o(.text.__tcf_3) }
    .ai_startup_function_1 0x00338418 : { *ai-startup-missionconditionstaywithin.o(.text._Z41__static_initialization_and_destruction_0ii) }
    .ai_startup_function_2 0x0033855c : { *ai-startup-missionconditionstaywithin.o(.text._GLOBAL__I__ZN26MissionConditionStayWithinC2EP11LevelObjectii) }
    .ai_startup_storage_0 0x004ba368 (NOLOAD) : { *ai-startup-missionconditionstaywithin.o(.bss._ZN3irr5scene6quake315irrEmptyStringcE) }
    .ai_startup_storage_1 0x004ba388 (NOLOAD) : { *ai-startup-missionconditionstaywithin.o(.bss._ZN3irr2ps5vHalfE) }
    .ai_startup_storage_2 0x004ba394 (NOLOAD) : { *ai-startup-missionconditionstaywithin.o(.bss._ZN8gameloft2ai11civ_passiveE) }
    .ai_startup_storage_3 0x004ba39c (NOLOAD) : { *ai-startup-missionconditionstaywithin.o(.bss._ZN8gameloft2ai12npc_scriptedE) }
    .ai_startup_storage_4 0x004ba3a4 (NOLOAD) : { *ai-startup-missionconditionstaywithin.o(.bss._ZN8gameloft2ai13civ_agressiveE) }
    .ai_startup_storage_5 0x004ba3ac (NOLOAD) : { *ai-startup-missionconditionstaywithin.o(.bss._ZN8gameloft2ai11gang_memberE) }
    .ai_startup_storage_6 0x004ba3b4 (NOLOAD) : { *ai-startup-missionconditionstaywithin.o(.bss._ZN8gameloft2ai3copE) }
    .ai_startup_storage_7 0x004ba3bc (NOLOAD) : { *ai-startup-missionconditionstaywithin.o(.bss._ZN8gameloft2ai4swatE) }
    .ai_startup_storage_8 0x004ba3c4 (NOLOAD) : { *ai-startup-missionconditionstaywithin.o(.bss._ZN8gameloft2ai11civ_vehicleE) }
    .ai_startup_storage_9 0x004ba3cc (NOLOAD) : { *ai-startup-missionconditionstaywithin.o(.bss._ZN8gameloft2ai11cop_vehicleE) }
    .ai_startup_storage_10 0x004ba3d4 (NOLOAD) : { *ai-startup-missionconditionstaywithin.o(.bss._ZN8gameloft2ai5guardE) }
    .ai_startup_storage_11 0x004ba3dc (NOLOAD) : { *ai-startup-missionconditionstaywithin.o(.bss._ZN8gameloft2ai16scripted_vehicleE) }
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
