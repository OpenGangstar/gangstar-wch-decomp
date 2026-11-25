mapLegendButtonName = 0x0041aab8;
SECTIONS {
 .widgets_mission_event 0x002ed214 : { *ai-startup-menuwidget.o(.text._ZN7Widgets7Mission7OnEventERN8RenderFX5EventE) }
 ASSERT(SIZEOF(.widgets_mission_event) == 132, "native Mission OnEvent strict span")
 .widgets_maplegend_event 0x002ed298 : { *ai-startup-menuwidget.o(.text._ZN7Widgets9MapLegend7OnEventERN8RenderFX5EventE) }
 ASSERT(SIZEOF(.widgets_maplegend_event) == 240, "native MapLegend OnEvent strict span")
 .startMissionButton 0x0041ab48 : { *ai-startup-menuwidget.o(.rodata.startMissionButton) }
 .mapLegendArrow 0x0041ab58 : { *ai-startup-menuwidget.o(.rodata.mapLegendArrow) }
}
