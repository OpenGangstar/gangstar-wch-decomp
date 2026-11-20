# NPC attack animation receiver correction

Unapplied, unmatched reconstruction of NPC::attackTarget() at Thumb 0x002ff5d1.
The first animation-164 test applies to the target Character. The subsequent
animation-164 test applies to the attacking NPC. The earlier candidate tested
the owner twice. This corrects behavior; it does not earn matching credit.

Native loads the target into R0 at 0x002ff616. Category-5/8 branches reach
0x002ff7c6, which sets only R1 before calling isCurrentAnimation. The separate
owner test sets R0 from this at 0x002ff630. The corrected C++ and emitted call
sequence preserve both receivers. All other candidate operations remain intact.

The patch includes private nonvirtual declarations, two existing event-state
names, the current IrrlichtDevice include and strict native comparison selectors.
It changes no existing function body, layout, virtual slot or compiler setting.
The original incomplete-device compilation failure is preserved separately in
the private audit; subsequent prerequisites and the corrected candidate compile.

Apply only in an isolated checkout at the recorded baseline commit:

```sh
git apply --unidiff-zero nonmatching/ai/NPC-attackTarget-target-receiver.patch
```

The coordinator independently applies this final public patch in a fresh current
source/configuration/tool mirror. Actual target and full section remain 2084
versus native 2108 bytes, linked SHA256
`6689327faeee3cca2793de24413d4cb2f516ebf2cceffe944ccb4ad2fb81ebd2`.
Comparison exits 1:

```text
MISMATCH  _ZN3NPC12attackTargetEv  0x002ff5d1
  expected : d5 f7 54 fe 82 24 64 00 b5 4d 80 46 86 6b 38 59
  actual   : d5 f7 54 fe 82 24 64 00 a4 4e 80 46 85 6b 38 59
  differs at 0x18
```

All 223 existing function comparisons and 59 section/region comparisons pass;
886 frozen inputs remain stable. The only new object definition is the assigned
function. Native fixed-address extent checks pass without moving any neighbor;
the following pending NPC::Update body is not newly compiled in this image.
The whole-function/full-section mismatch remains authoritative. Do not confuse
these existing-match checks with acceptance of the pending target.

No canonical source/header, assembly marker, classification or progress credit
changes. No extra source forms, hints, padding, assembly or output editing were
used. The preceding incorrect control reproduces the historical 2088-byte image;
its closer positional agreement is not a reason to retain the wrong receiver.
