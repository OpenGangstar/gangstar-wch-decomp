# Node properties with corrected short-string construction

Unapplied typed candidate. Native initializes the 24-byte STLport string finish
pointer to the buffer BEGIN, not its end. At allocation size 16 the actual
native allocator leaves object fields untouched; the old source therefore
wrote a zero byte into its own finish pointer. Corrected construction is
verified against native code and cached official Android STLport source pinned
to e64e7c849b0b659d3e198e4efaed563601e554be. The exact retail revision/macros
are not proven.

The char-only adaptation preserves source notices and the observed empty
allocator/EBO proxy, protected base/derived RAII lifecycle and conditional
operator-delete policy. It changes no global String interface or algorithm.
Models pass size 24/alignment4/finish16/proxy20. Four old-GCC non-POD offsetof
warning lines remain visible; no warnings are suppressed. Count-return signedness
is not uniquely established by the observed recursive R0 accumulation.

Strict 528-byte extent and native neighbor guards pass. The coordinator replays
the public patch independently in a fresh current-root clone: 147 existing
functions and130 region checks exact (127 old plus three literal regions),
884 inputs stable, verifier exit 1. Only the assigned executable definition is
added; no constructor/destructor helper is emitted or hidden.

Four bytes still differ: 1e,d2,110,120. The recursive flag now uses native SP20,
but saved GOT offset and cached SSO end slots are exchanged. A separate earlier
corrected POD candidate also has four differing stack-slot bytes. Neither is
a match; source-order/frame/padding searches are stopped.

Reference: https://android.googlesource.com/platform/external/stlport/+/e64e7c849b0b659d3e198e4efaed563601e554be/stl/_string_base.h

No production body, assembly marker, catalogue status or matched/Fully Linked
credit changes. These artifacts preserve accurate partial work for a future
evidence-based attempt. Verify each candidate independently in a separate
checkout; their source-model and preservation scopes must not be combined.

```text
MISMATCH  _ZN9GS3DStuff19PrintNodePropertiesEPN3irr5scene10ISceneNodeEbi  0x002de6dd
  expected : fa 44 91 46 52 46 53 58 03 91 d4 27 1b 68 80 46
  actual   : fa 44 91 46 52 46 53 58 04 91 d4 27 1b 68 80 46
  differs at 0x1e
```

Linked SHA256: `550fc9bfa2581681b7cecaa15c5bb196b0cd1cbe0839dfd24e9e3339dd6212e6`.
