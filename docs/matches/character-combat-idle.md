# Character::goToCombatIdle exact match

```text
OK  _ZN9Character14goToCombatIdleEv  0x002f2581  300 bytes
OK SECTION .character_combat_idle  0x002f2580  300 bytes
OK SECTION .character_combat_idle_table  0x0041bcf4  36 bytes
```

Sets the combat-idle movement flag and picks the idle animation for the held
weapon type through a nine-entry switch.

The unapplied reconstruction in `nonmatching/characters/Character-combat-idle.md`
already used separate (ungrouped) identical case bodies and differed only at
function offsets `0x76`/`0x9a` and in the jump table: the animation-59 and
animation-73 handlers were laid out in swapped order.

Writing the `case 4:` handler before the identical `case 3:` handler fixes the
layout. In the RTL `csa` dump the cross-jump pass redirects the earlier of two
identical predecessors of the exit block and keeps the later one; each removed
edge's slot in the table-jump block's successor list is refilled from the end
of the list, and `bbro` then places the equal-frequency handlers in that
successor order. With `case 4` first, `case 3` survives and the handlers come
out in retail's 59, 73, 64 order. Every case still runs the same flag update
and animation call as retail.

No header, hint, inline assembly or register constraint is used. The function
and its 36-byte table are placed at their retail addresses; the NPC and
PlayerTest units, which compile Character as a dependency, no longer bind it
as an external Thumb function.

Full gate: `python -B tools/build.py --all` exited 0 with 5,503 function,
5,580 section and 181 region comparisons and no mismatch or skip.
