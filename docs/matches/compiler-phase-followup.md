# Unchanged compiler-phase diagnostics

These investigations add diagnostic dumps to frozen candidates without changing
their source, headers or optimization flags. They locate compiler decisions;
they do not establish the original source or add matched or Fully Linked credit.
Every comparison below refers to the candidate's recorded historical closure,
not an untested reconstruction against current headers.

## Map notification: post-reload tail sharing

The strongest 220-byte candidate for `Menus::Map::Notify` at Thumb
`0x002e78ad` has 21 differing bytes. Its complete owning object remained
byte-identical after adding `-fdump-tree-all -fdump-rtl-all`:
`dc019f10c94f684528c714f5c4688fdda0c6c2ae13e5c0fda83c971650372018`.
All 637 existing function checks and 417 region checks passed. All 829 allocated
payloads and all raw relocation payloads were unchanged.

Tree passes and RTL through `141r.flow2` retain three separate push calls.
The first sharing decision occurs in `143r.csa`:

```text
Splitting bb 16 before 5 insns
Cross jumping from bb 15 to bb 16; 5 common insns
```

This merges case 0 with case 1 and leaves case 2 with its own complete tail.
Retail instead shares cases 1 and 2. Later `147r.bbro` changes physical block
order but preserves the earlier pairing.

GCC 4.2.1's
[`try_crossjump_bb`](https://github.com/gcc-mirror/gcc/blob/releases/gcc-4.2.1/gcc/cfgcleanup.c#L1821)
first favors a fallthrough predecessor, then
traverses predecessor edges and block-index pairs. It does not rank partners
by branch probability. The three candidate case blocks also have equal
recorded frequency. Consequently, a likelihood hint is not supported by this
pair-selection finding. Native code itself shares tails, so disabling
cross-jumping is not established as a correct retail compiler setting either.
The original source-level reason for the different pairing remains unknown.

## Sound selection: redundant-load elimination before RTL

`SoundManager::_getReadySound(int)` at Thumb `0x00353095` is 224 bytes in
retail. The frozen candidate remains 222 bytes. The diagnostic reproduced the
complete historical object byte for byte, and all 71 existing function checks
and 75 section checks passed. The linked candidate SHA-256 remains
`24022b22c11ba1abf9c0f115804b6d85532d4010f98f6e064a98c1974e557c77`.

All five saved source forms already include a second selected-slot query and
null test before `Stop(0)`. This is not an omitted source operation. SSA through
`033t.ccp` retains the separate memory load; `034t.fre` replaces it with the
earlier search value. The test survives through `040t.dce2`, then `041t.dom1`
threads the null and non-null paths and removes the redundant test. RTL
expansion therefore already contains the cached-pointer path.

Retail reloads the row and slot at `0x003530f8` and `0x003530fa`, then tests the
result at `0x003530fc`. No intervening call, write or escaped address has been
identified between the two queries in the candidate. Its declarations use
ordinary pointers and a boolean; `-fno-strict-aliasing` is already enabled.
The extra native load alone does not justify inventing a volatile qualifier,
callback, barrier or memory side effect. A new experiment requires actual
declaration, helper or compiler-context evidence explaining why the original
queries were not equivalent to the compiler.

## Target arrival: historical input recovery and allocation

The 60-byte `PlayerTest::onTargetReached()` at Thumb `0x003017b1` differs from
its saved candidate only in nine bytes expressing reversed register roles.
The original working snapshot was absent. The saved patch's four preimage
Git blobs were available, however, and applying the patch reproduced all four
recorded postimage identities. The remaining effective 78-file include closure
and build configuration were invariant across the corresponding history
interval. This established the tracked inputs without selecting a nearby
revision by guesswork.

One compile added only `-fdump-rtl-all` to the recovered historical flags.
The linked 60-byte candidate reproduced exactly, with SHA-256
`0478bba3fe62e9e9dc38da4d792ff5a3a03c22b9384aa498997132e46fd7f2b0`.
All 289 historical positive comparison lines were reproduced. The known target
mismatch remained the only failure. Current external compiler/library identities
were recorded; an unavailable historical compiler binary hash was not inferred.

RTL expansion represents `this` as pseudo 103 and offset 368 as pseudo 109.
`112r.cse1` shares an offset value across `justStoleCar`, and `131r.split1`
splits its materialization into 184 followed by a shift. The first dump exposing
physical register roles is `138r.greg`: `this` uses r4 and the offset uses r5.
Retail uses the reverse legal allocation. Later register renaming and scheduling
retain those roles. The dumps do not expose the precise earlier local-allocation
priority decision or establish an original-source correction.

## Disposition

All three functions remain parked with their assembly and original matching status.
No source permutation, optimization-flag change, output modification or new
branch hint follows from these diagnostics alone.
