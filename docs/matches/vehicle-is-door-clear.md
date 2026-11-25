# Vehicle::isDoorClear exact match

`Vehicle::isDoorClear(bool, b2Body*) const` matches all 396 retail bytes at
Thumb address `0x0030a731`, including relocations.

```text
OK  _ZNK7Vehicle11isDoorClearEbP6b2Body  0x0030a731  396 bytes
```

## Source form

`isDoorClear` queries the physics world around the left or right door and
returns `false` when a relevant shape blocks either door segment. A shape is
skipped when any of these hold:

- it is in another group with category 0;
- it has a zero mask;
- it is a sensor;
- it belongs to the given body or to the vehicle's own collision body.

Details that the retail bytes require:

- **Group test.** It is a file-local `static inline bool` helper, written as
  if-returns. The mask test stays a separate `continue`, which gives retail's
  forwarder blocks.
- **Body test.** It is a second if-return helper with the `body != 0` arm
  first. Splitting the body checks into three separate continue edges lets
  PRE insert the loop's end-pointer address on seven edges. That ranks it
  last in global allocation and gives retail's `r8`, `sl`, `r9` and `fp`
  assignments. The arm order sets the round-robin `r2`/`r3` reload
  rotation.
- **Definition style.** The function is defined through its mangled name with
  a file-local `VehicleDoorClearView`, so no `Vehicle.h` declaration is needed.
  PlayerTest already calls it through an `extern "C"` declaration.

No branch hint, inline assembly, register constraint or output edit is used,
and no header change. The other Vehicle.cpp functions keep their bytes.
`memset` is bound at its PLT address.

## Verification

`python -B tools/build.py vehicle-cleanup` passes. A fresh complete build, `python -B tools/build.py --all`, exited 0 with
5,600 function, 5,704 section and 180 region comparisons and no mismatch or
skip; the previous baseline was 5,599, 5,703 and 180.
