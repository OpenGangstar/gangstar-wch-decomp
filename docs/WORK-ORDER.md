# Reuse-first matching workflow

On 2026-10-29 the maintainer replaced the strict smallest-area-to-100% schedule
with a workflow based on OpenRAC's
[family selection](https://github.com/OpenRAC/rac1-decomp/blob/main/docs/AGENT_WORKFLOW.md#picking-functions-family-order)
and [bounded worker attempts](https://github.com/OpenRAC/rac1-decomp/blob/main/docs/QUEUE.md).
Select work for the matched bytes and reusable knowledge it can unlock. Work may
cross gameplay areas. The full objective is still all 4,661 game functions,
575,264 retail code bytes, matched byte for byte; vendored dependencies stay
outside that budget. No verification rule is relaxed.

## Selection priorities

1. **Tools and existing evidence first.** Look for exact candidates that were
   never integrated, identical implementations, and variants of existing
   matches. Reuse their source and normal build configuration. Similarity or a
   masked comparison is a candidate filter, never proof of a match.
2. **Matched relatives.** Prefer functions with a matched sibling, variant or
   corresponding implementation. Compare their instructions, interfaces and
   layouts before adapting the source; names alone do not establish a family.
3. **Unlock families.** For an unmatched family, start with its smallest useful
   representative. Prefer families with more pending relatives, so one solution
   supplies a starting point for several others.
4. **Fresh shared helpers and small functions.** Prefer common helpers and
   functions in translation units whose types, imports and build configuration
   are already established. Use size as a tie-breaker, not an area gate.
5. **Long functions and near misses.** Give long routines a bounded dedicated
   pass when most of their callees and interfaces are understood. Revisit saved
   near misses with new evidence or an explicit escalation budget. Keep known
   toolchain or catalogue problems out of the ordinary matching queue until
   their prerequisites are addressed.

## Running a batch

- Prepare a short batch of candidates in priority order. For each candidate,
  gather its retail assembly, called symbols, relevant types and closest
  matched source before the first compile. Use `config/functions.tsv` and
  the existing assembly files as the queue.
- After a representative matches, check its remaining relatives for source
  reuse before starting another family. Verify each candidate against its own
  retail bytes. Re-rank after the family lands so newly matched source and
  recovered types feed directly into the next batch.
- Record attempts, exact matches and matched bytes for each batch. Include
  time spent preparing or integrating candidates so the next batch can be
  chosen using actual throughput.

## Attempt limits and handoff

- Default first pass: six candidate compile/compare iterations per function.
- Stop earlier if three materially different source forms produce identical
  function bytes. Diagnose the unchanged instructions and record the result.
- Keep the best source/header pair, reproduction command, compiler flags,
  exact comparison output and remaining differences. A near miss earns no
  matching credit; its assembly remains in the queue.
- Park a stalled function and take the next ranked candidate. Return when a
  matched relative, corrected type or prototype, compiler finding, or other
  concrete new evidence changes the next experiment. A longer escalation must
  have an explicit bound and a specific hypothesis.
- Environment failures need separate repair; do not conceal them as failed
  source hypotheses or claim stale output as a match.

These are work-selection limits, not a reduced completion target. A parked
function is still required for 100%. Human authorization is still required
before starting a wave of agents, as specified in AGENTS.md.

## Current stalled combat work

The saved BulletTraceManager::OnAnimate and Rocket::launch candidates remain
unmatched. Their diagnostics and reproduction paths are documented under
docs/matches/ and nonmatching/combat/. Preserve them while advancing the
reuse queue. Do not restart their exhausted source-order searches without new
evidence. Historical area-order statements in old match notes are not queue
instructions.
