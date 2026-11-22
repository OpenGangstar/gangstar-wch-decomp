# Physics source corrections and rejected experiments

These investigations concern pending functions. None receives new matching
credit. Canonical progress remains 4,286/4,550 functions and 353,094/561,716 bytes
(62.86%); Fully Linked remains 20.39%. Canonical C++ and assembly markers are
unchanged by this checkpoint.

## Reliable native analysis

Corrected Thumb instruction widths, false returning-call termination overrides,
physical argument storage and four spurious function boundaries restore the
complete 4,800-byte height-map method's executable body: 2,042 instructions,
4,672 code bytes and 128 literal-pool bytes. Twelve internal long branches stay
branches; the genuine recursive call stays a call. No retail instruction or
memory byte was edited. Subsequent conclusions compare original instruction
operands, not merely decompiler expressions.

## GetJumpHeight: wrong interpolation edge

For `PhysicAttributes::GetJumpHeight` at Thumb 0x0031a6fd, all six archived
candidates used A-B in the final coefficient where retail uses B-C:

```cpp
(position.X - B.X) * (B.Y - C.Y)
    - (B.X - C.X) * (position.Y - B.Y)
```

The native loads and subtraction operands at31a8d6/31a8e8 identify B and C
independently. A finite binary32 example on a square ramp yields native 2.5
versus the old candidate's 6.25. This corrects the earlier blanket claim that
the interpolation formula was already faithful.

One approved v1-based correction in current source context compiles to 588 bytes
versus native 596. Strict extent checking stops linking. All 41 previous function
payloads and semantic relocations remain unchanged, but linked38-function/
11-region, GOT and full-target checks were not run. The unlinked checker also
refuses 49 unresolved relocations. This is a preserved correct-source candidate,
not a match. No additional source form was tried.

## Large height-map intersection: persistent coefficients and normal graph

For the 4,800-byte overload at Thumb 0x0031b9a9, an accepted overlap candidate can
replace the current triangle even when all segment and containment tests fail.
Its AB overlap refresh updates coefficients subsequently consumed by the BC and
CA gates; BC overlap similarly updates CA coefficients. Skipped flag/epoch
entries do not refresh them. All six old forms incorrectly retained entry
coefficients. The complete correction preserves entry straddle snapshots while
updating eight persistent coefficients at their native pre/post-call stages.

A separate operand audit identifies B-anchored normal calculations. Stock SDK
`getNormal` uses C-A; native uses C-B, with the observed signed products and
additions. The intermediate binary32 rounding differs on finite inputs. The
four normal paths account exactly for 16 excess subtractions and 12 missing
additions in the old candidate. The current corrected candidate's math-call
census now equals retail: 94 subtractions, 75 additions and 72 multiplications.

The coherent current source prefix retains the actual accepted
`FindLowerCostNode` 192-byte and `LoadArrays` 1,336-byte definitions, current
headers and all 17 established compiler flags. The historical fixture lacked
both definitions: an absolute import could not satisfy a real 192-byte section
assertion. That assertion was preserved, not weakened.

The corrected current target remains 4,864 bytes versus native 4,800, with frame
428 versus 404. All 41 old function payloads/semantic relocations and 56 old
allocated sections remain identical. A separate relocated diagnostic image,
with a verified missing ARM PLT comparison binding restored, passes all 38 old
functions and 11 support checks. The target is relocated in that image and
receives no native byte-comparison credit. Original strict failures are retained.

## Compiler evidence and rejected configuration

A single dump-only build reproduces the entire current object byte for byte,
including all 42 function payloads and 57 allocated sections. The real-object
footprint is the same120 bytes as native. The first relevant motion occurs in
`069t.sink`: coefficient arithmetic moves past the segment queries; global
allocation/reload later assigns scalar spill homes. Extra frame space is below
the real objects; no larger constructor object has been established.

One precisely scoped `-fno-tree-sink` control restores the native 404-byte frame,
all seven object offsets and pre-query arithmetic order. It still emits 4,832
bytes and regresses seven previously matching functions. Both strict links fail;
linked checks are skipped. The configuration is rejected. This does not prove
the original compiler flags, and no flag matrix follows it.

## GetRandomDestination: current-context replay remains negative

The exact archived v3 body was compiled once on the full current prefix,
headers and17 flags, retaining all current source and selectors. It still emits
the identical 724-byte target with the same 11 scalar stack-operand differences,
first at+0x52. The function and full-section checks explicitly fail.

All 41 old function payloads/semantic relocations are identical; owner38-function/
11-region checks and the Character/NPC dependency profiles pass. Actual output
contains 223 passing function, 56 section and 3 region checks, alongside the two
target mismatches. No source, slot, lifetime or flag variant was added.

## Preserved evidence

Private reproducibility packets remain under `_scratch`:

- `worker-jump-height-semantic-bc-control`: corrected588-byte candidate and
  unresolved-link/extent proof.
- `worker-heightmap-normal-current-control`: corrected4,864-byte current
  candidate and passing relocated old-function proof.
- `worker-heightmap-current-frame-diagnostic`: byte-identical dumps and pass map.
- `worker-heightmap-no-tree-sink-control`: rejected configuration and regressions.
- `worker-random-destination-current-context-control`: exact current replay and
  explicit target mismatch.

They preserve source, commands, raw results, hashes and failure boundaries.
No game data, proprietary tools, relaxed target extent or fabricated matching
credit is included. The ownership registry records released investigations and
new independent assignments.
