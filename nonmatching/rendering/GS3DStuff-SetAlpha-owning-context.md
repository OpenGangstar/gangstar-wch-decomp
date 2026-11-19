# SetAlpha: unchanged owning-context replay

Target: `GS3DStuff::SetAlpha(irr::scene::ISceneNode*, unsigned char,
GS3DStuff::eColorType)`, Thumb `0x002df34d`, native 168 bytes. Base: main
PR #743, `68f0bc30`. Unapplied and unmatched; no progress credit.

The previous six source forms were compiled in a standalone wrapper. This one
bounded contextual replay appends the unchanged canonical v6 body to the actual
current GS3DStuff translation unit and reuses its existing applyToChildren
helper. No existing body, field, declaration, ordinary compiler flag or header
is changed. Only the target is newly emitted; no new helper definition appears.
The normal owning profile and its Stream/DataStream dependencies are used,
with an added native-address target selector and a 168-byte extent assertion.

An initial enum-baseline hypothesis was rejected before compilation: both the
historical gs3d-stuff profile and the archived SetColor manifest already list
`-fno-short-enums`. The recently corrected NDK default therefore provides no
new enum-width experiment for this family. SetColor was not recompiled.

The current full-context SetAlpha executable is byte-identical to archived v6:
168 bytes, 34 differing bytes, first difference `0x56`, SHA256
`02f4949240624a813cb0f21736528bde06e1f42a18a73682fb2829b2847ca55f`.
Exact target failure:

```text
MISMATCH  _ZN9GS3DStuff8SetAlphaEPN3irr5scene10ISceneNodeEhNS_10eColorTypeE  0x002df34d
MISMATCH SECTION .gs3d_set_alpha
  expected : 00 21 98 47 57 22 83 5c 9e 42 f1 d0 81 6d 84 6a
  actual   : 00 21 98 47 57 22 83 5c b3 42 f1 d0 81 6d 84 6a
  differs at 0x56
```

Across the normal owning/dependency run, all 147 existing function checks,
124 section checks and three GOT-region checks pass. The target and its full
section fail; build exit 1. No new full-project gate is claimed for this
rejected patch. The initial compare instruction reverses equal operands; the
later flag-update tail also differs. Fixing that first comparison alone would
not establish a match. No additional source variants were tried.

Set WCH_BASE_LIB, apply this patch only in an isolated checkout and run
`python tools/build.py gs3d-stuff`. Native placement, size, import, overlap and
comparison guards remain enabled. No compiler output is edited. Production
source/configuration, the assembly marker and generated progress are unchanged.
Coordinator review releases ownership; further work needs new causal evidence.
