# PhysicAttributes::IntersectSegmentWithHeightMap (PhysicInfo overload) exact match

`PhysicAttributes::IntersectSegmentWithHeightMap(PhysicInfo&, plane3d<float> const&,
vector3d<float> const&, vector3d<float> const&, vector3d<float>&, vector3d<float>&)`
matches all 4800 retail bytes at Thumb address `0x0031b9a9`, including
relocations. The other sections of `PhysicAttributes.cpp` are unchanged,
including the detailed `GetHeight`, `AddCollisionShapes`,
`ContactListener::Add`, `GetNextRandomPos` and `FindLowerCostNode`.

## Source form

The function walks a segment across height-map triangles, testing each
triangle's three edges against the segment through three overlap loops. The
retail stack slots and compare operand orders follow GCC's SSA-name numbering.
Every detail that steers it is behaviour-preserving, emits no code and is
commented in the source:

- **Loop-0 read-once local.** The loop-0 check reads `pa.Y` into a local. That
  removes one dead copy before ivopts and shifts its last-in-first-out free list,
  so all three loop compares get retail's operand order.
- **Loop-1 dead pad.** A never-taken store, guarded by `(buffer & 3) > 3`, of a
  13-term xor chain. VRP removes it, and the freed names give `bc$X`'s root to
  the loop-1 definition, as in retail.
- **Loop-2 side block.** After `subTo(pc)` the body jumps to a side block that
  holds a 3-term dead pad, then jumps back. A never-taken branch into the block
  keeps it separate until SSA. dce2 frees its names last, and they become
  `pb$X`'s PHI names, so out-of-SSA creates `pb`'s temps before `pc`'s
  (retail slots 244/248/252).
- **Placement and pad.** The function is defined before the detailed `GetHeight`,
  and an 8-enumerator pad after it keeps the later functions' temporaries
  unchanged.
