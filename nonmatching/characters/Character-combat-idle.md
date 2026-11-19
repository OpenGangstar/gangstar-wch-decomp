# Character combat idle: plain separate-handler candidate

This function is **not matched**. Its native executable section is 300 bytes at
Thumb `0x002f2581`. The candidate has the same extent but differs at two
animation immediates and corresponding switch-table destinations. Its assembly
marker remains pending and no progress is credited.

Baseline: `cd3301292ca3e38471e30a6a944ae0f9581b7b53` (PR #739). Apply only in an
isolated checkout:

```powershell
git apply --check nonmatching/characters/Character-combat-idle.patch
git apply nonmatching/characters/Character-combat-idle.patch
$env:WCH_BASE_LIB = 'C:/path/to/your/libsanangeles.so'
python tools/build.py ai-startup-character
```

Expected exit: **1**, with failures for the new function, full section and full
switch table. Existing comparisons must remain exact.

## Bounded transfer and exact differences

The six archived forms included separate duplicate handlers only with a branch
hint. Following the ready-function layout evidence, one bounded transfer uses
those handlers without a hint. No flag store, condition, animation ID, class
layout, existing function body or shared helper changes. A numeric reordering
of the separate cases emits the identical complete target and table; that
straightforward numeric-order source is retained. No further case/return/hint
variants were attempted in this escalation.

Only two executable bytes differ:

| Offset | Native immediate | Candidate immediate |
| --- | ---: | ---: |
| `0x76` | 59 | 73 |
| `0x9a` | 73 | 59 |

The complete 36-byte table at `0x0041bcf4` follows the exchanged handlers. Eight
bytes differ, at offsets `0x08`, `0x09`, `0x0c`, `0x0d`, `0x10`, `0x11`, `0x18`
and `0x19`. Cases retain their intended animation mapping; the difference is
physical layout. No executable or table bytes may be patched to claim a match.

```text
MISMATCH  _ZN9Character14goToCombatIdleEv  0x002f2581
  expected : 01 93 a0 23 d4 58 28 1c 3b 21 2b 4a 01 23 a0 47
  actual   : 01 93 a0 23 d4 58 28 1c 49 21 2b 4a 01 23 a0 47
  differs at 0x76
```

Both tested forms have complete unlinked target SHA256
`b3c9605f1f88e0a0ae086c32327eabd8d4b46f598e736b8f274d67cf26c938af`.
Only the new target is emitted. The owner retains **113 existing function
checks, 31 section checks and one GOT region check**. Normal GNU ld overlap
checking and strict 300/36-byte extent assertions remain enabled. This is an
owner/dependency proof, not a new 190-profile run. The unapplied patch changes
no production source, compiler settings, shared header or matching credit.
Further ordering searches require new evidence.
