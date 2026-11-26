# GS3DStuff::checkForDespawn exact match

`GS3DStuff::checkForDespawn(LevelObject*)` matches all 636 retail bytes at
Thumb address `0x002dd0c1`, including relocations.

```text
OK  _ZN9GS3DStuff15checkForDespawnEP11LevelObject  0x002dd0c1  636 bytes
```

## Source form

For an object with any of the despawnable flags set, the function picks the
civilian or vehicle spawn centre and despawns the object when it is flagged
for removal, outside the spawn radius or of a despawnable type. It returns
the object, or what the object manager returned for it.

Details that the retail bytes require:

- **One despawn site.** The three despawn conditions are joined in one test
  that assigns `object = gom->despawn(object)`, and the function has a
  single `return object` at the end. The flag test wraps the body instead
  of returning early. Each form alone changes nothing; together they lower
  the predicted frequency of the block after the flag test. Global register
  allocation then orders the PIC register before the constant 36, as
  retail does, and the remaining register and spill-slot choices follow,
  including retail's 72-byte frame.
- **Placement.** The function is defined at the end of `GS3DStuff.cpp`; the
  rest of the file keeps its bytes. It uses the file-local `despawnWord`
  helper.

No branch hint, inline assembly, register constraint, output edit or header
change is used.

## Verification

`python -B tools/build.py` passes for gs3d-stuff and the seven units that
link its object. A fresh complete build,
`python -B tools/build.py --all`, exited 0 with 5,612 function, 5,709 section
and 180 region comparisons and no mismatch or skip; the previous baseline
was 5,611, 5,709 and 180.
