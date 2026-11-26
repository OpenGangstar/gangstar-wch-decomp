# ScriptManager::setState exact match

`ScriptManager::setState(ScriptManager::State)` matches all 732 retail bytes
at Thumb address `0x0033f1ed`, including relocations. Its 28-byte jump table
is placed at `0x0042f270` and compared.

```text
OK  _ZN13ScriptManager8setStateENS_5StateE  0x0033f1ed  732 bytes
OK SECTION .script_manager_set_state_table  0x0042f270  28 bytes
```

## Source form

The function switches the script manager's state: it locks or restores the
wanted level, the camera, the controls and the HUD, and when entering a
cinematic it finds the spawn point closest to the player and despawns the
nearby objects.

Details that the retail bytes require, each commented in the source:

- **Flags-test polarity.** The flags test is split into
  `t = (flags & 0x400) ^ 0x400; if (t == 0x400)` and a no-code
  `__builtin_prefetch` marks one arm as guarded. Together they predict the
  exit edge at 48.8%, which gives retail's branch direction.
- **Identical-arm statements.** Two statements of the form
  `if (test) store; else store;` survive until after register allocation,
  where cross-jumping merges the arms and the test is deleted, so no code is
  emitted. Their uses of the loop index and of `state` give those values
  retail's registers; with them, the per-axis distance values are evicted
  and spilled as in retail.
- **Player-position loads.** The three player-position loads come after the
  loop's two `continue` tests. Partial redundancy elimination then leaves
  them alone, and loop-invariant motion hoists them as the user variables,
  declared `float pz, py, px;`. That keeps retail's load order and gives the
  three values retail's stack slots, which a hoisted PRE temporary cannot.

## Integration

The shared ScriptManager query-section script places the function and its
jump table for every unit that links the ScriptManager helper object.
