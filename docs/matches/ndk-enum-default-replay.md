# Controlled NDK enum-default candidate audit

Against main PR #743 (`68f0bc30`), the coordinator reviewed 68 prepared pending
functions across 66 independent old source/profile contexts. Each profile's
ordinary flags equal the current production flags with only the verified
original NDK default `-fno-short-enums` removed. Unsupported flag variants and
contexts already covered by the full default replay were excluded.

Each exact source context was compiled and assembled twice: recorded flags,
then only that SDK default added. Actual production SDK compiler/assembler
executables, input source path, working directory and other options stay fixed;
output paths differ. No saved source, header or manifest is edited. All tracked
source/header/manifest hashes remain stable. There are 132 successful compiler
runs and 132 successful assembler runs. No link is attempted and no existing
native closure or new match is claimed by this audit. This is a diagnostic of
uncredited candidates, not acceptance of their provisional types or bodies.

Results:

| Classification | Functions | Result |
| --- | ---: | --- |
| Identical target bytes and relocation signatures | 65 | No new enum-default lead |
| Identical code, different anonymous constant name | 1 | PlayerTest::updateCarInteraction still has identical 1684-byte code; both referenced carOpenDoor objects are the same 14 bytes, SHA256 8bba5c5b768542606cd7dd991a168cec5619b58185dd7ae9f94c92e851b148b8 |
| Changed instruction bytes | 2 | AddCollisionShapes remains 1820/native1816; Vehicle::CreateBody remains 1060/native1044 |

The generated anonymous-namespace name is not a semantic code improvement.
No symbol is renamed in compiler output or bound away. Both genuinely changed
code cases get one repeated old-flag control, reproducing the exact original
unlinked hashes. A follow-up assertion initially used an unmasked Thumb value
when slicing a function; the existing symbol_bytes reader verifies the same
artifacts correctly. That reader mistake never changes compiler output or
creates match credit.

The new default does not repair any complete target in this batch. No code,
assembly marker, table status, denominator or progress changes. The two changed
oversized candidates are new investigation leads; native layout, shared types
and complete old-function preservation still need proof before any integration.
No padding, output edits, address relocation, overlap suppression or guessed
signature is permitted to make them fit.

The [complete ledger](ndk-enum-default-replay.json) identifies every binary,
address, symbol, source context, profile, native/control/corrected size and raw
hash. Commands, source/header hashes, objects and logs remain in the private
`_scratch/ndk-enum-bounded-replay-current/` case directories. The audit runs
compiler subprocesses; no game execution or sub-agent integration occurs.
Root reviewed all results and released all 68 function assignments.

## AddCollisionShapes layout follow-up

A read-only audit of case 044's already compiled objects confirms that the enum
correction leaves the remaining layout costs unchanged. No new source form or
link is attempted:

| Image | Function bytes | Code and alignment | Literal pools |
| --- | ---: | ---: | ---: |
| Recorded-default control | 1820 | 1724 | 96 |
| Corrected enum default | 1820 | 1724 | 96 |
| Native | 1816 | 1728 | 88 |

Both objects have Thumb/data mapping boundaries at offsets 0, 944, 988 and
1768; native boundaries are 0, 808, 844 and 1764. The actual corrected assembly
still reserves a 356-byte frame versus native 364. The corrected shape type
stores become words, and several scalar spill slots move, but the net four-byte
excess remains code/alignment minus four plus literal pools plus eight.
The previous source-order/minimum/maximum attempts remain parked. The SDK enum
finding alone does not justify another such source or compiler-flag grid.
