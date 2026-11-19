# Segment-heightmap wrapper: recovered cross-product candidate

This wrapper is **not matched** and receives no credit. Native Thumb
`0x0031da29` is 596 bytes; the retained candidate is 592 bytes. The original
assembly remains pending. The separate traversal overload is an imported native
function, outside this scope.

The source/configuration baseline is `647af517e490e93bd17904c9c8db18fe1cac7c79`
(PR #738). Apply the patch only in an isolated checkout:

```powershell
git apply --check nonmatching/characters/PhysicAttributes-segment-heightmap.patch
git apply nonmatching/characters/PhysicAttributes-segment-heightmap.patch
$env:WCH_BASE_LIB = 'C:/path/to/your/libsanangeles.so'
python tools/build.py ai-startup-physicattributes
```

Expected exit: **1**, with the new wrapper reporting MISMATCH. No compiler
output is edited; production compiler options remain unchanged.

## New evidence and reconstruction

The five archived forms predate the recovered modified-fork `crossProduct`.
Stock subtraction and hand-expanded expressions produced different signed-zero
operations. The retained source forms the perpendicular `(delta.Y, -delta.X, 0)`
and calls its current `crossProduct(delta)`. The normal is normalized, a plane
is constructed through the starting point, selected PhysicInfo fields are
copied, the native traversal helper runs, and success returns the recomputed
hit-distance/segment-distance ratio. Constructor side effects precede the
empty-info check; distances are recomputed after the helper because references
may alias.

The old aligned byte-storage workaround now triggers the unit's legitimate
`-fstack-protector`, emitting a guard absent from native. Its initial current
trial is 636 bytes. The already integrated PhysicInfo constructor-linkage
recovery permits the ordinary `PhysicInfo temporary` declaration instead; this
removes the guard without disabling protection or changing the constructor.
The retained plane interface and native traversal/static-counter declarations
are private prerequisites in this unapplied patch, with no storage changes.
The real weak constructor remains compiled and compared.

Two typed control-flow forms (early failure returns and a nested success block)
emit the identical 592-byte target. A single permitted success-branch hint emits
596 bytes but changes GOT/register scheduling and fails at offset `0x0c`.
The hint is rejected and is absent from the retained patch. No additional forms
were attempted after that bounded escalation.

## Verification and limits

The retained normal link passes **38 existing function checks, 10 section checks
and one GOT region check**, including the actual 96-byte PhysicInfo constructor.
Its traversal import has authentic Thumb metadata. Three newly needed ARM PLT
bindings for float/double conversion and sqrt were added after an initial
undefined-reference linker failure. These are build inputs, not output edits.
No full 190-profile preservation run is claimed for these private prerequisites.

```text
MISMATCH  _ZN16PhysicAttributes29IntersectSegmentWithHeightMapERKN3irr4core8vector3dIfEES5_RS3_S6_  0x0031da29
  expected : b9 68 90 68 a6 f6 66 ec 80 4c 80 49 81 4e a3 46
  actual   : b9 68 90 68 a6 f6 66 ec 7f 4c 7f 49 80 4e a3 46
  differs at 0x36
```

Through offset `0xf4`, the only nine differing instructions are PC-relative
literal loads. They keep the same destination registers and load the identical
four-byte values from the differently positioned pools. This diagnostic
establishes the recovered arithmetic/register sequence, **not a byte match**.
The first control-flow difference is at `0xf6`: the compiler places the failure
return and shared epilogue before the success copy/traversal path; native places
them after it. Later branch/pool displacements and the total extent differ.
The retained complete unlinked target SHA256 is
`37cbc4135dac85a6ee7ae749f4d576c4d5fca0b5f984a1955f3b133aa2297936`.

Do not credit the equal-size rejected hint or the diagnostic prefix. Revisit
only with new return-layout/compiler evidence. The production source, headers,
profiles, assembly marker and matched-function progress remain unchanged.
