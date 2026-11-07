OUTPUT_FORMAT("elf32-littlearm")
OUTPUT_ARCH(arm)
INCLUDE build/matches/ai-startup-character/retail-symbols.ld
_ZdlPv = 0x001c42b0;
__aeabi_atexit = 0x001c494c;
_ZN28retail_character_transitions16civPassive_transE = 0x0041c640;
_ZN28retail_character_transitions17scriptedNpc_transE = 0x0041c76c;
_ZN28retail_character_transitions19civAggressive_transE = 0x0041c79c;
_ZN28retail_character_transitions16gangMember_transE = 0x0041c880;
_ZN28retail_character_transitions9cop_transE = 0x0041c88c;
_ZN28retail_character_transitions10swat_transE = 0x0041c9c4;
_ZN28retail_character_transitions17civ_vehicle_transE = 0x0041c9d0;
_ZN28retail_character_transitions17cop_vehicle_transE = 0x0041ca60;
_ZN28retail_character_transitions11guard_transE = 0x0041cb14;
_ZN28retail_character_transitions22scripted_vehicle_transE = 0x0041cbbc;
__cxa_guard_acquire = 0x001c4958;
__cxa_guard_release = 0x001c46c4;
INCLUDE config/linker/CharacterStateSections.ld
SECTIONS
{
    .ai_manager_singleton 0x002dbae8 : { *ai-startup-character.o(.gnu.linkonce.t._ZN9AIManager11getInstanceEv) }
    .ai_manager_cleanup 0x002f1a14 : { *ai-startup-character.o(.text.__tcf_0) }
    .ai_manager_guard 0x004b6a90 (NOLOAD) : { *ai-startup-character.o(.gnu.linkonce.b._ZGVZN9AIManager11getInstanceEvE3aim) }
    .ai_manager_instance 0x004b6ae8 (NOLOAD) : { *ai-startup-character.o(.gnu.linkonce.b._ZZN9AIManager11getInstanceEvE3aim) }
    .ai_startup_function_0 0x002f1808 : { *ai-startup-character.o(.text.__tcf_4) }
    .ai_startup_function_1 0x002f3330 : { *ai-startup-character.o(.text._Z41__static_initialization_and_destruction_0ii) }
    .ai_startup_function_2 0x002f3474 : { *ai-startup-character.o(.text._GLOBAL__I__ZN9Character20s_timelineControllerE) }
    .ai_startup_storage_0 0x004b7dd8 (NOLOAD) : { *ai-startup-character.o(.bss._ZN3irr5scene6quake315irrEmptyStringcE) }
    .ai_startup_storage_1 0x004b7df8 (NOLOAD) : { *ai-startup-character.o(.bss._ZN3irr2ps5vHalfE) }
    .ai_startup_storage_2 0x004b7e04 (NOLOAD) : { *ai-startup-character.o(.bss._ZN8gameloft2ai11civ_passiveE) }
    .ai_startup_storage_3 0x004b7e0c (NOLOAD) : { *ai-startup-character.o(.bss._ZN8gameloft2ai12npc_scriptedE) }
    .ai_startup_storage_4 0x004b7e14 (NOLOAD) : { *ai-startup-character.o(.bss._ZN8gameloft2ai13civ_agressiveE) }
    .ai_startup_storage_5 0x004b7e1c (NOLOAD) : { *ai-startup-character.o(.bss._ZN8gameloft2ai11gang_memberE) }
    .ai_startup_storage_6 0x004b7e24 (NOLOAD) : { *ai-startup-character.o(.bss._ZN8gameloft2ai3copE) }
    .ai_startup_storage_7 0x004b7e2c (NOLOAD) : { *ai-startup-character.o(.bss._ZN8gameloft2ai4swatE) }
    .ai_startup_storage_8 0x004b7e34 (NOLOAD) : { *ai-startup-character.o(.bss._ZN8gameloft2ai11civ_vehicleE) }
    .ai_startup_storage_9 0x004b7e3c (NOLOAD) : { *ai-startup-character.o(.bss._ZN8gameloft2ai11cop_vehicleE) }
    .ai_startup_storage_10 0x004b7e44 (NOLOAD) : { *ai-startup-character.o(.bss._ZN8gameloft2ai5guardE) }
    .ai_startup_storage_11 0x004b7e4c (NOLOAD) : { *ai-startup-character.o(.bss._ZN8gameloft2ai16scripted_vehicleE) }
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
