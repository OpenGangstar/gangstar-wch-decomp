# Building and verifying a match

This project does not ship a full-game build system yet. This document describes what
the build *has* to be for a function to count as matched, and what is already
known about the toolchain.

For the proposed setup, single-command verification and complete-library build
milestones, see [Command-driven build plan](COMMAND-BUILD-PLAN.md).

## What a match means

A function is matched when the bytes the compiler produces for your C++ are
**identical** to the bytes at that function's address in the retail library.
Not "equivalent", not "close enough" — identical.

The comparison is made on the compiled object, function by function, with the
relocations and the section layout accounted for. Anything less is a near
miss.

## The toolchain

The retail library was built with:

```
GCC: (GNU) 4.2.1
```

for ARM EABI. The symbol table of the library
still records the path the compiler was built at:

```
/cygdrive/c/digit/Android/git/android-ndk/out/arm-eabi-4.2.1/toolchain/src/gcc-4.2.1/...
```

That identifies an **Android NDK** toolchain, built from
the `android-ndk` git repository, with the GCC 4.2.1 cross compiler configured
as `arm-eabi-4.2.1`. It does not identify an exact NDK release or GCC patch set.
The Windows NDK r4b includes GCC 4.2.1 and has now produced exact bytes for
two small, integer-only probes. See `COMPILER-NOTES.md` for reproduction.

The library's `e_flags` are `0x04000002`: the EABI version field is 4, not 5.
Neither the soft-float (`0x200`) nor hard-float (`0x400`) ABI flag is set.
These flags do not establish the floating-point calling convention.

To match byte for byte, the compiler has to be that compiler. A modern
`arm-linux-gnueabi-gcc` will produce different code for the same source.

### Getting the NDK

The Windows r4b archive is still available directly from Google:

* <https://dl.google.com/android/ndk/android-ndk-r4b-windows.zip>

The compiler requires a 32-bit Cygwin runtime. `COMPILER-NOTES.md` lists the
runtime packages and a working probe command for current Windows hosts.
NDK r5 removed GCC 4.2.1; do not use r5 to obtain that compiler.

Build the cross compiler the same way the retail build did:

```sh
git clone https://android.googlesource.com/platform/ndk
cd ndk
./build/tools/make-standalone.sh --arch=arm-eabi --toolchain=4.2.1 ...
```

The resulting compiler is `arm-eabi-4.2.1`.

## The flags

The retail build's flags are not recorded in the shared object, so they have
to be recovered by experiment. The constraints they have to satisfy:

* **Thumb.** Most functions are Thumb. Use `-mthumb` for Thumb functions;
  ARM functions require separate investigation.
* **Floating point.** The exact ABI and instruction selection still need
  experiments involving float arguments and arithmetic.
* **Exceptions and RTTI.** These settings remain unverified. The starting
  flags below disable them; integer-only probes do not establish either.
* **STLport.** The library uses STLport (the `stlp_priv` symbols are in the
  symbol table), which is what the NDK of that era shipped.

A good starting point:

```
arm-eabi-g++ -c -O2 -fno-strict-aliasing -fno-rtti -mthumb -mfloat-abi=softfp \
    -fno-exceptions -I<stlport include> ...
```

The exact set is still to be determined; record what works in
`docs/COMPILER-NOTES.md`.

## The comparison

The builder reuses freshly parsed images within each unit for all function and
section checks. Every invocation still compiles from source; no persistent cache
is used. [Verifier performance](VERIFIER-PERFORMANCE.md) records the measured
improvement and regression checks.

The tooling in this repository gives you everything you need to read the
retail bytes:

```sh
# the disassembly of one function, with its address and size
cat asm/vehicles/_ZN7Vehicle11getSkinMeshEv.s

# the bytes of that function in the retail library
python3 -c "
from tools.project import load_base_library
elf, _ = load_base_library()
print(elf.read_at(0x2f8c4c, 0x18).hex())
"
```

To compare a compiled object against the retail bytes, the steps are:

1. Compile the translation unit with the matching toolchain.
2. Find the symbol in the object file.
3. Extract its bytes.
4. Compare them with the retail bytes at the function's address.

`tools/check.py` implements this for object functions without unresolved
relocations, including Thumb symbols (whose low address bit is a marker):

```sh
python tools/check.py build/toolchain-baseline/importgl.o --func importGLInit
```

It refuses functions touched by unresolved relocations. Configured units can
now be compiled and linked against the retail layout with the original GNU
linker, then checked as fully resolved images:

```sh
python tools/build.py logs
python tools/build.py --all
```

`config/matches/*.json` records the compiler flags, source, linker script,
function list and any whole sections to compare. `config/linker/Logs.ld`
places the Logs code, strings and GOT base at their retail addresses, and
binds external calls to the retail ARM PLT entry addresses. Neither compiler
output nor linked bytes are edited. Linked functions must also have the
correct retail address. These verification images do not provide a full
library build or a replacement runtime.

Units with `retail_got: true` compile a generated C++ reference harness before
linking. This reproduces the retail global GOT ordering through GNU ld's own
symbol allocation; it does not patch relocation results. The ADPCM manifest
also checks the tables and the complete global GOT region. The PLT/local GOT
prefix remains reserved rather than rebuilt. See `matches/adpcm.md`.

Manifests may declare `dependencies` naming other configured units. The
builder rebuilds and verifies those units first, then links their real object
files into the dependent image. Their definitions are excluded from generated
retail bindings as well. BufferStream uses this to retain Stream's Thumb
function metadata and verify both source units together. Dependency cycles
are rejected before compilation.

The command plans the complete dependency graph before compiling. Each required
unit is built and compared once per invocation, even when several selected units
share it or it is also selected explicitly. Every dependent image still links
the verified dependency object and runs its own function and section comparisons.
`BUILD <unit>` identifies each scheduled unit. A failed byte comparison skips
its dependent units, reports `SKIP`, and makes the command fail; independent
units are still checked. A compiler or linker failure stops the command.

This scheduling does not provide a persistent or incremental cache. Every new
command rebuilds all required units from source using their configured compiler
profiles (or the explicit toolchain override). Keep sources, manifests, linker
scripts and toolchains unchanged while a command runs.

### External Thumb callees

A unit may list `external_thumb_functions` in its manifest when a callee still
uses the retail implementation. The builder validates each name against the
retail ELF and assembles an absolute `.thumb_set` symbol declaration with the
original address and Thumb function metadata. No instructions or function bytes
are emitted for these symbols. The declarations do not mark callees matched.

This prevents the legacy linker from turning an original Thumb `BL` into an
ARM `BLX` merely because an address-only linker assignment lost its mode. A
compiled definition in the unit or any native dependency cannot be overridden;
unknown names, ARM functions, objects, imports and duplicates are rejected.
Native dependencies remain the way to verify callees reconstructed in C++.
Compiler-generated assembly and linked bytes are never rewritten. SaveGame's
filename helper exercises this with the still-pending Application::GetInstance.

## What is already automated

The repository and progress checks need no game data. Catalogue, symbol-map
and disassembly generation require the retail library:

```sh
python3 tools/catalogue.py     # the function catalogue
python3 tools/symbol_map.py    # the symbol map
python3 tools/disasm.py        # the assembly of every pending function
python3 tools/progress.py      # how far along the decompilation is
python3 tools/check_repository.py
```

## Repeated local function names

Compiler-generated names such as `__tcf_3` and
`_Z41__static_initialization_and_destruction_0ii` occur in many translation units.
The byte checker rejects ambiguous names instead of selecting the first one.
Specify the exact retail symbol address, including its Thumb marker:

```sh
python3 tools/check.py build/matches/my-unit/my-unit.elf \
  --func __tcf_3 --address 0x0033116d
```

The compiled definition must still have the correct address, size and bytes.
The selector also chooses the matching local definition in a linked image and
uses that definition's relocation range. Same-named definitions in a relocatable
object require a linked verification image to disambiguate them.

Matching manifests retain string selectors for unique names. An explicit
selector in their `functions` list has this form:

```json
{"name": "__tcf_3", "address": "0x0033116d"}
```

This selects a definition to verify; it does not change compiler output, linker
placement or match status. Undefined imports and absolute address bindings are
not compiled definitions and cannot be credited by the function checker.

## The engine

The library is not just game code. See [ENGINE.md](ENGINE.md) for the full
breakdown. The short version: the engine and its dependencies are upstream
open source and get vendored, not decompiled, so they are excluded from the
matching budget.


### Renumbered generated cleanup callbacks

GCC numbers local destructor callbacks by emission order. A partial translation
unit can therefore emit a retail __tcf_2 as __tcf_0 even when its code and linked
address are exact. The explicit compiled-name selector supports only __tcf_N
callbacks, requires --address and a linked image, and retains all definition,
Thumb address, size, byte and relocation checks:

```sh
python3 tools/check.py build/matches/gs3d-stuff/gs3d-stuff.elf \
  --func __tcf_2 --address 0x002dd06d --compiled-func __tcf_0
```

Its manifest selector is:

```json
{"name": "__tcf_2", "address": "0x002dd06d", "compiled_name": "__tcf_0"}
```

The comparison output discloses the compiled name. This selects the generated
C++ definition; it does not rename a symbol, edit output, or claim an exact full
ELF symbol table. Remove the mapping when the completed translation unit restores
the original emission order. Other function-name mappings are rejected.

### Primary object precedence

Linked manifests may set `source_first: true` to pass the primary object before
native dependency objects to GNU ld. The default remains dependencies first.
This controls ordinary weak-definition selection when the primary translation
unit and a dependency both emit the same inline SDK/factory methods. The retail
GOT harness still precedes all game objects, and every existing comparison runs.
The saved GS3D update image uses this to select its own factory methods before
LevelObject's copies. Non-Boolean flag values are rejected before compilation.
