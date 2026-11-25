# Wheel::processTouch exact match

`Wheel::processTouch(long)` matches all 300 retail bytes at Thumb address
`0x0032cfcd`, including relocations. Its 20-byte non-virtual thunk at
`0x0032cfb8` now links from the same object, so the `Wheel` vtable slot
resolves to the retail thunk address.

```text
OK  _ZN5Wheel12processTouchEl  0x0032cfcd  300 bytes
OK  _ZThn8_N5Wheel12processTouchEl  0x0032cfb8  20 bytes
```

## Source form

The body follows the retail instruction sequence:

1. It returns unless flag bit 0 is set.
2. It fetches the touch point, and logs an invalid ID with `printf` (string at
   `0x00425374`).
3. While the wheel is not yet turning (flag bit 1 clear), it rejects
   displacements that are larger than one on both axes, and also a zero
   displacement. The zero test is a single 32-bit load of the packed `x`/`y`
   pair.
4. It measures the horizontal distance from the first touch point. It records
   the direction, then clamps `distance / maximumDisplacement` to 1.0.
5. It raises an `EvWheelTurn` from a stack buffer, destroys the event, and then
   sets flag bit 1.

The destructor is called through a weak `extern "C"` declaration of
`_ZN11EvWheelTurnD1Ev`. That gives the out-of-line `bl` that retail makes, in
place of the inlined destructor.

### Documented branch hint

The zero-distance early return is written as
`if (__builtin_expect(!distance, 0))`. The maintainer clarification of
2026-10-25 allows `__builtin_expect` when it is documented. The hint changes
only block placement and allocation; every memory access and call is the same
as retail.

Without the hint, the same source gives 300 bytes with 21 unmasked differing
bytes:

```text
symbol _ZN5Wheel12processTouchEl retail 0x0032cfcc size 300; candidate size 300
unmasked differing offsets: 21 ['0x14', '0x16', '0x30', '0x4a', '0x4e', '0x6a', '0x77', '0x78', '0x8c', '0x94', '0xa4', '0xb0', '0xb8', '0xbc', '0xbe', '0xc0', '0xda', '0xde', '0xe4', '0xfa', '0x112']
DIFFERENT
```

No inline assembly, register constraint or output edit is used.

## Linking

`config/linker/WheelSdkStartup.ld` places:

- the function at `0x0032cfcc` and its thunk at `0x0032cfb8`;
- the format string at `0x00425374`;
- the `Point2D<short>` linkonce destructors and vtable at their retail
  addresses (`0x00326374`, `0x00326394`, `0x004abf88`), which are shared with
  AnalogStick and CameraManager.

It also binds `__aeabi_fdiv`, `__aeabi_fcmpgt` and `printf` to their PLT stubs.

## Verification

`python -B tools/build.py sdk-startup-wheel` passes every function and section
check of the unit. This includes `.wheel_vtable`, which links the thunk
address. A fresh complete build, `python -B tools/build.py --all`, exited 0
with 5,569 function, 5,652 section and 181 region comparisons and no mismatch
or skip; the previous baseline was 5,567, 5,650 and 181. The thunk verification
image `wheel-touch-thunk` now compiles the canonical unit.
