# LODSceneNode::computeLODLevel exact match

`LODSceneNode::computeLODLevel()` matches all 306 retail bytes at Thumb address
`0x002d2d61`. Its section, padded to 308 bytes by alignment, ends at the next
retail function.

```text
OK  _ZN12LODSceneNode15computeLODLevelEv  0x002d2d61  306 bytes
OK SECTION .lod_compute_level  0x002d2d60  308 bytes
```

## Source form

The function measures the squared distance from the active camera to the first
LOD node.

- **Beyond the maximum distance:** it hides the current level and resets it
  to -1.
- **Otherwise:** it scans the levels from the last one downwards. At the first
  level whose threshold is exceeded it hides the old level, records the new one
  and shows it.

Earlier forms differed in three operand-order bytes, in the compare and the
address addition of the copied loop header. The cause is in the SSA names:

- Copying the loop header gives fresh SSA names once the free list is
  exhausted.
- DOM then puts the lower version first, which is the wrong order.

Two inline accessors in `LODSceneNode.h`, `getLODNode(int)` and
`setLODVisible(int, bool)`, are fully inlined. Their parameter and return copies
are released early and leave recycled names for the copied header, so the copied
loads receive versions below `distance` and the base pointer comes first, as in
retail.

The accessors do not change behaviour, and no symbol is emitted for them. They
are reconstructed: the binary cannot show whether the original had them.

No branch hint, inline assembly, register constraint or output edit is used.

## Verification

`python -B tools/build.py --all` exited 0 with 5,555 function, 5,638 section
and 181 region comparisons and no mismatch or skip. This includes every unit
that includes `LODSceneNode.h`. Unit tests, repository checks and progress
checks pass.
