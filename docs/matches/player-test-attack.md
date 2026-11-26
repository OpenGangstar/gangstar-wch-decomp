# PlayerTest::attack exact match

`PlayerTest::attack(bool)` matches all 352 retail bytes at Thumb address
`0x00305a1d`, including relocations.

```text
OK  _ZN10PlayerTest6attackEb  0x00305a1d  352 bytes
```

## Source form

`attack` fires the current weapon at the acquired target when the weapon is
ready and the player is aimed, or readies the weapon. It returns whether an
attack happened.

Details that the retail bytes require:

- **Flag test.** The `0x4000000` flag test goes through a file-local
  `attackHasFlags(f, C)` helper that returns `(f & C) == C`.
- **Aim test.** The aim test is a file-local `static inline bool attackAimed()`
  made of if-returns: not locked returns `true`, otherwise it returns the
  facing test.
- **Why both are needed.** With both, the helper's return join and the
  condition shape change the block indices. Cross-jumping can then fold the
  ready path's `false` return into the shared `movs r0,#0` block, as in
  retail. Either change alone leaves an extra `movs r0,#0` in the ready
  block.
- **`Character::isDown`.** It is declared weak and called through the GOT. It
  is `STB_WEAK` in retail.

No branch hint, inline assembly, register constraint or output edit is used,
and no header change. The other PlayerTest.cpp functions keep their bytes.

## Verification

`python -B tools/build.py ai-startup-playertest` passes. A fresh complete build, `python -B tools/build.py --all`, exited 0 with
5,602 function, 5,706 section and 180 region comparisons and no mismatch or
skip; the previous baseline was 5,601, 5,705 and 180.
