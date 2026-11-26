# AnalogStick constructor exact match

`AnalogStick::AnalogStick(ASprite*, int, int)` matches all 360 retail bytes
at Thumb address `0x00326581`, including relocations. The complete-object
and base-object constructors share the same code.

```text
OK  _ZN11AnalogStickC1EP7ASpriteii  0x00326581  360 bytes
```

## Source form

The constructor builds the HUD element, records the base frame's origin,
sets a 140-pixel touch region centred on the base module, records the
handle's centre and computes the stick radius from the two module widths.

Details that the retail bytes require:

- **Right edge recomputed from memory.** Retail computes the right edge of
  the touch region before any of the region stores. GCC 4.2.1's
  temporary-expression replacement moves a single-use expression into its
  use unless the expression reads memory and a store intervenes. The right
  edge is therefore recomputed from the frame-module origin and the module
  width, read through two file-local view structs. As distinct memory
  expressions, tree value numbering does not share them with the left
  edge, and RTL CSE later merges the duplicate loads and conversions. The
  value equals `left + 140`.
- **Store order.** The region is written top, left, right, bottom, which
  keeps the left edge at its definition. Instruction scheduling then gives
  retail's store order.
- **Field names.** `AnalogStick.h` names the stick radius and the handle's
  draw origin and position fields, which were byte arrays. The layout is
  unchanged.

No branch hint, inline assembly, register constraint or output edit is used.
The other AnalogStick.cpp functions keep their bytes.

## Verification

`python -B tools/build.py` passes for sdk-startup-analogstick and
hud-manager-helpers. A fresh complete build, `python -B tools/build.py --all`,
exited 0 with 5,607 function, 5,709 section and 180 region comparisons and no
mismatch or skip; the previous baseline was 5,606, 5,709 and 180.
