OUTPUT_FORMAT("elf32-littlearm")
OUTPUT_ARCH(arm)
INCLUDE build/matches/ai-startup-script/retail-symbols.ld
_ZdlPv = 0x001c42b0;
__aeabi_atexit = 0x001c494c;
_ZN25retail_script_transitions16civPassive_transE = 0x0042ea20;
_ZN25retail_script_transitions17scriptedNpc_transE = 0x0042eb4c;
_ZN25retail_script_transitions19civAggressive_transE = 0x0042eb7c;
_ZN25retail_script_transitions16gangMember_transE = 0x0042ec60;
_ZN25retail_script_transitions9cop_transE = 0x0042ec6c;
_ZN25retail_script_transitions10swat_transE = 0x0042eda4;
_ZN25retail_script_transitions17civ_vehicle_transE = 0x0042edb0;
_ZN25retail_script_transitions17cop_vehicle_transE = 0x0042ee40;
_ZN25retail_script_transitions11guard_transE = 0x0042eef4;
_ZN25retail_script_transitions22scripted_vehicle_transE = 0x0042ef9c;
SECTIONS
{
    .script_finalize 0x00339c80 : { *ai-startup-script.o(.text._ZN6Script8finalizeEv) }
    .ai_startup_function_0 0x00339148 : { *ai-startup-script.o(.text.__tcf_6) }
    .ai_startup_function_1 0x003393ec : { *ai-startup-script.o(.text._Z41__static_initialization_and_destruction_0ii) }
    .ai_startup_function_2 0x00339530 : { *ai-startup-script.o(.text._GLOBAL__I__ZN6Script16s_driveBadPointsE) }
    .ai_startup_storage_0 0x004ba4fc (NOLOAD) : { *ai-startup-script.o(.bss._ZN3irr5scene6quake315irrEmptyStringcE) }
    .ai_startup_storage_1 0x004ba51c (NOLOAD) : { *ai-startup-script.o(.bss._ZN3irr2ps5vHalfE) }
    .ai_startup_storage_2 0x004ba528 (NOLOAD) : { *ai-startup-script.o(.bss._ZN8gameloft2ai11civ_passiveE) }
    .ai_startup_storage_3 0x004ba530 (NOLOAD) : { *ai-startup-script.o(.bss._ZN8gameloft2ai12npc_scriptedE) }
    .ai_startup_storage_4 0x004ba538 (NOLOAD) : { *ai-startup-script.o(.bss._ZN8gameloft2ai13civ_agressiveE) }
    .ai_startup_storage_5 0x004ba540 (NOLOAD) : { *ai-startup-script.o(.bss._ZN8gameloft2ai11gang_memberE) }
    .ai_startup_storage_6 0x004ba548 (NOLOAD) : { *ai-startup-script.o(.bss._ZN8gameloft2ai3copE) }
    .ai_startup_storage_7 0x004ba550 (NOLOAD) : { *ai-startup-script.o(.bss._ZN8gameloft2ai4swatE) }
    .ai_startup_storage_8 0x004ba558 (NOLOAD) : { *ai-startup-script.o(.bss._ZN8gameloft2ai11civ_vehicleE) }
    .ai_startup_storage_9 0x004ba560 (NOLOAD) : { *ai-startup-script.o(.bss._ZN8gameloft2ai11cop_vehicleE) }
    .ai_startup_storage_10 0x004ba568 (NOLOAD) : { *ai-startup-script.o(.bss._ZN8gameloft2ai5guardE) }
    .ai_startup_storage_11 0x004ba570 (NOLOAD) : { *ai-startup-script.o(.bss._ZN8gameloft2ai16scripted_vehicleE) }
    .script_add 0x003390a4 : { *ai-startup-script.o(.text._ZN6Script10addCommandEPN7Structs13ScriptCommandE) }
    .script_mission_id 0x003390c8 : { *ai-startup-script.o(.text._ZNK6Script12getMissionIdEv) }
    .script_ended 0x003390cc : { *ai-startup-script.o(.text._ZNK6Script7isEndedEv) }
    .script_state 0x003390e0 : { *ai-startup-script.o(.text._ZNK6Script8getStateEv) }
    .script_peek 0x003390e4 : { *ai-startup-script.o(.text._ZNK6Script11peekCommandEi) }
    .script_source 0x00339100 : { *ai-startup-script.o(.text._ZNK6Script9getSourceEv) }
    .script_set_parent 0x00339104 : { *ai-startup-script.o(.text._ZN6Script9setParentEPS_) }
    .script_parent 0x00339108 : { *ai-startup-script.o(.text._ZNK6Script9getParentEv) }
    .script_unlock 0x00339268 : { *ai-startup-script.o(.text._ZN6Script12unlockScriptEi) }
    .script_freeze 0x00339284 : { *ai-startup-script.o(.text._ZN6Script12freezeScriptEi) }
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
