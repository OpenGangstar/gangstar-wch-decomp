# PNG memory/string wrappers

The four functions attributed to `png_helper.cpp` delegate to the original ARM
C-library PLT entries. The memory-writing wrappers explicitly return the original
destination after the call; the comparison and length wrappers return the
C-library result. There are no data sections or shared-header changes.

The first compilation used direct return expressions for all wrappers and the
existing NDK 1.6 optimization flags. GCC reversed their source order, so all
four native-address checks failed. The generated memory-writing functions also
returned the callee's result rather than retaining the destination, differing
from the original instructions.

The accepted second compilation uses ordinary C++ destination returns and
`-fno-toplevel-reorder` to preserve the retail function placement. No assembly,
register constraints, compiler-output edits, or existing function changes were
used. The linker binds `memset`, `memcpy`, `memcmp`, and `strlen` to their original
ARM PLT entries, following existing verification profiles.

`python tools/build.py png-helper` printed exactly:

```text
BUILD png-helper
OK  _Z10png_memsetPvhi  0x003935bd  12 bytes
OK  _Z10png_memcpyPvPKvi  0x003935c9  12 bytes
OK  _Z10png_memcmpPKvS0_i  0x003935d5  12 bytes
OK  _Z10png_strlenPKc  0x003935e1  12 bytes
```

All four actual compiler-generated definitions are present at their retail
addresses in the native verification ELF. Only after these exact comparisons
were their assembly files removed and the catalogue regenerated. This completes
all four functions and 48 code bytes attributed to `png_helper.cpp`.
