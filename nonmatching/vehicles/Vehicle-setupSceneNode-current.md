# Vehicle scene setup: current interfaces

This unapplied patch reconstructs Vehicle::setupSceneNode at 0x00309a4d using
the genuine animator->drop() hierarchy and the weak factory getter already
used by matched Vehicle code. It adds no factory header, proxy animator,
startup cleanup helper or header refactor.

The observed billboard view remains provisional: complete root+40 points to
an opaque record whose+8 field supplies params[0]. Its original class identity
and the downcast assumption are not proven. This limitation is retained rather
than presented as a recovered complete type.

The strict 736-byte function/section fits the native span and next boundary
0x00309d2c, but its entire output equals the archived candidate. Reusing the
real interfaces improves the reconstruction without adding matched bytes.

The coordinator independently applies this public patch in a fresh isolated
copy of the current source/configuration/tools, compiles the original owning
profile and reproduces the exact native-address size and linked SHA256 below.
All 188 existing functions and 112 section/region comparisons remain exact;
only the assigned target and its complete section fail. The replay exits 1,
with 884 frozen inputs stable and only the assigned executable definition added.
This is independent of the other vehicle candidate; no combined-patch closure
is claimed.

```text
MISMATCH  _ZN7Vehicle14setupSceneNodeEiPN3irr5scene10ISceneNodeEiPPv  0x00309a4d
  expected : 8b b0 17 1c 14 9a 81 46 01 24 00 92 90 46 3a 1c
  actual   : 8b b0 17 1c 14 9a 81 46 9f 4c 00 92 92 46 3a 1c
  differs at 0x14
```

Linked SHA256: `c39efcc20cac54a3a5b872a66a90f4f86d6ea70472b882bb998ecb3c939c9a29`.

Use a separate checkout when reproducing:

```sh
git apply --check nonmatching/vehicles/Vehicle-setupSceneNode-current.patch
git apply nonmatching/vehicles/Vehicle-setupSceneNode-current.patch
python tools/build.py vehicle-cleanup --baselib <local-retail-library>
```

Expected result is verifier exit 1, not a successful match. Source and original
compiler output are not postprocessed. No production function body, assembly
marker, catalogue status or matching/Fully Linked credit is changed. Further
source variants require new causal evidence; this bounded trial is finished.
