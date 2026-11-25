# Character::ready exact match

```text
OK  _ZN9Character5readyEf  0x002f26ad  284 bytes
OK SECTION .character_ready  0x002f26ac  284 bytes
OK SECTION .character_ready_table  0x0041bd18  36 bytes
```

When the specific animation 165 is playing, picks the ready animation for the
held weapon type through a nine-entry switch (resetting the punch/kick combo
for bare hands).

The earlier archived candidate differed only by the animation-138 and -145
handlers being laid out in swapped order (offsets `0x96`/`0x106` and the jump
table). The same mechanism as `Character::goToCombatIdle`
(`docs/matches/character-combat-idle.md`) applies: writing the identical
`case 4:` handler before `case 3:` makes the cross-jump pass keep `case 3`,
which changes the table-jump block's successor order and therefore
bb-reorder's placement of the equal-frequency handlers.

No header, hint, inline assembly or register constraint is used. The NPC and
PlayerTest units, which compile Character as a dependency, no longer bind it
as an external Thumb function.

Full gate: `python -B tools/build.py --all` exited 0 with 5,507 function,
5,584 section and 181 region comparisons and no mismatch or skip.
