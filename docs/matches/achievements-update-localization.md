# Widgets::Achievements::UpdateLocalization exact match

`Widgets::Achievements::UpdateLocalization()` matches all 500 retail bytes at
Thumb address `0x002ee489`, and its strict section ends at the retail extent.

```text
OK  _ZN7Widgets12Achievements18UpdateLocalizationEv  0x002ee489  500 bytes
OK SECTION .widgets_achievements_localize  0x002ee488  500 bytes
```

## Source form

The function refreshes the four visible achievement rows. The row index wraps
modulo `count + 2` and is corrected when negative.

- **Real rows.** For each real achievement it sets:
  - the title, from `getString(titleId)`;
  - the description, wrapped in the completed colour format when flag 2 is set;
  - the icon visibility, and its `unlock`/`lock` frame;
  - the `updateLayout` callback.
- **Empty rows.** These clear the title and description to the shared empty
  string and hide the icon.

The widget's previously opaque 96-byte field at +44 is now typed as
`int achievementIds[24]`, the IDs passed to
`AchievementManager::getAchievementFromID`. Its layout is unchanged.

No header change, branch hint, inline assembly, register constraint or output
edit is used.

## Linking the tail-merged string

Retail tail-merges the already matched Volumes widget's `"on"` (`0x0041b1dc`)
into the end of this function's icon path string, which starts at `0x0041b1a8`
and ends in `.icon`. Both strings must keep their retail addresses for the
GOT-relative references in the two functions.

`config/linker/WidgetAchievementsLocalization.ld` therefore places the icon path
at its retail VMA but loads it at an unused LMA (`AT(0x00710000)`). This avoids
an LMA overlap while every relocation still resolves to the retail address. The
other seven row strings are placed at their retail addresses.

## Verification

`python -B tools/build.py --all` exited 0 with 5,543 function, 5,625 section
and 181 region comparisons and no mismatch or skip. Unit tests, repository
checks and progress checks pass.
