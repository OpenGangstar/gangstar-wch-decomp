# ByteMatch progress tracking

The project is tracked at https://bytematch.dev/Virjoinga/gangstar-wch-decomp.
CI uploads `build/android-arm/report.json` as `android-arm_report` after the
catalogue and README checks. Successful push runs on main become history;
pull request artifacts can support comparisons. No upload token is needed.

Run `python tools/bytematch.py` to reproduce the report locally. This exports
the checked-in game catalogue into objdiff's version-2 report schema; it does
not run objdiff or reverify retail bytes in CI. Match evidence remains the
linked comparisons recorded in docs/matches and pull requests. Regenerate the
catalogue after verifying functions, following CONTRIBUTING.md.

The report uses the same game-only scope and symbol accounting as
`tools/progress.py`, including constructor/destructor aliases. Units are grouped
by gameplay area and original source file, with repository source paths for
the viewer. Engine and dependency code are excluded. Pending functions earn
zero credit; near matches have no partial or functional-C claim. Fuzzy progress
therefore equals exact progress. These are distinct measures even when their
values coincide: matched code counts individually verified functions; fuzzy
code would additionally count measured partial matches if those were tracked.

Fully Linked code follows OpenRAC's complete-unit convention. An original
`source_file` qualifies only when every game function attributed to it has
`status == matched`. Its report units then receive `metadata.complete = true`,
their entire code size as `complete_code`, and `complete_units = 1`. Totals and
categories sum those unit contributions; they are not all-or-nothing tests of
the entire project. Existing area/source unit names remain stable. Startup
helpers sometimes appear under another area, so a fully matched fragment is
still incomplete if any function from the same source file is pending elsewhere.

This is code completion within the report's existing game-only scope, not a
claim that the whole Android shared library, its data, or the Windows port is
finished. External calls resolved by verification bindings do not substitute
for an incomplete unit's own functions. The native checker excludes absolute
symbols from function selection and compares executable definitions. Data totals
and complete-data measures remain zero because comprehensive data coverage is
not tracked. Linked and matched code overlap; their percentages must not be added.

See [Fully Linked investigation](BYTEMATCH-LINKED-AUDIT.md) for upstream source
references, qualification checks and the before/after report. CI validates the
generated report with pinned objdiff 3.8.1 before uploading the existing artifact.

The version label `android-arm` identifies the single library selected by
`BASE_LIB_SHA256` in tools/project.py; it does not invent an unverified release
number. The original objects are unavailable, so an objdiff.json with fabricated
target/base object paths is deliberately not provided.

ByteMatch polls successful main push runs periodically. If ingestion stalls,
use Poll now on the project's manage page and inspect its ingest error. See
https://bytematch.dev/docs/getting-started for artifact requirements and
https://github.com/encounter/objdiff/blob/main/objdiff-core/protos/report.proto
for the report schema. Source links depend on ByteMatch's C++ symbol resolver;
report metadata supplies the original demangled names and source files.
