# ContactListener::Add exact match

`ContactListener::Add(b2ContactPoint const*)` matches all 2384 retail bytes at
Thumb address `0x00320351`, including relocations. Its vtable (`0x004abd18`) is
also placed and compared. The other sections of `PhysicAttributes.cpp` are
unchanged.

## Source form

The function handles Box2D contacts between two level objects. It applies
vehicle-against-NPC hits, player kills by vehicle, vehicle collisions and
rocket explosions, and raises the related player events. Details that the
retail bytes require, each commented in the source:

- **Zero-extended player flag.** The flag is copied through an `unsigned char`
  local. TER then nests the comparison as `(int)(uchar)(x != 0)`, which expands
  through a QImode store-flag and keeps retail's `lsls/lsrs #24`.
- **Vehicle copies.** A ternary sets `secondVehicle` on both metatype arms, and
  `hit = secondVehicle` feeds the raise path. Identical `raise` arms give the
  arm-1 store a use, so DSE keeps it.
- **Second-NPC type read.** The type is read through `NPC*`, so PRE does not reuse
  the vehicle-test value and reload reuses `r0`/`r1`.
- **Allocation hints.**
  - `best` is declared before `direction`, which gives retail's stack slots.
  - `__builtin_expect` on two category tests and on both negation tests breaks
    a three-way priority tie for `side.X`/`side.Y`/product.
  - Identical arms around `onObjectKilled`, under a two-compare expect
    condition, advance the reload register rotation by two. Crossjump merges
    the arms, so they emit no code.
- **Block-order hints.** Expect-wrapped dead tests jump, in blocks where the
  condition is known, to labels in other blocks. Each adds about one unit of
  profile frequency, which breaks a basic-block reordering tie the way retail
  does. Address-taken label statements keep a block split where retail splits
  it, without code. DOM folds every dead test.
