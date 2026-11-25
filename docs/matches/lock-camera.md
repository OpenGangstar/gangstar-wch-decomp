# LockCamera::init and LockCamera::update exact matches

Both remaining LockCamera methods now match byte for byte:

```text
OK  _ZN10LockCamera4initEP11LevelObjecti  0x00334a81  376 bytes
OK  _ZN10LockCamera6updateEf  0x00334c25  360 bytes
OK SECTION .lock_camera_vtable  0x004accf0  32 bytes
OK SECTION .lock_camera_init  0x00334a80  376 bytes
OK SECTION .lock_camera_update  0x00334c24  360 bytes
```

Neither function had a compiled candidate on record. Both follow the matched
VehicleCamera methods: the owner's `PlayerTest::_GetTarget()` supplies the target,
the camera sits 300 units behind the normalized owner-to-target direction,
80 units along the owner's right vector and 150 units above it, and looks at
the target raised by 120 units. `init` also stores the new owner first.

## Source details

- `pos += right * 80.0f` is required: retail stores each component right after
  its addition. `pos = pos + ...` emits four extra bytes and different
  registers. `src/game/core/Vector3.h` therefore gains upstream Irrlicht's
  `vector3d::operator+=`; no existing caller uses it, and every existing match
  is unchanged.
- The `PlayerTest` casts reproduce retail's null-checked `-4`/`+4` adjustments
  around `_GetTarget`, `GetPosition` and `GetRight`.
- Defining `update`, LockCamera's key method, emits its vtable; the linker
  places it at its retail address and the manifest compares it.
- `PlayerTest::_GetTarget` is still retail-only, so it is listed in
  `external_thumb_functions`; without it GNU ld turns the original Thumb `BL`
  into `BLX`. The soft-float helpers are bound to their retail PLT entries.

No branch hint, inline assembly, register constraint or output edit is used.

## Verification

`python -B tools/build.py ai-startup-lockcamera` passed every function, section
and GOT region check. A fresh complete `python -B tools/build.py --all` exited 0
with 5,470 function, 5,494 section and 181 region comparisons and no mismatch
or skip.
