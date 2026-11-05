OUTPUT_FORMAT("elf32-littlearm")
OUTPUT_ARCH(arm)
INCLUDE build/matches/ai-startup-carbar/retail-symbols.ld
_ZdlPv = 0x001c42b0;
__aeabi_atexit = 0x001c494c;
_ZN25retail_carbar_transitions16civPassive_transE = 0x00423020;
_ZN25retail_carbar_transitions17scriptedNpc_transE = 0x0042314c;
_ZN25retail_carbar_transitions19civAggressive_transE = 0x0042317c;
_ZN25retail_carbar_transitions16gangMember_transE = 0x00423260;
_ZN25retail_carbar_transitions9cop_transE = 0x0042326c;
_ZN25retail_carbar_transitions10swat_transE = 0x004233a4;
_ZN25retail_carbar_transitions17civ_vehicle_transE = 0x004233b0;
_ZN25retail_carbar_transitions17cop_vehicle_transE = 0x00423440;
_ZN25retail_carbar_transitions11guard_transE = 0x004234f4;
_ZN25retail_carbar_transitions22scripted_vehicle_transE = 0x0042359c;
SECTIONS
{
    .ai_startup_function_0 0x00327704 : { *ai-startup-carbar.o(.text.__tcf_3) }
    .ai_startup_function_1 0x00327848 : { *ai-startup-carbar.o(.text._Z41__static_initialization_and_destruction_0ii) }
    .ai_startup_function_2 0x0032798c : { *ai-startup-carbar.o(.text._GLOBAL__I__ZN6CarBarC2EP7ASpriteiii) }
    .ai_startup_storage_0 0x004b934c (NOLOAD) : { *ai-startup-carbar.o(.bss._ZN3irr5scene6quake315irrEmptyStringcE) }
    .ai_startup_storage_1 0x004b936c (NOLOAD) : { *ai-startup-carbar.o(.bss._ZN3irr2ps5vHalfE) }
    .ai_startup_storage_2 0x004b9378 (NOLOAD) : { *ai-startup-carbar.o(.bss._ZN8gameloft2ai11civ_passiveE) }
    .ai_startup_storage_3 0x004b9380 (NOLOAD) : { *ai-startup-carbar.o(.bss._ZN8gameloft2ai12npc_scriptedE) }
    .ai_startup_storage_4 0x004b9388 (NOLOAD) : { *ai-startup-carbar.o(.bss._ZN8gameloft2ai13civ_agressiveE) }
    .ai_startup_storage_5 0x004b9390 (NOLOAD) : { *ai-startup-carbar.o(.bss._ZN8gameloft2ai11gang_memberE) }
    .ai_startup_storage_6 0x004b9398 (NOLOAD) : { *ai-startup-carbar.o(.bss._ZN8gameloft2ai3copE) }
    .ai_startup_storage_7 0x004b93a0 (NOLOAD) : { *ai-startup-carbar.o(.bss._ZN8gameloft2ai4swatE) }
    .ai_startup_storage_8 0x004b93a8 (NOLOAD) : { *ai-startup-carbar.o(.bss._ZN8gameloft2ai11civ_vehicleE) }
    .ai_startup_storage_9 0x004b93b0 (NOLOAD) : { *ai-startup-carbar.o(.bss._ZN8gameloft2ai11cop_vehicleE) }
    .ai_startup_storage_10 0x004b93b8 (NOLOAD) : { *ai-startup-carbar.o(.bss._ZN8gameloft2ai5guardE) }
    .ai_startup_storage_11 0x004b93c0 (NOLOAD) : { *ai-startup-carbar.o(.bss._ZN8gameloft2ai16scripted_vehicleE) }
    .bar_entry_0 0x00327790 : { *ai-startup-carbar.o(.text._ZThn4_N6CarBarD0Ev) }
    .bar_entry_1 0x003277a4 : { *ai-startup-carbar.o(.text._ZN6CarBarD0Ev) }
    .bar_entry_2 0x003277d4 : { *ai-startup-carbar.o(.text._ZThn4_N6CarBarD1Ev) }
    .bar_entry_3 0x003277e8 : { *ai-startup-carbar.o(.text._ZN6CarBarD1Ev) }
    .bar_entry_4 0x00327814 : { *ai-startup-carbar.o(.text._ZN6CarBarC1EP7ASpriteiii) }
    .bar_vtable 0x004ac118 : { *ai-startup-carbar.o(.data.rel.ro._ZTV6CarBar) }
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
