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
