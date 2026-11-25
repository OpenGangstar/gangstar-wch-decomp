# MissionConditionStayWithin::evaluate exact match

```text
OK  _ZN26MissionConditionStayWithin8evaluateEi  0x0033820d  524 bytes
OK SECTION .stay_within_evaluate  0x0033820c  524 bytes
```

Counts down the mission timer while the player (or their vehicle) is farther
than the allowed distance from the target, showing the "stay within" warning,
and resets the timer otherwise; it then shows or clears the mission timer text
and reports whether time remains.

- Retail evaluate contains a stack-protector canary (`__stack_chk_guard` load,
  guard word, `__stack_chk_fail` call), so the unit's manifest now passes
  `-fstack-protector`, like its sibling `MissionConditionBeQuick` unit. Every
  other function of the unit compiles to the same bytes with the flag.
- The distance is a ternary with `getDistanceFromSQ` in each arm.
- Testing `timer != timerLimit` with the clamp/timer-text branch first makes
  reload keep `this` in r1 for the store, as retail does.
- The shared `"%02d:%02d:%01d"` timer format (from `MissionTimerText.h`) is
  placed at its retail address 0x0042ad20, as in the BeQuick unit.

Retail-only callees are bound to retail Thumb addresses and the soft-float,
division and `sprintf` helpers to their PLT entries. No header change, hint,
inline assembly or register constraint is used.

Full gate: `python -B tools/build.py --all` exited 0 with 5,527 function,
5,604 section and 181 region comparisons and no mismatch or skip.
