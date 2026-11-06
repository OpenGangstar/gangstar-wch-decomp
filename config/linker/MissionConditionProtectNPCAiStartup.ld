OUTPUT_FORMAT("elf32-littlearm")
OUTPUT_ARCH(arm)
INCLUDE build/matches/ai-startup-missionconditionprotectnpc/retail-symbols.ld
_ZdlPv = 0x001c42b0;
__aeabi_atexit = 0x001c494c;
_ZN45retail_missionconditionprotectnpc_transitions16civPassive_transE = 0x0042c540;
_ZN45retail_missionconditionprotectnpc_transitions17scriptedNpc_transE = 0x0042c66c;
_ZN45retail_missionconditionprotectnpc_transitions19civAggressive_transE = 0x0042c69c;
_ZN45retail_missionconditionprotectnpc_transitions16gangMember_transE = 0x0042c780;
_ZN45retail_missionconditionprotectnpc_transitions9cop_transE = 0x0042c78c;
_ZN45retail_missionconditionprotectnpc_transitions10swat_transE = 0x0042c8c4;
_ZN45retail_missionconditionprotectnpc_transitions17civ_vehicle_transE = 0x0042c8d0;
_ZN45retail_missionconditionprotectnpc_transitions17cop_vehicle_transE = 0x0042c960;
_ZN45retail_missionconditionprotectnpc_transitions11guard_transE = 0x0042ca14;
_ZN45retail_missionconditionprotectnpc_transitions22scripted_vehicle_transE = 0x0042cabc;
SECTIONS
{
    .mission_protect_00337ad8 0x00337ad8 : { *ai-startup-missionconditionprotectnpc.o(.text._ZN26MissionConditionProtectNPCD0Ev) }
    .mission_protect_00337b04 0x00337b04 : { *ai-startup-missionconditionprotectnpc.o(.text._ZN26MissionConditionProtectNPCD2Ev .text._ZN26MissionConditionProtectNPCD1Ev) }
    .mission_protect_vtable 0x004acec0 : { *ai-startup-missionconditionprotectnpc.o(.data.rel.ro._ZTV26MissionConditionProtectNPC) }
    .mission_condition_00337914 0x00337914 : { *ai-startup-missionconditionprotectnpc.o(.text._ZN26MissionConditionProtectNPCC1EP3NPCi .text._ZN26MissionConditionProtectNPCC2EP3NPCi) }
    .mission_condition_00337930 0x00337930 : { *ai-startup-missionconditionprotectnpc.o(.text._ZN26MissionConditionProtectNPC8evaluateEi) }
    .mission_condition_00337948 0x00337948 : { *ai-startup-missionconditionprotectnpc.o(.text._ZN26MissionConditionProtectNPC4drawEv) }
    .mission_condition_0033794c 0x0033794c : { *ai-startup-missionconditionprotectnpc.o(.text._ZNK26MissionConditionProtectNPC5causeEv) }
    .ai_startup_function_0 0x00337950 : { *ai-startup-missionconditionprotectnpc.o(.text.__tcf_2) }
    .ai_startup_function_1 0x00337980 : { *ai-startup-missionconditionprotectnpc.o(.text._Z41__static_initialization_and_destruction_0ii) }
    .ai_startup_function_2 0x00337ac4 : { *ai-startup-missionconditionprotectnpc.o(.text._GLOBAL__I__ZN26MissionConditionProtectNPCC2EP3NPCi) }
    .ai_startup_storage_0 0x004ba1f4 (NOLOAD) : { *ai-startup-missionconditionprotectnpc.o(.bss._ZN3irr5scene6quake315irrEmptyStringcE) }
    .ai_startup_storage_1 0x004ba214 (NOLOAD) : { *ai-startup-missionconditionprotectnpc.o(.bss._ZN3irr2ps5vHalfE) }
    .ai_startup_storage_2 0x004ba220 (NOLOAD) : { *ai-startup-missionconditionprotectnpc.o(.bss._ZN8gameloft2ai11civ_passiveE) }
    .ai_startup_storage_3 0x004ba228 (NOLOAD) : { *ai-startup-missionconditionprotectnpc.o(.bss._ZN8gameloft2ai12npc_scriptedE) }
    .ai_startup_storage_4 0x004ba230 (NOLOAD) : { *ai-startup-missionconditionprotectnpc.o(.bss._ZN8gameloft2ai13civ_agressiveE) }
    .ai_startup_storage_5 0x004ba238 (NOLOAD) : { *ai-startup-missionconditionprotectnpc.o(.bss._ZN8gameloft2ai11gang_memberE) }
    .ai_startup_storage_6 0x004ba240 (NOLOAD) : { *ai-startup-missionconditionprotectnpc.o(.bss._ZN8gameloft2ai3copE) }
    .ai_startup_storage_7 0x004ba248 (NOLOAD) : { *ai-startup-missionconditionprotectnpc.o(.bss._ZN8gameloft2ai4swatE) }
    .ai_startup_storage_8 0x004ba250 (NOLOAD) : { *ai-startup-missionconditionprotectnpc.o(.bss._ZN8gameloft2ai11civ_vehicleE) }
    .ai_startup_storage_9 0x004ba258 (NOLOAD) : { *ai-startup-missionconditionprotectnpc.o(.bss._ZN8gameloft2ai11cop_vehicleE) }
    .ai_startup_storage_10 0x004ba260 (NOLOAD) : { *ai-startup-missionconditionprotectnpc.o(.bss._ZN8gameloft2ai5guardE) }
    .ai_startup_storage_11 0x004ba268 (NOLOAD) : { *ai-startup-missionconditionprotectnpc.o(.bss._ZN8gameloft2ai16scripted_vehicleE) }
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
