# PhysicAttributes::GetRandomDestination exact match

`PhysicAttributes::GetRandomDestination(unsigned short, unsigned short&,
vector3d<float> const&, float, float)` matches all 724 retail bytes at Thumb
address `0x0031aa5d`, including relocations.

```text
OK  _ZN16PhysicAttributes20GetRandomDestinationEtRtRKN3irr4core8vector3dIfEEff  0x0031aa5d  724 bytes
```

## Source form

`GetRandomDestination` picks a random walkable surface whose distance from
the origin lies within the given band. If none qualifies, it falls back to
the surface whose distance is closest to the middle of the band. It returns
the surface's centre.

Details that the retail bytes require:

- **Distance from the middle.** Both loops compute `fabsf(distance - middle)`
  directly in the comparison and again in the update. They do not keep it in
  a separate local. The tree-level redundancy pass merges the two calls.
- **Spill slots.** Without the extra local, the SSA numbering changes, and
  so do the out-of-SSA partition order and the split temporaries. That
  places the minimum, maximum and best-distance values in retail's spill
  slots.

No branch hint, inline assembly, register constraint or output edit is used,
and no header change. `lrand48`, `__aeabi_idiv` and `__aeabi_idivmod` are
bound at their PLT addresses.

## Verification

`python -B tools/build.py ai-startup-physicattributes` passes. A fresh complete build, `python -B tools/build.py --all`, exited 0 with
5,605 function, 5,709 section and 180 region comparisons and no mismatch or
skip; the previous baseline was 5,602, 5,706 and 180.
