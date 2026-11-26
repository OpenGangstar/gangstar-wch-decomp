# Vehicle::CreateWheels exact match

`Vehicle::CreateWheels(Box2DUserInfo*)` matches all 1408 retail bytes at
Thumb address `0x0030d149`, including relocations.

```text
OK  _ZN7Vehicle12CreateWheelsEP13Box2DUserInfo  0x0030d149  1408 bytes
```

## Source form

The function creates the front and rear wheel bodies, gives each a box
shape and mass, and joins them to the chassis with a revolute (front) and
prismatic (rear) joint.

Details that the retail bytes require:

- **Store order.** The first wheel offset's Z store comes before the rear
  wheel node is read. That moves the birth of the `592` offset constant
  three instructions earlier, lowering its local-alloc priority below
  `rear.X` but keeping it above `rear.Y`, which gives retail's high
  registers (rear.X in r8, 592 in sl, rear.Y in r9).
- **Field view.** The file-local `WheelView` declares the four wheel
  offsets as separate members (same offsets as before) rather than an
  array. Alias analysis can then tell the Z store and the wheel-node load
  apart, so the scheduler moves the load ahead of the store as retail
  does.
- **Earlier forms kept.** The rear node is read as its own statement, and
  the mass block uses no `left` local.
- **Linker.** The unit now emits the `b2ShapeDef`, `b2PolygonDef` and
  `b2CircleDef` destructors and vtables as link-once sections; the linker
  script places them at their retail addresses.

Behaviour is unchanged. No branch hint, inline assembly, register
constraint, flag change, output edit or header change is used.

## Verification

`python -B tools/build.py vehicle-cleanup` passes. A fresh complete build,
`python -B tools/build.py --all`, exited 0 with 5,647 function, 5,713
section and 180 region comparisons and no mismatch or skip; the previous
baseline was 5,646, 5,713 and 180.
