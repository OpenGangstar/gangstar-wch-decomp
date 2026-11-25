# GS3DStuff::SetAlpha exact match

```text
OK  _ZN9GS3DStuff8SetAlphaEPN3irr5scene10ISceneNodeEhNS_10eColorTypeE  0x002df34d  168 bytes
OK SECTION .gs_set_alpha  0x002df34c  168 bytes
```

For a mesh scene node (type `'daem'` or `'daes'`) and colour type 0, sets the
alpha of material 0's colour at offset 84, marks dirty bit 8, and recomputes
the material's blend flag (bit 4 of `flags40`, with dirty bit 1 when it
changes). Other node types recurse into their children.

The retail material update keeps a dirty cache that stock Irrlicht lacks. It is
written as two small always-inline helpers in an anonymous namespace,
`sameColor` (compares two `SColor`s as one 32-bit word) and `updateColorBlend`.
`updateColorBlend` tests the "blend not needed" condition first (set-bit arm
first), which gives retail's `lsls #29` test in the clear arm. The equivalent
inline-written condition shared the constant 4 with the later `bics`
(33 differing bytes in the earlier archive).

The early-out compare is written `(unsigned int)alpha == colorAlpha(...)`
through a one-line inline accessor. A plain `alpha == material.color84.a` is
reordered by the front-end fold, which puts the parameter second; retail
compares with the parameter first.

No header change, hint, inline assembly or register constraint is used.
`GS3DStuff::SetColor`, which shares the helpers, remains unmatched (8 bytes;
see `DECOMP_TASKS.md`).

Full gate: `python -B tools/build.py --all` exited 0 with 5,510 function,
5,587 section and 181 region comparisons and no mismatch or skip.
