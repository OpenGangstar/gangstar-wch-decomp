# SideMission::enableCheckpoints exact match

`SideMission::enableCheckpoints(irr::core::array<Checkpoint*>&,
irr::core::vector3d<float>)` matches all 332 retail bytes at Thumb address
`0x003470f9`, including relocations.

```text
OK  _ZN11SideMission17enableCheckpointsERN3irr4core5arrayIP10CheckpointNS1_12irrAllocatorIS4_EEEENS1_8vector3dIfEE  0x003470f9  332 bytes
```

## Source form

The function enables every checkpoint, shows each on the minimap and
returns the checkpoint nearest to the given position.

Details that the retail bytes require:

- **Loop compare order from SSA name reuse.** The loop compares a signed
  index cast to unsigned with the array size. The loop optimiser rewrites
  the cast into a new temporary, and a later fold puts the operand with the
  lower SSA version first. A new temporary reuses the most recently freed
  version number. The first distance is computed as
  `(position - checkpoints.data[0]->GetPosition()).getLengthSQ()`, whose
  struct temporary leaves a low version free; the cast temporary reuses it,
  so the compare keeps retail's index-first order.
- **Element access mix.** The first checkpoint's display call uses
  `checkpoints[0]`; the other reads use `checkpoints.data[...]` and the
  loop distance uses `getDistanceFromSQ`. This gives retail's store order
  and registers for the nearest-element return.

No branch hint, inline assembly, register constraint, output edit or header
change is used. The other SideMission.cpp functions keep their bytes.

## Verification

`python -B tools/build.py ai-startup-sidemission` passes. A fresh complete
build, `python -B tools/build.py --all`, exited 0 with 5,624 function, 5,710
section and 180 region comparisons and no mismatch or skip; the previous
baseline was 5,623, 5,710 and 180.
