# Civilian controller lifecycle

CivAgressiveController reuses the recovered NPCController interface. Its
destructor detaches event IDs 16 and 22, fetching the application and event
manager separately for each call, then lets C++ perform base cleanup. The
compiler emits both complete/base aliases and the deleting destructor normally.

Verification command:

```sh
python tools/build.py ai-startup-civagressivecontroller
```

Exact output:

```text
OK  _ZN22CivAgressiveControllerD1Ev  0x00340945  64 bytes
OK  _ZN22CivAgressiveControllerD2Ev  0x00340945  64 bytes
OK  _ZN22CivAgressiveControllerD0Ev  0x00340901  68 bytes
OK SECTION .civ_aggressive_vtable  0x004acf98  24 bytes
```

All existing startup callbacks, strings, and GOT checks in this unit also pass.

## Passive controller

The passive controller uses the same proven event detachment and base cleanup
sequence. `python tools/build.py ai-startup-civpassivecontroller` exited 0 with
all existing comparisons preserved:

```text
OK  _ZN20CivPassiveControllerD1Ev  0x00340c35  64 bytes
OK  _ZN20CivPassiveControllerD2Ev  0x00340c35  64 bytes
OK  _ZN20CivPassiveControllerD0Ev  0x00340bf1  68 bytes
OK SECTION .civ_passive_vtable  0x004acfb0  24 bytes
```

## Guard controller

The guard controller reuses the same two event detachments and native base
cleanup. `python tools/build.py ai-startup-guardcontroller` exited 0 with all
existing comparisons preserved:

```text
OK  _ZN15GuardControllerD1Ev  0x00341d25  64 bytes
OK  _ZN15GuardControllerD2Ev  0x00341d25  64 bytes
OK  _ZN15GuardControllerD0Ev  0x00341d65  68 bytes
OK SECTION .guard_vtable  0x004ad000  24 bytes
```

## Derived controller constructors

The aggressive, passive, and guard controllers reuse NPCController's recovered
constructor and original transition storage. Their event attachments preserve
separate application/event-manager calls. The aggressive and passive controllers
advance an NPC waypoint only for initial state 1. The guard controller clears
the observed NPC flag before attaching events and entering its original state.
Friend declarations grant access to already recovered fields without changing
layout or existing implementations.

The integrated command checked all three derived units, NPCController, and NPC:

```sh
python tools/build.py ai-startup-guardcontroller ai-startup-civagressivecontroller ai-startup-civpassivecontroller ai-startup-npccontroller ai-startup-npc
```

It exited 0, preserving every existing comparison:

```text
OK  _ZN15GuardControllerC1EP3NPCN8gameloft2ai7StateIDE  0x00342221  104 bytes
OK  _ZN15GuardControllerC2EP3NPCN8gameloft2ai7StateIDE  0x00342221  104 bytes
OK  _ZN22CivAgressiveControllerC1EP3NPCN8gameloft2ai7StateIDE  0x00340985  96 bytes
OK  _ZN22CivAgressiveControllerC2EP3NPCN8gameloft2ai7StateIDE  0x00340985  96 bytes
OK  _ZN20CivPassiveControllerC1EP3NPCRKN8gameloft2ai10TransitionENS3_7StateIDE  0x00340c75  96 bytes
OK  _ZN20CivPassiveControllerC2EP3NPCRKN8gameloft2ai10TransitionENS3_7StateIDE  0x00340c75  96 bytes
```

## Cop controller destruction

The cop controller conditionally clears its observed static arrest flag, then
uses one cached event manager to detach event IDs 16, 23, 24, and 22. Its observed
Boolean at offset 20 follows the existing 16-byte base and a four-byte opaque
field. The static flag remains a retail import; no replacement game state is
introduced.

`python tools/build.py ai-startup-copcontroller` exited 0 with all existing
function, vtable, startup, and GOT comparisons preserved:

```text
OK  _ZN13CopControllerD1Ev  0x00340f49  104 bytes
OK  _ZN13CopControllerD2Ev  0x00340f49  104 bytes
OK  _ZN13CopControllerD0Ev  0x00340edd  108 bytes
OK SECTION .cop_vtable  0x004acfc8  24 bytes
```

## State dispatch and civilian events

The recovered state handlers preserve each controller's original control flow,
NPC operations, target selection, event construction, and state-store ordering.
The cop and guard switch tables are compared as complete 44-byte sections.
The cop constructor preserves its cached event manager and four attachments.
Civilian event handlers reuse EvPlayer's inline getState accessor, and retain
all seven existing event helper sections through PlayerEventSections.ld.
CharacterRecoveredSections.ld includes the same shared fragment, preserving
its existing output section names and addresses.

StateID now declares its observed signed 32-bit range with an explicit minimum
integer range marker. This marker is an ABI declaration, not a claimed gameplay
state or an inferred original enumerator name. The original RaceDriving name is
retained; other recovered states use numeric cases until their names are known.
TransitionCondition includes the observed comparison value 21. Without the
signed range, GCC eliminates valid states or uses unsigned branch conditions.

Validation caught an existing NPC::equipWeapon register-order difference after
unused provisional numeric StateID names were added. Removing those unused
names while retaining the signed range restored the complete original function.
No existing matched implementation was edited. The integrated checks also
rebuild NPC and PlayerTest dependencies to prove this preservation.

The combined scoped build exited 0 for the four controller units and PlayerTest,
with all dependencies, functions, tables, strings, and GOT comparisons passing:

```text
OK  _ZN15GuardController11switchStateEN8gameloft2ai7StateIDENS1_19TransitionConditionE  0x003420cd  340 bytes
OK SECTION .guard_switch_table  0x00431814  44 bytes
OK  _ZN22CivAgressiveController7onEventEPK6IEventPK12EventManager  0x0034084d  92 bytes
OK  _ZN22CivAgressiveController11switchStateEN8gameloft2ai7StateIDENS1_19TransitionConditionE  0x003408a9  86 bytes
OK  _ZN20CivPassiveController7onEventEPK6IEventPK12EventManager  0x00340cd5  148 bytes
OK  _ZN20CivPassiveController11switchStateEN8gameloft2ai7StateIDENS1_19TransitionConditionE  0x00340b6d  132 bytes
OK  _ZN13CopController11switchStateEN8gameloft2ai7StateIDENS1_19TransitionConditionE  0x00341139  460 bytes
OK  _ZN13CopControllerC1EP3NPCN8gameloft2ai7StateIDE  0x00341305  124 bytes
OK  _ZN13CopControllerC2EP3NPCN8gameloft2ai7StateIDE  0x00341305  124 bytes
OK SECTION .cop_switch_table  0x00430c48  44 bytes
```
