SECTIONS {
 .widgets_controls_event 0x002efda4 : { *ai-startup-menuwidget.o(.text._ZN7Widgets8Controls7OnEventERN8RenderFX5EventE) }
 ASSERT(SIZEOF(.widgets_controls_event) == 372, "native widgets_controls_event strict span")
 .controlsSteeringPart 0x0041b610 : { *ai-startup-menuwidget.o(.rodata.controlsSteeringPart) }
 .controlsThrottlePart 0x0041b61c : { *ai-startup-menuwidget.o(.rodata.controlsThrottlePart) }
}
