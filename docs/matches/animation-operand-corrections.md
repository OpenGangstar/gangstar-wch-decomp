# Animation reconstruction corrections: unmatched

Complete retail-byte-verified Ghidra instruction and switch recovery exposes
three concrete source errors. The preserved C++ fragments correct those errors;
neither function matches retail yet. No assembly marker or progress credit
changes. These fragments use repository LF endings and require their separately
preserved full private translation-unit/header/compiler contexts.

## Character::switchCombatAnimation

Target `_ZN9Character21switchCombatAnimationEv`, Thumb `0x002f517d`, 1,108 bytes.
The original switch covers animation values 51 through 175 with 125 signed
relative entries and 26 destinations. All 505 real instructions / 1,050 bytes
are independently verified; two padding bytes and 56 literal bytes complete
the original extent. Saved analysis metadata changes no original bytes.

Cases 54/58/63/71/80/96 call getSpecificAnimation(165), then branch at native
`0x002f54f4` to the same setAnimation tail used by case 66. That call is followed
by a fresh movementFlags bit-22 test, conditional ready(1.0f), then a fresh
post-ready flags load and clear. All five recovered candidates omit this tail
on those six cases. An initial negative audit missed that outgoing branch;
the later proof explicitly corrects it without deleting the earlier evidence.

The [preserved fragment](../../nonmatching/characters/Character-switchCombatAnimation-shared-ready.cpp)
adds exactly the existing case-66 conditional after the six-case group's
setAnimation. One separately authorized control compiles and assembles, but
both function and input section remain 1,100 bytes versus native 1,108.
Actual assembly now reaches the shared ready tail. Strict extent checks fail,
so native linking, target/full-section and linked owner/dependency checks are
skipped. Raw function SHA-256:
`61730b9a7838a49e207f5c9712d03dd5c209f1bee2bb11f5ed2a33f23a3c4475`.

All 110 other actual raw definitions, 136 other allocated payloads, 693
semantic relocation entries, imports and 409 frozen inputs are preserved.
The coordinator independently extracts the function and verifies all old raw
definitions and frozen inputs. No compiler output is edited.

Configuration limitation: the direct historical command/profile was not saved.
Two adjacent archived snapshots corroborate 14 legacy flags without
-fno-short-enums, but do not prove the exact historical invocation. The
coordinator explicitly selected one reconstruction with those 14 flags and
the archived headers/prefix, restoring the v4 suffix from the surviving v5 TU.
Actual v4/v5 linked images are identical; the preserved v5 object supplies the
raw baseline. No baseline recompilation, current-15-flag variant or second
source form is run. This is not a current-root closure proof. Evidence:
`_scratch/worker-character-switch-combat-shared-ready-control`.

## PlayerTest::switchAnim

Target `_ZN10PlayerTest10switchAnimEv`, Thumb `0x00303bb9`, 1,072 bytes.
All 491 real instructions / 1,028 bytes and 44 literal bytes equal retail.
The 213-entry / 852-byte signed switch table reaches 12 verified targets.
Independent fresh readback corroborates both source corrections below.

In the driver-eject path, native passes setAnimation(id,1.0f,false,true,false).
The prior six candidates pass true as the first Boolean. Exact native register
and stack setup proves R3=0, SP0=1, SP4=0 at the saved virtual-slot-160 call;
the actual candidate sets R3=1. A sole first-Boolean correction preserves all
other arguments and call ordering, and actual output now passes R3=0.
Function/input section remain 1,088 bytes versus 1,072, so linking is skipped.

In high-animation cases 190/193/198/204/207/212, native reads combatMode byte
356 and, when false, targetLocked byte 354 after the animation callback.
All old candidates instead read lockRequested byte 353. A second separately
authorized control replaces only that operand, retaining fresh post-callback
reads and the eject correction. Function/input section become 1,084 bytes;
the emitted reads are 356 and 354. The strict 1,072-byte gate still fails,
so all native target/full-section and linked owner/dependency gates are skipped.

The [preferred Player fragment](../../nonmatching/ai/PlayerTest-switchAnim-corrected.cpp)
retains both corrections. Raw function SHA-256:
`b69067a43e6aa09a5246dd883b387963cbc91614463ea3b3a5f1d73c9690f81e`.
For each control, all 79 other raw definitions, 110 other allocated payloads,
66 other semantic relocation sections, imports and 485 frozen inputs remain
unchanged. The coordinator independently verifies each object, old raw
definitions and frozen inputs. Source replacements preserve exact private
source bytes and original argument paths; no line-ending conversion occurs.

Historical owner and 66 successful header-user profiles do not prove current
closure. The historical GameObjectManager fresh-link failure remains unresolved
in that old fixture; no stale image is substituted for a new link. The two
actual control packets are `_scratch/worker-player-switch-anim-eject-loop-control`
and `_scratch/worker-player-switch-anim-target-locked-control`. Further source
experiments require new evidence; smaller extent is not a matching percentage.

## Later bounded Player compiler controls

A structural census of the corrected 1,084-byte object localizes eight excess
bytes to address materialization around its inline four-byte memcpy. The
original six forms all use that intrinsic. A separately bounded experiment
expresses the same transport as unsigned 32-bit lvalue load/store at the same
proven aligned offsets, Vehicle312 to Player148, under the unchanged
-fno-strict-aliasing profile. This is a raw storage view, not a recovered
semantic destination type, float conversion, new field or layout change.

That one control emits a 1,076-byte function/input section. Its four-instruction
copy sequence, `3b591a599423fa50`, equals the corresponding eight native bytes.
The complete function still fails the strict 1,072-byte gate; linking is skipped.

Another separately bounded control gives cases 22/23 a driver-present state12
and break, with driver-absent fallthrough into cases 26/28's shared state3.
This matches the native shared-join structure with one driver read, preserving
all other states, calls and corrections. The function/input section remain
1,076 bytes. Raw hash of this final preferred fragment:
`f4597c7ffb08f2dafcc3995a7ef9b09afd51fc57dff0561767925f3395061d62`.

For both controls, all 79 other raw definitions, 110 other allocated payloads,
66 other semantic relocation sections, imports and 485 inputs stay unchanged.
The coordinator independently extracts and verifies each object and old raw
definitions. No native function/full-section/table or linked owner/dependency
checks run after the failed extent gates. Exact contexts and outputs remain in
`_scratch/worker-player-switch-anim-raw-word-control` and
`_scratch/worker-player-switch-anim-state3-join-control`.

The final object has the same 491 real instructions, 1,028 real code bytes and
44 literal bytes as native, but also four unreachable alignment bytes before
literal pools. This does not establish byte identity: block order, register and
stack assignments, instruction encodings, pool references and table payloads
still differ. Padding is neither removed nor credited. The candidate is parked
unmatched; no additional source or flag trial follows from equal counts alone.
