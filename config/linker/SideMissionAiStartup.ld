OUTPUT_FORMAT("elf32-littlearm")
OUTPUT_ARCH(arm)
INCLUDE build/matches/ai-startup-sidemission/retail-symbols.ld
_ZdlPv = 0x001c42b0;
__aeabi_atexit = 0x001c494c;
_ZN30retail_sidemission_transitions16civPassive_transE = 0x004348a4;
_ZN30retail_sidemission_transitions17scriptedNpc_transE = 0x004349d0;
_ZN30retail_sidemission_transitions19civAggressive_transE = 0x00434a00;
_ZN30retail_sidemission_transitions16gangMember_transE = 0x00434ae4;
_ZN30retail_sidemission_transitions9cop_transE = 0x00434af0;
_ZN30retail_sidemission_transitions10swat_transE = 0x00434c28;
_ZN30retail_sidemission_transitions17civ_vehicle_transE = 0x00434c34;
_ZN30retail_sidemission_transitions17cop_vehicle_transE = 0x00434cc4;
_ZN30retail_sidemission_transitions11guard_transE = 0x00434d78;
_ZN30retail_sidemission_transitions22scripted_vehicle_transE = 0x00434e20;
__cxa_guard_acquire = 0x001c4958;
__cxa_guard_release = 0x001c46c4;
SECTIONS
{
    .ai_manager_singleton 0x002dbae8 : { *ai-startup-sidemission.o(.gnu.linkonce.t._ZN9AIManager11getInstanceEv) }
    .ai_manager_cleanup 0x00346d00 : { *ai-startup-sidemission.o(.text.__tcf_1) }
    .ai_manager_guard 0x004b6a90 (NOLOAD) : { *ai-startup-sidemission.o(.gnu.linkonce.b._ZGVZN9AIManager11getInstanceEvE3aim) }
    .ai_manager_instance 0x004b6ae8 (NOLOAD) : { *ai-startup-sidemission.o(.gnu.linkonce.b._ZZN9AIManager11getInstanceEvE3aim) }
    .state_machine_singleton 0x002d44c4 : { *ai-startup-sidemission.o(.gnu.linkonce.t._ZN12StateMachine11getInstanceEv) }
    .state_machine_cleanup 0x00346ca4 : { *ai-startup-sidemission.o(.text.__tcf_0) }
    .state_machine_guard 0x004b6904 (NOLOAD) : { *ai-startup-sidemission.o(.gnu.linkonce.b._ZGVZN12StateMachine11getInstanceEvE2sm) }
    .state_machine_instance 0x004b6908 (NOLOAD) : { *ai-startup-sidemission.o(.gnu.linkonce.b._ZZN12StateMachine11getInstanceEvE2sm) }
    .ai_startup_function_0 0x00346c74 : { *ai-startup-sidemission.o(.text.__tcf_5) }
    .ai_startup_function_1 0x003474c0 : { *ai-startup-sidemission.o(.text._Z41__static_initialization_and_destruction_0ii) }
    .ai_startup_function_2 0x00347604 : { *ai-startup-sidemission.o(.text._GLOBAL__I__ZN11SideMission13addCheckpointEiN3irr4core8vector3dIfEEfftRt) }
    .ai_startup_storage_0 0x004bb530 (NOLOAD) : { *ai-startup-sidemission.o(.bss._ZN3irr5scene6quake315irrEmptyStringcE) }
    .ai_startup_storage_1 0x004bb550 (NOLOAD) : { *ai-startup-sidemission.o(.bss._ZN3irr2ps5vHalfE) }
    .ai_startup_storage_2 0x004bb55c (NOLOAD) : { *ai-startup-sidemission.o(.bss._ZN8gameloft2ai11civ_passiveE) }
    .ai_startup_storage_3 0x004bb564 (NOLOAD) : { *ai-startup-sidemission.o(.bss._ZN8gameloft2ai12npc_scriptedE) }
    .ai_startup_storage_4 0x004bb56c (NOLOAD) : { *ai-startup-sidemission.o(.bss._ZN8gameloft2ai13civ_agressiveE) }
    .ai_startup_storage_5 0x004bb574 (NOLOAD) : { *ai-startup-sidemission.o(.bss._ZN8gameloft2ai11gang_memberE) }
    .ai_startup_storage_6 0x004bb57c (NOLOAD) : { *ai-startup-sidemission.o(.bss._ZN8gameloft2ai3copE) }
    .ai_startup_storage_7 0x004bb584 (NOLOAD) : { *ai-startup-sidemission.o(.bss._ZN8gameloft2ai4swatE) }
    .ai_startup_storage_8 0x004bb58c (NOLOAD) : { *ai-startup-sidemission.o(.bss._ZN8gameloft2ai11civ_vehicleE) }
    .ai_startup_storage_9 0x004bb594 (NOLOAD) : { *ai-startup-sidemission.o(.bss._ZN8gameloft2ai11cop_vehicleE) }
    .ai_startup_storage_10 0x004bb59c (NOLOAD) : { *ai-startup-sidemission.o(.bss._ZN8gameloft2ai5guardE) }
    .ai_startup_storage_11 0x004bb5a4 (NOLOAD) : { *ai-startup-sidemission.o(.bss._ZN8gameloft2ai16scripted_vehicleE) }
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
