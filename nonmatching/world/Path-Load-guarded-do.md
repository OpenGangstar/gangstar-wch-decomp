# Path::Load: guarded-do control (unmatched)

Target: `_ZN4Path4LoadERKN7Structs4PathEPN3irr7collada15CColladaFactoryE`,
Thumb `0x00300bc5`, 200 retail bytes. This experiment does not replace the
preferred candidate or qualify for matching credit. Its assembly marker remains.

The native loop has a positive-count guard, local index initialization after
that guard, and a fresh member-count comparison at the backedge. The preferred
source uses a `for` loop. An unchanged-output neutral diagnostic had already
traced its four remaining register-byte differences to input/address reloads;
the persistent Z value correctly occupied R8.

One bounded experiment replaced only that loop wrapper with a positive guard
and `do` loop, preserving element reads, float conversions, vector assignment,
index increment, fresh count reads and final cleanup. The attached patch records
the change against the authenticated preferred full source; it does not apply
directly to canonical Path.cpp, which still lacks this function. The source hash before the patch is
`8ca0cfd9f98d4279e1bbf3f6dbbace6d476db81d3155833e93bffa1df9853d87`;
after the patch it is
`bf64636959351511ab09ddd1f3e8c109e37c597c287c46a6c90cf5261c59b795`.

The original optimized tree already had a guarded-do shape. This was disclosed
before the trial as a substantial risk that the source change would not affect
reload selection.

## Result

One original frontend/assembler pair exited successfully, with unchanged
compiler flags and no diagnostic options. Both function and input section remain
200 bytes. Exactly two whole-object bytes change, both in the target loop test:

```text
preferred/native: cmp r3,sl; bgt body
guarded-do:       cmp sl,r3; blt body
```

The original four register differences at offsets `0x68`, `0x6a`, `0x72` and
`0x78` remain. The new comparison adds differences at `0x9c` and `0x9f`, for
six nonrelocated differing bytes. There are also unresolved relocation operands
in the prelink comparison. No LD or authoritative linked comparison was run;
these six ordinary code differences already reject exact equality.

The 7,480-byte object has SHA256
`57c0e19cf91453b678dacd0b38f223baee048fe19f1bf979ce85cb4cd709a015`.
The 11,003-byte assembly has SHA256
`76a5b458fc6704be2a0f9602b563ab55643b7d3e07075db37b01ccf03799cd56`.

All 12 off-target functions, 17 off-target allocated payloads, 53 imports,
69 off-target references and all 78 references remained exact. Full symbol,
section and ELF-header metadata remained exact, with no identifier mapping or
output editing. All 2,891 pinned files remained unchanged.

A final reporting helper initially compared the 119 pinned compiler/runtime
files against the entire NDK directory. That membership assertion failed after
the successful compilation and preservation checks. Its original failure and
outputs were retained. A separately reviewed reporting-only resume corrected
the directory universe to the original compiler subtree and runtime, verified
119/119 exact membership and hashes, and left all compiled outputs and original
results unchanged. There was no compiler retry.

Keep the preferred 200-byte candidate with its four-byte residual. Do not repeat
the guarded-do wrapper or reset the earlier source-attempt budget from this
negative result. A further source experiment requires new allocation evidence.
