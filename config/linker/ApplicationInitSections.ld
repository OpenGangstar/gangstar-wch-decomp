SECTIONS
{
 .application_init 0x002d5590 : { *application-helpers.o(.text._ZN11Application4InitEPN3irr14IrrlichtDeviceE) }
 .application_text_styles 0x00413db0 : { *application-helpers.o(.rodata.application_text_styles) }
 .application_achievements 0x00413dc4 : { *application-helpers.o(.rodata.application_achievements) }
}
