# Animation-name lookup

`ASprite::GetAnimIdx(const char*)` matches all 64 bytes at Thumb `0x00349dd5`,
including its complete section. It reuses the existing matched `GetFrameIdx`
traversal with the animation count, table and 12-byte `Anim` record. The actual
`ASpriteData` view supplies `animationCount` at offset 20, `animations` at 48
and `nameOffset` at 8. Zero/negative count returns -1 before reading the table. strcmp argument
order, cached count and first matching index are unchanged.

Six archived forms and the later read-only canonical-record form differed in
one commuted ADD halfword. Direct family reuse restores the native operand
order: it retains the mutable record view and computes the table within the
indexed traversal, rather than keeping a separate const byte-base local.
There are no new helpers, hints, register controls, barriers, output edits or
production option changes.

Only an ordinary GetAnimIdx declaration is added to the shared ASprite header.
The existing field model and every existing matched function body are retained.
The lookup uses an explicit mutable ASpriteData view at that existing boundary;
the broader pointer-type recovery is not integrated.

## Exact verification

```text
OK  _ZN7ASprite10GetAnimIdxEPKc  0x00349dd5  64 bytes
OK SECTION .asprite_anim_index  0x00349dd4  64 bytes
```

Native and linked SHA256:
`a79ca34d6b096e5534188720f8374fd14e6b63176ba3d8e6738e2c1388111d8d`.
The original strcmp ARM PLT binding is retained; the real compiled function is
placed at its native address with a strict 64-byte section assertion.

The declaration-only prerequisite independently passed 190 profiles and
10,937 comparisons with the target absent; all 955 frozen inputs remained
unchanged. The minimal lookup then passed the strict linked owner comparison,
including every old function/section/region and the new full 64-byte section.

The final independent root full gate passed 190 profiles: 5,427 function checks,
5,331 section checks and 181 region checks = 10,939 comparisons. Exit 0, no
mismatch or skip; all 955 frozen inputs remained unchanged.

The independently verified marker alone is removed. This adds 64 real matched
bytes. The source still has pending functions, so Fully Linked bytes and the
denominator are unchanged. No Windows port or launcher changes are involved.

## Rejected or unnecessary supporting work

An isolated ASpriteData pointer recovery removed a duplicate proxy and made
three type-only compatibility edits. Its target-absent gate of 190 profiles passed
10,937 comparisons. A separate original-compiler layout fixture confirmed both
records have size 56 bytes and alignment 4 and identical relevant offsets. Its access-control
flag was confined to that fixture. The original const-view lookup still differed
in 2 bytes; this type recovery was not the matching fix.

A controlled r3 frontend diagnostic kept source, options, assembler, linker and
harness frontend fixed. It retained all 42 old functions, 35 sections and one
region, but emitted the same unmatched lookup. No production toolchain change
was made. The successful function uses the existing configured original SDK.
