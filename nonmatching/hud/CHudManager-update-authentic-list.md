# CHudManager::update: authentic touch-list reuse

This candidate is **not matched** and adds no progress. Native Thumb
`0x00324399` is 720 bytes. The retained complete 720-byte candidate differs in
14 bytes, reduced from the old candidate's 26. All original assembly markers
remain. Baseline: main PR #745, `d151cad3d53bfd1a6628b362a9d298a158a41bdb`.

## New evidence and reconstruction

The six old forms used a provisional global list model. The currently accepted
TouchIDListSupport.h supplies the real observed eight-byte sentinel, 12-byte
nodes, native stateless allocator path, insertion, sorting and cleanup imports.
Its existing getTouchIDList caller is byte-matched. This evidence justified
one bounded current-interface reuse trial of the old sixth HUD function body.

The original pinned Android STLport [_list.h](https://android.googlesource.com/platform/external/stlport/+/e64e7c849b0b659d3e198e4efaed563601e554be/stl/_list.h)
uses distance for list size. Its [_iterator_base.h](https://android.googlesource.com/platform/external/stlport/+/e64e7c849b0b659d3e198e4efaed563601e554be/stl/_iterator_base.h)
passes iterators by value into distance, then by const reference into the
input-iterator implementation, which copies the first iterator before traversing.
The private ABI view adapts that specific path and the original mutable-to-const
iterator conversion/comparison interfaces. Its existing copyright and altered
source notices remain. No retail STLport revision identity is inferred.

The caller uses the current real resetElements vector API, replacing old raw
field spellings without changing storage. The accepted defaultReceiver name
replaces the old provisional cameraManager name. Private friend access for
Radio/ToggleButton and the existing native isCurrentState declaration are
necessary call-interface prerequisites; no virtual slot or field offset changes.
The two region return temporaries, all original game control flow, normal flags,
and actual native imports are retained. No global std::list primary is invented.

The first setup compile failed because the complete TouchScreenBase include,
current vector field spelling and menu-method declaration were missing. The
failed log/input snapshot is retained privately. These setup issues were repaired
before successful assembly; no failed compile was represented as a candidate
match. Existing GCC offsetof warnings and the pre-existing undefined inline
Radio destructor warning remain visible; they are not suppressed.

## Reproduction and actual comparison

Apply the source patch only in an isolated checkout of the baseline:

```powershell
git apply --check nonmatching/hud/CHudManager-update-authentic-list.patch
git apply nonmatching/hud/CHudManager-update-authentic-list.patch
python nonmatching/hud/CHudManager-update-authentic-list-probe.py --baselib C:/path/to/libsanangeles.so
```

The compile-only probe intentionally exits **3** after assembly, never links,
and reports no native acceptance. Actual unresolved target object: 720 bytes,
SHA-256 `788f6ec64a7d40a9cb0107868874cf5cb9ed16068206cf85067137cc887f4d38`.

For the actual native-address comparison, apply the companion link patch too:

```powershell
git apply nonmatching/hud/CHudManager-update-authentic-list-link.patch
python tools/build.py --baselib C:/path/to/libsanangeles.so hud-manager-helpers
```

Normal build exit: **1**. Exact failed-check output:

```text
MISMATCH  _ZN11CHudManager6updateEd  0x00324399
  expected : 1b 1a 9b 10 00 2b 78 d0 00 23 69 46 04 aa 20 31
  actual   : 1b 1a 9b 10 00 2b 78 d0 6b 46 04 a9 00 22 20 33
  differs at 0x7e
MISMATCH SECTION .hud_update
  expected : 1b 1a 9b 10 00 2b 78 d0 00 23 69 46 04 aa 20 31
  actual   : 1b 1a 9b 10 00 2b 78 d0 6b 46 04 a9 00 22 20 33
  differs at 0x7e
```

All **49 original function checks and 42 original section/region checks pass**,
including the original native GOT and HUD vtable. All three native string
sections pass their own comparisons at the original addresses. The new target
is a genuine allocated executable definition at its native address, with a
strict 720-byte extent assertion. Its old external Thumb import is removed;
no absolute binding masks the compiled function. Only this target is a new
primary object function definition relative to the accepted root object.
All new list helpers are inlined. The public compile-only probe was re-run
against the frozen unhinted candidate: actual exit3 and the identical raw target
hash above. All three patches also apply sequentially in a separate isolated
checkout and reconstruct the measured diagnostic source/configuration text.
All 884 source/configuration/tool hashes
remain stable during the normal build. A full 190-profile consumer closure is
not claimed for the private support-header additions.

## Improvement, remaining gaps and stop

The original and new linked images are compared against the same full native
function. Both are 720 bytes. The old SHA-256 is
`8397e0aa13c30c9904f334ecdee31c039b3085dc2d24e6011f73cfadaf056948`;
the new linked SHA-256 is
`c6a03331522652d168fb29291be758edb7c1f46873e24af3759db953690ff25c`.
These identities and byte-difference counts are diagnostics, not match credit.

Authentic distance reuse resolves both six-byte list-counting loop differences
at +0x192..+0x196 and +0x1a6..+0x1aa. Remaining differences are ten bytes in
initial index/temporary-address scheduling at +0x7e..+0x8b, two GOT-base register
encodings at +0x1d4/+0x1d8, and the cleanup branch encoding at +0x278/+0x279.
The complete 68-byte frame and native call structure remain.

One separately bounded likelihood diagnostic marks the unlocked HUD branch
likely. The optional hint patch isolates that one expression. It emits **712
bytes** and the unchanged strict native-size assertion rejects linking. Actual
normal build exit is **2**, with no linked image, old closure or credit. All
884 inputs stay stable. The compiler output is untouched and the hint is absent
from the retained best candidate. No opposite hint, loop, source-order, lifetime
or compiler-flag grid follows. The function is parked pending genuinely new
evidence for the remaining fourteen bytes; production files remain unchanged.
