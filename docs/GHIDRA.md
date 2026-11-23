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

Further independent readbacks verify these additional complete bodies:

| Function | Real instruction bytes | Real instructions |
| --- | ---: | ---: |
| Vehicle::_processAIFlags | 3,000 | 1,345 |
| RenderFX::UpdateCursor | 1,962 | 916 |
| PlayerTest::Update | 2,108 | 963 |
| Vehicle::Update | 3,744 | 1,633 |
| PlayerTest::move | 2,342 | 1,040 |

Vehicle AI needs six proven internal BL overrides; Player Update needs one and
Vehicle Update needs 48. Cursor and Player movement need none. Conditional
targets can also reveal automatic interior function boundaries, so examining
only long-BL destinations is insufficient. Boundary removal still requires a
native instruction entry, no retail function symbol and incoming references
entirely within the verified original function. All real external calls retain
their original call semantics.

Cursor's explicit physical view includes self, cursor reference and signed index
in r0/r1/r2. Player movement includes self and two floats in those registers.
Player Update and vehicle AI take only self; Vehicle Update also takes signed
elapsed time in r1. All return void. Independent readback separates complete
code from literal pools and alignment rather than counting instruction-looking
padding as executable coverage.

A coordinator audit compares the complete original-function memory hashes for
all ten repaired bodies against retail, including their data and padding. All
ten agree, with 186 individually proven internal branches restored in total.
These are analysis improvements only. The resulting native/source guard
corrections remain [unmatched candidates](matches/guard-association-corrections.md)
until their compiled functions pass authoritative byte comparison.

Vehicle::CreateWheels required no internal BL overrides. One actual false
CALL_RETURN on the normal fadd call at program 0x0031d20a prevented its
continuation; three later instructions were incorrectly decoded as ARM.
Guarded metadata repair restores 598 real instructions / 1,338 code bytes.
The original assembly's 599th instruction-looking entry is an unreachable
two-byte alignment halfword at retail 0x0030d546. Together with 68 literal
bytes, these account for the complete 1,408-byte retail function extent.

Fresh independent MCP readback verifies all 527 two-byte and 71 four-byte
instructions, zero real holes, and the complete decompiled body. Physical ABI
is void with self in r0 and Box2DUserInfo in r1, both explicit nonautomatic
parameters. Public getters confirm the two-formal signature; custom storage
is verified separately in the saved project export. Full function memory
remains identical to retail, SHA-256
`3a99c436cec6deda048e31f44e79fdf6ef36d8660a7f91ec56770415fdcc8c5a`.
The completed source-tail audit finds no new discrepancy in the preserved
1,440-byte candidate. No compiler attempt or matching credit follows from
this analysis repair.

Three animation functions also needed computed-switch metadata despite complete
instruction ownership. Each native mov pc,r3 dispatch used a verified signed
relative table. The saved jump table and branch flow model restore all cases:

| Function | Real instructions | Real code bytes | Table entries | Unique targets |
| --- | ---: | ---: | ---: | ---: |
| Character::switchMoveAnimation | 548 | 1,154 | 206 | 23 |
| Character::switchCombatAnimation | 505 | 1,050 | 125 | 26 |
| PlayerTest::switchAnim | 491 | 1,028 | 213 | 12 |

The combat index is unsigned(animation - 51), so its 125 indices represent
animation values 51 through 175. Decompiler case labels initially contain
physical destination addresses; independent readback maps those destinations
back to actual table indices and animation values before reviewing source.
All instructions, widths and destinations agree with retail. Whole original
function and table memories remain unchanged. Physical signatures use explicit
self in r0; the Character methods return bool in r0 and Player switchAnim
returns void. No implicit duplicate receiver is introduced.

Complete move-animation cases reveal no new source constraint. Combat and
Player cases expose [unmatched source corrections](matches/animation-operand-corrections.md)
for a shared ready tail, an eject Boolean and a lock-state byte. Restored
analysis metadata itself adds no byte-matching or Fully Linked progress.

Additional guarded normal-return repairs and independent fresh readbacks cover:

| Function | Real instructions | Real code bytes | Other original bytes |
| --- | ---: | ---: | --- |
| Character::punch | 344 | 734 | 2 padding, 40 literals |
| Character::punched | 400 | 844 | 40 literals |
| Character::updateAnimation | 383 | 874 | 2 padding, 16 literals |
| Character::show | 252 | 544 | 56 literals |
| Character::initInVehicle | 186 | 404 | 52 literals |
| Character::positionInVehicle | 268 | 588 | 52 literals |
| PlayerTest::switchContext | 393 | 862 | 2 padding, 36 literals |

Punch needs one actual false fadd CALL_RETURN cleared; animation update needs
two fadd and one fsub override cleared. Show and vehicle positioning each need
two fadd continuations, while vehicle initialization needs one. All are
original returning math calls. No global callee flags, original calls, memory,
function boundaries or internal BL flow are changed for these repairs. An
initial animation-update transaction rolls back when a second hidden false
return still blocks ownership; the later guarded pass removes only the actual
verified math overrides and passes complete ownership validation.

Punched uses a verified 55-entry, six-target computed table indexed by unsigned
(animation - 90). Its physical signature is void(self, animation, damage,
attacker), explicitly in r0/r1/r2/r3. Punch returns bool; animation update returns
bool and takes elapsed float in r1. Show is void(self); vehicle initialization
and positioning are void with vehicle pointer and bool respectively in r1.

Context switching already owns all real instructions, yet its decompiler
incorrectly ends the nonnull body-data path after operator delete. An actual
CALL_RETURN at program 0x00311b60 causes that error. Clearing only that override
restores the original common continuation at 0x00311b64. The explicit view is
void(self, context word, force bool), in r0/r1/r2. Independent full 900-byte
memory verification and fresh decompilation confirm both delete paths join the
common body. Its [node-index source correction](../nonmatching/ai/PlayerTest-switchContext.md)
is still unmatched.

Every listed original instruction encoding and width is independently exact.
Whole original function memory, including all excluded padding and pools,
remains retail-identical. Complete analysis does not prove candidate identity:
these source candidates retain their assembly markers and matching budgets.

## Independent ready, target-selection and state readback

Fresh independent MCP readback also verifies the following original function
memories and real instruction listings against the retail ELF:

| Function | Thumb entry | Real instructions | Code bytes | Other original bytes |
| --- | --- | ---: | ---: | --- |
| Character::ready(float) | 0x002f26ad | 133 | 272 | 12 literals |
| PlayerTest::getAttackableTarget | 0x00303315 | 298 | 662 | 2 padding, 36 literals |
| ScriptManager::setState | 0x0033f1ed | 312 | 698 | 2 padding, 32 literals |
| PlayerTest::updateAnim(float) | 0x00303fe9 | 54 | 120 | 12 literals |
| Character::shoot(float, bool) | 0x002f55d1 | 1,160 | 2,526 | 2 padding, 80 literals |
| ScriptManager::cleanCommand | 0x0033ffc1 | 90 | 202 | 2 padding, 8 literals |

Ready's verified 36-byte relative table contains nine indices and seven unique
targets. Fresh decompilation recovers every target; physical-address labels are
normalized against the original table before source review. The saved 284-byte
candidate remains unmatched: function offsets `0x96` and `0x106` differ, with
corresponding table differences at `0x1c` and `0x20`.

Target selection is static, not a Player receiver method: its source, weapon and
fallback pointer carriers occupy r0/r1/r2 and the pointer result uses r0. Its
five saved returning-call repairs affect only actual false float/delete
CALL_RETURN overrides. Fresh full memory, all instructions and untruncated
decompilation corroborate the saved repair. The preferred candidate is still
696 bytes versus 700 native bytes; neither its diagnostic relaxed link nor
separate historical dependency checks establish an accepted target.

State's repaired normal fsub and GetHeight continuations restore every real
instruction, but **complete ownership alone does not recover its computed
switch**. Initial fresh pseudocode still treated program `0x0034f232` as an
indirect call and omitted the case bodies. The original 28-byte table at retail
`0x0042f270` has seven indices and five unique destinations.

A subsequent guarded coordinator transaction restores only that dispatch's
branch flow and exact jump-table override. Its five existing analysis references
use operand index -1, not 0; they are preserved, including provenance and primary
flags, rather than duplicated or replaced. Initial preflight/reference assumptions
stop execution before mutation and are corrected against actual OS/project
evidence. The committed transaction verifies all function boundaries, global
function ABI/callee properties, every original instruction, full function/table
memory, and non-dispatch flows/references unchanged. Its decompiler guard requires
all five destinations, switch cases and BRANCHIND without the former indirect-call
warnings. Independent fresh post-repair MCP readback confirms the full memories
and all five target groups, including the empty common state-store join.
This grants no source attempt or matching credit. Native instructions prove a
full-word state argument in r1; the existing local integer analysis view does not
resize or establish the width of the shared enum.

Player animation originally owns only 46 instructions and 100 executable bytes.
One actual false CALL_RETURN at native `0x00304038` hides eight instructions,
including a second fadd and both velocity stores. Its second fadd at `0x0030404a`
already has normal flow and is not changed. A guarded coordinator transaction
clears only the first override, decodes undefined original Thumb spans, and
restores the exact 120-byte code body without ABI, global-callee or branch edits.
Whole initialized program memory, other function boundaries and existing ABI
remain unchanged. Independent fresh readback verifies all 54 encodings/widths,
full 132-byte memory and complete untruncated pseudocode. The previously tried
Y-first arithmetic ordering remains the only known source distinction; no new
source trial or matching credit follows.

Character::shoot has a separate guarded normal-flow repair: nine actual false
returning-float overrides and three proven internal long branches to its own
epilogue are corrected. The transaction decodes 278 previously undefined native
instructions and restores ownership of all 1,160 instructions / 2,526 code bytes.
Its full 2,608-byte function and 572 table bytes, all 141 genuine external calls,
existing references, ABI and unrelated function metadata remain unchanged.
That initial phase deliberately leaves both computed-switch overrides untouched;
complete instruction ownership must not be presented as complete case pseudocode.
Independent fresh readback confirms full function/table memory, all instruction
encodings and widths, body ranges and all 103 encoded direct destinations.
Its initial pseudocode remains identical to the pre-repair output and omits cases.
The nine actual override removals, three branch overrides and global preservation
details remain coordinator-receipt evidence, not public getter observations.

A separate guarded transaction then restores the two exact computed switches:
134 signed entries/eight targets and nine entries/seven targets. Existing actual
reference operands, provenance, primary flags and symbol associations are
preserved, along with all normal-flow repairs and unrelated symbols. Fresh
independent readback normalizes all 143 indices and 15 target groups; complete
pseudocode no longer has either unresolved-switch/call warning.

This exposes a genuine [blocked-shot HUD guard correction](../nonmatching/characters/Character-shoot-blocked-hud.md):
native skips both damage and HUD updates when blocked. The one isolated source
control saves four bytes but remains unmatched at 2,622 function / 2,624 section
bytes versus 2,608 required; strict prelink rejection prevents any linker run.

CleanCommand's separately guarded 118-entry/nine-target switch repair preserves
its complete 212-byte function and 472-byte table, all instructions/references,
ABI and unrelated function metadata. Fresh readback recovers eight explicit
cleanup cases plus the empty epilogue, with no unresolved-switch warning.
Visible cleanup paths agree with the retained candidate, including opcode 114's
delete without clearing; no new source trial follows.

For these readbacks, public MCP getters expose signatures, memories and
instruction listings, but not explicit custom-storage flags or automatic
parameter flags. Those details remain saved-export evidence, corroborated by
native register use rather than misreported as independently queried metadata.
Analysis repairs themselves add no byte-matched functions or Fully Linked credit.
