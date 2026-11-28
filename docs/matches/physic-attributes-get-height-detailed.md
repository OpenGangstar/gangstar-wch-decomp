# PhysicAttributes::GetHeight (detailed overload) exact match

`PhysicAttributes::GetHeight(int, irr::core::vector3d<float> const&, bool, bool)`
matches all 5038 retail bytes at Thumb address `0x0031eb99`, including
relocations. The other sections of `PhysicAttributes.cpp` are unchanged,
including `ContactListener::Add`, `AddCollisionShapes`, `GetNextRandomPos` and
`GetRandomDestination`.

## Source form

The function finds the height-map triangle under a position by walking from the
current triangle across its three edges, or through the triangles that overlap
them. Several operand orders in the retail code follow GCC's SSA-name
numbering, which reuses released names from a last-in-first-out free list.
Every detail that steers that numbering is behaviour-preserving and commented in
the source:

- **Root partition.** A dead integer statement, `slot ^ (slot >> 1) ^ ...`, is
  removed before SRA. SRA reuses its names for its PHIs, so the loop-0 partition
  of `bc` keeps the root variable as in retail.
- **SRA copies.** Four dead vector copies after the edge-difference
  declarations use up SRA's spare low names, which gives the `ba` copies fresh
  names (the `pc.Y * ca.X` and related multiply operand orders).
- **Edge loops.** The edge-2 overlap loop carries two extra IVs and a counter
  `gh_k` that mirrors `k`. A no-code `__builtin_prefetch` of
  `OverlapPtr(array, gh_k)` after the loop adds one loop-closed PHI. ivopts then
  removes the extra IVs and frees their names before it rewrites edge 1, which
  gives the `k + 1` address adds of all three edges retail's operand order.
  `OverlapPtr` only does pointer arithmetic, and `gh_k` never exceeds the array
  size.
- **Neighbour block.** The neighbour block is placed after the overlap loop with
  gotos. Reload hands out spill slots in pseudo order, so this gives retail's
  per-edge slots.
- **Per-edge index copy.** Each edge's `slot == 0` block copies `index` into
  its own local, which gives each edge its own temporary register.
- **DECL_UID pad.** A one-enumerator pad before `ContactListener::Add` keeps the
  later functions' temporaries in retail order. It must be re-swept after any
  change to this body.
