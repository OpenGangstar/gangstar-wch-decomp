# LODSceneNode mesh transformed bounds

The complete 84-byte function at `0x002d2edd` matches using authentic
Irrlicht 1.4.2 ConstIterator semantics and a first-child traversal loop.
The read-only list subset retains its upstream notice and is explicitly
marked as adapted. Public scene-node interfaces and layouts are unchanged.

Retail returns a bounding-box reference. The upstream desktop implementation
returns a value; copying its box/matrix implementation would change this ABI.
A declaration of the genuine native getChildren method bridges its actual
const-list reference without changing the existing partial scene-node view.
The two native getter calls and original missing return on the empty-child
path remain. No fallback, matrix operation or fabricated box is introduced.

```text
OK  _ZNK12LODSceneNode29GetMeshTransformedBoundingBoxEPKN3irr5scene10ISceneNodeE  0x002d2edd  84 bytes
OK SECTION .lod_mesh_transformed  0x002d2edc  84 bytes
```

SHA-256: `9fab13ab101172767b98c7b2ab1cc5aa8d6d5c217b46742bff09229e7eb8b7b5`.
Run `python tools/build.py sdk-startup-lodscenenode` to reproduce.
All 27 prior owning-unit functions and nine regions pass; the caller closure
passes four builds, 175 functions, 133 sections and four regions. No additional
helper definition or data is emitted. computeLODLevel remains pending, so
this source does not receive Fully Linked completion credit.
