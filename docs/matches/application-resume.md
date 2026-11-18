# Application resume

Application::Resume() reconstructs the 344-byte Thumb function at 0x002d4e89.
The first source candidate matches exactly. It preserves first-resume handling,
interrupt-triggered texture unloading and device reinitialization, both native
StartGlobalResuming calls on the non-kind-21 path, repeated top-state/player
queries, timer reset, touch clearing, state wakeup, logging and HUD/menu/sound
routing. No existing decompiled function body changes.

The interface additions name the observed IrrlichtDevice slot 2 reinitDriver,
CTextureManager::unloadAllTextures and two native MenuManager methods. Existing
CTextureManager/ITextureManager compatibility and allocator declarations are reused.
No imported engine or pending game implementation receives matching credit.

ApplicationHelpers and GSFade both retain and compare the new executable
function, three complete string constants and the genuine one-byte LOCAL
isFirstTime initialized-data object. Shared linker placements preserve native
addresses. GSFade uses its existing compiled HUD methods; redundant external
Thumb bindings are omitted rather than overriding those definitions.

Both native-address images print:

```text
OK  _ZN11Application6ResumeEv  0x002d4e89  344 bytes
OK SECTION .application_resume_tag  0x00413d4c  28 bytes
OK SECTION .application_resume_message  0x00413d68  44 bytes
OK SECTION .application_resume_map  0x0040b608  4 bytes
OK SECTION .application_first_resume  0x004b5398  1 bytes
```

No compiler output is edited. Windows port sources and configuration are unchanged.

Coordinator `python tools/build.py --all` exited zero across 180 profiles,
with all 9,807 function, section and GOT-region comparisons passing. Logs:
_scratch/application-resume-root-full.log and .exit.
