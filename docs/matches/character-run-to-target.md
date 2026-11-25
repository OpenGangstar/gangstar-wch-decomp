# Character::runToTarget exact match

`Character::runToTarget(int)` matches all 296 retail bytes at Thumb address
`0x002f39e1`, including relocations.

```text
OK  _ZN9Character11runToTargetEi  0x002f39e1  296 bytes
```

## Source form

`runToTarget` returns early when there is no target, when the character is
already in one of the run animations 83, 84 or 85, or when its movement flags
block it. Otherwise it sets the run animation and moves towards the target,
scaled by the distance.

Details that the retail bytes require:

- **Early returns.** Each early-return condition is a separate
  `if (...) return;`. A single `||` chain makes VRP1 thread a copied return
  block to the end of the function, which moves the movement-flags test's
  reload to the end of the RTL stream. That shifts the round-robin `r2`/`r3`
  reload rotation for every later reload.
- **Target position.** The target position is copied through a
  `const vector3d<float>` local from an inline `positionOf` helper. That gives
  retail's `fadd(product, target)` operand order.

No branch hint, inline assembly, register constraint or output edit is used,
and no header change. The other Character.cpp functions are unchanged.

## Verification

`python -B tools/build.py ai-startup-character` passes. A fresh complete build, `python -B tools/build.py --all`, exited 0 with
5,594 function, 5,698 section and 180 region comparisons and no mismatch
or skip. The counts are lower than the previous 5,609, 5,700 and 181 because
the retired cash-draw-thunk unit re-checked functions, sections and one GOT
region that ai-startup-cash and other units already check. Matched coverage
rose from 77.08% to 77.19%.
