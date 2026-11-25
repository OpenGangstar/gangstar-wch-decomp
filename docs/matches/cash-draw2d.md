# Cash::draw2d exact match

`Cash::draw2d() const` matches all 324 retail bytes at Thumb address
`0x00327be9`, including relocations, as does its 20-byte non-virtual thunk at
`0x00327bd4`.

```text
OK  _ZNK4Cash6draw2dEv       0x00327be9  324 bytes
OK  _ZThn4_NK4Cash6draw2dEv  0x00327bd4   20 bytes
```

## Source form

`draw2d` draws the cash counter with its icons on the left or right side,
depending on the alignment.

Details that the retail bytes require:

- **Alignment flag.** The alignment is read once into `const bool left`.
- **Statement order.** The statements are, in order:
  1. `if (left) { left icons } else drawCash();`
  2. `if (left) drawCash();`
  3. `if (!left && icon != -1) { right icons }`
- **Why this order.** It keeps the right-icon block out of the right
  `drawCash` fall-through, so cse1 starts a fresh path and rebuilds the 0 and
  128 constants as retail does. It also puts the left icon test first in RTL
  order, which gives retail's reload scratch registers. Each `if` does
  distinct work.

No branch hint, inline assembly, register constraint or output edit is used,
and no header change. `memset` is bound at its PLT address.

## Verification

`python -B tools/build.py ai-startup-cash` passes the function, the thunk and
both sections. The `cash-draw-thunk` unit, which built the thunk from a
nonmatching draw2d draft, is retired: ai-startup-cash now checks every
function and section it checked. A fresh complete build, `python -B tools/build.py --all`, exited 0 with
5,594 function, 5,698 section and 180 region comparisons and no mismatch
or skip. The counts are lower than the previous 5,609, 5,700 and 181 because
the retired cash-draw-thunk unit re-checked functions, sections and one GOT
region that ai-startup-cash and other units already check. Matched coverage
rose from 77.08% to 77.19%.
