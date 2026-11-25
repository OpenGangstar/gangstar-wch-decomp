SECTIONS {
 .widgets_game_setting_event 0x002efafc : { *ai-startup-menuwidget.o(.text._ZN7Widgets11GameSetting7OnEventERN8RenderFX5EventE) }
 ASSERT(SIZEOF(.widgets_game_setting_event) == 308, "native GameSetting OnEvent strict span")
 .widgets_game_setting_vtable 0x004a9930 : { *ai-startup-menuwidget.o(.data.rel.ro._ZTVN7Widgets11GameSettingE) }
}
