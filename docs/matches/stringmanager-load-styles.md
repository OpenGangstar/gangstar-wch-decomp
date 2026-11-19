# StringManager style loading

The complete 332-byte loader and its original 40-byte default template match.
It reads big-endian records from ResStream, constructs real TextStyle objects,
uses their actual Read method and preserves the original chunk-end seek.
No validation or behavior is invented.

```text
OK  _ZN13StringManager10loadStylesEPKc  0x0034bd51  332 bytes
OK SECTION .string_load_styles  0x0034bd50  332 bytes
OK SECTION .string_style_default  0x00435fac  40 bytes
```

Function SHA-256:
`5443e0d83dafbbf1c552e45d4e59519589b35d0f83ab4c25ff99e49c7a928525`.

A local nonvirtual owner contains only aligned storage for the real DataStream.
It placement-constructs that object and invokes the actual native D1 exactly
once. Both owner and object are 16 bytes, alignment four. No automatic
DataStream member, second destruction, fake vtable, new ownership field or
global destructor-header change is involved. All owner helpers inline normally.
Qualified Tell/Seek calls preserve the observed direct dispatch.

The whole owning ARM profile retains inline limit 80 and enables the native
stack-protector policy. TextStyle::Read receives its actual weak linkage;
its existing 104-byte body remains exact. Every other existing method, the
three destructor entries, vtable and GOT remain exact. This recovers verified
ABI/configuration behavior, not the original source spelling.

The only newly emitted code/data are this function and the default template.
DataStream D1 remains a genuine weak native import, with no binding masking
a compiled definition. The affected current-root closure passes 15 builds,
1,153 function comparisons, 850 sections and 15 regions. The canonical full
190-profile gate also passes. Reproduce with
`python tools/build.py sdk-startup-stringmanager`. Three other StringManager
methods remain pending, so no Fully Linked completion is credited.
