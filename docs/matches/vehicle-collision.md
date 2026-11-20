# Vehicle collision match

Vehicle::collision(vector3df,int) at Thumb 0x00313385 matches all 1360 native
bytes and its complete section. The coordinator independently rebuilt it with
the actual compiled onDoorClosed neighbor at 0x003138d5 (128 bytes).

The remaining six-byte operand-order discrepancy was resolved through real
__aeabi_fmul/__aeabi_fadd calls and truthful const declarations. Compiler dumps
show generated FP calls are const calls (call_insn/u), while plain external
prototypes falsely clobber memory. The final declarations restore that existing
compiler contract: all 40 relevant calls again have /u. No artificial barriers,
register pins, aliases, extra helpers, hints, flags or output edits are used.
The existing matched helper callers remain byte-identical.

The two existing four-byte fields at 128 and 912 are refined to float without
moving fields or changing Vehicle size 1012. Three native sound arrays are
only declared/imported; no data definition or proprietary bytes are added.

```text
OK  _ZN7Vehicle9collisionEN3irr4core8vector3dIfEEi  0x00313385  1360 bytes
OK SECTION .vehicle_collision  0x00313384  1360 bytes
```

Native/linked SHA256:
`6142f89f79c86a44c26b3e57648ce1731ce4817adbdd62c4867d666645056733`.
The coordinator verifies all 188 prior owner functions and 112 prior selectors,
the new function/full section and genuine compiled neighbor. Only collision is
newly defined. The private affected-model gate passes 47 profiles (1850 function
and 1828 selector checks); all layout assertions pass.

The full canonical gate then passes 191 profiles, 5436 functions, 5340 sections
and 181 regions: all 10957 comparisons exact, exit 0, 1068 frozen inputs stable.
Only after that proof is the verified assembly marker removed and official
tables regenerated. No existing decompiled function body changes.

The earlier plain-helper 1356-byte form remains rejected. Its diagnostic replay
preserves all code/data/relocation sections, but two string tables have different
anonymous namespace suffixes; no complete-object identity is claimed for that
replay. No output normalization was performed.

Matched/Fuzzy becomes 345786/561716 bytes (61.56%), 4274/4550 functions.
Fully Linked remains 112376 bytes (20.01%), 125/203 units. All 17703 original
identities/classifications remain unchanged. Native Windows code is unchanged.
