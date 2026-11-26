# SpawnPoint::UpdateSpawnCenters exact match

`SpawnPoint::UpdateSpawnCenters()` matches all 848 retail bytes at Thumb
address `0x00307101`, including relocations.

```text
OK  _ZN10SpawnPoint18UpdateSpawnCentersEv  0x00307101  848 bytes
```

## Source form

The function places the six spawn centres (cars, parked cars and civilians,
inner and outer) along the camera's view direction, pushes the vehicle
centres further ahead when the player drives fast, and sets every centre's
height to the player's or the player vehicle's height.

Details that the retail bytes require:

- **Centres stored through a vector view.** Each centre is assigned as a
  whole through a `vector3d` reference to the centre global. Under
  `-fno-strict-aliasing` these stores may alias the direction vector, so
  partial-redundancy removal does not merge the scaled directions across
  centres, and retail's reloads remain.
- **Nested speed test.** The speed test is nested inside the vehicle test,
  which changes which register copy CSE treats as the zero offset and gives
  retail's allocation.
- **One reused centre variable.** A single `center` variable is reassigned
  for each centre. The SSA version reuse that follows gives retail's operand
  order in the parked-car centre sums.

No branch hint, inline assembly, register constraint, output edit or header
change is used. The other SpawnPoint.cpp functions keep their bytes.

## Verification

`python -B tools/build.py ai-startup-spawnpoint` passes. A fresh complete
build, `python -B tools/build.py --all`, exited 0 with 5,626 function, 5,710
section and 180 region comparisons and no mismatch or skip; the previous
baseline was 5,624, 5,710 and 180.
