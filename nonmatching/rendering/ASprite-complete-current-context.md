# Complete current ASprite context: no additional matches

One private translation unit combined the three unchanged preferred bodies with
the newly matched PaintFModule and all current matched ASprite source. Retained
fixtures had not previously compiled this complete combination. This tested
coherent source visibility, not a new algorithm or another source-form budget.

Exactly one current-profile frontend and assembler succeeded. Every copied source
and tool/runtime pin remained stable. Results are unchanged from the individually
preferred candidates, including their complete unlinked function bytes:

| Function | Function / input bytes | Native requirement | Result |
| --- | ---: | ---: | --- |
| GetAnimDuration | 80 / 80 | 82 | Unmatched |
| PaintModule | 500 / 500 | 512 | Unmatched |
| GetPixelInfoInFrame | 300 / 300 | 296 | Unmatched |

All 44 previously emitted function bodies remain byte-identical to the accepted
current object. This is an **unlinked raw-code comparison**, not a new native,
complete metadata, GOT, shared-header consumer or full-profile gate. The failed
extents stop the experiment before LD. No canonical header changed, no assembly
marker was removed, and no matching credit was added. PaintFModule's separately
verified 220-byte match remains intact.

The private context adds only genuine, previously reconstructed declarations and
views needed by these exact bodies: nonvirtual PaintModule and PixelInfo methods,
the existing ten-byte SpriteModule source-coordinate fields, mutable bounds in
the existing sixteen object bytes, the real VideoDriver destination-rectangle
overload at slot 49, and the existing nonconst IdentityMatrix declaration. It
does not create another matrix object or change a virtual slot count. These
prerequisites were applied **only in the private fixture**. The historical Cash
prototype regression remains an explicit wider integration gate; successful
compilation here does not waive it or authorize canonical header adoption.

The patch and JSON retain the precise base commit, before/after hashes and all
three original body identities. The patch has zero context to avoid whitespace
artifacts in a stored nested diff. Apply it only to a private copy of that base:

```sh
git apply --unidiff-zero --check nonmatching/rendering/ASprite-complete-current-context.patch
```

A private application reproduced all four complete input files after newline
normalization. No compiler output was edited. Earlier six-form and subsequent
explicit escalation budgets remain spent; do not repeat this full-unit context
without new evidence.
