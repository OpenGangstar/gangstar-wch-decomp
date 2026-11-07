OUTPUT_FORMAT("elf32-littlearm")
OUTPUT_ARCH(arm)
INCLUDE build/matches/ai-startup-npccontroller/retail-symbols.ld
_ZdlPv = 0x001c42b0;
__aeabi_atexit = 0x001c494c;
_ZN32retail_npccontroller_transitions16civPassive_transE = 0x00431e10;
_ZN32retail_npccontroller_transitions17scriptedNpc_transE = 0x00431f3c;
_ZN32retail_npccontroller_transitions19civAggressive_transE = 0x00431f6c;
_ZN32retail_npccontroller_transitions16gangMember_transE = 0x00432050;
_ZN32retail_npccontroller_transitions9cop_transE = 0x0043205c;
_ZN32retail_npccontroller_transitions10swat_transE = 0x00432194;
_ZN32retail_npccontroller_transitions17civ_vehicle_transE = 0x004321a0;
_ZN32retail_npccontroller_transitions17cop_vehicle_transE = 0x00432230;
_ZN32retail_npccontroller_transitions11guard_transE = 0x004322e4;
_ZN32retail_npccontroller_transitions22scripted_vehicle_transE = 0x0043238c;
__cxa_pure_virtual = 0;
SECTIONS
{
    .receiver_delete 0x002db4b4 : { *(.gnu.linkonce.t._ZN14IEventReceiverD0Ev) }
    .receiver_vtable 0x004a8b48 : { *(.gnu.linkonce.d.rel.ro._ZTV14IEventReceiver) }
    .npc_controller_switch 0x00342288 : { *(.text._ZN13NPCController11switchStateEN8gameloft2ai7StateIDENS1_19TransitionConditionE) }
    .npc_controller_construct 0x0034231c : { *(.text._ZN13NPCControllerC1EN8gameloft2ai7StateIDEP3NPCRKNS1_10TransitionE .text._ZN13NPCControllerC2EN8gameloft2ai7StateIDEP3NPCRKNS1_10TransitionE) }
    .npc_controller_delete 0x00342494 : { *(.text._ZN13NPCControllerD0Ev) }
    .npc_controller_destroy 0x003424c0 : { *(.text._ZN13NPCControllerD1Ev .text._ZN13NPCControllerD2Ev) }
    .npc_controller_vtable 0x004ad018 : { *(.data.rel.ro._ZTV13NPCController) }
    .ai_startup_function_0 0x003422ec : { *ai-startup-npccontroller.o(.text.__tcf_2) }
    .ai_startup_function_1 0x0034233c : { *ai-startup-npccontroller.o(.text._Z41__static_initialization_and_destruction_0ii) }
    .ai_startup_function_2 0x00342480 : { *ai-startup-npccontroller.o(.text._GLOBAL__I__ZN13NPCControllerC2EN8gameloft2ai7StateIDEP3NPCRKNS1_10TransitionE) }
    .ai_startup_storage_0 0x004ba9c4 (NOLOAD) : { *ai-startup-npccontroller.o(.bss._ZN3irr5scene6quake315irrEmptyStringcE) }
    .ai_startup_storage_1 0x004ba974 (NOLOAD) : { *ai-startup-npccontroller.o(.bss._ZN8gameloft2ai11civ_passiveE) }
    .ai_startup_storage_2 0x004ba97c (NOLOAD) : { *ai-startup-npccontroller.o(.bss._ZN8gameloft2ai12npc_scriptedE) }
    .ai_startup_storage_3 0x004ba984 (NOLOAD) : { *ai-startup-npccontroller.o(.bss._ZN8gameloft2ai13civ_agressiveE) }
    .ai_startup_storage_4 0x004ba98c (NOLOAD) : { *ai-startup-npccontroller.o(.bss._ZN8gameloft2ai11gang_memberE) }
    .ai_startup_storage_5 0x004ba994 (NOLOAD) : { *ai-startup-npccontroller.o(.bss._ZN8gameloft2ai3copE) }
    .ai_startup_storage_6 0x004ba99c (NOLOAD) : { *ai-startup-npccontroller.o(.bss._ZN8gameloft2ai4swatE) }
    .ai_startup_storage_7 0x004ba9a4 (NOLOAD) : { *ai-startup-npccontroller.o(.bss._ZN8gameloft2ai11civ_vehicleE) }
    .ai_startup_storage_8 0x004ba9ac (NOLOAD) : { *ai-startup-npccontroller.o(.bss._ZN8gameloft2ai11cop_vehicleE) }
    .ai_startup_storage_9 0x004ba9b4 (NOLOAD) : { *ai-startup-npccontroller.o(.bss._ZN8gameloft2ai5guardE) }
    .ai_startup_storage_10 0x004ba9bc (NOLOAD) : { *ai-startup-npccontroller.o(.bss._ZN8gameloft2ai16scripted_vehicleE) }
    .ai_startup_storage_11 0x004ba9e4 (NOLOAD) : { *ai-startup-npccontroller.o(.bss._ZN3irr2ps5vHalfE) }
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
