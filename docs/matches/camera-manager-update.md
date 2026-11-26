# CameraManager::update exact match

`CameraManager::update(float)` matches all 1,148 retail bytes at Thumb
address `0x00332771`, including relocations.

```text
OK  _ZN13CameraManager6updateEf  0x00332771  1148 bytes
```

## Source form

`update` advances the active camera (follow, vehicle or scripted), applies
the explosion camera shake, positions the scene camera and its target, and
updates the sound listener.

Details that the retail bytes require:

- **Up axis as a local.** The up axis for the follow-camera offset is a
  local declared before the follow test, so the block starts with the
  `getFacing` call and the call heuristic applies. That gives retail's
  block order and keeps a branch in range.
- **Locals for the camera compare.** The current camera and the follow
  camera are compared through two locals. With a member on one side, the
  front end swapped the operands.
- **Shake components.** The three shake components are separate floats in
  a nested block after the camera block. The X component is read through a
  pointer and the Y component through a pointer to a pointer, so their SSA
  names are created late and in retail's order. That gives retail's
  operand order for the X addition, its spill-slot order and its order of
  the zero stores when there is no shake.

No branch hint, inline assembly, register constraint, output edit or header
change is used. The other CameraManager.cpp functions keep their bytes.

## Verification

`python -B tools/build.py ai-startup-cameramanager` passes. A fresh complete
build, `python -B tools/build.py --all`, exited 0 with 5,634 function, 5,713
section and 180 region comparisons and no mismatch or skip; the previous
baseline was 5,633, 5,713 and 180.
