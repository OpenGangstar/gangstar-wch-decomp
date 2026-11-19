# StringManager destructor family

One ordinary C++ destructor now reproduces the real D1/D2 aliases and D0
deleting destructor. It unloads six packs, destroys each TextStyle font
array/style, erases the pointer-vector range and invokes the existing native
vector-base cleanup. Existing layouts, constructors and decompiled bodies
are unchanged.

```text
OK  _ZN13StringManagerD1Ev  0x0034be9d  240 bytes
OK  _ZN13StringManagerD2Ev  0x0034be9d  240 bytes
OK  _ZN13StringManagerD0Ev  0x0034bf8d  248 bytes
```

The D1/D2 function SHA-256 is
`4dbaa04cb13b60ba3e3d8e524334df7f9015e8c815e3ba31f718545966a8bf43`;
D0 is `9a827892070eb19abcc2d17e028afd83de2e0034eab7aa4a1ad6104792bce02b`.
The complete sections and original 16-byte vtable also compare exactly.
D1/D2 are compiler-generated aliases, not duplicated authored functions;
progress follows the existing catalogue convention of three entries /
728 reported bytes.

The restricted licensed STLport erase/copy/destruction-trait chain restores
the native conditional byte-count memmove tail. The reference commit is
`e64e7c849b0b659d3e198e4efaed563601e554be`; it does not identify the exact
retail library revision. No always_inline attribute, manual vptr, output
patch, invented ownership field or parent-class replacement is used.

The complete owning profile uses `-finline-limit=80` instead of 70. Measured
compiler diagnostics rejected the 35-instruction erase estimate at the old
limit; the larger budget allows ordinary inlining. All 16 existing owning
functions remain exact. Other profiles retain their own flags. This is a
verified reconstruction configuration, not proof of retail's original flags.

A signed style index with the normal `index < styles.size()` promotion
recovers the native duplicate counter lifetime. The unsigned native branch
alone does not prove the original source declaration. The pack loop and
current-end erase remain unchanged; no cached end or comparison trick is
introduced. All helper functions inline; only the family and original
vtable are newly emitted.

Reproduce with `python tools/build.py sdk-startup-stringmanager`.
The current-root affected closure passes 66 builds, 3,041 function checks,
3,291 sections and 65 regions. Canonical full verification passes 190
profiles and 10,524 comparisons. Four other StringManager methods remain
pending, so this family adds no Fully Linked completion credit.
