# COnFootControlHandler::onKeyboardEvent exact match

`COnFootControlHandler::onKeyboardEvent(IEvent const*)` matches all 1320 retail
bytes at Thumb address `0x0032e835`, including relocations. Its two jump tables
(98 and 53 entries) also match all 604 retail bytes at `0x00426228`.

```text
OK  _ZN21COnFootControlHandler15onKeyboardEventEPK6IEvent  0x0032e835  1320 bytes
OK SECTION .onfoot_keyboard_event         0x0032e834  1320 bytes
OK SECTION .onfoot_keyboard_event_tables  0x00426228  604 bytes
```

## Source form

The handler dispatches debug and gameplay keys. The pressed-key switch comes
first, then the released-key switch.

Details that the retail bytes require:

- **Equal-bodied cases.** The release-switch cases `G`/`J` and `H`/`Y` are
  written as separate cases with equal bodies, not stacked labels. Each extra
  case adds a switch edge, which changes the per-edge probability and the
  edge order. Post-reload cross-jumping then merges the bodies. Together this
  gives retail's release block order G, H, F, A, W, D, S and its W/S
  cross-jump host.
- **Case `125` placement.** Case `125` comes before case `L` and builds the
  item position with `position.X += 300.0f`. Its stack partition is then
  allocated first, and the Y/Z copy follows the add as in retail.
- **Door cases.** Case `5` comes before case `8`, and case `8` calls
  `openDoor(true)` itself. Cross-jumping only redirects into the
  lower-indexed block, so this merges case 5's call into case 8's tail.
- **Case `F`.** The attack test is written `unknown16 == 0`, with the
  handled-pressed arm first.
- **The one documented hint.** Case `8` keeps
  `__builtin_expect(car->getDriver() != 0, 0)`. Retail places the
  driver-show block out of line. With the pointer and call heuristics
  combined, the then-edge probability is about 0.65. bb-reorder only moves
  the triangle when that probability is below one third. Hint-free spellings
  of the test give the same 0.65. Case `7` keeps the unhinted pointer
  heuristic, because retail keeps its block inline.

## Header changes

`Vehicle.h` gains `friend class COnFootControlHandler;`, because the handler
reads the vehicle's immobilisation fields. That follows the existing friend
declarations and changes no layout.

The private `Character::positionInVehicle` and `Character::show` are called
through `extern "C"` declarations of their mangled names. A friend
declaration in `Character.h` alters `ServiceCarRental::Notify` in
ai-startup-menustate.

## Strings and data

The function-local statics `v`, `next` and `path`, and their guard variables,
are placed at their retail `.bss` addresses `0x004b9a14` to `0x004b9a28`.
`__aeabi_fadd` and `__aeabi_fsub` are bound at their PLT addresses.

No inline assembly, register constraint, flag change or output edit is used.

## Verification

`python -B tools/build.py ai-startup-confootcontrolhandler` passes every
function and section check. A fresh complete build, `python -B tools/build.py --all`, exited 0 with
5,604 function, 5,695 section and 181 region comparisons and no mismatch or
skip; the previous baseline was 5,603, 5,693 and 181.
