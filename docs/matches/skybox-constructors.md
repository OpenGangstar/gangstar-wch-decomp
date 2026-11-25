# CustomSkyBoxSceneNode constructors exact match

Both constructors of `CustomSkyBoxSceneNode(ITexture*, ISceneNode*, int)`
match every retail byte, including relocations.

```text
OK  _ZN21CustomSkyBoxSceneNodeC2EPN3irr5video8ITextureEPNS0_5scene10ISceneNodeEi  0x002faab9  4936 bytes
OK  _ZN21CustomSkyBoxSceneNodeC1EPN3irr5video8ITextureEPNS0_5scene10ISceneNodeEi  0x002f96e9  4984 bytes
```

## Source form

Each constructor takes the following steps in order:

1. It constructs the scene node base and the material.
2. It disables culling, resets the bounding box and sets the material type
   and flags.
3. It sets the texture filter state and binds the texture.
4. It stores the day palette, writes the 84 indices and 46 vertices of the
   sky dome, and adds the sun billboard with `./add-sun.tga`.

Details that the retail bytes require:

- **Vertex layout.** Each vertex uses `vector3d<float>` position and normal
  members and a `vector2d<float>` texture coordinate, in place of float
  arrays.
- **Vertex colours.** Vertices 0 to 20 read their colour from the named
  palette members `c0` to `c3`. Later bands copy the colour into a local
  first: `c1` before vertex 21, `c0` before 32 and `c3` before 40. These
  per-band locals move cse1's 1000-instruction flush points to where retail
  has them.
- **Texture filter state.** Bytes 38 and 39 are set through a file-local
  `SkyTextureView`. A shared `ITexture` header change alters
  `ServiceCarRental::Notify` in `ai-startup-menustate`, so the view stays in
  this file.
- **Texture binding.** A file-local `setSkyMaterialTexture` helper binds the
  texture. The shared `SMaterial::setTexture` stays weak, because other units
  call it out of line.

## Header changes

- **`Geometry.h`:** gains the public `aabbox3d` default constructor, which
  sets the edges to (-1,-1,-1) and (1,1,1), `aabbox3d::reset(x, y, z)` and
  the `vector2d` template.
- **`CustomSkyBoxSceneNode.h`:** uses the typed vertex members described
  above.

## Strings and data

The `./add-sun.tga` string is placed at `0x0041d1e0`. The inline `SMaterial`
constructor is placed at `0x0020e7ec`.

No branch hint, inline assembly, register constraint or output edit is used.

## Verification

`python -B tools/build.py sdk-startup-customskyboxscenenode` passes every
function and section check, including `setSkyColor`. A fresh complete build, `python -B tools/build.py --all`, exited 0 with 5,593 function, 5,680 section and 181 region comparisons and no mismatch or skip; the previous baseline was 5,589, 5,676 and 181.
