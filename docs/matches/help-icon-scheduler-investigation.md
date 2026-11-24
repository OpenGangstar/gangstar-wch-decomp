# Help icon wrapper: unmatched scheduling investigation

`Widgets::Help::SetIcon(char const*)`, retail Thumb `0x002ecb01`, remains
unmatched at 32 bytes. Its assembly marker stays in place. No canonical function,
header, matching profile or progress value changed.

The three historical source forms already reached the identical-output stopping
rule. This investigation adds no source form. It measures this function's own
compiler pipeline, rather than assuming the cause from the related Achievement
and IGMenu wrappers.

## Controlled diagnostic

No authenticated historical Help object survived in the recovered package.
Consequently three explicitly approved frontend/assembler pairs were used:

1. Unchanged current owning MenuWidget translation unit.
2. The same unit with only the retained Help body, its nonvirtual declaration
   and the 16-byte `widgetHelp.icon` literal added privately.
3. That exact Help source with tree/RTL dump options added, keeping all ordinary
   code-generation flags and relative input/output paths unchanged.

All six commands exited 0. No linker ran. The first execution stopped during
analysis after the two normal pairs: the script guessed a mangled local literal
name, whereas this compiler emits local object `helpIconPath`. The coordinator
independently checked the actual symbol, section and payload. A separately
preserved continuation validated those artifacts and executed only the remaining
neutral pair. Neither normal pair was repeated and no failure was hidden.

All 179 old emitted function payloads, 339 allocated payloads/metadata, 111
imports and 1132 semantic references remain raw-identical. No generated-name
correspondence is needed. Actual target and input section are both 32 bytes.
Baseline and neutral **whole object and assembly** are byte-identical:

| Artifact | SHA-256 |
| --- | --- |
| Object | `4054b3c894f63507370962b39fedcc12578c17e696392bcebbb99ff50f9e9a62` |
| Assembly | `106768b55b30a4996e896daf08d723438342a2888efd49b8445605b5c46ab873` |

All 906 original pins and 22 retained execution artifacts remain stable.
These object-preservation counts do not represent new native matches. No linked
function, full-section, GOT, caller or global acceptance check was run.

## Measured cause and policy limits

The explicit receiver snapshot reaches RTL expansion before the argument moves.
From `104r.expand` through `147r.bbro`, receiver-load instruction 9 precedes path
move 17, false move 19 and call 20. Allocation coalesces the receiver into R0
without reversing that order. **149r.sched2 first reverses it**, issuing path
move at cycle 5, false move at 6, receiver load at 7 and call at 8. Native instead
places the receiver load before those two argument moves.

The inspected immutable GCC 4.2.1 source supplies two useful constraints:

- ARM's `arm_adjust_cost` gives a true producer-to-call dependency cost 1.
  A default XScale load latency of 3 therefore does not require a three-cycle
  gap from this receiver load to the call.
- The direct register-pressure comparator in `rank_for_schedule` is disabled
  after reload. It cannot directly explain this postreload ranking choice.

Primary source:
[ARM scheduling costs](https://github.com/gcc-mirror/gcc/blob/0d5acec7b636b19aac6ed7517a1dea8fb9f6b0dc/gcc/config/arm/arm.c),
[scheduler ranking](https://github.com/gcc-mirror/gcc/blob/0d5acec7b636b19aac6ed7517a1dea8fb9f6b0dc/gcc/haifa-sched.c).
The release tag/commit and fetched-file hashes are retained in the local primary
provenance receipt. They identify upstream policy, not the proprietary compiler
fork's complete source.

The initial diagnostic contains issued cycles and an empty final ready list.
It does not print intermediate priorities or dependency candidates, so that
packet alone could not establish the deciding rank branch. The separately
reviewed measurement below supplies the missing state.

## Exact neutral higher-verbosity measurement

One additional unchanged-source frontend/assembler pair added only
`-fsched-verbose=7` to the existing diagnostic options. Both commands exited 0.
The complete object and assembly again match the hashes above, with all 180
emitted definitions, 341 allocated sections, 111 imports and 1135 references
identical, including Help and its literal. All 1925 original pins and 891 fresh
copied files stayed stable. No generated-name correspondence, linker or source
change was used. This is a neutral diagnostic, not a native match.

The measured candidates have equal scheduling priority 65:

| UID | Instruction role | Forward successors |
| --- | --- | --- |
| 9 | Load receiver into R0 | 35, 20 |
| 17 | Move path into R1 | 36, 35, 20 |
| 19 | Set false argument in R3 | 36, 35, 20 |

Receiver 9 is ready from cycle 0. At cycle 5 the sorted ready list is
`34 19 9 17`, printed lowest to highest priority; 17 issues. At cycle 6 the
list is `34 9 19`; 19 issues. Receiver 9 then issues at cycle 7.

The recorded priorities, groups, block identity, last-issued relationships and
ready-list semantics establish the first nonzero comparison in the pinned
upstream ranking implementation: **three forward dependents beat two**. Direct
register pressure is disabled after reload, and critical-path priorities are
equal. Original-order fallback is never reached. This reconstructs the deciding
rule from measured inputs; GCC does not directly print comparator-return traces.

UID 35 is the compiler's restored-R4 lifetime clobber; UID 36 is its volatile
epilogue marker. Dependency construction retains prior R1/R3 set histories for
the epilogue, while the call's explicit R0 result supersedes the receiver's
previous R0 definition. These are conservative compiler histories, not genuine
argument-value uses after the call. Edge kinds are derived from primary rules
and actual RTL; successor membership and counts are printed directly.

Additional primary references:
[Thumb epilogue construction](https://github.com/gcc-mirror/gcc/blob/0d5acec7b636b19aac6ed7517a1dea8fb9f6b0dc/gcc/config/arm/arm.c#L13861),
[dependency histories](https://github.com/gcc-mirror/gcc/blob/0d5acec7b636b19aac6ed7517a1dea8fb9f6b0dc/gcc/sched-deps.c#L1250).
The installed compiler's complete source remains unproven. No incorrect return
ABI or missing source operation follows from this scheduler explanation.

A read-only trace-parser newline error was corrected without rerunning the
compiler or changing outputs. The complete trace, policy reconstruction and raw
identity evidence remain in `_scratch/worker-help-scheduler-verbosity-plan/`.

## Rejected Thumb epilogue-option control

Primary Thumb prologue/epilogue construction tests `TARGET_SCHED_PROLOG`.
Consequently one separately approved unchanged-source control added only
`-mno-sched-prolog` to the authenticated verbose diagnostic. This inserts
compiler-generated scheduling markers; no source barrier was written.

The sole frontend/assembler pair exited 0. Help remains function/input 32/32,
with the identical raw target hash
`b8e1ffaef7479ac82121ced4eefeb838b695107dc7f2f939cdf47f95eba0a9fc`.
The new barrier receives the extra argument-history edges instead of eliminating
their count advantage. All three priorities become 97, but argument moves still
precede the receiver. The same six native instruction bytes remain wrong.

The option also changes 100 existing function payloads. Definition, allocated
section, import and reference counts remain 180/341/111/1135; stable counts do
not excuse the real regressions. Adoption is rejected. No linker, production
profile change, per-function exception, source refinement or credit follows.
Full raw failures and controlled inputs remain in
`_scratch/worker-help-no-sched-prolog-feasibility/`.

No omitted source operation, load width, alias relation, return ABI or callback
was found. Repeating pointer spellings, source statement order, barriers or
artificial dependencies is not justified. Any compiler-option control needs a
specific primary-supported hypothesis and separate coordinator approval;
production flags remain unchanged. Preserve the spent source budget.

Detailed commands, source reversal, the failed original gate, continuation,
complete inventories and Help-only pass extracts remain under
`_scratch/worker-help-icon-neutral-plan/`. Policy evidence remains under
`_scratch/worker-help-scheduler-policy/`.
