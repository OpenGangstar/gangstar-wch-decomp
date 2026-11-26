# NPC::Update exact match

`NPC::Update(int)` matches all 3012 retail bytes at Thumb address
`0x002ffe0d`, including relocations.

```text
OK  _ZN3NPC6UpdateEi  0x002ffe0d  3012 bytes
```

## Source form

The per-frame NPC update handles fading, cliff and destination steering,
cinematic and vehicle states, door handling and target tracking. Each of the
following forms is commented in the source; none emits code beyond retail's:

- **Destination reload.** `dY` and `dX` are read and stored straight back
  before the differences are computed, which gives retail's reload of
  `destination.Y`.
- **Branch probabilities.** A one-field struct test on `initialTarget`, a
  documented `__builtin_expect` on `getVehicle()`, no-code prefetch hints and
  a split stop-flag test give retail's block order.
- **Door paths.** The `GetSpeed() <= 10.0f` tests are written with inverted
  arms so the keep path's reload comes first in RTL order, as retail's
  register rotation requires.
- **Identical-arm statements.** Two statements of the form
  `if (t) X; else X;` (a `SetTarget(0)` call pair and an `unknown264` load
  pair) survive until after register allocation, where cross-jumping merges
  the arms and the test is deleted. Their reloads set the rotation so the
  player compare uses retail's register, which also makes the scheduler
  order `SetTarget`'s arguments as retail does.

## Integration

The shared PhysicInfo constructor rule now also takes the NPC object's
linkonce copy. The PlayerTest unit, which links the NPC object, places the
function and the NPC and Character functions it references.
