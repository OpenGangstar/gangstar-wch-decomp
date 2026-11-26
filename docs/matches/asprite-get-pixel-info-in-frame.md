# ASprite::GetPixelInfoInFrame exact match

`ASprite::GetPixelInfoInFrame(int, int, int, int&, int&)` matches all 296
retail bytes at Thumb address `0x0034a28d`, including relocations.

```text
OK  _ZN7ASprite19GetPixelInfoInFrameEiiiRiS0_  0x0034a28d  296 bytes
```

## Source form

The function finds the topmost module of a sprite frame that contains a
point and returns that module's index and the colour of the pixel under the
point.

Details that the retail bytes require:

- **Pixel address shape.** The pixel is read as
  `(blob + image->unknown16 + (x + row))[column]`. An address used
  directly in a load is expanded as a sum that the compiler flattens and
  re-sorts, so the operand order depends on the tree's shape; only this
  shape gives retail's `((blob + offset) + x) + row` with the column as the
  index. It also computes the row first, so the registers and the spill
  of `x` match retail.
- **Typed blob pointers in the loop.** The sprite data tables are read
  through a file-local view and reloaded inside the loop, as in the earlier
  near miss.
- **Definition without a header change.** The method is defined through
  its mangled name and reuses the sprite view of `PaintModule`.

No branch hint, inline assembly, register constraint, output edit or header
change is used. The other ASprite.cpp functions keep their bytes.

## Verification

`python -B tools/build.py asprite-startup` passes. A fresh complete build,
`python -B tools/build.py --all`, exited 0 with 5,635 function, 5,713
section and 180 region comparisons and no mismatch or skip; the previous
baseline was 5,634, 5,713 and 180.
