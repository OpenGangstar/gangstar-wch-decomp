# PhysicAttributes::SetHeightAttributes exact match

`PhysicAttributes::SetHeightAttributes(irr::core::vector3d<float> const&,
PhysicInfo*)` matches all 1,388 retail bytes at Thumb address `0x0031ad31`,
including relocations.

```text
OK  _ZN16PhysicAttributes19SetHeightAttributesERKN3irr4core8vector3dIfEEP10PhysicInfo  0x0031ad31  1388 bytes
```

## Source form

The function finds the heightmap triangle under a position. It walks the
triangles that overlap the position's cell, uses edge cross products to test
whether the point lies inside each one, and interpolates the height from the
triangle's plane. When an edge test fails and the segment crosses a
neighbour, it records the neighbour and retries there. It fills the physic
information and returns the height.

Details that the retail bytes require:

- **Declaration order and SSA versions.** GCC 4.2.1 orders the operands of
  commutative operations by SSA version number. The six edge vectors are
  declared at the top of the function, before the heightmap offset. Scalar
  replacement then creates their components first, so they reuse the freed
  version numbers and the offset's components get new, higher ones. That
  gives retail's addition operand order and spill-slot order. The unused
  initial values are removed by the compiler.
- **Offset helper.** The heightmap's absolute position is read through an
  inline helper that returns it by value.
- **Retry blocks.** Each of the three edges has its own `if` block that
  stores the neighbour and recurses. CSE and cross-jumping then give
  retail's shared and merged paths.
- **Definition without a header change.** This overload is not declared in
  `PhysicAttributes.h`, so the function is defined through its mangled name.

No branch hint, inline assembly, register constraint or output edit is used.
The other PhysicAttributes.cpp functions keep their bytes.

## Verification

`python -B tools/build.py ai-startup-physicattributes` passes. A fresh
complete build, `python -B tools/build.py --all`, exited 0 with 5,608
function, 5,709 section and 180 region comparisons and no mismatch or skip;
the previous baseline was 5,607, 5,709 and 180.
