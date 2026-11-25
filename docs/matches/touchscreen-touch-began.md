# TouchScreenBase::touchBegan exact match

```text
OK  _ZN15TouchScreenBase10touchBeganERK7Point2DIsEl  0x0034ccf1  140 bytes
OK SECTION .touchscreen_touch_began  0x0034ccf0  140 bytes
OK SECTION .touchscreen_begin_message  0x0043604c  28 bytes
```

Traces "Finger pression detected", grows the slot count, initialises an
inactive slot's first point, swipe direction and point count, then shifts the
current point into `previous` and records the new point and touch time.

The earlier unapplied reconstructions
(`nonmatching/input/TouchScreenBase-touchBegan-*.md`) stored `point.x` and
`point.y` straight into `slot.first`. Out-of-SSA substitution then folded each
load into its store, so the first-point address and the active-flag value got
different registers from retail (7 to 10 differing bytes).

Copying the point into a local first restores retail's allocation and schedule:

```cpp
Point2D<short> p(point);
slot.first = p;
```

`Point2D` has a virtual destructor, so the copy constructor and assignment are
inlined non-trivial calls; the local is split into scalars that are both loaded
before the stores. No header, hint, inline assembly or register constraint is
used. The trace string is placed at its retail address. The
`TouchScreenWin32` unit, which previously bound `touchBegan` to retail as an
external Thumb function, now links the compiled body instead.

Full gate: `python -B tools/build.py --all` exited 0 with 5,500 function,
5,576 section and 181 region comparisons and no mismatch or skip.
