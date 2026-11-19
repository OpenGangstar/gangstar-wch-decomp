# NPC freeze: rejected voice likelihood

Target `NPC::freeze()`, Thumb `0x002fe999`, native 224 bytes. Baseline main
PR #743, `68f0bc30`. These patches remain unapplied and unmatched; no credit.

The archived canonical candidate differs at three bytes in its second voice
branch: condition orientation and the physical placement of IDs 76/73. One
bounded escalation tests `__builtin_expect(driverBehavior != 0, 1)` only in
that conditional expression. Cases, payload IDs, state changes and ordinary
compiler flags remain intact. The private translation-unit MovementFlags view
names the previously unnamed frozen bit at position four; storage and all
existing named bit positions remain unchanged. No header changes are needed.

The hint worsens the result: still 224 bytes, but 19 differing bytes beginning
at 0x64. It rearranges the negative-remainder tail as well as the voice branch.
Linked SHA256: `a8ace81765ec1a7a9e7c04f3de4bd0ebef877fc66c6873a21c9ce6710407a4ea`.
No opposite hint or further probability values are tried. The better unhinted
candidate is retained. A subsequent unchanged-source control under the SAME
current metadata and verified NDK enum default reproduces the complete archived
unhinted executable, including exactly three differing bytes at 0x83/0x84/0xb8.

Both valid normal runs preserve the owning NPC profile's 71 functions, 14
sections and GOT region, plus its dependencies: Character 114/32/1 and
PhysicsAttributes 38/10/1 (function/section/region checks). Target and full
224-byte section fail, exit 1. No new whole-project proof is claimed.

Exact unhinted control failure:

```text
MISMATCH  _ZN3NPC6freezeEv  0x002fe999
MISMATCH SECTION .npc_freeze
  expected : d1 f0 23 eb 58 00 2b 19 d0 4c 23 98 46 14 4b 8c
  actual   : d1 f0 23 eb 58 00 2b 19 d1 49 23 98 46 14 4b 8c
  differs at 0x83
```

Set WCH_BASE_LIB and apply NPC-freeze-current.patch in an isolated checkout;
run `python tools/build.py ai-startup-npc`. NPC-freeze-voice-likelihood.patch is
an optional DELTA requiring the baseline patch first. Native placement, extent,
binding, overlap and comparison guards remain enabled. No output editing,
register pins or barriers are used. The failed GNU hint and the private frozen
bit view are never integrated into production. Original assembly, existing
matched source and generated progress remain unchanged. Coordinator review
releases ownership; further voice-expression searches require new evidence.
