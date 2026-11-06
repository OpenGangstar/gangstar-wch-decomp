OUTPUT_FORMAT("elf32-littlearm")
OUTPUT_ARCH(arm)
INCLUDE build/matches/ai-startup-confootcontrolhandler/retail-symbols.ld
_ZdlPv = 0x001c42b0;
__aeabi_atexit = 0x001c494c;
_ZN40retail_confootcontrolhandler_transitions16civPassive_transE = 0x004264a4;
_ZN40retail_confootcontrolhandler_transitions17scriptedNpc_transE = 0x004265d0;
_ZN40retail_confootcontrolhandler_transitions19civAggressive_transE = 0x00426600;
_ZN40retail_confootcontrolhandler_transitions16gangMember_transE = 0x004266e4;
_ZN40retail_confootcontrolhandler_transitions9cop_transE = 0x004266f0;
_ZN40retail_confootcontrolhandler_transitions10swat_transE = 0x00426828;
_ZN40retail_confootcontrolhandler_transitions17civ_vehicle_transE = 0x00426834;
_ZN40retail_confootcontrolhandler_transitions17cop_vehicle_transE = 0x004268c4;
_ZN40retail_confootcontrolhandler_transitions11guard_transE = 0x00426978;
_ZN40retail_confootcontrolhandler_transitions22scripted_vehicle_transE = 0x00426a20;
__cxa_guard_acquire = 0x001c4958;
__cxa_guard_release = 0x001c46c4;
SECTIONS
{
    .state_machine_singleton 0x002d44c4 : { *ai-startup-confootcontrolhandler.o(.gnu.linkonce.t._ZN12StateMachine11getInstanceEv) }
    .state_machine_cleanup 0x0032e648 : { *ai-startup-confootcontrolhandler.o(.text.__tcf_0) }
    .state_machine_guard 0x004b6904 (NOLOAD) : { *ai-startup-confootcontrolhandler.o(.gnu.linkonce.b._ZGVZN12StateMachine11getInstanceEvE2sm) }
    .state_machine_instance 0x004b6908 (NOLOAD) : { *ai-startup-confootcontrolhandler.o(.gnu.linkonce.b._ZZN12StateMachine11getInstanceEvE2sm) }
    .ai_startup_function_0 0x0032e52c : { *ai-startup-confootcontrolhandler.o(.text.__tcf_4) }
    .ai_startup_function_1 0x0032ef14 : { *ai-startup-confootcontrolhandler.o(.text._Z41__static_initialization_and_destruction_0ii) }
    .ai_startup_function_2 0x0032f058 : { *ai-startup-confootcontrolhandler.o(.text._GLOBAL__I__ZN21COnFootControlHandlerC2EP15CControlManager) }
    .ai_startup_storage_0 0x004b9998 (NOLOAD) : { *ai-startup-confootcontrolhandler.o(.bss._ZN3irr5scene6quake315irrEmptyStringcE) }
    .ai_startup_storage_1 0x004b99b8 (NOLOAD) : { *ai-startup-confootcontrolhandler.o(.bss._ZN3irr2ps5vHalfE) }
    .ai_startup_storage_2 0x004b99c4 (NOLOAD) : { *ai-startup-confootcontrolhandler.o(.bss._ZN8gameloft2ai11civ_passiveE) }
    .ai_startup_storage_3 0x004b99cc (NOLOAD) : { *ai-startup-confootcontrolhandler.o(.bss._ZN8gameloft2ai12npc_scriptedE) }
    .ai_startup_storage_4 0x004b99d4 (NOLOAD) : { *ai-startup-confootcontrolhandler.o(.bss._ZN8gameloft2ai13civ_agressiveE) }
    .ai_startup_storage_5 0x004b99dc (NOLOAD) : { *ai-startup-confootcontrolhandler.o(.bss._ZN8gameloft2ai11gang_memberE) }
    .ai_startup_storage_6 0x004b99e4 (NOLOAD) : { *ai-startup-confootcontrolhandler.o(.bss._ZN8gameloft2ai3copE) }
    .ai_startup_storage_7 0x004b99ec (NOLOAD) : { *ai-startup-confootcontrolhandler.o(.bss._ZN8gameloft2ai4swatE) }
    .ai_startup_storage_8 0x004b99f4 (NOLOAD) : { *ai-startup-confootcontrolhandler.o(.bss._ZN8gameloft2ai11civ_vehicleE) }
    .ai_startup_storage_9 0x004b99fc (NOLOAD) : { *ai-startup-confootcontrolhandler.o(.bss._ZN8gameloft2ai11cop_vehicleE) }
    .ai_startup_storage_10 0x004b9a04 (NOLOAD) : { *ai-startup-confootcontrolhandler.o(.bss._ZN8gameloft2ai5guardE) }
    .ai_startup_storage_11 0x004b9a0c (NOLOAD) : { *ai-startup-confootcontrolhandler.o(.bss._ZN8gameloft2ai16scripted_vehicleE) }
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
