__aeabi_d2iz = 0x001c4844;
SECTIONS {
 .widgets_tutorial_localize 0x002ef6f4 : { *ai-startup-menuwidget.o(.text._ZN7Widgets8Tutorial18UpdateLocalizationEv) }
 ASSERT(SIZEOF(.widgets_tutorial_localize) == 464, "native Tutorial localization strict span")
 .tutorialTitleSuffix 0x0041b588 : { *ai-startup-menuwidget.o(.rodata.tutorialTitleSuffix) }
 ASSERT(SIZEOF(.tutorialTitleSuffix) == 16, "native tutorialTitleSuffix strict span")
 .tutorialContentSuffix 0x0041b598 : { *ai-startup-menuwidget.o(.rodata.tutorialContentSuffix) }
 ASSERT(SIZEOF(.tutorialContentSuffix) == 28, "native tutorialContentSuffix strict span")
 .tutorialTextHeightName 0x00418f50 : { *ai-startup-menuwidget.o(.rodata.tutorialTextHeightName) }
 ASSERT(SIZEOF(.tutorialTextHeightName) == 12, "native tutorialTextHeightName strict span")
}
