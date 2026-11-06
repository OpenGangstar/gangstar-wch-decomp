OUTPUT_FORMAT("elf32-littlearm")
OUTPUT_ARCH(arm)
INCLUDE build/matches/ai-startup-menumanager_map/retail-symbols.ld
_ZdlPv = 0x001c42b0;
__aeabi_atexit = 0x001c494c;
_ZN34retail_menumanager_map_transitions16civPassive_transE = 0x00419830;
_ZN34retail_menumanager_map_transitions17scriptedNpc_transE = 0x0041995c;
_ZN34retail_menumanager_map_transitions19civAggressive_transE = 0x0041998c;
_ZN34retail_menumanager_map_transitions16gangMember_transE = 0x00419a70;
_ZN34retail_menumanager_map_transitions9cop_transE = 0x00419a7c;
_ZN34retail_menumanager_map_transitions10swat_transE = 0x00419bb4;
_ZN34retail_menumanager_map_transitions17civ_vehicle_transE = 0x00419bc0;
_ZN34retail_menumanager_map_transitions17cop_vehicle_transE = 0x00419c50;
_ZN34retail_menumanager_map_transitions11guard_transE = 0x00419d04;
_ZN34retail_menumanager_map_transitions22scripted_vehicle_transE = 0x00419dac;
__cxa_guard_acquire = 0x001c4958;
__cxa_guard_release = 0x001c46c4;
SECTIONS
{
    .map_singleton 0x002dbb58 : { *ai-startup-menumanager_map.o(.gnu.linkonce.t._ZN3Map11getInstanceEv) }
    .map_cleanup 0x2e6628 : { *ai-startup-menumanager_map.o(.text.__tcf_1) }
    .map_guard 0x004b6a94 (NOLOAD) : { *ai-startup-menumanager_map.o(.gnu.linkonce.b._ZGVZN3Map11getInstanceEvE3map) }
    .map_instance 0x004b6b00 (NOLOAD) : { *ai-startup-menumanager_map.o(.gnu.linkonce.b._ZZN3Map11getInstanceEvE3map) }
    .target_marker_singleton 0x002e6660 : { *ai-startup-menumanager_map.o(.gnu.linkonce.t._ZN12TargetMarker11getInstanceEv .text._ZN12TargetMarker11getInstanceEv) }
    .target_marker_cleanup 0x002e66d4 : { *ai-startup-menumanager_map.o(.text.__tcf_0) }
    .target_marker_guard 0x004b7bd4 (NOLOAD) : { *ai-startup-menumanager_map.o(.gnu.linkonce.b._ZGVZN12TargetMarker11getInstanceEvE3map) }
    .target_marker_storage 0x004b7c54 (NOLOAD) : { *ai-startup-menumanager_map.o(.gnu.linkonce.b._ZZN12TargetMarker11getInstanceEvE3map) }
    .ai_startup_function_0 0x002e65f8 : { *ai-startup-menumanager_map.o(.text.__tcf_6) }
    .ai_startup_function_1 0x002e6c58 : { *ai-startup-menumanager_map.o(.text._Z41__static_initialization_and_destruction_0ii) }
    .ai_startup_function_2 0x002e6d9c : { *ai-startup-menumanager_map.o(.text._GLOBAL__I__ZN11MenuManager7initMapEv) }
    .ai_startup_storage_0 0x004b7bd8 (NOLOAD) : { *ai-startup-menumanager_map.o(.bss._ZN3irr5scene6quake315irrEmptyStringcE) }
    .ai_startup_storage_1 0x004b7bf8 (NOLOAD) : { *ai-startup-menumanager_map.o(.bss._ZN3irr2ps5vHalfE) }
    .ai_startup_storage_2 0x004b7c04 (NOLOAD) : { *ai-startup-menumanager_map.o(.bss._ZN8gameloft2ai11civ_passiveE) }
    .ai_startup_storage_3 0x004b7c0c (NOLOAD) : { *ai-startup-menumanager_map.o(.bss._ZN8gameloft2ai12npc_scriptedE) }
    .ai_startup_storage_4 0x004b7c14 (NOLOAD) : { *ai-startup-menumanager_map.o(.bss._ZN8gameloft2ai13civ_agressiveE) }
    .ai_startup_storage_5 0x004b7c1c (NOLOAD) : { *ai-startup-menumanager_map.o(.bss._ZN8gameloft2ai11gang_memberE) }
    .ai_startup_storage_6 0x004b7c24 (NOLOAD) : { *ai-startup-menumanager_map.o(.bss._ZN8gameloft2ai3copE) }
    .ai_startup_storage_7 0x004b7c2c (NOLOAD) : { *ai-startup-menumanager_map.o(.bss._ZN8gameloft2ai4swatE) }
    .ai_startup_storage_8 0x004b7c34 (NOLOAD) : { *ai-startup-menumanager_map.o(.bss._ZN8gameloft2ai11civ_vehicleE) }
    .ai_startup_storage_9 0x004b7c3c (NOLOAD) : { *ai-startup-menumanager_map.o(.bss._ZN8gameloft2ai11cop_vehicleE) }
    .ai_startup_storage_10 0x004b7c44 (NOLOAD) : { *ai-startup-menumanager_map.o(.bss._ZN8gameloft2ai5guardE) }
    .ai_startup_storage_11 0x004b7c4c (NOLOAD) : { *ai-startup-menumanager_map.o(.bss._ZN8gameloft2ai16scripted_vehicleE) }
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
ASSERT(SIZEOF(.target_marker_guard) == 4, "TargetMarker singleton guard extent");
ASSERT(SIZEOF(.target_marker_storage) == 28, "TargetMarker singleton storage extent");
