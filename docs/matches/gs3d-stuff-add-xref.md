# GS3DStuff::AddXRef exact match

`GS3DStuff::AddXRef(irr::scene::ISceneNode*)` matches all 824 retail bytes at
Thumb address `0x002deebd`, including relocations.

```text
OK  _ZN9GS3DStuff7AddXRefEPN3irr5scene10ISceneNodeE  0x002deebd  824 bytes
```

## Source form

The function resolves a Collada instance node, builds its scene, applies
material, colour and culling settings, sets up level-of-detail nodes and
creates the static collision bodies, attaching billboard props through a
separate path.

Details that the retail bytes require:

- **Placement.** The definition sits just before `checkVehicleProximity`.
  Placed after it, it changes that function's stack-slot order.
- **Billboard path.** The billboard arm is reached by a real `goto` and sits
  after `lod->drop()` inside the LOD block, with its own copy of the attach
  tail. The non-billboard arm is the fall-through of
  `if (getProperty(...) && atoi(value) == 1)`, which jump threading moves to
  the end of the function. In those two positions both copies of the tail get
  the same reload register, so crossjumping merges them after reload, giving
  retail's single tail and branch target.
- **Forced label.** The billboard label's address is taken (labels as
  values), so the block is not merged away before that point.
- **gcse padding.** A dead differently-typed store of an unsigned product
  sets the gcse PRE hash-table size, which orders the GOT and frame spill
  pseudos as retail does. Flow removes the store.

## Integration

`setLODNodesPosition`, `setLODNodesRotation` and `CreateStaticBodies` are
bound as external Thumb functions in the GS3DStuff manifest. The seven units
that link `gs3d-stuff.o` no longer bind AddXRef externally and place its
section at the retail address.
