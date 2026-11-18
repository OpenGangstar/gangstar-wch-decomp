# Application::Init

The saved first reconstruction is reused unchanged with the current canonical
180-byte Application layout and completed InitWin32 prerequisite.

```text
OK  _ZN11Application4InitEPN3irr14IrrlichtDeviceE  0x002d5591  656 bytes
OK  _ZNK16SceneNodeManager3crcEPKc  0x003215b5  58 bytes
```

The function preserves native filesystem/receiver setup, sprite transform,
EventManager construction and group initialization, concrete manager allocations,
update/drawing registration, timer/random seed, frame rate, achievements, menu
language/preferences, movie-state transition and material-renderer creation.
Concrete allocation extents come from recovered classes, with no fabricated
objects. EventManager grants only Application access to its existing private
initialization fields. Pending APIs and engine implementations remain imports.
StringManager::loadStyles is called for side effects; these callers do not
establish a meaningful return value, and the declaration uses a void call view.

Renderer declarations are extracted from the existing translation unit; existing
method bodies and comments remain unchanged. The two genuine forwarding
constructors reproduce the native 20-byte object and imported VTT/vtable.
The existing CCustomMaterialRenderer API spelling aliases the recovered concrete
class. Setup/font/preferences declarations are added without dropping newer APIs.
The two original text-style/achievement literals are retained and compared.

Both Application consumers explicitly compare Init. Compiled HUD and ScriptManager
providers are retained in the dependent image; initial obsolete Thumb-import
attempts were rejected by the builder and removed, not allowed to mask real code.

The material-renderer alias initially changed scheduling in the existing 58-byte
SceneNodeManager::crc. Restoring the order of its independent local declarations
restored every native byte, with no algorithm/comment change or new matching
credit. This existing-body edit is disclosed in the commit. No other existing
function body was changed by this integration; the Init candidate needed no new
source forms, compiler flags or output modifications.

Fresh `python tools/build.py --all`: 182 profiles, 10,256 exact
function/section/GOT comparisons, exit zero. Every prior match passes, including
the renderer profile and both previously fragile Cash/CRC functions. Local proof:
_scratch/application-init-integrated-full.log and .exit. Earlier failed setup and
comparison logs are retained separately. Windows port sources/settings unchanged.
