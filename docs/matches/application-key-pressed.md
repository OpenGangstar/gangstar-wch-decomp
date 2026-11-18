# Application pressed-key handling

`Application::appKeyPressed(int)` matches all 308 bytes at Thumb 0x002d4709. The
third original source form preserves native key 82/key 4 dispatch, current-state
queries and menu-depth checks, cutscene/duplicate-key guards, and event arguments.
Separate state 23/state 22 clauses preserve the native branch structure. No branch
hint, assembly, register constraint or compiler-output edit is used.

An earlier exact candidate could not be integrated because its then-required
partial interfaces disturbed two existing MenuState functions. Three bounded
header-only diagnoses established that the additional method declarations alone
changed InfoHelp code generation, while the precise field split and friendship
alone passed. No old menu body was changed. After genuine ProcessKeyEvent/device
interfaces and released-key handling were integrated, one unchanged candidate
replay in that materially new context passed both the target and every old gate.
The exact existing candidate was reused rather than restarting source search.

The only additional shared declaration now needed is appKeyPressed itself;
lastPressedKey at offset 148 and StateMachine friendship already came from the independently
verified released-key implementation. Actual code is retained at its native
address in ApplicationHelpers and its GSFade dependency image. Existing native
globals/depth lookup remain imports; no new support definitions receive credit.

Scoped coordinator output:

```text
OK  _ZN11Application15ProcessKeyEventEbi  0x002d40fd  268 bytes
OK  _ZN11Application14appKeyReleasedEi  0x002d45ad  348 bytes
OK  _ZN11Application13appKeyPressedEi  0x002d4709  308 bytes
OK  _ZN15TouchScreenBase5getIDEl  0x0034c599  68 bytes
```

Coordinator `python tools/build.py --all` exited 0: 180 profiles and 9,790 function,
section and region comparisons passed. The private log/exit files are
_scratch/key-pressed-root-full.log and .exit. The worker independently passed 90
normal-toolchain profiles, 3,356 functions and 3,838 section/region comparisons.
Only the new 308-byte function is credited; all previous matches are preserved.
