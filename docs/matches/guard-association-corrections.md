# Native-backed guard corrections: still unmatched

Complete native flow exposed behavior errors in saved unmatched candidates.
These corrections receive no matching credit. Canonical functions, assembly
markers and progress are unchanged. The [NPC freeze match](npc-freeze.md) remains
the only new credited function in this batch.

| Function | Preserved corrected source | Emitted bytes | Retail bytes | Other old raw definitions retained |
| --- | --- | ---: | ---: | ---: |
| NPC::Update | [common downed gate](../../nonmatching/ai/NPC-Update-common-downed.cpp) | 3044 | 3012 | 73 |
| NPC::attackTarget | [retarget guard](../../nonmatching/ai/NPC-attackTarget-retarget-else.cpp) | 2072 | 2108 | 71 |
| Vehicle::_processAIFlags | [pursuit priority and destination snapshot](../../nonmatching/vehicles/Vehicle-processAIFlags-corrected.cpp) | 3056 | 3220 | 197 |
| Vehicle::Update | [damage conditions and common material join](../../nonmatching/vehicles/Vehicle-Update-damage-common.cpp) | 3924 | 4020 | 199 |
| RenderFX::UpdateCursor | [release reference guard](../../nonmatching/rendering/RenderFX-UpdateCursor-release-else.cpp) | 1996 | 2012 | 109 |
| PlayerTest::Update | [car-interaction guard](../../nonmatching/ai/PlayerTest-Update-carinteraction-else.cpp) | 2216 | 2228 | 84 |

The table reports function extents; differing input-section sizes are recorded
below. Every strict extent gate
stopped before native linking. No candidate native ELF, target/full-section
comparison, linked owner/GOT/consumer result or matching percentage is claimed.
Older linked diagnostics remain separate baselines. No padding or output edits
were used.

## What the original machine code proves

NPC Update needs a common fresh isDown test after non-authored alive and
nonterminal dead/fade paths. The old source restricted the scene-only return to
authored characters. Its [detailed report](../../nonmatching/ai/NPC-Update-common-downed.md)
records the path proof, actual 3,044-byte result and remaining prerequisites.

NPC attack retargets an in-vehicle character at native 0x2ffc3c, then branches
directly to geometry 0x2ff6f4. The following empty-driver validation is an else-if
fallback, not an independent check of the newly selected vehicle. The old 2,084-byte
candidate did the latter; one else insertion emits 2,072 with the observed join.

Vehicle AI selects valid pursuit before waiting. Native 0x312124..0x31213e reaches
pursuit 0x3124d4; a null target falls back to waiting 0x312140. All prior sources
checked waiting first. One correction emits 3,040 versus the prior 3,060. Separately,
native 0x3121c8/0x3121ce/0x3121d4 captures adjustedDestination at offsets 260/264/268 before virtual
GetPosition at 0x3121de. Both candidates instead read destination at offsets 248/252/256 after that
callback. Correcting the member and preserving its snapshot emits 3,056. Each
independent defect received one bounded control; earlier budgets were not reset.

Cursor release updates its fourth controller reference only if a release
animation succeeds. When both fail, native sends the synthetic click at 0x3efca4, then
3efca8 branches directly to fifth-clear at 0x3efb7a. The old source updated fourth
unconditionally afterward. Moving only that assignment to the existing click
condition's else restores the observed reference behavior but still emits 1,996.

Player Update calls updateCarInteraction at 0x3054b2 for nonzero unknown372, then
3054b6 branches directly to scene visibility at 0x30536c. The byte 376 test and
finishedStopDriving belong to the else-if path. The old 2,200-byte source checked
them independently after car interaction. One else insertion emits 2,216; its
actual generated branch now skips that test as retail does.

The Player fragment also corrects a distinct virtual API call. The retail
ISceneNode vtable address point `0x0049084c` places
`updateAbsolutePosition(bool)` at slot 208, targeting `0x00273141`, and
`setCameraOffset(float)` at slot 228, targeting `0x00272abd`. Native Player Update
uses slot 208 with false; the old source called setCameraOffset with float zero.
Replacing only that call preserves the 2,216-byte extent and changes three raw
bytes: the slot immediate and boolean-argument instruction. All 84 other raw
definitions and all 945 frozen inputs remain unchanged. The fragment retains
both corrections and still receives no matching credit.

Vehicle Update uses two strict double comparisons against `0.3`, not `>= 1.2`.
Its material-node guard follows both the dead/light and nondead damage paths,
inside the existing non-death-water condition. Moving that guard to its common
join preserves a fresh health-ratio calculation after earlier callbacks. The
corrected function emits 3,924 bytes; its input section is 3,928 bytes because
four trailing assembler-alignment bytes lie outside the function symbol.
Independent object review preserves all 199 other raw definitions and all 1,065
frozen inputs. Its two real comparator relocations now name `__aeabi_dcmplt`.

The historical private fixture incorrectly labeled PLT `0x001c4244` as
`__aeabi_dcmpge`. Retail identifies that address as `__aeabi_dcmplt`; the real
`__aeabi_dcmpge` PLT is `0x001c4448`. Canonical linker files already use these
correct identities. No private binding was silently adopted or edited, and no
native linker ran for this control. Any eligible future link must review that
fixture error explicitly rather than substituting helpers to obtain a match.

## Preservation and reproduction limits

The coordinator independently inspected the NPC Update, NPC attack, vehicle AI,
Vehicle Update, cursor and Player objects, confirmed their extents and compared
old raw definitions with separately retained actual baselines. Workers also
checked allocated payloads, semantic relocations, imports and frozen inputs.
Compiler-run anonymous-name changes are disclosed and narrowly paired in
read-only audits; no object output was modified.

Physics and Character dependencies passed 152 function and 44 section/region
checks before each NPC control stopped. Those results do not prove the skipped
NPC owner checks. Vehicle, cursor and Player controls use their actual preserved
compile/assemble contexts. Older header/linked closures were not rerun. The
current-main 191-profile proof belongs to the accepted freeze source alone.

The published C++ files are function fragments with repository LF endings.
Their statements come from tested private translation units; they are not
standalone replacements or a canonical build configuration. Recover each full
source/header/profile context before another experiment. NPC model proposals,
event constructors and weak prerequisites must not be guessed or transferred
silently. Exact raw source, objects, commands, hashes and failed gates remain in
these local coordinator packets:

- `_scratch/worker-npc-update-common-downed-control`
- `_scratch/worker-npc-attack-retarget-else-control`
- `_scratch/worker-vehicle-ai-flags-adjusted-snapshot-control`
- `_scratch/worker-vehicle-update-damage-common-control`
- `_scratch/worker-renderfx-cursor-release-else-control`
- `_scratch/worker-player-update-carinteraction-else-control`

These corrections supersede earlier negative audits only for the demonstrated
paths. An incomplete decompiler or a general callback summary does not prove
equivalent control flow. Further attempts still require new evidence or an
explicit bounded escalation and authoritative full-byte verification.

## Rejected optimizer-policy probe

An unchanged-source dump diagnostic reproduced the corrected 3,924-byte Vehicle
Update before interpreting its passes. CFG cleanup at `143r.csa` first shares
the two glass visibility sites; `147r.bbro` then changes their block placement.
This supports one bounded `-fno-crossjumping` experiment, without establishing
which flags or intermediate representation retail used.

That whole-primary-unit flag control emits 4,008 bytes versus native 4,020, but
regresses five existing raw definitions: engine pitch, tire trails, the
transition callback, car factory getter and door state. Only 194/199 old raw
definitions and 221/226 old allocated payloads remain identical. Semantic
relocations also change. No native linker ran. The flag policy is rejected and
not integrated; the corrected 3,924-byte default-profile source stays preferred.
All failed gates, baselines and exact name-pairing evidence remain preserved.
