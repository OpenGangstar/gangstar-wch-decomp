# VehicleController::onEvent exact match

`VehicleController::onEvent(IEvent const*, EventManager const*)` matches all 200
retail bytes at Thumb address `0x00342585`, and its strict section ends at the
retail extent.

```text
OK  _ZN17VehicleController7onEventEPK6IEventPK12EventManager  0x00342585  200 bytes
OK SECTION .vehicle_controller_on_event  0x00342584  200 bytes
```

## Source form

The function handles two events:

- **Event 19 (NPC vehicle event).** For the controller's own vehicle it scans
  the state-transition triples `{from, condition, to}`, and switches state on
  the first match for the current state and the event type.
- **Event 22 (player event).** While the controller is in state 8, it retargets
  the vehicle between the player and the player's vehicle as the player enters
  (state 9) or leaves (state 10).

The earlier form differed in the loop latch compare orientation:

- **`int i < transition.count`.** fold's DECL_P rule swaps the operands at the
  front end.
- **A named `count` local.** The swap survives until loop-header copying
  refolds it by SSA version.
- **The fix.** An `unsigned` index compared through `static_cast<int>(i)` is a
  sign-changing conversion. That keeps the index first through both points and
  gives retail's `cmp r0,r7; bge`. Indexing was already unsigned in the trees,
  so the behaviour is unchanged.

`EvNPCVehicle` gains the inline accessor `getVehicle()` for its vehicle field.

No branch hint, inline assembly, register constraint or output edit is used.

## Verification

`python -B tools/build.py --all` exited 0 with 5,566 function, 5,649 section
and 181 region comparisons and no mismatch or skip, including every unit that
includes `NPCVehicleEvent.h`. Unit tests, repository checks and progress checks
pass.
