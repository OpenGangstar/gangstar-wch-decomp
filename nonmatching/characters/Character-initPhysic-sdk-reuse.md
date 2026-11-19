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
with an old one. This trial has no linked-byte comparison or old-match closure.
No source-order, lifetime, likelihood, register or compiler-flag grid follows.
The candidate is parked until new evidence explains the remaining differences.
The complete native function and affected old/header consumers must all pass
before any assembly marker can be removed or progress credited.
