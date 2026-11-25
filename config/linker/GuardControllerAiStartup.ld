OUTPUT_FORMAT("elf32-littlearm")
OUTPUT_ARCH(arm)
INCLUDE build/matches/ai-startup-guardcontroller/retail-symbols.ld
INCLUDE config/linker/PlayerEventSections.ld
_ZdlPv = 0x001c42b0;
__aeabi_atexit = 0x001c494c;
_ZN34retail_guardcontroller_transitions16civPassive_transE = 0x00431840;
_ZN34retail_guardcontroller_transitions17scriptedNpc_transE = 0x0043196c;
_ZN34retail_guardcontroller_transitions19civAggressive_transE = 0x0043199c;
_ZN34retail_guardcontroller_transitions16gangMember_transE = 0x00431a80;
_ZN34retail_guardcontroller_transitions9cop_transE = 0x00431a8c;
_ZN34retail_guardcontroller_transitions10swat_transE = 0x00431bc4;
_ZN34retail_guardcontroller_transitions17civ_vehicle_transE = 0x00431bd0;
_ZN34retail_guardcontroller_transitions17cop_vehicle_transE = 0x00431c60;
_ZN34retail_guardcontroller_transitions11guard_transE = 0x00431d14;
_ZN34retail_guardcontroller_transitions22scripted_vehicle_transE = 0x00431dbc;
SECTIONS
{
    .guard_controller_on_event 0x00341f30 : { *ai-startup-guardcontroller.o(.text._ZN15GuardController7onEventEPK6IEventPK12EventManager) }
    ASSERT(SIZEOF(.guard_controller_on_event) == 412, "Native GuardController onEvent extent")
    .guard_switch_state 0x003420cc : { *ai-startup-guardcontroller.o(.text._ZN15GuardController11switchStateEN8gameloft2ai7StateIDENS1_19TransitionConditionE) }
    .guard_switch_table 0x00431814 : { *ai-startup-guardcontroller.o(.rodata._ZN15GuardController11switchStateEN8gameloft2ai7StateIDENS1_19TransitionConditionE) }
    .guardcontroller_constructor 0x00342220 : { *ai-startup-guardcontroller.o(.text._ZN15GuardControllerC1EP3NPCN8gameloft2ai7StateIDE .text._ZN15GuardControllerC2EP3NPCN8gameloft2ai7StateIDE) }
    .guard_dtor 0x00341d24 : { *ai-startup-guardcontroller.o(.text._ZN15GuardControllerD1Ev .text._ZN15GuardControllerD2Ev) }
    .guard_delete 0x00341d64 : { *ai-startup-guardcontroller.o(.text._ZN15GuardControllerD0Ev) }
    .guard_vtable 0x004ad000 : { *ai-startup-guardcontroller.o(.data.rel.ro._ZTV15GuardController) }
    .ai_startup_function_0 0x00341f00 : { *ai-startup-guardcontroller.o(.text.__tcf_3) }
    .ai_startup_function_1 0x00341da8 : { *ai-startup-guardcontroller.o(.text._Z41__static_initialization_and_destruction_0ii) }
    .ai_startup_function_2 0x00341eec : { *ai-startup-guardcontroller.o(.text._GLOBAL__I__ZN15GuardControllerC2EP3NPCN8gameloft2ai7StateIDE) }
    .ai_startup_storage_0 0x004ba8f8 (NOLOAD) : { *ai-startup-guardcontroller.o(.bss._ZN8gameloft2ai11civ_passiveE) }
    .ai_startup_storage_1 0x004ba900 (NOLOAD) : { *ai-startup-guardcontroller.o(.bss._ZN8gameloft2ai12npc_scriptedE) }
    .ai_startup_storage_2 0x004ba948 (NOLOAD) : { *ai-startup-guardcontroller.o(.bss._ZN3irr5scene6quake315irrEmptyStringcE) }
    .ai_startup_storage_3 0x004ba908 (NOLOAD) : { *ai-startup-guardcontroller.o(.bss._ZN8gameloft2ai13civ_agressiveE) }
    .ai_startup_storage_4 0x004ba910 (NOLOAD) : { *ai-startup-guardcontroller.o(.bss._ZN8gameloft2ai11gang_memberE) }
    .ai_startup_storage_5 0x004ba918 (NOLOAD) : { *ai-startup-guardcontroller.o(.bss._ZN8gameloft2ai3copE) }
    .ai_startup_storage_6 0x004ba920 (NOLOAD) : { *ai-startup-guardcontroller.o(.bss._ZN8gameloft2ai4swatE) }
    .ai_startup_storage_7 0x004ba928 (NOLOAD) : { *ai-startup-guardcontroller.o(.bss._ZN8gameloft2ai11civ_vehicleE) }
    .ai_startup_storage_8 0x004ba930 (NOLOAD) : { *ai-startup-guardcontroller.o(.bss._ZN8gameloft2ai11cop_vehicleE) }
    .ai_startup_storage_9 0x004ba938 (NOLOAD) : { *ai-startup-guardcontroller.o(.bss._ZN8gameloft2ai5guardE) }
    .ai_startup_storage_10 0x004ba940 (NOLOAD) : { *ai-startup-guardcontroller.o(.bss._ZN8gameloft2ai16scripted_vehicleE) }
    .ai_startup_storage_11 0x004ba968 (NOLOAD) : { *ai-startup-guardcontroller.o(.bss._ZN3irr2ps5vHalfE) }
    .shared_startup_empty_text 0x0044d91c : { *(.gnu.linkonce.r.localStartupEmptyText) }
    .got 0x004b0048 : { *(.got.plt) . = 0x360; *(.got) }
    .verification 0x00600000 : { *retail-got.o(.text) }
}
ASSERT(SIZEOF(.ai_startup_storage_0) == 8, "_ZN8gameloft2ai11civ_passiveE extent");
ASSERT(SIZEOF(.ai_startup_storage_1) == 8, "_ZN8gameloft2ai12npc_scriptedE extent");
ASSERT(SIZEOF(.ai_startup_storage_2) == 32, "_ZN3irr5scene6quake315irrEmptyStringcE extent");
ASSERT(SIZEOF(.ai_startup_storage_3) == 8, "_ZN8gameloft2ai13civ_agressiveE extent");
ASSERT(SIZEOF(.ai_startup_storage_4) == 8, "_ZN8gameloft2ai11gang_memberE extent");
ASSERT(SIZEOF(.ai_startup_storage_5) == 8, "_ZN8gameloft2ai3copE extent");
ASSERT(SIZEOF(.ai_startup_storage_6) == 8, "_ZN8gameloft2ai4swatE extent");
ASSERT(SIZEOF(.ai_startup_storage_7) == 8, "_ZN8gameloft2ai11civ_vehicleE extent");
ASSERT(SIZEOF(.ai_startup_storage_8) == 8, "_ZN8gameloft2ai11cop_vehicleE extent");
ASSERT(SIZEOF(.ai_startup_storage_9) == 8, "_ZN8gameloft2ai5guardE extent");
ASSERT(SIZEOF(.ai_startup_storage_10) == 8, "_ZN8gameloft2ai16scripted_vehicleE extent");
ASSERT(SIZEOF(.ai_startup_storage_11) == 12, "_ZN3irr2ps5vHalfE extent");
