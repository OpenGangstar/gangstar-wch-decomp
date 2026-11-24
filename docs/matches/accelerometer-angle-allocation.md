# Accelerometer angle allocation: unmatched diagnostic

`AccelerometerBase::_calcAngles()` (`_ZN17AccelerometerBase11_calcAnglesEv`)
remains unmatched at retail Thumb address `0x0034d479`, size 264 bytes. The
retained candidate has 256 bytes. Its assembly marker remains in the queue;
this investigation adds no matched functions, bytes, or Fully Linked credit.

## Equivalent-output control

One unchanged-source frontend/assembler pair used the reconstructed current
15-option compiler recipe with tree and RTL detail dumps. Both processes exited
zero. No debugger or linker ran. The runner printed:

```text
Whole historical object/assembly and inventory EXACT; owned trace eligible. Native264 remains unmatched.
```

The complete historical 7,540-byte object reproduced with SHA-256
`3baa4946cb96adec5f5953b6d4d3d0802e5a6303ae493ad04a34607596b35b6d`.
The complete 13,971-byte assembly reproduced with SHA-256
`e6bf0b4a63949996db6dccebde78fc93275c80905bded964a2f4c44120f1ae73`.
All inventory fields also reproduced: 21 definitions, 25 allocated payloads,
13 imports, 69 references, 53 sections, and 110 symbols. The 3,956-byte source,
793-byte private header, and all 195 input pins in three file sets stayed
unchanged. There were 117 diagnostic dumps and two compiled outputs.

Output identity establishes that the diagnostic describes the retained
candidate. It does not authenticate historical compiler options or environment,
or identify the retail compiler patch set.

## First measured register assignment

The expand dump creates compiler PIC/GOT pseudo 112 and loads the EPSILON
floating value into pseudo 110. The latter is distinct from its source pointer.
The local-allocation dump reports neither pseudo assigned a hard register.
The first retained boundary with physical homes is pass 138, global allocation
and reload: PIC uses R7 and EPSILON uses R8. The retail code uses PIC in R8 and
EPSILON in R7.

This boundary does not distinguish initial allocation from reload retries.
The worklist order does not prove why the compiler selected these registers.
No runtime observation of that choice was performed.

## Store topology and residual

The original tree, optimized tree, and expand dump already contain three
separate assignments per axis: positive clamp, negative clamp, and atan2f.
All nine stores survive through the final instruction-length pass. Pass 147
reorders them into positive X/Y/Z, atan X/Z/Y, and negative X/Y/Z; it does not
create duplicated stores. The resulting cold-handler order agrees with retail.
The retail function really calls atan2f three times; a truncated listing must
not be used to infer their absence.

The retained extent ledger is retail 238 code bytes, two alignment bytes and
24 pool bytes, versus candidate 230 code bytes, two alignment bytes and 24 pool
bytes. Retail has two extra entry transport bytes and two extra transport bytes
for each of the three positive clamps. Negative-clamp transport/store extent
differences cancel. These observations do not establish the original source.

No new linked comparison, source candidate, compiler option control, canonical
edit, or progress change was made. Preserve the spent six-form budget. Revisit
only with a supported new source/type/compiler constraint; do not repeat a
store-order search based on a pass that already agrees with retail.

The private execution report has SHA-256
`6358e63f5008e9a2d60e0e93138f4c9602b07a10634ba7d01acdf8dc091e18fa`.
The coordinator verified that report and all 116 sealed owned-analysis files
before accepting these findings.
