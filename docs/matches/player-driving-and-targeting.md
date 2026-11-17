# Player driving, shooting, and target acquisition

The PlayerTest translation unit reconstructs target acquisition, driving entry,
driving exit, and shooting. The shooting adjustment thunk is emitted naturally
from the recovered virtual override; it contains no handwritten instructions.

The shooting and driving methods reuse the existing EvPlayer class. Its
constructor initializes IEvent with event ID 22. The existing complete and
deleting destructors and event vtable are retained at their original addresses.
The shared linker sections accept the ordinary weak definition selected by GNU
ld from either Character or PlayerTest, including profiles that put the primary
source object first. No compiled bytes are modified.

PlayerTest's observed layout now names the PhysicAttributes pointer at offset
28 and the transition flag at offset 260. Both refinements preserve the existing
class extent. The shooting override occupies the existing secondary interface
slot 41 and is declared after the pending destructor, preserving key-function
ownership of the unrecovered PlayerTest vtable.

Verification command:

```sh
python tools/build.py ai-startup-playertest
```

Exact comparison output:

```text
OK  _ZN10PlayerTest13acquireTargetEv  0x003035d1  72 bytes
OK  _ZN10PlayerTest12startDrivingEv  0x00303ab9  160 bytes
OK  _ZN10PlayerTest5shootEfb  0x00303b6d  76 bytes
OK  _ZThn4_N10PlayerTest5shootEfb  0x00303b58  20 bytes
OK  _ZN10PlayerTest11stopDrivingEN10playertest14PlayerCarState15ePlayerCarStateEb  0x00304701  404 bytes
```

The target-selection helper and Character shooting implementation remain retail
imports and are not credited by these matches. All existing function and section
comparisons in the dependency graph run alongside the new checks.
