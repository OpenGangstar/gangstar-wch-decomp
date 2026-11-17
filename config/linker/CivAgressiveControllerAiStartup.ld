OUTPUT_FORMAT("elf32-littlearm")
OUTPUT_ARCH(arm)
INCLUDE build/matches/ai-startup-civagressivecontroller/retail-symbols.ld
_ZdlPv = 0x001c42b0;
__aeabi_atexit = 0x001c494c;
_ZN41retail_civagressivecontroller_transitions16civPassive_transE = 0x004300a8;
_ZN41retail_civagressivecontroller_transitions17scriptedNpc_transE = 0x004301d4;
_ZN41retail_civagressivecontroller_transitions19civAggressive_transE = 0x00430204;
_ZN41retail_civagressivecontroller_transitions16gangMember_transE = 0x004302e8;
_ZN41retail_civagressivecontroller_transitions9cop_transE = 0x004302f4;
_ZN41retail_civagressivecontroller_transitions10swat_transE = 0x0043042c;
_ZN41retail_civagressivecontroller_transitions17civ_vehicle_transE = 0x00430438;
_ZN41retail_civagressivecontroller_transitions17cop_vehicle_transE = 0x004304c8;
_ZN41retail_civagressivecontroller_transitions11guard_transE = 0x0043057c;
_ZN41retail_civagressivecontroller_transitions22scripted_vehicle_transE = 0x00430624;
SECTIONS
{
    .civ_aggressive_event 0x0034084c : { *ai-startup-civagressivecontroller.o(.text._ZN22CivAgressiveController7onEventEPK6IEventPK12EventManager) }
    .civagressivecontroller_switch_state 0x003408a8 : { *ai-startup-civagressivecontroller.o(.text._ZN22CivAgressiveController11switchStateEN8gameloft2ai7StateIDENS1_19TransitionConditionE) }
    .civagressivecontroller_constructor 0x00340984 : { *ai-startup-civagressivecontroller.o(.text._ZN22CivAgressiveControllerC1EP3NPCN8gameloft2ai7StateIDE .text._ZN22CivAgressiveControllerC2EP3NPCN8gameloft2ai7StateIDE) }
    .civ_aggressive_dtor 0x00340944 : { *ai-startup-civagressivecontroller.o(.text._ZN22CivAgressiveControllerD1Ev .text._ZN22CivAgressiveControllerD2Ev) }
    .civ_aggressive_delete 0x00340900 : { *ai-startup-civagressivecontroller.o(.text._ZN22CivAgressiveControllerD0Ev) }
    .civ_aggressive_vtable 0x004acf98 : { *ai-startup-civagressivecontroller.o(.data.rel.ro._ZTV22CivAgressiveController) }
    .ai_startup_function_0 0x0034081c : { *ai-startup-civagressivecontroller.o(.text.__tcf_3) }
    .ai_startup_function_1 0x003409e4 : { *ai-startup-civagressivecontroller.o(.text._Z41__static_initialization_and_destruction_0ii) }
    .ai_startup_function_2 0x00340b28 : { *ai-startup-civagressivecontroller.o(.text._GLOBAL__I__ZN22CivAgressiveControllerC2EP3NPCN8gameloft2ai7StateIDE) }
    .ai_startup_storage_0 0x004ba754 (NOLOAD) : { *ai-startup-civagressivecontroller.o(.bss._ZN3irr5scene6quake315irrEmptyStringcE) }
    .ai_startup_storage_1 0x004ba714 (NOLOAD) : { *ai-startup-civagressivecontroller.o(.bss._ZN8gameloft2ai13civ_agressiveE) }
    .ai_startup_storage_2 0x004ba704 (NOLOAD) : { *ai-startup-civagressivecontroller.o(.bss._ZN8gameloft2ai11civ_passiveE) }
    .ai_startup_storage_3 0x004ba70c (NOLOAD) : { *ai-startup-civagressivecontroller.o(.bss._ZN8gameloft2ai12npc_scriptedE) }
    .ai_startup_storage_4 0x004ba71c (NOLOAD) : { *ai-startup-civagressivecontroller.o(.bss._ZN8gameloft2ai11gang_memberE) }
    .ai_startup_storage_5 0x004ba724 (NOLOAD) : { *ai-startup-civagressivecontroller.o(.bss._ZN8gameloft2ai3copE) }
    .ai_startup_storage_6 0x004ba72c (NOLOAD) : { *ai-startup-civagressivecontroller.o(.bss._ZN8gameloft2ai4swatE) }
    .ai_startup_storage_7 0x004ba734 (NOLOAD) : { *ai-startup-civagressivecontroller.o(.bss._ZN8gameloft2ai11civ_vehicleE) }
    .ai_startup_storage_8 0x004ba73c (NOLOAD) : { *ai-startup-civagressivecontroller.o(.bss._ZN8gameloft2ai11cop_vehicleE) }
    .ai_startup_storage_9 0x004ba744 (NOLOAD) : { *ai-startup-civagressivecontroller.o(.bss._ZN8gameloft2ai5guardE) }
    .ai_startup_storage_10 0x004ba74c (NOLOAD) : { *ai-startup-civagressivecontroller.o(.bss._ZN8gameloft2ai16scripted_vehicleE) }
    .ai_startup_storage_11 0x004ba774 (NOLOAD) : { *ai-startup-civagressivecontroller.o(.bss._ZN3irr2ps5vHalfE) }
    .shared_startup_empty_text 0x0044d91c : { *(.gnu.linkonce.r.localStartupEmptyText) }
    .got 0x004b0048 : { *(.got.plt) . = 0x360; *(.got) }
    .verification 0x00600000 : { *retail-got.o(.text) }
}
ASSERT(SIZEOF(.ai_startup_storage_0) == 32, "_ZN3irr5scene6quake315irrEmptyStringcE extent");
ASSERT(SIZEOF(.ai_startup_storage_1) == 8, "_ZN8gameloft2ai13civ_agressiveE extent");
ASSERT(SIZEOF(.ai_startup_storage_2) == 8, "_ZN8gameloft2ai11civ_passiveE extent");
ASSERT(SIZEOF(.ai_startup_storage_3) == 8, "_ZN8gameloft2ai12npc_scriptedE extent");
ASSERT(SIZEOF(.ai_startup_storage_4) == 8, "_ZN8gameloft2ai11gang_memberE extent");
ASSERT(SIZEOF(.ai_startup_storage_5) == 8, "_ZN8gameloft2ai3copE extent");
ASSERT(SIZEOF(.ai_startup_storage_6) == 8, "_ZN8gameloft2ai4swatE extent");
ASSERT(SIZEOF(.ai_startup_storage_7) == 8, "_ZN8gameloft2ai11civ_vehicleE extent");
ASSERT(SIZEOF(.ai_startup_storage_8) == 8, "_ZN8gameloft2ai11cop_vehicleE extent");
ASSERT(SIZEOF(.ai_startup_storage_9) == 8, "_ZN8gameloft2ai5guardE extent");
ASSERT(SIZEOF(.ai_startup_storage_10) == 8, "_ZN8gameloft2ai16scripted_vehicleE extent");
ASSERT(SIZEOF(.ai_startup_storage_11) == 12, "_ZN3irr2ps5vHalfE extent");

INCLUDE config/linker/PlayerEventSections.ld
