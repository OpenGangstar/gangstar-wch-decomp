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
