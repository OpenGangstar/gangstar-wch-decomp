# Fully Linked reporting investigation

## Root cause and upstream meaning

The previous adapter in `tools/bytematch.py` unconditionally emitted zero for
`complete_code`, `complete_code_percent` and `complete_units`, and false for
every unit's `metadata.complete`. ByteMatch faithfully displayed those values.
The old documentation incorrectly made a complete replacement game library a
prerequisite for reporting completed code units.

Objdiff's report generator takes the project's `metadata.complete` flag. When
true, it assigns the unit's full `total_code` to `complete_code` and contributes
one complete unit. Project/category totals sum those contributions. ByteMatch's
code bar reads `complete_code_percent`, which is
`100 * complete_code / total_code`; it does not infer completion from a green
100%-matched unit or inspect the project's executable itself.

References inspected on 2026-11-18:

- [Objdiff report schema](https://github.com/encounter/objdiff/blob/9aeec9cbab1a056ade7dc1f1625aacc41b0f8511/objdiff-core/protos/report.proto)
  names the complete/linked fields and unit metadata.
- [Objdiff report generation](https://github.com/encounter/objdiff/blob/9aeec9cbab1a056ade7dc1f1625aacc41b0f8511/objdiff-cli/src/cmd/report.rs)
  sets complete code/data and unit counts from that metadata flag.
- [ByteMatch measures](https://github.com/Veradictus/ByteMatch/blob/37153b5d1b30531d4410d5a595592080962ce883/src/report/measures.ts)
  calculates percentages and sums complete bytes/counts.
- [ByteMatch display](https://github.com/Veradictus/ByteMatch/blob/37153b5d1b30531d4410d5a595592080962ce883/src/components/project-view.tsx)
  distinguishes the linked, matched and additional fuzzy layers.

## OpenRAC comparison

| Project | Match evidence | Unit completion | Delivery |
| --- | --- | --- | --- |
| [rac1-decomp](https://github.com/OpenRAC/rac1-decomp/blob/84bd565ff5d079384f1b673ac8e39ea3e06c68b7/tools/gen_progress_report.py) | From-scratch build and retail comparison | Every function in the reporting unit is finished/exact | Custom version-2 report, CI freshness/schema checks, version report artifact |
| [rac2-decomp](https://github.com/OpenRAC/rac2-decomp/blob/4ea93ceaf43aec055e19211d36512e847860bac2/tools/progress.py) | Verified placement results from linked programs | Every function in the reporting unit is matched | Custom version-2 report with complete-code sums and CI checks |
| Gangstar | Original ARM compiler, native-address function/data comparisons, verified catalogue | Previously hardcoded false; now every game function from the original source must be matched | Existing `android-arm_report` artifact; now also objdiff schema validation |

Neither OpenRAC custom exporter requires an `objdiff.json` to calculate these
fields. In a conventional objdiff project that configuration supplies real
base/target objects and `metadata.complete`; here the existing report adapter
supplies the equivalent metadata directly. We do not invent original object
paths: the retail input is a linked ARM library, not the original relocatable
objects. Real object splitting and an objdiff comparison configuration would
be separate work if instruction-based fuzzy measurements are wanted.

The exact
[OpenRAC CI validation convention](https://github.com/OpenRAC/rac1-decomp/blob/84bd565ff5d079384f1b673ac8e39ea3e06c68b7/.github/workflows/progress.yml)
is adopted: objdiff-cli 3.8.1, release SHA-256 checked, then a report self-diff
before artifact upload. CI still needs neither game data nor the matching NDK.

## Qualification and accounting safeguards

Completion uses exact catalogue statuses, not rounded percentages, area
completion, or the presence of an object file. Any pending function, including
a zero-byte one, prevents completion. Engine/dependency functions remain outside
the existing game-only scope. Constructor/destructor aliases retain the same
symbol accounting as matched progress.

The viewer currently groups by `(area, source_file)`, yielding 208 report units
for 190 distinct catalogue source names. Some startup functions have a different
area from their parent source. Keeping unit identifiers stable avoids breaking
existing links/history, but completion is decided across **all** areas for the
source. For example, finished core helpers cannot complete AIManager.cpp while
its AI functions remain pending. Merely completing each area fragment separately
would incorrectly include 824 extra bytes in this snapshot.

All eligible functions have comparison selectors in the existing build
manifests. The native verifier requires defined executable functions, rejecting
absolute retail-address symbols as function substitutes. Calls to other units
may still use the established retail bindings; this does not finish any pending
function in the reporting unit itself. Whole-library integration, dynamic
relocations, complete data attribution and port functionality remain separate
milestones. No compiler flags, catalogue rows, game source, or Windows x86 files
are changed by this reporting fix.

An artifact audit found 98 complete source groups already covered by a single
native-address verification ELF. Two small relocation-free units, importgl.c
and AdpcmState.cpp, previously compared only relocatable objects. Minimal ARM
linker recipes now place their existing unchanged code at its retail addresses;
all six selected function/alias comparisons pass after linking. TargetMarker's
remaining header-owned singleton getter is already compiled, linked and checked
by MenuManager_map's verification unit; its other functions are checked by the
TargetMarker unit. Logical catalogue ownership therefore does not always equal
the physical translation unit that emits a shared/header function. Every
qualifying function is backed by actual native linked code, not a missing
function's absolute-address binding.

The final per-function audit covers all 1,571 qualifying function/alias entries
from those 101 source groups. Each selected definition has an executable section,
the original ARM address and identical complete retail bytes. The local
`build/android-arm/linked-code-proof.json` records the verification recipe for
every entry without storing retail bytes.

## Reproduced result

Baseline: main commit `0940b5e6e96203a0c392e5d1c57b2387f43ac859`.
Uncommitted decompilation work in another worktree is intentionally excluded.

| Measure | Previous report | Corrected report |
| --- | ---: | ---: |
| Game functions matched | 4,139 / 4,661 | 4,139 / 4,661 |
| Matched code | 322,056 / 575,264 bytes (55.98%) | unchanged |
| Fuzzy Matched code | 55.98% | unchanged |
| Fully Linked code | 0 / 575,264 bytes (0.00%) | 101,790 / 575,264 bytes (17.69%) |
| Complete report units | 0 / 208 | 114 / 208 |
| Complete original-source groups | Not reported | 101 / 190 |
| Tracked data | 0 | 0 (coverage remains untracked) |

Item.cpp is one qualifying example: all 40 catalogue functions and 3,760 code
bytes are matched. The same rule applies to the remaining complete sources;
partially matched sources contribute zero complete code even when many of
their functions already contribute to matched code.

Fuzzy equals matched because pending/near-matching functions receive zero
partial credit. These are separate overlapping measures, not three additive
percentages. No partial scores or data coverage are fabricated.

Verification performed:

- `python -m unittest discover -s tests`: 89 tests passed, including incomplete
  units, category sums, cross-area source fragments, zero-sized pending
  functions, vendor exclusion and alias accounting.
- `python tools/build.py --all`: exit 0, all 9,751 ARM function/section/region
  comparisons passed using the existing matching toolchains and private retail
  library. No native matching behavior was changed.
- Every report field other than completion metadata/measures is identical to
  the baseline exporter, including function scores, unit identifiers, category
  membership, matched progress and the deliberately untracked data fields.
- `python tools/check_repository.py` and `python tools/progress.py --check`:
  passed; the matched-function catalogue and README percentages are unchanged.
- `python tools/bytematch.py`: reproduces the corrected metrics above.
- objdiff-cli 3.8.1 `report changes` on the generated report against itself:
  accepted the schema and produced no changes.

ByteMatch will show the corrected linked percentage after these changes are
approved, reach the default branch, and its successful push artifact is ingested.
The site is not updated merely by generating a report locally. No PR or upload
is required to inspect these local results; no PR was created for this work.


## Verification after PR 711

The current catalogue reports 4,205/4,661 matched functions and 332,482/575,264
matched bytes (57.80%). Fully Linked code is 103,742/575,264 bytes (18.03%),
covering 118/208 viewer units and 105 complete original-source groups. Fuzzy
Matched remains 57.80%. These values supersede the earlier baseline totals.

A fresh native executable audit checked all 1,598 qualifying function/alias
entries. Each has a real executable STT_FUNC definition at the retail address,
with the correct size and identical native bytes. No qualifying entry lacks a
linked executable proof. The full current ARM build passed 182 profiles and
10,258 function/section/GOT comparisons. Local evidence is retained in
_scratch/linked-current-full.log/.exit and
_scratch/linked-current-executable-audit.json.

Comparison with the preceding exporter proved that every field outside completion
metadata and completion measures is identical. All 89 tests and repository and
progress checks pass. The changes are now integrated for the next reviewed PR.

The regenerated current report also passes objdiff-cli 3.8.1 `report changes`
against itself with exit zero. Evidence is retained in
_scratch/linked-current-schema-validation.json and .exit.

A broader executable audit also checked every currently credited game entry. All
4,205 entries covering 332,482 catalogue bytes have matching native-address
executable definitions. The audit found zero missing proofs. Local evidence is
_scratch/matched-current-executable-audit.json.

## Published report verification

PR 712 merged as `6bf7063e05ad51b980c9f9f631a2ca4c91d37ad2` after both
pull-request checks passed. The default-branch CI run `44328683329` also passed
and published `android-arm_report`, artifact `14438805689`. Downloading that
artifact independently confirmed 332,482 matched bytes, 103,742 complete bytes,
575,264 total bytes, 118 complete units and 4,205 matched functions. This checks
the uploaded report, rather than relying only on local export output.

A fresh full native build before publication passed all 182 profiles and 10,258
function/section/region comparisons with exit zero. All 89 tooling tests and
repository/progress checks passed. Local build evidence is retained in
`_scratch/hourly-linked-final-full.log` and `.exit`; the downloaded public report
is retained in `_scratch/pr712-main-artifact-report.json`.

The browser verification still showed the preceding PR 711 commit, with 57.80%
matched and 0.00% linked. Thus publication is verified, while ingestion of the
new commit was still pending at that observation. Do not interpret the older
page as a failed comparison or claim that the live site has updated yet.
