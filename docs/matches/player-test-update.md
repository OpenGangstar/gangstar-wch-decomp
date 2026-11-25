# PlayerTest::Update exact match

`PlayerTest::Update()` matches all 2228 retail bytes at Thumb address
`0x00304ec9`, including relocations.

```text
OK  _ZN10PlayerTest6UpdateEv  0x00304ec9  2228 bytes
```

## Source form

`Update` is the per-frame player step. It updates the following in order:

1. Turning, destination checks and death-water health.
2. Death handling and the wanted level.
3. Car interaction, cinematic driving state, movement and animation.
4. Shop proximity on the HUD, and terrain height.

Details that the retail bytes require:

- **Flag tests.** The 0x4000, 0x1000 and 0x2000 flag tests go through a
  file-local `hasFlags(flags, mask)` helper that returns
  `(flags & mask) == mask`. In the block that first tests a mask, combine
  folds the test into a shift. A later recheck reuses the CSE'd constant and
  keeps the retail and/cmp form. With this form the checkWanted test gets
  only the call heuristic, which gives retail's cold-block order. It also
  avoids reusing the AND result as a stored zero.
- **Cinematic driving.** After `updateCarInteraction`, `finishedStopDriving` is
  called in an `else if (!vehicleVisibleInCinematic)` branch. Retail's
  branch skips the visibility check when `updateCarInteraction` runs. The
  earlier draft tested it unconditionally, which was a real behavioural
  difference.
- **Turn reset.** `turning = false` comes before the `turnDirection` reset, the
  same order `Character.cpp` uses. That gives retail's store schedule.

Callees in sections that this unit's link would otherwise discard are placed
at their retail addresses:
- the three `CHudManager` shop functions;
- `PhysicAttributes::GetHeight(vector3d const&, int, bool)`.

`__aeabi_ui2f` and `cosf` are bound at their PLT addresses. The unit's inline
`PhysicInfo` constructor copy joins the shared placement at `0x00319dd0`.

No branch hint, inline assembly, register constraint or output edit is used,
and no header change.

## Verification

`python -B tools/build.py ai-startup-playertest` passes. A fresh complete build, `python -B tools/build.py --all`, exited 0 with
5,599 function, 5,687 section and 181 region comparisons and no mismatch or
skip; the previous baseline was 5,597, 5,685 and 181.
