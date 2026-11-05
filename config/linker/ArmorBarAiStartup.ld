OUTPUT_FORMAT("elf32-littlearm")
OUTPUT_ARCH(arm)
INCLUDE build/matches/ai-startup-armorbar/retail-symbols.ld
_ZdlPv = 0x001c42b0;
__aeabi_atexit = 0x001c494c;
_ZN27retail_armorbar_transitions16civPassive_transE = 0x00422a50;
_ZN27retail_armorbar_transitions17scriptedNpc_transE = 0x00422b7c;
_ZN27retail_armorbar_transitions19civAggressive_transE = 0x00422bac;
_ZN27retail_armorbar_transitions16gangMember_transE = 0x00422c90;
_ZN27retail_armorbar_transitions9cop_transE = 0x00422c9c;
_ZN27retail_armorbar_transitions10swat_transE = 0x00422dd4;
_ZN27retail_armorbar_transitions17civ_vehicle_transE = 0x00422de0;
_ZN27retail_armorbar_transitions17cop_vehicle_transE = 0x00422e70;
_ZN27retail_armorbar_transitions11guard_transE = 0x00422f24;
_ZN27retail_armorbar_transitions22scripted_vehicle_transE = 0x00422fcc;
__aeabi_idiv = 0x001c43dc;
SECTIONS
{
    .ai_startup_function_0 0x00327234 : { *ai-startup-armorbar.o(.text.__tcf_3) }
    .ai_startup_function_1 0x00327398 : { *ai-startup-armorbar.o(.text._Z41__static_initialization_and_destruction_0ii) }
    .ai_startup_function_2 0x003274dc : { *ai-startup-armorbar.o(.text._GLOBAL__I__ZN8ArmorBarC2EP7ASpriteiii) }
    .ai_startup_storage_0 0x004b92a4 (NOLOAD) : { *ai-startup-armorbar.o(.bss._ZN3irr5scene6quake315irrEmptyStringcE) }
    .ai_startup_storage_1 0x004b92c4 (NOLOAD) : { *ai-startup-armorbar.o(.bss._ZN3irr2ps5vHalfE) }
    .ai_startup_storage_2 0x004b92d0 (NOLOAD) : { *ai-startup-armorbar.o(.bss._ZN8gameloft2ai11civ_passiveE) }
    .ai_startup_storage_3 0x004b92d8 (NOLOAD) : { *ai-startup-armorbar.o(.bss._ZN8gameloft2ai12npc_scriptedE) }
    .ai_startup_storage_4 0x004b92e0 (NOLOAD) : { *ai-startup-armorbar.o(.bss._ZN8gameloft2ai13civ_agressiveE) }
    .ai_startup_storage_5 0x004b92e8 (NOLOAD) : { *ai-startup-armorbar.o(.bss._ZN8gameloft2ai11gang_memberE) }
    .ai_startup_storage_6 0x004b92f0 (NOLOAD) : { *ai-startup-armorbar.o(.bss._ZN8gameloft2ai3copE) }
    .ai_startup_storage_7 0x004b92f8 (NOLOAD) : { *ai-startup-armorbar.o(.bss._ZN8gameloft2ai4swatE) }
    .ai_startup_storage_8 0x004b9300 (NOLOAD) : { *ai-startup-armorbar.o(.bss._ZN8gameloft2ai11civ_vehicleE) }
    .ai_startup_storage_9 0x004b9308 (NOLOAD) : { *ai-startup-armorbar.o(.bss._ZN8gameloft2ai11cop_vehicleE) }
    .ai_startup_storage_10 0x004b9310 (NOLOAD) : { *ai-startup-armorbar.o(.bss._ZN8gameloft2ai5guardE) }
    .ai_startup_storage_11 0x004b9318 (NOLOAD) : { *ai-startup-armorbar.o(.bss._ZN8gameloft2ai16scripted_vehicleE) }
    .bar_entry_0 0x00327230 : { *ai-startup-armorbar.o(.gnu.linkonce.t._ZN8ArmorBar4showEv) }
    .bar_entry_1 0x00327264 : { *ai-startup-armorbar.o(.text._ZThn4_NK8ArmorBar6draw2dEv) }
    .bar_entry_2 0x00327278 : { *ai-startup-armorbar.o(.text._ZNK8ArmorBar6draw2dEv) }
    .bar_entry_3 0x003272e0 : { *ai-startup-armorbar.o(.text._ZThn4_N8ArmorBarD0Ev) }
    .bar_entry_4 0x003272f4 : { *ai-startup-armorbar.o(.text._ZN8ArmorBarD0Ev) }
    .bar_entry_5 0x00327324 : { *ai-startup-armorbar.o(.text._ZThn4_N8ArmorBarD1Ev) }
    .bar_entry_6 0x00327338 : { *ai-startup-armorbar.o(.text._ZN8ArmorBarD1Ev) }
    .bar_entry_7 0x00327364 : { *ai-startup-armorbar.o(.text._ZN8ArmorBarC1EP7ASpriteiii) }
    .bar_update 0x0032728c : { *ai-startup-armorbar.o(.text._ZN8ArmorBar6updateEd) }
    .bar_vtable 0x004ac018 : { *ai-startup-armorbar.o(.data.rel.ro._ZTV8ArmorBar) }
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
