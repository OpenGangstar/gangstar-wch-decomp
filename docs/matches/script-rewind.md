# Script::rewind exact match

```text
OK  _ZN6Script6rewindEv  0x003399f1  656 bytes
OK SECTION .script_rewind  0x003399f0  656 bytes
```

Undoes a script's effects on the objects it touched. For an unfinished
script it resets an active race, then walks the script's
`map<LevelObject*, int>` of action flags and reverses each one: disables
spawned objects (keeping the player's current car alive), removes highlights
and minimap entries, re-locks or unlocks shops, restores the wanted level,
clears kill tags on vehicles and NPCs, lifts the weapon limit, removes placed
items and leaves cinematic/locked-camera states (restoring the player camera).
It then clears the action map and resets the command cursor, source and
drive-quality gauge.

- The map walk uses the file's STLport layout view with a small iterator type
  compared through `operator!=` (end iterator on the left), which gives
  retail's loop without a copied header. `_Rb_global<bool>::_M_increment` is
  declared weak by its mangled name, so it is called through the GOT with
  `blx` as in retail.
- Shop unlock/lock is an `else if`; the kill-tag clear switches on the object
  type (vehicle out of line, NPC inline).
- The in-car test compares `flags240 & 0x400` held in a local with `==`,
  keeping retail's `and`/`cmp`; the camera-state test is written
  `flags & (0x200 | (flags & 0x400))`, equivalent to `flags & 0x600`, because
  that is the form whose code matches retail (other spellings fold to a
  single mask test).
- `ScriptManager::setState` and `Script::s_driveBadPoints` are reached through
  local mangled-name declarations (neither is declared in a header). The
  file gains includes for the classes it calls.

Retail-only callees are bound to retail Thumb addresses and `__aeabi_fcmpgt`
to its PLT entry. No header change, hint, inline assembly or register
constraint is used.

Full gate: `python -B tools/build.py --all` exited 0 with 5,534 function,
5,615 section and 181 region comparisons and no mismatch or skip.
