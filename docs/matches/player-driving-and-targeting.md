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

## Orientation, debug rendering, and teleportation

The related orientation and debug methods reuse recovered Character vector and
rendering interfaces. Orientation copies facing components individually, as in
the retail instructions, and retains the observed float at PlayerTest offset
336 without assigning an unproven semantic name. Debug rendering reuses the
Character implementation with the original 200-unit axis scale.

Teleportation recovers secondary virtual slots 38 (setNextAnimation) and 40
(setAnimation with an integer animation ID). It retains the already matched
CHudManager::walking definition from its native dependency and verifies that
callee in the PlayerTest image as well. The original game behavior and class
extent are unchanged.

The scoped command exited 0 with these comparisons:

```text
OK  _ZN10PlayerTest13orientTowardsEN3irr4core8vector3dIfEE  0x00302241  288 bytes
OK  _ZN10PlayerTest5debugEPN3irr5video12IVideoDriverE  0x003020f1  336 bytes
OK  _ZN10PlayerTest10teleportToEPK11LevelObject  0x00304895  336 bytes
OK  _ZN11CHudManager7walkingEv  0x00323b01  52 bytes
```
