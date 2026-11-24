# Quaternion return-declaration controls: no adoption

The stock Irrlicht 1.4.2 header declares void returns for `set`, `rotationFromTo`
and `fromAngleAxis`; our partial declaration views use quaternion-reference
returns. That difference justified bounded private controls, not a blanket
correction to the Gameloft fork. No canonical header or function changed, no
assembly marker was removed, and no matching credit was added.

The inspected retail callers discard the helper result and pass their retained
quaternion addresses onward. This does not identify the declared fork return
type: incidental R0 contents are not return-contract proof. Conversely, ignored
results do not guarantee identical compilation. Pinned GCC 4.2.1 selects an
initial call-value versus call RTL form before discarding an ignored expression
result; final allocation and scheduling can differ.

Primary references:
[Irrlicht 1.4.2 quaternion API](https://svn.code.sf.net/p/irrlicht/code/tags/release-1.4.2/include/quaternion.h),
[GCC call expansion](https://github.com/gcc-mirror/gcc/blob/0d5acec7b636b19aac6ed7517a1dea8fb9f6b0dc/gcc/calls.c),
[C++ conversion to void](https://github.com/gcc-mirror/gcc/blob/0d5acec7b636b19aac6ed7517a1dea8fb9f6b0dc/gcc/cp/cvt.c).
These identify upstream behavior, not the entire proprietary compiler or engine
fork. Their hashes and exact inspected anchors remain in the private receipts.

## Reviewed outcomes

Each control changes exactly one return declaration in its authentic private
paired header. Method identity, arguments, weak attribute, class layout and
every candidate function-body byte remain unchanged. Original compiler flags,
assembler, paths and runtime are retained. No linker ran.

| Target | Native bytes | Control bytes | Result |
| --- | ---: | ---: | --- |
| Vehicle::step, void set | 4372 | 4336 | Four pre-constructor move bytes change; no extent, frame or call-sharing repair |
| Rocket::launch, void rotationFromTo | 744 | 744 | Eight previously native-equal instruction bytes regress |
| BulletTraceManager::OnAnimate, void rotationFromTo | 496 | 496 | Four previously native-equal instruction bytes regress |
| Vehicle::Update, void fromAngleAxis | 4020 | 3936 | Four target bytes regress; protected matched stepPhysic also changes |
| PlayerTest::switchAnim, void rotationFromTo | 1072 | 1076 | Eighteen receiver-setup bytes change; no extent repair |

Vehicle step used one frontend/assembler pair on the original 4336-byte context,
not either conditional-object variant. All 200 other function payloads remain
exact; anonymous namespace identity differences are separately disclosed in
`nonmatching/vehicles/step-conditional-controls/`.

Rocket used an untouched baseline pair first. The complete baseline object and
assembly reproduce the historical artifacts exactly. The sole declaration
control preserves all 18 other functions, 36 off-target allocated payloads,
92 imports and 144 off-target references without name mapping. Only eight target
bytes change, at offsets 0xe6 through 0xed; those positions were already
native-equal. The later mismatch is not repaired.

BulletTrace's recovered checked baseline has the same 496-byte function as its
historical artifact. All 29 emitted function payloads, 36 allocated payloads
and 288 references reproduce exactly. Its old generated STT_FILE basename
differs from the replay basename, so raw whole-object identity fails. The
coordinator independently reviewed that filename and related string/file-offset
bookkeeping; the raw failure remains recorded. Only the remaining declaration
pair was then separately authorized. It preserves all 28 other functions and
35 off-target allocated payloads, symbols, imports and all 288 references. The
entire control object changes at only four target bytes, exchanging two
previously native-equal instructions at 0x162 and 0x164.

Vehicle Update's untouched baseline also fails raw whole-file identity. The
coordinator proves that one complete anonymous namespace prefix substitution
accounts for every object and assembly byte difference, with no payload or
reference change. That explicit correspondence permits only the private
declaration test; it does not establish raw identity or matching credit. The
control leaves Update at 3936 bytes and swaps two instructions before the first
angle-axis call. Crucially, the protected 1536-byte `Vehicle::stepPhysic()` body
also changes at ten bytes. Only 198/199 off-target definitions and 225/226
off-target payloads remain exact after the separately disclosed namespace
correspondence. This real code regression independently rejects adoption.

All permitted commands exited 0, with no compiler retry or source refinement.
The two-pair controls preserve their original stopped-baseline packets and
separately recorded resume approvals. No failed raw gate is relabeled as a
pass, and no compiler output is edited.

The BulletTrace replay needs two coordinator-created include-path aliases after
the repository move: the old source prefix resolves to relocated source, while
the old checked scalar-fixture prefix resolves only to the private fixture.
The existing legacy root is preserved; donor source and headers remain unchanged.
The private header's intentional change and all alias-resolved input pins are
recorded separately. These local aliases are not repository or game-data changes.

## Consequence

Do not replace these partial return declarations solely to resemble stock
Irrlicht. The controls supply no complete native match and demonstrate actual
regressions. No original fork signature is proved by these comparisons alone.
Preserve the current canonical declarations and existing matching verification.
Additional controls need different concrete evidence, not another return-type
or constructor permutation.

Detailed immutable command, source, header, baseline, raw-delta and preservation
receipts remain under `_scratch/worker-vehicle-step-set-return-audit/`,
`_scratch/worker-rocket-rotation-return-audit/`,
`_scratch/worker-bullettrace-rotation-return-audit/` and
`_scratch/worker-vehicle-update-angle-return-audit/`. The separate latest
four-correction PlayerTest context and its 1076-byte negative control are retained
under `_scratch/worker-player-switchanim-rotation-return-audit/`: all 79 other
function payloads, 110 off-target allocated payloads, 132 imports and 426
off-target references remain exact under the explicitly recorded seven-constant
name correspondence. Its original whole-file baseline failure and mechanical
preflight stop before mutation/compilation remain preserved. Neither is a failed
compiler invocation or an undisclosed repeat. No linker ran for that control.
