/* ScriptManager queries and script registration at retail addresses. */
SECTIONS
{
    .script_manager_tagged 0x0033cfec : { *script-manager-helpers.o(.text._ZN13ScriptManager12taggedKilledEv) }
    .script_manager_print 0x0033d004 : { *script-manager-helpers.o(.text._ZN13ScriptManager12printCommandERKN7Structs13ScriptCommandE) }
    .script_manager_add 0x0033d008 : { *script-manager-helpers.o(.text._ZN13ScriptManager9addScriptEP6Script) }
    .script_manager_find 0x0033d020 : { *script-manager-helpers.o(.text._ZNK13ScriptManager10findScriptEi) }
    .script_manager_blocking 0x0033d03c : { *script-manager-helpers.o(.text._ZNK13ScriptManager26areBlockingCommandsSkippedEv) }
    .script_manager_cinematic 0x0033d04c : { *script-manager-helpers.o(.text._ZNK13ScriptManager13isInCinematicEv) }
    .script_manager_skip_visible 0x0033d070 : { *script-manager-helpers.o(.text._ZNK13ScriptManager19isSkipButtonVisibleEv) }
    .script_manager_failure 0x0033d090 : { *script-manager-helpers.o(.text._ZN13ScriptManager15getFailureCauseEv) }
}
