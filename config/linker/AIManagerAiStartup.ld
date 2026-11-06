OUTPUT_FORMAT("elf32-littlearm")
OUTPUT_ARCH(arm)
INCLUDE build/matches/ai-startup-aimanager/retail-symbols.ld
_ZdlPv = 0x001c42b0;
__aeabi_atexit = 0x001c494c;
_ZN28retail_aimanager_transitions16civPassive_transE = 0x0042fad8;
_ZN28retail_aimanager_transitions17scriptedNpc_transE = 0x0042fc04;
_ZN28retail_aimanager_transitions19civAggressive_transE = 0x0042fc34;
_ZN28retail_aimanager_transitions16gangMember_transE = 0x0042fd18;
_ZN28retail_aimanager_transitions9cop_transE = 0x0042fd24;
_ZN28retail_aimanager_transitions10swat_transE = 0x0042fe5c;
_ZN28retail_aimanager_transitions17civ_vehicle_transE = 0x0042fe68;
_ZN28retail_aimanager_transitions17cop_vehicle_transE = 0x0042fef8;
_ZN28retail_aimanager_transitions11guard_transE = 0x0042ffac;
_ZN28retail_aimanager_transitions22scripted_vehicle_transE = 0x00430054;
__cxa_pure_virtual = 0;
INCLUDE config/linker/ApplicationEventSections.ld
SECTIONS
{
    .wanted_changed_delete 0x003405cc : { *(.gnu.linkonce.t._ZN20EvWantedLevelChangedD0Ev) }
    .wanted_changed_destroy 0x003402e0 : { *(.gnu.linkonce.t._ZN20EvWantedLevelChangedD1Ev) }
    .wanted_changed_vtable 0x004acf80 : { *(.gnu.linkonce.d.rel.ro._ZTV20EvWantedLevelChanged) }
    .receiver_delete 0x002db4b4 : { *(.gnu.linkonce.t._ZN14IEventReceiverD0Ev) }
    .receiver_vtable 0x004a8b48 : { *(.gnu.linkonce.d.rel.ro._ZTV14IEventReceiver) }
    .ai_manager_construct 0x00340128 : { *ai-startup-aimanager.o(.text._ZN9AIManagerC1Ev .text._ZN9AIManagerC2Ev) }
    .ai_manager_delete 0x003405f8 : { *ai-startup-aimanager.o(.text._ZN9AIManagerD0Ev) }
    .ai_manager_destroy 0x00340638 : { *ai-startup-aimanager.o(.text._ZN9AIManagerD1Ev .text._ZN9AIManagerD2Ev) }
    .ai_manager_vtable 0x004acf68 : { *ai-startup-aimanager.o(.data.rel.ro._ZTV9AIManager) }
    .ai_startup_function_0 0x003400b8 : { *ai-startup-aimanager.o(.text.__tcf_4) }
    .ai_startup_function_1 0x00340188 : { *ai-startup-aimanager.o(.text._Z41__static_initialization_and_destruction_0ii) }
    .ai_startup_function_2 0x003402cc : { *ai-startup-aimanager.o(.text._GLOBAL__I__ZN9AIManagerC2Ev) }
    .ai_startup_storage_0 0x004ba6d8 (NOLOAD) : { *ai-startup-aimanager.o(.bss._ZN3irr5scene6quake315irrEmptyStringcE) }
    .ai_startup_storage_1 0x004ba688 (NOLOAD) : { *ai-startup-aimanager.o(.bss._ZN8gameloft2ai11civ_passiveE) }
    .ai_startup_storage_2 0x004ba690 (NOLOAD) : { *ai-startup-aimanager.o(.bss._ZN8gameloft2ai12npc_scriptedE) }
    .ai_startup_storage_3 0x004ba698 (NOLOAD) : { *ai-startup-aimanager.o(.bss._ZN8gameloft2ai13civ_agressiveE) }
    .ai_startup_storage_4 0x004ba6a0 (NOLOAD) : { *ai-startup-aimanager.o(.bss._ZN8gameloft2ai11gang_memberE) }
    .ai_startup_storage_5 0x004ba6a8 (NOLOAD) : { *ai-startup-aimanager.o(.bss._ZN8gameloft2ai3copE) }
    .ai_startup_storage_6 0x004ba6b0 (NOLOAD) : { *ai-startup-aimanager.o(.bss._ZN8gameloft2ai4swatE) }
    .ai_startup_storage_7 0x004ba6b8 (NOLOAD) : { *ai-startup-aimanager.o(.bss._ZN8gameloft2ai11civ_vehicleE) }
    .ai_startup_storage_8 0x004ba6c0 (NOLOAD) : { *ai-startup-aimanager.o(.bss._ZN8gameloft2ai11cop_vehicleE) }
    .ai_startup_storage_9 0x004ba6c8 (NOLOAD) : { *ai-startup-aimanager.o(.bss._ZN8gameloft2ai5guardE) }
    .ai_startup_storage_10 0x004ba6d0 (NOLOAD) : { *ai-startup-aimanager.o(.bss._ZN8gameloft2ai16scripted_vehicleE) }
    .ai_startup_storage_11 0x004ba6f8 (NOLOAD) : { *ai-startup-aimanager.o(.bss._ZN3irr2ps5vHalfE) }
    .shared_startup_empty_text 0x0044d91c : { *(.gnu.linkonce.r.localStartupEmptyText) }
    .got 0x004b0048 : { *(.got.plt) . = 0x360; *(.got) }
    .verification 0x00600000 : { *retail-got.o(.text) }
}
ASSERT(SIZEOF(.ai_startup_storage_0) == 32, "_ZN3irr5scene6quake315irrEmptyStringcE extent");
ASSERT(SIZEOF(.ai_startup_storage_1) == 8, "_ZN8gameloft2ai11civ_passiveE extent");
ASSERT(SIZEOF(.ai_startup_storage_2) == 8, "_ZN8gameloft2ai12npc_scriptedE extent");
ASSERT(SIZEOF(.ai_startup_storage_3) == 8, "_ZN8gameloft2ai13civ_agressiveE extent");
ASSERT(SIZEOF(.ai_startup_storage_4) == 8, "_ZN8gameloft2ai11gang_memberE extent");
ASSERT(SIZEOF(.ai_startup_storage_5) == 8, "_ZN8gameloft2ai3copE extent");
ASSERT(SIZEOF(.ai_startup_storage_6) == 8, "_ZN8gameloft2ai4swatE extent");
ASSERT(SIZEOF(.ai_startup_storage_7) == 8, "_ZN8gameloft2ai11civ_vehicleE extent");
ASSERT(SIZEOF(.ai_startup_storage_8) == 8, "_ZN8gameloft2ai11cop_vehicleE extent");
ASSERT(SIZEOF(.ai_startup_storage_9) == 8, "_ZN8gameloft2ai5guardE extent");
ASSERT(SIZEOF(.ai_startup_storage_10) == 8, "_ZN8gameloft2ai16scripted_vehicleE extent");
ASSERT(SIZEOF(.ai_startup_storage_11) == 12, "_ZN3irr2ps5vHalfE extent");
