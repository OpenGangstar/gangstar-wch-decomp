# GS3DStuff::CreateStaticBodies exact match

`GS3DStuff::CreateStaticBodies(ISceneNode*, ISceneNode*, ISceneNode*, ISceneNode*)`
matches all 1580 retail bytes at Thumb address `0x002ddf79`, including
relocations. Its static `ID` counter is placed at `0x004b6a8c`. Every other
section of `GS3DStuff.cpp` is unchanged, including `updateVisibility`, the
`OctTreeAABBNode` constructor and `AddXRef`.

## Source form

The function scans the static scene nodes and builds Box2D static body
definitions for jump and polygon shapes. Each source detail is
behaviour-preserving and commented:

- **Plane-failure block.** Two never-taken jumps into it, each guarded by a
  no-code `__builtin_prefetch`, place it as in retail.
- **Scan loop.** A hidden constant 4 in the latch, an expect-false `continue`
  and an `else` prefetch make the loop rotate into retail's order.
- **Loop 2.** A known-false expect `break` at its start cools it, so `node`,
  `transform` and `mesh` land in retail's registers.
- **Loops 2 and 3.** The exit test uses `end + (k - 4)`, where `k` comes from a
  do-while that only VRP2 resolves. DOM3 then refolds the compare operands in
  retail's order.
- **Loop 1.** The exit is a separate-statement XOR test, with a known-false
  aggregate `break` and a guard-`else` prefetch to keep its frequencies.
- **Non-jump userData.** It is built through a file-local constructor overload
  that stores the same fields in a different order, which gives reload retail's
  registers.
- **DECL_UID pads.** A 12-enumerator pad follows the function, and the OctTree
  pad is now 5 enumerators. Together they keep the later functions unchanged.
