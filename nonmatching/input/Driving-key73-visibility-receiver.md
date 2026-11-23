# Driving key 73: shared visibility receiver, still unmatched

Target `_ZN22CDrivingControlHandler7onEventEPK6IEventPK12EventManager`,
Thumb `0x0032da91`, native **2,172 bytes**. No matching credit is added.
The [delta](Driving-key73-visibility-receiver.patch) applies only to the retained
private v5 `game/input/CDrivingControlHandler.cpp`, not directly to current HEAD.

After the initial visibility toggle, native `0x32df68` captures the vehicle
before final `getMesh` / `isVisible`. Both flag-write arms use that receiver,
while reading flags after the callbacks. The old v5 reloads the handler member
afterward; all six historical forms share this discrepancy.

The one control adds `Vehicle* const visibilityVehicle = vehicle` immediately
**after** the unchanged toggle, then uses it for the final query and both word
bit-2 writes. It does not cache the flags or move the final player scene call.
If an intervening callback rebinds the member, native still writes the captured
vehicle; this is not a claim that actual gameplay exercises such rebinding.

## Measured result

One baseline compiler/assembler pair reproduces the complete saved v5 object
byte-for-byte, SHA256
`a56c6e4cb8b0d7ccf7218a2c5b0b1b920b27d4e3694c8d23c9c8257b80d21a3c`.
One corrected pair verifies the intended shared receiver in both arms and
preserves all 126 static calls in the same sequence.

**Function and entire input section remain 2,144 bytes**, versus 2,172 required.
The frame remains 164 versus 180 native bytes. Both strict extent gates fail:

```text
PRELINK STRICT FUNCTION: FAIL
PRELINK STRICT WHOLE INPUT SECTION: FAIL
NO LD: stop for root review.
```

The first raw non-relocated difference is at function `+0xc`. External call
relocations remain unresolved; this is not a linked native-byte comparison.
No linker, target table/GOT/native-placement check, current linked owner gate or
global rebuild ran for the control. No padding, flags or output bytes were edited.

Control raw function/full-section SHA256:
`ea0806487c4c5684c85432aec0f231d8b5226fd93268789980c804831f2e61f9`.
All non-target definitions, imports, allocated payloads and relocation records,
including target switch-data payload, remain unchanged. All 454 frozen inputs
are stable; no anonymous-name normalization was needed.

The private packet `_scratch/opencode-driving-visibility-control/` retains
`REPORT.md`, `source.patch`, exact compiler/assembler commands and exits,
baseline/control source and objects, and receiver/call-sequence proofs.
Its frozen 208-file graph includes historical Player interface views and five
existing noinline declarations; these are not silently installed in canonical
headers. The patch is not a portable current-tree profile.

The six initial forms and this one authorized receiver control remain spent.
No frame padding, quaternion retry, additional source form or inferred match
follows. The original parent assembly and all progress credit remain unchanged.
