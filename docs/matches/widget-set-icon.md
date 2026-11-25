# Widget frame setters exact matches

`Widgets::Help::SetIcon`, `Widgets::Achievement::SetIcon` and
`Widgets::IGMenu::GoToFrame` (32 bytes each) match retail exactly.

```text
OK  _ZN7Widgets4Help7SetIconEPKc  0x002ecb01  32 bytes
OK  _ZN7Widgets11Achievement7SetIconEPKc  0x002ecbbd  32 bytes
OK  _ZN7Widgets6IGMenu9GoToFrameEPKc  0x002ecb9d  32 bytes
```

## Source form

Each function forwards its frame label to `RenderFX::GotoFrame` for its
widget's character: `"widgetHelp.icon"`, `"widgetAchievement.anim.icon"` and
`"widgetIGMenu.groupBoutons"`. The strings are placed at their retail addresses
`0x0041a9ac`, `0x0041a9f4` and `0x0041a9d8`.

Calling through the bool-returning `RenderFX::GotoFrame` member put three
argument-setup instructions in a different order. The call then sets `r0` as an
unused return value, which removes one forward dependence of the `ldr r0`. The
sched2 tie-break on forward-dependence count then schedules it last.

Retail ignores the result. The functions call the same retail symbol through a
`void` `extern "C"` declaration, following this file's existing practice for
`RenderFX::SetText`. That keeps retail's dependence count and instruction order,
and is ABI-identical because the result is unused.

No header change, branch hint, inline assembly, register constraint or output
edit is used.

## Verification

`python -B tools/build.py --all` exited 0 with 5,567 function, 5,650 section
and 181 region comparisons and no mismatch or skip. Unit tests, repository
checks and progress checks pass.
