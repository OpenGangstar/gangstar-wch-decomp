# MenuManager::update exact match

`MenuManager::update(StateMachine*)` matches all 872 retail bytes at Thumb
address `0x002e4e7d`, including relocations.

```text
OK  _ZN11MenuManager6updateEP12StateMachine  0x002e4e7d  872 bytes
```

## Source form

While a menu is open, `update`:

1. accumulates the frame time and clears every cursor's touched flag;
2. snapshots the touch IDs;
3. advances the eight-step cheat sequence when the expected zone is pressed.
   On completion it refreshes the game-settings menu if it is on top and
   plays the unlock sound;
4. maps touches to up to four cursor slots, updates the cursors, and compacts
   released cursors out of the table;
5. consumes the cursor when the tutorial widget reports a press.

It then refreshes widget visibility if needed, and updates the menu animation
unless the menu is idle.

Details that the retail bytes require:

- When a released cursor is compacted, the vacated slot is cleared (`-1`)
  before the count is decremented. The other order recomputes the slot
  address.
- `StateMachine::getTimeStamp` is declared as a local `extern "C"` symbol.
  Including `StateMachine.h` would emit an inline singleton accessor and an
  extra cleanup function into this unit.
- `list<long>::operator=` is called through the GOT, by a weak declaration.
- The game-settings state name is a file-local array, placed at its retail
  address `0x00418da0`. The menu-state unit places its own copy of that string
  there, so in that link the helper copy goes to verification-only storage.

No branch hint, inline assembly, register constraint or output edit is used,
and no header change. The double-precision helpers are bound to their PLT
stubs in the shared `MenuManagerFocus.ld`. The new callees are bound as Thumb
functions.

## Verification

`python -B tools/build.py` passes for menu-manager-helpers, ai-startup-menustate
and the five state-hook units that link the helper object. A fresh complete
build, `python -B tools/build.py --all`, exited 0 with 5,584 function, 5,668
section and 181 region comparisons and no mismatch or skip; the previous
baseline was 5,583, 5,666 and 181.
