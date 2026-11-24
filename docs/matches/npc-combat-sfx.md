# NPC::triggerCombatSFX

`NPC::triggerCombatSFX(int)` (`_ZN3NPC16triggerCombatSFXEi`, Thumb
`0x002fe615`) is reconstructed as a static member function. The native body
occupies 368 bytes at `0x002fe614`, ending at the next function, `0x002fe784`.
Its seven-entry switch table occupies 28 bytes at `0x0041d8fc`. The recovered
static timer is a four-byte zero-initialized BSS object at `0x004b803c`.
Static declarations add no instance storage or virtual slots.

The implementation preserves the type guard, timer and random-selection
phases, sound-manager flag lifetime, playback arguments, and NPC notification
traversal. It reuses the existing Application, Irrlicht device, SoundManager,
GameObjectManager and NPC interfaces. The device header supplies its existing
complete interface; no replacement engine declaration is introduced.

## Resolving the final register differences

The earlier candidate differed in eight bytes: four pairs of low-register
constant materialization and transfer to R8. A neutral register-origin
diagnostic traced the choices to reload, rather than later scheduling. A
single source composition changed the early case visitation order by placing
case 5 before case 4 and exchanging the equivalent case-6 conditional arms.
That ordinary C++ form reproduced all nine native materializer choices.
Random calls, their observation phases and selected sound IDs remain unchanged.

The existing 15 production compiler flags are unchanged. No branch hints,
inline assembly, register constraints, artificial barriers, output editing,
replacement machine code or additional padding are used.

The historical source trial preserved all 69 off-target definitions, 126
imports and 351 reference sites. The whole object changed only the eight
intended target bytes and 16 string-table bytes identifying one generated
anonymous namespace. A narrowly enumerated identifier correspondence was used
for that read-only preservation audit; neither object nor linked image was
rewritten. The historical link fixture lacked paired current dependencies,
so it was not replayed or accepted as native proof.

## Native placement and verification

The current build recompiles actual configured dependencies and generates
bindings excluding real definitions. The candidate, switch table and timer
are routed through `NPCFunctionSections.ld`, shared by the NPC and PlayerTest
images. Both parent scripts assert the native extents and next-function
boundary, following the existing NPC freeze convention. Unselected dependency
sections remain the established verification boundary, not newly completed
code or additional progress credit.

The authoritative checker prints:

```text
OK  _ZN3NPC16triggerCombatSFXEi  0x002fe615  368 bytes
OK SECTION .npc_combat_sfx  0x002fe614  368 bytes
OK SECTION .npc_combat_sfx_table  0x0041d8fc  28 bytes
```

The implementation additionally requires a positive executable function symbol
of size 368, exact full code and table bytes, and a positive four-byte NOBITS
timer symbol at its retail address. No ABS symbol substitutes for this body.

Initial verification failures are retained: a missing complete device include,
the PlayerTest image discarding the newly defined timer when sections were
only in the NPC parent, and legacy-linker rejection of assertions inside an
included fragment. The final arrangement keeps shared sections in the fragment
and assertions in both parent scripts. No checks or native placement constraints
were relaxed to resolve these failures.

The fresh all-profile gate passed 191 profiles, 5464 function, 5487 section and 181 region comparisons (11132 total). All 1178 frozen inputs remained unchanged. Every one of the 4,294 previously
matched game entries received its direct successful native comparison.
Canonical integration copied exactly the six reviewed source/configuration
files from that tested snapshot; all other frozen inputs were identical.

The canonical `python tools/build.py ai-startup-npc --baselib <retail-library>`
run also passes, including the exact function and both full sections quoted
above. After removing only this verified function marker, regenerated tables
retain all 17,703 retail functions and change exactly one pending game entry.
Progress becomes 4,295/4,550 functions, 357,306/561,716 bytes (63.61%).
Fully Linked remains 114,548 bytes (20.39%, 126/202 units), because NPC is
still incomplete. Fuzzy Matched is 63.61%, with no approximate credit.
