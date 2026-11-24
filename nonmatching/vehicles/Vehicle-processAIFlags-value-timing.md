# Vehicle AI: callback snapshots and real scalar lifetimes

The accompanying fragment preserves the tested **3192-byte unmatched**
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

The scalar reconstruction and subsequent even-first control each used one
original GCC 4.2.1 frontend and assembler pair, both successful. Object function and
input section are both 3192 bytes, alignment 8, without padding. The frame remains
476 bytes. Mapped executable bytes are 2972, pool bytes 220; native has 3000 and
220 respectively. The strict extent gate therefore fails by **28 executable
bytes**. This aggregate deficit is not attributed entirely to one branch or
event tail.

All 197 old functions, 225 nonempty off-target allocated payloads, definition
metadata, 294 import entries and 1446 off-target semantic relocations are
preserved. Compiler-generated anonymous identities differ: 23 section and 23
symbol names have an explicitly enumerated collision-free correspondence
`2D56FD8F` to `B254F827` for the scalar control and `B254F827` to `29BA2EC2`
for the even-first control. Whole-object identity is not claimed. No output was
rewritten. Source/object/raw target identities and the object gate summary are
recorded in the JSON.

No linker ran. The ordinary object checker exited 1 because the function still
has unresolved relocations; exact output:

```text
_ZN7Vehicle15_processAIFlagsEv has 160 relocation(s); the bytes cannot be compared until they are resolved:
  0x30, 0x7e, 0x118, 0x122, 0x12a, 0x134, 0x13c, 0x162, 0x16c, 0x176, 0x19e, 0x1a8, 0x1b0, 0x1ba, 0x1c2, 0x1c6
```

There is no resolved native-address match, current canonical/global build gate,
deleted assembly marker or progress credit. The fragment itself was not separately
compiled. Reproduction requires the actual paired 935-input fixture and original
options, including its existing stack-protector setting; another translation-unit
or header context is not the recorded experiment.

Private evidence resides in `_scratch/worker-vehicle-ai-used-scalars/` and
`_scratch/worker-vehicle-ai-even-first/`: original
commands, source-only patch, pinned input/tool manifest, complete preservation
inventories, raw metadata-name correspondence, target bytes/disassembly and
`SEQUENCE-PROOF.json`. Its report discloses two corrected analysis-only failures
(Python helper shadowing `inspect` and objdump runtime PATH); the compiler and
assembler were each invoked only once. The prior callback, scalar-dot and literal
branch packets remain separately retained.

The published fragment is the later even-first control. Inverting only the
random-sign condition and exchanging the existing branch bodies restores retail's
even/positive inline and odd/negative outlined layout. Exactly four raw target
bytes change; extent remains 3192. The JSON retains both control identities and
the complete four-byte delta. This local correction does not explain the remaining
28-byte deficit or establish a complete native match.
