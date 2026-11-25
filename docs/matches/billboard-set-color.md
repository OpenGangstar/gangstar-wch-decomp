# CustomBillboardSceneNode::setColor exact match

`CustomBillboardSceneNode::setColor(ISceneNode*, SColor)` matches all 232 retail
bytes at Thumb address `0x002f7ce9`, and its strict section ends at the retail
extent.

```text
OK  _ZN24CustomBillboardSceneNode8setColorEPN3irr5scene10ISceneNodeENS0_5video6SColorE  0x002f7ce9  232 bytes
OK SECTION .billboard_set_color  0x002f7ce8  232 bytes
```

## Source form

For mesh and animated-mesh nodes (types `'daem'`/`'daes'`), the function writes
the colour into material 0's colour at +84. It then updates that material's
blend and dirty flags, like the matched `GS3DStuff::SetColor`. For any other
node type it recurses into every child with the same colour. Retail keeps
`this` live in `r8` for the recursive call.

The earlier form differed in 8 bytes, which came from two things together:
`switch` on the node type, and locals declared as b, a, g, r. Copying the
matched `GS3DStuff::SetColor` shape reproduces the channel registers and the
order of the byte stores for the recursive call. That shape is: locals declared
a, b, g, r, and an `if`/`||` on the node type.

The function is an `extern "C"` definition of the retail mangled name. Declaring
the member in `CustomBillboardSceneNode.h` perturbs the matched
`GameObjectManager::GetMetatypeFromName` through declaration UIDs, so no header
declaration is used. Lock.cpp calls it through the same mangled-name
declaration.

No header change, branch hint, inline assembly, register constraint or output
edit is used.

## Verification

`python -B tools/build.py --all` exited 0 with 5,553 function, 5,636 section
and 181 region comparisons and no mismatch or skip. Unit tests, repository
checks and progress checks pass.
