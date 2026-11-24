# VehicleController::onEvent: consumed snapshots (unmatched)

Target: `_ZN17VehicleController7onEventEPK6IEventPK12EventManager`, Thumb
`0x00342585`, 200 retail bytes. This remains unmatched; its assembly marker and
progress status are unchanged. No Fully Linked credit is added.

The attached four-file patch archives a coherent current-context candidate.
It adds the pending body, two genuine const nonvirtual EvNPCVehicle getters,
native section routing and the existing PlayerTest getter binding. The current
event constructor, destructor attributes, fields, layout and virtual slots are
preserved. These private prerequisites have not been adopted canonically.
`git apply --check` succeeds against the source/configuration checkpoint after
PR #788. Patch text uses normalized newlines; the measured private source hash
below identifies the exact original compilation context.

The patched profile retains its old owner selectors; a successful ordinary
profile build is not a target match. Check the linked candidate separately:

```sh
python tools/build.py ai-startup-vehiclecontroller --baselib <retail-library>
python tools/check.py build/matches/ai-startup-vehiclecontroller/ai-startup-vehiclecontroller.elf --func _ZN17VehicleController7onEventEPK6IEventPK12EventManager --baselib <retail-library>
```

The candidate must remain uncredited while that function comparison fails.

## Establishing a current baseline

The old v3 target image survived, but its whole-object/source/input pairing did
not. The current fixture uses current headers, all 16 production compiler flags
and the exact archived v3 body. It does not claim to reproduce the missing
historical whole object.

The fresh ordinary baseline passed all 12 current owner function checks and
13 section/region checks, plus five real helper functions and seven complete
helper sections. The target was actual positive executable code, function and
input both 200 bytes, ending at `0x0034264c`. The next function and switchState
remained exact. No emitted definition was replaced by a generated binding.
Emitted D2 aliases were checked as actual aliases to D1; nonexistent retail D2
symbols were not invented or credited.

The complete GOT retained 642 differences within its 864-byte prefix and zero
differences in its 17,972-byte suffix. One positive unselected IEventReceiver
destructor orphan remains outside native matching claims. No whole-GOT or
whole-library match is claimed.

An unchanged-source neutral diagnostic reproduced the whole 13,320-byte object,
26,144-byte assembly, all metadata and all 139 references exactly before any
pass analysis. The comparison orientation was already present in the earliest
trees. Pass 147 complemented the loop branch without commuting its operands.

## One source composition

Primary GCC 4.2.1 comparison folding preserves the written order of two DECL
operands. One bounded composition introduced real consumed target/result
snapshots, preserving each target read before the opaque player getter and each
fresh assignment receiver read before its final callback. It also used a cached
count with an ordinary for loop. Native code already reads that count once;
the only loop callback immediately exits. Count caching alone was previously
tried with a different guarded-do form and is not presented as a new discovery.

One frontend/assembler pair with unchanged flags produced function/input
200/200. Exactly one byte of the entire object changed:

```text
object offset 0x6e0, target offset 0xb0: 84 -> a0
old CMP r4,r0 -> new CMP r0,r4
```

That equality now agrees with retail. Two nonrelocated loop-comparison bytes
remain different at `0x3e` and `0x41`. Twelve other prelink differences belong to
unresolved BL operands and are not claimed as linked mismatches. The separate
LD-only verification below resolves them. No full-function match is claimed.

All other 13,319 object bytes remain exact. The 22 off-target functions,
41 off-target allocated payloads, 42 imports, 135 off-target references, all
139 references and full symbol/section/ELF-header metadata remain exact. All
3,936 pinned files, all 119 compiler/runtime files and all 22 saved ordinary
auxiliary outputs remain unchanged. No output was patched or normalized.

Measured private source SHA256:
`75e2f9914cedc14b7494610c66c74c818021b58944a94e3a066cfed8e34e1fd8`.
Object SHA256:
`45414f3117c20d53e42ba2ed35670bd1b30ae8a1a3af524d90039dd9bbe7d5fa`.
Assembly SHA256:
`a4001f353c6adabd5489f5c208737d4c8f87d767de97a5fb4ff400dc9d573cb8`.

## Paired linked verification and loop origin

A separately approved LD-only run used the saved genuine harness and bindings,
with no compiler, assembler or harness rebuild. All 17 existing function and
20 section/region checks passed. The actual target and its complete 200-byte
section both differ from retail in exactly the two loop-comparison bytes above.
The entire linked image differs from the ordinary baseline in exactly the one
fixed equality byte; all ELF, symbol and section metadata remain exact. The
paired GOT is unchanged, including its disclosed native-prefix differences.
The positive target, nextPoint, switchState and the unselected orphan retain
their placements. No emitted definition becomes missing or ABS.

An exact whole-object/assembly replay of the improved source then located the
first loop-order reversal at pass 47, header copying. The original and SSA
condition is `i_1 < count_19`. After header copying, the backedge condition is
`count_19 > i_56`, with `i_56 = i_41 + 3`. This first-pass boundary is measured.
Attributing the swap to the primary SSA-version comparison-folding rule is an
inference; no direct call to that helper was logged. Later RTL retains count
in R7 and index in R0, and pass 147 complements the branch without commuting it.

Keep this improved candidate distinct from the three-byte-residual ordinary
baseline. Further source changes require a new supported constraint; the earlier
six-form budget is not reset. Matching and Fully Linked progress remain unchanged.
