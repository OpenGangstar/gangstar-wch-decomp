SECTIONS {
 .widgets_corruption_localize 0x002ef0b0 : { *ai-startup-menuwidget.o(.text._ZN7Widgets10Corruption18UpdateLocalizationEv) }
 ASSERT(SIZEOF(.widgets_corruption_localize) == 524, "native Corruption localization strict span")
 .corruptionBadgeGroup 0x0041b320 : { *ai-startup-menuwidget.o(.rodata.corruptionBadgeGroup) }
 .corruptionTitle 0x0041b338 : { *ai-startup-menuwidget.o(.rodata.corruptionTitle) }
 .corruptionSlashField 0x0041b354 : { *ai-startup-menuwidget.o(.rodata.corruptionSlashField) }
 .corruptionPrice 0x0041b370 : { *ai-startup-menuwidget.o(.rodata.corruptionPrice) }
 .corruptionValue 0x0041b38c : { *ai-startup-menuwidget.o(.rodata.corruptionValue) }
 .corruptionPerBadge 0x0041b3a8 : { *ai-startup-menuwidget.o(.rodata.corruptionPerBadge) }
 .corruptionButton 0x0041b3c8 : { *ai-startup-menuwidget.o(.rodata.corruptionButton) }
 .corruptionButtonText 0x0041b3e4 : { *ai-startup-menuwidget.o(.rodata.corruptionButtonText) }
 .corruptionNoWantedLevel 0x0041b408 : { *ai-startup-menuwidget.o(.rodata.corruptionNoWantedLevel) }
 .corruptionSlash 0x004361d0 : { *ai-startup-menuwidget.o(.rodata.corruptionSlash) }
}
