# PlayerTest::PlayerTest(b2World*) exact match

The `PlayerTest` constructor matches all 872 retail bytes at Thumb address
`0x00303701`, including relocations. The complete-object (C1) and
base-object (C2) symbols share the body, as in retail.

```text
OK  _ZN10PlayerTestC1EP7b2World  0x00303701  872 bytes
OK  _ZN10PlayerTestC2EP7b2World  0x00303701  872 bytes
```

## Source form

After the `Character(8)` base construction, the constructor:

1. clears and initialises its player state in ascending field order: cash
   10000, context word -1, context records, photo targets and the two context
   arrays;
2. registers itself as `s_player` and sets the movement mode;
3. creates its physic attributes;
4. builds a dynamic circle body (radius 0.5, density 1, friction 0.3) in the
   given world and sets a 0.01 mass;
5. stores the world and the creation time;
6. sets 300 health and the player object type (254, registered as type 8 in
   `LevelObject::s_type`);
7. initialises the factions.

Details that the retail bytes require:

- The movement-flag update is two statements (`>> 8`, then `<< 8 | 1`). A
  single masked expression folds into `bics`.
- The two eight-byte context arrays are cleared with `__builtin_memset`.
- The body definition fields are set explicitly, as in `Character::initPhysic`.
  The position is cleared with `b2Vec2::SetZero()`, which stores x before y.
  Assigning a `b2Vec2(0, 0)` temporary stores y first.
- The mass data is filled in inertia, centre, mass order.

`PlayerTest.h` names the fields the constructor writes; previously they were
opaque byte arrays, and the layout is unchanged.

No branch hint, inline assembly, register constraint or output edit is used.

## Linking

The Box2D shape-definition destructors and vtables, and the `IMapTrackable`
vtable, are linkonce copies that the new includes emit in this object. They
are placed at their retail addresses so the GOT region stays exact.
`PhysicAttributes`' constructor, the `b2World`/`b2Body` calls and
`Factions::init` are bound as Thumb functions.

## Verification

`python -B tools/build.py ai-startup-playertest` passes every function, section
and GOT check. A fresh complete build, `python -B tools/build.py --all`, exited 0
with 5,583 function, 5,666 section and 181 region comparisons and no mismatch or
skip; the previous baseline was 5,581, 5,665 and 181. The `PlayerTest.h` field
names change no other matched function.
