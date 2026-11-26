# PhysicAttributes::SetHeightAttributes scene-node overload exact match

`PhysicAttributes::SetHeightAttributes(irr::scene::ISceneNode*,
irr::core::vector3d<float> const&, PhysicInfo&)` matches all 1,040 retail
bytes at Thumb address `0x0031b3e9`, including relocations.

```text
OK  _ZN16PhysicAttributes19SetHeightAttributesEPN3irr5scene10ISceneNodeERKNS0_4core8vector3dIfEER10PhysicInfo  0x0031b3e9  1040 bytes
```

## Source form

This overload finds the triangle under a position in a scene node's mesh
buffers. For each triangle it stores the three vertices in the physic
information, tests whether the position lies inside and, when it does,
computes the plane normal and interpolates the height.

Details that the retail bytes require:

- **Normal from the stored vertices.** The two edges for the normal are
  read back from the vertices just stored in the physic information, not
  from the local copies. The values are the same. As memory reads, the
  vertex Z components each have one use, so tree sinking leaves them where
  they are computed, as retail does, and the normal is not built from the
  in-loop edge. RTL CSE later replaces the loads with the stored values.
- **Offset declared first.** The node offset is declared before the vertex
  and edge vectors and assigned in the loop. Its components get low SSA
  version numbers, which give retail's addition operand order and spill
  slots.
- **Loop compare.** The buffer loop uses an `int` index compared as
  `getMeshBufferCount() > (unsigned int)i`, which gives retail's compare
  operand order.
- **No block-scope using-declarations.** The mesh types are written fully
  qualified. The already-matched `FindLowerCostNode`, compiled later in the
  translation unit, depends on how many declarations the compiler has
  created before it. With the using-declarations, its register choice
  changes.
- **Definition without a header change.** The overload is defined through
  its mangled name.

No branch hint, inline assembly, register constraint or output edit is used.
The other PhysicAttributes.cpp functions keep their bytes.

## Verification

`python -B tools/build.py ai-startup-physicattributes` passes. A fresh
complete build, `python -B tools/build.py --all`, exited 0 with 5,609
function, 5,709 section and 180 region comparisons and no mismatch or skip;
the previous baseline was 5,608, 5,709 and 180.
