OUTPUT_FORMAT("elf32-littlearm")
OUTPUT_ARCH(arm)
INCLUDE build/matches/menu-manager-helpers/retail-symbols.ld
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
_ZdlPv = 0x001c42b0;
__aeabi_atexit = 0x001c494c;
SECTIONS
{
    .helper_0 0x002e3e7c : { *menu-manager-helpers.o(.text._ZN11MenuManager21resetWidgetVisibilityEv .gnu.linkonce.t._ZN11MenuManager21resetWidgetVisibilityEv) }
    .helper_1 0x002e3e84 : { *menu-manager-helpers.o(.text._ZN11MenuManager9MenuPauseEv .gnu.linkonce.t._ZN11MenuManager9MenuPauseEv) }
    .helper_2 0x002e3e88 : { *menu-manager-helpers.o(.text._ZN11MenuManager10MenuResumeEv .gnu.linkonce.t._ZN11MenuManager10MenuResumeEv) }
    .helper_3 0x002e3e8c : { *menu-manager-helpers.o(.text._ZN11MenuManager14setTutorialIdsEii .gnu.linkonce.t._ZN11MenuManager14setTutorialIdsEii) }
    .helper_4 0x002e3eb4 : { *menu-manager-helpers.o(.text._ZN11MenuManager13setRepairCostEi .gnu.linkonce.t._ZN11MenuManager13setRepairCostEi) }
    .helper_5 0x002e3eb8 : { *menu-manager-helpers.o(.text._ZNK11MenuManager13getRepairCostEv .gnu.linkonce.t._ZNK11MenuManager13getRepairCostEv) }
    .helper_6 0x002e3ebc : { *menu-manager-helpers.o(.text._ZNK11MenuManager17areCheatsUnlockedEv .gnu.linkonce.t._ZNK11MenuManager17areCheatsUnlockedEv) }
    .helper_7 0x002e3ee4 : { *menu-manager-helpers.o(.text._ZNK11MenuManager21isCheatsUnlockAllowedEv .gnu.linkonce.t._ZNK11MenuManager21isCheatsUnlockAllowedEv) }
    .helper_8 0x002e3f04 : { *menu-manager-helpers.o(.text._ZNK11MenuManager15isClearingFocusEv .gnu.linkonce.t._ZNK11MenuManager15isClearingFocusEv) }
    .helper_9 0x002e3f0c : { *menu-manager-helpers.o(.text._ZN11MenuManager9getMenuFXEv .gnu.linkonce.t._ZN11MenuManager9getMenuFXEv) }
    .helper_10 0x002e3f14 : { *menu-manager-helpers.o(.text._ZNK11MenuManager12isInGameMenuEv .gnu.linkonce.t._ZNK11MenuManager12isInGameMenuEv) }
    .helper_11 0x002e3f18 : { *menu-manager-helpers.o(.text._ZNK11MenuManager15consumedCursorsEv .gnu.linkonce.t._ZNK11MenuManager15consumedCursorsEv) }
    .helper_12 0x002e3f20 : { *menu-manager-helpers.o(.text._ZN11MenuManager13consumeCursorEv .gnu.linkonce.t._ZN11MenuManager13consumeCursorEv) }
    .helper_13 0x002e3f2c : { *menu-manager-helpers.o(.text._ZN11MenuManager19getCharAutoLineFeedEv .gnu.linkonce.t._ZN11MenuManager19getCharAutoLineFeedEv) }
    .helper_14 0x002e3f78 : { *menu-manager-helpers.o(.text._ZN11MenuManager11enableAnimsEb .gnu.linkonce.t._ZN11MenuManager11enableAnimsEb) }
    .helper_15 0x002e3f84 : { *menu-manager-helpers.o(.text._ZNK11MenuManager15areAnimsEnabledEv .gnu.linkonce.t._ZNK11MenuManager15areAnimsEnabledEv) }
    .helper_16 0x002e465c : { *menu-manager-helpers.o(.text._ZNK11MenuManager8getDepthEv .gnu.linkonce.t._ZNK11MenuManager8getDepthEv) }
    .helper_17 0x002e65d0 : { *menu-manager-helpers.o(.text._ZNK11MenuManager10getMapModeEv .gnu.linkonce.t._ZNK11MenuManager10getMapModeEv) }
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
    .got 0x004b0048 : { *(.got.plt) . = 0x360; *(.got) }
    .verification 0x00600000 : { *retail-got.o(.text) }
    .shared_startup_empty_text 0x0044d91c : { *(.gnu.linkonce.r.localStartupEmptyText) }
}
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
