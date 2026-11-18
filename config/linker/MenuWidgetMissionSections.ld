/* Shared verified mission widget update and native path literals. */
SECTIONS
{
    .widget_mission_localization 0x2ed8ac : { *ai-startup-menuwidget.o(.text._ZN7Widgets7Mission18UpdateLocalizationEv) }
    .widget_mission_objective 0x41ad40 : { *ai-startup-menuwidget.o(.rodata.missionObjectivePath) }
    .widget_mission_message 0x419090 : { *ai-startup-menuwidget.o(.rodata.missionMessagePath) }
    .widget_mission_locationtitle 0x4190b8 : { *ai-startup-menuwidget.o(.rodata.missionLocationTitlePath) }
    .widget_mission_locationvalue 0x41ad5c : { *ai-startup-menuwidget.o(.rodata.missionLocationValuePath) }
    .widget_mission_typetitle 0x41ad7c : { *ai-startup-menuwidget.o(.rodata.missionTypeTitlePath) }
    .widget_mission_typevalue 0x41ad98 : { *ai-startup-menuwidget.o(.rodata.missionTypeValuePath) }
    .widget_mission_cashtitle 0x41adb4 : { *ai-startup-menuwidget.o(.rodata.missionCashTitlePath) }
    .widget_mission_cashvalue 0x41add8 : { *ai-startup-menuwidget.o(.rodata.missionCashValuePath) }
    .widget_mission_icon 0x41adfc : { *ai-startup-menuwidget.o(.rodata.missionIconPath) }
    .widget_mission_button 0x41ae14 : { *ai-startup-menuwidget.o(.rodata.missionButtonPath) }
    .widget_mission_buttontext 0x41ae34 : { *ai-startup-menuwidget.o(.rodata.missionButtonTextPath) }
}
