OUTPUT_FORMAT("elf32-littlearm")
OUTPUT_ARCH(arm)
INCLUDE build/matches/state-hooks-gsmainmenu/retail-symbols.ld
_ZdlPv = 0x001c42b0;
_ZN29retail_gsmainmenu_transitions16civPassive_transE = 0x00417b5c;
_ZN29retail_gsmainmenu_transitions17scriptedNpc_transE = 0x00417c88;
_ZN29retail_gsmainmenu_transitions19civAggressive_transE = 0x00417cb8;
_ZN29retail_gsmainmenu_transitions16gangMember_transE = 0x00417d9c;
_ZN29retail_gsmainmenu_transitions9cop_transE = 0x00417da8;
_ZN29retail_gsmainmenu_transitions10swat_transE = 0x00417ee0;
_ZN29retail_gsmainmenu_transitions17civ_vehicle_transE = 0x00417eec;
_ZN29retail_gsmainmenu_transitions17cop_vehicle_transE = 0x00417f7c;
_ZN29retail_gsmainmenu_transitions11guard_transE = 0x00418030;
_ZN29retail_gsmainmenu_transitions22scripted_vehicle_transE = 0x004180d8;
__aeabi_atexit = 0x001c494c;
__cxa_guard_acquire = 0x001c4958;
__cxa_guard_release = 0x001c46c4;
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
SECTIONS
{
    .map_singleton 0x002dbb58 : { *menu-manager-helpers.o(.gnu.linkonce.t._ZN3Map11getInstanceEv) }
    .map_cleanup 0x002e425c : { *menu-manager-helpers.o(.text.__tcf_0) }
    .map_guard 0x004b6a94 (NOLOAD) : { *menu-manager-helpers.o(.gnu.linkonce.b._ZGVZN3Map11getInstanceEvE3map) }
    .map_instance 0x004b6b00 (NOLOAD) : { *menu-manager-helpers.o(.gnu.linkonce.b._ZZN3Map11getInstanceEvE3map) }
    .hook_0 0x002e2fa0 : { *state-hooks-gsmainmenu.o(.text._ZN10GSMainMenu4drawEPK12StateMachine .gnu.linkonce.t._ZN10GSMainMenu4drawEPK12StateMachine) }
    .hook_1 0x002e2fa4 : { *state-hooks-gsmainmenu.o(.text._ZN10GSMainMenu6draw2dEPK12StateMachine .gnu.linkonce.t._ZN10GSMainMenu6draw2dEPK12StateMachine) }
    .state_ctor 0x002e3044 : { *state-hooks-gsmainmenu.o(.text._ZN10GSMainMenuC1Ev) }
    .base_0 0x002dacc0 : { *state-hooks-gsmainmenu.o(.gnu.linkonce.t._ZN9StateBase8isKindOfEi .text._ZN9StateBase8isKindOfEi .gnu.linkonce.d.rel.ro._ZN9StateBase8isKindOfEi .data.rel.ro._ZN9StateBase8isKindOfEi) }
    .base_1 0x002dacac : { *state-hooks-gsmainmenu.o(.gnu.linkonce.t._ZN9StateBase4drawEPK12StateMachine .text._ZN9StateBase4drawEPK12StateMachine .gnu.linkonce.d.rel.ro._ZN9StateBase4drawEPK12StateMachine .data.rel.ro._ZN9StateBase4drawEPK12StateMachine) }
    .base_2 0x002db4ec : { *state-hooks-gsmainmenu.o(.gnu.linkonce.t._ZN9StateBaseD0Ev .text._ZN9StateBaseD0Ev .gnu.linkonce.d.rel.ro._ZN9StateBaseD0Ev .data.rel.ro._ZN9StateBaseD0Ev) }
    .base_3 0x002daca4 : { *state-hooks-gsmainmenu.o(.gnu.linkonce.t._ZN9StateBase6resumeEPK12StateMachine .text._ZN9StateBase6resumeEPK12StateMachine .gnu.linkonce.d.rel.ro._ZN9StateBase6resumeEPK12StateMachine .data.rel.ro._ZN9StateBase6resumeEPK12StateMachine) }
    .base_4 0x002dacb8 : { *state-hooks-gsmainmenu.o(.gnu.linkonce.t._ZN9StateBase6wakeupEPK12StateMachine .text._ZN9StateBase6wakeupEPK12StateMachine .gnu.linkonce.d.rel.ro._ZN9StateBase6wakeupEPK12StateMachine .data.rel.ro._ZN9StateBase6wakeupEPK12StateMachine) }
    .base_5 0x002dacbc : { *state-hooks-gsmainmenu.o(.gnu.linkonce.t._ZN9StateBase10isDrawableEv .text._ZN9StateBase10isDrawableEv .gnu.linkonce.d.rel.ro._ZN9StateBase10isDrawableEv .data.rel.ro._ZN9StateBase10isDrawableEv) }
    .base_6 0x002dac9c : { *state-hooks-gsmainmenu.o(.gnu.linkonce.t._ZN9StateBase4dtorEPK12StateMachine .text._ZN9StateBase4dtorEPK12StateMachine .gnu.linkonce.d.rel.ro._ZN9StateBase4dtorEPK12StateMachine .data.rel.ro._ZN9StateBase4dtorEPK12StateMachine) }
    .base_7 0x002dacb4 : { *state-hooks-gsmainmenu.o(.gnu.linkonce.t._ZN9StateBase5sleepEPK12StateMachine .text._ZN9StateBase5sleepEPK12StateMachine .gnu.linkonce.d.rel.ro._ZN9StateBase5sleepEPK12StateMachine .data.rel.ro._ZN9StateBase5sleepEPK12StateMachine) }
    .base_8 0x002db50c : { *state-hooks-gsmainmenu.o(.gnu.linkonce.t._ZN9StateBaseD1Ev .text._ZN9StateBaseD1Ev .gnu.linkonce.d.rel.ro._ZN9StateBaseD1Ev .data.rel.ro._ZN9StateBaseD1Ev) }
    .base_9 0x002dacb0 : { *state-hooks-gsmainmenu.o(.gnu.linkonce.t._ZN9StateBase6draw2dEPK12StateMachine .text._ZN9StateBase6draw2dEPK12StateMachine .gnu.linkonce.d.rel.ro._ZN9StateBase6draw2dEPK12StateMachine .data.rel.ro._ZN9StateBase6draw2dEPK12StateMachine) }
    .base_10 0x002dac98 : { *state-hooks-gsmainmenu.o(.gnu.linkonce.t._ZN9StateBase4ctorEPK12StateMachine .text._ZN9StateBase4ctorEPK12StateMachine .gnu.linkonce.d.rel.ro._ZN9StateBase4ctorEPK12StateMachine .data.rel.ro._ZN9StateBase4ctorEPK12StateMachine) }
    .base_11 0x002daca0 : { *state-hooks-gsmainmenu.o(.gnu.linkonce.t._ZN9StateBase5pauseEPK12StateMachine .text._ZN9StateBase5pauseEPK12StateMachine .gnu.linkonce.d.rel.ro._ZN9StateBase5pauseEPK12StateMachine .data.rel.ro._ZN9StateBase5pauseEPK12StateMachine) }
    .base_12 0x002daca8 : { *state-hooks-gsmainmenu.o(.gnu.linkonce.t._ZN9StateBase6updateEP12StateMachine .text._ZN9StateBase6updateEP12StateMachine .gnu.linkonce.d.rel.ro._ZN9StateBase6updateEP12StateMachine .data.rel.ro._ZN9StateBase6updateEP12StateMachine) }
    .base_13 0x004a8b60 : { *state-hooks-gsmainmenu.o(.gnu.linkonce.t._ZTV9StateBase .text._ZTV9StateBase .gnu.linkonce.d.rel.ro._ZTV9StateBase .data.rel.ro._ZTV9StateBase) }
    .got 0x004b0048 : { *(.got.plt) . = 0x360; *(.got) }
    .verification 0x00600000 : { *retail-got.o(.text) }
    .state_destructor 0x002e3218 : { *state-hooks-gsmainmenu.o(.text._ZN10GSMainMenuD1Ev) }
    .state_delete 0x002e31ec : { *state-hooks-gsmainmenu.o(.text._ZN10GSMainMenuD0Ev) }
    .state_vtable 0x004a8de0 : { *state-hooks-gsmainmenu.o(.data.rel.ro._ZTV10GSMainMenu .gnu.linkonce.d.rel.ro._ZTV10GSMainMenu) }
    .state_kind 0x002e2f90 : { *state-hooks-gsmainmenu.o(.gnu.linkonce.t._ZN10GSMainMenu8isKindOfEi .text._ZN10GSMainMenu8isKindOfEi) }
    .entry_0 0x002e2ff4 : { *state-hooks-gsmainmenu.o(.text._ZN10GSMainMenu4ctorEPK12StateMachine .gnu.linkonce.t._ZN10GSMainMenu4ctorEPK12StateMachine) }
    .entry_1 0x002e2fa8 : { *state-hooks-gsmainmenu.o(.text._ZN10GSMainMenu6updateEP12StateMachine .gnu.linkonce.t._ZN10GSMainMenu6updateEP12StateMachine) }
    .entry_text 0x00413c7c : { *state-hooks-gsmainmenu.o(.rodata.str1.4 .rodata.str1.1) }
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
    .menu_exit 0x002e2fc8 : { *state-hooks-gsmainmenu.o(.text._ZN10GSMainMenu4dtorEPK12StateMachine) }
    .local_startup_function_0 0x002e3064 : { *state-hooks-gsmainmenu.o(.text._Z41__static_initialization_and_destruction_0ii) }
    .local_startup_function_1 0x002e31a8 : { *state-hooks-gsmainmenu.o(.text._GLOBAL__I__ZN10GSMainMenuC2Ev) }
    .local_startup_function_2 0x002e31bc : { *state-hooks-gsmainmenu.o(.text.__tcf_4) }
    .local_startup_storage_0 0x004b6f6c (NOLOAD) : { *state-hooks-gsmainmenu.o(.bss._ZN3irr5scene6quake315irrEmptyStringcE) }
    .local_startup_storage_1 0x004b6f8c (NOLOAD) : { *state-hooks-gsmainmenu.o(.bss._ZN3irr2ps5vHalfE) }
    .local_startup_storage_2 0x004b6f98 (NOLOAD) : { *state-hooks-gsmainmenu.o(.bss._ZN8gameloft2ai11civ_passiveE) }
    .local_startup_storage_3 0x004b6fa0 (NOLOAD) : { *state-hooks-gsmainmenu.o(.bss._ZN8gameloft2ai12npc_scriptedE) }
    .local_startup_storage_4 0x004b6fa8 (NOLOAD) : { *state-hooks-gsmainmenu.o(.bss._ZN8gameloft2ai13civ_agressiveE) }
    .local_startup_storage_5 0x004b6fb0 (NOLOAD) : { *state-hooks-gsmainmenu.o(.bss._ZN8gameloft2ai11gang_memberE) }
    .local_startup_storage_6 0x004b6fb8 (NOLOAD) : { *state-hooks-gsmainmenu.o(.bss._ZN8gameloft2ai3copE) }
    .local_startup_storage_7 0x004b6fc0 (NOLOAD) : { *state-hooks-gsmainmenu.o(.bss._ZN8gameloft2ai4swatE) }
    .local_startup_storage_8 0x004b6fc8 (NOLOAD) : { *state-hooks-gsmainmenu.o(.bss._ZN8gameloft2ai11civ_vehicleE) }
    .local_startup_storage_9 0x004b6fd0 (NOLOAD) : { *state-hooks-gsmainmenu.o(.bss._ZN8gameloft2ai11cop_vehicleE) }
    .local_startup_storage_10 0x004b6fd8 (NOLOAD) : { *state-hooks-gsmainmenu.o(.bss._ZN8gameloft2ai5guardE) }
    .local_startup_storage_11 0x004b6fe0 (NOLOAD) : { *state-hooks-gsmainmenu.o(.bss._ZN8gameloft2ai16scripted_vehicleE) }

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
