# Trail::BuildPoint exact match

`Trail::BuildPoint(int, bool)` matches all 812 retail bytes at Thumb address
`0x00348735`, and its strict section ends at the retail extent.

```text
OK  _ZN5Trail10BuildPointEib  0x00348735  812 bytes
OK SECTION .trail_build_point  0x00348734  812 bytes
```

## Source form

The body builds the segment direction, the cross-product normal and the left and
right edge points with `vector3d<float>` operators. It then writes both vertices
of the strip through local views of the mesh-buffer vertex array.

- **The normal.** The `crossProduct` result is assigned into a
  default-constructed `normal`. This keeps all three zero stores and retail's
  84-byte frame.
- **The edge points.** `p1 = center - normal * halfWidth` and
  `p2 = normal * halfWidth + center` are written without a named `offset`
  vector.
  - A named offset is split by SRA into a newer `offset$Z` with a lower pseudo
    number.
  - That swaps the offset.Z and center.Z spill slots, and the different SSA
    versions flip the operand order of two adds.
  - Without it, the product temporaries are older than the subtraction's load
    temporaries, as in retail.
- **Vertex positions** are stored one component at a time.

The texture-row table `g_trailTexOffsetY` (`{0,1},{0.25,0.5},{0.5,0.75}`) is
defined in Trail.cpp and placed at its retail address `0x00435a48`, where retail
holds the same six floats.

No header change, branch hint, inline assembly, register constraint or output
edit is used.

## Verification

`python -B tools/build.py --all` exited 0 with 5,541 function, 5,623 section
and 181 region comparisons and no mismatch or skip. Unit tests, repository
checks and progress checks pass.
