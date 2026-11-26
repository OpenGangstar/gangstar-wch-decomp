# ASprite::PaintModule exact match

`ASprite::PaintModule(int, int, int, int) const` matches all 512 retail bytes
at Thumb address `0x00349e15`, including relocations.

```text
OK  _ZNK7ASprite11PaintModuleEiiii  0x00349e15  512 bytes
```

## Source form

The function draws one sprite module at a position, with the module's
source rectangle, the global colour and transform, through the video
driver's `draw2DImage`.

Details that the retail bytes require:

- **Destination rectangle through a helper.** The destination rectangle is
  built by a file-local helper with Irrlicht's `rect(position, dimension)`
  body, called with the absolute module width and height. That leaves the
  height's absolute value as the last statement of its block, and tree
  sinking moves only that statement, so the width's chain stays before the
  corner stores and the height's subtraction lands after them, as retail
  has it.
- **Definition without a header change.** `ASprite.h` does not declare the
  method and its fields are private, so the function is defined through
  its mangled name with file-local views of the sprite, the sprite data
  and the video driver's vtable slot.

No branch hint, inline assembly, register constraint, output edit or header
change is used. The other ASprite.cpp functions keep their bytes.

## Verification

`python -B tools/build.py asprite-startup` passes. A fresh complete build,
`python -B tools/build.py --all`, exited 0 with 5,633 function, 5,713
section and 180 region comparisons and no mismatch or skip; the previous
baseline was 5,632, 5,713 and 180.
