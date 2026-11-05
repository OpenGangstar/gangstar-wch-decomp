OUTPUT_FORMAT("elf32-littlearm")
OUTPUT_ARCH(arm)
INCLUDE build/matches/hud-manager-helpers/retail-symbols.ld
_ZN30retail_chudmanager_transitions16civPassive_transE = 0x00421de4;
_ZN30retail_chudmanager_transitions17scriptedNpc_transE = 0x00421f10;
_ZN30retail_chudmanager_transitions19civAggressive_transE = 0x00421f40;
_ZN30retail_chudmanager_transitions16gangMember_transE = 0x00422024;
_ZN30retail_chudmanager_transitions9cop_transE = 0x00422030;
_ZN30retail_chudmanager_transitions10swat_transE = 0x00422168;
_ZN30retail_chudmanager_transitions17civ_vehicle_transE = 0x00422174;
_ZN30retail_chudmanager_transitions17cop_vehicle_transE = 0x00422204;
_ZN30retail_chudmanager_transitions11guard_transE = 0x004222b8;
_ZN30retail_chudmanager_transitions22scripted_vehicle_transE = 0x00422360;
_ZdlPv = 0x001c42b0;
__aeabi_atexit = 0x001c494c;
INCLUDE config/linker/CHudManagerSpySections.ld
SECTIONS
{
    .helper_0 0x003235a4 : { *hud-manager-helpers.o(.text._ZN11CHudManager4initEv .gnu.linkonce.t._ZN11CHudManager4initEv) }
    .helper_1 0x003235e4 : { *hud-manager-helpers.o(.text._ZN11CHudManager4lockEv .gnu.linkonce.t._ZN11CHudManager4lockEv) }
    .helper_2 0x003235ec : { *hud-manager-helpers.o(.text._ZN11CHudManager6unlockEv .gnu.linkonce.t._ZN11CHudManager6unlockEv) }
    .helper_3 0x003235f4 : { *hud-manager-helpers.o(.text._ZNK11CHudManager8isLockedEv .gnu.linkonce.t._ZNK11CHudManager8isLockedEv) }
    .module_startup_hud_manager_helpers_function_0 0x003236b8 : { *hud-manager-helpers.o(.text.__tcf_3) }
    .module_startup_hud_manager_helpers_function_1 0x00323ed8 : { *hud-manager-helpers.o(.text._Z41__static_initialization_and_destruction_0ii) }
    .module_startup_hud_manager_helpers_function_2 0x0032401c : { *hud-manager-helpers.o(.text._GLOBAL__I__ZN11CHudManagerC2Ev) }
    .module_startup_hud_manager_helpers_storage_0 0x004b9108 (NOLOAD) : { *hud-manager-helpers.o(.bss._ZN3irr5scene6quake315irrEmptyStringcE) }
    .module_startup_hud_manager_helpers_storage_1 0x004b9128 (NOLOAD) : { *hud-manager-helpers.o(.bss._ZN3irr2ps5vHalfE) }
    .module_startup_hud_manager_helpers_storage_2 0x004b9134 (NOLOAD) : { *hud-manager-helpers.o(.bss._ZN8gameloft2ai11civ_passiveE) }
    .module_startup_hud_manager_helpers_storage_3 0x004b913c (NOLOAD) : { *hud-manager-helpers.o(.bss._ZN8gameloft2ai12npc_scriptedE) }
    .module_startup_hud_manager_helpers_storage_4 0x004b9144 (NOLOAD) : { *hud-manager-helpers.o(.bss._ZN8gameloft2ai13civ_agressiveE) }
    .module_startup_hud_manager_helpers_storage_5 0x004b914c (NOLOAD) : { *hud-manager-helpers.o(.bss._ZN8gameloft2ai11gang_memberE) }
    .module_startup_hud_manager_helpers_storage_6 0x004b9154 (NOLOAD) : { *hud-manager-helpers.o(.bss._ZN8gameloft2ai3copE) }
    .module_startup_hud_manager_helpers_storage_7 0x004b915c (NOLOAD) : { *hud-manager-helpers.o(.bss._ZN8gameloft2ai4swatE) }
    .module_startup_hud_manager_helpers_storage_8 0x004b9164 (NOLOAD) : { *hud-manager-helpers.o(.bss._ZN8gameloft2ai11civ_vehicleE) }
    .module_startup_hud_manager_helpers_storage_9 0x004b916c (NOLOAD) : { *hud-manager-helpers.o(.bss._ZN8gameloft2ai11cop_vehicleE) }
    .module_startup_hud_manager_helpers_storage_10 0x004b9174 (NOLOAD) : { *hud-manager-helpers.o(.bss._ZN8gameloft2ai5guardE) }
    .module_startup_hud_manager_helpers_storage_11 0x004b917c (NOLOAD) : { *hud-manager-helpers.o(.bss._ZN8gameloft2ai16scripted_vehicleE) }

.got 0x004b0048 : { *(.got.plt) . = 0x360; *(.got) }
    .verification 0x00600000 : { *retail-got.o(.text) }
    .shared_startup_empty_text 0x0044d91c : { *(.gnu.linkonce.r.localStartupEmptyText) }
}
ASSERT(SIZEOF(.module_startup_hud_manager_helpers_storage_0) == 32, "hud-manager-helpers _ZN3irr5scene6quake315irrEmptyStringcE extent");
ASSERT(SIZEOF(.module_startup_hud_manager_helpers_storage_1) == 12, "hud-manager-helpers _ZN3irr2ps5vHalfE extent");
ASSERT(SIZEOF(.module_startup_hud_manager_helpers_storage_2) == 8, "hud-manager-helpers _ZN8gameloft2ai11civ_passiveE extent");
ASSERT(SIZEOF(.module_startup_hud_manager_helpers_storage_3) == 8, "hud-manager-helpers _ZN8gameloft2ai12npc_scriptedE extent");
ASSERT(SIZEOF(.module_startup_hud_manager_helpers_storage_4) == 8, "hud-manager-helpers _ZN8gameloft2ai13civ_agressiveE extent");
ASSERT(SIZEOF(.module_startup_hud_manager_helpers_storage_5) == 8, "hud-manager-helpers _ZN8gameloft2ai11gang_memberE extent");
ASSERT(SIZEOF(.module_startup_hud_manager_helpers_storage_6) == 8, "hud-manager-helpers _ZN8gameloft2ai3copE extent");
ASSERT(SIZEOF(.module_startup_hud_manager_helpers_storage_7) == 8, "hud-manager-helpers _ZN8gameloft2ai4swatE extent");
ASSERT(SIZEOF(.module_startup_hud_manager_helpers_storage_8) == 8, "hud-manager-helpers _ZN8gameloft2ai11civ_vehicleE extent");
ASSERT(SIZEOF(.module_startup_hud_manager_helpers_storage_9) == 8, "hud-manager-helpers _ZN8gameloft2ai11cop_vehicleE extent");
ASSERT(SIZEOF(.module_startup_hud_manager_helpers_storage_10) == 8, "hud-manager-helpers _ZN8gameloft2ai5guardE extent");
ASSERT(SIZEOF(.module_startup_hud_manager_helpers_storage_11) == 8, "hud-manager-helpers _ZN8gameloft2ai16scripted_vehicleE extent");
