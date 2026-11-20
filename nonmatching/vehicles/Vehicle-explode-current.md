# Vehicle explosion: corrected reconstruction

This unapplied patch corrects Vehicle::explode at 0x003130a1. Native GetPlayer
at 0x0031333e is followed by immediate 224 and a zero-word store, with no shift:
`ed f7 43 fd e0 23 42 46 c2 50`. The old candidate wrote 448. The corrected
source writes the genuine inherited PlayerTest::health field at 224 and
preserves the second GetPlayer call.

Ordinary EvVehicleDestroyed construction now uses IEvent(20), preserving its
existing default constructor and member/layout. Actual generated code contains
both base and derived event-vtable references. No forced vptr stores are used.
The source reuses matched repairVisualState/block fields instead of an invented
morphing-mesh view. The private timeline slot 4 setClip(int) declaration is an
ignored-result call view; the original return type is not proven. Neither
private header change is integrated into production by this patch artifact.

Private header verification covers 190 unique canonical profiles and 10953
comparisons with 1044 stable inputs. The initial all-profile runner incorrectly
forced NDK 1.6 onto the two r4b profiles, causing a Logs padding failure and two
skipped dependents. That failed run/exit 1 remains recorded. Canonical Logs,
adpcm-state and skipped-dependent repair exits 0; the coordinator independently
checks the unique-profile union, excluding the incorrect-toolchain results.
This is aggregate coverage, not a claimed single all-profile exit 0.

The corrected target remains 740 bytes and still fails the native comparison.

The coordinator independently applies this public patch in a fresh isolated
copy of the current source/configuration/tools, compiles the original owning
profile and reproduces the exact native-address size and linked SHA256 below.
All 188 existing functions and 112 section/region comparisons remain exact;
only the assigned target and its complete section fail. The replay exits 1,
with 884 frozen inputs stable and only the assigned executable definition added.
This is independent of the other vehicle candidate; no combined-patch closure
is claimed.

```text
MISMATCH  _ZN7Vehicle7explodeEv  0x003130a1
  expected : 95 b0 07 1c 00 2b 00 d0 01 e1 01 23 9b 46 bb 54
  actual   : 95 b0 07 1c 00 2b 00 d0 02 e1 01 23 9b 46 bb 54
  differs at 0x20
```

Linked SHA256: `a58f97941d088b08ad26a8834e7b4434bda26bfd52745e706b2100e007be5189`.

Use a separate checkout when reproducing:

```sh
git apply --check nonmatching/vehicles/Vehicle-explode-current.patch
git apply nonmatching/vehicles/Vehicle-explode-current.patch
python tools/build.py vehicle-cleanup --baselib <local-retail-library>
```

Expected result is verifier exit 1, not a successful match. Source and original
compiler output are not postprocessed. No production function body, assembly
marker, catalogue status or matching/Fully Linked credit is changed. Further
source variants require new causal evidence; this bounded trial is finished.
