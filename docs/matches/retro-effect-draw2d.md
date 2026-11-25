# RetroEffect::draw2d exact match

```text
OK  _ZNK11RetroEffect6draw2dEv  0x0032abe9  332 bytes
OK SECTION .retro_draw2d  0x0032abe8  332 bytes
```

When the effect is enabled, shows menu widget 29 if hidden and draws the
effect texture over the 854x480 screen with a random -2..1 pixel jitter, then
restores a default 2D material; when disabled, hides the widget.

Retail keeps the constant 1 in r9 for both the `flags & 1` test and the
`useAlphaChannel` argument of `draw2DImage`. The archived form put the draw
code after an `if/else` whose else branch returned; the join label then had
two predecessors, cse1 lost the test's context, and a separate `mov #1` came
out (324 bytes). Placing the draw code inside the `if (flags & 1)` block (the
hide path in the `else`, without an early return) lets cse1 skip over the
`Show()` block and keep the constant shared.

The `retroeffect-draw-thunk` verification image previously compiled a local
copy of `draw2d` to check the compiler-generated this-adjusting thunk; it now
includes the matched canonical source only, and the main unit also places
that thunk. `MenuManager::getInstance` and `MenuWidget::IsVisible` are bound to
retail Thumb addresses and `lrand48` to its PLT entry. No header change, hint,
inline assembly or register constraint is used.

Full gate: `python -B tools/build.py --all` exited 0 with 5,522 function,
5,599 section and 181 region comparisons and no mismatch or skip.
