# MenuManager::initMap exact match

`MenuManager::initMap()` matches all 428 retail bytes at Thumb address
`0x002e7165`, including relocations.

```text
OK  _ZN11MenuManager7initMapEv  0x002e7165  428 bytes
```

## Source form

`initMap` takes the following steps in order:

1. It sizes the map panel from the screen dimensions and sets the maximum
   zoom from the map texture width.
2. It resets the rotation and the screen origin.
3. It centres the map on the player position, or on the vehicle position
   when the player is driving.
4. It sets the target marker angle from the heading against the Y axis:
   `acosf` of the clamped cosine, negated when `front.X` is not positive.

Details that the retail bytes require:

- **Player front.** The player front is copied through a
  `const vector3d<float>` local and then assigned in X, Z, Y order. Retail
  loads the three components in that order on the player path. The vehicle
  path assigns the whole vector.
- **Length.** `sqrt` is declared `__attribute__((const))`, matching bionic's
  `__pure2` declaration.
- **Views.** `_positionMapOnPoint` takes a file-local `InitMapPoint`. The marker
  angle is written through a file-local `InitMapMarker` view.

No branch hint, inline assembly, register constraint or output edit is used,
and no header change.

## Verification

`python -B tools/build.py menu-manager-helpers` passes. The section and the
`f2d`, `sqrt`, `d2f` and `acosf` bindings are in the shared
`MenuManagerFocus.ld`. The `ai-startup-menustate` external is removed. A fresh complete build, `python -B tools/build.py --all`, exited 0 with 5,593 function, 5,680 section and 181 region comparisons and no mismatch or skip; the previous baseline was 5,589, 5,676 and 181.
