# Widgets::Achievements::SetCategory exact match

`Widgets::Achievements::SetCategory(int)` matches all 112 retail bytes at
Thumb address `0x002ee67d`, including relocations.

```text
OK  _ZN7Widgets12Achievements11SetCategoryEi  0x002ee67d  112 bytes
```

## Source form

The function stores the selected category, resets the list count and
collects the identifiers of all achievements in that category, then
publishes the count.

Details that the retail bytes require:

- **Guard against the reset count.** The loop guard compares the
  achievement count with the list count that was just reset to zero, read
  back through a file-local view. The value is the same as comparing with
  zero. At branch-prediction time the comparison is against a load, so the
  opcode heuristic for comparisons with zero does not apply and only the
  early-return heuristic does. The resulting entry and exit frequency ranks
  `this` above the loop index in global register allocation, as retail
  does. RTL CSE later forwards the stored zero, so the code is still a
  compare with zero. The margin in the allocation ranking is small.
- **Declaration.** The `Achievements` class is defined in `MenuWidget.cpp`,
  so its `SetCategory` declaration is added there; no shared header
  changes.

No branch hint, inline assembly, register constraint or output edit is used.
The other MenuWidget.cpp functions keep their bytes.

## Verification

`python -B tools/build.py` passes for ai-startup-menuwidget and
ai-startup-menustate. A fresh complete build, `python -B tools/build.py
--all`, exited 0 with 5,616 function, 5,709 section and 180 region
comparisons and no mismatch or skip; the previous baseline was 5,615, 5,709
and 180.
