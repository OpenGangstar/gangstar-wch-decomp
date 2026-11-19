# NPC transition dispatcher: current event interface

Unmatched candidate for `NPCController::onEvent(const IEvent*, const EventManager*)`,
Thumb `0x0034228d`, native 96 bytes. No matching credit or assembly deletion.
Apply only after the full-word TransitionCondition correction documented in
[the prerequisite note](../../docs/matches/npc-transition-condition-width.md).
The patch changes the pending method, its profile and its native placements;
it does not change any existing function body or compiler option.

This is one bounded switch-dispatch escalation after six archived early-return
forms. It reuses the genuine EvNPC accessors, controller declaration and current
StateID ABI. The transition table retains its observed pointer plus signed
word count and three-word entries. The event ID, NPC identity, positive-count
gate, matching state/condition, first-match virtual call and exit are preserved.

The initial narrow TransitionCondition declaration emits 98 bytes and includes
`lsl r2, r5, #24` / `lsr r2, r2, #24` before the call. Retail forwards the full
condition word. A separate header-only correction removes this narrowing, but
the callback still emits 94 bytes in a 96-byte allocated section. Neither the
function size nor its bytes match. The final unsigned full-range declaration
and the signed full-width diagnostic produce identical 94-byte function bytes.
The source body was not varied again.

```text
BUILD ai-startup-npccontroller
{"size": 94, "native_size": 96, "section_size": 96, "new_definitions": ["_ZN13NPCController7onEventEPK6IEventPK12EventManager", "_ZN6IEventD0Ev", "_ZN6IEventD1Ev", "_ZN6IEventD2Ev", "_ZNK6IEvent10getEventIDEv"], "raw_sha256": "17a58fe3b7f560697b2f31b3305d7fb33db4421ff76dfa61e1aa4b5777c719c5", "linked": false}
Prelink extent/helper guard failed; no linked comparison claimed.
```

Genuine IEvent helpers are newly emitted because the candidate includes the
existing NPC event header. Their native function, section and vtable selectors
are explicit; the D2 alias has no separate native catalogue entry and receives
no credit. The prelink guard allows only this documented definition set and
requires the exact target size before linking. It stops with exit 3. No helper
or callback linked proof, old-function comparison or new matched credit is
claimed for the candidate image. The header prerequisite was proved separately
with the pending candidate completely removed.

With `WCH_BASE_LIB` configured, `python tools/build.py ai-startup-npccontroller`
after applying the patch is expected to report a function mismatch. The
96-byte allocated section satisfies its strict section assertion; the actual
94-byte function does not match. The private prelink probe additionally
requires the actual function symbol size to equal 96 and stops before linking. Extent and overlap checks
are never relaxed. Do not add alignment or edit compiler output to fill the
two-byte gap. Further callback trials need new evidence.
