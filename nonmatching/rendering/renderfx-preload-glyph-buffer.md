# RenderFX::PreloadGlyphs(unsigned short*, ...) layout candidate

This uncounted candidate targets the 492-byte Thumb function at `0x003ed9ed`.
It emits 500 bytes and fails strict native linking. The target assembly remains
present. The [patch](renderfx-preload-glyph-buffer.patch) includes both the
declaration prerequisites and the single faithful source trial against
`5012b833`; apply it independently of other candidate patches.

```sh
git apply --check --ignore-space-change nonmatching/rendering/renderfx-preload-glyph-buffer.patch
git apply --ignore-space-change nonmatching/rendering/renderfx-preload-glyph-buffer.patch
python tools/build.py renderfx-animation
```

Exit 2 is expected. The original GNU linker reports:

```text
section .renderfx_preload_glyphs_text [003edbd8 -> 003edc7b] overlaps section .renderfx_preload_glyph_buffer [003ed9ec -> 003edbdf]
```

It also reports an unresolved real `__aeabi_fcmpgt` import. Repairing that import
cannot remove the proven eight-byte overlap, so the trial stopped. No linked
target percentage, existing-match closure pass for this trial, or Fully Linked
credit is claimed. Native addresses and section-overlap checks are preserved.

## Evidence supporting the declarations

The retail fork differs from the public-domain gameswf font/glyph layouts.
This candidate uses verified native extents rather than copying upstream
classes wholesale:

- `ref_counted` is a 12-byte polymorphic base. Constructor `0x003b4be9`
  initializes its vptr and words at offsets 4 and 8. Native `add_ref` increments
  offset 4; offset 8 is the weak proxy.
- `character_def` is 32 bytes, including that base. Its constructor at
  `0x003a88d5` and 52-byte vtable at `0x004ae5f8` establish the intermediate
  hierarchy. The existing bitmap child remains 36 bytes.
- The real font constructor at `0x003b1db5` invokes `character_def` and initializes
  the proven 132-byte allocation. Name, italic and bold use offsets 48, 72 and
  73. Unknown fields remain explicitly opaque within the verified extent.
- `array<glyph>::resize` at `0x003d8a39` independently proves a 60-byte glyph
  stride and inline constructor defaults, including a **16-bit** zero at
  offset 52. Bytes 28..47 and 54..55 are not initialized by that constructor.
- Glyph destructor `0x003d8891` releases owners at offsets 24, then 20, before
  the real base destructor. Its vtable is at `0x004af440`. No ownership cleanup
  at offset 56 is invented.
- The genuine string assignment interface returns `void`, matching native weak
  assignment `0x0039e645`. The canonical string destructor remains unchanged.

Authentic helpers come from public-domain gameswf
[font definitions](https://github.com/weihuoya/gameswf/blob/7fdd64b3cdae7ad36ecaf1da023a5cb61cd38a9e/tu-testbed/gameswf/gameswf_font.h)
and
[smart pointers](https://github.com/weihuoya/gameswf/blob/7fdd64b3cdae7ad36ecaf1da023a5cb61cd38a9e/tu-testbed/base/smart_ptr.h),
adapted to the independently verified retail hierarchy. Real font, glyph and
base implementations remain native imports. No vptr is assigned manually.

## Verification limits

Before adding the target body, the declaration-only prerequisite passed all
114 renderer functions and 33 section/region checks. Its affected closure
passed 16 builds, 1,364 function comparisons, 1,691 section comparisons and
16 region comparisons. No new definitions or vtables were emitted. Compile-time
assertions preserve the 12-, 32- and 36-byte extents.

After adding the target, only its 500-byte definition is newly emitted. All
144 previous allocated object sections retain their payloads; that object audit
does not replace linked verification. The strict link fails before the target
and dependent comparisons can execute. No artificial lifetime wrapper, padding
object, compiler-flag variation, new branch hint, output rewriting or mask is
used. This is preserved evidence for future work, not a matching implementation.
