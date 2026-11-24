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

The saved diagnostic contains issued cycles and an empty final ready list. It
does not print intermediate candidate priorities, comparator outcomes or the
complete dynamically built dependency graph. The precise deciding rank branch
is therefore unproven. Do not substitute load-latency or register-pressure
speculation for that missing evidence.

No omitted source operation, load width, alias relation, return ABI or callback
was found. Repeating pointer spellings, source statement order, scheduler flags,
barriers or artificial dependencies is not justified. Preserve the spent source
budget and park until genuinely new source/compiler evidence exists.

Detailed commands, source reversal, the failed original gate, continuation,
complete inventories and Help-only pass extracts remain under
`_scratch/worker-help-icon-neutral-plan/`. Policy evidence remains under
`_scratch/worker-help-scheduler-policy/`.
