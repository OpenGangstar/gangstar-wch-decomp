# VehicleCamera::goToSide exact match

`VehicleCamera::goToSide(bool)` matches all 304 retail bytes at Thumb
`0x003351dd`, and its strict 304-byte section ends at the matched
`VehicleCamera::init` boundary.

```text
OK  _ZN13VehicleCamera8goToSideEb  0x003351dd  304 bytes
OK SECTION .vehicle_camera_go_to_side  0x003351dc  304 bytes
```

## Source form

The reviewed historical body stored the selected side vector in a named
`side` local. It emitted the correct instructions but swapped the stack slots
of the two `GetRight()` return temporaries (eight differing bytes at
`0x90`-`0xa4` and `0x118`-`0x124`). Writing the conditional directly inside the
multiplication changes the temporaries' creation order and reproduces retail:

```cpp
vector52 = (left ? vehicle->GetRight() : -vehicle->GetRight())
    * static_cast<float>(vehicle->cameraSideDistance);
```

Calls, field reads, conversions and stores are unchanged; the false arm still
negates the returned vector, which retail does by flipping each sign bit. No
branch hint, inline assembly, register constraint or output edit is used. The
existing `Vehicle` camera fields and friend declaration are reused unchanged.

## Verification

`python -B tools/build.py ai-startup-vehiclecamera` passed every function and
section of the unit, including the lines above. A fresh complete
`python -B tools/build.py --all` exited 0 with 5,468 function, 5,491 section and
181 region comparisons and no mismatch or skip.
