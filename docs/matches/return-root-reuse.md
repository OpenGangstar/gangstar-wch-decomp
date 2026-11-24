# Reusing return-root findings

The [FSelect match](fselect.md) supplies a measured compiler mechanism, not a
general instruction to rewrite every return. A genuine user-named result prevented
GCC 4.2.1 from coalescing an ignored floating return temporary into a live input
parameter. Its complete 32-byte function and affected old matches were verified.
No source rewrite earns credit without the normal exact-byte checks.

## Establish applicability first

Compare the actual candidate and retail return transfers, then inspect existing
paired compiler traces. Distinguish source declarations, SSA partitions, generated
temporaries and final hard-register reuse. A shared register does not prove a
tree-level declaration merge. A different register does not by itself identify a
source defect. Use actual `Try`/`Coalesced` records and the first responsible pass
when that causal claim matters.

An unchanged-source diagnostic must preserve function/data payloads, metadata and
semantic relocations before its dumps are interpreted. Enumerate any generated
anonymous-name correspondence explicitly; do not rewrite emitted output or claim
raw whole-object identity when it differs. Retained dumps from a different source
candidate are not evidence for the current one.

## Reviewed cases

These are findings for the identified retained candidates, not proof that no
future evidence could justify revisiting a function. All unmatched functions
remain in the queue; previous source budgets remain spent.

| Function / Thumb address | Observed mechanism | Reuse decision |
| --- | --- | --- |
| FSelect / `0x00349315` | First copyrename merged an ignored float return into the positive input. A real named result blocks the two-user-root merge and produces exact native bytes. | Verified success, already integrated. |
| NPC::attackTarget / `0x002ff5d1` | Bool users remain separate. PRE creates an integer return-conversion PHI; copyrename3 merges the generated return carrier into that generated root. Later CSE/allocation explains R5. | Direct FSelect user-root analogy refuted for the 2108-byte candidate; no rewrite follows. |
| ASprite::GetAnimDuration / `0x00349d81` | Candidate already has named `duration` and one final return. First mismatch is a signed field load selected after TER, not parameter/return-root merging. | Do not add another named output or repeat exhausted load forms. |
| GS3DStuff::checkForDespawn / `0x002dd0c1` | Both native and candidate retain object in R7, assign the despawn result into it and use the common R0-from-R7 return. | The supposedly unwanted merge is native behavior here. |
| Widgets::Mission::OnEvent / `0x002ed215` | Void return; the six remaining operand bytes exchange PIC/event registers. | No returned value exists to protect. Guard/pointer/API forms already repeat identical output. |

The NPC diagnostic's original/gimple signature remains `bool`. Observed integer
lowering and SI result registers do not establish a source `int` return type.
The known original caller ignores R0, and ordinary member mangling omits return
types; neither justifies changing the signature.

## Retained evidence and limits

The authoritative successful comparison is in `fselect.md`. The unmatched NPC
source and failed link are preserved in
[NPC attack notes](../../nonmatching/ai/NPC-attackTarget-flat-control.md).
Detailed local diagnostic packets are retained under `_scratch/`:

- `worker-fselect-cold-return-origin/` and `worker-fselect-named-result-control/`.
- `worker-npc-attack-return-origin/RETURN-TRACE-REPORT.md` and its original dump
  line-evidence index.
- `worker-asprite-duration-return-root-review/REPORT.md`.
- `worker-gs3d-despawn-return-root-review/REPORT.md`.
- `worker-widget-mission-event-opportunity-review/REPORT.md`.

These follow-up reviews add no matching or Fully Linked credit. They prevent
repeating disproved hypotheses while preserving evidence needed for a genuinely
new experiment. Read the ownership registry before taking any target.
