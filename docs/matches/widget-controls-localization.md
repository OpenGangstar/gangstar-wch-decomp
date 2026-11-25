# Widgets::Controls::UpdateLocalization exact match

```text
OK  _ZN7Widgets8Controls18UpdateLocalizationEv  0x002ee6ed  292 bytes
OK SECTION .widgets_controls_localize  0x002ee6ec  292 bytes
```

Selections default from the HUD steering/throttle modes by scanning the retail
tables `Widgets::Controls::s_choiceSteerings` (three entries) and
`s_choiceThrottles` (two), then the four labels are set from the string
manager. Natural `for` loops over the tables, fully unrolled by GCC, give
retail's cold-store block order; the earlier if/else-if chains needed a hint and
still differed. The tables are declared, not defined, under their retail names;
the eight-byte `ControlChoice` record name and the four static string names are
not recovered (the function has no spills, so names do not affect bytes). The
strings are placed at retail addresses by `WidgetControlsLocalization.ld`,
shared with the MenuState image.

Full gate: `python -B tools/build.py --all` exited 0 with 5,479 function, 5,516 section and 181 region comparisons and no mismatch or skip.
