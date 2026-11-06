OUTPUT_FORMAT("elf32-littlearm")
OUTPUT_ARCH(arm)
INCLUDE build/matches/ai-startup-taxisidemission/retail-symbols.ld
_ZdlPv = 0x001c42b0;
__aeabi_atexit = 0x001c494c;
_ZN34retail_taxisidemission_transitions16civPassive_transE = 0x00435460;
_ZN34retail_taxisidemission_transitions17scriptedNpc_transE = 0x0043558c;
_ZN34retail_taxisidemission_transitions19civAggressive_transE = 0x004355bc;
_ZN34retail_taxisidemission_transitions16gangMember_transE = 0x004356a0;
_ZN34retail_taxisidemission_transitions9cop_transE = 0x004356ac;
_ZN34retail_taxisidemission_transitions10swat_transE = 0x004357e4;
_ZN34retail_taxisidemission_transitions17civ_vehicle_transE = 0x004357f0;
_ZN34retail_taxisidemission_transitions17cop_vehicle_transE = 0x00435880;
_ZN34retail_taxisidemission_transitions11guard_transE = 0x00435934;
_ZN34retail_taxisidemission_transitions22scripted_vehicle_transE = 0x004359dc;
__cxa_guard_acquire = 0x001c4958;
__cxa_guard_release = 0x001c46c4;
SECTIONS
{
    .ai_manager_singleton 0x002dbae8 : { *ai-startup-taxisidemission.o(.gnu.linkonce.t._ZN9AIManager11getInstanceEv) }
    .ai_manager_cleanup 0x00347ecc : { *ai-startup-taxisidemission.o(.text.__tcf_0) }
    .ai_manager_guard 0x004b6a90 (NOLOAD) : { *ai-startup-taxisidemission.o(.gnu.linkonce.b._ZGVZN9AIManager11getInstanceEvE3aim) }
    .ai_manager_instance 0x004b6ae8 (NOLOAD) : { *ai-startup-taxisidemission.o(.gnu.linkonce.b._ZZN9AIManager11getInstanceEvE3aim) }
    .ai_startup_function_0 0x00347e8c : { *ai-startup-taxisidemission.o(.text.__tcf_4) }
    .ai_startup_function_1 0x00348330 : { *ai-startup-taxisidemission.o(.text._Z41__static_initialization_and_destruction_0ii) }
    .ai_startup_function_2 0x00348474 : { *ai-startup-taxisidemission.o(.text._GLOBAL__I__ZN15TaxiSideMissionC2Ev) }
    .ai_startup_storage_0 0x004bb640 (NOLOAD) : { *ai-startup-taxisidemission.o(.bss._ZN3irr5scene6quake315irrEmptyStringcE) }
    .ai_startup_storage_1 0x004bb660 (NOLOAD) : { *ai-startup-taxisidemission.o(.bss._ZN3irr2ps5vHalfE) }
    .ai_startup_storage_2 0x004bb66c (NOLOAD) : { *ai-startup-taxisidemission.o(.bss._ZN8gameloft2ai11civ_passiveE) }
    .ai_startup_storage_3 0x004bb674 (NOLOAD) : { *ai-startup-taxisidemission.o(.bss._ZN8gameloft2ai12npc_scriptedE) }
    .ai_startup_storage_4 0x004bb67c (NOLOAD) : { *ai-startup-taxisidemission.o(.bss._ZN8gameloft2ai13civ_agressiveE) }
    .ai_startup_storage_5 0x004bb684 (NOLOAD) : { *ai-startup-taxisidemission.o(.bss._ZN8gameloft2ai11gang_memberE) }
    .ai_startup_storage_6 0x004bb68c (NOLOAD) : { *ai-startup-taxisidemission.o(.bss._ZN8gameloft2ai3copE) }
    .ai_startup_storage_7 0x004bb694 (NOLOAD) : { *ai-startup-taxisidemission.o(.bss._ZN8gameloft2ai4swatE) }
    .ai_startup_storage_8 0x004bb69c (NOLOAD) : { *ai-startup-taxisidemission.o(.bss._ZN8gameloft2ai11civ_vehicleE) }
    .ai_startup_storage_9 0x004bb6a4 (NOLOAD) : { *ai-startup-taxisidemission.o(.bss._ZN8gameloft2ai11cop_vehicleE) }
    .ai_startup_storage_10 0x004bb6ac (NOLOAD) : { *ai-startup-taxisidemission.o(.bss._ZN8gameloft2ai5guardE) }
    .ai_startup_storage_11 0x004bb6b4 (NOLOAD) : { *ai-startup-taxisidemission.o(.bss._ZN8gameloft2ai16scripted_vehicleE) }
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
