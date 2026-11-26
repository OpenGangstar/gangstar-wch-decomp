# OctTreeAABB::OctTreeAABBNode constructor exact match

The C1 constructor `OctTreeAABB::OctTreeAABBNode(int&, int, array<RootNode*>*,
unsigned int, aabbox3d<float>)` matches all 832 retail bytes at Thumb address
`0x002df655`, including relocations. Before this match it was placed in the
`.gs_oct_tree_node_ctor_uncredited` section; it is now credited. The other
sections of `GS3DStuff.cpp` are unchanged.

## Source form

The constructor builds an octree node. When the node is over its limit and
not flat, it splits its root list into eight children by box intersection.
Details that the retail bytes require, each commented in the source:

- **Reload rotation via jump-only arms.** The `equals` result is held in
  `flat`. Inside the `||` it is tested by two identical arms, each just
  `if (flat) goto leafRoots;`, selected by a `__builtin_expect(..., 0)`
  condition. Crossjump merges the jump-only arms after reload and deletes the
  selecting test, so no code remains.
  - **First four compares:** `this`, `&count`, `limit` and `&incoming`. Each
    takes one reload, so the spill-register rotation ends on `r6`. The roots
    store and the loop preheader then reload into `r1`/`r2`/`r3` as in retail.
  - **Remaining compares:** they inherit those reloads and only add RTL
    instructions. That gives gcse1's expression hash table 77 buckets, whose
    PRE order puts the reallocate literal in the lower stack slot, as in
    retail.
- **Default bounds.** `bounds()` uses the default `aabbox3d` constructor
  (`-1..1`) instead of an init constructor plus a `MaxEdge` store.
- **Child box helper.** `octChildBox` takes the corner as arguments, so its
  loads land in the loop header and ivopts sees the corners use before the
  children store.
- **Dead corner loads.** Two dead corner loads and two named copies emit no
  code. DCE releases their SSA names, which SRA recycles, and that keeps
  retail's box-first (`fcmpge`) compares.
- **DECL_UID pad.** A 28-enumerator pad after the constructor keeps
  `updateVisibility`'s scheduling.
