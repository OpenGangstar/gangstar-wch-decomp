# ScriptManager::cleanCommand exact match

`ScriptManager::cleanCommand(Structs::ScriptCommand*)` matches all 212 retail
bytes at Thumb address `0x0033ffc1`, including relocations. Its 118-entry
jump table also matches all 472 retail bytes at `0x0042f28c`.

```text
OK  _ZN13ScriptManager12cleanCommandEPN7Structs13ScriptCommandE  0x0033ffc1  212 bytes
OK SECTION .script_manager_clean_command        0x0033ffc0  212 bytes
OK SECTION .script_manager_clean_command_table  0x0042f28c  472 bytes
```

## Source form

`cleanCommand` switches on the command opcode. For each opcode that owns
strings, it frees the argument strings with `delete[]` and clears the
pointers. The structure each case reads its arguments through decides its
delete and clear sequence:

| Structure | Sequence |
|---|---|
| `WaitCheckpoint` | `argument` |
| `SetAnim` | `argument2`, then `argument1`, or `argument1`, then `argument2` |
| `SetAnim2` | `argument3`, `argument1`, `argument2` |
| `ProtectNPC` | `argument2` |
| `AddRacer` | `argument3`, `argument1` |
| `VehicleChasePlayer` | `argument1`, `argument2` |
| `SetPhotoTarget` | `argument` (no clear) |

There is no default case.

Details that the retail bytes require:

- **Block layout.** The cases are grouped and ordered so that GCC 4.2.1's
  cross-jumping and basic-block reordering reproduce retail's block layout
  and jump table.
  - Each run of stacked labels shares one body.
  - Cases with equal behaviour are split into separate bodies where retail's
    edge frequencies need it.
- **VehicleChasePlayer.** Case 37 is placed after case 105. That makes 37 the
  separate `argument1`, `argument2` block that the `SetAnim2` tail cross-jumps
  into, as retail's jump table shows, while case 105 merges into the shared
  `SetAnim` block.
- **Behaviour.** Every case keeps its retail behaviour. Only the order of the
  case bodies and the grouping of their labels differ from a straight
  ascending switch.

No branch hint, inline assembly, register constraint or output edit is used,
and no header change.

## Verification

`python -B tools/build.py script-manager-helpers` passes the function and
both section checks. The dependent state-hook units pass. The
`ai-startup-script` unit keeps its Thumb binding for the call from
`Script::~Script`. A fresh complete build, `python -B tools/build.py --all`, exited 0 with 5,595 function, 5,683 section and 181 region comparisons and no mismatch or skip; the previous baseline was 5,594, 5,681 and 181.
