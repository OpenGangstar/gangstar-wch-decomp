# CopController::onEvent exact match

`CopController::onEvent(IEvent const*, EventManager const*)` matches all 894
retail bytes at Thumb address `0x00341381`, including relocations.

```text
OK  _ZN13CopController7onEventEPK6IEventPK12EventManager  0x00341381  894 bytes
```

## Source form

The function first forwards to `NPCController::onEvent`, then reads the current
wanted level and dispatches on the event ID:

- **NPC state events (16)** for this cop: a state-5 event in state 1 starts
  pursuit of the player when the cop has a pursuit level, and clears flag
  `0x10000`. That case falls through to state 21: while the player is wanted,
  the cop targets the player's vehicle when the player is driving, otherwise
  the player.
- **Player state events (22)**:
  - **State 2**: attacks a player within 3000 units and raises the wanted
    level to at least 1.
  - **State 9**: makes a single arrest attempt at the player's vehicle.
  - **State 10**: resets the alert state and pursues aggressively.
  - **State 11**: returns the controller to state 1.
- **Wanted-level changes (23)**: set the pursuit level, capped at 3, and pursue
  the player or their vehicle. Aggressive pursuit starts above level 2. When
  the player is no longer wanted, the handler falls through to the stand-down
  case (24).

Two small inline helpers reproduce retail's evaluation order and tail merging:

- `pursue(npc, target, aggressive)` sets the target and the pursuit flags. As
  an inline taking the object and target as arguments, it evaluates the object,
  then the arguments, then the virtual function pointer. That lets the two
  calls tail-merge.
- `raiseWantedLevel(manager, const int level)`.

`CopNPCView` is a file-local view of the two NPC flag words written here.
`movementFlags` at `+236` is private to `Character`.

No branch hint, inline assembly, register constraint or output edit is used,
and no header change.

## Linking

The section is placed at `0x00341380`. `NPCController::onEvent`,
`NPC::clearOnAlert` and `WantedLevelManager::_processWantedLevel` are bound as
Thumb functions. The float helpers are bound to their PLT stubs.

## Verification

`python -B tools/build.py ai-startup-copcontroller` passes every function and
section check. A fresh complete build, `python -B tools/build.py --all`, exited
0 with 5,577 function, 5,661 section and 181 region comparisons and no mismatch
or skip; the previous baseline was 5,576, 5,660 and 181.
