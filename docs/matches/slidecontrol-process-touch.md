# SlideControl::processTouch exact match

```text
OK  _ZN12SlideControl12processTouchEl  0x0032b665  668 bytes
OK SECTION .slide_process_touch  0x0032b664  668 bytes
OK  _ZThn8_N12SlideControl12processTouchEl  0x0032b650  20 bytes
```

Converts a touch on an enabled slide control into a normalised offset along
its axis (clamped to the configured minimum/maximum), raises a left/right or
up/down stick-move event and stores the knob offset.

Starting from the archived body (`nonmatching/ui/`, 96 differing bytes):

- The "no movement" test is written in the shape GCC's jump threading
  produces, `if (mode == Vertical || !x) { if (!y) return; x = 0; }`; the
  extra `x = 0` is a no-op when `x` is already zero. Building that merge in the
  source gives the `x` PHI a lower SSA number, so the following comparison
  keeps retail's operand order.
- The negated coordinate is computed before the limit is loaded, which gives
  retail's `cmp neg, limit`.
- For both axes the negative arm is written first; this removes an extra
  reload and gives retail's register choice for the float-negation constant.

The `slidecontrol-touch-thunk` verification image previously compiled its own
copy of the function to check the this-adjusting thunk; it now links the
canonical unit's object. The stick-move event destructors and vtables are
placed at their retail addresses. No header change, hint, inline assembly or
register constraint is used.

Full gate: `python -B tools/build.py --all` exited 0 with 5,537 function,
5,619 section and 181 region comparisons and no mismatch or skip.
