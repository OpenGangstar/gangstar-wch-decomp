# ComputeShortestPath: genuine-object reconstruction

Target: `libsanangeles.so`, Thumb `0x00320ca1`, 1,668 bytes. This patch is
unapplied and unmatched. The original assembly marker, catalogue status and
canonical source remain unchanged. It adds no matched or Fully Linked bytes.

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
