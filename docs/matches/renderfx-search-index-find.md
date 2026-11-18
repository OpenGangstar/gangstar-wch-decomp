# RenderFX search-index lookup

The third bounded source candidate matches all 300 bytes:

```text
OK  _ZN8RenderFX11SearchIndex4FindEPKc  0x003eed69  300 bytes
```

The lookup builds the real suffix string key, calls the native weak find_index,
then traverses the original candidate records and dot-separated path tests.
The 128-byte stack buffer, 260-byte records and native use of the original full
name length on the final component are preserved. No bounds checks or parsing
fixes are invented for the matching reconstruction.

The permitted GNU likelihood hint is `__builtin_expect(match != 0, 1)` on the
successful strstr branch. Both earlier ordinary forms emitted identical
304-byte functions; the hint recovers native branch layout and register use.
The complete 300-byte function and every affected existing match compare;
no compiler output is edited. The hint does not change the branch condition.

The hash view follows authentic tu-testbed container.h records: eight-byte table
header followed by 28-byte entries, with the value at entry offset 24. It adds
no fake one-element array or engine algorithm. Native find_index and the
length-taking string constructor remain imports. The existing zero-initializing
hash constructor only changes its pointer member name from table to m_table;
layout and emitted code remain unchanged, including old RenderFX constructors
and SearchIndex destructor. SDK record/return evidence is archived under
_scratch/renderfx-search-find/reference with provenance in its NOTES.md.

Shared native placements retain and explicitly compare the compiled definition
in RenderFX and both menu/widget images. All current string, coordinate, callback
and color-transform matches are included. Coordinator graph: 9 profiles,
1,851 passing function/section/GOT comparisons, exit zero. Proof:
_scratch/renderfx-search-root.log and .exit. All affected header users pass;
no existing game function body, Windows source or engine implementation changes.
