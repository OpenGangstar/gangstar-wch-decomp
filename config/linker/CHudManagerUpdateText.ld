/* Retail address of CHudManager::update's "BlockingTutorial" string. GSBlockingTutorial owns the identical retail string there and links its own copy instead. */
SECTIONS
{
    .hud_update_blocking_text 0x00414c84 : { *hud-manager-helpers.o(.rodata.hudBlockingTutorial) }
}
