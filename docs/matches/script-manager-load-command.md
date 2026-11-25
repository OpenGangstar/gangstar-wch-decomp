# ScriptManager::loadCommand exact match

`ScriptManager::loadCommand(DataStream&)` matches all 2,436 retail bytes at
Thumb `0x0033ddd5`, together with its 472-byte jump table and five 16-byte
constant arrays at their retail addresses.

```text
OK  _ZN13ScriptManager11loadCommandER10DataStream  0x0033ddd5  2436 bytes
OK SECTION .script_manager_load_command  0x0033ddd4  2436 bytes
OK SECTION .script_load_command_table  0x0042f098  472 bytes
```

## Source shape

The earlier reconstruction emitted 2,440 bytes: identical instructions with two
extra long branches. GCC 4.2.1 fixes edge frequencies at tree level; a single
grouped case for the 18 opcodes without payload (4, 15-18, 46, 48, 67, 68, 72,
81, 84, 86, 91, 104, 109, 110, 113) is one switch edge, while separate identical
case bodies keep 18 edges until RTL cross-jumping merges them. The merged block
then carries their combined frequency, so block reordering lets it fall into
the early print/return tail exactly as retail does.

- Each of the 18 opcodes has its own identical case body.
- Opcodes 47 and 112 have separate identical ShowTutorial bodies.
- Cross-jumping keeps the last identical body in source order, so the 113 body
  precedes 109; the survivor must be 48, 109 or 110.
- The opcode-only records use `Structs::NoPayloadCommand`, an inline-read
  four-byte record matching the existing payload pattern. Its name is not
  recovered; its layout equals `Structs::ScriptCommand`. Storing through the
  typed allocation before assigning `command` reproduces retail's store order.

No call, allocation, read or callback order changed. No hint, inline assembly
or output edit is used. `DataStream::Peek4` is bound as an external Thumb
callee; placements live in `ScriptManagerQuerySections.ld` so dependent images
link the same layout.

## Verification

`python -B tools/build.py script-manager-helpers` passed every function and
section. python -B tools/build.py --all exited 0 with 5,476 function, 5,509 section and 181 region comparisons and no mismatch or skip.
