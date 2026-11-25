# Widgets::Statistics::Show exact match

`Widgets::Statistics::Show()` matches all 128 retail bytes at Thumb address
`0x002ee409`, including relocations.

```text
OK  _ZN7Widgets10Statistics4ShowEv  0x002ee409  128 bytes
```

## Source form

`Show` shows the widget and then rebuilds the list of visible statistics.
It resets its cursor fields and collects every statistic ID whose
achievement-manager record has the visible bit set.

Details that the retail bytes require:

- **Loop start.** The loop index starts from `unknown20`, which was reset to 0
  two statements earlier. That keeps a real statement ahead of the manager's
  GOT load. The index is then live across the last PIC use, so it conflicts
  with the PIC register and the two get retail's registers.
- **Why a literal 0 fails.** Writing `int id = 0` lets constant propagation
  place the copy after the GOT load, and the two then share a register.

No branch hint, inline assembly, register constraint or output edit is used,
and no header change.

## Data

`Show` is the key function of `Widgets::Statistics`, so its vtable is now
emitted here. The vtable and `Show` are placed at their retail addresses
`0x004a9890` and `0x002ee408` in the shared `MenuWidgetFunctions.ld`, which
the menu-state link also uses.

## Verification

`python -B tools/build.py` passes for ai-startup-menuwidget and
ai-startup-menustate. A fresh complete build, `python -B tools/build.py --all`, exited 0 with
5,609 function, 5,700 section and 181 region comparisons and no mismatch or
skip; the previous baseline was 5,607, 5,698 and 181.
