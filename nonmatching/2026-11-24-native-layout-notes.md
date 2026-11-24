# Native layout follow-up: preserved candidates, no additional credit

These investigations follow the earlier reconstruction notes. Only the exact
existing Vehicle cleanup reconstruction was adopted; its current-source global
verification is documented in
[vehicle event construction](../docs/matches/vehicle-event-construction.md).
The candidates below remain outside matched source, and their assembly markers
remain present.

## ScriptManager::update

The retained logical-AND flag test had already folded to a single mask
comparison in GCC's original tree. Retail instead tests bits 14 and 13
separately. Explicit plain-C++ short-circuit control flow restores those two
tests without changing callbacks or failure outcomes. Removing the remaining
experimental script-state hint in this new context then restores the native
loop latch, header, inline execute call and both initial pool positions.

The final fragment has no likelihood hint. Function size is 1,220 bytes and its
complete input section is 1,224 bytes; the trailing `c046c046` agrees with the
retail gap. A strict link retained the actual Thumb entry `0x0033f511`, native
section boundaries and adjacent startup addresses. All 143 existing function
and 136 existing section checks pass. The assigned function and its complete
section still have **196 differing bytes**. This is not matching credit.

Exact checker output:

```text
MISMATCH  _ZN13ScriptManager6updateEi  0x0033f511
  expected : fd f7 78 fd 00 28 00 d1 13 e1 01 22 00 21 00 23
  actual   : fd f7 78 fd 00 28 00 d1 0d e1 01 22 50 46 00 21
  differs at 0x50
```

All 58 direct-call relocations resolve to their correct retail destinations.
Remaining differences include initial argument-move scheduling, two commuted
indexed-load operands and the widget-hide arm layout. The latter changes local
branch displacements and neighboring cold-block positions. Earlier linked
stages had 988, 973 and 791 differing target bytes; these are historical
comparisons, not percentages or completed functions.

The complete GOT still differs in 642 reserved-prefix bytes; every byte from
offset `0x360` onward is exact. Neither target bytes nor GOT contents were
patched. The JSON beside the fragment records the actual source, object and
linked-image identities. This is a historical 884-input fixture, not a claim
that the fragment has passed the current complete-source global gate.

## Vehicle::_processAIFlags

The unchanged method fragment is now paired with its tested base-initializing
constructor and automatic-cleanup context. It produces 3,168 function/input
bytes versus 3,220 native bytes, the native 476-byte frame and all ten native
event homes. All ten base/ID/derived construction phases are independently
verified. The historical linked image preserves all 188 existing function
and 112 existing region checks, including cleanup's native 84 bytes. The AI
function and its section remain mismatched.

Both images contain 220 pool bytes. The remaining deficit is 52 executable
bytes. Existing compiler diagnostics locate the first merge of three event
continuations in `143r.csa`: two raise/destructor tails merge into the third.
Their duplicate instruction content accounts for 36 bytes locally, but other
joins change in the same pass. This does not establish a complete explanation
of the 52-byte deficit or justify inserting code.

The neutral diagnostic initially failed strict whole-object identity. A
subsequent raw inventory confined all 368 differing bytes to generated
anonymous-name tokens in the string tables. An explicit bijection covers 23
section and symbol pairs; every function/data payload and semantic reference
is preserved under that correspondence. Only then were the existing dumps
interpreted. The original whole-file failure remains disclosed; output was
never renamed or rewritten, and the seed-generation cause remains unknown.

One separate `-fno-crossjumping` control overshot the native function extent
and regressed five existing functions. It was rejected without linking or
changing canonical compiler flags. The retained candidate remains the
original configuration with its measured 52-byte deficit.

## GetRandomDestination and Billboard

An unchanged-source `-fdump-tree-optimized-details` run recovered the missing
SSA coalescing map for `PhysicAttributes::GetRandomDestination`. Its complete
22,672-byte object and all 317 semantic relocations were identical to the
authenticated baseline. Synthetic roots are created as maximum, minimum,
linear error; reversed declaration order feeds the already measured spill
homes. This explains the current allocation chain but supplies no justified
source transformation producing the native rotation. The 724-byte candidate
still differs in eleven operand bytes and remains parked.

Two bounded Billboard trials, binding the genuine camera result by reference
and explicitly capturing target XY scalars, each produced the identical whole
object. Its 704-byte parent and generated 20-byte thunk were preserved; neither
trial added matching credit. Further local spelling experiments are parked.
