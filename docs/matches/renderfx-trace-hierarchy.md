# RenderFX::TraceHierarchy

The 464-byte Thumb function at `0x003ecb09` matches the retail library exactly.
The faithful unhinted traversal reuses the typed name/string helpers proven by
CollectCharacters and context tracing. It preserves root fallback, visibility
and alpha filtering, indentation, edit-text/sprite/type branches and recursion.
The world color-transform import returns the actual native reference; no
invented complete gameswf character class or hidden result buffer is used.

```text
OK  _ZN8RenderFX14TraceHierarchyEPN7gameswf9characterEii  0x003ecb09  464 bytes
OK SECTION .renderfx_trace_hierarchy  0x003ecb08  464 bytes
```

Function SHA-256:
`381a56f1985b3a086c00cea942896572aaabd9b9796e97cc89c56b20e88dfb08`.
Only the new function and seven actual print-literal objects are added. All
seven complete physical sections compare at their original addresses. The
five-byte PLAY/STOP symbols occupy eight-byte native sections including padding.
No helper, vtable, compiler-output edit, forced inline or flag change is added.
All existing compiled code/data remains verified.

The owning function initially matched while independent consumer checks exposed
BLX instead of the native BL to get_world_cxform. Its genuine Thumb metadata
was added to both consumers, which now explicitly compare this function and all
seven literals. Pre-repair images and failed comparisons were preserved; they
were not treated as successful target proofs. The original missing PLT bindings
for fcmpeq and memset were likewise corrected without changing source or flags.

The final full current-root gate passes 190 profiles and 10,584 comparisons.
The existing compiler profiles, native dependencies and old comparison selectors
are retained. The final affected consumer closure also passes after linker-file
line-ending normalization. Shared string helpers remain unchanged from the
accepted collection function. This source remains incomplete, so the additional
464 matched bytes do not add Fully Linked credit.
