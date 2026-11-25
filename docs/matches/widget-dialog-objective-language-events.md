# Widgets Dialog, Objective and Language OnEvent exact matches

```text
OK  _ZN7Widgets6Dialog7OnEventERN8RenderFX5EventE  0x002ee061  608 bytes
OK  _ZN7Widgets9Objective7OnEventERN8RenderFX5EventE  0x002ef901  252 bytes
OK  _ZN7Widgets8Language7OnEventERN8RenderFX5EventE  0x002efc31  372 bytes
```

All three test the click as `switch (event.type) { case 6: ... }`; the
equivalent `if` forms receive GCC's equality-edge heuristic and allocate
registers differently (Dialog's `if` control differs in 117 bytes).

- **Dialog** builds `"<name>.btn"` with the character's real `tu_string`
  (`c_str()` inline, whose heap test reproduces retail's branch layout), checks
  the event path prefix and maps the pressed button through 18 names; three
  reuse existing statics and seventeen new `dialog*` strings are placed at their
  retail addresses.
- **Objective** toggles `expanded` and replays the three open/close animations
  before refreshing its text. Retail merges `"btnObjective"` into the tail of
  `"widgetObjective.btnObjective"`, so it is an extern hidden symbol aliased to
  `0x0041aad4`.
- **Language** handles OK/left/right with the saved previous selection (retail
  keeps it in a register rather than reloading), switches and preloads language
  packs, and saves preferences. It calls no base handler, as in retail.

Retail-only callees are bound as external Thumb functions. No hint, inline
assembly or output edit is used.

Full gate: `python -B tools/build.py --all` exited 0 with 5,487 function,
5,555 section and 181 region comparisons and no mismatch or skip.
