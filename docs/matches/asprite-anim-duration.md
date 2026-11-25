# ASprite::GetAnimDuration exact match

`ASprite::GetAnimDuration(int)` matches all 82 retail bytes at Thumb address
`0x00349d81`. Its section, padded to 84 bytes by alignment, ends at the next
retail function.

```text
OK  _ZN7ASprite15GetAnimDurationEi  0x00349d81  82 bytes
OK SECTION .asprite_anim_duration  0x00349d80  84 bytes
```

## Source form

The function sums the 16-bit duration field (+2) of each 9-byte frame record
belonging to an animation. Earlier forms were 80 bytes. The source details that
reach 82:

- **The loop.** It is an indexed `for` over `entry->count` that reads
  `entry->firstFrame + i` inside the body. This keeps retail's separate `ldrh`
  and sign extension of `firstFrame`, instead of a fused `ldrsh`, and puts the
  accumulator in r4.
- **The frame pointer.** A typed blob pointer is declared inside the loop body,
  and the frame base is built as `frames = blob; frames += blob->animationFrames;`.
  This yields retail's `data + offset` base and its
  `((first + count) * 9 + 2) + base` end-pointer association together. Forming
  the base in a single expression reverses one of the two.
- **The `Application::GetInstance()` call.** Retail makes this call and discards
  the result, and the source does the same.

No header change, branch hint, inline assembly, register constraint or output
edit is used.

## Verification

`python -B tools/build.py --all` exited 0 with 5,544 function, 5,626 section
and 181 region comparisons and no mismatch or skip. Unit tests, repository
checks and progress checks pass.
