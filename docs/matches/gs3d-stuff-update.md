# GS3DStuff::update exact match

`GS3DStuff::update(StateMachine*)` matches all 1232 retail bytes at Thumb
address `0x002e078d`, including relocations.

```text
OK  _ZN9GS3DStuff6updateEP12StateMachine  0x002e078d  1232 bytes
```

## Source form

The function steps the physics world, walks the game-object list (despawn
checks, then sorting vehicles and pickables into two function-local static
vectors for the proximity checks) and updates the player, camera, scripts
and scene nodes.

Details that the retail bytes require:

- **Function-local statics.** `vehicles` and `pickables` are real
  function-local `static std::vector`s with guard variables, placed at
  retail's `.bss` addresses (`0x004b6a6c`/`0x004b6a70` guards,
  `0x004b6a74`/`0x004b6a80` vectors). Their compiler-generated destructors
  are retail's `__tcf_7` and `__tcf_8`; GCC names them `__tcf_4` and
  `__tcf_5` in this unit, so the manifests map them with `compiled_name`.
  The hand-written `extern "C"` destructor stubs for those two symbols are
  removed.
- **Inline limit.** The unit is compiled with `-finline-limit=70`, the value
  retail used for this file (previously `-finline-limit=40`). With 70 the
  inlined vector growth and accessors match; every other GS3DStuff.cpp
  comparison still passes. This flag change was approved by the maintainer.
- **Views.** Application, PlayerTest and LevelObject fields are read through
  file-local partial views that assert no complete layout;
  `StateMachine::getTimeStamp` is declared through its mangled name.

No branch hint, inline assembly, register constraint, output edit or header
change is used.

## Verification

`python -B tools/build.py gs3d-stuff` passes. A fresh complete build,
`python -B tools/build.py --all`, exited 0 with 5,640 function, 5,713
section and 180 region comparisons and no mismatch or skip; the previous
baseline was 5,638, 5,713 and 180.
