# RenderFX::CollectCharacters

The 240-byte Thumb function at `0x003ed1bd` matches the retail library exactly.
It preserves visibility/type filtering, substring selection, native name-length
checks, collection growth and recursive traversal of sprite children.

## Authentic helper reuse

The implementation uses the actual `get_name()` const-reference interface and
`tu_string` accessor chain: `c_str`, conversion, const/nonconst `get_buffer`,
and `using_heap`. The existing inline `c_str` body is changed to that authentic
chain. Constructor declarations, destructor branch hint, 16-byte storage and
all existing compiled matches are preserved. The new `length`/`size` accessors
retain retail tag/heap-buffer-size minus one; first-byte emptiness would change
behavior. No upstream union layout is transplanted.

Reference: public-domain tu-testbed `container.h` and `gameswf_character.h` at
weihuoya/gameswf commit `7fdd64b3cdae7ad36ecaf1da023a5cb61cd38a9e`.
Upstream's tag and heap offsets differ from this retail fork. The adaptation
uses the independently observed retail tag at string+0, heap size at+4, and
heap pointer at+12. The name field is at character+136 and sprite children at
+324; the partial views do not assert complete engine object layouts.

## Verification

```text
OK  _ZN8RenderFX17CollectCharactersEPN7gameswf9characterEPKci  0x003ed1bd  240 bytes
OK SECTION .renderfx_collect_characters  0x003ed1bc  240 bytes
```

Function SHA-256:
`bfe1ebbb270da06bf252a0242d84c40139a4f7d41a1ca67b8dd2bdf3bab2034c`.
Only the target function/text section is newly emitted; no helper or data
body is added. Every old allocated object payload remains identical. Both
consumer images retain the real compiled function at its native address,
remove only their obsolete retail target import, and explicitly check it.
No compiled definition is masked by an absolute binding.

The full gate passes 190 profiles and 10,545 comparisons: 5,269 functions,
5,095 sections and 181 regions. The final affected consumer closure passes
613 functions, 317 sections and five GOT regions. Existing flags, dependencies
and function/section selectors are retained. There is no relaxed overlap check,
forced inline, branch hint or compiler-output edit. The original source still
has pending functions, so this adds 240 matched bytes and no Fully Linked credit.
