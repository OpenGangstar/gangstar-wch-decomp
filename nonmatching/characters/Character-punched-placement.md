# Character::punched: preserved unmatched placement candidate

Historical candidate, superseded by the verified implementation described in
[Character::punched match](../../docs/matches/character-punched.md). The patch
targets the earlier prefix and must not be applied over current matched source.
The failure and control history below describe that preserved earlier candidate.

Target `_ZN9Character7punchedEiiP11LevelObject`, Thumb `0x002f6c45`, 884 bytes.
`Character-punched-placement.patch` appends the retained helper and candidate
to `src/game/characters/Character.cpp`; it is **not applied** to canonical source.
The assembly marker remains pending and this candidate earns no progress.

The baseline prefix SHA256 is
`a02afdc09876341c78c89da7cb7aeab1c4c5727b56cefaa049fd0f953b33dd72`.
The complete tested source SHA256 is
`453084f94089f1552f43323464ae67037d56192e5e2c9feaf45e02bdd0c650ab`.

## Bounded construction controls

Historical source forms and budgets were retained. A fresh current-prefix
temporary baseline reproduced the 868-byte near miss. Three separately
authorized controls then established specific compiler behavior:

1. Real placement construction retains both native base-vptr stores. Two
   attribute-free C-linkage D1 declarations incorrectly produce direct calls;
   the function stays 868 bytes and fails its strict pre-link size gate.
2. Existing sibling-style weak declarations restore native GOT-indirect D1
   calls and the full 884-byte extent. Separate nested unsigned-storage scopes
   still coalesce into a 40-byte frame and one `sp+24` slot.
3. Removing only the NPC storage's inner scope keeps both real event buffers
   in overlapping lexical lifetimes. Native 56-byte frame and distinct
   NPC `sp+28` / Player `sp+44` homes return. Explicit NPC destruction still
   precedes the category read; Player destruction precedes lock cleanup.

The final complete event block, offsets `[0x288,0x2f4)`, is byte-identical to
retail. The captured EventManager, genuine C++ destructor definitions, event
payloads, switch table and cleanup order remain intact. No header, class layout,
compiler policy, output byte or helper implementation was changed.

## Exact remaining failure

The coordinator independently repeated the comparison on the actual final ELF:

```text
MISMATCH  _ZN9Character7punchedEiiP11LevelObject  0x002f6c45
  expected : e7 f0 23 f3 58 00 2b 00 d0 88 e0 f5 23 9a 46 0e
  actual   : e7 f0 23 f3 58 00 2b 00 d1 88 e0 f2 23 9a 46 0e
  differs at 0x225
```

The complete 884-byte section fails at the same offset. All nine differing
byte offsets are `0x225`, `0x228`, `0x325`, `0x326`, `0x333`, `0x334`,
`0x33a`, `0x340` and `0x346`. They concern voice-selection branch and constant
placement; the current source still maps nonzero/zero `driverBehavior` to the
same voice IDs as retail. Do not describe this as a proven behavioral bug or
change the mapping to chase bytes.

All existing 114 function and 33 section/region checks pass in that same image,
plus the native 220-byte switch-table check. Ten real event helpers/vtables are
selected at native addresses and match; no imported/ABS substitute replaces
them. Off-target allocated payloads, definitions, imports and semantic
relocations remain unchanged. No successful whole-project integration is
claimed for this unapplied patch.

Final linked ELF SHA256:
`3aa8dbb3f532ecf8192f34af06fd41c287d62954a9f22f99c48de55b10839727`.
Target SHA256:
`40f36039e83543c9c93e3c3cdd22457df8cbba407ca160d0a856f101b603d01a`.

The construction/lifetime controls are spent. Preserve the candidate; revisit
voice control-flow lowering only with new evidence or a separately bounded
coordinator escalation. Do not repeat an event, scope, constructor or flag grid.
Full source/object/ELF/log/linker/map/input proofs remain under
`_scratch/heartbeat-20261124-character-punched/paired-control/lexical-lifetime/`.
Private replay scripts and prior controls remain in the containing packet.
