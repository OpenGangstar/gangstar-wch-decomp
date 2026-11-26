# SoundManager::update and SoundManager::_getReadySound exact matches

`SoundManager::update(double)` matches all 428 retail bytes at Thumb address
`0x00353175`, and `SoundManager::_getReadySound(int)` matches all 224 retail
bytes at `0x00353095`, both including relocations.

```text
OK  _ZN12SoundManager14_getReadySoundEi  0x00353095  224 bytes
OK  _ZN12SoundManager6updateEd  0x00353175  428 bytes
```

## Source form

`update` advances the playing sounds, stops and releases finished ones and
updates the radio and low-frame-rate music. `_getReadySound` finds a free
or finished channel for a sound in up to three attempts, stops and releases
what was playing there unless the sound type keeps it, and attaches a new
static or streaming sound.

Details that the retail bytes require:

- **Slot clear in update.** When `update` deletes a finished sound, the slot
  is cleared through a file-local view of the slot table that uses array
  indexing. GCC 4.2.1 orders the operands of tree pointer arithmetic by SSA
  version, which puts the table first. An array reference is expanded with
  the scaled offset first instead, which gives retail's `ldr r3,[r4,r2]`.
- **Loop slot read in _getReadySound.** The retry loop reads the slot
  through a row holder view, keeping the row load as pointer arithmetic and
  the slot load as an array reference. Because that reference differs from
  the plain read after the loop, tree value numbering and partial-redundancy
  removal keep retail's reload of the row and slot. The finished flag is
  read through a view because it is private to `CSound`.
- **Definition without a header change.** `_getReadySound` is not declared
  in `SoundManager.h`. Adding the declaration changes
  `Menus::ServiceMissions::GotFocus`, so the method is defined through its
  mangled name.

No branch hint, inline assembly, register constraint or output edit is used,
and no header change. The other SoundManager.cpp functions keep their bytes.

## Verification

`python -B tools/build.py` passes for sdk-startup-soundmanager and
ai-startup-menustate. A fresh complete build,
`python -B tools/build.py --all`, exited 0 with 5,615 function, 5,709 section
and 180 region comparisons and no mismatch or skip; the previous baseline
was 5,613, 5,709 and 180.
