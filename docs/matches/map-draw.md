# Map::draw exact match

`Map::draw() const` matches all 304 retail bytes at Thumb address
`0x00328c49`, including relocations.

```text
OK  _ZNK3Map4drawEv  0x00328c49  304 bytes
```

## Source form

`draw` takes the following steps in order:

1. It resets the world transform.
2. It builds a texture matrix from the rotation, the negated offset, the
   offset and the uniform scale.
3. It draws the map texture at the pixel offset, clipped to the map
   rectangle.
4. It resets the texture transform.

Details that the retail bytes require:

- **Offset member.** Map's scroll offset at `+12` is an
  `irr::core::vector2d<float>` member named `offset`. It replaces two separate
  floats. Retail's scheduling places the second `offset.Y` load after the
  `center.Y` store but before the `center.X` store. GCC 4.2's
  `nonoverlapping_component_refs_p` only separates those memory references
  when both are field accesses of the same record type. With plain float
  members, every store may alias every load, and the order stays fixed.
- **Matrix call.** `CMatrix4<float>::buildTextureTransform` is called through
  the GOT with three `vector2d<float>` temporaries, as in retail.

## Header change

`Map.h` includes `Geometry.h` and declares `offset` as a `vector2d<float>`. The
constructor initialises it as `offset(0.0f, 0.0f)`.

The nonmatching MiniMap `draw2d` draft writes `offset.X` and `offset.Y`
instead of the old fields. No other source used the fields.

No branch hint, inline assembly, register constraint or output edit is used.

## Verification

`python -B tools/build.py sdk-startup-map` passes. `memset` is bound at its
PLT address `0x001c45d4`. A fresh complete build, `python -B tools/build.py --all`, exited 0 with
5,599 function, 5,687 section and 181 region comparisons and no mismatch or
skip; the previous baseline was 5,597, 5,685 and 181.
