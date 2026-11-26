# SlideControl and WantedMeter constructor exact matches

Both HUD constructors match all their retail bytes, including relocations.

```text
OK  _ZN12SlideControlC1EP7ASpriteiiNS_16SlideControlModeE  0x0032b1f5  492 bytes
OK  _ZN11WantedMeterC1EP7ASpritei  0x0032c961  272 bytes
```

The C2 (base) constructors are aliases of C1 at the same address.

## Shared cause

Both constructors finish by filling a touch rectangle: left, top, the right
edge computed as `left + width` with a soft-float add, and the bottom edge.
Retail emits the float add first and then the three stores, with the
height load issued before the add and kept live across the call. Earlier
forms always had GCC's expression replacement move the add into the store
of the right edge, which put the other stores before the call.

## Source form

```cpp
float right = width;          // integer width converted to float
const int height = ...;       // height loaded before the add
right = left + right;         // same variable: the conversion is not folded in
coordinates[2] = right;       // stored again below
coordinates[0] = left;
coordinates[1] = top;
coordinates[2] = right;
coordinates[3] = top + (float)height;
```

- Reassigning `right` keeps the width conversion at its own statement.
- Loading the height before the add keeps it in a register across the call
  (retail's `r4`), which also restores retail's assignment of `this` and the
  track pointer.
- Storing the right edge twice gives the add two uses, so it stays at its
  definition and the stores follow it in retail's order. The first store is
  dead and is removed by flow; no code is emitted for it. Source comments
  explain the form.

Behaviour is unchanged. No branch hint, inline assembly, register
constraint, flag change, output edit or header change is used. The linker
scripts place the new constructor sections at their retail addresses
(including the SlideControl touch-thunk unit, which links the same object)
and provide the needed soft-float and `operator new` entries.

## Verification

`python -B tools/build.py sdk-startup-slidecontrol`,
`slidecontrol-touch-thunk` and `sdk-startup-wantedmeter` pass. A fresh
complete build, `python -B tools/build.py --all`, exited 0 with 5,654
function, 5,713 section and 180 region comparisons and no mismatch or
skip; the previous baseline was 5,652, 5,713 and 180.
