# LevelObject::canGoToPoint exact match

`LevelObject::canGoToPoint(vector3d<float> const&, vector3d<float>&,
vector3d<float>&)` matches all 3120 retail bytes at Thumb address `0x00317fb5`,
including relocations. The other sections of `LevelObject.cpp` are unchanged.

## Source form

The function casts the object's movement against the physics world. It walks
the shapes it hits, slides along their edges, and reports whether the target
point is reachable. Details that the retail bytes require, each commented in
the source:

- **Reload rotation.** In the edge loop, the `sideX + sideY` addition sits in
  identical arms selected by
  `__builtin_expect((unsigned long)this > 1 && (unsigned long)closestShape > 1, 0)`.
  Each high-register compare takes one reload. Together they advance reload's
  spill-register rotation so that the edge latch reloads into `r4`, as in
  retail. Crossjump merges the arms after reload and deletes the test, so it
  adds no code.
- **Spill slots via the gcse hash table.** The arms also add exactly seven RTL
  instructions, bringing the function to 1351 instructions before gcse1. That
  gives the 337-bucket expression hash table whose PRE pseudo order produces
  retail's `sp#8`..`sp#28` slots.
- **Compare operand order.** `side` is a zero-initialised GNU
  `__complex__ float`. Only its real part is written and read. It stays in a
  register, and it adds no loop-carried PHI, so dom1's free-list reuse is
  unchanged. Complex lowering gives the real part a late SSA version, which
  keeps retail's `closestNormal.y == side` operand order.
- **Perpendicular.** A no-code `typedef vector3d<float> Vector;` before the
  perpendicular computation keeps its gimplification order.
