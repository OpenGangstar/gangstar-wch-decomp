# Command-driven build plan

This plan covers decompilation verification and native library linking. It was
prepared after meta reached 100% byte-matched on 2026-10-26.

## Reference and current capability

[OpenRAC's README](https://github.com/OpenRAC/rac1-decomp/blob/main/README.md)
separates local retail input, toolchain setup and a single build/verify command.
It uses assembly for pending functions so its complete image can still link.
Its [build fidelity rules](https://github.com/OpenRAC/rac1-decomp/blob/main/docs/BUILD_FIDELITY.md)
require honest compiler/toolchain evidence and whole-file flags. We can adopt
that workflow while keeping Gangstar's prohibition on compiler-output edits.

Gangstar already has working commands:

```sh
python tools/build.py item
python tools/build.py --all
python -m unittest discover -s tests
python tools/check_repository.py
python tools/progress.py --check
python tools/bytematch.py
```

The first two compile whole configured translation units, link verification
images at retail addresses and compare their configured functions and sections.
They do not produce a complete, loadable libsanangeles.so. The current Docker
image supplies analysis binutils, not the proven matching compiler environment.
Existing asm/*.s files are annotated disassembly listings, not linkable assembly.
ByteMatch currently reports matched game code; complete/link and data measures
stay zero. Engine code remains outside the game-code progress budget, even
though a complete library build must account for it.

## Intended contributor commands

The following interface is proposed; these tools do not exist yet:

```sh
# Supply the library from your own game installation.
python tools/setup.py --retail /path/to/libsanangeles.so --toolchain /path/to/ndk
python tools/doctor.py
python tools/configure.py
python tools/make.py item       # existing Item verification through one entry point
python tools/make.py verify     # all configured matching units
python tools/make.py library    # enabled only after the full-link milestones below
python tools/make.py check      # tooling, catalogue and native verification
```

Keep Python as the portable entry point; a small Makefile can alias these
commands for contributors who prefer make. Retain tools/build.py compatibility.
Avoid requiring Git Bash solely for wrappers on Windows.

## 1. Reproducible setup and diagnosis

Add a versioned host/toolchain manifest, setup.py and doctor.py. Validate the
retail SHA-256 against tools/project.py before generating anything. Copy only
to the ignored baselib directory, or honor WCH_BASE_LIB. Record compiler,
assembler, linker and required runtime hashes separately from the retail hash.
Accept a user-supplied toolchain path and honor WCH_TOOLCHAIN_ROOT. Download
only explicitly selected, pinned dependencies with checksum verification;
never redistribute proprietary toolchain files in the repository or images.

Start with the proven Windows NDK 1.6_r1 GCC 4.2.1 plus its 32-bit Cygwin runtime.
Test an equivalent Linux compiler or a licensed host execution route before
advertising cross-platform matching. The compiler version string alone is not
proof that another build produces identical bytes. Preserve per-unit flags.

Acceptance: a clean checkout diagnoses missing inputs clearly, rejects wrong
retail/compiler hashes, and reproduces the Item comparison without editing
paths in tracked files. Setup never overwrites the contributor's source tree.

## 2. One build command for the existing matching workflow

Have configure.py validate the dependency graph in config/matches and generate
an ignored build graph. Compile each configured source as a whole. Reuse a
verified dependency object only when its source, transitive headers, compiler,
flags and configuration hashes are unchanged. A clean mode must rebuild all
inputs. Build failures must invalidate stale outputs and return nonzero.

Expose per-unit, all-unit and check targets. Save exact checker output, source
commit and tool hashes in an ignored verification manifest. Run the current
byte checker after linking; a cache hit alone cannot establish a new match.

Acceptance: clean and incremental builds report identical results; a changed
header rebuilds every affected unit; intentional byte mismatches fail the
command. This milestone improves contributor usability without claiming a
complete library or changing area completion order.

## 3. Reconstruct inputs for code and data that are not decompiled

Create a local extraction/configuration step driven by the verified ELF,
symbol map and original object layout. Generate assembler input with explicit
ARM/Thumb state, symbol identities, local labels, literal pools, alignment and
relocations. Handle aliases, duplicate local names, overlapping function
extents, jump tables, weak symbols and data ownership explicitly. Do not feed
the existing objdump listings directly to the assembler.

Generated retail assembly/data stays ignored and is never counted as C++
progress. Vendored engine/dependencies need a separate build inventory and
license/version record; stock Irrlicht source is a reference, not proof that
Gameloft's fork matches. Pending game functions stay on the existing queue.
No raw retail blob can be presented as a decompiled match.

Acceptance: the unmodified extraction baseline assembles at retail addresses
and compares exactly for every covered code/data region, with no unaccounted
bytes or fabricated symbol bindings. Only then substitute compiled game units.

## 4. Link a complete Android ARM shared library

Replace the per-unit verification harness with a complete link graph and an
evidence-based linker script. Account for every allocated section, startup and
cleanup record, vtable, RTTI region where present, BSS extent, GOT/PLT slot,
dynamic import/export and relocation. Reproduce ELF program headers and ARM
EABI metadata. Inventory retail's actual initialization mechanism rather than
assuming a modern Android layout.

The current retail GOT harness orders references for isolated comparisons;
it must not become a substitute for real full-library symbol resolution.
Keep one authoritative definition per global and resolve weak inline copies
consistently across original translation units. Existing units may expose
partial-header or ABI disagreements that individual images cannot detect.
Keep library mode unavailable until those disagreements are resolved.

Acceptance: all symbols and sections have expected addresses/sizes, dynamic
relocations and imports are audited, every configured match still compares,
and the resulting library is structurally loadable. Report code, data and ELF
metadata comparisons separately. Claim a byte-identical file only when the
entire output SHA-256 equals the retail SHA-256; otherwise enumerate remaining
file differences. Never patch compiler output to close them.

## 5. Validate library loading and continuous checks

Test the complete library locally with the maintainer's original installation
on a compatible Android device/emulator. Start with library load, JNI entry,
startup and cleanup.

Public CI should keep running the 71 tooling tests, repository/progress checks,
and ByteMatch report export. Add synthetic extraction/linker tests and build
manifest checks without game data. Native retail comparison remains local or
on a trusted runner with private inputs; publish only logs/hashes and progress
reports. Never attach the generated library, extracted retail fragments or
proprietary tools to public artifacts. Update complete/data progress measures
only when the new build actually measures them.

Acceptance: a clean documented setup can reproduce verification and, after the
full-link gate, a local library build. Each PR retains exact native comparison
output and must pass required CI with a clean merge before merging.

## Delivery order

The maintainer's [AndroidRecomp and BackStabRecomp references](PORTING-REFERENCES.md)
were reviewed during combat work; their findings are recorded there. Their
runtime approaches may inform later porting work; they do not change these
matching and full-link acceptance gates.

Implement setup/doctor first, then the unified verification command. Keep those
small tooling PRs separate from function matches. Follow with extraction,
full-link auditing, and finally library loading validation; each has the gates
above. Full linking is a separate engineering project and must not imply that
pending C++ functions are complete. Continue the decompilation in
[WORK-ORDER.md](WORK-ORDER.md) reuse-first order across gameplay areas.
