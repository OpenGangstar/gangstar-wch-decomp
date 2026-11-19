# Application::_Update(int)

The 106-byte Thumb function at `0x002d4a01` matches the retail library exactly.
It walks the actual updatable registration list, converts the signed elapsed
argument to double once, updates each registered object and the state machine,
then performs the original menu and device calls.

## Reconstruction

`ApplicationListIterator.h` adapts the licensed STLport iterator interface over
the existing eight-byte sentinel and twelve-byte node records. It preserves the
user-defined iterator copy/conversion constructors, reference dereference,
reference-returning prefix increment and by-value const-iterator comparison.
These genuine interfaces produce the original shared bottom comparison; the
previous raw-pointer candidates did not match. No branch hint, forced register,
inline attribute, compiler flag change or compiler-output modification is used.

Reference: Android external/stlport commit
`e64e7c849b0b659d3e198e4efaed563601e554be`, `stl/_list.h`, lines 82â€“151.
The upstream file SHA-256 is
`3fab6aac009441bfa909cfba78bf84f4850f52aed48217f574082570ef000c29`.
The exact retail STLport revision is not established. The adaptation retains the
upstream license. All iterator helpers inline naturally; only the target function
and its text section are newly emitted, with no additional data or helper bodies.

Two missing declarations are restored without changing layouts or adding slots:
`MenuManager::update(StateMachine*)` and `ISceneManager::getParameters()` in
existing slot 72. The latter is corroborated by Irrlicht 1.4.2's interface and
the retail CSceneManager vtable: address point `0x004845a0`, slot 72,
function `0x002177e9`. The menu update is the actual Thumb import at `0x002e4e7d`;
its unused return type remains inferred as void.

## Verification

The comparison output is:

```text
OK  _ZN11Application7_UpdateEi  0x002d4a01  106 bytes
OK SECTION .application_update  0x002d4a00  108 bytes
```

Function SHA-256:
`f3952785cc4c9711cd3b950d5b7576f3579f739ec9945d721171656e51ca4ff9`.
The section includes the original two-byte `c046` alignment NOP before LogoDraw.
The owning profile retains every previous 74 function and 45 section/region
comparison, plus its JNI dependency. The target's former retail Thumb import
is removed so its real compiled definition is verified. No neighbor is moved
and no compiled definition is replaced by an absolute binding.

Initial setup failures were missing declarations, the deliberately rejected
compiled-target/import conflict, and a duplicate external import. They were
corrected in configuration without changing the candidate source.

The final combined current-root verification passes all 190 profiles and
10,539 comparisons: 5,266 functions, 5,092 sections and 181 regions.
All previously configured comparisons are retained. The matched-function
catalogue is regenerated only after this successful gate. These sources remain
incomplete overall and receive no additional Fully Linked credit.
