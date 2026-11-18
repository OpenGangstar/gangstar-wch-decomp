# SceneNodeManager pool-ID lookup

The signed-key red-black lookup now reproduces all 68 native bytes. It reuses
an authentic cached STLport implementation rather than another permutation of
the exhausted handwritten model. The cached Android reference is commit
e64e7c849b0b659d3e198e4efaed563601e554be; matching retail template symbols confirm
the six-parameter MapTraits/Select1st family, without proving that exact release.
The upstream copyright/license and explicit modified-subset notice are retained.

The decisive source difference is the raw mutable-node _M_find result with
nested end-pointer assignment, followed by the const-iterator wrapper. Real
by-value iterator comparisons and const key/value views preserve the observed
header/node layout. The previous model returned an iterator through a ternary
and emitted a four-byte cold block absent from retail. The genuine structure
eliminates that discrepancy without a branch hint, compiler flag or output edit.

PoolIndex remains 24 bytes, node 24, key/value offsets 16/20, iterator four and
manager 1068 bytes. All existing data members and constructor bodies are unchanged.
The coordinator retains the authentic default iterator behavior (no invented
initialization); that unused-interface cleanup also passes the native target.
The existing std::less<int> is reused after its actual declaration is available;
no full incompatible STL headers, new global std types or extra storage are added.
No additional helper function or data definition is emitted.

Exact comparison output:

```text
OK  _ZNK16SceneNodeManager9getPoolIDEi  0x00321445  68 bytes
OK SECTION .scene_pool_id  0x00321444  68 bytes
```

All 28 old unit functions, existing sections and complete GOT remain exact.
The affected-header/caller closure passed ten profiles including dependencies:
725 functions, 572 sections and ten regions. Coordinator integration passed
`python tools/build.py --all`: exit zero, 190 profiles, 10,503 successful
function/section/region comparisons. The source still has report, reclaimGarbage
and drop pending, so this match earns no new Fully Linked completion credit.

Other investigations in this batch remain rejected: a bool UI-forwarder model
keeps its scheduling mismatch; disabling sched2 regresses 140 old functions and
two sections; the literal iPhone initializer matches locally but its declaration
changes an existing Cash instruction order. None of those candidates or flags
is integrated or credited.
