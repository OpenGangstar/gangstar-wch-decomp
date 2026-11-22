# ComputeShortestPath: genuine-object reconstruction

Target: `libsanangeles.so`, Thumb `0x00320ca1`, 1,668 bytes. This patch is
unapplied and unmatched. The original assembly marker, catalogue status and
canonical source remain unchanged. It adds no matched or Fully Linked bytes.

The latest evidence-supported candidate is **1,672/native 1,668 bytes** after
the original-terminal correction below. The historical 1,688-byte patch and
rejected quotient-width control are retained for provenance.

## New evidence and bounded scope

Six earlier forms exhausted the first-pass budget. Their supported candidate
used aligned storage and a native constructor ABI bridge, emitted 1,688 bytes,
and had the native 460-byte frame. Two genuine-object forms emitted 1,680 bytes
but incorrectly made PhysicInfo C1 strong and called it directly; their smaller
size was not a supported result.

The current PhysicInfo interface, established after those attempts, emits its
existing 96-byte constructor with weak binding and uses the native GOT call
for an ordinary automatic object. A separate construction/assignment fixture
verified that behavior and the 140-byte class layout before this replay.
Constructor function size and class size are different quantities.

One bounded replay reuses the saved genuine-object algorithm with this current
header. It removes obsolete weak pragmas and initializes its two arrays through
the existing zero-storage PathArray view. No scheduling variants, compiler
flags, forced registers, barriers, hints or compiler-output edits were tried.
The existing 24-byte node fields and all canonical matched bodies are unchanged.

## Prerequisite verification and limits

The first private prerequisite added a generic array constructor. The full gate
rejected it because existing CollisionBodyDef and LODSceneNode matches changed;
dependent profiles also skipped. That form was not used or integrated.

The restricted prerequisite removes that constructor and retains only ordinary
declarations, the observed node constructor/equality, and the existing array
clear/erase/reverse-search interfaces. With the target absent, a fresh full ARM
gate passed **190 profiles, 5,425 function checks, 5,329 section checks and 181
region checks: 10,935 comparisons**. Exit 0, no mismatch or skip; all 952 frozen
input files remained unchanged. The target object contained no pathfinding
definition. This proves prerequisite preservation, not a post-body linked gate.

The candidate emits only the new pathfinding definition, a native 460-byte
frame, and the unchanged weak 96-byte PhysicInfo C1. Its constructor reference
is `R_ARM_GOT32` (26), correcting the old unsupported direct-call ABI. However,
the function and physical section are both 1,688 bytes against native 1,668.
The probe stops before linking. No overlapping image, linked comparison,
matching percentage or post-body closure result is claimed. Further source
forms require new evidence; the six-form budget was not reset.

## Reproduction

Use a disposable checkout at source context `32ef85f0` (PR735), the original
Windows ARM SDK workflow, and an independently supplied retail library:

```powershell
git apply --check nonmatching/characters/ComputeShortestPath.patch
git apply nonmatching/characters/ComputeShortestPath.patch
python nonmatching/characters/ComputeShortestPath-probe.py --baselib C:/path/to/libsanangeles.so
```

The probe deliberately exits 3 after assembling the object and before linking.
The exact candidate result is:

```text
BUILD ai-startup-physicattributes
{
  "size": 1688,
  "native_size": 1668,
  "section_size": 1688,
  "raw_sha256": "ff00af580a2c6c750c9b2ca8d12693d430b678f72f85154b26a26ceb05dcdabf",
  "ctor_size": 96,
  "ctor_binding": 2,
  "ctor_references": [
    {
      "offset": 956,
      "type": 26
    }
  ],
  "linked": false
}
Prelink analysis only; no linked comparison claimed.
```

The raw object digest is an artifact identity, not a native byte-match claim.
The first public-probe invocation lacked the retail path and stopped before
compilation; providing the explicit `--baselib` argument produced the result
above. No game data or proprietary toolchain is included in these artifacts.


## Bounded quotient-width follow-up after PR #741

A comparison of adjacent shift pairs suggested a possible unnecessary
unsigned-short truncation after division by three. One bounded source form
removed the three casts around `current.triangleOffset / 3` and `next / 3`,
and changed only the two quotient locals to unsigned int. Actual ushort wire
fields, sentinels, constructor parameters, layouts, array operations, flags and
all existing function bodies remained unchanged. Each numerator is a ushort;
its quotient is at most 21,845, so these local arithmetic changes preserve
its value. This is an investigation of intermediate arithmetic, not permission
to widen stored fields or change the algorithm.

The hypothesis failed: the candidate grows to 1,692 bytes, versus the supported
1,688-byte baseline and 1,668-byte retail target. Its constructor remains weak,
96 bytes, and byte-identical to the verified prerequisite object. Only the
assigned pending function is newly emitted. The probe stops before linking,
exit 3; no existing-function or native linked comparison is claimed.

```text
BUILD ai-startup-physicattributes
{"size": 1692, "native_size": 1668, "section_size": 1692, "new_definitions": ["_ZN16PhysicAttributes19ComputeShortestPathEiiN3irr4core8vector3dIfEES3_f"], "raw_sha256": "d65149058121a1efe73a47b9f3c576212b6c75536849552d7fe086de41b6eae8", "ctor_size": 96, "ctor_binding": 2, "ctor_raw_identical_to_prerequisite": true, "linked": false}
Prelink analysis only; no linked comparison claimed.
```

Both candidates and retail retain three unsigned divide calls. Removing the
source casts does not remove the generated extension/scaling sequences: all
three contain three left shifts by 16, with differently scheduled right shifts
and scaling. Adjacent-pair counts alone do not establish that retail omits an
operation or that the source type causes it. No signed-division correction,
flag variation, additional source form or shared-header change was attempted.
The original 1,688-byte candidate remains the supported baseline; this larger
candidate earns no credit and does not replace it.

To reproduce this diagnostic, first apply `ComputeShortestPath.patch` in an
isolated checkout, then apply `ComputeShortestPath-quotient-width.patch` and
run the existing prelink probe with the retail path. The small second patch
requires the first; it is not meant to apply directly to production source.
Current production base used for this follow-up: PR #741, main `91833d3c`.
Further quotient-cast trials require new evidence. The same pure cast-removal
hypothesis should not be blindly repeated on neighboring physics functions.


## Original-terminal correction

Complete retail instruction ownership was restored before this review. The
reconstruction stop predicate in the historical source was wrong: it compared
the found parent index against the changing traversal cursor. Retail instead
keeps the original terminal index in `r5`, initializes traversal from it at
0x003210c8, and compares each found parent to that unchanged `r5` at
0x003212dc. There is no write to `r5` on the reconstruction loop; intervening
calls preserve it under ARM EABI. The earlier audit's description of this
register as the previous cursor is superseded.

The [incremental correction](ComputeShortestPath-original-terminal.patch)
adds an immutable terminal snapshot and changes only the stop comparison:

```cpp
const int originalTerminal = selected;
// Within the existing reconstruction loop:
if (originalTerminal == next) break;
selected = next;
```

This preserves the retail termination rule, including its limitations. A
self-parent encountered after leaving the terminal is not the same condition
as returning to the terminal. No additional cycle guard or gameplay repair is
introduced.

Apply the incremental patch after the historical base patch in its documented
source context. Do not apply the quotient-width patch:

```powershell
git apply nonmatching/characters/ComputeShortestPath.patch
git apply --check nonmatching/characters/ComputeShortestPath-original-terminal.patch
git apply nonmatching/characters/ComputeShortestPath-original-terminal.patch
python nonmatching/characters/ComputeShortestPath-probe.py --baselib C:/path/to/libsanangeles.so
```

The coordinator independently populated the three affected files from Git
commit `32ef85f0cfddeeee04e462d81f310540413f2b04`, applied both patches with
strict Git checks and confirmed that the resulting source exactly equals the
actual compiled control. Source SHA-256:
`728082fffb6f4ad823157147155b3d957a572c9a3ec2339e4424573574337b95`.

One approved source-only compile emitted a 1,672-byte function and input
section, retaining the 460-byte local frame and weak 96-byte PhysicInfo C1.
Target payload SHA-256:
`83e1123c3beec7abe49982c889e8f4340f64c0dfdafebf120c71afcb3b6ef27d`.
All 41 existing function payloads, their semantic relocations and 53 other
allocated-section payloads remained identical to the supported object. The
same 41 functions also agree with the current canonical object; 953 frozen
inputs remained stable. The coordinator independently reread the real object
and verified its target extent/hash and all 41 old function payloads.

The strict gate printed:

```text
REJECT PRELINK: target does not have exact native1668-byte function/section extent; native link and owner/support checks SKIPPED
```

No linked target comparison or post-body owner/support gate was run. The
four-byte size excess does not mean only four bytes differ. The function
remains unmatched, its assembly marker remains, and matching progress is
unchanged. No second source form was compiled for this correction.


## Later bounded diagnostics

The 1,672-byte corrected candidate contains the same 1,620 real instruction
bytes, 48 literal bytes and 751 real instructions as retail. Its four-byte
size excess is two two-byte alignment fills before the literal pools. The
real chunks are 950/670 bytes rather than retail 948/672. Call-target counts
also agree. This is structural evidence, not instruction identity or permission
to remove padding.

One native-array identity control replaced only the two local derived array
objects with the primary array type and identical observed field initialization.
The entire emitted object was byte-identical. A subsequent unchanged-source
compiler-dump run also reproduced the entire baseline object and assembly.
The first self spill/reload appears in `138r.greg`; `149r.sched2` moves the
reload to its emitted position. Block placement changes at `147r.bbro`, while
`154r.mach` first creates the pools and alignment directives. Final offsets
come from assembly/object bytes, not estimated addresses in intermediate dumps.

A separate single cleanup-factoring control tested the observed six delete
sites before allocation versus four later. It reduced the pre-allocation
sites to four but retained the self spill and emitted 1,664/native 1,668 bytes.
All 41 old functions, their semantic relocations and 53 other allocated
payloads remained unchanged. Strict pre-link validation again stopped before
native linking or owner/GOT checks. No second factoring form was tried.
The preferred snapshot-corrected 1,672-byte candidate remains preserved;
these negative controls establish no new match or original compiler-option claim.
