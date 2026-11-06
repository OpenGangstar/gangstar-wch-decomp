OUTPUT_FORMAT("elf32-littlearm")
OUTPUT_ARCH(arm)
INCLUDE build/matches/ai-startup-spawnpoint/retail-symbols.ld
_ZdlPv = 0x001c42b0;
__aeabi_atexit = 0x001c494c;
_ZN29retail_spawnpoint_transitions16civPassive_transE = 0x0041eee0;
_ZN29retail_spawnpoint_transitions17scriptedNpc_transE = 0x0041f00c;
_ZN29retail_spawnpoint_transitions19civAggressive_transE = 0x0041f03c;
_ZN29retail_spawnpoint_transitions16gangMember_transE = 0x0041f120;
_ZN29retail_spawnpoint_transitions9cop_transE = 0x0041f12c;
_ZN29retail_spawnpoint_transitions10swat_transE = 0x0041f264;
_ZN29retail_spawnpoint_transitions17civ_vehicle_transE = 0x0041f270;
_ZN29retail_spawnpoint_transitions17cop_vehicle_transE = 0x0041f300;
_ZN29retail_spawnpoint_transitions11guard_transE = 0x0041f3b4;
_ZN29retail_spawnpoint_transitions22scripted_vehicle_transE = 0x0041f45c;
__cxa_guard_acquire = 0x001c4958;
__cxa_guard_release = 0x001c46c4;
SECTIONS
{
    .ai_manager_singleton 0x002dbae8 : { *ai-startup-spawnpoint.o(.gnu.linkonce.t._ZN9AIManager11getInstanceEv) }
    .ai_manager_cleanup 0x00306458 : { *ai-startup-spawnpoint.o(.text.__tcf_1) }
    .ai_manager_guard 0x004b6a90 (NOLOAD) : { *ai-startup-spawnpoint.o(.gnu.linkonce.b._ZGVZN9AIManager11getInstanceEvE3aim) }
    .ai_manager_instance 0x004b6ae8 (NOLOAD) : { *ai-startup-spawnpoint.o(.gnu.linkonce.b._ZZN9AIManager11getInstanceEvE3aim) }
    .wanted_singleton 0x002dba04 : { *ai-startup-spawnpoint.o(.gnu.linkonce.t._ZN18WantedLevelManager11getInstanceEv) }
    .wanted_cleanup 0x0030643c : { *ai-startup-spawnpoint.o(.text.__tcf_0) }
    .wanted_guard 0x004b6728 (NOLOAD) : { *ai-startup-spawnpoint.o(.gnu.linkonce.b._ZGVZN18WantedLevelManager11getInstanceEvE3wlm) }
    .wanted_instance 0x004b6a98 (NOLOAD) : { *ai-startup-spawnpoint.o(.gnu.linkonce.b._ZZN18WantedLevelManager11getInstanceEvE3wlm) }
    .ai_startup_function_0 0x00306ff8 : { *ai-startup-spawnpoint.o(.text.__tcf_5) }
    .ai_startup_function_1 0x00306e24 : { *ai-startup-spawnpoint.o(.text._Z41__static_initialization_and_destruction_0ii) }
    .ai_startup_function_2 0x00306fe4 : { *ai-startup-spawnpoint.o(.text._GLOBAL__I__ZN10SpawnPoint16s_innerCenterCivE) }
    .ai_startup_function_3 0x003070cc : { *ai-startup-spawnpoint.o(.text.__tcf_6) }
    .ai_startup_storage_0 0x004b867c (NOLOAD) : { *ai-startup-spawnpoint.o(.bss._ZN3irr5scene6quake315irrEmptyStringcE) }
    .ai_startup_storage_1 0x004b869c (NOLOAD) : { *ai-startup-spawnpoint.o(.bss._ZN3irr2ps5vHalfE) }
    .ai_startup_storage_2 0x004b86a8 (NOLOAD) : { *ai-startup-spawnpoint.o(.bss._ZN8gameloft2ai11civ_passiveE) }
    .ai_startup_storage_3 0x004b86b0 (NOLOAD) : { *ai-startup-spawnpoint.o(.bss._ZN8gameloft2ai12npc_scriptedE) }
    .ai_startup_storage_4 0x004b86b8 (NOLOAD) : { *ai-startup-spawnpoint.o(.bss._ZN8gameloft2ai13civ_agressiveE) }
    .ai_startup_storage_5 0x004b86c0 (NOLOAD) : { *ai-startup-spawnpoint.o(.bss._ZN8gameloft2ai11gang_memberE) }
    .ai_startup_storage_6 0x004b86c8 (NOLOAD) : { *ai-startup-spawnpoint.o(.bss._ZN8gameloft2ai3copE) }
    .ai_startup_storage_7 0x004b86d0 (NOLOAD) : { *ai-startup-spawnpoint.o(.bss._ZN8gameloft2ai4swatE) }
    .ai_startup_storage_8 0x004b86d8 (NOLOAD) : { *ai-startup-spawnpoint.o(.bss._ZN8gameloft2ai11civ_vehicleE) }
    .ai_startup_storage_9 0x004b86e0 (NOLOAD) : { *ai-startup-spawnpoint.o(.bss._ZN8gameloft2ai11cop_vehicleE) }
    .ai_startup_storage_10 0x004b86e8 (NOLOAD) : { *ai-startup-spawnpoint.o(.bss._ZN8gameloft2ai5guardE) }
    .ai_startup_storage_11 0x004b86f0 (NOLOAD) : { *ai-startup-spawnpoint.o(.bss._ZN8gameloft2ai16scripted_vehicleE) }
    .ai_startup_storage_12 0x004b8218 (NOLOAD) : { *ai-startup-spawnpoint.o(.bss._ZN10SpawnPoint16s_innerCenterCivE) }
    .ai_startup_storage_13 0x004b8224 (NOLOAD) : { *ai-startup-spawnpoint.o(.bss._ZN10SpawnPoint17s_outterCenterCivE) }
    .ai_startup_storage_14 0x004b8230 (NOLOAD) : { *ai-startup-spawnpoint.o(.bss._ZN10SpawnPoint16s_innerCenterCarE) }
    .ai_startup_storage_15 0x004b823c (NOLOAD) : { *ai-startup-spawnpoint.o(.bss._ZN10SpawnPoint17s_outterCenterCarE) }
    .ai_startup_storage_16 0x004b8248 (NOLOAD) : { *ai-startup-spawnpoint.o(.bss._ZN10SpawnPoint22s_innerCenterParkedCarE) }
    .ai_startup_storage_17 0x004b8254 (NOLOAD) : { *ai-startup-spawnpoint.o(.bss._ZN10SpawnPoint23s_outterCenterParkedCarE) }
    .ai_startup_storage_18 0x004b8260 (NOLOAD) : { *ai-startup-spawnpoint.o(.bss._ZN10SpawnPoint13s_spawnPointsE) }
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
ASSERT(SIZEOF(.ai_startup_storage_12) == 12, "_ZN10SpawnPoint16s_innerCenterCivE extent");
ASSERT(SIZEOF(.ai_startup_storage_13) == 12, "_ZN10SpawnPoint17s_outterCenterCivE extent");
ASSERT(SIZEOF(.ai_startup_storage_14) == 12, "_ZN10SpawnPoint16s_innerCenterCarE extent");
ASSERT(SIZEOF(.ai_startup_storage_15) == 12, "_ZN10SpawnPoint17s_outterCenterCarE extent");
ASSERT(SIZEOF(.ai_startup_storage_16) == 12, "_ZN10SpawnPoint22s_innerCenterParkedCarE extent");
ASSERT(SIZEOF(.ai_startup_storage_17) == 12, "_ZN10SpawnPoint23s_outterCenterParkedCarE extent");
ASSERT(SIZEOF(.ai_startup_storage_18) == 12, "_ZN10SpawnPoint13s_spawnPointsE extent");
