SECTIONS {
 .widgets_controls_localize 0x002ee6ec : { *ai-startup-menuwidget.o(.text._ZN7Widgets8Controls18UpdateLocalizationEv) }
 ASSERT(SIZEOF(.widgets_controls_localize) == 292, "native Controls localization strict span")
 .controlsSteeringTitle 0x0041b234 : { *ai-startup-menuwidget.o(.rodata.controlsSteeringTitle) }
 .controlsSteeringValue 0x0041b258 : { *ai-startup-menuwidget.o(.rodata.controlsSteeringValue) }
 .controlsThrottleTitle 0x0041b27c : { *ai-startup-menuwidget.o(.rodata.controlsThrottleTitle) }
 .controlsThrottleValue 0x0041b2a0 : { *ai-startup-menuwidget.o(.rodata.controlsThrottleValue) }
}
