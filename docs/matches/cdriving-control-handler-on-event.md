# CDrivingControlHandler::onEvent exact match

`CDrivingControlHandler::onEvent(IEvent const*, EventManager const*)` matches
all 2172 retail bytes at Thumb address `0x0032da91`, including relocations,
its six jump tables and its two function-local statics.

```text
OK  _ZN22CDrivingControlHandler7onEventEPK6IEventPK12EventManager  0x0032da91  2172 bytes
```

## Source form

The handler dispatches driving input events: accelerometer steering, the
on-screen sticks and buttons, keyboard controls, camera distance, radio
and visibility toggles, and the fallback that drives the player to a random
destination.

Details that the retail bytes require:

- **Member calls on the player.** The fallback calls the player's position
  interface members directly instead of binding a `SavePositionInterface&`.
  The reference conversion emitted a null check; without it the frame is
  retail's 180 bytes and the spill layout matches.
- **Case order.** The keyboard `case 134` precedes `case 133`, so
  crossjumping merges the increment pair as retail does. The accelerometer
  case comes first in the outer switch; this changes the instruction order
  reload sees and gives retail's spill-register choices (source comment).
- **Layout hint.** A documented no-code `__builtin_prefetch` in the
  visibility-clear arm of the `I` key lowers that arm's frequency, so block
  reordering places it after the radio arm, as retail does.
- **Local views.** The stick event payload, the vehicle camera distance and
  the radio toggle state are read through file-local views instead of
  private headers.
- **Linker.** The jump tables (`0x00425978`) and the `backWeight` and
  `frontWeight` statics (`0x004b9980`, `0x004b9984`) are placed at their
  retail addresses, and the soft-float and libm PLT entries are provided.

The section is 2176 bytes: the body plus a `c046c046` pad, matching
retail's alignment before the next function at `0x0032e310`. Behaviour is
unchanged. No inline assembly, register constraint, flag change, output
edit or header change is used.

## Verification

`python -B tools/build.py ai-startup-cdrivingcontrolhandler` passes. A
fresh complete build, `python -B tools/build.py --all`, exited 0 with
5,649 function, 5,713 section and 180 region comparisons and no mismatch or
skip; the previous baseline was 5,648, 5,713 and 180.
