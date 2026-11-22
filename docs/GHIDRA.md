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
