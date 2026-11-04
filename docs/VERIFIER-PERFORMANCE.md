# Reusing parsed verification images

Native builds still compile every required unit from source on each invocation.
Within one unit, the builder now parses the retail library and source object
once, then parses the newly linked image after a successful link. The same
images serve the GOT harness, Thumb bindings, function comparisons and section
comparisons where applicable. There is no persistent or cross-invocation cache.
Inputs must remain unchanged while a build is running.

The CLI and builder share `tools.check.check_function`. The CLI still checks
the input path and loads its files. The builder supplies its freshly parsed
images directly, avoiding repeated file parsing and argument parsing for every
function. Manifest selectors use one common validator; `comparison_arguments`
remains available for callers that need CLI arguments.

The verification logic retains its machine/file-type, symbol-definition,
ambiguity, Thumb-address, relocation, linked-address, size and complete-byte
checks. Explicit compiled-name mappings remain restricted to `__tcf_N`
callbacks with retail addresses and linked images. Function failure does not
skip later functions or section checks; compiler/linker failure stops before
any stale linked result can be checked.

## Measured result

A local back-to-back Windows run on 2026-10-31 used the same sources, matching
toolchains and retail library. The original builder/checker were loaded from
commit `2220e41525584e51014c716342ee24204379baf4`; both versions rebuilt all
163 configured units from source.

| Verifier | Full native build and verification |
| --- | ---: |
| Original per-function file parsing | 263.58 seconds |
| Parsed images reused within each unit | 87.73 seconds |

This measurement is 3.00 times faster, reducing the run by 175.85 seconds.
Both runs exit 0 with exactly the same 4,703 `OK` comparisons and complete log
contents. All 324 primary object/image sizes and SHA-256 hashes are identical
after both runs and match the preceding decompilation baseline. Independent
name/address/size coverage includes all 1,357 credited game functions. No game
source, compiler flags, linker script or matching credit changes.

An earlier ten-comparison profile attributed 1.482 of 1.535 seconds to twenty
ELF loads, principally symbol-table parsing. The optimization removes that
repeated work while retaining every comparison.

## Regression coverage

`python -m unittest discover -s tests` reports `Ran 83 tests` / `OK`.
Success and failure fixtures exercise both the CLI and loaded-image API,
requiring identical status codes and output. They include duplicate names,
wrong bytes/addresses/sizes, imports/absolute bindings, relocation failures,
invalid callback mappings and machine/file-type mismatches.

Build tests cover one load per image within a unit, fresh reads and source
compilation on a second invocation, continued function/section checks after
a mismatch, and refusal to read or compare a stale image after a failed link.
Existing dependency-order, failure propagation and linker-order tests also pass.
