# LevelObject::CastRay exact match

`LevelObject::CastRay(vector3df const&, vector3df const&, vector3df&,
vector3df&, LevelObject*&, bool)` matches all 1504 retail bytes at Thumb
address `0x003179d5`, including relocations.

```text
OK  _ZN11LevelObject7CastRayERKN3irr4core8vector3dIfEES5_RS3_S6_RPS_b  0x003179d5  1504 bytes
```

## Source form

The function casts a Box2D ray through the world, then for each hit tests
the object's mesh, bounding box or stored height range against the ray
height, keeping the closest hit.

Details that the retail bytes require, each commented in the source:

- **Empty-then non-node test.** `if (lower == (upper = upperHeight)) {} else
  {...}` changes predecessor-edge order so cross-jumping merges the shared
  fraction-load blocks into the fall-through first, as retail does.
- **Goto dispatch.** The node/detailed/spawn tests jump to the mesh and box
  paths, so the RTL order is node tests, non-node, mesh, box. That order
  gives retail's reload registers; the test order and short-circuits are
  unchanged.
- **Two branch hints.** `__builtin_expect` on the non-node continue and on
  the final return restore retail's block order, which the goto dispatch
  would otherwise change.
- **Height multiply.** `height += (falling * 50.0f).Z;` gives retail's
  argument order for the multiply call.
- **Fraction copy.** In the box path, the fraction is copied before the
  direction X load so it stays live in r4, which gives the reload retail's
  registers.

## Integration

`MeshCollision`'s constructor and ray test are bound as external Thumb
functions, and the shared navigation-section script places the function at
its retail address for every unit that links the LevelObject object.
