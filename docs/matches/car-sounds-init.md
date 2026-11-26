# CarSounds::Init exact match

`CarSounds::Init(CarSoundSettings*)` matches all 1,032 retail bytes at Thumb
address `0x0035047d`, including relocations.

```text
OK  _ZN9CarSounds4InitEP16CarSoundSettings  0x0035047d  1032 bytes
```

## Source form

`Init` copies the car sound settings, allocates the engine, turbo and
auxiliary sound tables and their fades, sets the initial load and gear
state, and sets up the RPM filter and the on/off cross-fade gains.

Details that the retail bytes require:

- **Field names.** `CarSoundCallbacks.h` names two placeholder fields of
  `CarSounds`: `unknown32` becomes an `int`, and the float at offset 56 is
  named `filterFrequency`. The layout is unchanged, and `Vehicle.cpp` and
  `GS3DStuff.cpp`, which include the header, keep their bytes.
- **Load before the first store.** The initial load is read from the
  settings before the zero store to offset 32; under `-fno-strict-aliasing`
  the scheduler cannot move that load past the store.
- **SSA name reuse in the table loops.** Each of the five table loops gets a
  new scaled-index temporary from the loop optimiser, which reuses the most
  recently freed SSA version; a later fold puts the lower version first in
  the address. The chained gear assignment and setting `previousLoad`
  before clearing `unknown32` leave the free list in the state that gives
  retail's address operand order in every loop.

No branch hint, inline assembly, register constraint or output edit is used.
The other CarSounds.cpp functions keep their bytes.

## Verification

`python -B tools/build.py car-sound-callbacks` passes. A fresh complete
build, `python -B tools/build.py --all`, exited 0 with 5,627 function, 5,710
section and 180 region comparisons and no mismatch or skip; the previous
baseline was 5,626, 5,710 and 180.
