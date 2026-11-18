# Application singleton and lifecycle wrappers

The recovered Application has a native 180-byte extent: IEventReceiver base,
four eight-byte registration-list sentinels, existing service pointers/flags,
and a real 24-byte monitored-pointer map record. The licensed STLport storage
view supplies only the three actual list specializations, avoiding collisions
with existing unrelated containers. The original constructor and destructor
remain native imports; neither a parked constructor nor an invented object
initialization body is introduced.

The singleton uses ordinary C++ function-local static storage. Both verification
images retain and compare its actual executable definition and GCC cleanup:

```text
OK  _ZN11Application11GetInstanceEv  0x002d528d  84 bytes
OK  __tcf_4  0x002d5d89  28 bytes (compiled: __tcf_1)
```

The existing explicit callback selector accounts for GCC's numbering in this
partial translation unit; no symbol or compiler output is rewritten. Its native
four-byte LOCAL guard at 0x004b684c and 180-byte LOCAL NOBITS instance at
0x004b6850 are checked independently and enforced by linker size assertions.
The callback is a separately catalogued game function and receives credit only
for its complete executable byte comparison.

Nine existing method expressions are mechanically updated for genuine member
addresses: three unregister methods, four register methods and two monitored-map
methods. Algorithms and comments remain unchanged. Their complete original bytes
must still compare exactly, alongside every old Application match. This change
is explicitly recorded in the integration commit rather than hidden as new work.
Historical partial-layout comments are retained and marked superseded.

The same coherent layout permits these independently reconstructed wrappers:

```text
OK  appDeinit  0x002d26f1  36 bytes
OK  appOnAccelerometer  0x002d25a9  124 bytes
OK  appPause  0x002d2731  36 bytes
```

Shutdown stops all sounds, unloads big sounds with -1 and unconditionally calls
the native Quit. Pause calls the matched Application::Pause before clearing the
resume timer. Accelerometer updates the three real imported float globals with
0.11f, caches each updated value, then dispatches moved through the actual
accelerometer pointer/virtual slot when both device and application exist.
The recovered pointer is directly exposed in the native layout view, avoiding
additional accessor or friendship declarations. Shutdown imports the genuine
mangled Quit entry with its explicit Application* ABI; the native C++ member
implementation remains pending and receives no credit. This is a normal symbol
import, not a replacement body, alias, or compiler-output edit.

The earlier partial-layout/friendship context changed one ADD encoding in
WeaponManager::unlockWeapon. A normal getter alternative restored that match
but perturbed existing Cash and SceneNodeManager code generation. The final
layout view and direct native Quit import preserve the complete new functions
and restore WeaponManager, InfoHelp, Cash and SceneNodeManager comparisons
without editing those implementations. Failed full-gate logs are retained;
only the final fully verified context may receive matching credit.

All eight wrapper images retain and compare the new wrapper definitions at
native addresses. Both singleton images retain the new code and storage.
Adding the singleton exposed old unplaced Application methods in GSFade; those
already-matched executable sections now have explicit original-address selectors
and comparisons, with genuine Thumb imports. No bytes, ABI or implementations
are substituted to bypass linker overlap checks. Windows sources are unchanged.

Final coordinator `python tools/build.py --all` passed all 181 profiles and
9,935 function/section/GOT comparisons, exit zero. Final proof:
_scratch/application-canonical-import-full.log and .exit. Earlier friendship
and getter contexts failed and receive no credit; their logs are retained as
_scratch/application-canonical-root-full.log and
_scratch/application-canonical-getter-full.log.
