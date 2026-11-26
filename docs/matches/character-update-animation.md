# Character::updateAnimation exact match

`Character::updateAnimation(float)` matches all 892 retail bytes at Thumb
address `0x002f3489`, including relocations.

```text
OK  _ZN9Character15updateAnimationEf  0x002f3489  892 bytes
```

## Source form

`updateAnimation` advances the character's animator and handles the end of
an animation. For root-motion animations it moves the character and sets
the collision body's velocity, waking the body when it moves. It returns
whether the animation finished.

Details that the retail bytes require:

- **Collision body after a wake.** On the waking path, the collision body
  pointer is re-read from the character after the wake call and then
  stored through. Retail reloads it on that path and reuses the first load
  on the other path, which is partial-redundancy removal of the join load.
  GCC 4.2.1 does not derive that from a single post-join store, so the
  source writes the reload out. Waking the body does not change the
  pointer, so the re-read changes no behaviour.
- **Definition without a header change.** The function is defined through
  its mangled name with file-local view structs for the private animation,
  scene-node and body fields. A declaration change in `Character.h` alters
  `ServiceCarRental::Notify`. PlayerTest's `updateAnim` already calls it
  through an `extern "C"` declaration.

No branch hint, inline assembly, register constraint or output edit is used,
and no header change. The other Character.cpp functions keep their bytes.

## Verification

`python -B tools/build.py` passes for ai-startup-character,
ai-startup-playertest and ai-startup-npc. A fresh complete build, `python -B tools/build.py --all`, exited 0 with
5,605 function, 5,709 section and 180 region comparisons and no mismatch or
skip; the previous baseline was 5,602, 5,706 and 180.
