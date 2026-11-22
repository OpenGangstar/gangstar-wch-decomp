# Ghidra analysis and MCP

Ghidra supports investigation; the retail ARM disassembly and exact-byte checker
remain authoritative. Decompiled C, inferred signatures, function extents and
cross-references can be incomplete or wrong. Analysis repairs do not earn matching
credit or change catalogue status.

## Verified local configuration

The investigated configuration is Ghidra 12.1.4, GhidraMCP 2.0.0, Python 3.12
with PyGhidra and JDK 21. Keep installations, imported libraries, projects and
analysis exports outside Git. Verify the imported library against the SHA-256
in `tools/project.py` before using its results.

The isolated corrected project uses `ARM:LE:32:v5t` with the default compiler
specification, `ARM_v45.cspec`. Its `__stdcall` model passes float arguments
through general registers. In contrast, the automatically selected ARMv8
default specification can use VFP registers. Do not transfer a convention name
between specifications without checking its actual argument/return storage.

For this import, Ghidra rebases addresses by `0x10000`. Remove the Thumb marker
from a catalogue address, then add the rebase to obtain the instruction address
in Ghidra. Verify the image base for each project rather than assuming this
offset universally.

GhidraMCP can serve an existing project on loopback with `--headless`,
`--no-analyze`, `--transport streamable-http`, `--mcp-host 127.0.0.1` and an
explicit `--mcp-port`. Use `--no-analyze` when reopening a repaired project:
automatic analysis was observed to reintroduce incorrect no-return metadata.
Do not open the same writable project simultaneously from multiple processes.
The coordinator owns shared analysis metadata; workers collect evidence.

## False no-return calls and missing Thumb continuations

Automatic analysis marked the imported `__aeabi_fadd`, `__aeabi_fsub` and scalar
`operator delete` as non-returning. Native callers prove returning continuations.
The analyzer also left `CALL_RETURN` instruction overrides and missing Thumb
context after affected calls. Correcting a callee signature alone did not repair
these callers.

The verified repair sequence, restricted to an owned function, is:

1. Prove the callee returns from original caller control flow and register use.
   Physical adjacency alone is insufficient: string append's fatal throw path
   is bypassed by the normal branch and must remain non-returning.
2. In a Ghidra transaction, clear the proven false flag with
   `Function.setNoReturn(false)`. For a thunk, inspect its actual external target.
3. Remove only the affected call's `FlowOverride.CALL_RETURN`, using
   `FlowOverride.NONE`.
4. Decode from the next undefined continuation with
   `ArmDisassembleCommand(nextAddress, restrictedRegion, true)`. The final
   argument selects Thumb mode. Starting at an already defined entry may decode
   nothing. Restrict traversal to the known native extent and exclude adjacent
   functions, alignment and literal data from instruction claims.
5. Recompute the actual function with
   `CreateFunctionCmd.fixupFunctionBody(program, function, monitor)`.
6. Inspect `getDisassembledAddressSet()`, the resulting listing and function
   body. A successful command return alone does not prove instructions decoded.
   Compare every exported instruction byte to the original ELF and review the
   corrected CFG before drawing source-level conclusions.

Full reanalysis changed previously false no-return flags back to true in the
isolated project. Inspect flags and call overrides after analysis, not only
before it. The verified examples restored 76 instruction bytes plus a separate
4-byte literal for `PlayPolicy_Loop`, 122 instruction bytes for
`PhysicAttributes::IsPositionOnJump`, all 172 bytes of
`NPC::isOutsideSearchRadius`, and all 142 bytes of `MenuFX::GetStateHandler`.
These repairs confirmed existing candidate semantics; they produced no new
byte-matched function.

## Prototype limitations

GhidraMCP 2.0.0's prototype parser does not accept a calling-convention token in
the tested declaration form. Applying a signature also does not clear an
existing no-return flag. Use the relevant Ghidra APIs separately when needed,
then read back both metadata and variable storage. For the verified float
helpers, two float arguments occupy `r0:4` and `r1:4`; the float result occupies
`r0:4`. Decompiler casts or an inferred `undefined4` return do not establish the
original C++ types.

API behavior above was checked against the installed Ghidra source archives,
scripts and actual project readback. Preserve negative source candidates and
their attempt budgets when an analysis repair reveals no new source constraint.


## Incorrect ARM decoding inside Thumb functions

A missing Thumb continuation can leave existing ARM instructions in the middle
of an otherwise correct Thumb function. Restoring the return edge alone does
not replace these definitions. In the verified large-function repairs, the
native listing exposed 30 incorrect ARM definitions across two functions.

Construct an instruction whitelist from authoritative retail disassembly,
excluding literal pools. Verify each instruction encoding against both the
original ELF and imported program before changing analysis metadata. Clear only
incorrect code units whose entire span lies inside verified instruction bytes.
Set `TMode` to one only over the newly undefined instruction spans, then use
`ArmDisassembleCommand` with the whitelist as its restricted address set.
Setting context across existing instructions can raise
`ContextChangeException`; do not suppress that error or extend the repair into
adjacent data. Recompute the function body and verify every resulting instruction
encoding and width again.

This restored all 800 listed MiniMap offset instructions, 2,171 large height-query
instructions and 782 random-position instructions: 8,448 instruction bytes,
including ten alignment bytes. These are analysis repairs, not matched code.

## Internal Thumb BL instructions can be long branches

GCC 4.2.1 can encode a jump between distant blocks using Thumb `BL`. Do not
classify every such instruction as a source call. Establish its role from native
control flow, use of the current stack frame, lack of a separate callee prologue,
a shared parent epilogue and corresponding compiler local-label evidence.
Actual recursive calls must retain call semantics.

For the large `PhysicAttributes::GetHeight` routine at retail Thumb
`0x0031eb99`, twelve internal long branches required `FlowOverride.BRANCH`;
three genuine calls back to the function entry remained calls. Four overrides
recovered 34 previously unowned executable bytes. The other eight were also
necessary for an accurate CFG even though their destination blocks already
belonged to the function. Function ownership alone does not prove correct flow.
After fixup, all 4,890 executable bytes belong to the function; only three
two-byte alignment instructions remain outside its body.

## Explicit physical ABI views

Inferred method prototypes can omit both the hidden result pointer and the
receiver. For MiniMap's offset calculation, caller and callee instructions prove
an output pointer in `r0`, receiver in `r1`, position pointer in `r2`, rectangle
pointer in `r3`, and bool arguments in incoming stack slots zero and four. The
output pointer returns in `r0`. The nominal C++ coordinate return class remains
unproven.

Use an explicitly labelled analysis-only view when the physical ABI is known
but the source return type is not. The verified update uses
`Function.updateFunction` with `CUSTOM_STORAGE`, six explicit `ParameterImpl`
objects and a `ReturnParameterImpl`. Pointer storage is four bytes in `r0` through
`r3`; each bool occupies one byte at its four-byte-spaced stack slot. This avoids
an additional inferred hidden parameter. It does not assert that the original
source function returned an `int*`.

Enumerate the actual program's compiler conventions before applying a name. The
corrected ARMv5t/default project reports `__stdcall` and `__thiscall`; its default
`__stdcall` supplies the soft-float GPR convention. A similarly named model from
a different installed compiler specification is not interchangeable. Read back
the complete parameter and return storage after updating it.
