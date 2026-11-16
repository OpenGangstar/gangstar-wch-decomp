SECTIONS
{
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
    .widget_button_prefix 0x00419f00 : { *ai-startup-menuwidget.o(.rodata.widgetButtonPrefix) }
    .widget_constructor 0x002ec3d0 : { *ai-startup-menuwidget.o(.text._ZN10MenuWidgetC2EPKc .text._ZN10MenuWidgetC1EPKc) }
    .widget_hide 0x002ecd5c : { *ai-startup-menuwidget.o(.text._ZN10MenuWidget4HideEb) }
    .widget_show 0x002ece20 : { *ai-startup-menuwidget.o(.text._ZN10MenuWidget4ShowEv) }
    .widget_hide_animation 0x0041aa74 : { *ai-startup-menuwidget.o(.rodata.widgetHideAnimation) }
    .widget_show_animation 0x0041aa7c : { *ai-startup-menuwidget.o(.rodata.widgetShowAnimation) }
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
