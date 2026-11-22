# Large height query: corrected collision-update predicate, unmatched

The pending `_ZN16PhysicAttributes9GetHeightEiRKN3irr4core8vector3dIfEEbb` starts
at Thumb `0x0031eb99` and occupies 5,038 retail bytes. Repaired Ghidra control
flow exposed a behavioral error previously missed by the broad source audit.
Direct retail branch tracing independently proves:

```cpp
state.unknown60 || (state.onGround && !state.wasOnGround)
```

All six historical candidates instead used
`state.unknown60 || !state.onGround || !state.wasOnGround`. When the dirty flag
is clear and the object is airborne, that expression incorrectly calls
`UpdateEdgesCollisions`; retail skips it regardless of the previous-ground flag.

Retail checks byte 60 at `0x0031f7c0`. A nonzero dirty flag reaches the call at
`0x0031fb06`. Otherwise byte 136 equal to zero branches directly from
`0x0031f7d0` to the skip path at `0x0031f7d4`. If byte 136 is nonzero, byte 137
at `0x0031faf8` determines whether to call: zero calls, nonzero skips. The earlier
audit's assertion that the OR condition was correct is superseded by this trace.

One isolated condition-only GCC 4.2.1 trial on the preserved v5 source emits the
correct branch behavior but remains 4,982/5,038 bytes, with its physical section
4,984 bytes and first exact-comparison failure at `0xc`. There are 4,720 differing
positions including the 56 missing bytes. The linked candidate SHA-256 is
`b55bcb155bb9124b5559f415a03561c4b0f47cbe1e80e50a74ae1340ef8d0225`.

All 37 existing selected functions and nine support regions remain exact in the
same image. All 40 other emitted function payloads remain unchanged. This is a
scoped private result, not the current full repository gate. Preserve the
behavior-correct candidate; the earlier nearest-size source retains the known
bug. No source integration, assembly-marker deletion, or matching credit follows
from this partial reconstruction.
