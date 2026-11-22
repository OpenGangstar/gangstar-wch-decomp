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


## Subsequent source corrections and current candidate

A bounded signed-counter trial changes only the light-node loop's local index
from unsigned int to int. The array contains four-byte pointers, so valid
`used <= allocated <= SIZE_MAX / 4` bounds keep every reached index representable
as int. The unsigned array-size comparison and all accesses retain their values.
This restores the original counter-copy pattern, exact 2,576-byte extent, and
all switch destinations. It is a valid reconstruction choice, not proof of the
original local variable's declared type.

Case 12 also contained a confirmed wrong singleton call in all six historical
forms. The original final literal is `0x2d1c`; adding PIC base `0x004b0048` gives
GOT slot `0x004b2d64`, whose value is `0x002dba05`, the already matched
`WantedLevelManager::getInstance()`. The earlier SoundManager call instead uses
GOT slot `0x004b4994`, targeting `0x002d40cd`. Only the case-12 terminal call is
corrected; genuine case-13 SoundManager operations remain.

With both corrections and the world snapshot, the current candidate occupies
exactly 2,576 bytes but still differs at four byte positions: offsets `0x1d8`,
`0x1dc`, `0x202`, and `0x204`. They encode the city-static address register and
the order of two loads before the scene-node query. The target and full target
section remain unmatched. Its linked SHA-256 is
`f45a3a21d400410e74bdd8256a9322022e6fab23d0f8189c401fd1e418d47c63`.

The switch and 132 selected support/section checks pass; the separate full
target-section check fails. All 147 available existing function selectors pass,
and 112 other emitted function payloads remain unchanged. An isolated explicit
query-receiver temporary produced identical target bytes and was stopped. Keep
the simpler corrected candidate as the reference. The global Quaternion
float-constructor annotation, Cash regression and incomplete dependent closure
remain unresolved prerequisites; none of these scoped results supplies the
current complete repository gate or matching credit.


A separate current-type prerequisite trial removes the rejected global
constructor annotation using an explicitly documented no-initialization SDK tag
and the existing quaternion setter. All ten layout assertions compile, only the
pending load definition is added, and all 112 existing object-function payloads
remain unchanged. However, this adaptation emits 2,568 target bytes. The strict
linker correctly stops with `arm-eabi-ld: load native extent`; no candidate ELF
exists and no native-image comparison is claimed for it. The shared-header and
dependent full-repository gates remain unproven. Both the four-byte legacy
candidate and this unapplied current-type proposal are retained separately.
