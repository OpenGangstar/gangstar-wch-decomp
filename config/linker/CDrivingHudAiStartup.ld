OUTPUT_FORMAT("elf32-littlearm")
OUTPUT_ARCH(arm)
INCLUDE build/matches/ai-startup-cdrivinghud/retail-symbols.ld
_ZdlPv = 0x001c42b0;
__aeabi_atexit = 0x001c494c;
_ZN30retail_cdrivinghud_transitions16civPassive_transE = 0x004217f8;
_ZN30retail_cdrivinghud_transitions17scriptedNpc_transE = 0x00421924;
_ZN30retail_cdrivinghud_transitions19civAggressive_transE = 0x00421954;
_ZN30retail_cdrivinghud_transitions16gangMember_transE = 0x00421a38;
_ZN30retail_cdrivinghud_transitions9cop_transE = 0x00421a44;
_ZN30retail_cdrivinghud_transitions10swat_transE = 0x00421b7c;
_ZN30retail_cdrivinghud_transitions17civ_vehicle_transE = 0x00421b88;
_ZN30retail_cdrivinghud_transitions17cop_vehicle_transE = 0x00421c18;
_ZN30retail_cdrivinghud_transitions11guard_transE = 0x00421ccc;
_ZN30retail_cdrivinghud_transitions22scripted_vehicle_transE = 0x00421d74;
SECTIONS
{
    .ai_startup_function_0 0x0032307c : { *ai-startup-cdrivinghud.o(.text.__tcf_3) }
    .ai_startup_function_1 0x0032344c : { *ai-startup-cdrivinghud.o(.text._Z41__static_initialization_and_destruction_0ii) }
    .ai_startup_function_2 0x00323590 : { *ai-startup-cdrivinghud.o(.text._GLOBAL__I__ZN11CDrivingHudC2EP11CHudManager) }
    .ai_startup_storage_0 0x004b908c (NOLOAD) : { *ai-startup-cdrivinghud.o(.bss._ZN3irr5scene6quake315irrEmptyStringcE) }
    .ai_startup_storage_1 0x004b90ac (NOLOAD) : { *ai-startup-cdrivinghud.o(.bss._ZN3irr2ps5vHalfE) }
    .ai_startup_storage_2 0x004b90b8 (NOLOAD) : { *ai-startup-cdrivinghud.o(.bss._ZN8gameloft2ai11civ_passiveE) }
    .ai_startup_storage_3 0x004b90c0 (NOLOAD) : { *ai-startup-cdrivinghud.o(.bss._ZN8gameloft2ai12npc_scriptedE) }
    .ai_startup_storage_4 0x004b90c8 (NOLOAD) : { *ai-startup-cdrivinghud.o(.bss._ZN8gameloft2ai13civ_agressiveE) }
    .ai_startup_storage_5 0x004b90d0 (NOLOAD) : { *ai-startup-cdrivinghud.o(.bss._ZN8gameloft2ai11gang_memberE) }
    .ai_startup_storage_6 0x004b90d8 (NOLOAD) : { *ai-startup-cdrivinghud.o(.bss._ZN8gameloft2ai3copE) }
    .ai_startup_storage_7 0x004b90e0 (NOLOAD) : { *ai-startup-cdrivinghud.o(.bss._ZN8gameloft2ai4swatE) }
    .ai_startup_storage_8 0x004b90e8 (NOLOAD) : { *ai-startup-cdrivinghud.o(.bss._ZN8gameloft2ai11civ_vehicleE) }
    .ai_startup_storage_9 0x004b90f0 (NOLOAD) : { *ai-startup-cdrivinghud.o(.bss._ZN8gameloft2ai11cop_vehicleE) }
    .ai_startup_storage_10 0x004b90f8 (NOLOAD) : { *ai-startup-cdrivinghud.o(.bss._ZN8gameloft2ai5guardE) }
    .ai_startup_storage_11 0x004b9100 (NOLOAD) : { *ai-startup-cdrivinghud.o(.bss._ZN8gameloft2ai16scripted_vehicleE) }
    .hud_entry_0 0x00322f58 : { *ai-startup-cdrivinghud.o(.text._ZN11CDrivingHudC1EP11CHudManager) }
    .hud_entry_1 0x00322f88 : { *ai-startup-cdrivinghud.o(.text._ZN11CDrivingHudD1Ev) }
    .hud_showSpyGauge 0x00322fa0 : { *ai-startup-cdrivinghud.o(.text._ZN11CDrivingHud12showSpyGaugeEb) }
    .hud_showCash 0x00322fdc : { *ai-startup-cdrivinghud.o(.text._ZN11CDrivingHud8showCashEb) }
    .hud_weapon_selector 0x00322ffc : { *ai-startup-cdrivinghud.o(.text._ZN11CDrivingHud20toggleWeaponSelectorEb) }
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
