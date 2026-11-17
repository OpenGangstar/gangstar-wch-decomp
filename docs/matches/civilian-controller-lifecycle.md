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
