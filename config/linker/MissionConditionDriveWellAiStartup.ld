OUTPUT_FORMAT("elf32-littlearm")
OUTPUT_ARCH(arm)
INCLUDE build/matches/ai-startup-missionconditiondrivewell/retail-symbols.ld
_ZdlPv = 0x001c42b0;
__aeabi_atexit = 0x001c494c;
_ZN44retail_missionconditiondrivewell_transitions16civPassive_transE = 0x0042b3d0;
_ZN44retail_missionconditiondrivewell_transitions17scriptedNpc_transE = 0x0042b4fc;
_ZN44retail_missionconditiondrivewell_transitions19civAggressive_transE = 0x0042b52c;
_ZN44retail_missionconditiondrivewell_transitions16gangMember_transE = 0x0042b610;
_ZN44retail_missionconditiondrivewell_transitions9cop_transE = 0x0042b61c;
_ZN44retail_missionconditiondrivewell_transitions10swat_transE = 0x0042b754;
_ZN44retail_missionconditiondrivewell_transitions17civ_vehicle_transE = 0x0042b760;
_ZN44retail_missionconditiondrivewell_transitions17cop_vehicle_transE = 0x0042b7f0;
_ZN44retail_missionconditiondrivewell_transitions11guard_transE = 0x0042b8a4;
_ZN44retail_missionconditiondrivewell_transitions22scripted_vehicle_transE = 0x0042b94c;
__cxa_guard_acquire = 0x001c4958;
__cxa_guard_release = 0x001c46c4;
SECTIONS
{
    .wanted_singleton 0x002dba04 : { *ai-startup-missionconditiondrivewell.o(.gnu.linkonce.t._ZN18WantedLevelManager11getInstanceEv) }
    .wanted_cleanup 0x00336df4 : { *ai-startup-missionconditiondrivewell.o(.text.__tcf_0) }
    .wanted_guard 0x004b6728 (NOLOAD) : { *ai-startup-missionconditiondrivewell.o(.gnu.linkonce.b._ZGVZN18WantedLevelManager11getInstanceEvE3wlm) }
    .wanted_instance 0x004b6a98 (NOLOAD) : { *ai-startup-missionconditiondrivewell.o(.gnu.linkonce.b._ZZN18WantedLevelManager11getInstanceEvE3wlm) }
    .ai_startup_function_0 0x00336dc4 : { *ai-startup-missionconditiondrivewell.o(.text.__tcf_4) }
    .ai_startup_function_1 0x003371b8 : { *ai-startup-missionconditiondrivewell.o(.text._Z41__static_initialization_and_destruction_0ii) }
    .ai_startup_function_2 0x003372fc : { *ai-startup-missionconditiondrivewell.o(.text._GLOBAL__I__ZN25MissionConditionDriveWellC2EP7Vehicle) }
    .ai_startup_storage_0 0x004ba080 (NOLOAD) : { *ai-startup-missionconditiondrivewell.o(.bss._ZN3irr5scene6quake315irrEmptyStringcE) }
    .ai_startup_storage_1 0x004ba0a0 (NOLOAD) : { *ai-startup-missionconditiondrivewell.o(.bss._ZN3irr2ps5vHalfE) }
    .ai_startup_storage_2 0x004ba0ac (NOLOAD) : { *ai-startup-missionconditiondrivewell.o(.bss._ZN8gameloft2ai11civ_passiveE) }
    .ai_startup_storage_3 0x004ba0b4 (NOLOAD) : { *ai-startup-missionconditiondrivewell.o(.bss._ZN8gameloft2ai12npc_scriptedE) }
    .ai_startup_storage_4 0x004ba0bc (NOLOAD) : { *ai-startup-missionconditiondrivewell.o(.bss._ZN8gameloft2ai13civ_agressiveE) }
    .ai_startup_storage_5 0x004ba0c4 (NOLOAD) : { *ai-startup-missionconditiondrivewell.o(.bss._ZN8gameloft2ai11gang_memberE) }
    .ai_startup_storage_6 0x004ba0cc (NOLOAD) : { *ai-startup-missionconditiondrivewell.o(.bss._ZN8gameloft2ai3copE) }
    .ai_startup_storage_7 0x004ba0d4 (NOLOAD) : { *ai-startup-missionconditiondrivewell.o(.bss._ZN8gameloft2ai4swatE) }
    .ai_startup_storage_8 0x004ba0dc (NOLOAD) : { *ai-startup-missionconditiondrivewell.o(.bss._ZN8gameloft2ai11civ_vehicleE) }
    .ai_startup_storage_9 0x004ba0e4 (NOLOAD) : { *ai-startup-missionconditiondrivewell.o(.bss._ZN8gameloft2ai11cop_vehicleE) }
    .ai_startup_storage_10 0x004ba0ec (NOLOAD) : { *ai-startup-missionconditiondrivewell.o(.bss._ZN8gameloft2ai5guardE) }
    .ai_startup_storage_11 0x004ba0f4 (NOLOAD) : { *ai-startup-missionconditiondrivewell.o(.bss._ZN8gameloft2ai16scripted_vehicleE) }
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
