# MenuManager::preloadGlyphs exact match

`MenuManager::preloadGlyphs(bool)` matches all 460 retail bytes at Thumb
`0x002e5e4d`, with its format, mode and error strings at their retail
addresses.

```text
OK  _ZN11MenuManager13preloadGlyphsEb  0x002e5e4d  460 bytes
OK SECTION .menu_preload_glyphs  0x002e5e4c  460 bytes
```

The previous reconstruction differed in eight bytes. Two source facts fix them:

- `s_GlypOptimizerData` is const: retail stores it in `.data.rel.ro`. Read-only
  loads remove a memory anti-dependence on an outgoing argument store, and
  sched2's dependent-count tie-break then issues the format address first.
- **Disclosed name choice.** Two spilled GOT offsets were in swapped stack
  slots. Reload numbers those slots by gcse's reaching-register order, which
  follows each expression's hash bucket, `(16 + h(name)) % 37` over the
  symbol name. Retail has no name for the `"rb"` string, so it is named
  `preloadBinaryMode`, whose bucket reproduces retail; `preloadMode` did not.
  The name was selected for this reason; any name in buckets 2-9 is equivalent.

Retail merges this `"rb"` with RenderFX's read mode at `0x004014f0`. The owning
image checks it there; the MenuState image, which links both objects, gives the
unchecked MenuManager duplicate a documented non-retail address.

## Verification

`python -B tools/build.py menu-manager-helpers` passed every function and
section. python -B tools/build.py --all exited 0 with 5,476 function, 5,509 section and 181 region comparisons and no mismatch or skip.
