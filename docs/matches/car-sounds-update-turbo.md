# CarSounds::UpdateTurboSounds exact match

`CarSounds::UpdateTurboSounds()` matches all 508 retail bytes at Thumb address
`0x0034fbf9`, including relocations.

```text
OK  _ZN9CarSounds17UpdateTurboSoundsEv  0x0034fbf9  508 bytes
```

## Source form

1. The primary turbo loop gets a flat-ended interpolated volume and a pitch
   that blends the RPM ratio towards 1.
2. The secondary loop gets its own volume at unit pitch.
3. On a clutch trigger, or when the load drops to zero, the function looks up
   the auxiliary sample whose RPM threshold brackets the secondary turbo RPM. It
   starts that sample if it is not already playing.

The previous reconstruction differed in 53 bytes, all in the threshold search.
It wrote the search as `while (turboArray284[index] < rpm && ...) ++index;`.
Full redundancy elimination then merged the loop's `index * 4` address product
with the post-loop `auxiliaryTurboIds[index - 1]` access. That kept the product
live across the loop and changed the early-exit constant.

Loading the threshold into a local before the loop, and again at the end of each
iteration, takes the loop's product from the incremented index instead. The
two products then stay distinct, which reproduces retail's index PHI and
`lsls` placement. Behaviour is unchanged.

No branch hint, inline assembly, register constraint or output edit is used,
and no header change.

## Verification

The unit builds pass every function and section check. A fresh complete build,
`python -B tools/build.py --all`, exited 0 with 5,576 function, 5,660 section
and 181 region comparisons and no mismatch or skip; the previous baseline was
5,574, 5,657 and 181.
