# Vehicle::dropSceneNode exact match

`Vehicle::dropSceneNode()` matches all 328 retail bytes at Thumb address
`0x00309f0d`, and its strict section ends at the retail extent.

```text
OK  _ZN7Vehicle13dropSceneNodeEv  0x00309f0d  328 bytes
OK SECTION .vehicle_drop_scene_node  0x00309f0c  328 bytes
```

## Source form

The function hides the enabled node and drops the base scene node. It clears the
door, mesh, texture, wheel and repair pointers. It returns the pooled repair,
light and auxiliary nodes to `SceneNodeManager`, then clears those pointers.

The earlier best form differed in four scheduling bytes. GCC must see the node
at offset 844 as a field separate from the three-entry light array at 832..840.

A `Vehicle.h` member split did that, but it perturbed the matched
`PhysicAttributes::FindLowerCostNode` through declaration UIDs. The function is
now an `extern "C"` definition of the retail mangled name. It reads every field
through one file-local `VehicleDropSceneView` that has the split layout and the
`Vehicle.h` field types, which gives the same alias split without touching a
header.

No branch hint, inline assembly, register constraint or output edit is used.

## Verification

`python -B tools/build.py --all` exited 0 with 5,563 function, 5,646 section
and 181 region comparisons and no mismatch or skip. `GetMetatypeFromName` and
`FindLowerCostNode` remain exact. Unit tests, repository checks and progress
checks pass.
