OUTPUT_FORMAT("elf32-littlearm")
OUTPUT_ARCH(arm)
INCLUDE build/matches/script-manager-helpers/retail-symbols.ld
_ZN32retail_scriptmanager_transitions16civPassive_transE = 0x0042f464;
_ZN32retail_scriptmanager_transitions17scriptedNpc_transE = 0x0042f590;
_ZN32retail_scriptmanager_transitions19civAggressive_transE = 0x0042f5c0;
_ZN32retail_scriptmanager_transitions16gangMember_transE = 0x0042f6a4;
_ZN32retail_scriptmanager_transitions9cop_transE = 0x0042f6b0;
_ZN32retail_scriptmanager_transitions10swat_transE = 0x0042f7e8;
_ZN32retail_scriptmanager_transitions17civ_vehicle_transE = 0x0042f7f4;
_ZN32retail_scriptmanager_transitions17cop_vehicle_transE = 0x0042f884;
_ZN32retail_scriptmanager_transitions11guard_transE = 0x0042f938;
_ZN32retail_scriptmanager_transitions22scripted_vehicle_transE = 0x0042f9e0;
_ZdlPv = 0x001c42b0;
__aeabi_atexit = 0x001c494c;
INCLUDE config/linker/ScriptManagerQuerySections.ld
__cxa_guard_acquire = 0x001c4958;
__cxa_guard_release = 0x001c46c4;
SECTIONS
{
    .wanted_singleton 0x002dba04 : { *script-manager-helpers.o(.gnu.linkonce.t._ZN18WantedLevelManager11getInstanceEv) }
    .wanted_cleanup 0x0033d3b4 : { *script-manager-helpers.o(.text.__tcf_1) }
    .wanted_guard 0x004b6728 (NOLOAD) : { *script-manager-helpers.o(.gnu.linkonce.b._ZGVZN18WantedLevelManager11getInstanceEvE3wlm) }
    .wanted_instance 0x004b6a98 (NOLOAD) : { *script-manager-helpers.o(.gnu.linkonce.b._ZZN18WantedLevelManager11getInstanceEvE3wlm) }
    .helper_0 0x0033cffc : { *script-manager-helpers.o(.text._ZN13ScriptManager6resumeEv .gnu.linkonce.t._ZN13ScriptManager6resumeEv) }
    .helper_1 0x0033d034 : { *script-manager-helpers.o(.text._ZN13ScriptManager20skipBlockingCommandsEv .gnu.linkonce.t._ZN13ScriptManager20skipBlockingCommandsEv) }
    .helper_2 0x0033d08c : { *script-manager-helpers.o(.text._ZNK13ScriptManager10getMissionEv .gnu.linkonce.t._ZNK13ScriptManager10getMissionEv) }
    .helper_3 0x0033d0a4 : { *script-manager-helpers.o(.text._ZNK13ScriptManager22getCinematicsHudSpriteEv .gnu.linkonce.t._ZNK13ScriptManager22getCinematicsHudSpriteEv) }
    .helper_4 0x0033d0a8 : { *script-manager-helpers.o(.text._ZNK13ScriptManager7getRaceEv .gnu.linkonce.t._ZNK13ScriptManager7getRaceEv) }
    .module_startup_script_manager_helpers_function_0 0x0033d0c0 : { *script-manager-helpers.o(.text.__tcf_6) }
    .module_startup_script_manager_helpers_function_1 0x0033f9d8 : { *script-manager-helpers.o(.text._Z41__static_initialization_and_destruction_0ii) }
    .module_startup_script_manager_helpers_function_2 0x0033fb1c : { *script-manager-helpers.o(.text._GLOBAL__I__ZN13ScriptManager12s_playerTestE) }
    .module_startup_script_manager_helpers_storage_0 0x004ba59c (NOLOAD) : { *script-manager-helpers.o(.bss._ZN3irr5scene6quake315irrEmptyStringcE) }
    .module_startup_script_manager_helpers_storage_1 0x004ba5bc (NOLOAD) : { *script-manager-helpers.o(.bss._ZN3irr2ps5vHalfE) }
    .module_startup_script_manager_helpers_storage_2 0x004ba5c8 (NOLOAD) : { *script-manager-helpers.o(.bss._ZN8gameloft2ai11civ_passiveE) }
    .module_startup_script_manager_helpers_storage_3 0x004ba5d0 (NOLOAD) : { *script-manager-helpers.o(.bss._ZN8gameloft2ai12npc_scriptedE) }
    .module_startup_script_manager_helpers_storage_4 0x004ba5d8 (NOLOAD) : { *script-manager-helpers.o(.bss._ZN8gameloft2ai13civ_agressiveE) }
    .module_startup_script_manager_helpers_storage_5 0x004ba5e0 (NOLOAD) : { *script-manager-helpers.o(.bss._ZN8gameloft2ai11gang_memberE) }
    .module_startup_script_manager_helpers_storage_6 0x004ba5e8 (NOLOAD) : { *script-manager-helpers.o(.bss._ZN8gameloft2ai3copE) }
    .module_startup_script_manager_helpers_storage_7 0x004ba5f0 (NOLOAD) : { *script-manager-helpers.o(.bss._ZN8gameloft2ai4swatE) }
    .module_startup_script_manager_helpers_storage_8 0x004ba5f8 (NOLOAD) : { *script-manager-helpers.o(.bss._ZN8gameloft2ai11civ_vehicleE) }
    .module_startup_script_manager_helpers_storage_9 0x004ba600 (NOLOAD) : { *script-manager-helpers.o(.bss._ZN8gameloft2ai11cop_vehicleE) }
    .module_startup_script_manager_helpers_storage_10 0x004ba608 (NOLOAD) : { *script-manager-helpers.o(.bss._ZN8gameloft2ai5guardE) }
    .module_startup_script_manager_helpers_storage_11 0x004ba610 (NOLOAD) : { *script-manager-helpers.o(.bss._ZN8gameloft2ai16scripted_vehicleE) }

.got 0x004b0048 : { *(.got.plt) . = 0x360; *(.got) }
    .verification 0x00600000 : { *retail-got.o(.text) }
    .shared_startup_empty_text 0x0044d91c : { *(.gnu.linkonce.r.localStartupEmptyText) }
}
ASSERT(SIZEOF(.module_startup_script_manager_helpers_storage_0) == 32, "script-manager-helpers _ZN3irr5scene6quake315irrEmptyStringcE extent");
ASSERT(SIZEOF(.module_startup_script_manager_helpers_storage_1) == 12, "script-manager-helpers _ZN3irr2ps5vHalfE extent");
ASSERT(SIZEOF(.module_startup_script_manager_helpers_storage_2) == 8, "script-manager-helpers _ZN8gameloft2ai11civ_passiveE extent");
ASSERT(SIZEOF(.module_startup_script_manager_helpers_storage_3) == 8, "script-manager-helpers _ZN8gameloft2ai12npc_scriptedE extent");
ASSERT(SIZEOF(.module_startup_script_manager_helpers_storage_4) == 8, "script-manager-helpers _ZN8gameloft2ai13civ_agressiveE extent");
ASSERT(SIZEOF(.module_startup_script_manager_helpers_storage_5) == 8, "script-manager-helpers _ZN8gameloft2ai11gang_memberE extent");
ASSERT(SIZEOF(.module_startup_script_manager_helpers_storage_6) == 8, "script-manager-helpers _ZN8gameloft2ai3copE extent");
ASSERT(SIZEOF(.module_startup_script_manager_helpers_storage_7) == 8, "script-manager-helpers _ZN8gameloft2ai4swatE extent");
ASSERT(SIZEOF(.module_startup_script_manager_helpers_storage_8) == 8, "script-manager-helpers _ZN8gameloft2ai11civ_vehicleE extent");
ASSERT(SIZEOF(.module_startup_script_manager_helpers_storage_9) == 8, "script-manager-helpers _ZN8gameloft2ai11cop_vehicleE extent");
ASSERT(SIZEOF(.module_startup_script_manager_helpers_storage_10) == 8, "script-manager-helpers _ZN8gameloft2ai5guardE extent");
ASSERT(SIZEOF(.module_startup_script_manager_helpers_storage_11) == 8, "script-manager-helpers _ZN8gameloft2ai16scripted_vehicleE extent");
ASSERT(SIZEOF(.script_manager_instance_guard) == 4, "ScriptManager singleton guard extent");
ASSERT(SIZEOF(.script_manager_instance_storage) == 108, "ScriptManager singleton storage extent");
