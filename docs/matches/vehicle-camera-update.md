# VehicleCamera::update exact match

`VehicleCamera::update(float)` matches all 968 retail bytes at Thumb address
`0x00335849`, including relocations.

```text
OK  _ZN13VehicleCamera6updateEf  0x00335849  968 bytes
```

## Source form

The camera follows its vehicle in four steps:

1. **Distance.** The follow distance grows or shrinks with the vehicle's
   acceleration when the camera is nearly behind or nearly in front of it, then
   is clamped between the vehicle's minimum and maximum camera distances.
2. **Swing.** When the vehicle reverses or drives forward against the camera,
   the follow direction rotates about Z. The rotation is proportional to speed,
   with the sign given by the side component.
3. **Look-at.** The look-at point is the vehicle position plus the look-ahead
   vector, with the configured look height.
4. **Position.** The camera position is the vehicle position plus the follow
   vector, at the configured camera height. It keeps the previous height delta.

Four source details reproduce retail's operand and load order:

- `getFacing()` is called before the vehicle basis vector is copied into a
  local, so SRA loads its three components after the call.
- The clamps are written as inline comparisons against the converted limits.
  Named minimum and maximum locals swap the compare operands.
- The swing sign is an inline ternary multiplied last.
- The negated angle is a separate statement, which stops fold from pushing the
  negation into the constants.

`Vehicle.h` names the int at `+932` `cameraMinDistance`. It was previously the
second half of an opaque byte array; the layout is unchanged.
`vector3d::normalize` and `rotateXYBy` are reached through the GOT through
their existing weak declarations. `Vehicle::getVelDirec` is bound as a Thumb
function. The double-precision compare helpers are bound to their PLT stubs.

No branch hint, inline assembly, register constraint or output edit is used.

## Verification

`python -B tools/build.py ai-startup-vehiclecamera` passes every function and
section check. A fresh complete build, `python -B tools/build.py --all`, exited 0
with 5,581 function, 5,665 section and 181 region comparisons and no mismatch or
skip; the previous baseline was 5,580, 5,664 and 181. The `Vehicle.h` field name
changes no other matched function.
