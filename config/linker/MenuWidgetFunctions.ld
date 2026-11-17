strstr = 0x001c446c;
PROVIDE(strcpy = 0x001c3fd4);
PROVIDE(strcat = 0x001c43a0);
PROVIDE(__aeabi_i2f = 0x001c41e4);
PROVIDE(__aeabi_fdiv = 0x001c4520);
PROVIDE(__aeabi_fadd = 0x001c4154);
PROVIDE(__aeabi_f2iz = 0x001c44cc);
PROVIDE(__aeabi_idiv = 0x001c43dc);
PROVIDE(__aeabi_fsub = 0x001c4328);
PROVIDE(__aeabi_fcmpgt = 0x001c419c);
PROVIDE(__aeabi_fcmplt = 0x001c479c);
SECTIONS
{
    .volumesButton 0x0041b628 : { *ai-startup-menuwidget.o(.rodata.volumesButton) }
    .volumesMuteButton 0x0041b648 : { *ai-startup-menuwidget.o(.rodata.volumesMuteButton) }
    .volumesSfxPart 0x0041b634 : { *ai-startup-menuwidget.o(.rodata.volumesSfxPart) }
    .volumesMusicPart 0x0041b63c : { *ai-startup-menuwidget.o(.rodata.volumesMusicPart) }
    .volumesLeftButton 0x0041b5fc : { *ai-startup-menuwidget.o(.rodata.volumesLeftButton) }
    .volumesRightButton 0x0041b604 : { *ai-startup-menuwidget.o(.rodata.volumesRightButton) }
    .widget_volumes_event 0x002eff18 : { *ai-startup-menuwidget.o(.text._ZN7Widgets7Volumes7OnEventERN8RenderFX5EventE) }
    .widget_mainmenu_vtable 0x004a9868 : { *ai-startup-menuwidget.o(.data.rel.ro._ZTVN7Widgets8MainMenuE) }
    .widget_volumes_vtable 0x004a99d0 : { *ai-startup-menuwidget.o(.data.rel.ro._ZTVN7Widgets7VolumesE) }
    .widget_arrows_vtable 0x004a9a98 : { *ai-startup-menuwidget.o(.data.rel.ro._ZTVN7Widgets6ArrowsE) }
    .widget_mainmenu_event 0x002ef9fc : { *ai-startup-menuwidget.o(.text._ZN7Widgets8MainMenu7OnEventERN8RenderFX5EventE) }
    .widget_volumes_show 0x002f01c4 : { *ai-startup-menuwidget.o(.text._ZN7Widgets7Volumes4ShowEv) }
    .widget_arrows_event 0x002f0248 : { *ai-startup-menuwidget.o(.text._ZN7Widgets6Arrows7OnEventERN8RenderFX5EventE) }
    .main_button_prefix 0x0041b5d8 : { *ai-startup-menuwidget.o(.rodata.mainButtonPrefix) }
    .main_twitter_button 0x0041b5e0 : { *ai-startup-menuwidget.o(.rodata.mainTwitterButton) }
    .main_info_button 0x0041b5ec : { *ai-startup-menuwidget.o(.rodata.mainInfoButton) }
    .main_more_button 0x0041b5f4 : { *ai-startup-menuwidget.o(.rodata.mainMoreButton) }
    .widget_volumes_playlist_path 0x0041b650 : { *ai-startup-menuwidget.o(.rodata.volumesPlaylistPath) }
    .widget_arrow_left_label 0x0041b668 : { *ai-startup-menuwidget.o(.rodata.arrowLeftLabel) }
    .widget_arrow_right_label 0x0041b678 : { *ai-startup-menuwidget.o(.rodata.arrowRightLabel) }
    .widget_achievements_event 0x002eeda0 : { *ai-startup-menuwidget.o(.text._ZN7Widgets12Achievements7OnEventERN8RenderFX5EventE) }
    .widget_statistics_localization 0x002ee2c0 : { *ai-startup-menuwidget.o(.text._ZN7Widgets10Statistics18UpdateLocalizationEv) }
    .widget_statistics_entry_format 0x0041b0e0 : { *ai-startup-menuwidget.o(.rodata.statisticsEntryFormat) }
    .widget_statistics_event 0x002eec14 : { *ai-startup-menuwidget.o(.text._ZN7Widgets10Statistics7OnEventERN8RenderFX5EventE) }
    .widget_confirm_payment_vtable 0x004a9b40 : { *ai-startup-menuwidget.o(.data.rel.ro._ZTVN7Widgets14ConfirmPaymentE) }
    .widget_volumes_hide 0x002ecd98 : { *ai-startup-menuwidget.o(.text._ZN7Widgets7Volumes4HideEb) }
    .widget_confirm_payment_localization 0x002edfbc : { *ai-startup-menuwidget.o(.text._ZN7Widgets14ConfirmPayment18UpdateLocalizationEv) }
    .widget_confirm_payment_format 0x0041afd0 : { *ai-startup-menuwidget.o(.rodata.confirmPaymentFormat) }
    .widget_confirm_payment_message 0x0041aff4 : { *ai-startup-menuwidget.o(.rodata.confirmPaymentMessagePath) }
    .widget_demobuy_vtable 0x004a9a20 : { *ai-startup-menuwidget.o(.data.rel.ro._ZTVN7Widgets7DemoBuyE) }
    .widget_corruption_event 0x002ed138 : { *ai-startup-menuwidget.o(.text._ZN7Widgets10Corruption7OnEventERN8RenderFX5EventE) }
    .widget_demobuy_event 0x002ed1c4 : { *ai-startup-menuwidget.o(.text._ZN7Widgets7DemoBuy7OnEventERN8RenderFX5EventE) }
    .widget_demobuy_localization 0x002ed808 : { *ai-startup-menuwidget.o(.text._ZN7Widgets7DemoBuy18UpdateLocalizationEv) }
    .widget_blocking_tutorial_event 0x002eebc4 : { *ai-startup-menuwidget.o(.text._ZN7Widgets16BlockingTutorial7OnEventERN8RenderFX5EventE) }
    .widget_tutorial_event 0x002ee978 : { *ai-startup-menuwidget.o(.text._ZN7Widgets8Tutorial7OnEventERN8RenderFX5EventE) }
    .widget_igmenu_event 0x002edd6c : { *ai-startup-menuwidget.o(.text._ZN7Widgets6IGMenu7OnEventERN8RenderFX5EventE) }
    .corrupt_button_name 0x0041ab24 : { *ai-startup-menuwidget.o(.rodata.corruptButtonName) }
    .demobuy_confirm_button 0x0041ab38 : { *ai-startup-menuwidget.o(.rodata.demoBuyConfirmButtonName) }
    .menu_back_button 0x0041ab40 : { *ai-startup-menuwidget.o(.rodata.menuBackButtonName) }
    .demobuy_confirm_text 0x0041acd8 : { *ai-startup-menuwidget.o(.rodata.demoBuyConfirmText) }
    .demobuy_back_text 0x0041acf0 : { *ai-startup-menuwidget.o(.rodata.demoBuyBackText) }
    .demobuy_description_0 0x0041ad08 : { *ai-startup-menuwidget.o(.rodata.demoBuyDescription0) }
    .demobuy_description_1 0x0041ad24 : { *ai-startup-menuwidget.o(.rodata.demoBuyDescription1) }
    .tutorial_ok_button 0x0041b018 : { *ai-startup-menuwidget.o(.rodata.tutorialOkButton) }
    .tutorial_close_button_label 0x0041b03c : { *ai-startup-menuwidget.o(.rodata.tutorialCloseButtonLabel) }
    .tutorial_scroll_button_label 0x0041b2d0 : { *ai-startup-menuwidget.o(.rodata.tutorialScrollButtonLabel) }
    .tutorial_part_format 0x00419e70 : { *ai-startup-menuwidget.o(.rodata.tutorialPartFormat) }
    .tutorial_scroll_part 0x0041b2dc : { *ai-startup-menuwidget.o(.rodata.tutorialScrollPart) }
    .tutorial_arrow_up_part 0x0041b2f0 : { *ai-startup-menuwidget.o(.rodata.tutorialArrowUpPart) }
    .tutorial_arrow_down_part 0x0041b300 : { *ai-startup-menuwidget.o(.rodata.tutorialArrowDownPart) }
    .igmenu_button_name 0x0041af50 : { *ai-startup-menuwidget.o(.rodata.igMenuButtonName) }
    .widget_corruption_vtable 0x004a9980 : { *ai-startup-menuwidget.o(.data.rel.ro._ZTVN7Widgets10CorruptionE) }
    .widget_maplegend_localization 0x002edb60 : { *ai-startup-menuwidget.o(.text._ZN7Widgets9MapLegend18UpdateLocalizationEv) }
    .widget_maplegend_row_text 0x0041ae90 : { *ai-startup-menuwidget.o(.rodata.mapLegendRowLabelFormat) }
    .widget_maplegend_button_text 0x0041aeac : { *ai-startup-menuwidget.o(.rodata.mapLegendButtonText) }
    .widget_about_localization 0x002ed458 : { *ai-startup-menuwidget.o(.text._ZN7Widgets5About18UpdateLocalizationEv) }
    .widget_about_event 0x002ee810 : { *ai-startup-menuwidget.o(.text._ZN7Widgets5About7OnEventERN8RenderFX5EventE) }
    .widget_maplegend_ctor 0x002ec820 : { *ai-startup-menuwidget.o(.text._ZN7Widgets9MapLegendC1Ev .text._ZN7Widgets9MapLegendC2Ev) }
    .widget_maplegend_show 0x002ecf0c : { *ai-startup-menuwidget.o(.text._ZN7Widgets9MapLegend4ShowEv) }
    .widget_about_version_token 0x0041abcc : { *ai-startup-menuwidget.o(.rodata.aboutVersionToken) }
    .widget_about_version_format 0x0041abd0 : { *ai-startup-menuwidget.o(.rodata.aboutVersionFormat) }
    .about_text_button 0x0041b2c4 : { *ai-startup-menuwidget.o(.rodata.aboutTextButtonName) }
    .widget_maplegend_name 0x0041a91c : { *ai-startup-menuwidget.o(.rodata.widgetMapLegendName) }
    .widget_maplegend_button 0x0041aaa8 : { *ai-startup-menuwidget.o(.rodata.mapLegendButton) }
    .widget_maplegend_vtable 0x004a9ac0 : { *ai-startup-menuwidget.o(.data.rel.ro._ZTVN7Widgets9MapLegendE) }
    .widget_about_ctor 0x002ec564 : { *ai-startup-menuwidget.o(.text._ZN7Widgets5AboutC1Ev .text._ZN7Widgets5AboutC2Ev) }
    .widget_about_show 0x002ece94 : { *ai-startup-menuwidget.o(.text._ZN7Widgets5About4ShowEv) }
    .widget_about_name 0x0041a858 : { *ai-startup-menuwidget.o(.rodata.aboutWidgetName) }
    .widget_about_credit_format 0x0041a864 : { *ai-startup-menuwidget.o(.rodata.aboutCreditFormat) }
    .widget_about_anim_text 0x0041aa84 : { *ai-startup-menuwidget.o(.rodata.aboutAnimationName) }
    .widget_about_vtable 0x004a98e0 : { *ai-startup-menuwidget.o(.data.rel.ro._ZTVN7Widgets5AboutE) }
    .widget_about_disable 0x002ef040 : { *ai-startup-menuwidget.o(.text._ZN7Widgets5About7DisableEv) }
    .widget_about_update 0x002ebf34 : { *ai-startup-menuwidget.o(.text._ZN7Widgets5About6UpdateEb) }
    .widget_about_enable 0x002ed11c : { *ai-startup-menuwidget.o(.text._ZN7Widgets5About6EnableEv) }
    .widget_shop_set_item 0x002ecb20 : { *ai-startup-menuwidget.o(.text._ZN7Widgets4Shop7SetItemEiiiPKci) }
    .widget_shop_item_icon_format 0x0041a9bc : { *ai-startup-menuwidget.o(.rodata.shop_item_icon_format) }
    .widget_shop_localization 0x002ed6bc : { *ai-startup-menuwidget.o(.text._ZN7Widgets4Shop18UpdateLocalizationEv) }
    .shop_button_path 0x0041ac58 : { *ai-startup-menuwidget.o(.rodata.shop_button_path) }
    .shop_name_path 0x0041ac70 : { *ai-startup-menuwidget.o(.rodata.shop_name_path) }
    .shop_price_path 0x0041ac90 : { *ai-startup-menuwidget.o(.rodata.shop_price_path) }
    .shop_availability_path 0x0041acb0 : { *ai-startup-menuwidget.o(.rodata.shop_availability_path) }
    .widget_shop_on_event 0x002ed17c : { *ai-startup-menuwidget.o(.text._ZN7Widgets4Shop7OnEventERN8RenderFX5EventE) }
    .widget_shop_vtable 0x004a99f8 : { *ai-startup-menuwidget.o(.data.rel.ro._ZTVN7Widgets4ShopE) }
    .widget_shop_item_button_prefix 0x0041ab30 : { *ai-startup-menuwidget.o(.rodata.*shopItemButtonPrefix*) }
    .widget_shop_availability 0x002ebf08 : { *ai-startup-menuwidget.o(.text._ZN7Widgets4Shop19SetAvailabilityTextEi) }
    .widget_shop_selected_item 0x002ebf0c : { *ai-startup-menuwidget.o(.text._ZNK7Widgets4Shop15GetSelectedItemEv) }
    .widget_shop_ctor 0x002eef44 : { *ai-startup-menuwidget.o(.text._ZN7Widgets4ShopC1Ev .text._ZN7Widgets4ShopC2Ev) }
    .widget_shop_name 0x0041b314 : { *ai-startup-menuwidget.o(.rodata.widget_shop_name) }
    .widget_shop_reset 0x002eef24 : { *ai-startup-menuwidget.o(.text._ZN7Widgets4Shop5ResetEv) }
    .widget_money_localization 0x002edaf0 : { *ai-startup-menuwidget.o(.text._ZN7Widgets5Money18UpdateLocalizationEv) }
    .widget_blocking_tutorial_localization 0x002ef8c4 : { *ai-startup-menuwidget.o(.text._ZN7Widgets16BlockingTutorial18UpdateLocalizationEv) }
    .widget_money_label 0x0041ae58 : { *ai-startup-menuwidget.o(.rodata.widgetMoneyLabel) }
    .widget_money_amount 0x0041ae74 : { *ai-startup-menuwidget.o(.rodata.widgetMoneyAmount) }
    .widget_blocking_tutorial_ok_text 0x0041b5b4 : { *ai-startup-menuwidget.o(.rodata.blockingTutorialOkText) }
    .widget_title_text_id 0x002ebe6c : { *ai-startup-menuwidget.o(.text._ZN7Widgets5Title9SetTextIdEi) }
    .widget_title_localization 0x002ec0dc : { *ai-startup-menuwidget.o(.text._ZN7Widgets5Title18UpdateLocalizationEv) }
    .widget_arrows_localization 0x002ecc14 : { *ai-startup-menuwidget.o(.text._ZN7Widgets6Arrows18UpdateLocalizationEv) }
    .widget_arrows_text 0x0041aa24 : { *ai-startup-menuwidget.o(.rodata.widgetArrowsText) }
    .widget_arrows_page_format 0x0041aa38 : { *ai-startup-menuwidget.o(.rodata.widgetArrowsPageFormat) }
    .widget_title_text 0x0041a6e4 : { *ai-startup-menuwidget.o(.rodata.widgetTitleText) }
    .widget_help_text_id 0x002ebf30 : { *ai-startup-menuwidget.o(.text._ZN7Widgets4Help9SetTextIdEi) }
    .widget_game_setting_selection 0x002ec270 : { *ai-startup-menuwidget.o(.text._ZN7Widgets11GameSetting13ShowSelectionEv) }
    .widget_game_setting_ok 0x002ed5cc : { *ai-startup-menuwidget.o(.text._ZN7Widgets11GameSetting12ShowButtonOkEv) }
    .widget_game_setting_left_button 0x0041a750 : { *ai-startup-menuwidget.o(.rodata.gameSettingLeftButton) }
    .widget_game_setting_right_button 0x0041a76c : { *ai-startup-menuwidget.o(.rodata.gameSettingRightButton) }
    .widget_game_setting_selection_background 0x0041a788 : { *ai-startup-menuwidget.o(.rodata.gameSettingSelectionBackground) }
    .widget_game_setting_ok_button 0x0041a738 : { *ai-startup-menuwidget.o(.rodata.gameSettingOkButton) }
    .widget_game_setting_ok_text 0x0041abec : { *ai-startup-menuwidget.o(.rodata.gameSettingOkText) }
    .widget_game_setting_hidebuttonok 0x002ec1fc : { *ai-startup-menuwidget.o(.text._ZN7Widgets11GameSetting12HideButtonOkEv) }
    .widget_game_setting_hideselection 0x002ec21c : { *ai-startup-menuwidget.o(.text._ZN7Widgets11GameSetting13HideSelectionEv) }
    .widget_game_setting_settitleid 0x002ebf28 : { *ai-startup-menuwidget.o(.text._ZN7Widgets11GameSetting10SetTitleIdEi) }
    .widget_game_setting_setvalueid 0x002ebf2c : { *ai-startup-menuwidget.o(.text._ZN7Widgets11GameSetting10SetValueIdEi) }
    .widget_game_setting_setvalue 0x002ec08c : { *ai-startup-menuwidget.o(.text._ZN7Widgets11GameSetting8SetValueEPKc) }
    .widget_game_setting_settitle 0x002ec0b4 : { *ai-startup-menuwidget.o(.text._ZN7Widgets11GameSetting8SetTitleEPKc) }
    .widget_help_localization 0x002ed540 : { *ai-startup-menuwidget.o(.text._ZN7Widgets4Help18UpdateLocalizationEv) }
    .widget_game_setting_localization 0x002ed574 : { *ai-startup-menuwidget.o(.text._ZN7Widgets11GameSetting18UpdateLocalizationEv) }
    .widget_help_text_path 0x0041abdc : { *ai-startup-menuwidget.o(.rodata.helpTextPath) }
    .widget_game_setting_title_path 0x0041a6c8 : { *ai-startup-menuwidget.o(.rodata.gameSettingTitlePath) }
    .widget_game_setting_value_path 0x0041a6ac : { *ai-startup-menuwidget.o(.rodata.gameSettingValuePath) }
    .widget_help_vtable 0x004a9908 : { *ai-startup-menuwidget.o(.data.rel.ro._ZTVN7Widgets4HelpE) }
    .widget_language_show 0x002ed6a0 : { *ai-startup-menuwidget.o(.text._ZN7Widgets8Language4ShowEv) }
    .widget_controls_show 0x002eced4 : { *ai-startup-menuwidget.o(.text._ZN7Widgets8Controls4ShowEv) }
    .widget_language_localization 0x002ed614 : { *ai-startup-menuwidget.o(.text._ZN7Widgets8Language18UpdateLocalizationEv) }
    .widget_language_vtable 0x004a9958 : { *ai-startup-menuwidget.o(.data.rel.ro._ZTVN7Widgets8LanguageE) }
    .widget_controls_vtable 0x004a99a8 : { *ai-startup-menuwidget.o(.data.rel.ro._ZTVN7Widgets8ControlsE) }
    .widget_language_title 0x0041ac0c : { *ai-startup-menuwidget.o(.rodata.languageTitlePath) }
    .widget_language_value 0x0041ac24 : { *ai-startup-menuwidget.o(.rodata.languageValuePath) }
    .widget_language_ok 0x0041ac3c : { *ai-startup-menuwidget.o(.rodata.languageOkPath) }
    .widget_language_ids 0x0041b6b0 : { *ai-startup-menuwidget.o(.rodata._ZN7Widgets8Language13s_languageIdsE) }
    .widget_tutorial_show 0x002ed024 : { *ai-startup-menuwidget.o(.text._ZN7Widgets8Tutorial4ShowEv) }
    .widget_blocking_tutorial_show 0x002ed060 : { *ai-startup-menuwidget.o(.text._ZN7Widgets16BlockingTutorial4ShowEv) }
    .widget_tutorial_vtable 0x004a9c08 : { *ai-startup-menuwidget.o(.data.rel.ro._ZTVN7Widgets8TutorialE) }
    .widget_blocking_tutorial_vtable 0x004a9be0 : { *ai-startup-menuwidget.o(.data.rel.ro._ZTVN7Widgets16BlockingTutorialE) }
    .widget_blocking_tutorial_close_button 0x0041ab04 : { *ai-startup-menuwidget.o(.rodata.blockingTutorialCloseButton) }
    .widget_objective_show 0x002ecf78 : { *ai-startup-menuwidget.o(.text._ZN7Widgets9Objective4ShowEv) }
    .widget_objective_vtable 0x004a9ae8 : { *ai-startup-menuwidget.o(.data.rel.ro._ZTVN7Widgets9ObjectiveE) }
    .widget_objective_open 0x0041aa98 : { *ai-startup-menuwidget.o(.rodata.objectiveOpen) }
    .widget_objective_close 0x0041aaa0 : { *ai-startup-menuwidget.o(.rodata.objectiveClose) }
    .widget_objective_button 0x0041aac4 : { *ai-startup-menuwidget.o(.rodata.objectiveButton) }
    .widget_objective_up 0x00406164 : { *ai-startup-menuwidget.o(.rodata.objectiveArrowUp) }
    .widget_objective_down 0x0041aae4 : { *ai-startup-menuwidget.o(.rodata.objectiveArrowDown) }
    .widget_objective_arrow 0x0041aaec : { *ai-startup-menuwidget.o(.rodata.objectiveArrow) }
    .widget_achievement_localization 0x002ede5c : { *ai-startup-menuwidget.o(.text._ZN7Widgets11Achievement18UpdateLocalizationEv) }
    .widget_objective_localization 0x002edc1c : { *ai-startup-menuwidget.o(.text._ZN7Widgets9Objective18UpdateLocalizationEv) }
    .widget_achievement_caption 0x0041af58 : { *ai-startup-menuwidget.o(.rodata.achievementCaptionPath) }
    .widget_achievement_title 0x0041af80 : { *ai-startup-menuwidget.o(.rodata.achievementTitlePath) }
    .widget_objective_text_path 0x0041aecc : { *ai-startup-menuwidget.o(.rodata.objectiveTextPath) }
    .widget_objective_button_path 0x0041aee4 : { *ai-startup-menuwidget.o(.rodata.objectiveButtonPath) }
    .widget_achievements_show 0x002ece58 : { *ai-startup-menuwidget.o(.text._ZN7Widgets12Achievements4ShowEv) }
    .widget_achievements_vtable 0x004a98b8 : { *ai-startup-menuwidget.o(.data.rel.ro._ZTVN7Widgets12AchievementsE) }
    .widget_statistics_update 0x002ebfc4 : { *ai-startup-menuwidget.o(.text._ZN7Widgets10Statistics6UpdateEb) }
    .widget_achievements_update 0x002ebf78 : { *ai-startup-menuwidget.o(.text._ZN7Widgets12Achievements6UpdateEb) }
    .widget_achievements_reset 0x002ec3b4 : { *ai-startup-menuwidget.o(.text._ZN7Widgets12Achievements5ResetEv) }
    .widget_statistics_disable 0x002eeff8 : { *ai-startup-menuwidget.o(.text._ZN7Widgets10Statistics7DisableEv) }
    .widget_achievements_disable 0x002ef01c : { *ai-startup-menuwidget.o(.text._ZN7Widgets12Achievements7DisableEv) }
    .widget_statistics_enable 0x002ed0f0 : { *ai-startup-menuwidget.o(.text._ZN7Widgets10Statistics6EnableEv) }
    .widget_achievements_enable 0x002ed10c : { *ai-startup-menuwidget.o(.text._ZN7Widgets12Achievements6EnableEv) }
    .widget_statistics_ctor 0x002ec49c : { *ai-startup-menuwidget.o(.text._ZN7Widgets10StatisticsC1Ev .text._ZN7Widgets10StatisticsC2Ev) }
    .widget_achievements_ctor 0x002ec504 : { *ai-startup-menuwidget.o(.text._ZN7Widgets12AchievementsC1Ev .text._ZN7Widgets12AchievementsC2Ev) }
    .widget_objective_ctor 0x002ec878 : { *ai-startup-menuwidget.o(.text._ZN7Widgets9ObjectiveC1Ev .text._ZN7Widgets9ObjectiveC2Ev) }
    .widget_achievement_ctor 0x002ec9b0 : { *ai-startup-menuwidget.o(.text._ZN7Widgets11AchievementC1Ev .text._ZN7Widgets11AchievementC2Ev) }
    .widget_achievement_set_title 0x002ebe78 : { *ai-startup-menuwidget.o(.text._ZN7Widgets11Achievement8SetTitleEi) }
    .widget_achievement_auto_hide 0x002ebe7c : { *ai-startup-menuwidget.o(.text._ZNK7Widgets11Achievement8AutoHideEv) }
    .widget_objective_set_text 0x002ebe98 : { *ai-startup-menuwidget.o(.text._ZN7Widgets9Objective16SetObjectiveTextEi) }
    .widget_statistics_name 0x0041a7f8 : { *ai-startup-menuwidget.o(.rodata.widgetStatisticsName) }
    .widget_statistics_anim 0x0041a80c : { *ai-startup-menuwidget.o(.rodata.widgetStatisticsAnimation) }
    .widget_achievements_name 0x0041a824 : { *ai-startup-menuwidget.o(.rodata.widgetAchievementsName) }
    .widget_achievements_anim 0x0041a838 : { *ai-startup-menuwidget.o(.rodata.widgetAchievementsAnimation) }
    .widget_objective_name 0x0041a92c : { *ai-startup-menuwidget.o(.rodata.widgetObjectiveName) }
    .widget_achievement_name 0x0041a95c : { *ai-startup-menuwidget.o(.rodata.widgetAchievementName) }
    .widget_achievement_vtable 0x004a9bb8 : { *ai-startup-menuwidget.o(.data.rel.ro._ZTVN7Widgets11AchievementE) }
    .widget_background_demo_buy_ctor 0x002ec738 : { *ai-startup-menuwidget.o(.text._ZN7Widgets17BackgroundDemoBuyC1Ev .text._ZN7Widgets17BackgroundDemoBuyC2Ev) }
    .widget_demo_buy_ctor 0x002ec764 : { *ai-startup-menuwidget.o(.text._ZN7Widgets7DemoBuyC1Ev .text._ZN7Widgets7DemoBuyC2Ev) }
    .widget_tutorial_ctor 0x002ec9e4 : { *ai-startup-menuwidget.o(.text._ZN7Widgets8TutorialC1EPKc .text._ZN7Widgets8TutorialC2EPKc) }
    .widget_blocking_tutorial_ctor 0x002eca1c : { *ai-startup-menuwidget.o(.text._ZN7Widgets16BlockingTutorialC1Ev .text._ZN7Widgets16BlockingTutorialC2Ev) }
    .widget_background_main_menu_ctor 0x002ecaa8 : { *ai-startup-menuwidget.o(.text._ZN7Widgets18BackgroundMainMenuC1Ev .text._ZN7Widgets18BackgroundMainMenuC2Ev) }
    .widget_tutorial_cursor_pressed 0x002ebe70 : { *ai-startup-menuwidget.o(.text._ZNK7Widgets8Tutorial15IsCursorPressedEv) }
    .widget_bg_main_name 0x0041a8d4 : { *ai-startup-menuwidget.o(.rodata.widgetBGMainName) }
    .widget_buy_name 0x0041a8e4 : { *ai-startup-menuwidget.o(.rodata.widgetBuyName) }
    .widget_tuto_block_name 0x0041a970 : { *ai-startup-menuwidget.o(.rodata.widgetTutoBlockName) }
    .widget_background_demo_buy_vtable 0x004a9cd0 : { *ai-startup-menuwidget.o(.gnu.linkonce.d.rel.ro._ZTVN7Widgets17BackgroundDemoBuyE) }
    .widget_background_main_menu_vtable 0x004a9d20 : { *ai-startup-menuwidget.o(.gnu.linkonce.d.rel.ro._ZTVN7Widgets18BackgroundMainMenuE) }
    .widget_help_ctor 0x002ec608 : { *ai-startup-menuwidget.o(.text._ZN7Widgets4HelpC1Ev .text._ZN7Widgets4HelpC2Ev) }
    .widget_help_name 0x0041a870 : { *ai-startup-menuwidget.o(.rodata.widgetHelpName) }
    .widget_game_setting_ctor 0x002ec63c : { *ai-startup-menuwidget.o(.text._ZN7Widgets11GameSettingC1Ev .text._ZN7Widgets11GameSettingC2Ev) }
    .widget_game_setting_name 0x0041a87c : { *ai-startup-menuwidget.o(.rodata.widgetGameSettingName) }
    .widget_language_ctor 0x002ec670 : { *ai-startup-menuwidget.o(.text._ZN7Widgets8LanguageC1Ev .text._ZN7Widgets8LanguageC2Ev) }
    .widget_language_name 0x0041a890 : { *ai-startup-menuwidget.o(.rodata.widgetLanguageName) }
    .widget_corruption_ctor 0x002ec6a0 : { *ai-startup-menuwidget.o(.text._ZN7Widgets10CorruptionC1Ev .text._ZN7Widgets10CorruptionC2Ev) }
    .widget_corruption_name 0x0041a8a0 : { *ai-startup-menuwidget.o(.rodata.widgetCorruptionName) }
    .widget_controls_ctor 0x002ec6d0 : { *ai-startup-menuwidget.o(.text._ZN7Widgets8ControlsC1Ev .text._ZN7Widgets8ControlsC2Ev) }
    .widget_controls_name 0x0041a8b4 : { *ai-startup-menuwidget.o(.rodata.widgetControlsName) }
    .widget_volumes_ctor 0x002ec704 : { *ai-startup-menuwidget.o(.text._ZN7Widgets7VolumesC1Ev .text._ZN7Widgets7VolumesC2Ev) }
    .widget_volumes_name 0x0041a8c4 : { *ai-startup-menuwidget.o(.rodata.widgetVolumesName) }
    .widget_ig_pressed 0x002ebe94 : { *ai-startup-menuwidget.o(.text._ZNK7Widgets6IGMenu20GetLastPressedButtonEv) }
    .widget_black_box_ctor 0x002ec908 : { *ai-startup-menuwidget.o(.text._ZN7Widgets8BlackBoxC1Ev .text._ZN7Widgets8BlackBoxC2Ev) }
    .widget_black_box_set_state 0x002ecd0c : { *ai-startup-menuwidget.o(.text._ZN7Widgets8BlackBox8SetStateENS0_6eStateE) }
    .widget_black_box_name 0x0041a94c : { *ai-startup-menuwidget.o(.rodata.widgetBlackBoxName) }
    .widget_black_box_thin 0x0041aa64 : { *ai-startup-menuwidget.o(.rodata.blackBoxThinAnimation) }
    .widget_black_box_wide 0x0041aa6c : { *ai-startup-menuwidget.o(.rodata.blackBoxWideAnimation) }
    .widget_black_box_vtable 0x004a9cf8 : { *ai-startup-menuwidget.o(.data.rel.ro._ZTVN7Widgets8BlackBoxE .gnu.linkonce.d.rel.ro._ZTVN7Widgets8BlackBoxE) }
    .widget_ig_menu_localization 0x002edc7c : { *ai-startup-menuwidget.o(.text._ZN7Widgets6IGMenu18UpdateLocalizationEv) }
    .widget_ig_menu_title_text_path 0x00419100 : { *ai-startup-menuwidget.o(.rodata.igMenuTitleText) }
    .widget_ig_menu_button_text_format 0x0041af08 : { *ai-startup-menuwidget.o(.rodata.igMenuButtonTextFormat) }
    .widget_ig_menu_disable 0x002ef064 : { *ai-startup-menuwidget.o(.text._ZN7Widgets6IGMenu7DisableEv) }
    .widget_ig_menu_active_button 0x002ecc4c : { *ai-startup-menuwidget.o(.text._ZN7Widgets6IGMenu15SetActiveButtonENS0_7eButtonEb) }
    .widget_ig_menu_back_text 0x0041af34 : { *ai-startup-menuwidget.o(.rodata.igMenuBackText) }
    .widget_ig_menu_selected 0x0041aa58 : { *ai-startup-menuwidget.o(.rodata.igMenuSelected) }
    .widget_ig_menu_ctor 0x002ec8b0 : { *ai-startup-menuwidget.o(.text._ZN7Widgets6IGMenuC1Ev .text._ZN7Widgets6IGMenuC2Ev) }
    .widget_ig_menu_show 0x002ed004 : { *ai-startup-menuwidget.o(.text._ZN7Widgets6IGMenu4ShowEv) }
    .widget_ig_menu_deleting_dtor 0x002ec044 : { *ai-startup-menuwidget.o(.text._ZN7Widgets6IGMenuD0Ev) }
    .widget_ig_menu_complete_dtor 0x002ec06c : { *ai-startup-menuwidget.o(.text._ZN7Widgets6IGMenuD1Ev .text._ZN7Widgets6IGMenuD2Ev) }
    .widget_ig_menu_name 0x0041a93c : { *ai-startup-menuwidget.o(.rodata.widgetIGMenuName) }
    .widget_ig_menu_vtable 0x004a9b10 : { *ai-startup-menuwidget.o(.data.rel.ro._ZTVN7Widgets6IGMenuE) }
    .widget_main_menu_localization 0x002ed388 : { *ai-startup-menuwidget.o(.text._ZN7Widgets8MainMenu18UpdateLocalizationEv) }
    .widget_main_menu_button_text_format 0x0041ab70 : { *ai-startup-menuwidget.o(.rodata.mainMenuButtonTextFormat) }
    .widget_main_menu_more_text 0x0041ab90 : { *ai-startup-menuwidget.o(.rodata.mainMenuMoreText) }
    .widget_main_menu_twitter_text 0x0041abac : { *ai-startup-menuwidget.o(.rodata.mainMenuTwitterText) }
    .widget_main_menu_button_info 0x002ec180 : { *ai-startup-menuwidget.o(.text._ZN7Widgets8MainMenu13SetButtonInfoENS0_7eButtonEibb) }
    .widget_main_menu_pressed_button 0x002ec010 : { *ai-startup-menuwidget.o(.text._ZNK7Widgets8MainMenu16GetPressedButtonEv) }
    .widget_main_menu_constructor 0x002ec428 : { *ai-startup-menuwidget.o(.text._ZN7Widgets8MainMenuC1Ev .text._ZN7Widgets8MainMenuC2Ev) }
    .widget_main_menu_button_format 0x0041a71c : { *ai-startup-menuwidget.o(.rodata.mainMenuButtonFormat) }
    .widget_main_menu_name 0x0041a7b0 : { *ai-startup-menuwidget.o(.rodata.widgetMainMenuName) }
    .widget_main_menu_twitter_name 0x0041a7c0 : { *ai-startup-menuwidget.o(.rodata.widgetMainMenuTwitterName) }
    .widget_main_menu_double_option_name 0x0041a7dc : { *ai-startup-menuwidget.o(.rodata.widgetMainMenuDoubleOptionName) }
    .widget_ig_menu_hide_buttons 0x002ec2c4 : { *ai-startup-menuwidget.o(.text._ZN7Widgets6IGMenu11HideButtonsEv) }
    .widget_ig_menu_show_buttons 0x002ec33c : { *ai-startup-menuwidget.o(.text._ZN7Widgets6IGMenu11ShowButtonsEv) }
    .widget_ig_menu_button_info 0x002ec114 : { *ai-startup-menuwidget.o(.text._ZN7Widgets6IGMenu13SetButtonInfoENS0_7eButtonEib) }
    .widget_ig_menu_button_format 0x0041a6f8 : { *ai-startup-menuwidget.o(.rodata.igMenuButtonFormat) }
    .widget_ig_menu_title_text 0x002ebe8c : { *ai-startup-menuwidget.o(.text._ZN7Widgets6IGMenu12SetTitleTextEi) }
    .widget_ig_menu_back_button_text 0x002ebe90 : { *ai-startup-menuwidget.o(.text._ZN7Widgets6IGMenu17SetBackButtonTextEi) }
    .widget_volumes_set_playlist 0x002ebf10 : { *ai-startup-menuwidget.o(.text._ZN7Widgets7Volumes11SetPlaylistEi) }
    .widget_corruption_set_wanted_level 0x002ebf24 : { *ai-startup-menuwidget.o(.text._ZN7Widgets10Corruption14SetWantedLevelEi) }
    .widget_volumes_playlist 0x004b53a4 : { *ai-startup-menuwidget.o(.data._ZN7Widgets7Volumes10s_playlistE) }
    .widget_set_listener 0x002ebe48 : { *ai-startup-menuwidget.o(.text._ZN10MenuWidget11SetListenerEP9MenuState) }
    .widget_arrows_set_page_count 0x002ebe9c : { *ai-startup-menuwidget.o(.text._ZN7Widgets6Arrows12SetPageCountEiib) }
    .widget_title_set_icon 0x002ecbdc : { *ai-startup-menuwidget.o(.text._ZN7Widgets5Title7SetIconEPKc) }
    .widget_title_icon 0x0041aa10 : { *ai-startup-menuwidget.o(.rodata.widgetTitleIcon) }
    .widget_mission_constructor 0x002ec790 : { *ai-startup-menuwidget.o(.text._ZN7Widgets7MissionC2Ev .text._ZN7Widgets7MissionC1Ev) }
    .widget_mission_name 0x0041a8f0 : { *ai-startup-menuwidget.o(.rodata.widgetMissionName) }
    .widget_money_constructor 0x002ec7c0 : { *ai-startup-menuwidget.o(.text._ZN7Widgets5MoneyC2Ev .text._ZN7Widgets5MoneyC1Ev) }
    .widget_money_name 0x0041a900 : { *ai-startup-menuwidget.o(.rodata.widgetMoneyName) }
    .widget_arrows_constructor 0x002ec7ec : { *ai-startup-menuwidget.o(.text._ZN7Widgets6ArrowsC2Ev .text._ZN7Widgets6ArrowsC1Ev) }
    .widget_arrows_name 0x0041a90c : { *ai-startup-menuwidget.o(.rodata.widgetArrowsName) }
    .widget_contentbox_constructor 0x002eca48 : { *ai-startup-menuwidget.o(.text._ZN7Widgets10ContentBoxC2Ev .text._ZN7Widgets10ContentBoxC1Ev) }
    .widget_contentbox_name 0x0041a980 : { *ai-startup-menuwidget.o(.rodata.widgetContentBoxName) }
    .widget_title_constructor 0x002eca74 : { *ai-startup-menuwidget.o(.text._ZN7Widgets5TitleC2Ev .text._ZN7Widgets5TitleC1Ev) }
    .widget_title_name 0x0041a994 : { *ai-startup-menuwidget.o(.rodata.widgetTitleName) }
    .widget_backgroundingame_constructor 0x002ecad4 : { *ai-startup-menuwidget.o(.text._ZN7Widgets16BackgroundInGameC2Ev .text._ZN7Widgets16BackgroundInGameC1Ev) }
    .widget_backgroundingame_name 0x0041a9a0 : { *ai-startup-menuwidget.o(.rodata.widgetBGName) }
    .widget_mission_script 0x002ebf04 : { *ai-startup-menuwidget.o(.text._ZN7Widgets7Mission9SetScriptEPK6Script) }
    .widget_arrows_current_page 0x002ebf00 : { *ai-startup-menuwidget.o(.text._ZNK7Widgets6Arrows14GetCurrentPageEv) }
    .widget_title_text 0x002ebe6c : { *ai-startup-menuwidget.o(.text._ZN7Widgets5Title9SetTextIdEi) }
    .widget_mission_show 0x002ecee8 : { *ai-startup-menuwidget.o(.text._ZN7Widgets7Mission4ShowEv) }
    .widget_mission_vtable 0x004a9a48 : { *ai-startup-menuwidget.o(.data.rel.ro._ZTVN7Widgets7MissionE) }
    .widget_money_show 0x002ecef4 : { *ai-startup-menuwidget.o(.text._ZN7Widgets5Money4ShowEv) }
    .widget_money_vtable 0x004a9a70 : { *ai-startup-menuwidget.o(.data.rel.ro._ZTVN7Widgets5MoneyE) }
    .widget_arrows_show 0x002ecf00 : { *ai-startup-menuwidget.o(.text._ZN7Widgets6Arrows4ShowEv) }
    .widget_arrows_vtable 0x004a9a98 : { *ai-startup-menuwidget.o(.data.rel.ro._ZTVN7Widgets6ArrowsE) }
    .widget_contentbox_show 0x002ed088 : { *ai-startup-menuwidget.o(.text._ZN7Widgets10ContentBox4ShowEv) }
    .widget_contentbox_vtable 0x004a9c30 : { *ai-startup-menuwidget.o(.data.rel.ro._ZTVN7Widgets10ContentBoxE) }
    .widget_title_show 0x002ed094 : { *ai-startup-menuwidget.o(.text._ZN7Widgets5Title4ShowEv) }
    .widget_title_vtable 0x004a9c58 : { *ai-startup-menuwidget.o(.data.rel.ro._ZTVN7Widgets5TitleE) }
    .widget_backgroundingame_show 0x002ed0a0 : { *ai-startup-menuwidget.o(.text._ZN7Widgets16BackgroundInGame4ShowEv) }
    .widget_backgroundingame_vtable 0x004a9c80 : { *ai-startup-menuwidget.o(.data.rel.ro._ZTVN7Widgets16BackgroundInGameE) }
    .widget_enable 0x002ed0ac : { *ai-startup-menuwidget.o(.text._ZN10MenuWidget6EnableEv) }
    .widget_disable 0x002eef94 : { *ai-startup-menuwidget.o(.text._ZN10MenuWidget7DisableEv) }
    .widget_constructor 0x002ec3d0 : { *ai-startup-menuwidget.o(.text._ZN10MenuWidgetC2EPKc .text._ZN10MenuWidgetC1EPKc) }
    .widget_hide 0x002ecd5c : { *ai-startup-menuwidget.o(.text._ZN10MenuWidget4HideEb) }
    .widget_show 0x002ece20 : { *ai-startup-menuwidget.o(.text._ZN10MenuWidget4ShowEv) }
    .widget_destructor 0x002ebe1c : { *ai-startup-menuwidget.o(.text._ZN10MenuWidgetD2Ev .text._ZN10MenuWidgetD1Ev) }
    .widget_is_visible 0x002ebe34 : { *ai-startup-menuwidget.o(.text._ZNK10MenuWidget9IsVisibleEv) }
    .widget_auto_hide 0x002ebe38 : { *ai-startup-menuwidget.o(.text._ZNK10MenuWidget8AutoHideEv) }
    .widget_is_enabled 0x002ebe3c : { *ai-startup-menuwidget.o(.text._ZNK10MenuWidget9IsEnabledEv) }
    .widget_on_event 0x002ebe40 : { *ai-startup-menuwidget.o(.text._ZN10MenuWidget7OnEventERN8RenderFX5EventE) }
    .widget_update_localization 0x002ebe44 : { *ai-startup-menuwidget.o(.text._ZN10MenuWidget18UpdateLocalizationEv) }
    .widget_confirm_payment_set_price 0x002ebe80 : { *ai-startup-menuwidget.o(.text._ZN7Widgets14ConfirmPayment8SetPriceEi) }
    .widget_dialog_set_message 0x002ebe84 : { *ai-startup-menuwidget.o(.text._ZN7Widgets6Dialog10SetMessageEi) }
    .widget_dialog_get_pressed_button 0x002ebe88 : { *ai-startup-menuwidget.o(.text._ZNK7Widgets6Dialog16GetPressedButtonEv) }
    .widget_dialog_show 0x002ed014 : { *ai-startup-menuwidget.o(.text._ZN7Widgets6Dialog4ShowEv) }
    .widget_dialog_constructor 0x002ec938 : { *ai-startup-menuwidget.o(.text._ZN7Widgets6DialogC2EPKc .text._ZN7Widgets6DialogC1EPKc) }
    .widget_confirm_constructor 0x002ec95c : { *ai-startup-menuwidget.o(.text._ZN7Widgets7ConfirmC2EPKc .text._ZN7Widgets7ConfirmC1EPKc) }
    .widget_confirm_payment_constructor 0x002ec980 : { *ai-startup-menuwidget.o(.text._ZN7Widgets14ConfirmPaymentC2Ev .text._ZN7Widgets14ConfirmPaymentC1Ev) }
    .widget_confirm_name 0x00418f80 : { *ai-startup-menuwidget.o(.rodata.confirmWidgetName) }
    .widget_dialog_vtable 0x004a9b90 : { *ai-startup-menuwidget.o(.data.rel.ro._ZTVN7Widgets6DialogE) }
    .widget_vtable 0x004a9ca8 : { *ai-startup-menuwidget.o(.data.rel.ro._ZTV10MenuWidget) }
}
