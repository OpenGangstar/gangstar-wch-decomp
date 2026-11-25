# Wheel constructor exact match

```text
OK  _ZN5WheelC1EP7ASpritei  0x0032cbe1  256 bytes
OK  _ZN5WheelC2EP7ASpritei  0x0032cbe1  256 bytes
OK SECTION .wheel_constructor  0x0032cbe0  256 bytes
```

Builds the `HudElement` base, anchors the element at its first frame module,
derives a touch region padded by 30 around the module image and stores the
wheel centre.

- `Wheel.h` names the previously opaque `unknown64`/`unknown76` pairs as
  `centerX`/`centerY` and `previousTouchX`/`previousTouchY` (same offsets and
  sizes) and adds an inline `setAnchor` helper; existing Wheel matches still
  pass.
- `right = left + right` (reassigning the same variable) and the store order
  `[2], [0], [1], [3]` reproduce retail's schedule.

`HudElement` C1 and the soft-float helpers (`i2f`, `fadd`, `ui2f`) are bound to
retail addresses; the placement is mirrored in `WheelTouchThunk.ld`.

Full gate: `python -B tools/build.py --all` exited 0 with 5,499 function,
5,574 section and 181 region comparisons and no mismatch or skip.
