OUTPUT_FORMAT("elf32-littlearm")
OUTPUT_ARCH(arm)
INCLUDE build/matches/ai-startup-wantedlevelmanager/retail-symbols.ld
_ZdlPv = 0x001c42b0;
__aeabi_atexit = 0x001c494c;
_ZN37retail_wantedlevelmanager_transitions16civPassive_transE = 0x00432a7c;
_ZN37retail_wantedlevelmanager_transitions17scriptedNpc_transE = 0x00432ba8;
_ZN37retail_wantedlevelmanager_transitions19civAggressive_transE = 0x00432bd8;
_ZN37retail_wantedlevelmanager_transitions16gangMember_transE = 0x00432cbc;
_ZN37retail_wantedlevelmanager_transitions9cop_transE = 0x00432cc8;
_ZN37retail_wantedlevelmanager_transitions10swat_transE = 0x00432e00;
_ZN37retail_wantedlevelmanager_transitions17civ_vehicle_transE = 0x00432e0c;
_ZN37retail_wantedlevelmanager_transitions17cop_vehicle_transE = 0x00432e9c;
_ZN37retail_wantedlevelmanager_transitions11guard_transE = 0x00432f50;
_ZN37retail_wantedlevelmanager_transitions22scripted_vehicle_transE = 0x00432ff8;
__cxa_pure_virtual = 0;
INCLUDE config/linker/ApplicationEventSections.ld
SECTIONS
{
    .wanted_escaped_delete 0x00342db4 : { *(.gnu.linkonce.t._ZN15EvWantedEscapedD0Ev) }
    .wanted_escaped_destroy 0x00342de0 : { *(.gnu.linkonce.t._ZN15EvWantedEscapedD1Ev) }
    .wanted_escaped_vtable 0x004ad080 : { *(.gnu.linkonce.d.rel.ro._ZTV15EvWantedEscaped) }
    .updatable_delete 0x002d62b8 : { *(.gnu.linkonce.t._ZN10IUpdatableD0Ev) }
    .receiver_delete 0x002db4b4 : { *(.gnu.linkonce.t._ZN14IEventReceiverD0Ev) }
    .updatable_vtable 0x004a6290 : { *(.gnu.linkonce.d.rel.ro._ZTV10IUpdatable) }
    .receiver_vtable 0x004a8b48 : { *(.gnu.linkonce.d.rel.ro._ZTV14IEventReceiver) }
    .wanted_delete_thunk 0x00342d18 : { *ai-startup-wantedlevelmanager.o(.text._ZThn4_N18WantedLevelManagerD0Ev) }
    .wanted_delete 0x00342d2c : { *ai-startup-wantedlevelmanager.o(.text._ZN18WantedLevelManagerD0Ev) }
    .wanted_destroy_thunk 0x00342d6c : { *ai-startup-wantedlevelmanager.o(.text._ZThn4_N18WantedLevelManagerD1Ev) }
    .wanted_destroy 0x00342d80 : { *ai-startup-wantedlevelmanager.o(.text._ZN18WantedLevelManagerD1Ev .text._ZN18WantedLevelManagerD2Ev) }
    .wanted_vtable 0x004ad050 : { *ai-startup-wantedlevelmanager.o(.data.rel.ro._ZTV18WantedLevelManager) }
    .wanted_clean 0x00342ad4 : { *ai-startup-wantedlevelmanager.o(.text._ZN18WantedLevelManager5cleanEv) }
    .wanted_store 0x00342a5c : { *ai-startup-wantedlevelmanager.o(.text._ZN18WantedLevelManager16storeWantedLevelEv) }
    .wanted_lock 0x00342a70 : { *ai-startup-wantedlevelmanager.o(.text._ZN18WantedLevelManager4lockEi) }
    .wanted_restore 0x00342f4c : { *ai-startup-wantedlevelmanager.o(.text._ZN18WantedLevelManager18restoreWantedLevelEv) }
    .wanted_reset 0x00342f7c : { *ai-startup-wantedlevelmanager.o(.text._ZN18WantedLevelManager16resetWantedLevelEv) }
    .wanted_unlock 0x00342a80 : { *ai-startup-wantedlevelmanager.o(.text._ZN18WantedLevelManager6unlockEv) }
    .ai_startup_function_0 0x00342a88 : { *ai-startup-wantedlevelmanager.o(.text.__tcf_5) }
    .ai_startup_function_1 0x00342bc0 : { *ai-startup-wantedlevelmanager.o(.text._Z41__static_initialization_and_destruction_0ii) }
    .ai_startup_function_2 0x00342d04 : { *ai-startup-wantedlevelmanager.o(.text._GLOBAL__I__ZN18WantedLevelManager18s_bTutoWantedLevelE) }
    .ai_startup_storage_0 0x004baa70 (NOLOAD) : { *ai-startup-wantedlevelmanager.o(.bss._ZN3irr5scene6quake315irrEmptyStringcE) }
    .ai_startup_storage_1 0x004baa90 (NOLOAD) : { *ai-startup-wantedlevelmanager.o(.bss._ZN3irr2ps5vHalfE) }
    .ai_startup_storage_2 0x004baa9c (NOLOAD) : { *ai-startup-wantedlevelmanager.o(.bss._ZN8gameloft2ai11civ_passiveE) }
    .ai_startup_storage_3 0x004baaa4 (NOLOAD) : { *ai-startup-wantedlevelmanager.o(.bss._ZN8gameloft2ai12npc_scriptedE) }
    .ai_startup_storage_4 0x004baaac (NOLOAD) : { *ai-startup-wantedlevelmanager.o(.bss._ZN8gameloft2ai13civ_agressiveE) }
    .ai_startup_storage_5 0x004baab4 (NOLOAD) : { *ai-startup-wantedlevelmanager.o(.bss._ZN8gameloft2ai11gang_memberE) }
    .ai_startup_storage_6 0x004baabc (NOLOAD) : { *ai-startup-wantedlevelmanager.o(.bss._ZN8gameloft2ai3copE) }
    .ai_startup_storage_7 0x004baac4 (NOLOAD) : { *ai-startup-wantedlevelmanager.o(.bss._ZN8gameloft2ai4swatE) }
    .ai_startup_storage_8 0x004baacc (NOLOAD) : { *ai-startup-wantedlevelmanager.o(.bss._ZN8gameloft2ai11civ_vehicleE) }
    .ai_startup_storage_9 0x004baad4 (NOLOAD) : { *ai-startup-wantedlevelmanager.o(.bss._ZN8gameloft2ai11cop_vehicleE) }
    .ai_startup_storage_10 0x004baadc (NOLOAD) : { *ai-startup-wantedlevelmanager.o(.bss._ZN8gameloft2ai5guardE) }
    .ai_startup_storage_11 0x004baae4 (NOLOAD) : { *ai-startup-wantedlevelmanager.o(.bss._ZN8gameloft2ai16scripted_vehicleE) }
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
