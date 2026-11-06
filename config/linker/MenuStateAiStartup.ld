OUTPUT_FORMAT("elf32-littlearm")
OUTPUT_ARCH(arm)
INCLUDE build/matches/ai-startup-menustate/retail-symbols.ld
_ZdlPv = 0x001c42b0;
__aeabi_atexit = 0x001c494c;
_ZN28retail_menustate_transitions16civPassive_transE = 0x0041a084;
_ZN28retail_menustate_transitions17scriptedNpc_transE = 0x0041a1b0;
_ZN28retail_menustate_transitions19civAggressive_transE = 0x0041a1e0;
_ZN28retail_menustate_transitions16gangMember_transE = 0x0041a2c4;
_ZN28retail_menustate_transitions9cop_transE = 0x0041a2d0;
_ZN28retail_menustate_transitions10swat_transE = 0x0041a408;
_ZN28retail_menustate_transitions17civ_vehicle_transE = 0x0041a414;
_ZN28retail_menustate_transitions17cop_vehicle_transE = 0x0041a4a4;
_ZN28retail_menustate_transitions11guard_transE = 0x0041a558;
_ZN28retail_menustate_transitions22scripted_vehicle_transE = 0x0041a600;
__cxa_guard_acquire = 0x001c4958;
__cxa_guard_release = 0x001c46c4;
SECTIONS
{
    .wanted_singleton 0x002dba04 : { *ai-startup-menustate.o(.gnu.linkonce.t._ZN18WantedLevelManager11getInstanceEv) }
    .wanted_cleanup 0x002e761c : { *ai-startup-menustate.o(.text.__tcf_0) }
    .wanted_guard 0x004b6728 (NOLOAD) : { *ai-startup-menustate.o(.gnu.linkonce.b._ZGVZN18WantedLevelManager11getInstanceEvE3wlm) }
    .wanted_instance 0x004b6a98 (NOLOAD) : { *ai-startup-menustate.o(.gnu.linkonce.b._ZZN18WantedLevelManager11getInstanceEvE3wlm) }
    .ai_startup_function_0 0x002e73b0 : { *ai-startup-menustate.o(.text.__tcf_6) }
    .ai_startup_function_1 0x002e9564 : { *ai-startup-menustate.o(.text._Z41__static_initialization_and_destruction_0ii) }
    .ai_startup_function_2 0x002e96a8 : { *ai-startup-menustate.o(.text._GLOBAL__I__ZN9MenuStateC2EPKc) }
    .ai_startup_storage_0 0x004b7c70 (NOLOAD) : { *ai-startup-menustate.o(.bss._ZN3irr5scene6quake315irrEmptyStringcE) }
    .ai_startup_storage_1 0x004b7c90 (NOLOAD) : { *ai-startup-menustate.o(.bss._ZN3irr2ps5vHalfE) }
    .ai_startup_storage_2 0x004b7c9c (NOLOAD) : { *ai-startup-menustate.o(.bss._ZN8gameloft2ai11civ_passiveE) }
    .ai_startup_storage_3 0x004b7ca4 (NOLOAD) : { *ai-startup-menustate.o(.bss._ZN8gameloft2ai12npc_scriptedE) }
    .ai_startup_storage_4 0x004b7cac (NOLOAD) : { *ai-startup-menustate.o(.bss._ZN8gameloft2ai13civ_agressiveE) }
    .ai_startup_storage_5 0x004b7cb4 (NOLOAD) : { *ai-startup-menustate.o(.bss._ZN8gameloft2ai11gang_memberE) }
    .ai_startup_storage_6 0x004b7cbc (NOLOAD) : { *ai-startup-menustate.o(.bss._ZN8gameloft2ai3copE) }
    .ai_startup_storage_7 0x004b7cc4 (NOLOAD) : { *ai-startup-menustate.o(.bss._ZN8gameloft2ai4swatE) }
    .ai_startup_storage_8 0x004b7ccc (NOLOAD) : { *ai-startup-menustate.o(.bss._ZN8gameloft2ai11civ_vehicleE) }
    .ai_startup_storage_9 0x004b7cd4 (NOLOAD) : { *ai-startup-menustate.o(.bss._ZN8gameloft2ai11cop_vehicleE) }
    .ai_startup_storage_10 0x004b7cdc (NOLOAD) : { *ai-startup-menustate.o(.bss._ZN8gameloft2ai5guardE) }
    .ai_startup_storage_11 0x004b7ce4 (NOLOAD) : { *ai-startup-menustate.o(.bss._ZN8gameloft2ai16scripted_vehicleE) }
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
