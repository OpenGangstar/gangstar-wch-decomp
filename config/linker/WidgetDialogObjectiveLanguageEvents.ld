objectiveButtonLabel = 0x0041aad4;
SECTIONS {
 .widgets_objective_event 0x002ef900 : { *ai-startup-menuwidget.o(.text._ZN7Widgets9Objective7OnEventERN8RenderFX5EventE) }
 ASSERT(SIZEOF(.widgets_objective_event) == 252, "native widgets_objective_event strict span")
 .widgets_dialog_event 0x002ee060 : { *ai-startup-menuwidget.o(.text._ZN7Widgets6Dialog7OnEventERN8RenderFX5EventE) }
 ASSERT(SIZEOF(.widgets_dialog_event) == 608, "native widgets_dialog_event strict span")
 .widgets_language_event 0x002efc30 : { *ai-startup-menuwidget.o(.text._ZN7Widgets8Language7OnEventERN8RenderFX5EventE) }
 ASSERT(SIZEOF(.widgets_language_event) == 372, "native widgets_language_event strict span")
 .dialogButtonPart 0x0041b010 : { *ai-startup-menuwidget.o(.rodata.dialogButtonPart) }
 .dialogOpenButton 0x0041b020 : { *ai-startup-menuwidget.o(.rodata.dialogOpenButton) }
 .dialogSaveButton 0x0041b028 : { *ai-startup-menuwidget.o(.rodata.dialogSaveButton) }
 .dialogCancelButton 0x0041b030 : { *ai-startup-menuwidget.o(.rodata.dialogCancelButton) }
 .dialogDiscardButton 0x0041b048 : { *ai-startup-menuwidget.o(.rodata.dialogDiscardButton) }
 .dialogApplyButton 0x0041b054 : { *ai-startup-menuwidget.o(.rodata.dialogApplyButton) }
 .dialogResetButton 0x0041b060 : { *ai-startup-menuwidget.o(.rodata.dialogResetButton) }
 .dialogRestoreDefaultsButton 0x0041b06c : { *ai-startup-menuwidget.o(.rodata.dialogRestoreDefaultsButton) }
 .dialogHelpButton 0x0041b080 : { *ai-startup-menuwidget.o(.rodata.dialogHelpButton) }
 .dialogSaveAllButton 0x0041b088 : { *ai-startup-menuwidget.o(.rodata.dialogSaveAllButton) }
 .dialogYesButton 0x0041b094 : { *ai-startup-menuwidget.o(.rodata.dialogYesButton) }
 .dialogYesToAllButton 0x0041b09c : { *ai-startup-menuwidget.o(.rodata.dialogYesToAllButton) }
 .dialogNoButton 0x0041b0a8 : { *ai-startup-menuwidget.o(.rodata.dialogNoButton) }
 .dialogNoToAllButton 0x0041b0b0 : { *ai-startup-menuwidget.o(.rodata.dialogNoToAllButton) }
 .dialogAbortButton 0x0041b0bc : { *ai-startup-menuwidget.o(.rodata.dialogAbortButton) }
 .dialogRetryButton 0x0041b0c8 : { *ai-startup-menuwidget.o(.rodata.dialogRetryButton) }
 .dialogIgnoreButton 0x0041b0d4 : { *ai-startup-menuwidget.o(.rodata.dialogIgnoreButton) }
}
