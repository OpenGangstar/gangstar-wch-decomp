# RenderFX::PreloadGlyphs(unsigned short*, ...) exact match

`RenderFX::PreloadGlyphs(unsigned short*, int, char const*, int, bool, bool,
gameswf::filter*)` matches all 492 retail bytes at Thumb address
`0x003ed9ed`, including relocations.

```text
OK  _ZN8RenderFX13PreloadGlyphsEPtiPKcibbPN7gameswf6filterE  0x003ed9ed  492 bytes
```

## Source form

The function creates a font for the given name, then for each glyph code
fetches the glyph and asks the matching (bitmap or filtered) glyph texture
cache for its region, so the glyphs are rendered ahead of use.

Details that the retail bytes require:

- **Instruction-count padding.** Before the glyph code is stored, the same
  field is first written through a `short&` with an unsigned 24-term
  product of the code; the real `unsigned short` store then overwrites it.
  Tree dead-store elimination does not pair the two differently-typed
  stores, so the product reaches RTL, where flow deletes it together with
  the dead store. No code is emitted, but the larger instruction count at
  gcse time gives a 55-bucket PRE table, which orders the two spilled GOT
  values (stack guard and glyph vtable) into retail's stack slots. A source
  comment explains the form.
- **Local views, no header change.** The glyph and font layouts, the
  `ref_counted` base (vtable, count, weak proxy) and a small reference
  holder are file-local to menufx.cpp. The `ref_counted` constructor, the
  glyph destructor and a weak `tu_string::operator=` are reached through
  `extern "C"` declarations of their mangled names. The glyph destructor is
  called explicitly on the `continue` path and at the end of each
  iteration, as retail does.

Behaviour is unchanged. No inline assembly, register constraint, flag
change, output edit or header change is used. The other two PreloadGlyphs
overloads keep their bytes; `ai-startup-menustate` and
`ai-startup-menuwidget` no longer list this function as external.

## Verification

`python -B tools/build.py renderfx-animation` passes. A fresh complete
build, `python -B tools/build.py --all`, exited 0 with 5,651 function,
5,713 section and 180 region comparisons and no mismatch or skip; the
previous baseline was 5,650, 5,713 and 180.
