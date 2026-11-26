# Menus::ServiceCarRental::Update exact match

`Menus::ServiceCarRental::Update()` matches all 816 retail bytes at Thumb
address `0x002eb12d`, including relocations.

```text
OK  _ZN5Menus16ServiceCarRental6UpdateEv  0x002eb12d  816 bytes
```

## Source form

When the player confirms a rental, the function creates the chosen
vehicle, finds the nearest suitable car spawn point to the player (or to
the player's vehicle), places and activates the vehicle there, registers it
as rented, plays the confirmation sound and returns to the map menu.
Otherwise it plays the cancel sound and clears the selection.

Details that the retail bytes require:

- **Vehicle position override.** The override of the search position by the
  player's vehicle position is written as an `if` with an empty then-branch
  and the assignment in the `else`. That places the vehicle position block
  after the search loop in the instruction order reload sees, so its
  round-robin choice of spill registers before the loop matches retail.
  The behaviour is the same as the direct condition.
- **Definition without header changes.** The vehicle offers, spawn points,
  octree list and player flags are read through file-local views, and the
  private and undeclared methods are called through their mangled names.
  The MenuState translation unit's other functions, including the
  declaration-sensitive `ServiceCarRental::Notify` and
  `ServiceMissions::GotFocus`, keep their bytes.

No branch hint, inline assembly, register constraint, output edit or header
change is used.

## Verification

`python -B tools/build.py ai-startup-menustate` passes. A fresh complete
build, `python -B tools/build.py --all`, exited 0 with 5,630 function, 5,713
section and 180 region comparisons and no mismatch or skip; the previous
baseline was 5,629, 5,713 and 180.
