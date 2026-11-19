# Character::initPhysic: complete SDK class reuse

This candidate is **not matched** and adds no progress. Native Thumb
`0x002f4465` is 456 bytes; the current candidate is 440 bytes. The original
assembly marker remains. Source baseline: main PR #745,
`d151cad3d53bfd1a6628b362a9d298a158a41bdb`.

## Evidence and bounded scope

The earlier five retained forms used incomplete SDK interfaces, external
weak destructor declarations or placement storage. Complete licensed shape
classes can now emit the real inline destructor bodies, preserving weak
binding. A separate SDK-only normal link has already verified six destructors,
nine sections and one GOT region against native bytes; see the
[Vehicle SDK evidence](../vehicles/Vehicle-CreateBody-sdk-reuse.md).
That proof justified this one new reuse trial. It does not prove this caller.

The trial reuses those complete classes, an ordinary automatic circle object,
and the previously reconstructed function body. It preserves current production
compiler flags, the current b2BodyDef constructor, the current Player hierarchy,
two virtual position reads and the existing null-adjusted Player comparison.
The old partial destructor class definitions are replaced with the complete
header, retaining their existing comment. No placement buffer, explicit weak
function call, inline assembly or output manipulation is used.

Private prerequisites add b2Vec2::SetZero and b2Body::CreateShape without new
virtual slots. PhysicsBodyData gains its native 28-byte construction fields:
native allocates 28 bytes, writes owner/node at 0/4, zero floats at 8/12/16/20,
and zero bytes at 24/25 before storing the pointer in b2Body at 144. These
prerequisites remain unapplied and require all affected consumer checks before
integration. No standalone constructor or SDK function receives new credit.

## Reproduction

Apply only in an isolated checkout of the baseline:

```powershell
git apply --check nonmatching/characters/Character-initPhysic-sdk-reuse.patch
git apply nonmatching/characters/Character-initPhysic-sdk-reuse.patch
python nonmatching/characters/Character-initPhysic-sdk-reuse-probe.py --baselib C:/path/to/libsanangeles.so
```

The probe always stops immediately after primary assembly. Expected actual
Python exit code: **3**. It does not link, compare native function bytes or
validate old matches. The raw object hash identifies this source/toolchain
result and is not a matching percentage.

Actual output from the reviewed current-context trial:

```text
{"symbol": "_ZN9Character10initPhysicEv", "native_address": "0x2f4465", "native_size": 456, "compiled_size": 440, "input_section_size": 440, "raw_sha256": "0d03244d24205907d64537b28cc7f0a3821976dcaa1a06880f3569b173cc4470", "native_extent_matches": false, "linked": false, "native_bytes_compared": false, "old_match_closure_checked": false, "credited": false}
COMPILE-ONLY: no native byte comparison or old-match proof.
```

The published probe was then run against the same frozen candidate. It also
exited 3 and reproduced the exact 440-byte object hash above. This was an
unchanged-source reproducer check, not another source form. The patch applies
with plain git apply --check; its initial local Windows line-ending encoding
was normalized before that check.

All 885 frozen source/configuration/tool inputs stayed unchanged during the
trial and reproducer check. Six emitted SDK destructor definitions are genuinely weak, with native
function extents 24/32, 36/44 and 36/44 bytes for base/polygon/circle. They were
not linked or revalidated in this caller context. An initial post-build audit
used a nonexistent ELF reader property, failed before writing its report, then
was corrected to use the existing is_undefined property on the unchanged object.
No additional source form or compilation was needed for that reader correction.

## Remaining differences and stop

The frame is 124 bytes versus native 116. The automatic circle starts at
SP+8 rather than native SP+0; the body starts at SP+52 rather than native
SP+44. Both position calls remain, with their 12-byte return temporaries.
Native reloads the three halfword filter fields before storing the Character
fields. This candidate forwards the known mask constant instead of reloading
it. These observations identify actual differences, not a proven source fix.

Older retained linked candidates have extents 436 and 440 bytes; neither was
matched. Equality of an extent does not establish equality of this new body
with an old one. The initial compile-only trial has no linked-byte comparison or old-match
closure; the unchanged-source diagnostic follow-up below supplies the local
closure and confirms that the target still fails.
No source-order, lifetime, likelihood, register or compiler-flag grid follows.
The candidate is parked until new evidence explains the remaining differences.
The complete native function and affected old/header consumers must all pass
before any assembly marker can be removed or progress credited.

## Unchanged-source native placement and local preservation

A subsequent normal build uses the same source and object identity, places the
candidate at its actual retail address, and checks the original owning profile.
This is a diagnostic link, not acceptance of the function. The optional
`Character-initPhysic-sdk-reuse-link.patch` adds only that diagnostic profile
configuration. Apply it after the source patch in an isolated checkout, then:

```powershell
python tools/build.py --baselib C:/path/to/libsanangeles.so ai-startup-character
```

Expected normal build exit: **1**, with exactly the following two failed checks:

```text
MISMATCH  _ZN9Character10initPhysicEv  0x002f4465
  expected : 4d 46 44 46 f0 b4 b4 22 63 49 86 58 9d b0 8b 46
  actual   : 4d 46 44 46 f0 b4 b4 22 5f 49 86 58 9f b0 89 46
  differs at 0xe
MISMATCH SECTION .trial_init_physic
  expected : 4d 46 44 46 f0 b4 b4 22 63 49 86 58 9d b0 8b 46
  actual   : 4d 46 44 46 f0 b4 b4 22 5f 49 86 58 9f b0 89 46
  differs at 0xe
```

All **114 original function checks and 33 original section/region checks pass**,
including the native GOT comparison. The three newly emitted polygon definition
sections are placed at their real native addresses and pass ordinary checks;
the two added polygon function comparisons pass too. All six SDK destructor
bodies and three SDK vtables are additionally audited against retail bytes at
the actual addresses: genuine allocated definitions, preserved weak bindings,
correct native extents. The target is a genuine allocated 440-byte definition
at its native address and fails comparison. No absolute import masks a compiled
SDK definition or the target.

The native placement has a maximum-span guard of 456 bytes to prevent overlap;
it deliberately does not turn the shorter function into a 456-byte function.
The ordinary function comparison and section comparison remain mandatory and
both fail. No previous extent assertion was removed or relaxed, and no padding
was inserted. The frozen 885 source/configuration/tool inputs remain stable
through this normal build. This local closure does not substitute for a full
190-profile header-consumer gate. No new source form was compiled or credited.
The source and configuration patches remain unapplied in production.

## One subsequent original SDK vector API transfer

After reviewing the first trial, the cached original Box2D 2.0.1 archive's
`Source/Common/b2Math.h` confirms the inline two-float b2Vec2::Set interface.
The old fifth source already used it in its old context. The coordinator allowed
one transfer into this new complete-class context, with no other body or flag
change: use Set for body.position instead of assigning a temporary b2Vec2.
`Character-initPhysic-sdk-set.patch` is that optional delta, applied after the
source patch. It does not depend on the diagnostic link patch. Reuse the same
compile-only probe to inspect it; expected exit remains 3.

Actual output:

```text
{"symbol": "_ZN9Character10initPhysicEv", "native_address": "0x2f4465", "native_size": 456, "compiled_size": 440, "input_section_size": 440, "raw_sha256": "c5a7138eccdd6c9c9d29371c510d81d4a97805b441021a2ae1610dc3bb4a8754", "native_extent_matches": false, "linked": false, "native_bytes_compared": false, "old_match_closure_checked": false, "credited": false}
COMPILE-ONLY: no native byte comparison or old-match proof.
```

All 885 frozen inputs remain stable. The frame remains 124 bytes. GOT and X
allocation move to native FP/R9, but body/shape addresses and the remaining
extent gap persist. No normal link or old/header closure is claimed for this
API-transfer variant. The first source form and its measured local preservation
remain the primary saved candidate. This single API transfer ends the bounded
SDK escalation; no further lifetime, source-order or register search follows.
