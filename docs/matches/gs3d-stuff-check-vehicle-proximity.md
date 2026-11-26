# GS3DStuff::checkVehicleProximity exact match

`GS3DStuff::checkVehicleProximity(std::vector<Vehicle*>&)` matches all 580
retail bytes at Thumb address `0x002dc715`, including relocations.

```text
OK  _ZN9GS3DStuff21checkVehicleProximityERSt6vectorIP7VehicleSaIS2_EE  0x002dc715  580 bytes
```

## Source form

The function finds the nearest vehicle in range whose door is clear,
records it on the player, and updates the HUD's near-car prompt unless the
car is dead or a cinematic is running.

Details that the retail bytes require:

- **Shared root for `nearest`.** `nearest` is declared as `LevelObject*`.
  The tail after the loop is a file-local inline helper, whose return value
  is assigned back to `nearest`. Copyrename coalesces the helper's variable
  into `nearest`, so the tail partition keeps the user variable and the loop
  partition becomes an out-of-SSA temporary. That temporary gets the lowest
  pseudo number and so retail's highest spill slot.
- **No re-test after the merge.** The tail is written as
  `(car = a) != 0 || (car = b) != 0`, with no second null test, so jump
  threading does not rebuild the merge with a later SSA version.
- **Interfaces.** The function is defined through its mangled `extern "C"`
  name to give retail's `bool` return without a header change, and
  `Vehicle::isDoorClear` is declared the same way. The vehicle's door data
  is read through a file-local view.

Behaviour is unchanged: the helper's result goes to a dead store, and call
and memory order are the same. No branch hint, inline assembly, register
constraint, flag change, output edit or header change is used. The other
GS3DStuff.cpp functions keep their bytes.

## Verification

`python -B tools/build.py gs3d-stuff` passes. A fresh complete build,
`python -B tools/build.py --all`, exited 0 with 5,642 function, 5,713
section and 180 region comparisons and no mismatch or skip; the previous
baseline was 5,641, 5,713 and 180.
