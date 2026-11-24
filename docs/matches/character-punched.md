# Character::punched: exact 884-byte reconstruction

Target `_ZN9Character7punchedEiiP11LevelObject`, Thumb `0x002f6c45`, original
source `Character.cpp`. The complete function, native switch table and all
existing matches pass the original ARM GCC 4.2.1 comparison workflow.

## Reused construction and voice patterns

The retained full-expression event candidate was 868 bytes. Separate bounded
controls established the missing compiler context without changing headers,
class layouts, compiler policy or game behavior:

- Placement construction retains the native base and derived vptr stores for
  the genuine `EvNPC` and `EvPlayer` classes, using existing `IEvent(16)` and
  `IEvent(22)` constructors.
- Explicit weak D1 declarations, already used by matched local factory and
  Vehicle code, preserve native GOT-indirect calls to actual compiled event
  destructors. Attribute-free aliases instead produced direct calls.
- The real NPC storage remains in the containing block while Player storage
  occupies its conditional block. Their overlapping lexical lifetimes retain
  the native 56-byte frame and distinct `sp+28` / `sp+44` homes. Both buffers
  construct actual events; no dummy storage or padding is introduced.

The EventManager is captured once. NPC destruction precedes the category read;
Player destruction precedes lock cleanup. This produced the exact native event
block but left nine voice branch/constant-layout bytes unmatched.

The final control reuses an already exact source pattern from
`Character::hijacked`: `switch(driverBehavior)` with `case 0` before `default`.
Only the three retained ternary voice assignments change to equivalent nested
switches. Zero retains IDs 245/231/240; nonzero retains 242/238/237. This resolves
all remaining bytes without changing the mapping, adding branch hints or
editing compiler output.

## Exact canonical verification

Reproduce with:

```text
python tools/build.py ai-startup-character --baselib <local-retail-library>
```

Exact output:

```text
OK  _ZN9Character7punchedEiiP11LevelObject  0x002f6c45  884 bytes
OK SECTION .character_punched  0x002f6c44  884 bytes
OK SECTION .character_punched_table  0x0041c564  220 bytes
```

Both complete function and complete section match all 884 retail bytes. Target
SHA256 is `8a01b6d322da2e0bbfc27c0a4fd071e483a47ce60e51dcfa171bb9df5d79bdfa`.
The native 220-byte switch table is checked separately. Strict shared linker
assertions preserve their native ends at `0x002f6fb8` and `0x0041c640`.

The shared placement is also available to NPC and PlayerTest dependency images.
Their obsolete external Thumb declarations for punched are removed, so the real
compiled definition cannot be overridden by a retail fallback. All ten actual
event helper/vtable definitions remain selected at native addresses and exact;
no ABS/import substitute masks an uncompiled helper.

The private control preserves all 149 off-target allocated sections and 815
semantic relocation records, existing definitions and imports. The complete
canonical prefix remains byte-identical; no preexisting decompiled body changes.

## Global acceptance and progress

The coordinator independently rechecked the private full function, section,
switch and original 114/33 owning-profile comparisons before integration.
Canonical integration initially failed on legacy linker assertion syntax;
the failure is preserved. Assertions were moved into the existing shared
`CharacterStateSections.ld` format without relaxing either native extent.

A fresh complete preservation run then passes **191 profiles / 11,125 exact
comparisons**: 5,461 function, 5,483 section and 181 region checks. All 1,122
recorded inputs stay hash-identical during the run. Every one of the 4,291
previously credited entries and the new punched function has direct successful
comparison coverage, with no gaps. Only afterward is its assembly marker removed.

A final EOF blank-line cleanup is checked by rebuilding the owning dependency
closure. The entire emitted Character object stays byte-identical, SHA256
`8876e0d7241cbc5335461ab10d5da5be459e8912b6cd052104406cc2a72cf181`;
all owning comparisons still pass. This formatting change alters no linked
input bytes from the complete preservation run.

Regenerated tables preserve all 17,703 original identities and change only this
function's status. Local Matched/Fuzzy progress becomes **4,292/4,550 functions,
356,686/561,716 bytes (63.50%)**. Character remains incomplete, so Fully Linked
stays **114,548 bytes (20.39%), 126/203 reporting units**. Publication follows the
maintainer's combined hourly PR workflow.

The historical nine-byte candidate remains in
`nonmatching/characters/Character-punched-placement.*`; it is superseded and
must not be applied over the matched implementation. Exact controls and source,
object, ELF, maps and logs remain under
`_scratch/heartbeat-20261124-character-punched/paired-control/voice-only/`.
Independent review: `_scratch/root-punched-voice-review.*`.
Failed and accepted global runs:
`_scratch/character-punched-integration/` and
`_scratch/character-punched-integration-pass2/`. The repeated final global
receipt is `_scratch/character-punched-integration-final/`; EOF cleanup proof is
`_scratch/character-punched-eof-cleanup/`.
