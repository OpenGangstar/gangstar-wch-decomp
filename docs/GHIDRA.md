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


A correct formal math signature does not guarantee correct physical storage.
The verified `sqrt(double)` import originally returned through `r1:r0` but
incorrectly took its argument from `Stack[0x0]:8`. Native callers pass the low
word in `r0` and high word in `r1`. Explicit custom storage for both the argument
and result fixes that analysis error. Ghidra represents this join as
`r1:4,r0:4`, with the most significant word first. Float-to-double and
double-to-float helpers require corresponding split-register storage. Read back
both the PLT thunk and its resolved external function; a displayed C prototype
alone is insufficient. These changes affect analysis metadata only.


## Returning calls in physics analysis

A correct callee prototype does not remove an existing instruction-level
`CALL_RETURN` override. Inspect the actual call instruction as well as its
resolved callee. The following retail-verified repairs restore normal returning
float operations and `operator delete`; no machine-code byte was changed.

| Retail function | Thumb entry | Complete executable bytes | Separate padding | Literal bytes |
| --- | --- | ---: | ---: | ---: |
| ContactFilter::ShouldCollide | 0x0031dc7d | 1,058 | 2 | 40 |
| PhysicAttributes::ComputeShortestPath | 0x00320ca1 | 1,620 | 0 | 48 |
| PhysicAttributes::FindLowerCostNode | 0x0031a40d | 184 | 0 | 8 |
| PhysicAttributes::GetTriCenter | 0x0031a4cd | 274 | 2 | 12 |
| PhysicAttributes::GetHeight(vector3df const&, int, bool) | 0x0031ff49 | 234 | 2 | 12 |

For `ShouldCollide`, four false float-call termination overrides hid 102 real
instruction bytes. Its complete instruction listing also includes a separate
two-byte alignment instruction, which is intentionally outside the function
body. For `ComputeShortestPath`, float-call repairs alone restored only 1,452
of 1,620 executable bytes. Three additional stale overrides on returning
`operator delete` calls at retail 0x003210ae, 0x00321154 and 0x003212ee blocked
reconstruction and cleanup. Removing those specific overrides restores every
one of its 751 native instruction entries. Decode only verified instructions;
the intervening literal pool is not executable code.

These functions also require explicit physical ABI views. The shortest-path
member returns void and receives `self`, index, mode and the source vector
carrier in `r0` through `r3`; destination vector carrier and final float occupy
incoming stack offsets zero and four. The source API still passes the two
nontrivial vectors by value. Analysis pointers represent their invisible
reference carriers and do not change that API.

`FindLowerCostNode` receives its 24-byte result buffer in `r0`, receiver in
`r1`, array in `r2` and index-output pointer in `r3`. `GetTriCenter` is static:
its 12-byte result buffer occupies `r0`, followed by material and triangle
carriers in `r1` and `r2`. Both return the result pointer in `r0`. The small
`GetHeight` member takes receiver, position reference, signed slot and bool in
`r0` through `r3`, returning a float through `r0`. These are analysis storage
models; no extra automatic hidden parameter may be inserted.

A complete repaired CFG is evidence for analysis, not a matching claim. Source
candidates remain pending until compilation and the authoritative exact-byte
checker succeed.


The same returning-call check also restored complete real code for
`GS3DStuff::checkPickableProximity` (330 bytes),
`MenuManager::_positionMapOnPoint` (288 bytes), `updateMarkers` (338 bytes),
and `ContactListener::Persist` (578 bytes). Their retail extents additionally
include alignment and literal pools. Native instruction ownership was checked
separately from those non-executable bytes. `GSFailure::draw2d` already had its
complete 292-byte code body but omitted its receiver in the inferred prototype;
its explicit physical view now takes receiver and callback state in `r0` and
`r1` and returns void.

Menu callers exposed further untyped imports: `__aeabi_i2d`, `__aeabi_dsub`
and `__aeabi_d2iz`. Their explicit models use `r1:r0` for the low/high double
pair and `r3:r2` for the second double argument to subtraction. Signed integer
input and output use `r0`. Readback verifies both each PLT thunk and its
resolved target. `StateMachine::getTimeStamp` returns the double pair;
`PlayerTest::getAmbientSound` returns a signed integer in `r0`.

`SoundManager::playEx` needs nine physical values, including its receiver.
Receiver, sound ID, position pointer and first bool occupy `r0` through `r3`;
float, integer, bool, float and callback follow at incoming stack offsets zero,
four, eight, twelve and sixteen. The bool occupies one byte within its ABI
slot. Its result is an integer in `r0`. Omitting the receiver shifts every
argument and produces misleading inferred float and callback values. Existing
source declarations and literals already agree with retail and remain
unchanged by these analysis repairs.


Subsequent restricted repairs restore `ContactListener::Add` to its complete
2,298 executable bytes (1,053 owned instructions, two bytes of separate
padding and 84 literal bytes within the 2,384-byte retail extent),
`MenuManager::tearDown` to 284 executable bytes, and `_zoomMap` to 546.
Each repair removes only inspected false returning-call termination overrides
and preserves ordinary game calls. No internal long-branch overrides were
needed in these functions. Complete native instruction coverage supports the
analysis; it does not reopen an exhausted source budget by itself.

`MenuManager::_drawMap` subsequently expands from 226 to 390 executable bytes
after removing its inspected false float-call termination. `AddCollisionShapes`
expands from 286 to 1,726 executable bytes after four such repairs and correcting
two verified Thumb instructions previously decoded as ARM. Its 781 real native
instructions are all owned; a separate padding instruction and 88 literal bytes
complete the 1,816-byte retail extent. Its physical view uses receiver in `r0`,
signed slot in `r1`, unsigned-short vertex in `r2:2` and a void result.


## World flow and verified computed switches

Restricted repairs restore `LevelObject::CastRay` to 1,418 executable bytes
and `canGoToPoint` to 3,022. Their explicit physical views include the receiver;
CastRay has three additional stack slots for its two remaining outputs and bool.
Both return a bool in the low byte of `r0`. Only the two native long BLs at
0x00318a76 and 0x00318a86 are classified as internal branches to 0x00318226;
ordinary calls remain calls. Retail has no function entry at that target and
the project had no separate function boundary to remove. Native byte/width and
ownership audits account separately for alignment and literal pools.

The same pass restores MenuManager updateMap and initMap to their complete
372-byte and 400-byte executable bodies. Setup already had its complete
1,682-byte body; its physical view now includes receiver and unused bool.
These repairs change analysis metadata only.

MenuManager setText owns its instructions but requires a computed-switch
override. The 17 signed-relative entries at retail 0x004191e4 derive the exact
targets for `mov pc,r3` at 0x002e5436. Function and table hashes were verified
before and after the update; no memory byte changed. The recovered decompilation
contains all 17 cases and deliberately warns that the switch is overridden.
Ghidra 12 adds a display-format argument: its shipped SwitchOverride script uses
`JumpTable(address, destinations, true, 0)`. The first old-API attempt rolled
back safely; the installed source verified the corrected constructor before retry.


## Large AI and vehicle functions

Complete native branch analysis exposed additional truncated bodies. Restricted
metadata repairs, followed by independent worker readback, restore these real
instruction ranges:

| Function | Original real code | Real instructions | Previous owned body |
| --- | ---: | ---: | ---: |
| NPC::Update | 2,850 bytes | 1,320 | 84 bytes |
| Vehicle::UpdatePhysic | 8,848 bytes | 3,799 | 76 bytes |
| ServiceCarRental::Update | 778 bytes | 358 | 476 bytes |
| VehicleCamera::goToSide | 300 bytes | 133 | 112 bytes |
| VehicleCamera::update | 900 bytes | 387 | 90 bytes |

Their retail extents additionally contain alignment and literal pools. Every
real instruction is independently checked for native bytes, width and function
ownership. Physics pagination covers 2,000 plus 1,799 instructions; the first
page alone is not a completeness result. Alignment remains separately recorded.

NPC Update has 13 proven internal Thumb BLs and vehicle physics has 118. Each
target is an interior block of the same original retail function, retains its
outer frame and has no separate retail function symbol. Only these verified
edges receive BRANCH overrides. Automatic interior function boundaries are
removed only after checking their names and that every incoming reference comes
from the verified native instruction set. Ordinary external calls remain calls.

The same repair removes inspected false CALL_RETURN overrides on established
returning math/delete helpers and the already verified small GetHeight method.
Fixing a callee's no-return property alone can leave a stale caller override.
The first batch rolled back because NPC Update still stopped at its GetHeight
call; removing that actual caller override allowed complete ownership. Wrong ARM
instructions were cleared only within independently verified Thumb instruction
spans. All five complete function-memory hashes remain unchanged.

Explicit physical views retain receiver in r0 and argument in r1: signed elapsed
for NPC Update, float elapsed for physics/camera update and bool for camera side.
CarRental Update takes only its receiver. All return void. Live getters verify
signatures and complete decompilation; register-storage and auto-parameter flags
are separately verified in the saved project export where the public RPC does
not expose them. These metadata repairs confer no matching credit or new source
attempt budget.

NPC triggerCombatSFX also required a computed switch. Its seven signed entries
at retail 0x0041d8fc are added to that table base, producing the original targets
for mov pc,r3 at 0x002fe66c. Independent readback verifies all 157 instructions
and 330 real bytes, the complete 28-byte table and all seven decompiled cases.
The explicit view is static void with event type in r0 and no receiver. Complete
function and table hashes are unchanged; the existing source remains unmatched.
