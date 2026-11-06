OUTPUT_FORMAT("elf32-littlearm")
OUTPUT_ARCH(arm)
INCLUDE build/matches/ai-startup-revive/retail-symbols.ld
_ZdlPv = 0x001c42b0;
__aeabi_atexit = 0x001c494c;
_ZN25retail_revive_transitions16civPassive_transE = 0x0042e268;
_ZN25retail_revive_transitions17scriptedNpc_transE = 0x0042e394;
_ZN25retail_revive_transitions19civAggressive_transE = 0x0042e3c4;
_ZN25retail_revive_transitions16gangMember_transE = 0x0042e4a8;
_ZN25retail_revive_transitions9cop_transE = 0x0042e4b4;
_ZN25retail_revive_transitions10swat_transE = 0x0042e5ec;
_ZN25retail_revive_transitions17civ_vehicle_transE = 0x0042e5f8;
_ZN25retail_revive_transitions17cop_vehicle_transE = 0x0042e688;
_ZN25retail_revive_transitions11guard_transE = 0x0042e73c;
_ZN25retail_revive_transitions22scripted_vehicle_transE = 0x0042e7e4;
_Znwj = 0x001c4814;
__cxa_guard_acquire = 0x001c4958;
__cxa_guard_release = 0x001c46c4;
SECTIONS
{
    .state_machine_singleton 0x002d44c4 : { *ai-startup-revive.o(.gnu.linkonce.t._ZN12StateMachine11getInstanceEv) }
    .state_machine_cleanup 0x00338bac : { *ai-startup-revive.o(.text.__tcf_1) }
    .state_machine_guard 0x004b6904 (NOLOAD) : { *ai-startup-revive.o(.gnu.linkonce.b._ZGVZN12StateMachine11getInstanceEvE2sm) }
    .state_machine_instance 0x004b6908 (NOLOAD) : { *ai-startup-revive.o(.gnu.linkonce.b._ZZN12StateMachine11getInstanceEvE2sm) }
    .wanted_singleton 0x002dba04 : { *ai-startup-revive.o(.gnu.linkonce.t._ZN18WantedLevelManager11getInstanceEv) }
    .wanted_cleanup 0x00338c24 : { *ai-startup-revive.o(.text.__tcf_0) }
    .wanted_guard 0x004b6728 (NOLOAD) : { *ai-startup-revive.o(.gnu.linkonce.b._ZGVZN18WantedLevelManager11getInstanceEvE3wlm) }
    .wanted_instance 0x004b6a98 (NOLOAD) : { *ai-startup-revive.o(.gnu.linkonce.b._ZZN18WantedLevelManager11getInstanceEvE3wlm) }
    .revive_construct 0x00338e78 : { *ai-startup-revive.o(.text._ZN6ReviveC1Eb .text._ZN6ReviveC2Eb) }
    .revive_finish 0x00338b54 : { *ai-startup-revive.o(.text._ZN6Revive19finishCashLostAnimsEv) }
    .revive_draw 0x00338b8c : { *ai-startup-revive.o(.text._ZN6Revive6draw2dEv) }
    .revive_destroy 0x00338be8 : { *ai-startup-revive.o(.text._ZN6ReviveD1Ev .text._ZN6ReviveD2Ev) }
    .ai_startup_function_0 0x00338b5c : { *ai-startup-revive.o(.text.__tcf_5) }
    .ai_startup_function_1 0x00338f4c : { *ai-startup-revive.o(.text._Z41__static_initialization_and_destruction_0ii) }
    .ai_startup_function_2 0x00339090 : { *ai-startup-revive.o(.text._GLOBAL__I__ZN6ReviveC2Eb) }
    .ai_startup_storage_0 0x004ba460 (NOLOAD) : { *ai-startup-revive.o(.bss._ZN3irr5scene6quake315irrEmptyStringcE) }
    .ai_startup_storage_1 0x004ba480 (NOLOAD) : { *ai-startup-revive.o(.bss._ZN3irr2ps5vHalfE) }
    .ai_startup_storage_2 0x004ba48c (NOLOAD) : { *ai-startup-revive.o(.bss._ZN8gameloft2ai11civ_passiveE) }
    .ai_startup_storage_3 0x004ba494 (NOLOAD) : { *ai-startup-revive.o(.bss._ZN8gameloft2ai12npc_scriptedE) }
    .ai_startup_storage_4 0x004ba49c (NOLOAD) : { *ai-startup-revive.o(.bss._ZN8gameloft2ai13civ_agressiveE) }
    .ai_startup_storage_5 0x004ba4a4 (NOLOAD) : { *ai-startup-revive.o(.bss._ZN8gameloft2ai11gang_memberE) }
    .ai_startup_storage_6 0x004ba4ac (NOLOAD) : { *ai-startup-revive.o(.bss._ZN8gameloft2ai3copE) }
    .ai_startup_storage_7 0x004ba4b4 (NOLOAD) : { *ai-startup-revive.o(.bss._ZN8gameloft2ai4swatE) }
    .ai_startup_storage_8 0x004ba4bc (NOLOAD) : { *ai-startup-revive.o(.bss._ZN8gameloft2ai11civ_vehicleE) }
    .ai_startup_storage_9 0x004ba4c4 (NOLOAD) : { *ai-startup-revive.o(.bss._ZN8gameloft2ai11cop_vehicleE) }
    .ai_startup_storage_10 0x004ba4cc (NOLOAD) : { *ai-startup-revive.o(.bss._ZN8gameloft2ai5guardE) }
    .ai_startup_storage_11 0x004ba4d4 (NOLOAD) : { *ai-startup-revive.o(.bss._ZN8gameloft2ai16scripted_vehicleE) }
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
