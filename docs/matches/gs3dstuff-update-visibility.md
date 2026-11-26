# GS3DStuff::updateVisibility exact match

`GS3DStuff::updateVisibility(unsigned int)` matches all 1944 retail bytes at
Thumb address `0x002dd7e1`, including relocations. Every other section in
`GS3DStuff.cpp` is unchanged, including `checkVehicleProximity`.

## Source form

The function rebuilds the visible scene-node lists. It destroys physics bodies
for nodes that left view, creates them for nodes that entered, and refreshes the
renderable list for objects, items, vehicles, lights and effects. Details that
the retail bytes require, each commented in the source:

- **Stack slots via the gcse hash table.** gcse1 PRE creates the stack-address
  and GOT pseudos in expression hash-bucket order, and their stack slots follow
  register number. The table size depends on the function's instruction count
  before gcse1. A default `aabbox3d<float> box;` instead of the init constructor
  plus a `MaxEdge` store brings the count to 786 instructions. That gives a
  197-bucket table, the size that produces retail's `[sp,#8]`/`[sp,#16]` slots.
- **Two-counter latches.** The DestroyBody and CreateBody loops are written as
  `for (j = 0, x = 0; x < N; j = x) { ...; x = j + 1; }`. This reproduces retail's
  `adds rA,rB,#1; adds rB,rA,#0` latch and its index-first loads.
- **Pointer round-trip counters.** Four loops advance their counter through a
  `char*` round trip, the form `GS3DStuff.cpp` already uses elsewhere. This
  controls SSA-name recycling for the loops that follow.
- **Guarded object body.** The object loop wraps its body in
  `if (sceneNode && sceneNode->isVisible())` instead of an early `continue`, which
  gives retail's GOT and PIC copy registers.
- **Unsigned impact counter.** The 8-entry impacts loop uses an unsigned counter.
- **Declaration-UID compensation.** Named locals in the inline
  `visibilityRenderables` helper shift global declaration UIDs back, which keeps
  `checkVehicleProximity`'s stack slots. That makes this compensation sensitive
  to later edits above it in the file, so rerun the real-path check after any
  change there.
- **Node-type constants.** Four unreferenced node-type constants go to the
  existing verification-only area of the linker script.
