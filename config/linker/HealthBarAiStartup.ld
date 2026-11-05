OUTPUT_FORMAT("elf32-littlearm")
OUTPUT_ARCH(arm)
INCLUDE build/matches/ai-startup-healthbar/retail-symbols.ld
_ZdlPv = 0x001c42b0;
__aeabi_atexit = 0x001c494c;
_ZN28retail_healthbar_transitions16civPassive_transE = 0x00423bc0;
_ZN28retail_healthbar_transitions17scriptedNpc_transE = 0x00423cec;
_ZN28retail_healthbar_transitions19civAggressive_transE = 0x00423d1c;
_ZN28retail_healthbar_transitions16gangMember_transE = 0x00423e00;
_ZN28retail_healthbar_transitions9cop_transE = 0x00423e0c;
_ZN28retail_healthbar_transitions10swat_transE = 0x00423f44;
_ZN28retail_healthbar_transitions17civ_vehicle_transE = 0x00423f50;
_ZN28retail_healthbar_transitions17cop_vehicle_transE = 0x00423fe0;
_ZN28retail_healthbar_transitions11guard_transE = 0x00424094;
_ZN28retail_healthbar_transitions22scripted_vehicle_transE = 0x0042413c;
SECTIONS
{
    .ai_startup_function_0 0x003281c8 : { *ai-startup-healthbar.o(.text.__tcf_3) }
    .ai_startup_function_1 0x00328390 : { *ai-startup-healthbar.o(.text._Z41__static_initialization_and_destruction_0ii) }
    .ai_startup_function_2 0x003284d4 : { *ai-startup-healthbar.o(.text._GLOBAL__I__ZN9HealthBarC2EP7ASpriteiii) }
    .ai_startup_storage_0 0x004b9470 (NOLOAD) : { *ai-startup-healthbar.o(.bss._ZN3irr5scene6quake315irrEmptyStringcE) }
    .ai_startup_storage_1 0x004b9490 (NOLOAD) : { *ai-startup-healthbar.o(.bss._ZN3irr2ps5vHalfE) }
    .ai_startup_storage_2 0x004b949c (NOLOAD) : { *ai-startup-healthbar.o(.bss._ZN8gameloft2ai11civ_passiveE) }
    .ai_startup_storage_3 0x004b94a4 (NOLOAD) : { *ai-startup-healthbar.o(.bss._ZN8gameloft2ai12npc_scriptedE) }
    .ai_startup_storage_4 0x004b94ac (NOLOAD) : { *ai-startup-healthbar.o(.bss._ZN8gameloft2ai13civ_agressiveE) }
    .ai_startup_storage_5 0x004b94b4 (NOLOAD) : { *ai-startup-healthbar.o(.bss._ZN8gameloft2ai11gang_memberE) }
    .ai_startup_storage_6 0x004b94bc (NOLOAD) : { *ai-startup-healthbar.o(.bss._ZN8gameloft2ai3copE) }
    .ai_startup_storage_7 0x004b94c4 (NOLOAD) : { *ai-startup-healthbar.o(.bss._ZN8gameloft2ai4swatE) }
    .ai_startup_storage_8 0x004b94cc (NOLOAD) : { *ai-startup-healthbar.o(.bss._ZN8gameloft2ai11civ_vehicleE) }
    .ai_startup_storage_9 0x004b94d4 (NOLOAD) : { *ai-startup-healthbar.o(.bss._ZN8gameloft2ai11cop_vehicleE) }
    .ai_startup_storage_10 0x004b94dc (NOLOAD) : { *ai-startup-healthbar.o(.bss._ZN8gameloft2ai5guardE) }
    .ai_startup_storage_11 0x004b94e4 (NOLOAD) : { *ai-startup-healthbar.o(.bss._ZN8gameloft2ai16scripted_vehicleE) }
    .bar_entry_0 0x003281f8 : { *ai-startup-healthbar.o(.text._ZThn4_NK9HealthBar6draw2dEv) }
    .bar_entry_1 0x0032820c : { *ai-startup-healthbar.o(.text._ZNK9HealthBar6draw2dEv) }
    .bar_entry_2 0x003282d8 : { *ai-startup-healthbar.o(.text._ZThn4_N9HealthBarD0Ev) }
    .bar_entry_3 0x003282ec : { *ai-startup-healthbar.o(.text._ZN9HealthBarD0Ev) }
    .bar_entry_4 0x0032831c : { *ai-startup-healthbar.o(.text._ZThn4_N9HealthBarD1Ev) }
    .bar_entry_5 0x00328330 : { *ai-startup-healthbar.o(.text._ZN9HealthBarD1Ev) }
    .bar_entry_6 0x0032835c : { *ai-startup-healthbar.o(.text._ZN9HealthBarC1EP7ASpriteiii) }
    .bar_vtable 0x004ac298 : { *ai-startup-healthbar.o(.data.rel.ro._ZTV9HealthBar) }
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
