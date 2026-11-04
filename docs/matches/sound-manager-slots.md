# SoundManager slot queries

The sound table holds four channel slots per sound ID. The allocation
query counts populated slots. Both playback queries convert resource IDs
through the existing ID helper and test the status of populated slots.

```text
OK  _ZN12SoundManager26getNumberOfAllocatedSoundsEv  0x00352845  48 bytes
OK  _ZN12SoundManager14isSoundPlayingEi  0x00352c3d  52 bytes
OK  _ZN12SoundManager14isSoundPlayingEii  0x00352c71  58 bytes
```

The separate 80-byte getNumberOfPlayingSounds candidate differs at offset
0x20. The emitted Thumb load uses the same registers in reverse operand
order. The function remains pending.
