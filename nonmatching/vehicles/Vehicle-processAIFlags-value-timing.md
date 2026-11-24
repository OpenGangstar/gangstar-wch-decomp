# Vehicle AI: callback snapshots and real scalar lifetimes

The accompanying fragment preserves the tested **3224-byte unmatched**
`Vehicle::_processAIFlags()` reconstruction, Thumb `0x00312081`, native
3220 bytes. It is a historical private-fixture method fragment, not a standalone
translation unit or an accepted current-source implementation. The older
`Vehicle-processAIFlags-reconstruction` packet remains a distinct 3168-byte
linked construction/cleanup control; its linked results do not apply to this
new object.

## Supported source findings

The original virtual `GetFront()` callback precedes the reads of
`init372/376/380` in the turn calculation. Binding its genuine by-value result
before those field reads preserves that observable boundary. The dot product
then uses the measured float grouping and operand order; a callback may alter
the fields, so the earlier pre-callback snapshot was not equivalent.

In initial lateral destination selection, both actual signs use addition for
both coordinates. Odd selects -200.0f; even selects +200.0f. This does not express
an assumed perpendicular-vector construction. Native captures target X/Y before
`GetFront`, front X/Y before the random call, and loads target Z late.
The fragment names those real scalar values, branch-local product X, result X
and product Y. Result X remains live through the second multiplication, followed
by the shared X store and Y addition. The emitted operand order and these
value/store boundaries now follow the measured retail sequence. No artificial
alias, volatile/barrier, register constraint, assembly or compiler-output edit
was used. No GCC dump measurement establishes the exact pass responsible for
this improvement.

## Actual verification and limits

The same native scalar structure also occurs in the pursuit lateral branch.
Its earlier dynamic offset shared four helper sites; retail has two constant
paths and a common Y addition, seven sites. Applying the verified genuine scalar
pattern there recovers native captures, operand order, X-result lifetime and
shared late X store. Static multiplication/addition counts now equal retail;
this does not prove every control edge or operand equal.

The initial scalar reconstruction, even-first control and pursuit reconstruction
each used one successful original GCC 4.2.1 frontend/assembler pair. Latest object
function and input section are both 3224 bytes, alignment 8, without padding.
The frame remains 476 bytes. Mapped executable bytes are 3004, pool bytes 220;
native has 3000 and 220 respectively. The strict extent gate fails: the actual
function is **four executable bytes longer**, not a native-sized function plus
padding. This is an aggregate extent difference, not a claim that only four bytes
of code differ. Relocation, layout and control-flow differences remain, including
shared event tails.

All 197 old functions, 225 nonempty off-target allocated payloads, definition
metadata, 294 import entries and 1446 off-target semantic relocations are
preserved. Compiler-generated anonymous identities differ: 23 section and 23
symbol names have an explicitly enumerated collision-free correspondence
`2D56FD8F` to `B254F827` for the scalar control and `B254F827` to `29BA2EC2`
for the even-first control, then `29BA2EC2` to `04723354` for pursuit.
Whole-object identity is not claimed. No output was
rewritten. Source/object/raw target identities and the object gate summary are
recorded in the JSON.

No linker ran. The ordinary object checker exited 1 because the function still
has unresolved relocations; exact output:

```text
_ZN7Vehicle15_processAIFlagsEv has 163 relocation(s); the bytes cannot be compared until they are resolved:
  0x30, 0x7e, 0x118, 0x122, 0x12a, 0x134, 0x13c, 0x162, 0x16c, 0x176, 0x19e, 0x1a8, 0x1b0, 0x1ba, 0x1c2, 0x1c6
```

There is no resolved native-address match, current canonical/global build gate,
deleted assembly marker or progress credit. The fragment itself was not separately
compiled. Reproduction requires the actual paired 935-input fixture and original
options, including its existing stack-protector setting; another translation-unit
or header context is not the recorded experiment.

Private evidence resides in `_scratch/worker-vehicle-ai-used-scalars/` and
`_scratch/worker-vehicle-ai-even-first/`: original
commands, source-only patches and pinned manifests. The latest pursuit packet is
`_scratch/worker-vehicle-ai-pursuit-scalars/`; its native proof and unapplied
proposal were reviewed in `_scratch/worker-vehicle-ai-residual3192/` before that
single compilation. They also retain complete preservation inventories, raw
metadata-name correspondence, target bytes/disassembly and `SEQUENCE-PROOF.json`.
The used-scalars report discloses two corrected analysis-only failures
(Python helper shadowing `inspect` and objdump runtime PATH); the compiler and
assembler were each invoked only once. The prior callback, scalar-dot and literal
branch packets remain separately retained.

The published fragment includes the later pursuit reconstruction. In the
preceding even-first control, inverting only the
random-sign condition and exchanging the existing branch bodies restores retail's
even/positive inline and odd/negative outlined layout. Exactly four raw target
bytes change; extent remains 3192. The JSON retains both control identities and
the complete four-byte delta. This local correction does not explain the
then-remaining 28-byte deficit or establish a complete native match. Pursuit then
adds 32 executable bytes; its separate identities and measured result are recorded
in the JSON. The previous controls remain immutable private packets.
