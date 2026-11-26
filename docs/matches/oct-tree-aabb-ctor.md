# OctTreeAABB::OctTreeAABB exact match

`OctTreeAABB::OctTreeAABB(irr::scene::ISceneNode*, unsigned int)` matches all
384 retail bytes at Thumb address `0x002df995`, including relocations.

```text
OK  _ZN11OctTreeAABBC1EPN3irr5scene10ISceneNodeEj  0x002df995  384 bytes
```

## Source form

The constructor counts the renderable nodes, builds the root and
spawn-point nodes, computes the bounding box of all roots and builds the
octree from it. If there are no roots, the empty root array is freed.

Details that the retail bytes require:

- **Node constructor in the unit.** `OctTreeAABBNode`'s constructor is
  defined inline in GS3DStuff.cpp with `__attribute__((used))`, so it is
  emitted as a link-once section. Retail calls it through the GOT, and the
  plain `new OctTreeAABBNode(nodeId, 0, roots, maxDepth, box)` keeps the
  front-end copy of the box at retail's stack slots. That constructor does
  not yet match (828 of its 832 bytes); it is placed uncredited in its
  retail span, with a linker assertion that it fits.
- **Count read.** The root count is read through a byte offset of the
  array pointer, which keeps the later null test of the delete path, as
  retail has. The box is declared before that read.
- **Delete-path hint.** `__builtin_expect(storage->free_when_destroyed, 1)`
  lays the data delete out as the fall-through path, with a source
  comment; the same documented hint is used in PlayerTest.cpp.
- **Field names.** The class's eight unknown bytes are named `nodeId` and
  `nodeCount` inside GS3DStuff.cpp's own class definition; no shared header
  changes.

The seven units that link the GS3DStuff object no longer list the
constructor as an external symbol. Behaviour is unchanged. No inline
assembly, register constraint, flag change or output edit is used.

## Verification

`python -B tools/build.py gs3d-stuff` passes. A fresh complete build,
`python -B tools/build.py --all`, exited 0 with 5,648 function, 5,713
section and 180 region comparisons and no mismatch or skip; the previous
baseline was 5,647, 5,713 and 180.
