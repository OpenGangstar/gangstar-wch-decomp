# ScriptManager::update exact match

`ScriptManager::update(int)` matches all 1220 retail bytes at Thumb address
`0x0033f511`, including relocations.

```text
OK  _ZN13ScriptManager6updateEi  0x0033f511  1220 bytes
```

## Source form

Each frame the function advances the vehicle-name banner, the failure and
achievement/tutorial transitions, the camera shake and the running
scripts.

Details that the retail bytes require:

- **Shift-based script indexing.** The script loop reads
  `*reinterpret_cast<Script**>((i << 2) + reinterpret_cast<int>(scripts))`.
  Scalar evolution does not analyse the shift, so ivopts keeps the index's
  original SSA name. That name is older than the `scripts` load, so the
  canonical operand order gives retail's `ldr r0,[r5,r3]`.
- **Block-order hint.** The fade test is written
  `(__builtin_prefetch(&s_fadeIntensity), s_fadeIntensity <= 0)`, with a
  source comment. The prefetch emits no Thumb code; it only lets the call
  heuristic lower that edge's probability, so bb-reorder places the
  widget-reset block before the fade test as retail does.
- **Real `setText` return type.** `MenuManager::setText` returns `bool` (as
  its matched definition does), so it is called through that
  `extern "C"` declaration. A value-returning call sets `r0`, which changes
  the scheduler's dependences and gives retail's argument-setup order.
- **Shared strings.** "Tutorial" and "Achievement" are named static arrays
  placed at their shared retail addresses (`0x00414c8c`, `0x00419ef4`),
  like the other units that use them.

The section is 1224 bytes: the body plus the `c046c046` pad that retail
also has before the next function at `0x0033f9d8`. The five state-hook
units that link this object discard the new sections, since they do not
place them. Behaviour is unchanged. No inline assembly, register
constraint, flag change, output edit or header change is used.

## Verification

`python -B tools/build.py script-manager-helpers` passes. A fresh complete
build, `python -B tools/build.py --all`, exited 0 with 5,644 function,
5,713 section and 180 region comparisons and no mismatch or skip; the
previous baseline was 5,643, 5,713 and 180.
