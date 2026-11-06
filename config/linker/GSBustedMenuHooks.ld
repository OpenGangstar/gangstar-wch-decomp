OUTPUT_FORMAT("elf32-littlearm")
OUTPUT_ARCH(arm)
INCLUDE build/matches/state-hooks-gsbustedmenu/retail-symbols.ld
_ZdlPv = 0x001c42b0;
__cxa_guard_acquire = 0x001c4958;
__cxa_guard_release = 0x001c46c4;
__aeabi_atexit = 0x001c494c;
_ZN31retail_gsbustedmenu_transitions16civPassive_transE = 0x00415274;
_ZN31retail_gsbustedmenu_transitions17scriptedNpc_transE = 0x004153a0;
_ZN31retail_gsbustedmenu_transitions19civAggressive_transE = 0x004153d0;
_ZN31retail_gsbustedmenu_transitions16gangMember_transE = 0x004154b4;
_ZN31retail_gsbustedmenu_transitions9cop_transE = 0x004154c0;
_ZN31retail_gsbustedmenu_transitions10swat_transE = 0x004155f8;
_ZN31retail_gsbustedmenu_transitions17civ_vehicle_transE = 0x00415604;
_ZN31retail_gsbustedmenu_transitions17cop_vehicle_transE = 0x00415694;
_ZN31retail_gsbustedmenu_transitions11guard_transE = 0x00415748;
_ZN31retail_gsbustedmenu_transitions22scripted_vehicle_transE = 0x004157f0;
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
_ZN30retail_menumanager_transitions16civPassive_transE = 0x00419250;
_ZN30retail_menumanager_transitions17scriptedNpc_transE = 0x0041937c;
_ZN30retail_menumanager_transitions19civAggressive_transE = 0x004193ac;
_ZN30retail_menumanager_transitions16gangMember_transE = 0x00419490;
_ZN30retail_menumanager_transitions9cop_transE = 0x0041949c;
_ZN30retail_menumanager_transitions10swat_transE = 0x004195d4;
_ZN30retail_menumanager_transitions17civ_vehicle_transE = 0x004195e0;
_ZN30retail_menumanager_transitions17cop_vehicle_transE = 0x00419670;
_ZN30retail_menumanager_transitions11guard_transE = 0x00419724;
_ZN30retail_menumanager_transitions22scripted_vehicle_transE = 0x004197cc;
INCLUDE config/linker/CHudManagerSpySections.ld
INCLUDE config/linker/CHudManagerWalkingSections.ld
INCLUDE config/linker/ScriptManagerQuerySections.ld
SECTIONS
{
    .wanted_singleton 0x002dba04 : { *script-manager-helpers.o(.gnu.linkonce.t._ZN18WantedLevelManager11getInstanceEv) }
    .wanted_cleanup 0x0033d3b4 : { *script-manager-helpers.o(.text.__tcf_1) }
    .wanted_guard 0x004b6728 (NOLOAD) : { *script-manager-helpers.o(.gnu.linkonce.b._ZGVZN18WantedLevelManager11getInstanceEvE3wlm) }
    .wanted_instance 0x004b6a98 (NOLOAD) : { *script-manager-helpers.o(.gnu.linkonce.b._ZZN18WantedLevelManager11getInstanceEvE3wlm) }
    .map_singleton 0x002dbb58 : { *menu-manager-helpers.o(.gnu.linkonce.t._ZN3Map11getInstanceEv) }
    .map_cleanup 0x002e425c : { *menu-manager-helpers.o(.text.__tcf_0) }
    .map_guard 0x004b6a94 (NOLOAD) : { *menu-manager-helpers.o(.gnu.linkonce.b._ZGVZN3Map11getInstanceEvE3map) }
    .map_instance 0x004b6b00 (NOLOAD) : { *menu-manager-helpers.o(.gnu.linkonce.b._ZZN3Map11getInstanceEvE3map) }
    .hook_0 0x002e0f3c : { *state-hooks-gsbustedmenu.o(.text._ZN12GSBustedMenu4drawEPK12StateMachine .gnu.linkonce.t._ZN12GSBustedMenu4drawEPK12StateMachine) }
    .hook_1 0x002e0f40 : { *state-hooks-gsbustedmenu.o(.text._ZN12GSBustedMenu6draw2dEPK12StateMachine .gnu.linkonce.t._ZN12GSBustedMenu6draw2dEPK12StateMachine) }
    .state_ctor 0x002e1030 : { *state-hooks-gsbustedmenu.o(.text._ZN12GSBustedMenuC1Ev) }
    .base_0 0x002dacc0 : { *state-hooks-gsbustedmenu.o(.gnu.linkonce.t._ZN9StateBase8isKindOfEi .text._ZN9StateBase8isKindOfEi .gnu.linkonce.d.rel.ro._ZN9StateBase8isKindOfEi .data.rel.ro._ZN9StateBase8isKindOfEi) }
    .base_1 0x002dacac : { *state-hooks-gsbustedmenu.o(.gnu.linkonce.t._ZN9StateBase4drawEPK12StateMachine .text._ZN9StateBase4drawEPK12StateMachine .gnu.linkonce.d.rel.ro._ZN9StateBase4drawEPK12StateMachine .data.rel.ro._ZN9StateBase4drawEPK12StateMachine) }
    .base_2 0x002db4ec : { *state-hooks-gsbustedmenu.o(.gnu.linkonce.t._ZN9StateBaseD0Ev .text._ZN9StateBaseD0Ev .gnu.linkonce.d.rel.ro._ZN9StateBaseD0Ev .data.rel.ro._ZN9StateBaseD0Ev) }
    .base_3 0x002daca4 : { *state-hooks-gsbustedmenu.o(.gnu.linkonce.t._ZN9StateBase6resumeEPK12StateMachine .text._ZN9StateBase6resumeEPK12StateMachine .gnu.linkonce.d.rel.ro._ZN9StateBase6resumeEPK12StateMachine .data.rel.ro._ZN9StateBase6resumeEPK12StateMachine) }
    .base_4 0x002dacb8 : { *state-hooks-gsbustedmenu.o(.gnu.linkonce.t._ZN9StateBase6wakeupEPK12StateMachine .text._ZN9StateBase6wakeupEPK12StateMachine .gnu.linkonce.d.rel.ro._ZN9StateBase6wakeupEPK12StateMachine .data.rel.ro._ZN9StateBase6wakeupEPK12StateMachine) }
    .base_5 0x002dacbc : { *state-hooks-gsbustedmenu.o(.gnu.linkonce.t._ZN9StateBase10isDrawableEv .text._ZN9StateBase10isDrawableEv .gnu.linkonce.d.rel.ro._ZN9StateBase10isDrawableEv .data.rel.ro._ZN9StateBase10isDrawableEv) }
    .base_6 0x002dac9c : { *state-hooks-gsbustedmenu.o(.gnu.linkonce.t._ZN9StateBase4dtorEPK12StateMachine .text._ZN9StateBase4dtorEPK12StateMachine .gnu.linkonce.d.rel.ro._ZN9StateBase4dtorEPK12StateMachine .data.rel.ro._ZN9StateBase4dtorEPK12StateMachine) }
    .base_7 0x002dacb4 : { *state-hooks-gsbustedmenu.o(.gnu.linkonce.t._ZN9StateBase5sleepEPK12StateMachine .text._ZN9StateBase5sleepEPK12StateMachine .gnu.linkonce.d.rel.ro._ZN9StateBase5sleepEPK12StateMachine .data.rel.ro._ZN9StateBase5sleepEPK12StateMachine) }
    .base_8 0x002db50c : { *state-hooks-gsbustedmenu.o(.gnu.linkonce.t._ZN9StateBaseD1Ev .text._ZN9StateBaseD1Ev .gnu.linkonce.d.rel.ro._ZN9StateBaseD1Ev .data.rel.ro._ZN9StateBaseD1Ev) }
    .base_9 0x002dacb0 : { *state-hooks-gsbustedmenu.o(.gnu.linkonce.t._ZN9StateBase6draw2dEPK12StateMachine .text._ZN9StateBase6draw2dEPK12StateMachine .gnu.linkonce.d.rel.ro._ZN9StateBase6draw2dEPK12StateMachine .data.rel.ro._ZN9StateBase6draw2dEPK12StateMachine) }
    .base_10 0x002dac98 : { *state-hooks-gsbustedmenu.o(.gnu.linkonce.t._ZN9StateBase4ctorEPK12StateMachine .text._ZN9StateBase4ctorEPK12StateMachine .gnu.linkonce.d.rel.ro._ZN9StateBase4ctorEPK12StateMachine .data.rel.ro._ZN9StateBase4ctorEPK12StateMachine) }
    .base_11 0x002daca0 : { *state-hooks-gsbustedmenu.o(.gnu.linkonce.t._ZN9StateBase5pauseEPK12StateMachine .text._ZN9StateBase5pauseEPK12StateMachine .gnu.linkonce.d.rel.ro._ZN9StateBase5pauseEPK12StateMachine .data.rel.ro._ZN9StateBase5pauseEPK12StateMachine) }
    .base_12 0x002daca8 : { *state-hooks-gsbustedmenu.o(.gnu.linkonce.t._ZN9StateBase6updateEP12StateMachine .text._ZN9StateBase6updateEP12StateMachine .gnu.linkonce.d.rel.ro._ZN9StateBase6updateEP12StateMachine .data.rel.ro._ZN9StateBase6updateEP12StateMachine) }
    .base_13 0x004a8b60 : { *state-hooks-gsbustedmenu.o(.gnu.linkonce.t._ZTV9StateBase .text._ZTV9StateBase .gnu.linkonce.d.rel.ro._ZTV9StateBase .data.rel.ro._ZTV9StateBase) }
    .got 0x004b0048 : { *(.got.plt) . = 0x360; *(.got) }
    .verification 0x00600000 : { *retail-got.o(.text) }
    .state_destructor 0x002e12a8 : { *state-hooks-gsbustedmenu.o(.text._ZN12GSBustedMenuD1Ev) }
    .state_delete 0x002e127c : { *state-hooks-gsbustedmenu.o(.text._ZN12GSBustedMenuD0Ev) }
    .state_vtable 0x004a8be0 : { *state-hooks-gsbustedmenu.o(.data.rel.ro._ZTV12GSBustedMenu .gnu.linkonce.d.rel.ro._ZTV12GSBustedMenu) }
    .state_kind 0x002e0f2c : { *state-hooks-gsbustedmenu.o(.gnu.linkonce.t._ZN12GSBustedMenu8isKindOfEi .text._ZN12GSBustedMenu8isKindOfEi) }
    .cleanup_hook 0x002e0f90 : { *state-hooks-gsbustedmenu.o(.text._ZN12GSBustedMenu4dtorEPK12StateMachine) }
    .hud_manager_helpers_0 0x003235a4 : { *hud-manager-helpers.o(.text._ZN11CHudManager4initEv .gnu.linkonce.t._ZN11CHudManager4initEv) }
    .hud_manager_helpers_1 0x003235e4 : { *hud-manager-helpers.o(.text._ZN11CHudManager4lockEv .gnu.linkonce.t._ZN11CHudManager4lockEv) }
    .hud_manager_helpers_2 0x003235ec : { *hud-manager-helpers.o(.text._ZN11CHudManager6unlockEv .gnu.linkonce.t._ZN11CHudManager6unlockEv) }
    .hud_manager_helpers_3 0x003235f4 : { *hud-manager-helpers.o(.text._ZNK11CHudManager8isLockedEv .gnu.linkonce.t._ZNK11CHudManager8isLockedEv) }
    .script_manager_helpers_0 0x0033cffc : { *script-manager-helpers.o(.text._ZN13ScriptManager6resumeEv .gnu.linkonce.t._ZN13ScriptManager6resumeEv) }
    .script_manager_helpers_1 0x0033d034 : { *script-manager-helpers.o(.text._ZN13ScriptManager20skipBlockingCommandsEv .gnu.linkonce.t._ZN13ScriptManager20skipBlockingCommandsEv) }
    .script_manager_helpers_2 0x0033d08c : { *script-manager-helpers.o(.text._ZNK13ScriptManager10getMissionEv .gnu.linkonce.t._ZNK13ScriptManager10getMissionEv) }
    .script_manager_helpers_3 0x0033d0a4 : { *script-manager-helpers.o(.text._ZNK13ScriptManager22getCinematicsHudSpriteEv .gnu.linkonce.t._ZNK13ScriptManager22getCinematicsHudSpriteEv) }
    .script_manager_helpers_4 0x0033d0a8 : { *script-manager-helpers.o(.text._ZNK13ScriptManager7getRaceEv .gnu.linkonce.t._ZNK13ScriptManager7getRaceEv) }
    .entry_0 0x002e0fb4 : { *state-hooks-gsbustedmenu.o(.text._ZN12GSBustedMenu4ctorEPK12StateMachine) }
    .entry_text 0x00415268 : { *state-hooks-gsbustedmenu.o(.rodata.str1.4 .rodata.str1.1) }
    .menu_manager_helpers_0 0x002e3e7c : { *menu-manager-helpers.o(.text._ZN11MenuManager21resetWidgetVisibilityEv .gnu.linkonce.t._ZN11MenuManager21resetWidgetVisibilityEv) }
    .menu_manager_helpers_1 0x002e3e84 : { *menu-manager-helpers.o(.text._ZN11MenuManager9MenuPauseEv .gnu.linkonce.t._ZN11MenuManager9MenuPauseEv) }
    .menu_manager_helpers_2 0x002e3e88 : { *menu-manager-helpers.o(.text._ZN11MenuManager10MenuResumeEv .gnu.linkonce.t._ZN11MenuManager10MenuResumeEv) }
    .menu_manager_helpers_3 0x002e3e8c : { *menu-manager-helpers.o(.text._ZN11MenuManager14setTutorialIdsEii .gnu.linkonce.t._ZN11MenuManager14setTutorialIdsEii) }
    .menu_manager_helpers_4 0x002e3eb4 : { *menu-manager-helpers.o(.text._ZN11MenuManager13setRepairCostEi .gnu.linkonce.t._ZN11MenuManager13setRepairCostEi) }
    .menu_manager_helpers_5 0x002e3eb8 : { *menu-manager-helpers.o(.text._ZNK11MenuManager13getRepairCostEv .gnu.linkonce.t._ZNK11MenuManager13getRepairCostEv) }
    .menu_manager_helpers_6 0x002e3ebc : { *menu-manager-helpers.o(.text._ZNK11MenuManager17areCheatsUnlockedEv .gnu.linkonce.t._ZNK11MenuManager17areCheatsUnlockedEv) }
    .menu_manager_helpers_7 0x002e3ee4 : { *menu-manager-helpers.o(.text._ZNK11MenuManager21isCheatsUnlockAllowedEv .gnu.linkonce.t._ZNK11MenuManager21isCheatsUnlockAllowedEv) }
    .menu_manager_helpers_8 0x002e3f04 : { *menu-manager-helpers.o(.text._ZNK11MenuManager15isClearingFocusEv .gnu.linkonce.t._ZNK11MenuManager15isClearingFocusEv) }
    .menu_manager_helpers_9 0x002e3f0c : { *menu-manager-helpers.o(.text._ZN11MenuManager9getMenuFXEv .gnu.linkonce.t._ZN11MenuManager9getMenuFXEv) }
    .menu_manager_helpers_10 0x002e3f14 : { *menu-manager-helpers.o(.text._ZNK11MenuManager12isInGameMenuEv .gnu.linkonce.t._ZNK11MenuManager12isInGameMenuEv) }
    .menu_manager_helpers_11 0x002e3f18 : { *menu-manager-helpers.o(.text._ZNK11MenuManager15consumedCursorsEv .gnu.linkonce.t._ZNK11MenuManager15consumedCursorsEv) }
    .menu_manager_helpers_12 0x002e3f20 : { *menu-manager-helpers.o(.text._ZN11MenuManager13consumeCursorEv .gnu.linkonce.t._ZN11MenuManager13consumeCursorEv) }
    .menu_manager_helpers_13 0x002e3f2c : { *menu-manager-helpers.o(.text._ZN11MenuManager19getCharAutoLineFeedEv .gnu.linkonce.t._ZN11MenuManager19getCharAutoLineFeedEv) }
    .menu_manager_helpers_14 0x002e3f78 : { *menu-manager-helpers.o(.text._ZN11MenuManager11enableAnimsEb .gnu.linkonce.t._ZN11MenuManager11enableAnimsEb) }
    .menu_manager_helpers_15 0x002e3f84 : { *menu-manager-helpers.o(.text._ZNK11MenuManager15areAnimsEnabledEv .gnu.linkonce.t._ZNK11MenuManager15areAnimsEnabledEv) }
    .menu_manager_helpers_16 0x002e465c : { *menu-manager-helpers.o(.text._ZNK11MenuManager8getDepthEv .gnu.linkonce.t._ZNK11MenuManager8getDepthEv) }
    .menu_manager_helpers_17 0x002e65d0 : { *menu-manager-helpers.o(.text._ZNK11MenuManager10getMapModeEv .gnu.linkonce.t._ZNK11MenuManager10getMapModeEv) }
    .busted_update 0x002e11a4 : { *state-hooks-gsbustedmenu.o(.text._ZN12GSBustedMenu6updateEP12StateMachine) }
    .state_instance 0x002d44c4 : { *state-hooks-gsbustedmenu.o(.gnu.linkonce.t._ZN12StateMachine11getInstanceEv .text._ZN12StateMachine11getInstanceEv) }
    .state_instance_cleanup 0x002d4518 : { *state-hooks-gsbustedmenu.o(.text.__tcf_0) }
    .state_instance_guard 0x004b6904 (NOLOAD) : { *state-hooks-gsbustedmenu.o(.gnu.linkonce.b._ZGVZN12StateMachine11getInstanceEvE2sm .bss._ZGVZN12StateMachine11getInstanceEvE2sm) }
    .state_instance_storage 0x004b6908 (NOLOAD) : { *state-hooks-gsbustedmenu.o(.gnu.linkonce.b._ZZN12StateMachine11getInstanceEvE2sm .bss._ZZN12StateMachine11getInstanceEvE2sm) }
    .local_startup_function_0 0x002e104c : { *state-hooks-gsbustedmenu.o(.text._Z41__static_initialization_and_destruction_0ii) }
    .local_startup_function_1 0x002e1190 : { *state-hooks-gsbustedmenu.o(.text._GLOBAL__I__ZN12GSBustedMenuC2Ev) }
    .local_startup_function_2 0x002e0f44 : { *state-hooks-gsbustedmenu.o(.text.__tcf_4) }
    .local_startup_function_3 0x002e0f74 : { *state-hooks-gsbustedmenu.o(.text.__tcf_3) }
    .local_startup_storage_0 0x004b6bcc (NOLOAD) : { *state-hooks-gsbustedmenu.o(.bss._ZN3irr5scene6quake315irrEmptyStringcE) }
    .local_startup_storage_1 0x004b6bec (NOLOAD) : { *state-hooks-gsbustedmenu.o(.bss._ZN3irr2ps5vHalfE) }
    .local_startup_storage_2 0x004b6bf8 (NOLOAD) : { *state-hooks-gsbustedmenu.o(.bss._ZN8gameloft2ai11civ_passiveE) }
    .local_startup_storage_3 0x004b6c00 (NOLOAD) : { *state-hooks-gsbustedmenu.o(.bss._ZN8gameloft2ai12npc_scriptedE) }
    .local_startup_storage_4 0x004b6c08 (NOLOAD) : { *state-hooks-gsbustedmenu.o(.bss._ZN8gameloft2ai13civ_agressiveE) }
    .local_startup_storage_5 0x004b6c10 (NOLOAD) : { *state-hooks-gsbustedmenu.o(.bss._ZN8gameloft2ai11gang_memberE) }
    .local_startup_storage_6 0x004b6c18 (NOLOAD) : { *state-hooks-gsbustedmenu.o(.bss._ZN8gameloft2ai3copE) }
    .local_startup_storage_7 0x004b6c20 (NOLOAD) : { *state-hooks-gsbustedmenu.o(.bss._ZN8gameloft2ai4swatE) }
    .local_startup_storage_8 0x004b6c28 (NOLOAD) : { *state-hooks-gsbustedmenu.o(.bss._ZN8gameloft2ai11civ_vehicleE) }
    .local_startup_storage_9 0x004b6c30 (NOLOAD) : { *state-hooks-gsbustedmenu.o(.bss._ZN8gameloft2ai11cop_vehicleE) }
    .local_startup_storage_10 0x004b6c38 (NOLOAD) : { *state-hooks-gsbustedmenu.o(.bss._ZN8gameloft2ai5guardE) }
    .local_startup_storage_11 0x004b6c40 (NOLOAD) : { *state-hooks-gsbustedmenu.o(.bss._ZN8gameloft2ai16scripted_vehicleE) }

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
    .menu_startup_function_0 0x002e4cc4 : { *menu-manager-helpers.o(.text.__tcf_8) }
    .menu_startup_function_1 0x002e4aa8 : { *menu-manager-helpers.o(.text._Z41__static_initialization_and_destruction_0ii) }
    .menu_startup_function_2 0x002e4c44 : { *menu-manager-helpers.o(.text._GLOBAL__I__Z16SwfTextureLoaderPKcii) }
    .menu_startup_function_3 0x002e3fe8 : { *menu-manager-helpers.o(.text.__tcf_9) }
    .menu_startup_storage_0 0x004b7210 (NOLOAD) : { *menu-manager-helpers.o(.bss.s_textures) }
    .menu_startup_storage_1 0x004b7194 (NOLOAD) : { *menu-manager-helpers.o(.bss._ZN3irr5scene6quake315irrEmptyStringcE) }
    .menu_startup_storage_2 0x004b71b4 (NOLOAD) : { *menu-manager-helpers.o(.bss._ZN3irr2ps5vHalfE) }
    .menu_startup_storage_3 0x004b71c0 (NOLOAD) : { *menu-manager-helpers.o(.bss._ZN8gameloft2ai11civ_passiveE) }
    .menu_startup_storage_4 0x004b71c8 (NOLOAD) : { *menu-manager-helpers.o(.bss._ZN8gameloft2ai12npc_scriptedE) }
    .menu_startup_storage_5 0x004b71d0 (NOLOAD) : { *menu-manager-helpers.o(.bss._ZN8gameloft2ai13civ_agressiveE) }
    .menu_startup_storage_6 0x004b71d8 (NOLOAD) : { *menu-manager-helpers.o(.bss._ZN8gameloft2ai11gang_memberE) }
    .menu_startup_storage_7 0x004b71e0 (NOLOAD) : { *menu-manager-helpers.o(.bss._ZN8gameloft2ai3copE) }
    .menu_startup_storage_8 0x004b71e8 (NOLOAD) : { *menu-manager-helpers.o(.bss._ZN8gameloft2ai4swatE) }
    .menu_startup_storage_9 0x004b71f0 (NOLOAD) : { *menu-manager-helpers.o(.bss._ZN8gameloft2ai11civ_vehicleE) }
    .menu_startup_storage_10 0x004b71f8 (NOLOAD) : { *menu-manager-helpers.o(.bss._ZN8gameloft2ai11cop_vehicleE) }
    .menu_startup_storage_11 0x004b7200 (NOLOAD) : { *menu-manager-helpers.o(.bss._ZN8gameloft2ai5guardE) }
    .menu_startup_storage_12 0x004b7208 (NOLOAD) : { *menu-manager-helpers.o(.bss._ZN8gameloft2ai16scripted_vehicleE) }
    .menu_startup_storage_13 0x004b7170 (NOLOAD) : { *menu-manager-helpers.o(.bss._ZN11MenuManager22s_cheatActivationZonesE) }
}
ASSERT(SIZEOF(.state_instance_guard) == 4, "StateMachine instance guard extent");
ASSERT(SIZEOF(.state_instance_storage) == 40, "StateMachine instance storage extent");
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
ASSERT(SIZEOF(.menu_startup_storage_0) == 12, "MenuManager s_textures extent");
ASSERT(SIZEOF(.menu_startup_storage_1) == 32, "MenuManager _ZN3irr5scene6quake315irrEmptyStringcE extent");
ASSERT(SIZEOF(.menu_startup_storage_2) == 12, "MenuManager _ZN3irr2ps5vHalfE extent");
ASSERT(SIZEOF(.menu_startup_storage_3) == 8, "MenuManager _ZN8gameloft2ai11civ_passiveE extent");
ASSERT(SIZEOF(.menu_startup_storage_4) == 8, "MenuManager _ZN8gameloft2ai12npc_scriptedE extent");
ASSERT(SIZEOF(.menu_startup_storage_5) == 8, "MenuManager _ZN8gameloft2ai13civ_agressiveE extent");
ASSERT(SIZEOF(.menu_startup_storage_6) == 8, "MenuManager _ZN8gameloft2ai11gang_memberE extent");
ASSERT(SIZEOF(.menu_startup_storage_7) == 8, "MenuManager _ZN8gameloft2ai3copE extent");
ASSERT(SIZEOF(.menu_startup_storage_8) == 8, "MenuManager _ZN8gameloft2ai4swatE extent");
ASSERT(SIZEOF(.menu_startup_storage_9) == 8, "MenuManager _ZN8gameloft2ai11civ_vehicleE extent");
ASSERT(SIZEOF(.menu_startup_storage_10) == 8, "MenuManager _ZN8gameloft2ai11cop_vehicleE extent");
ASSERT(SIZEOF(.menu_startup_storage_11) == 8, "MenuManager _ZN8gameloft2ai5guardE extent");
ASSERT(SIZEOF(.menu_startup_storage_12) == 8, "MenuManager _ZN8gameloft2ai16scripted_vehicleE extent");
ASSERT(SIZEOF(.menu_startup_storage_13) == 32, "MenuManager _ZN11MenuManager22s_cheatActivationZonesE extent");
