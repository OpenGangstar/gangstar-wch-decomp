# NPCController::onEvent exact match

```text
OK  _ZN13NPCController7onEventEPK6IEventPK12EventManager  0x0034228d  96 bytes
OK SECTION .npc_event_function  0x0034228c  96 bytes
```

The handler reacts to event 16 for its own NPC by scanning the transition
table in triples `(from, condition, to)` and switching state on the first
entry matching the current state and the event's state.

The archived candidate used a switch and a pointer walk and differed in 15
bytes. Nested `if`s with a `return` right after `switchState`, reading `state`
and `transition.count` directly and indexing `transition.transitions[index]`
directly (no cached table pointer, so loop-invariant motion hoists the load
after the count guard) reproduce retail's register allocation and loop latch.
The existing full-width `TransitionCondition` enum supplies the 96-byte extent.
`gameloft::ai::Transition` is declared locally as in the earlier patch. The
IEvent inline helpers emitted with the body are placed at their retail
addresses so the image links without overlap; they are not additionally
credited here.

Full gate: `python -B tools/build.py --all` exited 0 with 5,477 function,
5,510 section and 181 region comparisons and no mismatch or skip.
