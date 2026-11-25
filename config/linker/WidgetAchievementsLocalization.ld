/* Achievements::UpdateLocalization and its row strings. Retail tail-merges
   Volumes' "on" (0x0041b1dc) into the end of the icon path string, so the icon
   path keeps its retail VMA but loads at an unused LMA to avoid the overlap. */
SECTIONS {
 .widgets_achievements_localize 0x002ee488 : { *ai-startup-menuwidget.o(.text._ZN7Widgets12Achievements18UpdateLocalizationEv) }
 ASSERT(SIZEOF(.widgets_achievements_localize) == 500, "native Achievements localization strict span")
 .achievementsRowTitlePath 0x0041b108 : { *ai-startup-menuwidget.o(.rodata.achievementsRowTitlePath) }
 .achievementsRowDescriptionPath 0x0041b144 : { *ai-startup-menuwidget.o(.rodata.achievementsRowDescriptionPath) }
 .achievementsCompletedDescription 0x0041b188 : { *ai-startup-menuwidget.o(.rodata.achievementsCompletedDescription) }
 .achievementsRowIconPath 0x0041b1a8 : AT(0x00710000) { *ai-startup-menuwidget.o(.rodata.achievementsRowIconPath) }
 .achievementsUnlockedFrame 0x0041b1e0 : { *ai-startup-menuwidget.o(.rodata.achievementsUnlockedFrame) }
 .achievementsLockedFrame 0x0041b1e8 : { *ai-startup-menuwidget.o(.rodata.achievementsLockedFrame) }
 .achievementsEntryFormat 0x0041b1f0 : { *ai-startup-menuwidget.o(.rodata.achievementsEntryFormat) }
 .achievementsLayoutCallback 0x0041b224 : { *ai-startup-menuwidget.o(.rodata.achievementsLayoutCallback) }
}
