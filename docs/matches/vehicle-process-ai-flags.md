# Vehicle::_processAIFlags exact match

`Vehicle::_processAIFlags()` matches all 3220 retail bytes at Thumb address
`0x00312081`, including relocations.

```text
OK  _ZN7Vehicle15_processAIFlagsEv  0x00312081  3220 bytes
```

## Source form

`_processAIFlags` runs the AI driver's per-frame flag logic. It handles:

- target detection, pursuit and waiting;
- sensor braking and steering towards the target;
- sirens and the AI events.

Details that the retail bytes require:

- **Direction declaration.** `vector3df direction` is declared before the
  `aiTarget` scene-node check. Its initialising stores sit in that join, which
  stops DOM1 jump threading, so PRE inserts the per-tail `aiTarget` reloads
  retail has. The 344 offset stays in `r8`.
- **Siren condition.** The siren condition ends in a file-local
  `static inline bool isDrivenByPlayer(const LevelObject*)` made of
  if-returns. The helper's join keeps the flags load from being treated as
  partially redundant. Retail's rematerialised 344 at the merged siren join
  follows, together with its literal-pool placement and registers.
- **Section size.** The section is 3224 bytes, made up of the 3220-byte
  function and the retail `c046c046` padding.

## Header changes

The header changes were checked by compiling all 183 game translation units
with and without them; the objects are identical.

- **`Vehicle.h`:** declares the private `_processAIFlags()`.
- **`LevelObject.h`:** makes `Vehicle` a friend, for `aiTarget->sceneNode`.

## Data

The inline `PhysicInfo` constructor copy is placed at its retail address
`0x00319dd0`. `__aeabi_dcmplt` is bound at its PLT address.

No branch hint, inline assembly, register constraint, flag change or output
edit is used.

## Verification

`python -B tools/build.py vehicle-cleanup` passes. A fresh complete build, `python -B tools/build.py --all`, exited 0 with
5,598 function, 5,702 section and 180 region comparisons and no mismatch or
skip; the previous baseline was 5,596, 5,700 and 180.
