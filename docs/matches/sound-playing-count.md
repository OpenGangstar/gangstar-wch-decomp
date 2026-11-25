# SoundManager::getNumberOfPlayingSounds exact match

`SoundManager::getNumberOfPlayingSounds()` matches all 80 retail bytes at Thumb
address `0x00352cad`, including its call relocation, and its strict 80-byte
section ends at the following `isLowFpsMusicPlaying` boundary.

```text
OK  _ZN12SoundManager24getNumberOfPlayingSoundsEv  0x00352cad  80 bytes
OK SECTION .sound_playing_count  0x00352cac  80 bytes
```

## Source form

The earlier unapplied reconstruction (`nonmatching/audio/SoundManager-playing-count.md`)
cached the slot pointer in a local and differed only at offsets `0x20`/`0x21`:
it emitted `ldr r3, [r6, r3]` where retail has `ldr r3, [r3, r6]`. GCC 4.2.1
canonicalizes commutative operands by SSA version, so the operand order follows
the shape of the source expression rather than any semantic difference.

Writing the slot access directly in both the null test and the call, in the same
style as the matched `getNumberOfAllocatedSounds` relative, reproduces retail:

```cpp
if (soundSlots[id][channel] && soundSlots[id][channel]->GetStatus() != 4)
    count++;
```

No branch hint, inline assembly, register constraint or output edit is used.
Every memory access, the `flags & 2` guard, both loop bounds and the
`GetStatus() != 4` test are unchanged from the retail instructions. The method
declaration is placed beside `getNumberOfAllocatedSounds` in `SoundManager.h`;
it adds no storage or virtual slot.

## Verification

`python -B tools/build.py sdk-startup-soundmanager` passed every function and
section check of the unit, including the two lines above. A fresh complete
build, `python -B tools/build.py --all`, exited 0 with 5,467 function, 5,490
section and 181 region comparisons and no mismatch or skip; the previous
baseline was 5,466, 5,489 and 181. The unrelated header change therefore did
not disturb `MenuManager::updateWidgetVisibility()` or any other existing match.
