# Vehicle::Load exact match

`Vehicle::Load(Structs::Car const&)` matches all 1368 retail bytes at Thumb
address `0x0030ff41`, including relocations.

```text
OK  _ZN7Vehicle4LoadERKN7Structs3CarE  0x0030ff41  1368 bytes
```

## Source form

After the `LevelObject` base load, the function:

1. copies about forty tuning, animation, camera and health fields from the car
   record;
2. derives the weight from the mass and the maximum speed in metres per second;
3. when the vehicle owns its scene node, sets the scene node up:
   - applies the material colours and Euler rotation;
   - builds and attaches the door animators;
   - looks up the door, body, interior, wheel and shadow nodes and the two
     car textures, using the file-local names already placed for
     `setupSceneNode`;
   - creates the body when flagged, and attaches the shadow to the scene root;
4. loads the explosion animation and creates the car sound state for the
   record's engine type;
5. finally chooses the driver metatype by vehicle metatype.

The `Structs::Car` layout already fits every field offset. A small file-local
view covers two Vehicle words that the header still declares with other types.

### The null-checked root cast

Retail reads the root record through a null-adjusted cast of the scene node:
`cmp; beq; subs #100`, followed by one shared load. Two source forms fail:

- **Plain `static_cast`:** this turns the null result into the constant 0,
  which adds an out-of-line block and 16 bytes.
- **Triangle forms:** these let CSE carry two offset constants across, which
  enlarges the frame.

The matching form spells the cast out explicitly. A ternary loads the record
pointer in each arm, with the null arm first:
`!node ? view(node)->record40 : view(static_cast<CRootSceneNode*>(node))->record40`.

- Loading in the arms keeps the load ahead of the store address.
- Putting the null arm first makes it the jumping arm, which post-reload
  cross-jumping merges into the other arm's tail.

An equivalent if/else gives the same bytes. Behaviour is unchanged: the null
case still dereferences the record field at address `0 + 40`, as the plain cast
does.

No branch hint, inline assembly, register constraint or output edit is used.

## Linking

The explosion asset name is a file-local array placed at its retail address
`0x0041f714`. The base load, the car sound constructors and the
double-precision helpers are bound as Thumb functions or PLT stubs.

## Verification

`python -B tools/build.py vehicle-cleanup` passes every function and section
check. A fresh complete build, `python -B tools/build.py --all`, exited 0 with
5,587 function, 5,674 section and 181 region comparisons and no mismatch or
skip; the previous baseline was 5,586, 5,672 and 181.
