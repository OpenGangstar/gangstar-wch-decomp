# ResStream destructor: measured three-quantity allocator sort

`ResStream::~ResStream()` D1/D2 at Thumb `0x0034ef15`, 56 retail bytes,
remains unmatched. This observation explains an installed compiler decision;
it adds no matched or Fully Linked credit and changes no production source.

## Neutrality and scope

One bounded GDB observation of the established GCC 4.2.1 frontend and one
ordinary assembler invocation exited successfully. No linker ran. Before
interpreting the trace, the entire object, assembly and complete ELF inventory
reproduced the saved ordinary outputs exactly:

| Artifact | SHA256 |
| --- | --- |
| Object | `18235e70b200d45e3d62a7694b564dde06ef54282c69b6615ee0bc7bf8adc51e` |
| Assembly | `9c05ee9b0c56f6acbfbf82541db44162bfb60c86f0acc79ec9f44bd2728ec15f` |

Actual D1/D2 are aliases of the same 56-byte input. The eight accepted events
belong to D1: entry, three comparator entry/return pairs, and completion. D2
was not independently observed. All pinned inputs and tools remained unchanged.
Only normal debugger-managed host breakpoints were used; no generated output
or game instruction was edited.

## Measured order

The initial order array is `[0,1,2]`. The comparator receives quantity IDs
directly, even after the separate order array changes:

| Comparison | Actual return | Order at next observation |
| --- | ---: | --- |
| `(0,1)` | `+10000` | `[1,0,2]` |
| `(1,2)` | `-10000` | `[1,0,2]` |
| `(0,1)` | `+10000` | `[0,1,2]` |

Thus the final exchange undoes the first. The swap outcomes are measured
between comparator stops and completion; no breakpoint observed the exchange
instructions themselves.

The stable captured quantities are:

| ID | First pseudo | References | Frequency | Birth/death | Size |
| --- | ---: | ---: | ---: | --- | ---: |
| 0 | 106 | 5 | 5000 | 2/12 | 1 |
| 1 | 104 | 6 | 6000 | 10/16 | 1 |
| 2 | 107 | 2 | 2000 | 22/24 | 1 |

The actual register-to-quantity mapping ties pseudos 104 and 105 to quantity 1;
pseudo 106 belongs to quantity 0. Upstream GCC 4.2.1's priority calculation
gives 10000, 20000 and 10000 for these records, consistent with all three
measured returns. See the primary
[local allocator implementation](https://github.com/gcc-mirror/gcc/blob/releases/gcc-4.2.1/gcc/local-alloc.c).

## Setup findings and limits

Earlier hardware-only observations delivered zero callbacks. Standard host
software breakpoints delivered events. Failed setup attempts remain separate
from this successful run and supply no accepted quantity observations.

The observer verifies the actual compiler PEB environment against the full
expected dictionary after the documented
[WOW64 startup transformation](https://learn.microsoft.com/en-us/windows/win32/winprog64/wow64-implementation-details).
It does not ignore differing keys or alter the configured environment. Runtime
module checks distinguish loader-reported names from actual kernel-backed files.
Completion events without a preceding owned three-item entry are counted without
reading quantity state; active sequences retain strict bounds.

The sort trace proves installed small-three sorting behavior for this function.
It ends before hard-register allocation. The separate observation below covers
that next step. Neither observation establishes the retail compiler revision,
proves that correcting the sort would match retail, or justifies a source,
compiler-option or toolchain change. Preserve the spent source budget.

The complete private receipts are under
`_scratch/worker-resstream-allocation-policy/debugger-preparation/paired-sort-completion/`.
No compiler executable, game data or generated binary is included here.

## Separate actual allocation observation

A second bounded debugger/compiler/assembler run reproduced the same entire
object, assembly and inventory exactly. All input and live checks passed before
interpreting its eight owned events. No linker or source change was involved.

The actual register preference begins R3,R2,R1,R0. Quantity 0 is attempted first;
both R3 and R2 are free, and it selects R3. Its call adds only the R3 bit across
its ten live entries. Quantity 1 then overlaps two of those entries: its actual
exclusion mask contains R3 and leaves R2 free. It scans R3, skips it, then selects
R2. The captured fixed/class/live masks explain every exclusion bit.

Post-propagation records directly confirm 106 maps to R3 and 104/105 map to R2,
with zero offsets. This measures the installed sorting-to-allocation path, beyond
correlation with final assembly. The saved native comparison requires the
opposite PIC/vtable register roles. No reordered allocation was executed, and no
retail compiler state or matching source correction follows from this result.

Complete receipts: the sibling private `allocation-observer/` packet.
