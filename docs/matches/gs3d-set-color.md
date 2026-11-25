# GS3DStuff::SetColor exact match

```text
OK  _ZN9GS3DStuff8SetColorEPN3irr5scene10ISceneNodeENS0_5video6SColorENS_10eColorTypeE  0x002ded05  440 bytes
OK SECTION .gs_set_color  0x002ded04  440 bytes
```

For a mesh scene node, writes `color` into one of material 0's four colours
(offsets 84, 48, 56 or 52, chosen by the colour type), marking the matching
dirty bit and, for the first two, recomputing the blend flag; other nodes
recurse into their children. It reuses the `sameColor`/`updateColorBlend`
helpers introduced for `GS3DStuff::SetAlpha` (`docs/matches/gs3d-set-alpha.md`)
plus one small always-inline setter per colour slot.

The last 8 differing bytes were the order of the entry byte loads of the
`color` parameter and of the copy-out before the recursive call. GCC's scalar
replacement creates a struct's scalar parts in the order of their first
individual reference, and the entry loads come out in reverse; whole-struct
copies only fill in the remaining parts in field order. Reading the channels
into locals at entry in the order `a, b, g, r` reproduces retail's loads, and
building each case's argument with the four-argument `SColor` constructor
keeps retail's per-case stack temporaries and store sequence.

No header change, hint, inline assembly or register constraint is used. The
units that compile `GS3DStuff` as a dependency no longer bind `SetColor` as an
external Thumb function.

Full gate: `python -B tools/build.py --all` exited 0 with 5,511 function,
5,588 section and 181 region comparisons and no mismatch or skip.
