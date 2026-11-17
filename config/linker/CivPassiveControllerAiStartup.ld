OUTPUT_FORMAT("elf32-littlearm")
OUTPUT_ARCH(arm)
INCLUDE build/matches/ai-startup-civpassivecontroller/retail-symbols.ld
_ZdlPv = 0x001c42b0;
__aeabi_atexit = 0x001c494c;
_ZN39retail_civpassivecontroller_transitions16civPassive_transE = 0x00430678;
_ZN39retail_civpassivecontroller_transitions17scriptedNpc_transE = 0x004307a4;
_ZN39retail_civpassivecontroller_transitions19civAggressive_transE = 0x004307d4;
_ZN39retail_civpassivecontroller_transitions16gangMember_transE = 0x004308b8;
_ZN39retail_civpassivecontroller_transitions9cop_transE = 0x004308c4;
_ZN39retail_civpassivecontroller_transitions10swat_transE = 0x004309fc;
_ZN39retail_civpassivecontroller_transitions17civ_vehicle_transE = 0x00430a08;
_ZN39retail_civpassivecontroller_transitions17cop_vehicle_transE = 0x00430a98;
_ZN39retail_civpassivecontroller_transitions11guard_transE = 0x00430b4c;
_ZN39retail_civpassivecontroller_transitions22scripted_vehicle_transE = 0x00430bf4;
SECTIONS
{
    .civ_passive_constructor 0x00340c74 : { *ai-startup-civpassivecontroller.o(.text._ZN20CivPassiveControllerC1EP3NPCRKN8gameloft2ai10TransitionENS3_7StateIDE .text._ZN20CivPassiveControllerC2EP3NPCRKN8gameloft2ai10TransitionENS3_7StateIDE) }
    .civ_passive_dtor 0x00340c34 : { *ai-startup-civpassivecontroller.o(.text._ZN20CivPassiveControllerD1Ev .text._ZN20CivPassiveControllerD2Ev) }
    .civ_passive_delete 0x00340bf0 : { *ai-startup-civpassivecontroller.o(.text._ZN20CivPassiveControllerD0Ev) }
    .civ_passive_vtable 0x004acfb0 : { *ai-startup-civpassivecontroller.o(.data.rel.ro._ZTV20CivPassiveController) }
    .ai_startup_function_0 0x00340b3c : { *ai-startup-civpassivecontroller.o(.text.__tcf_3) }
    .ai_startup_function_1 0x00340d68 : { *ai-startup-civpassivecontroller.o(.text._Z41__static_initialization_and_destruction_0ii) }
    .ai_startup_function_2 0x00340eac : { *ai-startup-civpassivecontroller.o(.text._GLOBAL__I__ZN20CivPassiveControllerC2EP3NPCRKN8gameloft2ai10TransitionENS3_7StateIDE) }
    .ai_startup_storage_0 0x004ba7d0 (NOLOAD) : { *ai-startup-civpassivecontroller.o(.bss._ZN3irr5scene6quake315irrEmptyStringcE) }
    .ai_startup_storage_1 0x004ba780 (NOLOAD) : { *ai-startup-civpassivecontroller.o(.bss._ZN8gameloft2ai11civ_passiveE) }
    .ai_startup_storage_2 0x004ba788 (NOLOAD) : { *ai-startup-civpassivecontroller.o(.bss._ZN8gameloft2ai12npc_scriptedE) }
    .ai_startup_storage_3 0x004ba790 (NOLOAD) : { *ai-startup-civpassivecontroller.o(.bss._ZN8gameloft2ai13civ_agressiveE) }
    .ai_startup_storage_4 0x004ba798 (NOLOAD) : { *ai-startup-civpassivecontroller.o(.bss._ZN8gameloft2ai11gang_memberE) }
    .ai_startup_storage_5 0x004ba7a0 (NOLOAD) : { *ai-startup-civpassivecontroller.o(.bss._ZN8gameloft2ai3copE) }
    .ai_startup_storage_6 0x004ba7a8 (NOLOAD) : { *ai-startup-civpassivecontroller.o(.bss._ZN8gameloft2ai4swatE) }
    .ai_startup_storage_7 0x004ba7b0 (NOLOAD) : { *ai-startup-civpassivecontroller.o(.bss._ZN8gameloft2ai11civ_vehicleE) }
    .ai_startup_storage_8 0x004ba7b8 (NOLOAD) : { *ai-startup-civpassivecontroller.o(.bss._ZN8gameloft2ai11cop_vehicleE) }
    .ai_startup_storage_9 0x004ba7c0 (NOLOAD) : { *ai-startup-civpassivecontroller.o(.bss._ZN8gameloft2ai5guardE) }
    .ai_startup_storage_10 0x004ba7c8 (NOLOAD) : { *ai-startup-civpassivecontroller.o(.bss._ZN8gameloft2ai16scripted_vehicleE) }
    .ai_startup_storage_11 0x004ba7f0 (NOLOAD) : { *ai-startup-civpassivecontroller.o(.bss._ZN3irr2ps5vHalfE) }
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
