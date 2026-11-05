OUTPUT_FORMAT("elf32-littlearm")
OUTPUT_ARCH(arm)
INCLUDE build/matches/state-hooks-gscarrentalmenu/retail-symbols.ld
_ZdlPv = 0x001c42b0;
_ZN34retail_gscarrentalmenu_transitions16civPassive_transE = 0x00415854;
_ZN34retail_gscarrentalmenu_transitions17scriptedNpc_transE = 0x00415980;
_ZN34retail_gscarrentalmenu_transitions19civAggressive_transE = 0x004159b0;
_ZN34retail_gscarrentalmenu_transitions16gangMember_transE = 0x00415a94;
_ZN34retail_gscarrentalmenu_transitions9cop_transE = 0x00415aa0;
_ZN34retail_gscarrentalmenu_transitions10swat_transE = 0x00415bd8;
_ZN34retail_gscarrentalmenu_transitions17civ_vehicle_transE = 0x00415be4;
_ZN34retail_gscarrentalmenu_transitions17cop_vehicle_transE = 0x00415c74;
_ZN34retail_gscarrentalmenu_transitions11guard_transE = 0x00415d28;
_ZN34retail_gscarrentalmenu_transitions22scripted_vehicle_transE = 0x00415dd0;
__aeabi_atexit = 0x001c494c;
__cxa_guard_acquire = 0x001c4958;
__cxa_guard_release = 0x001c46c4;
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
INCLUDE config/linker/CHudManagerSpySections.ld
INCLUDE config/linker/CHudManagerWalkingSections.ld
SECTIONS
{
    .hook_0 0x002e12f4 : { *state-hooks-gscarrentalmenu.o(.text._ZN15GSCarRentalMenu6updateEP12StateMachine .gnu.linkonce.t._ZN15GSCarRentalMenu6updateEP12StateMachine) }
    .hook_1 0x002e12f8 : { *state-hooks-gscarrentalmenu.o(.text._ZN15GSCarRentalMenu4drawEPK12StateMachine .gnu.linkonce.t._ZN15GSCarRentalMenu4drawEPK12StateMachine) }
    .state_ctor 0x002e12dc : { *state-hooks-gscarrentalmenu.o(.text._ZN15GSCarRentalMenuC1Ev) }
    .base_0 0x002dacc0 : { *state-hooks-gscarrentalmenu.o(.gnu.linkonce.t._ZN9StateBase8isKindOfEi .text._ZN9StateBase8isKindOfEi .gnu.linkonce.d.rel.ro._ZN9StateBase8isKindOfEi .data.rel.ro._ZN9StateBase8isKindOfEi) }
    .base_1 0x002dacac : { *state-hooks-gscarrentalmenu.o(.gnu.linkonce.t._ZN9StateBase4drawEPK12StateMachine .text._ZN9StateBase4drawEPK12StateMachine .gnu.linkonce.d.rel.ro._ZN9StateBase4drawEPK12StateMachine .data.rel.ro._ZN9StateBase4drawEPK12StateMachine) }
    .base_2 0x002db4ec : { *state-hooks-gscarrentalmenu.o(.gnu.linkonce.t._ZN9StateBaseD0Ev .text._ZN9StateBaseD0Ev .gnu.linkonce.d.rel.ro._ZN9StateBaseD0Ev .data.rel.ro._ZN9StateBaseD0Ev) }
    .base_3 0x002daca4 : { *state-hooks-gscarrentalmenu.o(.gnu.linkonce.t._ZN9StateBase6resumeEPK12StateMachine .text._ZN9StateBase6resumeEPK12StateMachine .gnu.linkonce.d.rel.ro._ZN9StateBase6resumeEPK12StateMachine .data.rel.ro._ZN9StateBase6resumeEPK12StateMachine) }
    .base_4 0x002dacb8 : { *state-hooks-gscarrentalmenu.o(.gnu.linkonce.t._ZN9StateBase6wakeupEPK12StateMachine .text._ZN9StateBase6wakeupEPK12StateMachine .gnu.linkonce.d.rel.ro._ZN9StateBase6wakeupEPK12StateMachine .data.rel.ro._ZN9StateBase6wakeupEPK12StateMachine) }
    .base_5 0x002dacbc : { *state-hooks-gscarrentalmenu.o(.gnu.linkonce.t._ZN9StateBase10isDrawableEv .text._ZN9StateBase10isDrawableEv .gnu.linkonce.d.rel.ro._ZN9StateBase10isDrawableEv .data.rel.ro._ZN9StateBase10isDrawableEv) }
    .base_6 0x002dac9c : { *state-hooks-gscarrentalmenu.o(.gnu.linkonce.t._ZN9StateBase4dtorEPK12StateMachine .text._ZN9StateBase4dtorEPK12StateMachine .gnu.linkonce.d.rel.ro._ZN9StateBase4dtorEPK12StateMachine .data.rel.ro._ZN9StateBase4dtorEPK12StateMachine) }
    .base_7 0x002dacb4 : { *state-hooks-gscarrentalmenu.o(.gnu.linkonce.t._ZN9StateBase5sleepEPK12StateMachine .text._ZN9StateBase5sleepEPK12StateMachine .gnu.linkonce.d.rel.ro._ZN9StateBase5sleepEPK12StateMachine .data.rel.ro._ZN9StateBase5sleepEPK12StateMachine) }
    .base_8 0x002db50c : { *state-hooks-gscarrentalmenu.o(.gnu.linkonce.t._ZN9StateBaseD1Ev .text._ZN9StateBaseD1Ev .gnu.linkonce.d.rel.ro._ZN9StateBaseD1Ev .data.rel.ro._ZN9StateBaseD1Ev) }
    .base_9 0x002dacb0 : { *state-hooks-gscarrentalmenu.o(.gnu.linkonce.t._ZN9StateBase6draw2dEPK12StateMachine .text._ZN9StateBase6draw2dEPK12StateMachine .gnu.linkonce.d.rel.ro._ZN9StateBase6draw2dEPK12StateMachine .data.rel.ro._ZN9StateBase6draw2dEPK12StateMachine) }
    .base_10 0x002dac98 : { *state-hooks-gscarrentalmenu.o(.gnu.linkonce.t._ZN9StateBase4ctorEPK12StateMachine .text._ZN9StateBase4ctorEPK12StateMachine .gnu.linkonce.d.rel.ro._ZN9StateBase4ctorEPK12StateMachine .data.rel.ro._ZN9StateBase4ctorEPK12StateMachine) }
    .base_11 0x002daca0 : { *state-hooks-gscarrentalmenu.o(.gnu.linkonce.t._ZN9StateBase5pauseEPK12StateMachine .text._ZN9StateBase5pauseEPK12StateMachine .gnu.linkonce.d.rel.ro._ZN9StateBase5pauseEPK12StateMachine .data.rel.ro._ZN9StateBase5pauseEPK12StateMachine) }
    .base_12 0x002daca8 : { *state-hooks-gscarrentalmenu.o(.gnu.linkonce.t._ZN9StateBase6updateEP12StateMachine .text._ZN9StateBase6updateEP12StateMachine .gnu.linkonce.d.rel.ro._ZN9StateBase6updateEP12StateMachine .data.rel.ro._ZN9StateBase6updateEP12StateMachine) }
    .base_13 0x004a8b60 : { *state-hooks-gscarrentalmenu.o(.gnu.linkonce.t._ZTV9StateBase .text._ZTV9StateBase .gnu.linkonce.d.rel.ro._ZTV9StateBase .data.rel.ro._ZTV9StateBase) }
    .got 0x004b0048 : { *(.got.plt) . = 0x360; *(.got) }
    .verification 0x00600000 : { *retail-got.o(.text) }
    .state_destructor 0x002e1538 : { *state-hooks-gscarrentalmenu.o(.text._ZN15GSCarRentalMenuD1Ev) }
    .state_delete 0x002e150c : { *state-hooks-gscarrentalmenu.o(.text._ZN15GSCarRentalMenuD0Ev) }
    .state_vtable 0x004a8c20 : { *state-hooks-gscarrentalmenu.o(.data.rel.ro._ZTV15GSCarRentalMenu .gnu.linkonce.d.rel.ro._ZTV15GSCarRentalMenu) }
    .state_kind 0x002e12cc : { *state-hooks-gscarrentalmenu.o(.gnu.linkonce.t._ZN15GSCarRentalMenu8isKindOfEi .text._ZN15GSCarRentalMenu8isKindOfEi) }
    .entry_0 0x002e1328 : { *state-hooks-gscarrentalmenu.o(.text._ZN15GSCarRentalMenu4ctorEPK12StateMachine .gnu.linkonce.t._ZN15GSCarRentalMenu4ctorEPK12StateMachine) }
    .entry_text 0x00415844 : { *state-hooks-gscarrentalmenu.o(.rodata.str1.4 .rodata.str1.1) }
    .menu_exit 0x002e12fc : { *state-hooks-gscarrentalmenu.o(.text._ZN15GSCarRentalMenu4dtorEPK12StateMachine) }
    .hud_manager_helpers_0 0x003235a4 : { *hud-manager-helpers.o(.text._ZN11CHudManager4initEv .gnu.linkonce.t._ZN11CHudManager4initEv) }
    .hud_manager_helpers_1 0x003235e4 : { *hud-manager-helpers.o(.text._ZN11CHudManager4lockEv .gnu.linkonce.t._ZN11CHudManager4lockEv) }
    .hud_manager_helpers_2 0x003235ec : { *hud-manager-helpers.o(.text._ZN11CHudManager6unlockEv .gnu.linkonce.t._ZN11CHudManager6unlockEv) }
    .hud_manager_helpers_3 0x003235f4 : { *hud-manager-helpers.o(.text._ZNK11CHudManager8isLockedEv .gnu.linkonce.t._ZNK11CHudManager8isLockedEv) }
    .script_manager_helpers_0 0x0033cffc : { *script-manager-helpers.o(.text._ZN13ScriptManager6resumeEv .gnu.linkonce.t._ZN13ScriptManager6resumeEv) }
    .script_manager_helpers_1 0x0033d034 : { *script-manager-helpers.o(.text._ZN13ScriptManager20skipBlockingCommandsEv .gnu.linkonce.t._ZN13ScriptManager20skipBlockingCommandsEv) }
    .script_manager_helpers_2 0x0033d08c : { *script-manager-helpers.o(.text._ZNK13ScriptManager10getMissionEv .gnu.linkonce.t._ZNK13ScriptManager10getMissionEv) }
    .script_manager_helpers_3 0x0033d0a4 : { *script-manager-helpers.o(.text._ZNK13ScriptManager22getCinematicsHudSpriteEv .gnu.linkonce.t._ZNK13ScriptManager22getCinematicsHudSpriteEv) }
    .script_manager_helpers_4 0x0033d0a8 : { *script-manager-helpers.o(.text._ZNK13ScriptManager7getRaceEv .gnu.linkonce.t._ZNK13ScriptManager7getRaceEv) }
    .local_startup_function_0 0x002e1384 : { *state-hooks-gscarrentalmenu.o(.text._Z41__static_initialization_and_destruction_0ii) }
    .local_startup_function_1 0x002e14c8 : { *state-hooks-gscarrentalmenu.o(.text._GLOBAL__I__ZN15GSCarRentalMenuC2Ev) }
    .local_startup_function_2 0x002e14dc : { *state-hooks-gscarrentalmenu.o(.text.__tcf_4) }
    .local_startup_storage_0 0x004b6c48 (NOLOAD) : { *state-hooks-gscarrentalmenu.o(.bss._ZN3irr5scene6quake315irrEmptyStringcE) }
    .local_startup_storage_1 0x004b6c68 (NOLOAD) : { *state-hooks-gscarrentalmenu.o(.bss._ZN3irr2ps5vHalfE) }
    .local_startup_storage_2 0x004b6c74 (NOLOAD) : { *state-hooks-gscarrentalmenu.o(.bss._ZN8gameloft2ai11civ_passiveE) }
    .local_startup_storage_3 0x004b6c7c (NOLOAD) : { *state-hooks-gscarrentalmenu.o(.bss._ZN8gameloft2ai12npc_scriptedE) }
    .local_startup_storage_4 0x004b6c84 (NOLOAD) : { *state-hooks-gscarrentalmenu.o(.bss._ZN8gameloft2ai13civ_agressiveE) }
    .local_startup_storage_5 0x004b6c8c (NOLOAD) : { *state-hooks-gscarrentalmenu.o(.bss._ZN8gameloft2ai11gang_memberE) }
    .local_startup_storage_6 0x004b6c94 (NOLOAD) : { *state-hooks-gscarrentalmenu.o(.bss._ZN8gameloft2ai3copE) }
    .local_startup_storage_7 0x004b6c9c (NOLOAD) : { *state-hooks-gscarrentalmenu.o(.bss._ZN8gameloft2ai4swatE) }
    .local_startup_storage_8 0x004b6ca4 (NOLOAD) : { *state-hooks-gscarrentalmenu.o(.bss._ZN8gameloft2ai11civ_vehicleE) }
    .local_startup_storage_9 0x004b6cac (NOLOAD) : { *state-hooks-gscarrentalmenu.o(.bss._ZN8gameloft2ai11cop_vehicleE) }
    .local_startup_storage_10 0x004b6cb4 (NOLOAD) : { *state-hooks-gscarrentalmenu.o(.bss._ZN8gameloft2ai5guardE) }
    .local_startup_storage_11 0x004b6cbc (NOLOAD) : { *state-hooks-gscarrentalmenu.o(.bss._ZN8gameloft2ai16scripted_vehicleE) }

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

    .shared_startup_empty_text 0x0044d91c : { *(.gnu.linkonce.r.localStartupEmptyText) }
}
ASSERT(SIZEOF(.local_startup_storage_0) == 32, "_ZN3irr5scene6quake315irrEmptyStringcE extent");
ASSERT(SIZEOF(.local_startup_storage_1) == 12, "_ZN3irr2ps5vHalfE extent");
ASSERT(SIZEOF(.local_startup_storage_2) == 8, "_ZN8gameloft2ai11civ_passiveE extent");
ASSERT(SIZEOF(.local_startup_storage_3) == 8, "_ZN8gameloft2ai12npc_scriptedE extent");
ASSERT(SIZEOF(.local_startup_storage_4) == 8, "_ZN8gameloft2ai13civ_agressiveE extent");
ASSERT(SIZEOF(.local_startup_storage_5) == 8, "_ZN8gameloft2ai11gang_memberE extent");
ASSERT(SIZEOF(.local_startup_storage_6) == 8, "_ZN8gameloft2ai3copE extent");
ASSERT(SIZEOF(.local_startup_storage_7) == 8, "_ZN8gameloft2ai4swatE extent");
ASSERT(SIZEOF(.local_startup_storage_8) == 8, "_ZN8gameloft2ai11civ_vehicleE extent");
ASSERT(SIZEOF(.local_startup_storage_9) == 8, "_ZN8gameloft2ai11cop_vehicleE extent");
ASSERT(SIZEOF(.local_startup_storage_10) == 8, "_ZN8gameloft2ai5guardE extent");
ASSERT(SIZEOF(.local_startup_storage_11) == 8, "_ZN8gameloft2ai16scripted_vehicleE extent");
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
