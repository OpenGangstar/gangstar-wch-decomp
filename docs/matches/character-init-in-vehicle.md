# Character::initInVehicle exact match

`Character::initInVehicle(Vehicle*)` matches all 456 retail bytes at Thumb
address `0x002f48b1`, and its strict section ends at the retail extent.

```text
OK  _ZN9Character13initInVehicleEP7Vehicle  0x002f48b1  456 bytes
OK SECTION .character_init_in_vehicle  0x002f48b0  456 bytes
```

## Source form

The function does the following, in order:

1. hides the character and attaches it to the vehicle as driver;
2. sets the in-vehicle movement flag and removes collisions;
3. moves the character to the vehicle position;
4. rotates the scene node by the vehicle transform turned 90 degrees about Z;
5. places the physics body at the left door, offset along the vehicle's right
   and front vectors. The offsets are 111/11 for low vehicles and 118/21
   otherwise;
6. starts the vehicle's seated animation.

The earlier form differed in 9 bytes because the libcall arguments of the
offset multiplies were in the wrong order:

- **Cause.** With a by-value scalar, copy propagation re-folds `offset * load`
  by SSA version.
- **Fix.** Scaling through the file-local
  `scaleVector(const vector3d<float>&, const float&)` helper takes the offset's
  address during the early passes. That delays its renaming, so the fold keeps
  retail's `load * offset` order and register allocation.

No header change, branch hint, inline assembly, register constraint or output
edit is used.

## Verification

`python -B tools/build.py --all` exited 0 with 5,554 function, 5,637 section
and 181 region comparisons and no mismatch or skip. Unit tests, repository
checks and progress checks pass.
