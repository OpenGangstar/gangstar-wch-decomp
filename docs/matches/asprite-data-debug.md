# ASpriteData::Debug

The complete 1,296-byte function at Thumb entry `0x0034a729` matches retail.
Its complete 1,140-byte allocated literal section at `0x00435a70` also matches.

An archived reconstruction already matched every instruction except one indexed
byte load. Retail used `[r5, r3]`; the compiler emitted `[r3, r5]`. Declaring the
signed byte index before an explicit byte pointer, then indexing that pointer,
changed the RTL address operands from `PLUS(index, base)` to `PLUS(base, index)`
and produced the exact native instruction. The first new source form matched;
no assembly, register constraints, barriers, flags or output edits were used.

The implementation retains the native diagnostics and observed record traversal,
including the nine-byte Debug AFrame stride versus the ten-byte Swap stride.
It adds only the real Debug declaration, a local eight-byte Palette observer and
the owned function. Existing function bodies and record storage are unchanged.

Coordinator output:

```
OK  _ZN11ASpriteData5DebugEv  0x0034a729  1296 bytes
OK SECTION .asprite_debug_literals  0x00435a70  1140 bytes
```

The unit preserves all 13 existing function checks, constructor/vtable sections
and full GOT region. All header consumers passed 50 function, 34 section and two
region comparisons. The coordinator's full build passed 183 profiles and 10,267
comparisons with exit zero; evidence is retained in
`_scratch/hourly-713-final-full.log` and `.exit`. The exact function SHA-256 is
`fd6e0b1f7cbc253730818dc855805d64768cfcf6aaf32a288a63e9ff0f1fdb0d`.
