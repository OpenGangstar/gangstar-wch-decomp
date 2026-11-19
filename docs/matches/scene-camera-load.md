# SceneCamera::Load

`SceneCamera::Load(Structs::SceneCamera const&)` matches all 96 bytes at Thumb
`0x00334fe9`. This finishes the original SceneCamera source group: all 15
catalogue entries, totaling 646 bytes, have native executable proofs.

## Reconstruction

The function loads its embedded LevelObject through the actual typed factory
API, copies its value-returning position, and converts the record's signed
coordinates into the camera's look-at vector. The genuine Irrlicht value
assignment preserves the native conversion and temporary boundaries:

```cpp
const float x = static_cast<float>(data.unknown88.X);
const float y = static_cast<float>(data.unknown88.Y);
lookAt = irr::core::vector3d<float>(x, y, static_cast<float>(data.unknown88.Z));
```

The earlier component assignments emitted 92 bytes. This whole-vector
assignment holds X across the Y conversion and permits the native Z-load,
X/Y-store and Z-conversion sequence. There are no hints, register pins,
barriers, forced inlining, artificial padding or compiler-output edits.
Compiler flags are unchanged.

## Factory provider and existing cleanup

The real factory header emits weak COMDAT definitions. Under SceneCamera's
existing flags, its createNode copy is 100 bytes; the already verified GS3D
provider emits the native 140-byte implementation with its own original
flags. The verification profile reuses that real dependency, following the
existing Weapon convention. Normal dependency-first linking selects the
GS3D definition and coalesces the duplicate. There is no manual discard or
absolute-address replacement of compiled code.

All selected factory methods, its physical vtable section, singleton storage,
guard, cleanup and GOT are checked. The linker map identifies the real
140-byte provider. Uninitialized storage is checked by address and extent,
without claiming that BSS has file bytes.

This also replaces an existing matched implementation: the handwritten
SceneCamera `__tcf_1` cleanup is removed in favor of the actual compiler-generated
`__tcf_0`. The native address and all 36 bytes remain unchanged; the comparison
selector records the different local compiler counter with `compiled_name`.
The separate GS3D cleanup remains at its own native address. No executable
orphan is left outside the verification fixture.

## Verification and progress

The final integrated `python tools/build.py --all` passed 190 profiles with
5,415 function, 5,321 section and 181 region checks: 10,917 exact comparisons,
with no failures or skips. The focused combined image passes 125 function
and 123 section/region checks.

```text
OK  _ZN11SceneCamera4LoadERKN7Structs11SceneCameraE  0x00334fe9  96 bytes
OK  __tcf_1  0x00334ef1  36 bytes (compiled: __tcf_0)
```

Independent executable extraction verifies the entire source group, including
aliases and the cleanup's actual compiled name. Load's SHA256 is
`2076436764302a8ae407c359e4706f7408263167adb43c3ff87ed9689aecd27c`.
The assembly file was removed only after that root verification.

The normal generated report adds 96 matched bytes and 646 fully linked bytes:
342,294 matched bytes (59.50%) and 111,046 fully linked bytes (19.30%), with
124 of 208 units complete. The game-code denominator stays 575,264
bytes. Fuzzy progress remains equal to matched progress; no partial credit is
introduced. Independent audits find executable proofs for all 4,260 matched
entries and all 1,662 entries in complete source groups.
