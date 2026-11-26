# SaveGame::SampleAndSave exact match

`SaveGame::SampleAndSave(char const*)` matches all 1,388 retail bytes at
Thumb address `0x00344821`, including relocations.

```text
OK  _ZN8SaveGame13SampleAndSaveEPKc  0x00344821  1388 bytes
```

## Source form

The function samples the player, weapons, achievements, statistics and
scripts into save blocks and writes them to the given file.

Details that the retail bytes require:

- **PRE hash table size.** Partial-redundancy removal creates its
  reaching registers in expression-hash bucket order, and the table has
  `(insns at cse1) / 4 | 1` buckets. Retail's spill-slot order fits only a
  133-bucket table. Reading the achievement's completed flag through a
  file-local bitfield view, into an unsigned local, adds two
  expand-level instructions that combine removes later, which gives that
  table size. The bit tested is the same as `flags & 2`.
- **Read-only manager load.** The achievement manager pointer is read
  through an `extern "C"` declaration of its mangled name qualified
  `const`. That marks the load read-only, which removes a scheduler
  anti-dependence against a spill store and gives retail's instruction
  order. The global itself is not const; this redeclaration exists only
  to reproduce retail's schedule and is accepted by the maintainer as a
  byte-exact form.

No branch hint, inline assembly, register constraint, output edit or header
change is used. The other SaveGame.cpp functions keep their bytes.

## Verification

`python -B tools/build.py save-game` passes. A fresh complete build,
`python -B tools/build.py --all`, exited 0 with 5,632 function, 5,713
section and 180 region comparisons and no mismatch or skip; the previous
baseline was 5,630, 5,713 and 180.
