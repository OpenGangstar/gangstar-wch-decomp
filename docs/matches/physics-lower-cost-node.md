# Physics lower-cost node selection

`PhysicAttributes::FindLowerCostNode` matches all 192 bytes at Thumb
`0x0031a40d`, including its complete physical section and literals. It is a
member function returning the existing 24-byte AStarNode by value: hidden
return pointer in R0, this in R1, array pointer in R2, output index in R3.

The implementation reuses the genuine release-mode Irrlicht size/indexed
accessors established by the checkpoint-range match. The existing node fields
and 24-byte size are unchanged. The recovered default constructor initializes
four invalid ushort keys, zero float costs and state words, and the final
invalid ushort key; the two trailing padding bytes are not initialized. The
selected index defaults to zero, including the empty-array case. Integer
minimum 999999999 and the native float/int conversions remain intact.

Five saved earlier outputs were audited. Three are byte-identical and differ
from native in four comparison bytes, so no first-pass budget was reset. The
single bounded accessor adaptation adds indexed access absent from every saved
form. Its ordinary constructor/declaration prerequisite independently passed
190 profiles and 10,927 comparisons with the target absent. No new outlined
helper, flags, hints, barriers, forced registers or output edits are used.

## Verification

The shared physics section places the real compiled definition at its native
address before the existing consumer dependency discard rules. Character, NPC
and PlayerTest images now explicitly verify this definition and its full
section as well. No prior comparison is removed or compiled body overridden.

```text
OK  _ZN16PhysicAttributes17FindLowerCostNodeEPN3irr4core5arrayI9AStarNodeNS1_12irrAllocatorIS3_EEEEPi  0x0031a40d  192 bytes
OK SECTION .physic_find_lower  0x0031a40c  192 bytes
```

The final independent root `python tools/build.py --all` passed 190 profiles:
5,425 function checks, 5,329 section checks and 181 region checks = 10,935
comparisons. Exit 0, no mismatch or skip; all frozen input hashes remained
unchanged. The original per-profile toolchains and options were retained.
All four linked images independently have native function SHA256
`44df9ac5048ac0eb763c8be9f4106770ce089ebea763ef08010f04113702a797`.

Only the independently verified assembly marker is removed. This adds 192
matched function bytes and does not complete the physics source group or add
fully linked bytes. No existing matched function body or node field is changed.
