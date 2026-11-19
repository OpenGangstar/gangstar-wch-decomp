# Application::_Draw()

The 272-byte Thumb function at `0x002d4fe1` matches the retail library exactly.
It retains the original drawable-state guard, driver/scene calls, two registered
drawable passes, state-machine/script/menu drawing and final buffer swap.

## Reconstruction

The scene and HUD passes reuse the authentic STLport iterator adaptation from
[Application::_Update](application-update.md) over the existing list sentinels.
The original reference, value-conversion and comparison APIs produce the native
shared bottom tests; the four previous raw-pointer forms were not exact.
The helper retains its upstream license and inlines naturally. No extra helper,
data or vtable definition is emitted. Existing compiler flags are unchanged.

The original `ISceneManager` slots 49 and 50 are named `drawAll(ISceneNode*)`
and `update(float, bool)`. Their signatures replace placeholders without adding
slots or changing object layout. A private header-only check of all 190 current
profiles passed all 10,527 comparisons before adding this function, including
the previously sensitive 68-byte `getID` method. An older context had exchanged
two independent initialization instructions there; the current gate does not
reproduce that regression. Its compiler-pass-level cause is not established.

## Verification

```text
OK  _ZN11Application5_DrawEv  0x002d4fe1  272 bytes
OK SECTION .application_draw  0x002d4fe0  272 bytes
```

Function SHA-256:
`cdeff922071bf9718c144ec2e3b3d42353fbd76878d2ebb932af1b3f96fad41c`.
The owning profile retains all 74 previous function and 45 section/region checks,
plus JNI checks. Its 264-byte `Application::Update()` remains exact while calling
the compiled `_Draw` definition. The only old object relocation metadata change
is that this call's unchanged symbol becomes defined; its operation and offset
remain unchanged. All old allocated object-section bytes are unchanged.

The target's retail Thumb import is removed. Dependent `state-hooks-gsfade`
imports for `_Update` and `_Draw` are also removed because that profile links the
real Application dependency object. Its existing comparisons remain configured.
The initial combined gate rejected the stale import rather than allowing it to
replace a compiled definition. No byte checks or linker-overlap checks are bypassed.

The coordinator's first combined integration omitted three required external
Thumb declarations (`StateMachine::isDrawable`, `ScriptManager::draw`, and
`MenuManager::draw`). The gate caught a `BLX`/`BL` difference at target offset
`0x14`. Restoring the package's genuine Thumb imports preserves the original
callee mode; it does not change the reconstructed source or compiler output.

The existing shared ApplicationFrameSections linker fragment retains every
original frame/data section and adds only the two new native placements.
An intermediate coordinator edit overwrote its original contents; strict extent
and overlap checks rejected that edit. The original sections were restored
before successful closure verification. The dependent state-hooks profile
uses its already compiled ScriptManager::draw definition, not a retail import.

The final combined current-root verification passes all 190 profiles and
10,539 comparisons: 5,266 functions, 5,092 sections and 181 regions.
All previously configured comparisons are retained. The matched-function
catalogue is regenerated only after this successful gate. These sources remain
incomplete overall and receive no additional Fully Linked credit.
