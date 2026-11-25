strlen = 0x001c48bc;
strrchr = 0x001c4340;
strstr = 0x001c446c;
strchr = 0x001c48e0;
__aeabi_ui2f = 0x001c4574;
__aeabi_fdiv = 0x001c4520;
OUTPUT_FORMAT("elf32-littlearm")
OUTPUT_ARCH(arm)
strcpy = 0x001c3fd4;
sprintf = 0x001c46ac;
memset = 0x001c45d4;
__aeabi_idivmod = 0x001c4934;
__cxa_pure_virtual = 0;
INCLUDE build/matches/ai-startup-menustate/retail-symbols.ld
_ZdlPv = 0x001c42b0;
__stack_chk_fail = 0x001c42e0;
__aeabi_i2d = 0x001c452c;
__aeabi_dsub = 0x001c4454;
__aeabi_d2iz = 0x001c4844;
_ZN23retail_achievement_menu5iconsE = 0x0047b1a0;
strcmp = 0x001c4658;
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
INCLUDE config/linker/MenuWidgetFunctions.ld
INCLUDE config/linker/MenuManagerFocus.ld
INCLUDE config/linker/RenderFXAnimationFunctions.ld
_ZN5Menus24s_helpSpecializedEntriesE = 0x0047b1b8;
INCLUDE config/linker/MenuWidgetMissionSections.ld
INCLUDE config/linker/WidgetVolumesLocalizationSections.ld
INCLUDE config/linker/WidgetTutorialLocalization.ld

INCLUDE config/linker/WidgetConfirmLocalization.ld
INCLUDE config/linker/WidgetControlsLocalization.ld
INCLUDE config/linker/WidgetGameSettingEvent.ld
INCLUDE config/linker/WidgetCorruptionLocalization.ld
INCLUDE config/linker/WidgetAchievementsLocalization.ld
INCLUDE config/linker/WidgetMissionMapLegendEvents.ld
INCLUDE config/linker/WidgetDialogObjectiveLanguageEvents.ld
INCLUDE config/linker/WidgetControlsEvent.ld

INCLUDE config/linker/MapNotifySections.ld

carRentalTutorialPartFormat = 0x00419e70;
SECTIONS
{
    .event_character_path 0x002e76e8 : { *ai-startup-menustate.o(.text._ZN8RenderFX5Event16GetCharacterPathEv) }
    .car_rental_notify 0x002eb760 : { *ai-startup-menustate.o(.text._ZN5Menus16ServiceCarRental6NotifyEPK10MenuWidgeti) }
    ASSERT(SIZEOF(.car_rental_notify) == 448, "Native car_rental_notify extent")
    .main_menu_notify 0x002ea478 : { *ai-startup-menustate.o(.text._ZN5Menus8MainMenu6NotifyEPK10MenuWidgeti) }
    ASSERT(SIZEOF(.main_menu_notify) == 544, "Native main_menu_notify extent")
    .car_rental_selected_suffix 0x00419e68 : { *ai-startup-menustate.o(.rodata.carRentalSelectedSuffix) }
    .main_menu_promotion_url 0x00419f14 : { *ai-startup-menustate.o(.rodata.mainMenuPromotionUrl) }
    .weapon_shop_update 0x002eb45c : { *ai-startup-menustate.o(.text._ZN5Menus17ServiceWeaponShop6UpdateEv) }
    ASSERT(SIZEOF(.weapon_shop_update) == 380, "Native ServiceWeaponShop Update extent")
    .menustate_got_focus 0x002e86fc : { *ai-startup-menustate.o(.text._ZN9MenuState8GotFocusEv) }
    .service_corruption_notify 0x002eb6a8 : { *ai-startup-menustate.o(.text._ZN5Menus17ServiceCorruption6NotifyEPK10MenuWidgeti) }
    .service_weaponshop_notify 0x002eb920 : { *ai-startup-menustate.o(.text._ZN5Menus17ServiceWeaponShop6NotifyEPK10MenuWidgeti) }
    ASSERT(SIZEOF(.service_weaponshop_notify) == 188, "ServiceWeaponShop Notify must retain native 188-byte extent")

    .infos_notify 0x002ea7f4 : { *ai-startup-menustate.o(.text._ZN5Menus5Infos6NotifyEPK10MenuWidgeti) }
    ASSERT(SIZEOF(.infos_notify) == 304, "Infos Notify must retain native 304-byte extent")
    .infos_notify_table 0x0041a070 : { *ai-startup-menustate.o(.rodata._ZN5Menus5Infos6NotifyEPK10MenuWidgeti) }
    ASSERT(SIZEOF(.infos_notify_table) == 20, "Infos switch table must retain native 20-byte extent")

    .option_volumes_notify 0x002eb084 : { *ai-startup-menustate.o(.text._ZN5Menus13OptionVolumes6NotifyEPK10MenuWidgeti) }
    ASSERT(SIZEOF(.option_volumes_notify) == 168, "OptionVolumes Notify must retain native 168-byte extent")

    .services_notify 0x002eb5d8 : { *ai-startup-menustate.o(.text._ZN5Menus8Services6NotifyEPK10MenuWidgeti) }
    ASSERT(SIZEOF(.services_notify) == 208, "Services Notify must retain native 208-byte extent")
    .servicesWeaponShopName 0x00418fdc : { *ai-startup-menustate.o(.rodata.servicesWeaponShopName) }
    .servicesCarRentalName 0x00418ff0 : { *ai-startup-menustate.o(.rodata.servicesCarRentalName) }

    .options_notify 0x002eab94 : { *ai-startup-menustate.o(.text._ZN5Menus7Options6NotifyEPK10MenuWidgeti) }
    ASSERT(SIZEOF(.options_notify) == 208, "Options Notify must retain native 208-byte extent")

    .info_achievements_notify 0x002ea924 : { *ai-startup-menustate.o(.text._ZN5Menus16InfoAchievements6NotifyEPK10MenuWidgeti) }
    ASSERT(SIZEOF(.info_achievements_notify) == 224, "InfoAchievements Notify must retain native 224-byte extent")
    .renderfx_trace_context 0x003ed2f4 : { *renderfx-animation.o(.text._ZN8RenderFX27DBG_TraceContextInformationEPN7gameswf9characterE) }
    .renderfx_found_child 0x0044ddf8 : { *renderfx-animation.o(.rodata.renderfx_found_child) }
    .renderfx_child_sprite 0x0044de10 : { *renderfx-animation.o(.rodata.renderfx_child_sprite) }

    .renderfx_collect_characters 0x003ed1bc : { *renderfx-animation.o(.text._ZN8RenderFX17CollectCharactersEPN7gameswf9characterEPKci) }
    .menu_anims_enabled 0x002e3f84 : { *menu-manager-helpers.o(.text._ZNK11MenuManager15areAnimsEnabledEv) }
    .menu_state_hide 0x002e8654 : { *ai-startup-menustate.o(.text._ZN9MenuState4HideEv) }
    .service_missions_focus 0x002e8fe8 : { *ai-startup-menustate.o(.text._ZN5Menus15ServiceMissions8GotFocusEv) }
    .help_empty_icon 0x00409c2c : { *ai-startup-menustate.o(.rodata.helpEmptyIcon) }
    .info_help_notify 0x002eaa04 : { *ai-startup-menustate.o(.text._ZN5Menus8InfoHelp6NotifyEPK10MenuWidgeti) }
    .menu_manager_clearing_focus 0x002e3f04 : { *menu-manager-helpers.o(.text._ZNK11MenuManager15isClearingFocusEv) }
    .menu_manager_consume_cursor 0x002e3f20 : { *menu-manager-helpers.o(.text._ZN11MenuManager13consumeCursorEv) }
    .tutorial_notify 0x002ea33c : { *ai-startup-menustate.o(.text._ZN5Menus8Tutorial6NotifyEPK10MenuWidgeti) }
    .blocking_tutorial_notify 0x002ea3b8 : { *ai-startup-menustate.o(.text._ZN5Menus16BlockingTutorial6NotifyEPK10MenuWidgeti) }
    .option_volumes_lost_focus 0x002e8c94 : { *ai-startup-menustate.o(.text._ZN5Menus13OptionVolumes9LostFocusEv) }
    .menu_state_lost_focus 0x002e9280 : { *ai-startup-menustate.o(.text._ZN9MenuState9LostFocusEv) }
    .main_menu_lost_focus 0x002e9284 : { *ai-startup-menustate.o(.text._ZN5Menus8MainMenu9LostFocusEv) }
    .service_missions_lost_focus 0x002e92c8 : { *ai-startup-menustate.o(.text._ZN5Menus15ServiceMissions9LostFocusEv) }
    .map_lost_focus 0x002e92f4 : { *ai-startup-menustate.o(.text._ZN5Menus3Map9LostFocusEv) }
    .in_game_menu_lost_focus 0x002e9308 : { *ai-startup-menustate.o(.text._ZN5Menus10InGameMenu9LostFocusEv) }
    .info_achievements_lost_focus 0x002e9334 : { *ai-startup-menustate.o(.text._ZN5Menus16InfoAchievements9LostFocusEv) }
    .info_help_lost_focus 0x002e9380 : { *ai-startup-menustate.o(.text._ZN5Menus8InfoHelp9LostFocusEv) }
    .option_game_settings_lost_focus 0x002e93ac : { *ai-startup-menustate.o(.text._ZN5Menus18OptionGameSettings9LostFocusEv) }
    .service_corruption_lost_focus 0x002e9408 : { *ai-startup-menustate.o(.text._ZN5Menus17ServiceCorruption9LostFocusEv) }
    .service_car_rental_lost_focus 0x002e9434 : { *ai-startup-menustate.o(.text._ZN5Menus16ServiceCarRental9LostFocusEv) }
    .service_weapon_shop_lost_focus 0x002e9460 : { *ai-startup-menustate.o(.text._ZN5Menus17ServiceWeaponShop9LostFocusEv) }
    .achievement_lost_focus 0x002e948c : { *ai-startup-menustate.o(.text._ZN5Menus11Achievement9LostFocusEv) }
    .helper_10 0x002e3f14 : { *menu-manager-helpers.o(.text._ZNK11MenuManager12isInGameMenuEv .gnu.linkonce.t._ZNK11MenuManager12isInGameMenuEv) }
    .in_game_menu_notify 0x002e7814 : { *(.text._ZN5Menus10InGameMenu6NotifyEPK10MenuWidgeti) }
    .in_game_menu_got_focus 0x002e88a8 : { *ai-startup-menustate.o(.text._ZN5Menus10InGameMenu8GotFocusEv) }
    .in_game_menu_vtable 0x004a95f0 : { *ai-startup-menustate.o(.data.rel.ro._ZTVN5Menus10InGameMenuE) }
    .options_got_focus 0x002e8ac8 : { *ai-startup-menustate.o(.text._ZN5Menus7Options8GotFocusEv) }
    .services_got_focus 0x002e8d18 : { *ai-startup-menustate.o(.text._ZN5Menus8Services8GotFocusEv) }
    .info_achievements_got_focus 0x002e89c0 : { *ai-startup-menustate.o(.text._ZN5Menus16InfoAchievements8GotFocusEv) }
    .service_corruption_got_focus 0x002e8dc8 : { *ai-startup-menustate.o(.text._ZN5Menus17ServiceCorruption8GotFocusEv) }
    .service_car_rental_got_focus 0x002e8e30 : { *ai-startup-menustate.o(.text._ZN5Menus16ServiceCarRental8GotFocusEv) }
    .service_weapon_shop_got_focus 0x002e8f0c : { *ai-startup-menustate.o(.text._ZN5Menus17ServiceWeaponShop8GotFocusEv) }
    .service_car_rental_vtable 0x004a9440 : { *ai-startup-menustate.o(.data.rel.ro._ZTVN5Menus16ServiceCarRentalE) }
    .service_weapon_shop_vtable 0x004a94d0 : { *ai-startup-menustate.o(.data.rel.ro._ZTVN5Menus17ServiceWeaponShopE) }
    .four_button_menu_frame 0x00419f0c : { *ai-startup-menustate.o(.rodata.fourButtonMenuFrame) }
    .infos_focus 0x002e88d4 : { *ai-startup-menustate.o(.text._ZN5Menus5Infos8GotFocusEv) }
    .infos_menu_frame 0x00419f04 : { *ai-startup-menustate.o(.rodata.infosMenuFrame) }
    .infos_vtable 0x004a9200 : { *ai-startup-menustate.o(.data.rel.ro._ZTVN5Menus5InfosE) }
    .options_vtable 0x004a9368 : { *ai-startup-menustate.o(.data.rel.ro._ZTVN5Menus7OptionsE) }
    .services_vtable 0x004a9560 : { *ai-startup-menustate.o(.data.rel.ro._ZTVN5Menus8ServicesE) }
    .info_statistics_got_focus 0x002e8990 : { *ai-startup-menustate.o(.text._ZN5Menus14InfoStatistics8GotFocusEv) }
    .info_about_got_focus 0x002e8a24 : { *ai-startup-menustate.o(.text._ZN5Menus9InfoAbout8GotFocusEv) }
    .info_help_got_focus 0x002e8a54 : { *ai-startup-menustate.o(.text._ZN5Menus8InfoHelp8GotFocusEv) }
    .option_language_got_focus 0x002e8c14 : { *ai-startup-menustate.o(.text._ZN5Menus14OptionLanguage8GotFocusEv) }
    .option_controls_got_focus 0x002e8c64 : { *ai-startup-menustate.o(.text._ZN5Menus14OptionControls8GotFocusEv) }
    .in_game_car_rental_got_focus 0x002e8ed8 : { *ai-startup-menustate.o(.text._ZN5Menus15InGameCarRental8GotFocusEv) }
    .in_game_weapon_shop_got_focus 0x002e8fb4 : { *ai-startup-menustate.o(.text._ZN5Menus16InGameWeaponShop8GotFocusEv) }
    .achievement_got_focus 0x002e91fc : { *ai-startup-menustate.o(.text._ZN5Menus11Achievement8GotFocusEv) }
    .tutorial_got_focus 0x002e9254 : { *ai-startup-menustate.o(.text._ZN5Menus8Tutorial8GotFocusEv) }
    .tutorial_lost_focus 0x002e94e4 : { *ai-startup-menustate.o(.text._ZN5Menus8Tutorial9LostFocusEv) }
    .blocking_tutorial_got_focus 0x002e9228 : { *ai-startup-menustate.o(.text._ZN5Menus16BlockingTutorial8GotFocusEv) }
    .blocking_tutorial_lost_focus 0x002e94b8 : { *ai-startup-menustate.o(.text._ZN5Menus16BlockingTutorial9LostFocusEv) }
    .menu_state_show 0x002e9518 : { *ai-startup-menustate.o(.text._ZN9MenuState4ShowEv) }
    .tutorial_show 0x002ea434 : { *ai-startup-menustate.o(.text._ZN5Menus8Tutorial4ShowEv) }
    .blocking_tutorial_deleting_destructor 0x002ea084 : { *ai-startup-menustate.o(.text._ZN5Menus16BlockingTutorialD0Ev) }
    .blocking_tutorial_complete_destructor 0x002ea0b0 : { *ai-startup-menustate.o(.text._ZN5Menus16BlockingTutorialD1Ev .text._ZN5Menus16BlockingTutorialD2Ev) }
    .blocking_tutorial_vtable 0x004a9680 : { *ai-startup-menustate.o(.data.rel.ro._ZTVN5Menus16BlockingTutorialE) }
    .menu_manager_texture_storage 0x004b7210 (NOLOAD) : { *menu-manager-helpers.o(.bss.s_textures) }
    .menu_manager_get_fx 0x002e3f0c : { *menu-manager-helpers.o(.text._ZN11MenuManager9getMenuFXEv) }
    .menu_manager_get_depth 0x002e465c : { *menu-manager-helpers.o(.text._ZNK11MenuManager8getDepthEv .gnu.linkonce.t._ZNK11MenuManager8getDepthEv) }
    .cleanup_map 0x002e66b4 : { *menu-manager-helpers.o(.text._ZN11MenuManager10cleanupMapEv) }
    .are_cheats_unlocked 0x002e3ebc : { *menu-manager-helpers.o(.text._ZNK11MenuManager17areCheatsUnlockedEv) }
    .option_orientation_get 0x002e7354 : { *(.text._ZN5Menus18OptionGameSettings14GetOrientationEv) }
    .option_orientation_set_enum 0x002e75f0 : { *(.text._ZN5Menus18OptionGameSettings14SetOrientationENS0_13stGameSetting12eOrientationE) }
    .option_orientation_set_int 0x002e7610 : { *(.text._ZN5Menus18OptionGameSettings14SetOrientationEi) }
    .option_settings_refresh 0x002e7988 : { *ai-startup-menustate.o(.text._ZN5Menus18OptionGameSettings7RefreshEv) }
    .option_settings_got_focus 0x002e8b74 : { *ai-startup-menustate.o(.text._ZN5Menus18OptionGameSettings8GotFocusEv) }
    .option_volumes_got_focus 0x002e8cc0 : { *ai-startup-menustate.o(.text._ZN5Menus13OptionVolumes8GotFocusEv) }
    .main_menu_deleting_destructor 0x002e982c : { *ai-startup-menustate.o(.text._ZN5Menus8MainMenuD0Ev .gnu.linkonce.t._ZN5Menus8MainMenuD0Ev) }
    .main_menu_complete_destructor 0x002e9854 : { *ai-startup-menustate.o(.text._ZN5Menus8MainMenuD1Ev .gnu.linkonce.t._ZN5Menus8MainMenuD1Ev .text._ZN5Menus8MainMenuD2Ev .gnu.linkonce.t._ZN5Menus8MainMenuD2Ev) }
    .main_menu_vtable 0x004a8fc0 : { *ai-startup-menustate.o(.data.rel.ro._ZTVN5Menus8MainMenuE .gnu.linkonce.d.rel.ro._ZTVN5Menus8MainMenuE) }
    .splash_deleting_destructor 0x002e97e4 : { *ai-startup-menustate.o(.text._ZN5Menus6SplashD0Ev .gnu.linkonce.t._ZN5Menus6SplashD0Ev) }
    .splash_complete_destructor 0x002e980c : { *ai-startup-menustate.o(.text._ZN5Menus6SplashD1Ev .gnu.linkonce.t._ZN5Menus6SplashD1Ev .text._ZN5Menus6SplashD2Ev .gnu.linkonce.t._ZN5Menus6SplashD2Ev) }
    .splash_vtable 0x004a9758 : { *ai-startup-menustate.o(.data.rel.ro._ZTVN5Menus6SplashE .gnu.linkonce.d.rel.ro._ZTVN5Menus6SplashE) }
    .service_car_rental_deleting_destructor 0x002e9eec : { *ai-startup-menustate.o(.text._ZN5Menus16ServiceCarRentalD0Ev .gnu.linkonce.t._ZN5Menus16ServiceCarRentalD0Ev) }
    .service_car_rental_complete_destructor 0x002e9f18 : { *ai-startup-menustate.o(.text._ZN5Menus16ServiceCarRentalD1Ev .gnu.linkonce.t._ZN5Menus16ServiceCarRentalD1Ev .text._ZN5Menus16ServiceCarRentalD2Ev .gnu.linkonce.t._ZN5Menus16ServiceCarRentalD2Ev) }
    .service_weapon_shop_deleting_destructor 0x002e9f94 : { *ai-startup-menustate.o(.text._ZN5Menus17ServiceWeaponShopD0Ev .gnu.linkonce.t._ZN5Menus17ServiceWeaponShopD0Ev) }
    .service_weapon_shop_complete_destructor 0x002e9fc0 : { *ai-startup-menustate.o(.text._ZN5Menus17ServiceWeaponShopD1Ev .gnu.linkonce.t._ZN5Menus17ServiceWeaponShopD1Ev .text._ZN5Menus17ServiceWeaponShopD2Ev .gnu.linkonce.t._ZN5Menus17ServiceWeaponShopD2Ev) }
    .map_deleting_destructor 0x002e9a54 : { *ai-startup-menustate.o(.text._ZN5Menus3MapD0Ev .gnu.linkonce.t._ZN5Menus3MapD0Ev) }
    .map_complete_destructor 0x002e9a80 : { *ai-startup-menustate.o(.text._ZN5Menus3MapD1Ev .gnu.linkonce.t._ZN5Menus3MapD1Ev .text._ZN5Menus3MapD2Ev .gnu.linkonce.t._ZN5Menus3MapD2Ev) }
    .map_vtable 0x004a95a8 : { *ai-startup-menustate.o(.data.rel.ro._ZTVN5Menus3MapE .gnu.linkonce.d.rel.ro._ZTVN5Menus3MapE) }
    .achievement_deleting_destructor 0x002e979c : { *ai-startup-menustate.o(.text._ZN5Menus11AchievementD0Ev .gnu.linkonce.t._ZN5Menus11AchievementD0Ev) }
    .achievement_complete_destructor 0x002e97c4 : { *ai-startup-menustate.o(.text._ZN5Menus11AchievementD1Ev .gnu.linkonce.t._ZN5Menus11AchievementD1Ev .text._ZN5Menus11AchievementD2Ev .gnu.linkonce.t._ZN5Menus11AchievementD2Ev) }
    .achievement_vtable 0x004a9638 : { *ai-startup-menustate.o(.data.rel.ro._ZTVN5Menus11AchievementE .gnu.linkonce.d.rel.ro._ZTVN5Menus11AchievementE) }
    .in_game_car_rental_deleting_destructor 0x002e9f40 : { *ai-startup-menustate.o(.text._ZN5Menus15InGameCarRentalD0Ev .gnu.linkonce.t._ZN5Menus15InGameCarRentalD0Ev) }
    .in_game_car_rental_complete_destructor 0x002e9f6c : { *ai-startup-menustate.o(.text._ZN5Menus15InGameCarRentalD1Ev .gnu.linkonce.t._ZN5Menus15InGameCarRentalD1Ev .text._ZN5Menus15InGameCarRentalD2Ev .gnu.linkonce.t._ZN5Menus15InGameCarRentalD2Ev) }
    .in_game_car_rental_vtable 0x004a93f8 : { *ai-startup-menustate.o(.data.rel.ro._ZTVN5Menus15InGameCarRentalE .gnu.linkonce.d.rel.ro._ZTVN5Menus15InGameCarRentalE) }
    .in_game_weapon_shop_deleting_destructor 0x002e9fe8 : { *ai-startup-menustate.o(.text._ZN5Menus16InGameWeaponShopD0Ev .gnu.linkonce.t._ZN5Menus16InGameWeaponShopD0Ev) }
    .in_game_weapon_shop_complete_destructor 0x002ea014 : { *ai-startup-menustate.o(.text._ZN5Menus16InGameWeaponShopD1Ev .gnu.linkonce.t._ZN5Menus16InGameWeaponShopD1Ev .text._ZN5Menus16InGameWeaponShopD2Ev .gnu.linkonce.t._ZN5Menus16InGameWeaponShopD2Ev) }
    .in_game_weapon_shop_vtable 0x004a9488 : { *ai-startup-menustate.o(.data.rel.ro._ZTVN5Menus16InGameWeaponShopE .gnu.linkonce.d.rel.ro._ZTVN5Menus16InGameWeaponShopE) }
    .cop_bribe_deleting_destructor 0x002e99b8 : { *ai-startup-menustate.o(.text._ZN5Menus8CopBribeD0Ev .gnu.linkonce.t._ZN5Menus8CopBribeD0Ev) }
    .cop_bribe_complete_destructor 0x002e99e4 : { *ai-startup-menustate.o(.text._ZN5Menus8CopBribeD1Ev .gnu.linkonce.t._ZN5Menus8CopBribeD1Ev .text._ZN5Menus8CopBribeD2Ev .gnu.linkonce.t._ZN5Menus8CopBribeD2Ev) }
    .cop_bribe_vtable 0x004a97a0 : { *ai-startup-menustate.o(.data.rel.ro._ZTVN5Menus8CopBribeE .gnu.linkonce.d.rel.ro._ZTVN5Menus8CopBribeE) }
    .car_repair_deleting_destructor 0x002e9964 : { *ai-startup-menustate.o(.text._ZN5Menus9CarRepairD0Ev .gnu.linkonce.t._ZN5Menus9CarRepairD0Ev) }
    .car_repair_complete_destructor 0x002e9990 : { *ai-startup-menustate.o(.text._ZN5Menus9CarRepairD1Ev .gnu.linkonce.t._ZN5Menus9CarRepairD1Ev .text._ZN5Menus9CarRepairD2Ev .gnu.linkonce.t._ZN5Menus9CarRepairD2Ev) }
    .car_repair_vtable 0x004a97e8 : { *ai-startup-menustate.o(.data.rel.ro._ZTVN5Menus9CarRepairE .gnu.linkonce.d.rel.ro._ZTVN5Menus9CarRepairE) }
    .weapon_shop_widget_ids 0x0041a69c : { *ai-startup-menustate.o(.rodata._ZZN5Menus17ServiceWeaponShopC1EPKcE*) }
    .mainMenu_game_continue 0x002e738c : { *ai-startup-menustate.o(.text._ZNK5Menus8MainMenu12GameContinueEv) }
    .main_menu_set_pause 0x002e7394 : { *(.text._ZN5Menus8MainMenu8SetPauseEb) }
    .main_menu_got_focus 0x002e87f4 : { *(.text._ZN5Menus8MainMenu8GotFocusEv) }
    .main_menu_update 0x002ea698 : { *(.text._ZN5Menus8MainMenu6UpdateEv) }
    .menu_localization 0x002e7cfc : { *(.text._ZN9MenuState18UpdateLocalizationEv) }
    .menu_rental_hide 0x002e86bc : { *(.text._ZN5Menus15InGameCarRental4HideEv) }
    .menu_weapon_shop_hide 0x002e86dc : { *(.text._ZN5Menus16InGameWeaponShop4HideEv) }
    .menu_map_event 0x002e8638 : { *(.text._ZN5Menus3Map7OnEventERN8RenderFX5EventE) }
    .menu_infos_update 0x002eab20 : { *(.text._ZN5Menus5Infos6UpdateEv) }
    .menu_statistics_command 0x002e79d4 : { *(.text._ZN5Menus14InfoStatistics11OnFSCommandEPKcS2_) }
    .menu_achievements_command 0x002e7a24 : { *(.text._ZN5Menus16InfoAchievements11OnFSCommandEPKcS2_) }
    .menu_about_command 0x002e7a74 : { *(.text._ZN5Menus9InfoAbout11OnFSCommandEPKcS2_) }
    .menu_update_statistics 0x00419e34 : { *(.rodata.menu_update_statistics) }
    .menu_update_achievements 0x00419e48 : { *(.rodata.menu_update_achievements) }
    .menu_update_about 0x00419e5c : { *(.rodata.menu_update_about) }
    .menu_map_got_focus 0x002e90cc : { *(.text._ZN5Menus3Map8GotFocusEv) }
    .helper_11 0x002e3f18 : { *menu-manager-helpers.o(.text._ZNK11MenuManager15consumedCursorsEv .gnu.linkonce.t._ZNK11MenuManager15consumedCursorsEv) }
    .helper_14 0x002e3f78 : { *menu-manager-helpers.o(.text._ZN11MenuManager11enableAnimsEb .gnu.linkonce.t._ZN11MenuManager11enableAnimsEb) }
    .menu_map_update 0x002ebb30 : { *(.text._ZN5Menus3Map6UpdateEv) }
    .achievement_menu_set 0x002e7d50 : { *(.text._ZN5Menus11Achievement14SetAchievementEPKN18AchievementManager11AchievementE) }
    .achievement_menu_show 0x002ea2e4 : { *(.text._ZN5Menus11Achievement4ShowEv) }
    .achievement_menu_update 0x002e7658 : { *(.text._ZN5Menus11Achievement6UpdateEv) }
    .main_menu_confirm 0x00418138 : { *(.rodata.main_menu_confirm) }
    .mainMenu_constructor 0x002e7dd0 : { *ai-startup-menustate.o(.text._ZN5Menus8MainMenuC1Ev .text._ZN5Menus8MainMenuC2Ev) }
    .mainMenu_name 0x00413c7c : { *ai-startup-menustate.o(.rodata.mainMenuName) }
    .splash_constructor 0x002e7e24 : { *ai-startup-menustate.o(.text._ZN5Menus6SplashC1Ev .text._ZN5Menus6SplashC2Ev) }
    .splash_name 0x00418710 : { *ai-startup-menustate.o(.rodata.splashName) }
    .serviceCarRental_constructor 0x002e8350 : { *ai-startup-menustate.o(.text._ZN5Menus16ServiceCarRentalC1EPKc .text._ZN5Menus16ServiceCarRentalC2EPKc) }
    .serviceWeaponShop_constructor 0x002e83a0 : { *ai-startup-menustate.o(.text._ZN5Menus17ServiceWeaponShopC1EPKc .text._ZN5Menus17ServiceWeaponShopC2EPKc) }
    .map_constructor 0x002e8450 : { *ai-startup-menustate.o(.text._ZN5Menus3MapC1Ev .text._ZN5Menus3MapC2Ev) }
    .map_name 0x0040b608 : { *ai-startup-menustate.o(.rodata.mapName) }
    .achievement_constructor 0x002e84a4 : { *ai-startup-menustate.o(.text._ZN5Menus11AchievementC1Ev .text._ZN5Menus11AchievementC2Ev) }
    .achievement_name 0x00419ef4 : { *ai-startup-menustate.o(.rodata.achievementName) }
    .blockingTutorial_constructor 0x002ea0d8 : { *ai-startup-menustate.o(.text._ZN5Menus16BlockingTutorialC1Ev .text._ZN5Menus16BlockingTutorialC2Ev) }
    .blockingTutorial_name 0x00414c84 : { *ai-startup-menustate.o(.rodata.blockingTutorialName) }
    .inGameCarRental_constructor 0x002ea14c : { *ai-startup-menustate.o(.text._ZN5Menus15InGameCarRentalC1Ev .text._ZN5Menus15InGameCarRentalC2Ev) }
    .inGameCarRental_name 0x00415844 : { *ai-startup-menustate.o(.rodata.inGameCarRentalName) }
    .inGameWeaponShop_constructor 0x002ea1b4 : { *ai-startup-menustate.o(.text._ZN5Menus16InGameWeaponShopC1Ev .text._ZN5Menus16InGameWeaponShopC2Ev) }
    .inGameWeaponShop_name 0x00418720 : { *ai-startup-menustate.o(.rodata.inGameWeaponShopName) }
    .copBribe_constructor 0x002ea28c : { *ai-startup-menustate.o(.text._ZN5Menus8CopBribeC1Ev .text._ZN5Menus8CopBribeC2Ev) }
    .copBribe_name 0x00415268 : { *ai-startup-menustate.o(.rodata.copBribeName) }
    .carRepair_constructor 0x002ea2b8 : { *ai-startup-menustate.o(.text._ZN5Menus9CarRepairC1Ev .text._ZN5Menus9CarRepairC2Ev) }
    .carRepair_name 0x00415e24 : { *ai-startup-menustate.o(.rodata.carRepairName) }
    .in_game_menu_deleting_destructor 0x002e9a0c : { *ai-startup-menustate.o(.text._ZN5Menus10InGameMenuD0Ev .gnu.linkonce.t._ZN5Menus10InGameMenuD0Ev) }
    .in_game_menu_complete_destructor 0x002e9a34 : { *ai-startup-menustate.o(.text._ZN5Menus10InGameMenuD1Ev .gnu.linkonce.t._ZN5Menus10InGameMenuD1Ev .text._ZN5Menus10InGameMenuD2Ev .gnu.linkonce.t._ZN5Menus10InGameMenuD2Ev) }
    .infos_deleting_destructor 0x002e9aa8 : { *ai-startup-menustate.o(.text._ZN5Menus5InfosD0Ev .gnu.linkonce.t._ZN5Menus5InfosD0Ev) }
    .infos_complete_destructor 0x002e9ad4 : { *ai-startup-menustate.o(.text._ZN5Menus5InfosD1Ev .gnu.linkonce.t._ZN5Menus5InfosD1Ev .text._ZN5Menus5InfosD2Ev .gnu.linkonce.t._ZN5Menus5InfosD2Ev) }
    .options_deleting_destructor 0x002e9c4c : { *ai-startup-menustate.o(.text._ZN5Menus7OptionsD0Ev .gnu.linkonce.t._ZN5Menus7OptionsD0Ev) }
    .options_complete_destructor 0x002e9c78 : { *ai-startup-menustate.o(.text._ZN5Menus7OptionsD1Ev .gnu.linkonce.t._ZN5Menus7OptionsD1Ev .text._ZN5Menus7OptionsD2Ev .gnu.linkonce.t._ZN5Menus7OptionsD2Ev) }
    .services_deleting_destructor 0x002e9df0 : { *ai-startup-menustate.o(.text._ZN5Menus8ServicesD0Ev .gnu.linkonce.t._ZN5Menus8ServicesD0Ev) }
    .services_complete_destructor 0x002e9e1c : { *ai-startup-menustate.o(.text._ZN5Menus8ServicesD1Ev .gnu.linkonce.t._ZN5Menus8ServicesD1Ev .text._ZN5Menus8ServicesD2Ev .gnu.linkonce.t._ZN5Menus8ServicesD2Ev) }
    .tutorial_deleting_destructor 0x002ea03c : { *ai-startup-menustate.o(.text._ZN5Menus8TutorialD0Ev .gnu.linkonce.t._ZN5Menus8TutorialD0Ev) }
    .tutorial_complete_destructor 0x002ea064 : { *ai-startup-menustate.o(.text._ZN5Menus8TutorialD1Ev .gnu.linkonce.t._ZN5Menus8TutorialD1Ev .text._ZN5Menus8TutorialD2Ev .gnu.linkonce.t._ZN5Menus8TutorialD2Ev) }
    .tutorial_vtable 0x004a96c8 : { *ai-startup-menustate.o(.data.rel.ro._ZTVN5Menus8TutorialE .gnu.linkonce.d.rel.ro._ZTVN5Menus8TutorialE) }
    .info_statistics_deleting_destructor 0x002e9bf8 : { *ai-startup-menustate.o(.text._ZN5Menus14InfoStatisticsD0Ev .gnu.linkonce.t._ZN5Menus14InfoStatisticsD0Ev) }
    .info_statistics_complete_destructor 0x002e9c24 : { *ai-startup-menustate.o(.text._ZN5Menus14InfoStatisticsD1Ev .gnu.linkonce.t._ZN5Menus14InfoStatisticsD1Ev .text._ZN5Menus14InfoStatisticsD2Ev .gnu.linkonce.t._ZN5Menus14InfoStatisticsD2Ev) }
    .info_statistics_vtable 0x004a90e0 : { *ai-startup-menustate.o(.data.rel.ro._ZTVN5Menus14InfoStatisticsE .gnu.linkonce.d.rel.ro._ZTVN5Menus14InfoStatisticsE) }
    .info_achievements_deleting_destructor 0x002e9ba4 : { *ai-startup-menustate.o(.text._ZN5Menus16InfoAchievementsD0Ev .gnu.linkonce.t._ZN5Menus16InfoAchievementsD0Ev) }
    .info_achievements_complete_destructor 0x002e9bd0 : { *ai-startup-menustate.o(.text._ZN5Menus16InfoAchievementsD1Ev .gnu.linkonce.t._ZN5Menus16InfoAchievementsD1Ev .text._ZN5Menus16InfoAchievementsD2Ev .gnu.linkonce.t._ZN5Menus16InfoAchievementsD2Ev) }
    .info_achievements_vtable 0x004a9128 : { *ai-startup-menustate.o(.data.rel.ro._ZTVN5Menus16InfoAchievementsE .gnu.linkonce.d.rel.ro._ZTVN5Menus16InfoAchievementsE) }
    .info_about_deleting_destructor 0x002e9b50 : { *ai-startup-menustate.o(.text._ZN5Menus9InfoAboutD0Ev .gnu.linkonce.t._ZN5Menus9InfoAboutD0Ev) }
    .info_about_complete_destructor 0x002e9b7c : { *ai-startup-menustate.o(.text._ZN5Menus9InfoAboutD1Ev .gnu.linkonce.t._ZN5Menus9InfoAboutD1Ev .text._ZN5Menus9InfoAboutD2Ev .gnu.linkonce.t._ZN5Menus9InfoAboutD2Ev) }
    .info_about_vtable 0x004a9170 : { *ai-startup-menustate.o(.data.rel.ro._ZTVN5Menus9InfoAboutE .gnu.linkonce.d.rel.ro._ZTVN5Menus9InfoAboutE) }
    .option_language_deleting_destructor 0x002e9d48 : { *ai-startup-menustate.o(.text._ZN5Menus14OptionLanguageD0Ev .gnu.linkonce.t._ZN5Menus14OptionLanguageD0Ev) }
    .option_language_complete_destructor 0x002e9d74 : { *ai-startup-menustate.o(.text._ZN5Menus14OptionLanguageD1Ev .gnu.linkonce.t._ZN5Menus14OptionLanguageD1Ev .text._ZN5Menus14OptionLanguageD2Ev .gnu.linkonce.t._ZN5Menus14OptionLanguageD2Ev) }
    .option_language_vtable 0x004a9290 : { *ai-startup-menustate.o(.data.rel.ro._ZTVN5Menus14OptionLanguageE .gnu.linkonce.d.rel.ro._ZTVN5Menus14OptionLanguageE) }
    .option_controls_deleting_destructor 0x002e9cf4 : { *ai-startup-menustate.o(.text._ZN5Menus14OptionControlsD0Ev .gnu.linkonce.t._ZN5Menus14OptionControlsD0Ev) }
    .option_controls_complete_destructor 0x002e9d20 : { *ai-startup-menustate.o(.text._ZN5Menus14OptionControlsD1Ev .gnu.linkonce.t._ZN5Menus14OptionControlsD1Ev .text._ZN5Menus14OptionControlsD2Ev .gnu.linkonce.t._ZN5Menus14OptionControlsD2Ev) }
    .option_controls_vtable 0x004a92d8 : { *ai-startup-menustate.o(.data.rel.ro._ZTVN5Menus14OptionControlsE .gnu.linkonce.d.rel.ro._ZTVN5Menus14OptionControlsE) }
    .option_volumes_deleting_destructor 0x002e9ca0 : { *ai-startup-menustate.o(.text._ZN5Menus13OptionVolumesD0Ev .gnu.linkonce.t._ZN5Menus13OptionVolumesD0Ev) }
    .option_volumes_complete_destructor 0x002e9ccc : { *ai-startup-menustate.o(.text._ZN5Menus13OptionVolumesD1Ev .gnu.linkonce.t._ZN5Menus13OptionVolumesD1Ev .text._ZN5Menus13OptionVolumesD2Ev .gnu.linkonce.t._ZN5Menus13OptionVolumesD2Ev) }
    .option_volumes_vtable 0x004a9320 : { *ai-startup-menustate.o(.data.rel.ro._ZTVN5Menus13OptionVolumesE .gnu.linkonce.d.rel.ro._ZTVN5Menus13OptionVolumesE) }
    .service_corruption_deleting_destructor 0x002e9e98 : { *ai-startup-menustate.o(.text._ZN5Menus17ServiceCorruptionD0Ev .gnu.linkonce.t._ZN5Menus17ServiceCorruptionD0Ev) }
    .service_corruption_complete_destructor 0x002e9ec4 : { *ai-startup-menustate.o(.text._ZN5Menus17ServiceCorruptionD1Ev .gnu.linkonce.t._ZN5Menus17ServiceCorruptionD1Ev .text._ZN5Menus17ServiceCorruptionD2Ev .gnu.linkonce.t._ZN5Menus17ServiceCorruptionD2Ev) }
    .service_corruption_vtable 0x004a93b0 : { *ai-startup-menustate.o(.data.rel.ro._ZTVN5Menus17ServiceCorruptionE .gnu.linkonce.d.rel.ro._ZTVN5Menus17ServiceCorruptionE) }
    .service_missions_deleting_destructor 0x002e9e44 : { *ai-startup-menustate.o(.text._ZN5Menus15ServiceMissionsD0Ev .gnu.linkonce.t._ZN5Menus15ServiceMissionsD0Ev) }
    .service_missions_complete_destructor 0x002e9e70 : { *ai-startup-menustate.o(.text._ZN5Menus15ServiceMissionsD1Ev .gnu.linkonce.t._ZN5Menus15ServiceMissionsD1Ev .text._ZN5Menus15ServiceMissionsD2Ev .gnu.linkonce.t._ZN5Menus15ServiceMissionsD2Ev) }
    .service_missions_vtable 0x004a9518 : { *ai-startup-menustate.o(.data.rel.ro._ZTVN5Menus15ServiceMissionsE .gnu.linkonce.d.rel.ro._ZTVN5Menus15ServiceMissionsE) }
    .inGameMenu_constructor 0x002e7ecc : { *ai-startup-menustate.o(.text._ZN5Menus10InGameMenuC1EPKc .text._ZN5Menus10InGameMenuC2EPKc) }
    .infos_constructor 0x002e7f0c : { *ai-startup-menustate.o(.text._ZN5Menus5InfosC1EPKc .text._ZN5Menus5InfosC2EPKc) }
    .infoStatistics_constructor 0x002e7f50 : { *ai-startup-menustate.o(.text._ZN5Menus14InfoStatisticsC1Ev .text._ZN5Menus14InfoStatisticsC2Ev) }
    .infoStatistics_name 0x00419e78 : { *ai-startup-menustate.o(.rodata.infoStatisticsName) }
    .infoAchievements_constructor 0x002e7f98 : { *ai-startup-menustate.o(.text._ZN5Menus16InfoAchievementsC1Ev .text._ZN5Menus16InfoAchievementsC2Ev) }
    .infoAchievements_name 0x00419e20 : { *ai-startup-menustate.o(.rodata.infoAchievementsName) }
    .infoAbout_constructor 0x002e7fe8 : { *ai-startup-menustate.o(.text._ZN5Menus9InfoAboutC1Ev .text._ZN5Menus9InfoAboutC2Ev) }
    .infoAbout_name 0x00419e88 : { *ai-startup-menustate.o(.rodata.infoAboutName) }
    .infoHelp_constructor 0x002e8030 : { *ai-startup-menustate.o(.text._ZN5Menus8InfoHelpC1Ev .text._ZN5Menus8InfoHelpC2Ev) }
    .infoHelp_name 0x00419e94 : { *ai-startup-menustate.o(.rodata.infoHelpName) }
    .help_categories 0x0041a654 : { *ai-startup-menustate.o(.rodata._ZN5Menus16s_helpCategoriesE) }
    .help_page_count 0x004b7cec (NOLOAD) : { *ai-startup-menustate.o(.bss._ZN5Menus15s_helpPageCountE) }
    .info_help_deleting_destructor 0x002e9afc : { *ai-startup-menustate.o(.text._ZN5Menus8InfoHelpD0Ev) }
    .info_help_complete_destructor 0x002e9b28 : { *ai-startup-menustate.o(.text._ZN5Menus8InfoHelpD1Ev .text._ZN5Menus8InfoHelpD2Ev) }
    .info_help_vtable 0x004a91b8 : { *ai-startup-menustate.o(.data.rel.ro._ZTVN5Menus8InfoHelpE) }
    .options_constructor 0x002e80a4 : { *ai-startup-menustate.o(.text._ZN5Menus7OptionsC1EPKc .text._ZN5Menus7OptionsC2EPKc) }
    .optionGameSettings_constructor 0x002e80e4 : { *ai-startup-menustate.o(.text._ZN5Menus18OptionGameSettingsC1Ev .text._ZN5Menus18OptionGameSettingsC2Ev) }
    .optionGameSettings_name 0x00418da0 : { *ai-startup-menustate.o(.rodata.optionGameSettingsName) }
    .option_game_settings_deleting_destructor 0x002e9d9c : { *ai-startup-menustate.o(.text._ZN5Menus18OptionGameSettingsD0Ev) }
    .option_game_settings_complete_destructor 0x002e9dc8 : { *ai-startup-menustate.o(.text._ZN5Menus18OptionGameSettingsD1Ev .text._ZN5Menus18OptionGameSettingsD2Ev) }
    .option_game_settings_vtable 0x004a9248 : { *ai-startup-menustate.o(.data.rel.ro._ZTVN5Menus18OptionGameSettingsE) }
    .scriptChapterStartup_path 0x00419ea0 : { *ai-startup-menustate.o(.rodata.scriptChapterStartupPath) }
    .data_stream_dtor 0x002d3654 : { *ai-startup-menustate.o(.text._ZN10DataStreamD1Ev .gnu.linkonce.t._ZN10DataStreamD1Ev) }
    .optionLanguage_constructor 0x002e81f8 : { *ai-startup-menustate.o(.text._ZN5Menus14OptionLanguageC1Ev .text._ZN5Menus14OptionLanguageC2Ev) }
    .optionLanguage_name 0x00419ec0 : { *ai-startup-menustate.o(.rodata.optionLanguageName) }
    .optionControls_constructor 0x002e823c : { *ai-startup-menustate.o(.text._ZN5Menus14OptionControlsC1Ev .text._ZN5Menus14OptionControlsC2Ev) }
    .optionControls_name 0x00419ed0 : { *ai-startup-menustate.o(.rodata.optionControlsName) }
    .optionVolumes_constructor 0x002e8280 : { *ai-startup-menustate.o(.text._ZN5Menus13OptionVolumesC1Ev .text._ZN5Menus13OptionVolumesC2Ev) }
    .optionVolumes_name 0x00419e10 : { *ai-startup-menustate.o(.rodata.optionVolumesName) }
    .services_constructor 0x002e82c8 : { *ai-startup-menustate.o(.text._ZN5Menus8ServicesC1EPKc .text._ZN5Menus8ServicesC2EPKc) }
    .serviceCorruption_constructor 0x002e8308 : { *ai-startup-menustate.o(.text._ZN5Menus17ServiceCorruptionC1Ev .text._ZN5Menus17ServiceCorruptionC2Ev) }
    .serviceCorruption_name 0x00419ee0 : { *ai-startup-menustate.o(.rodata.serviceCorruptionName) }
    .serviceMissions_constructor 0x002e8404 : { *ai-startup-menustate.o(.text._ZN5Menus15ServiceMissionsC1Ev .text._ZN5Menus15ServiceMissionsC2Ev) }
    .serviceMissions_name 0x00419e00 : { *ai-startup-menustate.o(.rodata.serviceMissionsName) }
    .tutorial_constructor 0x002e84ec : { *ai-startup-menustate.o(.text._ZN5Menus8TutorialC1EPKc .text._ZN5Menus8TutorialC2EPKc) }
    .menu_fx_state_deleting_destructor 0x002e96bc : { *ai-startup-menustate.o(.text._ZN6MenuFX5StateD0Ev .gnu.linkonce.t._ZN6MenuFX5StateD0Ev) }
    .menu_fx_state_complete_destructor 0x002e96f4 : { *ai-startup-menustate.o(.text._ZN6MenuFX5StateD1Ev .gnu.linkonce.t._ZN6MenuFX5StateD1Ev) }
    .menu_state_deleting_destructor 0x002e9724 : { *ai-startup-menustate.o(.text._ZN9MenuStateD0Ev .gnu.linkonce.t._ZN9MenuStateD0Ev) }
    .menu_state_base_destructor 0x002e9764 : { *ai-startup-menustate.o(.text._ZN9MenuStateD2Ev .gnu.linkonce.t._ZN9MenuStateD2Ev .text._ZN9MenuStateD1Ev .gnu.linkonce.t._ZN9MenuStateD1Ev) }
    .dialog_deleting_destructor 0x002e9874 : { *ai-startup-menustate.o(.text._ZN5Menus6DialogD0Ev .gnu.linkonce.t._ZN5Menus6DialogD0Ev) }
    .dialog_complete_destructor 0x002e989c : { *ai-startup-menustate.o(.text._ZN5Menus6DialogD1Ev .gnu.linkonce.t._ZN5Menus6DialogD1Ev) }
    .confirm_deleting_destructor 0x002e98bc : { *ai-startup-menustate.o(.text._ZN5Menus7ConfirmD0Ev .gnu.linkonce.t._ZN5Menus7ConfirmD0Ev) }
    .confirm_complete_destructor 0x002e98e8 : { *ai-startup-menustate.o(.text._ZN5Menus7ConfirmD1Ev .gnu.linkonce.t._ZN5Menus7ConfirmD1Ev) }
    .confirm_payment_deleting_destructor 0x002e9910 : { *ai-startup-menustate.o(.text._ZN5Menus14ConfirmPaymentD0Ev .gnu.linkonce.t._ZN5Menus14ConfirmPaymentD0Ev) }
    .confirm_payment_complete_destructor 0x002e993c : { *ai-startup-menustate.o(.text._ZN5Menus14ConfirmPaymentD1Ev .gnu.linkonce.t._ZN5Menus14ConfirmPaymentD1Ev) }
    .menu_fx_state_vtable 0x004a9830 : { *ai-startup-menustate.o(.data.rel.ro._ZTVN6MenuFX5StateE .gnu.linkonce.d.rel.ro._ZTVN6MenuFX5StateE) }
    .menu_state_vtable 0x004a9710 : { *ai-startup-menustate.o(.data.rel.ro._ZTV9MenuState .gnu.linkonce.d.rel.ro._ZTV9MenuState) }
    .dialog_vtable 0x004a9098 : { *ai-startup-menustate.o(.data.rel.ro._ZTVN5Menus6DialogE .gnu.linkonce.d.rel.ro._ZTVN5Menus6DialogE) }
    .confirm_vtable 0x004a9050 : { *ai-startup-menustate.o(.data.rel.ro._ZTVN5Menus7ConfirmE .gnu.linkonce.d.rel.ro._ZTVN5Menus7ConfirmE) }
    .confirm_payment_vtable 0x004a9008 : { *ai-startup-menustate.o(.data.rel.ro._ZTVN5Menus14ConfirmPaymentE .gnu.linkonce.d.rel.ro._ZTVN5Menus14ConfirmPaymentE) }
    .menu_fx_state_constructor 0x002e77d0 : { *ai-startup-menustate.o(.text._ZN6MenuFX5StateC1EPKc .text._ZN6MenuFX5StateC2EPKc .gnu.linkonce.t._ZN6MenuFX5StateC1EPKc .gnu.linkonce.t._ZN6MenuFX5StateC2EPKc) }
    .menu_state_constructor 0x002e7d98 : { *ai-startup-menustate.o(.text._ZN9MenuStateC1EPKc .text._ZN9MenuStateC2EPKc) }
    .menu_dialog_constructor 0x002e7e68 : { *ai-startup-menustate.o(.text._ZN5Menus6DialogC1EPKc .text._ZN5Menus6DialogC2EPKc) }
    .confirm_constructor 0x002e7e8c : { *ai-startup-menustate.o(.text._ZN5Menus7ConfirmC1EPKc .text._ZN5Menus7ConfirmC2EPKc) }
    .confirm_payment_constructor 0x002ea220 : { *ai-startup-menustate.o(.text._ZN5Menus14ConfirmPaymentC1EPKc .text._ZN5Menus14ConfirmPaymentC2EPKc) }
    .confirm_notify 0x002e7590 : { *ai-startup-menustate.o(.text._ZN5Menus7Confirm6NotifyEPK10MenuWidgeti) }
    .dialog_got_focus 0x002e8878 : { *ai-startup-menustate.o(.text._ZN5Menus6Dialog8GotFocusEv) }
    .confirm_got_focus 0x002e8898 : { *ai-startup-menustate.o(.text._ZN5Menus7Confirm8GotFocusEv) }
    .dialog_lost_focus 0x002e92b0 : { *ai-startup-menustate.o(.text._ZN5Menus6Dialog9LostFocusEv) }
    .state_create 0x002e7310 : { *ai-startup-menustate.o(.text._ZN6MenuFX5State6CreateEv) }
    .state_show 0x002e7314 : { *ai-startup-menustate.o(.text._ZN6MenuFX5State4ShowEv) }
    .state_hide 0x002e7318 : { *ai-startup-menustate.o(.text._ZN6MenuFX5State4HideEv) }
    .state_got_focus 0x002e731c : { *ai-startup-menustate.o(.text._ZN6MenuFX5State8GotFocusEv) }
    .state_lost_focus 0x002e7320 : { *ai-startup-menustate.o(.text._ZN6MenuFX5State9LostFocusEv) }
    .state_update 0x002e7324 : { *ai-startup-menustate.o(.text._ZN6MenuFX5State6UpdateEv) }
    .state_update_elapsed 0x002e7328 : { *ai-startup-menustate.o(.text._ZN6MenuFX5State6UpdateEi) }
    .state_on_event 0x002e7338 : { *ai-startup-menustate.o(.text._ZN6MenuFX5State7OnEventERN8RenderFX5EventE) }
    .state_on_fs_command 0x002e733c : { *ai-startup-menustate.o(.text._ZN6MenuFX5State11OnFSCommandEPKcS2_) }
    .state_can_handle_event 0x002e7340 : { *ai-startup-menustate.o(.text._ZN6MenuFX5State14CanHandleEventERN8RenderFX5EventE) }
    .menu_state_is_modal 0x002e7344 : { *ai-startup-menustate.o(.text._ZNK9MenuState7IsModalEv) }
    .confirm_is_modal 0x002e7348 : { *ai-startup-menustate.o(.text._ZNK5Menus7Confirm7IsModalEv) }
    .menu_state_notify 0x002e734c : { *ai-startup-menustate.o(.text._ZN9MenuState6NotifyEPK10MenuWidgeti) }
    .menu_state_get_depth 0x002e7350 : { *ai-startup-menustate.o(.text._ZNK9MenuState8GetDepthEv) }
    .menu_state_update 0x002e9510 : { *ai-startup-menustate.o(.text._ZN9MenuState6UpdateEv) }
    .menu_state_create 0x002e9514 : { *ai-startup-menustate.o(.text._ZN9MenuState6CreateEv) }
    .confirm_confirmed 0x002e7384 : { *ai-startup-menustate.o(.text._ZNK5Menus7Confirm9ConfirmedEv) }
    .confirm_payment_get_widget 0x002e7414 : { *ai-startup-menustate.o(.text._ZN5Menus14ConfirmPayment9GetWidgetEv) }
    .confirm_get_widget 0x002e7438 : { *ai-startup-menustate.o(.text._ZN5Menus7Confirm9GetWidgetEv) }
    .confirm_payment_set_price 0x002e8528 : { *ai-startup-menustate.o(.text._ZN5Menus14ConfirmPayment8SetPriceEi) }
    .menu_dialog_set_message 0x002e75dc : { *ai-startup-menustate.o(.text._ZN5Menus6Dialog10SetMessageEi) }
    .state_machine_singleton 0x002d44c4 : { *ai-startup-menustate.o(.gnu.linkonce.t._ZN12StateMachine11getInstanceEv) }
    .state_machine_cleanup 0x002e745c : { *ai-startup-menustate.o(.text.__tcf_1) }
    .state_machine_guard 0x004b6904 (NOLOAD) : { *ai-startup-menustate.o(.gnu.linkonce.b._ZGVZN12StateMachine11getInstanceEvE2sm) }
    .state_machine_instance 0x004b6908 (NOLOAD) : { *ai-startup-menustate.o(.gnu.linkonce.b._ZZN12StateMachine11getInstanceEvE2sm) }
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
    .menu_cheat_activation_zones 0x004b7170 (NOLOAD) : { *menu-manager-helpers.o(.bss._ZN11MenuManager22s_cheatActivationZonesE) }
    .map_singleton 0x002dbb58 : { *menu-manager-helpers.o(.gnu.linkonce.t._ZN3Map11getInstanceEv) }
    .map_cleanup 0x002e425c : { *menu-manager-helpers.o(.text.__tcf_0) }
    .map_guard 0x004b6a94 (NOLOAD) : { *menu-manager-helpers.o(.gnu.linkonce.b._ZGVZN3Map11getInstanceEvE3map) }
    .map_instance 0x004b6b00 (NOLOAD) : { *menu-manager-helpers.o(.gnu.linkonce.b._ZZN3Map11getInstanceEvE3map) }
    /* Retail merges preloadGlyphs' "rb" with RenderFX's read mode at 0x004014f0; this image places only
       RenderFX's copy there and gives the unchecked MenuManager duplicate a non-retail home. */
    /* Retail shares "Map" (0x0040b608) between MenuState and Widgets::Mission; this image checks MenuState's copy. */
    .menu_widget_duplicate_map_name 0x00700010 : { *ai-startup-menuwidget.o(.rodata.missionMapName) }
    .menu_manager_duplicate_read_mode 0x00700000 : { *menu-manager-helpers.o(.rodata.preloadBinaryMode) }
    /DISCARD/ : { *ai-startup-menuwidget.o(*) *menu-manager-helpers.o(*) }
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

INCLUDE config/linker/RenderFXUtilitySections.ld

INCLUDE config/linker/JNIGangstarBrowserSections.ld
ASSERT(SIZEOF(.gangstar_class)==4,"JNI Gangstar class cache extent");
ASSERT(SIZEOF(.gangstar_browser_method)==4,"JNI browser method cache extent");

ASSERT(SIZEOF(.gangstar_notify_method)==4,"JNI notify method cache extent");

ASSERT(SIZEOF(.gangstar_exit_method)==4,"JNI exit method cache extent");

ASSERT(SIZEOF(.gangstar_phone_method)==4,"JNI phone method cache extent");

ASSERT(SIZEOF(.gangstar_unlock_method)==4,"JNI unlock method cache extent");

ASSERT(SIZEOF(.gangstar_version_method)==4,"JNI version method cache extent");

ASSERT(SIZEOF(.gangstar_launch_method)==4,"JNI launch method cache extent");

ASSERT(SIZEOF(.menu_state_hide) == 104, "MenuState Hide native104B extent");

ASSERT(SIZEOF(.renderfx_collect_characters) == 240, "native CollectCharacters dependency span");

printf = 0x001c4058;
puts = 0x001c41b4;
ASSERT(SIZEOF(.renderfx_trace_context) == 124, "native TraceContext strict span");
ASSERT(SIZEOF(.renderfx_found_child) == 24, "native found-child format extent");
ASSERT(SIZEOF(.renderfx_child_sprite) == 24, "native child-sprite text extent");

ASSERT(SIZEOF(.set_character_focus) == 356, "SetFocus native356 exact extent");

INCLUDE config/linker/RenderFXSetMemberValue.ld


ASSERT(SIZEOF(.can_handle_mouse) == 92, "CanHandleMouse native92 exact extent");
ASSERT(SIZEOF(.event_character_path) == 192, "Native RenderFX Event GetCharacterPath extent");
