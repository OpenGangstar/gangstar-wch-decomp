# Menus::ServiceCorruption::Notify exact match

`Menus::ServiceCorruption::Notify(MenuWidget const*, int)` matches all 184
retail bytes at Thumb address `0x002eb6a9`, and its strict section ends at the
retail extent.

```text
OK  _ZN5Menus17ServiceCorruption6NotifyEPK10MenuWidgeti  0x002eb6a9  184 bytes
OK SECTION .service_corruption_notify  0x002eb6a8  184 bytes
```

## Source form

The earlier reconstruction differed in four bytes: it compared the notifying
widget with `r8` where retail compares with `r3`.

- **Why retail uses two registers.** Retail keeps the corruption widget in `r8`
  for the later `SetWantedLevel` call, and compares a separately converted value
  in `r3`.
- **Why the old form did not.** GCC 4.2.1 drops a pointer conversion that only
  adds `const`, so a plain `MenuWidget*` local compared the same value it later
  passed.
- **The fix.** The widget is held as `Widgets::Corruption*`, declared locally as
  a `MenuWidget` subclass in the same way as the existing `Widgets::IGMenu` and
  `Widgets::MainMenu` views.
  - The comparison `widget == corruption` is then a real derived-to-base
    conversion with its own temporary.
  - The member call `corruption->SetWantedLevel(level)` mangles to the existing
    retail symbol.

The guards and arithmetic come from the retail instructions:

- the `Services::Notify` fallthrough;
- widget index 5 and event 1;
- a wanted level above 0 together with either the rich flag or at least 1,500
  cash;
- the clamped decrement and `_processWantedLevel`;
- `subCash(1500)` and `UpdateLocalization`.

No header change, branch hint, inline assembly, register constraint or output
edit is used.

## Verification

`python -B tools/build.py --all` exited 0 with 5,542 function, 5,624 section
and 181 region comparisons and no mismatch or skip. Unit tests, repository
checks and progress checks pass.
