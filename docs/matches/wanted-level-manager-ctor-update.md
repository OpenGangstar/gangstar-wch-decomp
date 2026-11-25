# WantedLevelManager constructor and update exact matches

```text
OK  _ZN18WantedLevelManagerC1Ev  0x00342b09  184 bytes
OK  _ZN18WantedLevelManagerC2Ev  0x00342b09  184 bytes
OK SECTION .wanted_constructor  0x00342b08  184 bytes
OK  _ZN18WantedLevelManager6updateEd  0x00342fc9  376 bytes
OK SECTION .wanted_update  0x00342fc8  376 bytes
OK  _ZThn4_N18WantedLevelManager6updateEd  0x00342fb4  20 bytes
```

## Constructor

Initialises the wanted state (timers 10000.0 and 5000.0, elapsed timers 0.0,
flags false) and attaches the manager to events 22, 16 and 19. The earlier
body-assignment form stored the bools first, so the `strb` offset constant
took r2 and the zero r3 (16 differing bytes). Writing the members as a full
initializer list in declaration order puts the integer zero stores first, the
zero value is allocated first, and sched2 still yields retail's store order.
`unknown16`/`unknown20` stay uninitialised, as in retail.

## update(double)

Runs the wanted-level escape state machine: reset while cops are engaged,
start the first timer, count it down, then the second timer, and finally lower
the level, raising `EvWantedEscaped` at zero and recording the escape badge.

The earlier candidate was 16 bytes short. It built a named `EvWantedEscaped`
local, which kept the event address live in r4 while `application` was still
needed, pushing `application` to r6 and `elapsed` out of registers. Passing a
temporary, `raise(EvWantedEscaped())`, ends `application`'s lifetime first;
it then takes r4, `elapsed` stays in r6:r7 and the frame matches retail.

The `wanted-update-thunk` verification image previously compiled a local
copy of `update` to check the compiler-generated this-adjusting thunk; it now
includes the matched canonical source only. `EventManager::attach` and
`AchievementManager::recordBadgesEscaped` are bound to retail Thumb
addresses and the soft-float double helpers to their PLT entries.

No header, hint, inline assembly or register constraint is used.

Full gate: `python -B tools/build.py --all` exited 0 with 5,507 function,
5,584 section and 181 region comparisons and no mismatch or skip.
