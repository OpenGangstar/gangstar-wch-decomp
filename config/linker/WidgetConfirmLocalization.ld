SECTIONS {
 .widgets_confirm_localize 0x002edec0 : { *ai-startup-menuwidget.o(.text._ZN7Widgets7Confirm18UpdateLocalizationEv) }
 ASSERT(SIZEOF(.widgets_confirm_localize) == 252, "native Confirm localization strict span")
 .confirmMessageFormat 0x0041afa0 : { *ai-startup-menuwidget.o(.rodata.confirmMessageFormat) }
 ASSERT(SIZEOF(.confirmMessageFormat) == 16, "native confirmMessageFormat strict span")
 .confirmYesFormat 0x0041afb0 : { *ai-startup-menuwidget.o(.rodata.confirmYesFormat) }
 ASSERT(SIZEOF(.confirmYesFormat) == 16, "native confirmYesFormat strict span")
 .confirmNoFormat 0x0041afc0 : { *ai-startup-menuwidget.o(.rodata.confirmNoFormat) }
 ASSERT(SIZEOF(.confirmNoFormat) == 16, "native confirmNoFormat strict span")
 .widgets_confirm_vtable 0x004a9b68 : { *ai-startup-menuwidget.o(.data.rel.ro._ZTVN7Widgets7ConfirmE) }
 ASSERT(SIZEOF(.widgets_confirm_vtable) == 40, "native Confirm vtable strict span")
}
