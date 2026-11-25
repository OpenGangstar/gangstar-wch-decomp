/* CHudManager::update and its retail log/state-name strings, shared by every unit linking hud-manager-helpers.o. */
PROVIDE(__aeabi_d2iz = 0x001c4844);
PROVIDE(__android_log_print = 0x001c4238);
SECTIONS
{
    .hud_manager_update 0x00324398 : { *hud-manager-helpers.o(.text._ZN11CHudManager6updateEd) }
    .hud_update_release_text 0x004223c0 : { *hud-manager-helpers.o(.rodata.hudDefaultRelease) }
    .hud_update_used_text 0x004223e4 : { *hud-manager-helpers.o(.rodata.hudDefaultUsed) }
}
