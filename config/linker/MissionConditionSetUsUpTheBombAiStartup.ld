OUTPUT_FORMAT("elf32-littlearm")
OUTPUT_ARCH(arm)
INCLUDE build/matches/ai-startup-missionconditionsetusupthebomb/retail-symbols.ld
_ZdlPv = 0x001c42b0;
__aeabi_atexit = 0x001c494c;
_ZN49retail_missionconditionsetusupthebomb_transitions16civPassive_transE = 0x0042cb10;
_ZN49retail_missionconditionsetusupthebomb_transitions17scriptedNpc_transE = 0x0042cc3c;
_ZN49retail_missionconditionsetusupthebomb_transitions19civAggressive_transE = 0x0042cc6c;
_ZN49retail_missionconditionsetusupthebomb_transitions16gangMember_transE = 0x0042cd50;
_ZN49retail_missionconditionsetusupthebomb_transitions9cop_transE = 0x0042cd5c;
_ZN49retail_missionconditionsetusupthebomb_transitions10swat_transE = 0x0042ce94;
_ZN49retail_missionconditionsetusupthebomb_transitions17civ_vehicle_transE = 0x0042cea0;
_ZN49retail_missionconditionsetusupthebomb_transitions17cop_vehicle_transE = 0x0042cf30;
_ZN49retail_missionconditionsetusupthebomb_transitions11guard_transE = 0x0042cfe4;
_ZN49retail_missionconditionsetusupthebomb_transitions22scripted_vehicle_transE = 0x0042d08c;
SECTIONS
{
    .mission_bomb_00337b58 0x00337b58 : { *ai-startup-missionconditionsetusupthebomb.o(.text._ZN30MissionConditionSetUsUpTheBomb4drawEv) }
    .mission_bomb_00337b64 0x00337b64 : { *ai-startup-missionconditionsetusupthebomb.o(.text._ZN30MissionConditionSetUsUpTheBomb8evaluateEi) }
    .mission_bomb_00337b80 0x00337b80 : { *ai-startup-missionconditionsetusupthebomb.o(.text._ZN30MissionConditionSetUsUpTheBombD0Ev) }
    .mission_bomb_00337ba8 0x00337ba8 : { *ai-startup-missionconditionsetusupthebomb.o(.text._ZN30MissionConditionSetUsUpTheBombD1Ev .text._ZN30MissionConditionSetUsUpTheBombD2Ev) }
    .mission_bomb_00337bc8 0x00337bc8 : { *ai-startup-missionconditionsetusupthebomb.o(.text._ZN30MissionConditionSetUsUpTheBombC2EiP7Vehicle .text._ZN30MissionConditionSetUsUpTheBombC1EiP7Vehicle) }
    .mission_bomb_vtable 0x004acee0 : { *ai-startup-missionconditionsetusupthebomb.o(.data.rel.ro._ZTV30MissionConditionSetUsUpTheBomb .gnu.linkonce.d.rel.ro._ZTV30MissionConditionSetUsUpTheBomb) }
    .ai_startup_function_0 0x00337b28 : { *ai-startup-missionconditionsetusupthebomb.o(.text.__tcf_3) }
    .ai_startup_function_1 0x00337bec : { *ai-startup-missionconditionsetusupthebomb.o(.text._Z41__static_initialization_and_destruction_0ii) }
    .ai_startup_function_2 0x00337d30 : { *ai-startup-missionconditionsetusupthebomb.o(.text._GLOBAL__I__ZN30MissionConditionSetUsUpTheBombC2EiP7Vehicle) }
    .ai_startup_storage_0 0x004ba270 (NOLOAD) : { *ai-startup-missionconditionsetusupthebomb.o(.bss._ZN3irr5scene6quake315irrEmptyStringcE) }
    .ai_startup_storage_1 0x004ba290 (NOLOAD) : { *ai-startup-missionconditionsetusupthebomb.o(.bss._ZN3irr2ps5vHalfE) }
    .ai_startup_storage_2 0x004ba29c (NOLOAD) : { *ai-startup-missionconditionsetusupthebomb.o(.bss._ZN8gameloft2ai11civ_passiveE) }
    .ai_startup_storage_3 0x004ba2a4 (NOLOAD) : { *ai-startup-missionconditionsetusupthebomb.o(.bss._ZN8gameloft2ai12npc_scriptedE) }
    .ai_startup_storage_4 0x004ba2ac (NOLOAD) : { *ai-startup-missionconditionsetusupthebomb.o(.bss._ZN8gameloft2ai13civ_agressiveE) }
    .ai_startup_storage_5 0x004ba2b4 (NOLOAD) : { *ai-startup-missionconditionsetusupthebomb.o(.bss._ZN8gameloft2ai11gang_memberE) }
    .ai_startup_storage_6 0x004ba2bc (NOLOAD) : { *ai-startup-missionconditionsetusupthebomb.o(.bss._ZN8gameloft2ai3copE) }
    .ai_startup_storage_7 0x004ba2c4 (NOLOAD) : { *ai-startup-missionconditionsetusupthebomb.o(.bss._ZN8gameloft2ai4swatE) }
    .ai_startup_storage_8 0x004ba2cc (NOLOAD) : { *ai-startup-missionconditionsetusupthebomb.o(.bss._ZN8gameloft2ai11civ_vehicleE) }
    .ai_startup_storage_9 0x004ba2d4 (NOLOAD) : { *ai-startup-missionconditionsetusupthebomb.o(.bss._ZN8gameloft2ai11cop_vehicleE) }
    .ai_startup_storage_10 0x004ba2dc (NOLOAD) : { *ai-startup-missionconditionsetusupthebomb.o(.bss._ZN8gameloft2ai5guardE) }
    .ai_startup_storage_11 0x004ba2e4 (NOLOAD) : { *ai-startup-missionconditionsetusupthebomb.o(.bss._ZN8gameloft2ai16scripted_vehicleE) }
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
