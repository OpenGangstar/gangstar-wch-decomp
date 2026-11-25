# Widgets::Help::SetIcon and Widgets::Achievement::SetIcon exact matches

Both 32-byte widget icon setters match retail exactly.

```text
OK  _ZN7Widgets4Help7SetIconEPKc  0x002ecb01  32 bytes
OK  _ZN7Widgets11Achievement7SetIconEPKc  0x002ecbbd  32 bytes
```

## Source form

Each function forwards its icon frame label to `RenderFX::GotoFrame` for its
widget's icon character: `"widgetHelp.icon"` and
`"widgetAchievement.anim.icon"`. Both strings are placed at their retail
addresses `0x0041a9ac` and `0x0041a9f4`.

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

`python -B tools/build.py --all` exited 0 with 5,566 function, 5,649 section
and 181 region comparisons and no mismatch or skip. Unit tests, repository
checks and progress checks pass.
