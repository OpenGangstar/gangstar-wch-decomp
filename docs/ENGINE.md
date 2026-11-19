# What is inside `libsanangeles.so`

`libsanangeles.so` is the native library of Gangstar: West Coast Hustle. It
is 6.9 MB and was built for ARM EABI with GCC 4.2.1.

The file is a shared object with 26 sections, of which the interesting ones
are:

| Section | Address | Size | What it holds |
| --- | --- | ---: | --- |
| `.hash` | `0x000000b4` | 139,100 | the hash table of the dynamic symbols |
| `.dynsym` | `0x00021f10` | 292,768 | the exported symbols |
| `.dynstr` | `0x000696b0` | 1,040,502 | the exported symbol names |
| `.rel.dyn` | `0x00167728` | 377,912 | the relocations |
| `.plt` | `0x001c3f78` | 2,552 | the procedure linkage table |
| `.text` | `0x001c4970` | 2,337,048 | the code |
| `.rodata` | `0x00401088` | 315,040 | the read only data, including the strings |
| `.ARM.exidx` | `0x00457d6c` | 136,592 | the exception unwinding tables |
| `.data.rel.ro` | `0x0047a638` | 219,696 | the relocated read only data |
| `.data` | `0x004b49dc` | 6,424 | the writable data |
| `.bss` | `0x004b6078` | 38,796 | the uninitialised data |

The library depends on `libc.so`, `libstdc++.so`, `libm.so`, `libGLESv1_CM.so`,
`libdl.so` and `liblog.so`. It is a GLES 1.1 title: there is no shader
support in it at all.

## The symbol table

The library was shipped **unstripped**. That is the single most important
fact about it, and it is what makes this project possible.

* `.symtab` holds **53,044** entries, of which **52,797** are defined.
* **17,703** of them are functions, with their exact addresses and sizes.
* **19,615** are mangled C++ names, so the game's own classes and methods
  are known by their original names.
* **689** are `STT_FILE` symbols: the name of every translation unit the
  build compiled, in link order.

Nothing about the structure of the game has to be guessed.

## What the library is made of

The engine and its dependencies are statically linked next to the game code.

### Irrlicht Engine 1.4.2 — 8,005 functions

Gameloft shipped a fork of the [Irrlicht engine](https://github.com/irrlicht/irrlicht).
The version string is in `.rodata`:

```
&1.4.2
Warning: The library version of the Irrlicht Engine (
) does not match the version the application was compiled with (
```

The fork adds the parts a Gameloft title needs: OpenGL ES support, the
Collada and OGRE mesh loaders, the particle system, and the software renderer
for the platforms that need one.

### Using the upstream headers as a reference

An upstream Irrlicht 1.4.2 checkout identifies itself in
`include/IrrCompileConfig.h` with `IRRLICHT_SDK_VERSION "1.4.2"`.
Its `include/IQ3Shader.h` defines the header-local
`irr::scene::quake3::irrEmptyStringc("")`, explaining the repeated string startup
and cleanup helpers in game translation units. `include/vector3d.h` also provides
the three-component constructors and nontrivial copy constructor used to reason
about game parameter passing. These sources help recover types, inline code and
virtual interfaces before compiling the game functions against retail bytes.

The stock headers cannot be assumed to describe the fork's ABI. For example,
stock `include/irrString.h` directly deallocates its array in the destructor;
the verified retail game cleanup callbacks instead test a reference flag at
byte 29 and avoid deleting an inline buffer at byte 13. Preserve observed fork
layouts until native comparisons establish compatibility. Engine code remains
outside the game-code progress totals.

### gameswf — 2,850 functions

A [gameswf](https://github.com/kennethshackleton/gameswf) build for the
Flash based interface. Its symbols are clearly visible:

```
_ZN7gameswf5arrayINS_9tesselate12fill_segmentEE6resizeEi
```

#### Source references and version boundaries

The [original gameswf website](https://tulrich.com/geekstuff/gameswf.html)
provides project history, public-domain licensing information and links to the
tu-testbed source project and historical snapshots. Use it to establish source
provenance and locate older implementations.

The [Marmalade port](https://github.com/marmalade/gameswf), reviewed at commit
`1f16bc87aab11ae9dcc8b61a3d3f5900355cdd4c`, is another useful reference for
interfaces and platform adaptations. Its
[README](https://github.com/marmalade/gameswf/blob/1f16bc87aab11ae9dcc8b61a3d3f5900355cdd4c/README)
documents changes including replacing `strcasecmp` with `strcmp`. That changes
case-comparison behavior; ARM support alone does not establish compatibility with
Gameloft's fork. Its `tu_string` also uses a later buffer-free-count encoding,
rather than the retail tag-first representation.

For the retail string layout and resize algorithm, a closer historical reference
is the 2008-11-18 revision
[`b29f4cc842244eb8e1daf3b7c4d8ce2693c04853`](https://github.com/weihuoya/gameswf/tree/b29f4cc842244eb8e1daf3b7c4d8ce2693c04853/tu-testbed/base).
Its `container.h` and `container.cpp` describe the 16-byte union with the tag at
offset 0, inline characters at offset 1, and heap size, capacity and pointer at
offsets 4, 8 and 12 on the target ABI. Heap size includes the terminator; inline
capacity is 14 characters. Its resize implementation also retains the
`strcpy`/`strncpy` transitions observed in retail code. Later upstream revisions
change these copy operations and then the representation itself.

This correspondence identifies a useful source family, not the complete retail
fork. Constructor null checks, allocation interfaces and individual class layouts
still require retail verification. Keep original license notices when reusing
source, and accept reconstructed game functions only after complete native byte
comparisons. Reference research adds no matched or fully linked progress, and
vendored gameswf code remains outside game-code totals.

### Box2D 2.0.1 (recorded version) — 324 functions

[Erin Catto's Box2D](https://github.com/erincatto/box2d), used for the
vehicle and character physics.

The retail `b2_version` object at `0x004b6068` contains three little-endian
32-bit integers: `(2, 0, 1)`. Both symbol-table entries identify the same 12-byte
object. This corrects the earlier 2.0.2 label; the function catalogue and its
324 Box2D entries remain unchanged. The observation uses the verified retail
library with SHA-256
`b322b642d365a34c48e140234b7ef4efd965d1e81acd2b95d9034e2f4386ea8a`.

Treat this as the engine's recorded base version. Gameloft modifications and
individual source/header reconstructions still require native byte comparison.
For example, directly transferring the stock 2.0.1 body-definition constructor
into the current matching context regresses the existing `InitWorld` match;
that transfer remains rejected and unapplied.


### FreeType — 1,069 functions

The font engine, with the usual module prefixes (`tt_`, `psh_`, `cff_`,
`type1_`, `sfnt_`, `bdf_`, ...).

### libpng — 335 functions

### libjpeg — 284 functions

An IJG libjpeg 6b, judging by the file names (`jcmaster.c`, `jdarith.c`,
`jctrans.c`, ...).

### zlib — 81 functions

### STLport — 203 functions

The C++ standard library the NDK of that era shipped. The `stlp_priv`
namespace is visible in the symbol table.

### GCC support routines — 2 functions

The ARM soft float helpers (`__aeabi_f2uiz` and friends).

## The game code

**4,550 functions, 561,716 bytes.** That is what this project decompiles.

The [provenance correction ledger](PROVENANCE-CORRECTIONS.md) accounts for all
103 pending FreeType and 8 pending gameswf entries moved out of the original game classification. All
17,703 retail function entries remain in the full catalogue.

The game's own classes are in the global namespace, with names that make the
structure of the game obvious:

```
_ZN7Vehicle11getSkinMeshEv                    Vehicle::getSkinMesh()
_ZNK3NPC9getWeaponEv                          NPC::getWeapon() const
_ZN12SoundManager11getInstanceEv              SoundManager::getInstance()
_ZN13WeaponManager13unlimitedAmmoEb           WeaponManager::unlimitedAmmo(bool)
_ZN16AchievementManager4Stat8getValueEv       AchievementManager::Stat::getValue()
```

and, further down, the scripting and mission machinery:

```
_ZN7Mission14setTextToPrintEi                 Mission::setTextToPrint(int)
_ZN13ScriptManager6CreateEv                   ScriptManager::Create()
_ZN12StateMachine9pushStateI12GSInGameMenuEEPT_v
```

### The JNI layer

The library is loaded by the game's Java code. The entry point is
`app-android.c`, and there is a second native file, `jni_GLMediaPlayer.c`,
for the video playback.

### The platforms the build supports

The file names show that this build is the union of several platform ports:
`FileSystemIPhone.cpp`, `FileSystemWin32.cpp`, `TouchScreenIPhone.cpp`,
`TouchScreenWin32.cpp`, `AccelerometerIPhone.cpp`, `AccelerometerWin32.cpp`,
`MediaPlayerIPhone.cpp`. The Android build links the iPhone and Win32
variants and selects between them at runtime, which is why they are all in
the library.

## The strings

`.rodata` holds 3,400 printable strings. Among them are the game's own
identifiers:

```
Gangstar
Gameloft
```

and the engine's diagnostics:

```
&ERROR-fopen=0: CFileSystem::open-fullPath='%s'
Not enough memory for decompressing
```

which is useful, because the engine's error paths are in the library and
therefore in scope for the decompilation.
