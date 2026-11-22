# AddCollisionShapes: per-edge info-array snapshot

Target: `PhysicAttributes::AddCollisionShapes(int, unsigned short)`,
`libsanangeles.so`, Thumb `0x0031e285`, 1,816 bytes. This investigation remains
unmatched. No canonical source, assembly marker or progress credit changes.

## Native evidence

The complete repaired analysis owns all 781 real native instructions and 1,726
executable bytes. Two padding bytes and 88 literal bytes account for the rest
of the retail extent. Four false returning-float termination overrides and two
incorrect ARM definitions had hidden much of this function. Restricted Thumb
decoding restored analysis without changing any retail instruction bytes.

Retail captures the info-array base separately for each edge, after constructing
the position and before scanning for a duplicate body. The positive-count path
loads the base at `0x0031e66e` and stores it at stack offset 12; the nonpositive
count path performs the corresponding store at `0x0031e95c`. There is no later
overwrite before insertion. After body and shape creation, `0x0031e924` loads
that same saved pointer for insertion.

The previous native-order-corrected 1,820-byte candidate instead reloaded
`self.info` after `CreateShape`. An earlier entry-wide `PhysicInfo&` experiment
does not test this per-edge snapshot point. The other previous forms also use
a fresh insertion lookup. Actual callback mutation of this array pointer has
not been demonstrated; the evidence concerns the native read identity and
timing, rather than a proven gameplay failure.

## Single bounded control

The [incremental patch](AddCollisionShapes-edge-info.patch) captures
`PhysicInfo* edgeInfo = info` immediately before the duplicate scan and reuses
it only in that scan and the final body-slot insertion. Earlier per-triangle
position lookups and the later fresh `infoCount` read for scale are retained.
All previous native-order/reference extrema corrections remain intact. No
constructor, storage, compiler flag, header, import or linker change is bundled.

This patch targets the earlier private native-order-corrected candidate, not
canonical source. It is not a standalone current-checkout reproduction: that
fixture contains private shape-definition prerequisites and omits the current
accepted `FindLowerCostNode` selector. The patch preserves the narrow source
finding without claiming that incomplete fixture is a current full-unit build.

One compiler invocation and one assembly invocation succeeded. The function
and input section both became **1,808/native 1,816 bytes**; the 356-byte local
frame is unchanged. The emitted code preserves the intended pointer through
stack offset 92 and reuses it after shape creation. Target payload SHA-256:
`b7322aae1dc5fdfc3867c9aa13e865b1734003b9ee900fd913eaf3da1445ab51`.

All 44 other function definitions, their semantic relocations and 58 other
allocated-section payloads are unchanged. The 931-file input snapshot is stable;
only the approved CPP differs from the baseline, including its disclosed
CRLF-to-LF normalization. The coordinator independently reread the actual
object, verified the target extent/hash and compared all 44 old payloads.
Strict Git application of the incremental patch reproduces the compiled source
after line-ending normalization.

The strict gate printed:

```text
REJECT PRELINK: target does not have exact native1816-byte function/section extent; native link and owner/support checks SKIPPED
```

No native link, target byte comparison, full-section comparison or fresh owner,
GOT or support gate ran. The size difference is not a byte-difference count.
No second form was compiled; the snapshot-corrected candidate is preserved for
future evidence-driven work without claiming a match.
