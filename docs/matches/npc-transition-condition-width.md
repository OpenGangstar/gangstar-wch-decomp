# Full-word NPC transition conditions

The recovered `gameloft::ai::TransitionCondition` declaration contained only
values 0 and 21. With the matching ARM compiler, that declaration occupies one
byte. Casting the integer NPC-event payload into this enum emits two shifts
that truncate it to eight bits. The retail NPCController dispatcher instead
loads the complete word from event offset 8 and forwards it unchanged in r2
to the virtual switchState call at `0x003422e8`.

Add `TransitionConditionForceWidth = 0xffffffffu` as a declaration range marker.
It is not a recovered gameplay state. The compiler now gives the enum four-byte
storage and preserves every condition payload bit. Existing named values,
method signatures, virtual slots and data members are unchanged. No existing
function implementation or build option is edited. The marker changes an
incorrect partial type declaration; it does not establish the original enum's
complete list of names or independently prove its original signedness.

Native-compiler diagnostics confirm sizeof values 1 before and 4 after. A
separate signed four-byte marker was evaluated and rejected in favor of the
explicit unsigned full-range marker. An intermediate 0x7fffffff marker also
passed old checks but does not establish unsigned full-range conversion; it
was not adopted. Only the final 0xffffffffu declaration is integrated.

A signed header-only trial passed all 190 profiles: 5,432 functions, 5,336
sections and 181 regions, totaling 10,949 comparisons; no failures or skips.
For the final unsigned declaration, quoted-include reachability identifies six
affected profiles: AIManager, CivAgressiveController, CivPassiveController,
CopController, GuardController and NPCController. All six passed again:
63 functions, 68 sections and six regions, totaling 137 comparisons. Private
and production source/configuration/tool/nonmatching inputs stayed frozen
during each gate. A complete input comparison before integration found only
the intended NPCController.h difference. This is a 190-profile preliminary
gate plus the final affected-header closure, not a claimed second full
190-profile run with the final declaration.

Representative final comparison output:

```text
OK  _ZN22CivAgressiveController11switchStateEN8gameloft2ai7StateIDENS1_19TransitionConditionE  0x003408a9  86 bytes
OK  _ZN20CivPassiveController11switchStateEN8gameloft2ai7StateIDENS1_19TransitionConditionE  0x00340b6d  132 bytes
OK  _ZN13CopController11switchStateEN8gameloft2ai7StateIDENS1_19TransitionConditionE  0x00341139  460 bytes
OK  _ZN15GuardController11switchStateEN8gameloft2ai7StateIDENS1_19TransitionConditionE  0x003420cd  340 bytes
OK  _ZN13NPCController11switchStateEN8gameloft2ai7StateIDENS1_19TransitionConditionE  0x00342289  2 bytes
```

The accompanying [callback candidate](../../nonmatching/ai/NPCController-onEvent.md)
still emits 94 versus 96 native bytes and remains unapplied. Its assembly and
pending status remain. This prerequisite adds no matched functions or bytes;
Matched, Fully Linked and Fuzzy Matched progress are unchanged. No Windows
implementation or launcher change is included.
