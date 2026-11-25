# Character::initPhysic exact match

```text
OK  _ZN9Character10initPhysicEv  0x002f4465  456 bytes
OK SECTION .character_init_physic  0x002f4464  456 bytes
OK SECTION .character_polygon_d1  0x002df3f4  36 bytes
OK SECTION .character_polygon_d0  0x002df628  44 bytes
OK SECTION .character_polygon_table  0x004a8ac8  16 bytes
```

Creates the character's Box2D body (once): a physics-attributes object if
missing, the vehicle's physics info when seated, a body at the character's
position (scaled by 1/100) and a circle shape of radius 0.5 whose collision
category is 2 for the player and 4 for others, with the character's pool index
as the group. The filter is kept on the character, and the body's user data
links back to the character and its skinned mesh.

This builds on the two earlier reviewed reconstructions recorded in
`nonmatching/characters/Character-initPhysic-sdk-reuse.md` and
`Character-initPhysic-filter-aggregate.md`:

- Box2D 2.0.1 shape definitions (zlib licence, marked as altered) live in
  `vehicles/VehicleBodyShapes.h`; `b2FilterData` moves to
  `core/PhysicsFilterData.h`; `Physics.h` gains `b2Vec2::SetZero`,
  `b2Body::CreateShape` and the `PhysicsBodyData` constructor and fields.
- The character's collision filter is one `b2FilterData collisionFilter`
  (replacing `LevelObject::collisionCategory` and `Character::collisionMask`/
  `collisionGroup`; the layout is unchanged) and is copied as an aggregate.

The two remaining differences were closed here:

- Setting both `categoryBits` and `maskBits` in each branch of the player test
  gives each branch its own reloads, which cross-jumping later merges; the
  join block's reload for `groupIndex` then survives, supplying retail's
  missing two code bytes and its GOT register (fp).
- Assigning the body definition's zero damping and `isBullet` fields
  explicitly after construction lets dead-store elimination remove the
  constructor's copies, reproducing retail's store order.

The `b2PolygonDef` destructors and vtable emitted by the unit are placed at
their retail addresses. `PhysicAttributes(int, b2Body*)`, `b2World::CreateBody`,
`b2Body::CreateShape` and `b2Body::SetMassFromShapes` are bound to retail Thumb
addresses and `operator new` to its PLT entry. No hint, inline assembly or
register constraint is used.

Full gate: `python -B tools/build.py --all` exited 0 with 5,530 function,
5,608 section and 181 region comparisons and no mismatch or skip.
