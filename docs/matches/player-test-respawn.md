# PlayerTest::Respawn exact match

`PlayerTest::Respawn()` matches all 544 retail bytes at Thumb address
`0x003049e5`, including relocations.

```text
OK  _ZN10PlayerTest7RespawnEv  0x003049e5  544 bytes
```

## Source form

`Respawn` restores the player after death or arrest: it resets health,
wanted level and movement state, clears the target, repositions the player
and the camera, and restarts the idle animation.

Details that the retail bytes require:

- **Identical branches around the flag reset.** The reset of `flags240` and
  `unknown424` is written as `if (health > 0) { ... } else { ... }` with the
  same two stores in both branches. The join of the if/else ends the
  common-subexpression path, so the zero used for these stores gets its own
  register, and the later zeros use another one as in retail. The branch
  survives until after register allocation, which keeps retail's second
  zero argument to `_SetTarget`; cross-jumping then merges the identical
  branches and removes the test without leaving code. Behaviour is the same
  as storing the zeros directly. This form was accepted by the maintainer as
  byte-exact.
- **Definition without a header change.** The function is defined in
  `PlayerTest.cpp` after `teleportTo`, in retail order; `PlayerTest.h` is
  unchanged.

No branch hint, inline assembly, register constraint or output edit is used.
The other PlayerTest.cpp functions keep their bytes.

## Verification

`python -B tools/build.py ai-startup-playertest` passes. A fresh complete
build, `python -B tools/build.py --all`, exited 0 with 5,636 function, 5,713
section and 180 region comparisons and no mismatch or skip; the previous
baseline was 5,635, 5,713 and 180.
