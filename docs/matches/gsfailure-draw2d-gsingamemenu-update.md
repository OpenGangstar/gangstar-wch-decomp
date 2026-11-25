# GSFailure::draw2d and GSInGameMenu::update exact matches

```text
OK  _ZN9GSFailure6draw2dEPK12StateMachine  0x002e1e15  308 bytes
OK SECTION .gsfailure_draw2d  0x002e1e14  308 bytes
OK  _ZN12GSInGameMenu6updateEP12StateMachine  0x002e2725  352 bytes
OK SECTION .gsingamemenu_update  0x002e2724  352 bytes
```

## GSFailure::draw2d

Fades a red (cause bit 1) or blue (cause bit 2) full-screen tint while the
failure timer runs, draws the failure animation and, once it has finished,
sets the three failure text lines (busted, wasted or the mission's own failure
cause, plus a blinking prompt).

- `ScriptManager::getFailureCause` is effectively static in retail (called
  with a stale r0), so it is reached through a local `extern "C"` declaration of
  its mangled name, the pattern this project already uses for such calls.
- The tint colour is built as `SColor color(alpha, 0, 0, 0)` and then only its
  red or blue channel is set. With only two channels individually used, GCC's
  scalar replacement keeps the colour in memory and the early `g = 0` store
  stays before the second cause query, as in retail; setting more fields
  individually scalarizes it.

## GSInGameMenu::update

Runs the in-game menu's open delay, map push, close detection and fade-out.

- `switch (static_cast<int>(state))` gives retail's signed dispatch order.
- The ambient sound is fetched into a local before raising the sound
  manager's flag at offset 140, matching retail's store order and registers.
- `MenuManager::topSetVisible` is not declared in `MenuManager.h`; it is reached
  through a local `extern "C"` mangled-name declaration (header changes there
  perturb other matched code).
- Retail passes the tail of a linker-merged `"LightingMap"` literal as the
  `"Map"` menu name, so the name is an external alias bound to `0x0040b608`.
- Including `ai/StateMachine.h` emits the inline `StateMachine::getInstance`
  singleton in this unit, as in the other state units; its copies are placed
  at the retail singleton addresses like `GSFade`'s.

Retail-only callees are bound to retail Thumb addresses and the soft-float
helpers to their PLT entries. No hint, inline assembly or register constraint
is used.

Full gate: `python -B tools/build.py --all` exited 0 with 5,525 function,
5,602 section and 181 region comparisons and no mismatch or skip.
