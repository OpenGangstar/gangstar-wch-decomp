# Physics reset, array cleanup, and segment intersection

PhysicInfo::Reset preserves all original stores and the conditional cleanup of
its twelve body slots. The two bytes at offset 82 and Boolean at offset 84 now
have observed types, replacing opaque storage without changing the 140-byte
layout. Each body data pointer is freed and cleared before DestroyBody, then
the body slot is cleared in the original order.

The game-owned SafeDeleteArray wrapper uses normal C++ delete[] and nulls its
argument. UnsignedShortArray.h supplies only the required unsigned-short
specialization of the already observed 20-byte Irrlicht array layout, using
upstream conditional destruction semantics and retaining the upstream notice.
The generic Array.h template is unchanged. The specialization is included only
by PhysicAttributes.cpp; no existing tracked Irrlicht unsigned-short array
instance is affected. The unrelated gameswf unsigned-short array remains a
different type. Future neighbor-array callers must retain this ownership view.
Only the game wrapper receives matching credit; no engine binary is claimed.

SegmentsIntersect preserves the original XY-only geometry and floating-point
control flow, including degenerate segments and the collinear test. It uses
ordinary C++ arithmetic with the original ABI and soft-float imports.

The integrated physics, AIManager, and PlayerTest checks exited 0 with all
existing dependencies and sections preserved:

```text
OK  _ZN10PhysicInfo5ResetEP7b2World  0x00319cd5  144 bytes
OK  _Z15SafeDeleteArrayIN3irr4core5arrayItNS1_12irrAllocatorItEEEEEvRPT_  0x00319c21  62 bytes
OK  _ZN16PhysicAttributes17SegmentsIntersectERKN3irr4core8vector3dIfEES5_S5_S5_  0x003196fd  396 bytes
```

The new sections are retained through PhysicAttributesResetSections.ld in the
native physics unit and every existing dependent image. Initial dependent
linking exposed missing retention; moving the placements into that shared
fragment resolved it before any assembly deletion or matching credit.
