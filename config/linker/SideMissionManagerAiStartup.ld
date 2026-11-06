OUTPUT_FORMAT("elf32-littlearm")
OUTPUT_ARCH(arm)
INCLUDE build/matches/ai-startup-sidemissionmanager/retail-symbols.ld
_ZdlPv = 0x001c42b0;
__aeabi_atexit = 0x001c494c;
_ZN37retail_sidemissionmanager_transitions16civPassive_transE = 0x00434e90;
_ZN37retail_sidemissionmanager_transitions17scriptedNpc_transE = 0x00434fbc;
_ZN37retail_sidemissionmanager_transitions19civAggressive_transE = 0x00434fec;
_ZN37retail_sidemissionmanager_transitions16gangMember_transE = 0x004350d0;
_ZN37retail_sidemissionmanager_transitions9cop_transE = 0x004350dc;
_ZN37retail_sidemissionmanager_transitions10swat_transE = 0x00435214;
_ZN37retail_sidemissionmanager_transitions17civ_vehicle_transE = 0x00435220;
_ZN37retail_sidemissionmanager_transitions17cop_vehicle_transE = 0x004352b0;
_ZN37retail_sidemissionmanager_transitions11guard_transE = 0x00435364;
_ZN37retail_sidemissionmanager_transitions22scripted_vehicle_transE = 0x0043540c;
__cxa_guard_acquire = 0x001c4958;
__cxa_guard_release = 0x001c46c4;
SECTIONS
{
    .state_machine_singleton 0x002d44c4 : { *ai-startup-sidemissionmanager.o(.gnu.linkonce.t._ZN12StateMachine11getInstanceEv) }
    .state_machine_cleanup 0x00347a14 : { *ai-startup-sidemissionmanager.o(.text.__tcf_0) }
    .state_machine_guard 0x004b6904 (NOLOAD) : { *ai-startup-sidemissionmanager.o(.gnu.linkonce.b._ZGVZN12StateMachine11getInstanceEvE2sm) }
    .state_machine_instance 0x004b6908 (NOLOAD) : { *ai-startup-sidemissionmanager.o(.gnu.linkonce.b._ZZN12StateMachine11getInstanceEvE2sm) }
    .ai_startup_function_0 0x003477bc : { *ai-startup-sidemissionmanager.o(.text.__tcf_4) }
    .ai_startup_function_1 0x00347ce8 : { *ai-startup-sidemissionmanager.o(.text._Z41__static_initialization_and_destruction_0ii) }
    .ai_startup_function_2 0x00347e2c : { *ai-startup-sidemissionmanager.o(.text._GLOBAL__I__ZN18SideMissionManager22s_ambulanceSideMissionE) }
    .ai_startup_storage_0 0x004bb5c4 (NOLOAD) : { *ai-startup-sidemissionmanager.o(.bss._ZN3irr5scene6quake315irrEmptyStringcE) }
    .ai_startup_storage_1 0x004bb5e4 (NOLOAD) : { *ai-startup-sidemissionmanager.o(.bss._ZN3irr2ps5vHalfE) }
    .ai_startup_storage_2 0x004bb5f0 (NOLOAD) : { *ai-startup-sidemissionmanager.o(.bss._ZN8gameloft2ai11civ_passiveE) }
    .ai_startup_storage_3 0x004bb5f8 (NOLOAD) : { *ai-startup-sidemissionmanager.o(.bss._ZN8gameloft2ai12npc_scriptedE) }
    .ai_startup_storage_4 0x004bb600 (NOLOAD) : { *ai-startup-sidemissionmanager.o(.bss._ZN8gameloft2ai13civ_agressiveE) }
    .ai_startup_storage_5 0x004bb608 (NOLOAD) : { *ai-startup-sidemissionmanager.o(.bss._ZN8gameloft2ai11gang_memberE) }
    .ai_startup_storage_6 0x004bb610 (NOLOAD) : { *ai-startup-sidemissionmanager.o(.bss._ZN8gameloft2ai3copE) }
    .ai_startup_storage_7 0x004bb618 (NOLOAD) : { *ai-startup-sidemissionmanager.o(.bss._ZN8gameloft2ai4swatE) }
    .ai_startup_storage_8 0x004bb620 (NOLOAD) : { *ai-startup-sidemissionmanager.o(.bss._ZN8gameloft2ai11civ_vehicleE) }
    .ai_startup_storage_9 0x004bb628 (NOLOAD) : { *ai-startup-sidemissionmanager.o(.bss._ZN8gameloft2ai11cop_vehicleE) }
    .ai_startup_storage_10 0x004bb630 (NOLOAD) : { *ai-startup-sidemissionmanager.o(.bss._ZN8gameloft2ai5guardE) }
    .ai_startup_storage_11 0x004bb638 (NOLOAD) : { *ai-startup-sidemissionmanager.o(.bss._ZN8gameloft2ai16scripted_vehicleE) }
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
