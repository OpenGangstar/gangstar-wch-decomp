# Character::setAnimation(int, float, bool, bool, bool) exact match

```text
OK  _ZN9Character12setAnimationEifbbb  0x002f1d91  396 bytes
OK SECTION .character_set_animation  0x002f1d90  396 bytes
```

Starts an animation clip unless animations are locked (`movementFlags` bit 11)
or the same clip is playing. An id of -1 clears the animation state. A running
non-looping clip that cannot be interrupted (outside cinematics) defers the new
clip through `setNextAnimation`. Leaving the rocket animation 67 with a weapon
of type 7 reloads the rocket; clip 164 sets the top movement flag. The clip's
start, end and length come from the shared timeline controller.

- The lock test is retail's `lsls #20; bmi`. Written inline as
  `(int)(movementFlags << 20) < 0`, GCC's "opcode positive" guess predicts the
  shared `return false` block at 11.6% and lays it out late; the mask form
  `& 0x800` predicts 33% but emits `ands`. A bool-returning static inline helper,
  `isAnimationLocked`, gives the 33% guess while still lowering to `lsls`/`bmi`,
  which yields retail's block order.
- `Character.h` names the animation fields previously held in opaque padding
  (`animationStartFrame`, `animationEndFrame`, `animationSpeed`,
  `animationFlag149`, `animationFlag150`; layout unchanged), and
  `core/SceneNode.h` names `ITimelineController` slots 8-10 as
  `getClipStart`, `getClipEnd` and `getClipLength` (vtable offsets 32-40).

`Weapon::getWeaponType`, `Weapon::reloadRocket`, `ScriptManager::getInstance`
and `ScriptManager::isInCinematic` are bound to retail Thumb addresses. No hint,
inline assembly or register constraint is used.

Full gate: `python -B tools/build.py --all` exited 0 with 5,523 function,
5,600 section and 181 region comparisons and no mismatch or skip.
