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
The initial diagnostic did not establish the original source-level cause.
A separately authorized case-order trial subsequently matched all 220 bytes;
see [Map notification match](map-notify.md).

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

### Bounded FRE-only falsification

A separately authorized private experiment added only `-fno-tree-fre` to the
frozen sound candidate. It still emitted a 222-byte function. Its physical
section was 224 bytes, but alignment outside the function does not satisfy the
224-byte function requirement. The strict guard stopped before linking:

```text
STRICT SIZE FAILURE actual 222 physical 224 native224; no link/old closure invoked
```

The linked 71-function/75-section/GOT closure was not run in this experiment.
All 71 old unrelocated function payloads remained identical, which is not a
replacement for that linked proof. The new target raw bytes changed, so target
identity is not claimed.

Without FRE, `067t.pre` instead reuses the earlier slot value; `112r.cse1`
later removes the repeated test. Disabling FRE alone therefore does not retain
the native reload, restore its extent or establish a retail compiler setting.
No additional optimization-flag sweep follows from this result.

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
splits its materialization into 184 followed by a shift. The initial diagnostic's
first fully substituted RTL display is `138r.greg`: `this` uses r4 and the offset uses r5.
Retail uses the reverse legal allocation. Later register renaming and scheduling
retain those roles. Those initial dumps do not expose the precise earlier
local-allocation priority decision or establish an original-source correction.

### Current canonical replay

A separately bounded replay used the current canonical pointer type and actual
compiled `justStoleCar` body. The initial compile exposed a missing callback
declaration. Adding its ordinary, nonvirtual declaration then changed two
instructions in the existing NPC match. Reversing only two independent pointer
declarations restored that old match in the private context.

The replay also exposed missing Thumb metadata for the external `Weapon::hide`
callee in this profile's closure. Correcting that metadata restored its native
BL instruction. The actual compiled `justStoleCar` call was already correct;
its definition was not overridden.

With these prerequisites, the same complete 60-byte historical candidate was
reproduced, still differing from native in nine register-role bytes. All 342
current existing function checks and 112 region checks passed, with no skips.
The missing-declaration failure, NPC regression and wrong-call-mode result were
retained separately rather than counted as successful verification.

The [reproducible nonmatching patch](../../nonmatching/ai/PlayerTest-onTargetReached.md)
preserves the source and prerequisites against an identified baseline. None is
applied to production source; the assembly and progress remain unchanged.

### Reused detailed allocation evidence

A later audit recovered already completed local-details and runtime records;
no duplicate debugger or compiler run was needed. The detailed `137r.lreg`
records assign pseudo 103 to R4 and 109 to R5 before global allocation. Thus
138 is the first substituted display in the earlier diagnostic, rather than
the origin of these choices.

The retained runtime observes 13 quantities, not the ResStream three-item case.
Quantity 0 (`this`) has priority 5555; its suggested R0 attempt fails and the
ordinary attempt returns R4. Quantity 6 (offset 368), priority 3333, is attempted
later: R4 is live throughout its interval and R5 is free, so it returns R5.
Actual call/liveness/return records already explain the candidate's allocation.
They do not explain the native reversal or justify another source/flag grid.

The audit rehashed 879 retained inputs and all 15 recorded object identities,
and independently confirmed the same 60-byte target and nine native differences.
This remains historical frozen-context evidence; anonymous-name drift and its
preservation limits are disclosed in the private receipts. It does not claim
whole-object identity or a new replay against today's complete checkout.

## Disposition

Sound selection and target arrival remain parked with their assembly and
matching status. Map's separate, bounded source-order trial is now verified and
integrated. The flag experiment remains private, and no output modification or
new branch hint was introduced.

The matched Map result prompted three bounded family audits. MainMenu already
shares the native button-0/button-1 pair, and reversing its outer event clauses
was already tested. Settings has only one currently eligible pair of equivalent
localization tails; its relevant type-body order already matches native, while
the earlier R1/R1 versus native R2/R1 allocation remains unexplained. CarRental's
untried canonical 16-byte record has the same used fields at offsets 0/4/8 as
the private prefix, with no record-stride operation. None of these audits
established another source correction, and none ran another compilation.
