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
