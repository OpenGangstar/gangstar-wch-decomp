# Gangstar: West Coast Hustle — decompilation

[![Code](https://bytematch.dev/Virjoinga/gangstar-wch-decomp.svg?mode=shield&label=Code&measure=matched_code_percent)](https://bytematch.dev/Virjoinga/gangstar-wch-decomp)
[![Functions](https://bytematch.dev/Virjoinga/gangstar-wch-decomp.svg?mode=shield&label=Functions&measure=matched_functions)](https://bytematch.dev/Virjoinga/gangstar-wch-decomp)

A reverse engineering and decompilation project for the native library of
**Gangstar: West Coast Hustle** (Gameloft, 2013, Android).

The goal is C++ that compiles back to the retail bytes: the project takes the
game's `libsanangeles.so` apart and rebuilds it as readable, compilable
source.

<!-- progress:start -->
| Area | Functions | Bytes | Matched |
| --- | ---: | ---: | ---: |
| ai | 313 | 50734 | 20.22% |
| app | 222 | 17338 | 23.86% |
| audio | 281 | 18996 | 83.61% |
| characters | 232 | 58870 | 10.03% |
| combat | 145 | 15952 | 92.23% |
| core | 372 | 37240 | 22.67% |
| hud | 232 | 26776 | 35.68% |
| input | 229 | 19642 | 38.23% |
| meta | 130 | 9930 | 100.00% |
| missions | 283 | 27300 | 37.63% |
| persistence | 259 | 17750 | 73.87% |
| rendering | 366 | 66842 | 14.16% |
| scripting | 194 | 28500 | 20.36% |
| ui | 807 | 74484 | 16.08% |
| vehicles | 307 | 67932 | 5.38% |
| world | 289 | 36978 | 52.20% |
| **total** | **4661** | **575264** | **27.80%** |
<!-- progress:end -->

---

## Why this project is unusually tractable

Most mobile game decompilations start from a stripped binary and spend their
first weeks reconstructing what the symbols even mean. This one does not: the
retail library was shipped **unstripped**, and the symbol table that survived
is unusually generous.

| What the retail library gives us | |
| --- | --- |
| **17,703 function symbols** | every function, with its exact name and size |
| **19,619 C++ mangled names** | the real class and method names of the game |
| **689 source file names** | the complete list of files Gameloft compiled, via `STT_FILE` symbols |
| **The exact toolchain** | GCC 4.2.1 for ARM EABI, built from the Android NDK as `arm-eabi-4.2.1` |
| **The engine identified** | Irrlicht 1.4.2, plus gameswf, Box2D, libpng, freetype, libjpeg and zlib |

So the project starts with the answers: the game has 4,661 functions of its
own across 16 gameplay systems, it was built from 186 of its own translation
units, and every one of those functions is already disassembled and filed
under the right name.

## What the library contains

| Origin | Functions | Bytes | Note |
| --- | ---: | ---: | --- |
| **Gameloft game code** | 4,661 | 575,264 | the decompilation target |
| Irrlicht 1.4.2 | 8,005 | 943,776 | vendored, upstream open source |
| gameswf | 2,842 | 418,022 | vendored, upstream open source |
| FreeType | 966 | 201,554 | vendored, upstream open source |
| libpng | 335 | 74,784 | vendored, upstream open source |
| Box2D 2.0.2 | 324 | 72,858 | vendored, upstream open source |
| libjpeg | 284 | 66,478 | vendored, upstream open source |
| STLport | 203 | 23,648 | vendored, from the NDK |
| zlib | 81 | 27,388 | vendored, upstream open source |
| GCC support routines | 2 | 168 | vendored |

Only the first row is in scope. The rest is upstream code that gets vendored
rather than decompiled, exactly as in the established console decompilation
projects.

## Repository layout

```
asm/                the disassembly of every function that is not matched yet,
                    one file per function, filed under its gameplay area
config/
  functions.tsv     the function catalogue: the project's work queue
  files.tsv         the original source file manifest
  symbols.tsv       the full symbol map of the retail library
  toolchain/        the docker image with the ARM binutils
docs/               build instructions, engine notes, layout reference
src/game/           the decompilation, laid out exactly like the retail build
tools/              the tooling: symbol map, catalogue, disassembler, progress
tests/              unit tests for the tooling
baselib/            where you put your own copy of libsanangeles.so (git ignored)
```

`src/game/` mirrors Gameloft's own file layout one for one: `Vehicle.cpp`
lives in `src/game/vehicles/Vehicle.cpp`, `Menus.cpp` in
`src/game/ui/Menus.cpp`, and so on. The areas are the ones the code naturally
falls into — `ai`, `app`, `audio`, `characters`, `combat`, `core`, `hud`,
`input`, `meta`, `missions`, `persistence`, `rendering`, `scripting`, `ui`,
`vehicles` and `world`.

## Getting started

```sh
# 1. Put your own copy of the retail library where the tools expect it.
cp libsanangeles.so baselib/

# 2. Look at the work queue.
python3 tools/catalogue.py     # regenerate config/functions.tsv
python3 tools/progress.py     # how far along are we?

# 3. Pick a function.
python3 tools/progress.py     # the table lists every area
cat asm/vehicles/_ZN7Vehicle11getSkinMeshEv.s

# 4. Write the C++ in the matching source file.
#    src/game/vehicles/Vehicle.cpp

# 5. Delete the assembly file.  That is what marks the function as matched.
```

The assembly files are the queue: a function is decompiled when its `.s` file
is gone and a C++ definition has taken its place.

## Requirements

* Python 3.9 or newer. Nothing else — the tooling has no dependencies.
* GNU `objdump` for ARM and `c++filt`, or Docker to get them:

```sh
docker build -t gangstar-wch-decomp/toolchain:latest config/toolchain
```

The tooling finds `c++filt` and `objdump` on `PATH`, and falls back to the
toolchain image automatically.

## Documentation

* [docs/BUILDING.md](docs/BUILDING.md) — the toolchain, the flags and how a match is verified
* [docs/COMMAND-BUILD-PLAN.md](docs/COMMAND-BUILD-PLAN.md) — the staged plan for setup, one-command verification and a complete library build
* [docs/PORTING-REFERENCES.md](docs/PORTING-REFERENCES.md) — AndroidRecomp, BackStabRecomp and local Vita reference findings
* [docs/ENGINE.md](docs/ENGINE.md) — what is in the library and where it came from
* [docs/LAYOUT.md](docs/LAYOUT.md) — the original file layout and the gameplay areas
* [docs/WORK-ORDER.md](docs/WORK-ORDER.md) - reuse-first family selection and bounded matching attempts
* [CONTRIBUTING.md](CONTRIBUTING.md) — how to land a change
* [AGENTS.md](AGENTS.md) — the rules, for human and AI contributors alike

## Status

The project is at the starting line. The analysis is done — the symbol map,
the file manifest, the function catalogue and the disassembly are all
committed — and the decompilation itself is open.

The natural first targets are the small, self contained functions in
`src/game/core/` and the engine-facing code in
`src/game/rendering/`, where the Irrlicht types are already known.

## Related work

This project follows the conventions of the modern matching-decompilation
scene, and of the mobile decompilations that came before it:

* [decomp.me](https://decomp.me) and [asm-differ](https://github.com/decompals/asm-differ) — the diffing workflow
* [pret/pokecrystal](https://github.com/pret/pokecrystal) — the reference for a symbol map, a file manifest and a progress report
* [RSDKModding/RSDKv4-Decompilation](https://github.com/RSDKModding/RSDKv4-Decompilation) — a mobile game decompiled from its ARM binary
* [banteg/snail](https://github.com/banteg/snail) — a matching decompilation of a mobile game, with a modern toolchain
* [MetalSyntax/Gangstar-Miami-Vindication-Vita](https://github.com/MetalSyntax/Gangstar-Miami-Vindication-Vita) — a sibling Gameloft title, ported from Android
* [SubmitGame/awesome-decomp-games](https://github.com/SubmitGame/awesome-decomp-games) — the wider list of decompilation projects

## Legal

No game data is distributed here. The retail library is git ignored and must
come from your own copy of the game. See [LICENSE](LICENSE).
