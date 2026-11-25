# RenderFX::SearchIndex::Clear exact match

`RenderFX::SearchIndex::Clear()` matches all 180 retail bytes at Thumb address
`0x003ee721`, including relocations.

```text
OK  _ZN8RenderFX11SearchIndex5ClearEv  0x003ee721  180 bytes
```

## Source form

`Clear` walks the entries hash, deletes each entry list and then calls
`hash::clear`.

Details that the retail bytes require:

- **Iterator compares.** The hash iterator's `operator++` and `is_end` read
  the table's size mask and the current index into `const int` locals. They
  then compare `mask >= index` and `mask < index`. With direct member
  compares, dom2's `canonicalize_comparison` reverses the operands, because
  the recycled index PHI gets a lower SSA version.
- **Null hash.** `is_end` returns early when the hash or its table is null.
- **Entry list.** A file-local explicit specialisation of
  `gameswf::array<RenderFX::SearchIndex::Entry>` has an inline destructor.
  That destructor calls the out-of-line `release_buffer()` at `0x003ec5ad`
  through the GOT, as retail does.
- **Views.** The iterator and the hash table are file-local views in
  `menufx.cpp`.

No branch hint, inline assembly, register constraint or output edit is used,
and no header change.

## Verification

`python -B tools/build.py` passes for renderfx-animation and for the two
dependent units, ai-startup-menuwidget and ai-startup-menustate. Each places
the new section at the retail address. A fresh complete build, `python -B tools/build.py --all`, exited 0 with 5,594 function, 5,681 section and 181 region comparisons and no mismatch or skip; the previous baseline was 5,593, 5,680 and 181.
