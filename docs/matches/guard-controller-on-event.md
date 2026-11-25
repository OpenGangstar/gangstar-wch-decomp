# GuardController::onEvent exact match

```text
OK  _ZN15GuardController7onEventEPK6IEventPK12EventManager  0x00341f31  412 bytes
OK SECTION .guard_controller_on_event  0x00341f30  412 bytes
```

The archived body (408 bytes) tested `if (event->getEventID() == 22)`. GCC's
opcode heuristic gives an equality edge about 29%, below the 30% of the later
NPC-identity edge, so block reordering traced the NPC-payload switch first.
Writing the outer test as `switch (event->getEventID()) { case 22: ... }` gives
the case edge 50% and reproduces retail's trace order and extent. Every call
and memory access is unchanged; no hint is used. The image includes the existing
`PlayerEventSections.ld` so the inline event helpers link at retail addresses.
Retail-only callees `LevelObject::canSeeLevelObject` and
`NPCController::onEvent` are bound as external Thumb functions.

Full gate: `python -B tools/build.py --all` exited 0 with 5,479 function, 5,516 section and 181 region comparisons and no mismatch or skip.
