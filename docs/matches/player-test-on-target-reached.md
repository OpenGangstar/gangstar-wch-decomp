# PlayerTest::onTargetReached exact match

`PlayerTest::onTargetReached()` matches all 60 retail bytes at Thumb address
`0x003017b1`, including relocations.

```text
OK  _ZN10PlayerTest15onTargetReachedEv  0x003017b1  60 bytes
```

## Source form

When the player reaches the car it was running to, the function leaves
combat mode, hides the weapon, takes the car through `justStoleCar`, clears
the stored car, sets the follow-up state and clears flag `0x1000`.

Details that the retail bytes require:

- **Statement order.** The stored car is cleared right after the
  `justStoleCar` call, before the state and flag stores. The shorter
  lifetime of the zero store gives its offset priority over `this` in local
  register allocation, and scheduling still emits retail's store order.
- **Definition without a header change.** The method is not declared in
  `PlayerTest.h`, so it is defined through its mangled name directly after
  `justStoleCar`. `PlayerTest::Update` already calls it through an
  `extern "C"` declaration. An earlier attempt that added a header
  declaration changed `NPC::equipWeapon`.

No branch hint, inline assembly, register constraint or output edit is used.
The other PlayerTest.cpp functions keep their bytes.

## Verification

`python -B tools/build.py ai-startup-playertest` passes. A fresh complete
build, `python -B tools/build.py --all`, exited 0 with 5,613 function, 5,709
section and 180 region comparisons and no mismatch or skip; the previous
baseline was 5,612, 5,709 and 180.
