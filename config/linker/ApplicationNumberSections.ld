/* Original HUD numeric sprite renderer and its complete constant tables. */
SECTIONS
{
    .application_display_number 0x002d4860 : { *application-helpers.o(.text._ZN11Application26displayNumberWithHUDSpriteEiiiPKc) }
    .application_number_frames 0x004143c8 : { *application-helpers.o(.rodata._ZZN11Application26displayNumberWithHUDSpriteEiiiPKcE6frames) }
    .application_number_format 0x00413c9c : { *application-helpers.o(.rodata.application_number_format) }
}
