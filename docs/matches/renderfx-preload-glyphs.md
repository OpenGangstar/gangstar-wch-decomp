# RenderFX::PreloadGlyphs exact match

`RenderFX::PreloadGlyphs()` matches all 360 retail bytes at Thumb address
`0x003edc7d`, including relocations.

```text
OK  _ZN8RenderFX13PreloadGlyphsEv  0x003edc7d  360 bytes
```

## Source form

The function walks every text character of the movie and preloads its
glyphs, once for each of the character's filters and once without a
filter, at the character's font, size and style.

Details that the retail bytes require:

- **Accessor helpers for the loop reads.** The root character, each filter
  and the character used for the text read are fetched through small
  file-local inline helpers. Their copies are removed early, and the loop
  optimiser's new names for the scaled index and the filter offset then
  reuse those freed SSA versions. Since a later fold orders address operands
  by SSA version, this gives retail's operand order in both loop addresses;
  the first character read (the argument to `is`) is written directly so
  that it keeps the other order, as retail has it.
- **Definition without a header change.** The method is defined through its
  mangled name with file-local views of the movie, root, text character,
  filter and font fields.

No branch hint, inline assembly, register constraint, output edit or header
change is used. The other menufx.cpp functions keep their bytes, including
`RenderFX::Find`, whose bytes are sensitive to unrelated source in this file.

## Verification

`python -B tools/build.py` passes for renderfx-animation,
ai-startup-menustate and ai-startup-menuwidget. A fresh complete build,
`python -B tools/build.py --all`, exited 0 with 5,637 function, 5,713
section and 180 region comparisons and no mismatch or skip; the previous
baseline was 5,636, 5,713 and 180.
