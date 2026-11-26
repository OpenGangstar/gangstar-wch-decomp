# CameraManager::getClickedTarget exact match

`CameraManager::getClickedTarget(irr::core::line3d<float>, bool) const`
matches all 672 retail bytes at Thumb address `0x00332cf5`, including
relocations.

```text
OK  _ZNK13CameraManager16getClickedTargetEN3irr4core6line3dIfEEb  0x00332cf5  672 bytes
```

## Source form

The function walks the enabled, visible game objects and returns the first
whose padded bounding box (transformed for vehicles) intersects the given
ray.

Details that the retail bytes require:

- **Box work in an inlined helper.** The bounding-box arithmetic is a
  file-local inline helper. Its variables are placed ahead of the caller's
  in the variable list, which puts the inlined vector product in retail's
  spill slot.
- **Declaration order.** The result box is declared before the minimum
  edge, which gives retail's order of the scalarised groups and so its
  spill slots; with this shape the SSA versions also give retail's operand
  order in all nine float additions.
- **Arm order.** The plain bounding-box branch comes first, as retail
  places it.
- **Views.** LevelObject's flags, list link and scene node are read through
  a file-local view, because CameraManager is not a friend of LevelObject;
  `aabbox3d::intersectsWithLine` is called through its mangled name.

No branch hint, inline assembly, register constraint, output edit or header
change is used. The other CameraManager.cpp functions keep their bytes.

## Verification

`python -B tools/build.py ai-startup-cameramanager` passes. A fresh complete
build, `python -B tools/build.py --all`, exited 0 with 5,638 function, 5,713
section and 180 region comparisons and no mismatch or skip; the previous
baseline was 5,637, 5,713 and 180.
