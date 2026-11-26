# PlayerTest::moveTo exact match

`PlayerTest::moveTo(Vehicle const&)` matches all 620 retail bytes at Thumb
address `0x00302361`, including relocations.

```text
OK  _ZN10PlayerTest6moveToERK7Vehicle  0x00302361  620 bytes
```

## Source form

`moveTo` picks the nearer clear door of the vehicle. If the player is within
30 units, it turns to face the door. Otherwise it starts walking towards the
door.

Details that the retail bytes require:

- **Door choice.** The choice is one condition, `rightClear && (leftDistance >
  rightDistance || !leftClear)`, with a single store per door. That gives
  retail's register kick priority.
- **Walk-towards path.** It copies `adjustedDestination` through a named
  `const` local before the subtraction, which stops TER folding the loads
  into the soft-float calls.
- **Inherited calls.** The inherited calls are made directly on the player
  object.

## Definition without a header change

A class declaration of `moveTo` in `PlayerTest.h` alters the matched
`ServiceMissions::GotFocus`. The function is therefore defined through its
mangled name with an explicit `self`, which compiles exactly like the
implicit `this`. PlayerTest's `Update` already calls it this way.

Private members are reached as follows:
- **Vehicle doors:** a file-local view at `+316`.
- **Destination fields:** `destination` and `adjustedDestination` are read
  through a view at `+96` from the player. A view relative to the `Character`
  subobject changes register allocation.
- **`Character::getSpecificAnimation`:** called through an `extern "C"`
  declaration.

No branch hint, inline assembly, register constraint or output edit is used,
and no header change. Update, switchContext, updateAnim and
getAttackableTarget keep their bytes.

## Verification

`python -B tools/build.py ai-startup-playertest` passes. A fresh complete build, `python -B tools/build.py --all`,
exited 0 with 5,601 function, 5,705 section and 180 region comparisons and no
mismatch or skip; the previous baseline was 5,600, 5,704 and 180.
