# Character filter aggregate: ABI-compatible candidate, still unmatched

This candidate remains **unmatched** at native Thumb `0x002f4465`.
It emits 452 versus 456 native bytes. The current decompilation and all
assembly markers stay unchanged. Source baseline: main PR #746,
`7fcefedd0e5ceb4358967c234de717c8ea5dbd2b`.

## New evidence and legal object layout

Native Init copies all three filter halfwords from the shape into Character
at offsets 50, 52 and 54. The old individual field assignments let the compiler
forward the known mask constant and produced a 124-byte frame versus native 116.
An ordinary b2FilterData aggregate copy naturally emits the three observed
halfword loads. The ABI model places that six-byte member in Character rather
than splitting its category into the provisional LevelObject field and its
mask/group into two Character fields.

Removing the unused provisional base category leaves a non-POD base data prefix
ending at byte 50. The actual ARM GCC ABI permits the two-byte-aligned Character
filter to reuse its base tail padding. This requires no packing, overlay,
register pin, artificial padding or reinterpret cast. The layout probe compares
all five currently modeled direct derived classes before compiling the caller.
All twenty measured sizes/offsets agree exactly; the JSON ledger retains them.
Sizes remain 52 bytes for LevelObject, 296 for Character, 1,012 for Vehicle,
124 for Weapon, 120 for Rocket and 84 for Transformation. The filter fields
stay at offsets 50/52/54; Character facing, collisionBody and vehicle stay at
56/180/188, and Vehicle driver stays at 696. Other derived first fields stay
unchanged.

The separate layout-only diagnostic uses GCC -fno-access-control to inspect
protected/private offsets; the game candidate uses the unchanged production
compiler flags with normal access checking. No such diagnostic flag enters a
matching profile. Original source ownership is still an inference; equal layout
alone cannot prove the exact original class declarations.

The existing matched resetCollisions body receives only the three corresponding
field-access renames. Its native bytes remain exact in the owning profile.
The new dedicated filter header moves the same existing three-member definition;
all other SDK interfaces and the production body-definition constructor remain.

## Reproduction and native comparison

Apply the earlier source/link prerequisites in an isolated baseline checkout,
then the new delta:

```powershell
git apply nonmatching/characters/Character-initPhysic-sdk-reuse.patch
git apply nonmatching/characters/Character-initPhysic-sdk-reuse-link.patch
git apply nonmatching/characters/Character-initPhysic-filter-aggregate.patch
python nonmatching/characters/Character-initPhysic-sdk-reuse-probe.py --baselib C:/path/to/libsanangeles.so
python tools/build.py --baselib C:/path/to/libsanangeles.so ai-startup-character
```

The unchanged public primary-object probe exits **3**. Raw target SHA-256:
`3382c333476bac83dd9b7eb8ec4708a8a78859be34397ed9a8712bae99291814`.
The normal native-address build exits **1**; the target and its complete section
fail, while all **114 existing functions and 33 existing section/region checks
pass**, including the existing resetCollisions and SDK definitions. The
InitWorld dependency also passes with the production constructor.

Exact standalone comparison output from the same linked image:

```text
MISMATCH  _ZN9Character10initPhysicEv  0x002f4465
  expected : 4d 46 44 46 f0 b4 b4 22 63 49 86 58 9d b0 8b 46
  actual   : 4d 46 44 46 f0 b4 b4 22 62 49 86 58 9d b0 89 46
  differs at 0xe
```

The new frame is 116 bytes, the body is at SP+44 and the shape at SP+0, agreeing with native.
The real allocated target is 452 bytes at its native address, with linked SHA-256
`a9975024a4e14ab822f499c16a7b480ab022873982bbb4f9547f339f4a587ac0`.
All 886 frozen source/configuration/tool hashes remain stable. Four code bytes
remain absent; GOT/register scheduling also differs. A maximum-span guard
prevents overlap and both complete comparison failures remain mandatory.
There is no padding, absolute masking of this definition or progress credit.
The existing public probe reproduces the raw hash and intentional exit 3. The
three-patch prerequisite/delta sequence and both alternative SDK source deltas
reconstruct the measured text in a separate isolated checkout. The JSON ledger
also preserves the layout probe source.

## Bounded SDK transfers and rejection

The retail b2_version object reports 2.0.1; see ENGINE.md. The cached licensed
original 2.0.1 body-definition constructor has a different zero-initialization
order. One transfer of that original constructor plus its required vector API
still emits 452 bytes. Transferring the already measured caller Set API also emits 452 bytes.
Each variant preserves 886 frozen inputs, and their complete raw hashes and
source deltas are retained in the JSON ledger. Original license notices are
preserved in the constructor-header deltas.

The combined transfer's normal build correctly stops on an **existing**
InitWorld dependency failure before linking Character. Actual exit: **1**.
No Character linked image or old owning closure exists for that transfer:

```text
MISMATCH  _ZN16PhysicAttributes9InitWorldEv  0x0031a951
  expected : 03 95 01 95 04 95 05 95 09 95 0a 95 06 95 07 95
  actual   : 03 95 01 95 04 95 05 95 06 95 07 95 08 95 09 95
  differs at 0xb4
```

This rejects the stock-constructor transfer in the current matching context.
The retained aggregate model keeps the production constructor and passes that
same dependency. A recorded SDK version does not replace byte verification.
No full 190-profile consumer gate or production header integration is claimed.
The one aggregate model and two specific source transfers end this bounded
escalation; no further class/lifetime/order/hint/flag grid follows without
independent new evidence for the remaining differences.
