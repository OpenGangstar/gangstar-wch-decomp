# CopVehicleController::onEvent exact match

`CopVehicleController::onEvent(IEvent const*, EventManager const*)` matches
all 744 retail bytes at Thumb address `0x00341a3d`, including relocations.

```text
OK  _ZN20CopVehicleController7onEventEPK6IEventPK12EventManager  0x00341a3d  744 bytes
```

## Source form

The police vehicle controller reacts to vehicle and player events: it
starts or stops pursuit, spawns crew, raises the deactivation event and
updates the wanted level.

Details that the retail bytes require:

- **Case order.** The switch cases are written in the order 23, 24, 19, 22.
  This sets the instruction order that reload's round-robin spill-register
  choice sees, which gives retail's scratch registers and scheduling.
- **Pursue helper.** The pursuit code shared by two cases is a static
  helper, so the copies are cross-jumped with the frequencies retail's
  block order implies.
- **Driver test.** The driver slot is tested for null through an unsigned
  integer read of the slot. The value is the same; because the compare is
  not pointer-typed, the pointer branch heuristic does not apply, which
  gives retail's block order.
- **Event views.** The deactivation event is built through file-local
  views of the event layout, with the vtables named by their mangled names,
  because the shared event header's constructor cannot be changed.

No branch hint, inline assembly, register constraint, output edit or header
change is used. The other CopVehicleController.cpp functions keep their
bytes.

## Verification

`python -B tools/build.py ai-startup-copvehiclecontroller` passes. A fresh
complete build, `python -B tools/build.py --all`, exited 0 with 5,626
function, 5,710 section and 180 region comparisons and no mismatch or skip;
the previous baseline was 5,624, 5,710 and 180.
