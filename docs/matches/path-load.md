# Path::Load exact match

```text
OK  _ZN4Path4LoadERKN7Structs4PathEPN3irr7collada15CColladaFactoryE  0x00300bc5  200 bytes
OK SECTION .path_load  0x00300bc4  200 bytes
```

Loads the level-object base (through the game's `CGameFactory` singleton),
allocates `count / 3` waypoints, converts each integer coordinate triple to a
float vector and frees the source coordinate array.

The earlier preferred form kept the native 200-byte extent but differed in
four bytes: the copy of the `data` pointer and the Z temporary took r3/r2
where retail has r2/r3. Reading the coordinates into named locals in the order
`z, x, y` before taking the waypoint reference changes the pseudo creation
order, and reload then assigns retail's registers:

```cpp
const int* coordinates = data.values + i * 3;
const int z = coordinates[2];
const int x = coordinates[0];
const int y = coordinates[1];
irr::core::vector3d<float>& waypoint = waypoints[i];
waypoint = irr::core::vector3d<float>(static_cast<float>(x), static_cast<float>(y), static_cast<float>(z));
```

`CGameFactory::getInstance` is declared weak by its mangled name, as already
done in Rocket.cpp, NPC.cpp and Transformation.cpp, which yields retail's GOT
load and `blx`. `LevelObject::Load` is bound to its retail Thumb address and
the division, allocation and conversion helpers to their PLT entries.

No header change, hint, inline assembly or register constraint is used.

Full gate: `python -B tools/build.py --all` exited 0 with 5,512 function,
5,589 section and 181 region comparisons and no mismatch or skip.
