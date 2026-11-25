# ContactListener::Persist exact match

`ContactListener::Persist(b2ContactPoint const*)` matches all 604 retail bytes
at Thumb address `0x0031d7a1`, including relocations.

```text
OK  _ZN15ContactListener7PersistEPK14b2ContactPoint  0x0031d7a1  604 bytes
```

## Source form

For a persisting contact between an NPC and the world, `Persist` pushes the
NPC's avoidance vector along the contact normal. It then either moves the NPC
away or sends it back to its destination. The first-body and second-body
cases are handled separately.

Details that the retail bytes require:

- **Movement-category test.** It is a file-local `static inline bool
  IsMoving(unsigned int)` made of if-returns, which raises the category
  block's predicted frequency.
- **Avoidance vector.** The else arm builds it as one `vector3d` from the
  normal. The NPC position is read through the `LevelObject*`, which gives
  retail's load and store order.
- **The one documented hint.** The second-body path keeps
  `__builtin_expect(!first && secondData, 0)`. `secondData` is always set
  when `second` is, so the extra term does not change behaviour.
  - bb-reorder needs the second path below its 500-per-mille trace threshold
    but above the first path's equals-true block. That puts that block in
    retail's far tail.
  - Without the hint, GCC's pointer and early-return heuristics place the
    path too high. No hint-free form gets the layout.

## Access to private members

- **`NPC.h`:** makes `ContactListener` a friend, for the NPC's movement
  fields. The menu-state and menu-widget units still pass with it.
- **`Character::destination`:** this field is private, so it is read
  through a file-local view struct with the field at `+92`. A friend
  declaration in `Character.h` changes `ServiceCarRental::Notify`, and a
  `char*` offset view changes this function's code.

`vector3d::equals` is declared weak, as it is in retail (`STB_WEAK`).

No inline assembly, register constraint, flag change or output edit is used.
The other PhysicAttributes.cpp functions keep their bytes.

## Verification

`python -B tools/build.py ai-startup-physicattributes` passes. A fresh complete build, `python -B tools/build.py --all`,
exited 0 with 5,599 function, 5,703 section and 180 region comparisons and no
mismatch or skip; the previous baseline was 5,598, 5,702 and 180.
