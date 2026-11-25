# AnimObject::IsAnimOver exact match

```text
OK  _ZN10AnimObject10IsAnimOverEv  0x00349445  112 bytes
OK SECTION .anim_is_over  0x00349444  112 bytes
```

Reports whether the next frame step would run past the animation's end: for a
multi-frame animation it computes `speed * frameStep + frame` and returns true
when playing backwards past frame 0 or forwards to at least the duration.

- Hoisting `float end = (float)duration` before the next-frame computation
  gives retail's `fcmpge(next, end)` operand order, and returning a named
  `bool over` for the forward test reproduces retail's register use.
- The remaining layout difference came from GCC's "opcode values positive"
  guess, which predicts `speed < 0.0f` at 21% and made the backward block a
  late trace. Testing the sign through a bool-returning inline helper,
  `IsPlayingBackward(speed)`, removes that guess and yields retail's block
  order.

No header change, hint, inline assembly or register constraint is used.
`__aeabi_fcmpgt` is bound to its PLT entry.

Full gate: `python -B tools/build.py --all` exited 0 with 5,516 function,
5,593 section and 181 region comparisons and no mismatch or skip.
