# GS3DStuff::load world snapshot: unmatched

The pending function `_ZN9GS3DStuff4loadEiRi` starts at retail Thumb
`0x002dfb15` and occupies 2,576 bytes. Its assembly marker remains in the queue.

In case 9, retail code reads `PhysicAttributes::s_world` before allocating the
PlayerTest object, retains the pointer across allocation, and passes that saved
value to the constructor. The six earlier candidates instead read the global
after allocation. The isolated correction is:

```cpp
b2World* const world = PhysicAttributes::s_world;
playerTest = new PlayerTest(world);
```

Retail performs the world load at `0x002e0220`, allocation at `0x002e0222`, the
saved-pointer move at `0x002e0226`, and construction at `0x002e022a`. The corrected
candidate preserves this ordering four bytes earlier in the image. Case 4 is
still four instruction bytes shorter; correcting the snapshot does not resolve
that independent induction-variable discrepancy.

One GCC 4.2.1 compile/assemble/link control produced a 2,572-byte function and
section, so the exact native extent check fails. The checker prints:

```text
MISMATCH  _ZN9GS3DStuff4loadEiRi  0x002dfb15
  expected : 56 46 4d 46 44 46 f0 b4 bf 4a 99 b0 0c 1c 91 46
  actual   : 56 46 4d 46 44 46 f0 b4 be 4a 99 b0 0c 1c 91 46
  differs at 0xc
```

The full section and switch table also fail. There are 1,914 differing common
positions and four missing bytes; the four-byte size gap is not a claim that
only four bytes differ. The linked candidate SHA-256 is
`3c6ce1b87f996323fd6da6c3c9b11f66983e312375386722b9ffc1a305831cff`.

All 147 available existing function selectors pass in that private image, and
112 other emitted function payloads remain unchanged. This is not the current
complete repository gate. The retained private Quaternion `always_inline`
prerequisite previously regressed Cash, and dependent LevelObject placement and
remaining header-consumer checks are unresolved. No prerequisite, candidate,
progress credit or assembly-marker change is integrated. Future work must solve
the independent case-4 issue and provide coherent preservation proof before this
function can be accepted.
