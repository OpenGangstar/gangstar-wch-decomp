# Vehicle::setupSceneNode exact match

`Vehicle::setupSceneNode(int, irr::scene::ISceneNode*, int, void**)` matches all
736 retail bytes at Thumb address `0x00309a4d`, including relocations.

```text
OK  _ZN7Vehicle14setupSceneNodeEiPN3irr5scene10ISceneNodeEiPPv  0x00309a4d  736 bytes
```

## Source form

After the `LevelObject` base setup, the function performs these steps:

1. Applies the vehicle's two material colours.
2. Stores the root scene record.
3. Builds and attaches the two configured Collada animators, releasing its
   own references.
4. Fills the parameter table with the door, body, interior and wheel scene
   nodes and the two car textures.
5. Detaches the shadow node to the scene root, after setting its rendering
   layer, colours and material flags.
6. When a smoke dummy exists, finds or creates the smoke and fire effect pools.

The scene-node, texture and effect names are file-local arrays, which is the
same convention used elsewhere in the unit. Fourteen of them are contiguous in
retail at `0x0041f5c0`. `shadow-node` is shared with the character shadow name
at `0x0041bcc4`. The linker script places both groups at those addresses, so
every GOT-relative literal in the function's pool resolves as in retail.

`CRootSceneNode`'s record field is read through a file-local view.
`CGameFactory::getInstance` and `IReferenceCounted::drop` use the existing weak
bindings. `LevelObject::setupSceneNode` is bound as a Thumb function.

No branch hint, inline assembly, register constraint or output edit is used,
and no header change. Comparing every other text section of the unit before
and after the addition shows identical bytes and relocations.

## Verification

`python -B tools/build.py vehicle-cleanup` passes every function and section
check. A fresh complete build, `python -B tools/build.py --all`, exited 0 with
5,580 function, 5,664 section and 181 region comparisons and no mismatch or
skip; the previous baseline was 5,579, 5,663 and 181.
