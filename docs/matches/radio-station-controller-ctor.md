# RadioStationController constructor exact match

`RadioStationController::RadioStationController()` matches all 604 retail
bytes at Thumb address `0x00352335`, including relocations. The
complete-object and base-object constructors share the same code.

```text
OK  _ZN22RadioStationControllerC1Ev  0x00352335  604 bytes
```

## Source form

The constructor opens the radio station map and the advertisement list,
reads the stations and their songs and jingles through a data stream, and
initialises the selection state.

Details that the retail bytes require:

- **Stack protector.** Retail compiled this translation unit with
  `-fstack-protector`: the constructor has a stack canary. The manifest
  now passes the flag, as many other manifests do. No other function in
  the unit changes.
- **Constant numbering.** The constructor's two aggregate initialisers
  become compiler constants named `C.N`, where N counts the compiler's
  temporaries in parse order. Partial-redundancy removal creates the
  spilled reaching registers in expression-hash order, and the hash of a
  symbol depends on its name, so N decides the spill-slot order. The
  constructor is defined after the translation unit's static
  initialisation, which gives constant numbers in the window that hashes
  into retail's order. This is sensitive to code added earlier in the file.
- **Placement.** The constructor, its two constants, the path strings and
  the local copy of the `DataStream` destructor are placed at their retail
  addresses.

No branch hint, inline assembly, register constraint, output edit or header
change is used. The other RadioStationController.cpp functions keep their
bytes.

## Verification

`python -B tools/build.py string-startup-radiostationcontroller` passes. A
fresh complete build, `python -B tools/build.py --all`, exited 0 with 5,622
function, 5,709 section and 180 region comparisons and no mismatch or skip;
the previous baseline was 5,621, 5,709 and 180.
