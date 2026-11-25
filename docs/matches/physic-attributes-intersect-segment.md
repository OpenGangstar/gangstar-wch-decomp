# PhysicAttributes::IntersectSegmentWithHeightMap exact match

```text
OK  _ZN16PhysicAttributes29IntersectSegmentWithHeightMapERKN3irr4core8vector3dIfEES5_RS3_S6_  0x0031da29  596 bytes
OK SECTION .physics_segment_height  0x0031da28  596 bytes
```

Intersects a segment with the first physics info's height map: it builds the
vertical plane through the segment, copies the info into a temporary, advances
the shared `s_currentUsed` counter and calls the detailed overload, returning
the hit fraction along the segment (1.0 when there is no height map or no hit).

This builds on the reviewed reconstruction in
`nonmatching/characters/PhysicAttributes-segment-heightmap.md` (plane3d model,
overload and static declarations), which laid out the failure return before
the success path.

`PhysicInfo` offset 4 holds the height-map scene node (the file already casts
it so). It is now a union of the original `unsigned int` and an
`irr::scene::ISceneNode*` member. Testing and copying it as a pointer lets
GCC's null-pointer branch prediction apply, which puts the failure block after
the success path as in retail; casting in the condition or a local pointer
variable is stripped and does not trigger it, and testing through a pointer
view while copying the integer prevented the two loads from being combined.
The layout of `PhysicInfo` is unchanged.

`PhysicAttributes.h` gains the `plane3d` forward declaration, the static
`s_currentUsed` and the detailed overload's declaration. (An additional
declaration of the unmatched `GetJumpHeight` changed the code of the matched
`GameObjectManager::GetMetatypeFromName` through GCC declaration ordering, so
it is not included.) The overload is bound to its retail Thumb address and
`sqrt`/`__aeabi_f2d`/`__aeabi_d2f` to their PLT entries. No hint, inline
assembly or register constraint is used.

Full gate: `python -B tools/build.py --all` exited 0 with 5,533 function,
5,614 section and 181 region comparisons and no mismatch or skip.
