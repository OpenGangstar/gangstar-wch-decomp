# Vehicle::getCollisionRect exact match

`Vehicle::getCollisionRect(irr::core::vector3d<float>*, float)` matches all
752 retail bytes at Thumb address `0x0030ae3d`, including relocations.

```text
OK  _ZN7Vehicle16getCollisionRectEPN3irr4core8vector3dIfEEf  0x0030ae3d  752 bytes
```

## Source form

The function transforms the vehicle's collision polygon into world space,
then builds the four corners of its collision rectangle from the right and
front vectors, widened by a margin.

Details that the retail bytes require:

- **Overwritten store in the vertex loop.** Between the Y and X additions,
  `points[static_cast<unsigned int>(i)].y` is assigned the body angle; the
  same element is overwritten later in that iteration. The store survives
  early dead-store elimination long enough to make partial redundancy
  elimination hoist the angle load as a third float value, which gives
  retail's spill-slot order for the position and rotation values. No code
  is emitted for it.
- **Unused member reads.** Seven member fields are read into unused locals
  at the start. They are removed as dead code, but the SSA names they
  release are reused by the scalarised right and front components, which
  then have lower versions than `margin`. Operand canonicalisation therefore
  gives retail's operand order in the four post-loop multiplies.

Both forms are contrived but behaviour-preserving, and carry source
comments. No branch hint, inline assembly, register constraint, flag
change, output edit or header change is used. CreateWheels and the other
Vehicle.cpp functions keep their bytes.

## Verification

`python -B tools/build.py vehicle-cleanup` passes. A fresh complete build,
`python -B tools/build.py --all`, exited 0 with 5,650 function, 5,713
section and 180 region comparisons and no mismatch or skip; the previous
baseline was 5,649, 5,713 and 180.
