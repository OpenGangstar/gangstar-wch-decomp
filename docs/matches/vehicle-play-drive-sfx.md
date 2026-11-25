# Vehicle::playDriveSfx exact match

`Vehicle::playDriveSfx(unsigned int)` matches all 672 retail bytes at Thumb
address `0x00312d19`, and its strict section ends at the retail extent.

```text
OK  _ZN7Vehicle12playDriveSfxEj  0x00312d19  672 bytes
OK SECTION .vehicle_play_drive_sfx  0x00312d18  672 bytes
```

## Source form

When the sound flag is set, the function does the following, in order:

1. With skid and all four wheels grounded, it starts the skid sound (123) once.
2. Otherwise, under the same grounded conditions, it manages the 106 drive
   loop.
3. Otherwise it stops 123.
4. It records an airborne state and plays a random small-impact sound on
   landing.
5. It refreshes the engine pitch for speeds above 1 and stores the 0/1 drive
   state.

An earlier body was probe-equal only with a new `Vehicle.h` member
declaration. That declaration perturbs the matched
`GameObjectManager::GetMetatypeFromName` through declaration UIDs.

The function is therefore an `extern "C"` definition of the retail mangled name.
It reads the private fields through a file-local `VehicleDriveSfxView` taken
from the `Vehicle.h` layout, and calls the private `_adjustEnginePitch` through
a local mangled declaration. No header is changed.

With `this` as an explicit parameter, the two state locals must be declared
`int newState; int state;` in that order to reproduce retail's register
assignment.

No branch hint, inline assembly, register constraint or output edit is used.

## Verification

`python -B tools/build.py --all` exited 0 with 5,560 function, 5,643 section
and 181 region comparisons and no mismatch or skip. `GetMetatypeFromName` and
`FindLowerCostNode` remain exact. Unit tests, repository checks and progress
checks pass.
