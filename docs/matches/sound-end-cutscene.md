# SoundManager::endCutscene exact match

`SoundManager::endCutscene()` matches all 236 retail bytes at Thumb address
`0x00352a55`, and its strict section ends at the retail extent.

```text
OK  _ZN12SoundManager11endCutsceneEv  0x00352a55  236 bytes
OK SECTION .sound_end_cutscene  0x00352a54  236 bytes
```

## Source form

Earlier forms reached 236 bytes, but six bytes differed because the operands of
two slot loads were commuted. GCC 4.2.1 orders commutative operands by SSA
version, so the textual order of the source decides operand order. Two choices
reproduce retail:

- Write the radio-track branch first: `if (id == radioTrack) {...} else {loop}`.
- Access `soundSlots[id][channel]` directly in each test and call, as in
  `getNumberOfPlayingSounds`.

All guards come from the retail instructions:
`flags & 0x10`, `--s_soundsPlaying == 0`, `flags &= ~0x50`, the merged
`type & 0x400000 && !(flags & 0x100)` music test, the radio `Stop(0)` /
`SetVolume` paths, and the restricted-sfx volume loop.

No header change, branch hint, inline assembly, register constraint or output
edit is used.

## Verification

`python -B tools/build.py --all` exited 0 with 5,541 function, 5,623 section
and 181 region comparisons and no mismatch or skip. Unit tests, repository
checks and progress checks pass.
