# Touch beginning: rejected inline initializer helper

Target: `TouchScreenBase::touchBegan(const Point2D<short>&, long)`, Thumb
`0x0034ccf1`, native 140 bytes. Base: main PR #742, `30e19c51`.
The patch is unapplied and unmatched; no matched or Fully Linked credit.

After the six source forms, the unchanged-source RTL audit and the rejected
hot-branch hint, this separately bounded experiment tests one ordinary inline
reference helper for inactive-slot initialization. The helper receives the
first point, direction, count and input point by reference. It preserves both
input-coordinate snapshots, the stores and their source order. There are no
hints, attributes beyond standard inline, register pins, barriers, new fields,
compiler-option changes or output edits. No additional helper variants were
tried. The ordinary prelink guard confirms that only the target is newly
emitted; the helper is fully inlined.

The result is byte-identical to the retained unhinted candidate: 140 bytes,
seven differing bytes, first difference `0x32`, linked SHA256
`9452611f1b628eff572d8f83b9ec64e5037666ac4b3aaed4e7d8ab081b82e11d`.
The active-value/first-address register conflict is unchanged. The exact normal
comparison failure is:

```text
MISMATCH  _ZN15TouchScreenBase10touchBeganERK7Point2DIsEl  0x0034ccf1
MISMATCH SECTION .touch_began
  expected : db 00 58 19 07 1c 30 37 3c 79 00 2c 22 d1 b2 88
  actual   : db 00 58 19 07 1c 30 37 3b 79 00 2b 22 d1 b2 88
  differs at 0x32
```

All 35 existing functions, all 44 existing sections and the GOT region pass.
The added complete 28-byte message section also passes, giving 45 passing
sections in the diagnostic run. Build exit is 1. No derived-consumer or new
full-project proof is claimed for this rejected patch. The production source,
profiles, linker script, assembly marker and generated progress are unchanged.
Ownership is released after coordinator review. Further source search requires
new evidence rather than another helper or branch-probability grid.

Set `WCH_BASE_LIB`, apply this patch in an isolated checkout and run
`python tools/build.py string-startup-touchscreenbase`. The native 140-byte
extent assertion and all ordinary binding, overlap and comparison guards remain
active. The compiled `_trace` definition remains a real definition, not an
external import.
