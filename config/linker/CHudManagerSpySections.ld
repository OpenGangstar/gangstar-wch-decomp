/* CHudManager background wrappers at their retail addresses. */
SECTIONS
{
    .spy_gauge_spy 0x00323810 : { *hud-manager-helpers.o(.text._ZN11CHudManager18useSpyBGInSpyGaugeEv) }
    .spy_gauge_drive_bad 0x00323820 : { *hud-manager-helpers.o(.text._ZN11CHudManager23useDriveBadBGInSpyGaugeEv) }
    .spy_gauge_drive_well 0x00323830 : { *hud-manager-helpers.o(.text._ZN11CHudManager24useDriveWellBGInSpyGaugeEv) }
}
