# Menus::OptionGameSettings::Notify exact match

`Menus::OptionGameSettings::Notify(MenuWidget const*, int)` matches all 1056
retail bytes at Thumb address `0x002eac65`, including relocations.
`InfoHelp::Notify` and the other sections of `MenuState.cpp` are unchanged.

## Source form

The function handles the game-settings menu: arrow page changes update the
setting widget, and setting events change the selected value and apply it.
Details that the retail bytes require, each commented in the source:

- **Event gate.** The arrows-widget event range test is copied through a
  one-field aggregate, so the opcode heuristic sees it only after SRA folds it.
  A guarded no-code `__builtin_prefetch` on the failure arm cancels the call
  heuristic.
- **Preferences priority.** Two identical `Preferences` constructor calls are
  selected by a test on `settingKey`. Crossjumping merges them after reload, and
  the test's reference lowers `settingKey`'s allocation priority below
  `arrowsKey`'s, which gives retail's `sl`/`r9` assignment.
- **Dead-test frequency hints.** Two switch cases each contain a test that is
  always false on that case's edge (`id != 4` inside case 4, `id != 3` inside
  case 3). The test is hidden in an aggregate copy and wrapped in
  `__builtin_expect(..., 0)`. It jumps to a user label in another case (case 5
  and case 1). At profile time it adds exactly one unit of frequency to the
  target block, which breaks the equal-frequency ties in basic-block reordering
  the way retail does. DOM folds the test away after SRA, so it emits no code.
- **Strings.** The four menu strings live at scattered addresses in retail's
  merged string pool. They are hidden externs placed by the linker.
