# OctTreeAABBNode::getPolysIter exact match

`OctTreeAABB::OctTreeAABBNode::getPolysIter(...) const` matches all 620 retail
bytes at Thumb address `0x002dd33d`, including relocations.

## Source form

The query walks the octree without recursion, using a fixed stack of ten
frames, and collects collision bodies, spawn points and scene nodes whose
boxes touch the query box. Details that the retail bytes require, each
commented in the source:

- **Root reads.** Root array reads use a shift-indexed helper, and the spawn
  and scene-node reads in the null-collision branch use a byte-pointer form,
  which gives retail's address operand order.
- **Scan loop.** The scan re-reads the frame node it has just stored, so the
  parent becomes a separate copy and the child scan matches retail.
- **Box test helper.** The first box test goes through a small inline
  helper, which gives retail's spill slots for the box values.
- **Frames register.** One call site uses a hinted copy of the frame-advance
  helper: two in-bounds byte reads of the current frame feed an
  identical-arm increment. The test keeps two values live until register
  allocation, so the frames base cannot take r0 and gets retail's r6; the
  test is removed after cross-jumping.
- **Dead size check.** A `__builtin_object_size` test that folds away before
  partial redundancy elimination changes only SSA naming, which gives the
  spawn-path reload retail's operand order.

## Placement

The function is defined after the `SafeDelete<CollisionBodyDef*>`
specialisation. Other placements change `checkVehicleProximity`, because
the file's anonymous-namespace names hash the file contents.
