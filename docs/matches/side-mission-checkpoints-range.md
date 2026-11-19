# SideMission checkpoint-range helper

The static `SideMission::isInCheckpointsRange` at Thumb `0x00346f55` matches
all 70 retail function bytes. Its 72-byte physical section also matches,
including the original two-byte NOP before the next function at `0x00346f9d`.

The reconstruction reuses the genuine Irrlicht array `size()` and indexed
access interfaces, restricted to their release-mode behavior. Storage remains
the existing 20-byte fork view; allocator, ownership, constructors and the
opaque word are unchanged. The accessors are nonvirtual and add no fields.
The original copyright and license notice and all existing comments remain.
No original matched function body is edited.

The user-provided Irrlicht 1.4.2 `irrArray.h` supplies these accessors. This is
source-family evidence, not a claim that the retail fork exactly equals stock
Irrlicht. The native function has no debug bounds-check path. Full container
allocation or debug behavior is not reconstructed here.

Six prior direct-storage loop forms could not recover the final comparison
operand/unsigned branch ordering. The bounded accessor adaptation preserves
the existing by-value vector ABI, unsigned count comparison and reloads after
callee calls; it emits the original comparison order. It emits no new outlined helper, hint, forced register, barrier or
compiler-output edit.

## Verification

The accessor-only prerequisite passed 190 profiles and 10,925 comparisons with
the target absent. The first target compile emitted the correct 70-byte symbol
but a 72-byte input section. Its strict initial 70-byte section assertion
stopped before linking. Inspection proved the trailing `c046` bytes equal the
original padding, and the next native function starts at `0x00346f9d`.
A link-only recovery retained the unchanged compiled object, asserted the
72-byte physical section and separately checked the original 70-byte function.
No bytes were trimmed or changed.

Independent final root compilation used the ordinary unmodified builder:
`python tools/build.py --all`. All 190 profiles passed: 5,421 function checks,
5,325 section checks and 181 region checks, totaling 10,927 comparisons.
Exit 0, no mismatches or skips; all 945 frozen inputs remained unchanged.

```text
OK  _ZN11SideMission20isInCheckpointsRangeEN3irr4core8vector3dIfEERNS1_5arrayIP10CheckpointNS1_12irrAllocatorIS6_EEEE  0x00346f55  70 bytes
OK SECTION .side_mission_checkpoints_range  0x00346f54  72 bytes
```

Native and compiled function SHA256:
`89dc711f026e6fa8f1f276635f52156e7aeeb134210c908105b1a0f5e274468f`.
Only this verified assembly marker is removed. Seventy function bytes receive
credit; padding receives none. `enableCheckpoints` remains pending, so the
source unit is not marked fully linked.
