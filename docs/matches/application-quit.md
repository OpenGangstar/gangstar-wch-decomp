# Application::Quit

The saved reconstruction is reused unchanged with the current recovered renderer
and completed Init/InitWin32/destructor implementations.

```text
OK  _ZN11Application4QuitEv  0x002d4cd1  368 bytes
```

The method preserves optional SaveGame construction/destruction, sound cleanup,
achievement clearing, signed-positive state-stack draining, 3D teardown, opaque
owned-resource disposal, manager/input/filesystem destruction and null stores,
vehicle sound unregistration, device close/drop, the native renderer-drop
condition and FileManager shutdown. The device pointer is not cleared afterward,
and the unusual material cleanup condition is retained exactly.

IrrlichtDevice now has its real virtual IReferenceCounted base and virtual
destructor slots. The recovered reinitDriver API and all existing virtual-method
positions are preserved. This supplies the native virtual-base adjustment before
drop rather than a guessed fixed offset. SDK declarations/native vtable evidence
are preserved in the saved prerequisite audit. No engine implementation is added.

Application's existing opaque four-byte slot at offset 60 becomes an opaque
pointer of the same extent. Its concrete class remains unknown: the native
operation calls deleting-destructor slot 1 with the unchanged receiver, represented
by an explicit C++ function-pointer dispatch. No fake class, vptr assignment or
object extent is invented. Offset 52 retains its direct guarded operator delete.
The genuine GS3DStuff teardown and Quit declarations are added.

Both consumer images retain the compiled Quit body at its native address and
explicitly compare it. Existing compiled script/HUD dependencies remain real
providers, and pending APIs use actual native imports. No existing decompiled
body changed during this integration; no new source forms were needed.

Fresh `python tools/build.py --all`: 182 profiles, 10,258 exact
function/section/GOT comparisons, exit zero. All earlier matches pass, including
Cash, SceneNodeManager::crc, sprite/input, renderer and initialization paths.
Local proof: _scratch/application-quit-integrated-full.log and .exit.
An initial setup script stopped at a class-declaration spelling assertion before
compilation; it made no byte-match claim and was completed using the actual class.
No compiler output, Windows port source or build settings were modified.
