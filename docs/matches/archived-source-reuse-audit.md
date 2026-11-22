# Reusing partial successes from archived source

The accepted [NPC freeze match](npc-freeze.md) came from combining readable
source pieces that independently produced exact branches in earlier variants.
The coordinator assigned separate follow-up audits to test whether that evidence
also exists for other parked functions. These audits do not reset attempt
budgets, permit instruction splicing or grant matching credit.

## Reviewed negative results

| Function | Actual retained evidence | Why no new source composition is justified |
| --- | --- | --- |
| VehicleCamera::goToSide, Thumb `0x003351dd`, 304 bytes | Six emitted definitions, three unique native-address payloads; real source/object/relocation associations retained | Every form reverses the same positive/negative GetRight return slots. An apparently exact block in the worse inverted variant belongs to the other semantic arm. Reusing it would reverse behavior. |
| Vehicle::dropSceneNode, Thumb `0x00309f0d`, 328 bytes | Eight linked images, five unique payloads; the best image has four differing bytes | Every source already has the exact prefix. Every final-clear form stores field844 before restoring SP, opposite retail. No donor supplies the missing scheduling result. The surviving unsuffixed object belongs to the older chained-store form, not the best image. |
| NPC::triggerCombatSFX, Thumb `0x002fe615`, 368 bytes | Four actual images; three have eight differing bytes and the reordered switch has twelve | Complementary sound-selection cases exist, but no image has the native register for sound58. The improved local case bodies are text-identical; only whole-switch order differs. There is no distinct local source piece to transplant. |
| NPC::SetTarget, Thumb `0x003009d1`, 320 bytes | Six archived source/log pairs, but only the final hinted object/image survives | Earlier attempts overwrote one output path. Logged scores cannot prove exact donor blocks or relocation provenance. No replay was performed merely to manufacture missing evidence. |

For each negative result the coordinator reviewed actual-artifact provenance,
retained the existing mismatch and released ownership. No function source,
compiler setting, assembly marker, generated progress or native output changed
because of these audits. Historical owner checks remain historical; they are
not promoted to current full-project verification.

## Candidate requiring a separate experiment

CarRental Notify (`0x002eb761`, 448 bytes) has a typed candidate with an exact
confirmation tail and an older 452-byte candidate with exact short index/table
fragments. Their distinct availability/flags/suffix source graphs support one
bounded combined lowering experiment. They do not provide compatible complete
loop blocks: both retain nonnative loop/stack register assignments. The audit
therefore proposes a testable hypothesis only; neither similarity nor these
partial fragments establish a match. Any accepted result still requires a new
full-function and section comparison, unchanged existing matches and coordinator
review.


The sole CarRental combined control was subsequently rejected: its emitted
function and physical section are both 452 bytes, versus native448. The strict
extent guard stopped before native linking, binding generation and GOT harness
work. No candidate ELF exists. The coordinator independently checked actual
baseline/candidate objects: all 252 other emitted functions retain their raw
bytes, and all 940 frozen inputs remain unchanged. The worker's semantic
relocation audit and 261 other allocated payload comparisons also pass. Linked
owner/dependency, GOT, suffix and target comparisons were skipped; their older
640-function/421-region results belong only to the archived baseline. No further
form or credit is authorized by this result.

The MenuManager setText follow-up also found no viable composition. Thirteen
actual artifacts reduce to three code classes; earlier forms supply no genuine
missing whole block. The only apparently useful fragment loads a different text
path and destination slot once its PC-relative literal is resolved. All 59 target
relocations were checked per artifact. No new compilation followed.
