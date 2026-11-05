OUTPUT_FORMAT("elf32-littlearm")
OUTPUT_ARCH(arm)
INCLUDE build/matches/ai-startup-spygauge/retail-symbols.ld
_ZdlPv = 0x001c42b0;
__aeabi_atexit = 0x001c494c;
_ZN27retail_spygauge_transitions16civPassive_transE = 0x00424da4;
_ZN27retail_spygauge_transitions17scriptedNpc_transE = 0x00424ed0;
_ZN27retail_spygauge_transitions19civAggressive_transE = 0x00424f00;
_ZN27retail_spygauge_transitions16gangMember_transE = 0x00424fe4;
_ZN27retail_spygauge_transitions9cop_transE = 0x00424ff0;
_ZN27retail_spygauge_transitions10swat_transE = 0x00425128;
_ZN27retail_spygauge_transitions17civ_vehicle_transE = 0x00425134;
_ZN27retail_spygauge_transitions17cop_vehicle_transE = 0x004251c4;
_ZN27retail_spygauge_transitions11guard_transE = 0x00425278;
_ZN27retail_spygauge_transitions22scripted_vehicle_transE = 0x00425320;
SECTIONS
{
    .ai_startup_function_0 0x0032b91c : { *ai-startup-spygauge.o(.text.__tcf_3) }
    .ai_startup_function_1 0x0032ba70 : { *ai-startup-spygauge.o(.text._Z41__static_initialization_and_destruction_0ii) }
    .ai_startup_function_2 0x0032bbb4 : { *ai-startup-spygauge.o(.text._GLOBAL__I__ZN8SpyGaugeC2EP7ASpriteiiiii) }
    .ai_startup_storage_0 0x004b970c (NOLOAD) : { *ai-startup-spygauge.o(.bss._ZN3irr5scene6quake315irrEmptyStringcE) }
    .ai_startup_storage_1 0x004b972c (NOLOAD) : { *ai-startup-spygauge.o(.bss._ZN3irr2ps5vHalfE) }
    .ai_startup_storage_2 0x004b9738 (NOLOAD) : { *ai-startup-spygauge.o(.bss._ZN8gameloft2ai11civ_passiveE) }
    .ai_startup_storage_3 0x004b9740 (NOLOAD) : { *ai-startup-spygauge.o(.bss._ZN8gameloft2ai12npc_scriptedE) }
    .ai_startup_storage_4 0x004b9748 (NOLOAD) : { *ai-startup-spygauge.o(.bss._ZN8gameloft2ai13civ_agressiveE) }
    .ai_startup_storage_5 0x004b9750 (NOLOAD) : { *ai-startup-spygauge.o(.bss._ZN8gameloft2ai11gang_memberE) }
    .ai_startup_storage_6 0x004b9758 (NOLOAD) : { *ai-startup-spygauge.o(.bss._ZN8gameloft2ai3copE) }
    .ai_startup_storage_7 0x004b9760 (NOLOAD) : { *ai-startup-spygauge.o(.bss._ZN8gameloft2ai4swatE) }
    .ai_startup_storage_8 0x004b9768 (NOLOAD) : { *ai-startup-spygauge.o(.bss._ZN8gameloft2ai11civ_vehicleE) }
    .ai_startup_storage_9 0x004b9770 (NOLOAD) : { *ai-startup-spygauge.o(.bss._ZN8gameloft2ai11cop_vehicleE) }
    .ai_startup_storage_10 0x004b9778 (NOLOAD) : { *ai-startup-spygauge.o(.bss._ZN8gameloft2ai5guardE) }
    .ai_startup_storage_11 0x004b9780 (NOLOAD) : { *ai-startup-spygauge.o(.bss._ZN8gameloft2ai16scripted_vehicleE) }
    .spy_gauge_entry_0 0x0032b900 : { *ai-startup-spygauge.o(.text._ZN8SpyGauge6updateEd) }
    .spy_gauge_entry_1 0x0032b904 : { *ai-startup-spygauge.o(.text._ZN8SpyGauge14useDriveWellBGEv) }
    .spy_gauge_entry_2 0x0032b90c : { *ai-startup-spygauge.o(.text._ZN8SpyGauge13useDriveBadBGEv) }
    .spy_gauge_entry_3 0x0032b914 : { *ai-startup-spygauge.o(.text._ZN8SpyGauge8useSpyBGEv) }
    .spy_gauge_entry_4 0x0032b94c : { *ai-startup-spygauge.o(.text._ZThn4_NK8SpyGauge6draw2dEv) }
    .spy_gauge_entry_5 0x0032b960 : { *ai-startup-spygauge.o(.text._ZNK8SpyGauge6draw2dEv) }
    .spy_gauge_entry_6 0x0032b9ac : { *ai-startup-spygauge.o(.text._ZThn4_N8SpyGaugeD0Ev) }
    .spy_gauge_entry_7 0x0032b9c0 : { *ai-startup-spygauge.o(.text._ZN8SpyGaugeD0Ev) }
    .spy_gauge_entry_8 0x0032b9f0 : { *ai-startup-spygauge.o(.text._ZThn4_N8SpyGaugeD1Ev) }
    .spy_gauge_entry_9 0x0032ba04 : { *ai-startup-spygauge.o(.text._ZN8SpyGaugeD1Ev) }
    .spy_gauge_entry_10 0x0032ba30 : { *ai-startup-spygauge.o(.text._ZN8SpyGaugeC1EP7ASpriteiiiii) }
    .spy_gauge_vtable 0x004ac730 : { *ai-startup-spygauge.o(.data.rel.ro._ZTV8SpyGauge) }
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
