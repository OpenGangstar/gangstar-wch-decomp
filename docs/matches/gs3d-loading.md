# GS3D loading state machine

`GS3DStuff::load(int, int&)`, Thumb `0x002dfb15`, reconstructs the fourteen-step
loading state machine in 2,576 bytes. The integrated function and its complete
section match retail exactly. Its assembly marker was removed after the fresh
whole-repository gate and dependency-image verification passed.

```text
OK  _ZN9GS3DStuff4loadEiRi  0x002dfb15  2576 bytes
OK SECTION .gs_load  0x002dfb14  2576 bytes
```

The function payload SHA256 is
`0cc9b0d840d4dbdff2e7fb19b67498a5ea01d3610d03ae24edc5b933cc4f6686`.
This hashes the function payload, not the entire linked image.

## Reconstruction and reusable findings

The light-node container was a standalone twenty-byte placeholder. Its data,
allocation, size, ownership, sorted flag and opaque trailing word have the same
layout as the existing restricted `irr::core::array<ISceneNode*>` view. Reusing
that type removes the loader's cross-class reinterpret cast. The callee's
mangled signature independently identifies this exact array specialization.

Before this correction, GCC's SSA exit folded the city receiver load past the
array conversion temporary. The overlapping global-address lifetimes produced
four incorrect register/load-order bytes. The genuine type correction restores
all four bytes, including city-address register reuse. The complete emitted
result proves the match; no compiler output was edited. No stock SDK allocator,
constructor or destructor implementation was imported. The trailing word at
offset16 remains opaque and retains the native initialization value1.

A loader-local quaternion factory starts a real quaternion object's lifetime,
then calls the original setter before passing the value to the skybox's virtual
method. The empty tag constructor is declared in the shared header and defined
inline only in this translation unit. An inline shared-header definition
regressed the existing Cash match; declaration-only isolation preserves it.
The real setter writes all four fields before reading them during normalization.
The scoped factory keeps construction inside the original receiver expression;
no global float-constructor attribute was added. See
[the preservation investigation](quaternion-header-preservation.md).

The current PlayerTest hierarchy and null-preserving secondary-base conversions
are preserved. The world pointer is captured before PlayerTest allocation, as
retail does. The terminal singleton is WantedLevelManager, not SoundManager.
The signed light-loop counter restores the native current/next register copies.
All ten compile-time ABI assertions pass, including PlayerTest516, OctTree16,
quaternion16, vector12 and the actual array20.

## Existing source edits and fixture closure

Three already matched functions have mechanical field-name updates following
the array alias: the static initializer, `__tcf_10`, and `GS3DStuff::unload`.
Their instructions and operations remain unchanged. The integration
commit explicitly discloses these edits.

The loader contributes fifteen reachable sections: its code, switch, loading
weights and twelve resource strings. Each is assigned its native address with
strict extent assertions. Three separately emitted collada/lod constants have
zero incoming relocations, including section-target references. Those data
sections alone use the existing verification harness area and receive no native
matching credit; no executable helper is routed there.

The private exact trial passes all110 owning function selectors and133 section/
region selectors, plus38 dependency function selectors and9 dependency-owner
section/region checks. All112 prior raw function payloads are unchanged; load is
the only new emitted function, with no outlined factory or constructor helper.
The coordinator's final fresh build passes all191 profiles:5,455 function,
5,476 section and181 region checks (11,112 comparisons). All1,098 frozen inputs
remain unchanged. All112 old GS payloads are unchanged and every allocated GS
section is explicitly routed in all8 owner/dependent links. An additional880
checks verify all110 GS owning functions in each of those8 fresh images.
No profile, original selector, or dependency is skipped.

The15 reachable section placements are shared through GS3DLoadSections.ld.
The legacy linker rejects top-level ASSERT commands inside an included file;
identical strict assertions remain in each parent main script. The initial
failed shared-fragment run is preserved separately. A controlled relink and
then the complete fresh191-profile run validate the corrected include syntax.

Progress gains exactly1 function and2,576 bytes:4,286/4,550 functions and
353,094/561,716 bytes (62.86%). Fully Linked stays114,548 bytes (20.39%,126/203
units); other functions in this translation unit remain pending.

Reproduction inputs, exact commands and full checker output are retained under
`_scratch/worker-gs3d-load-restricted-array-control`. No retail library, assets,
or proprietary toolchain is committed.
