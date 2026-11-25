# Widgets::Mission::OnEvent and Widgets::MapLegend::OnEvent exact matches

```text
OK  _ZN7Widgets7Mission7OnEventERN8RenderFX5EventE  0x002ed215  132 bytes
OK  _ZN7Widgets9MapLegend7OnEventERN8RenderFX5EventE  0x002ed299  240 bytes
```

Both handlers test the click as `switch (event.type) { case 6: ... }`. The
single-case switch has neutral edge probability; `if`/early-return forms get
GCC's equality heuristic and allocate registers differently (six and eight
bytes off in earlier attempts).

- Mission: on "btnStartMission", a pending teleport command (opcode 64) moves
  the player to the named object, then the map menu is restored. A file-local
  view reads the command's object-name word at +4.
- MapLegend: toggles `expanded` and plays the open/close animations, reusing
  the Objective frame strings.

Retail merges "btnLegend" into the tail of "widgetMapLegend.btnLegend", so the
source declares it `extern ... __attribute__((visibility("hidden")))` and the
linker script aliases it to `0x0041aab8`. Retail also shares "Map" at
`0x0040b608` with MenuState; the MenuWidget image checks it there and the
MenuState image gives the duplicate an unchecked address.

Full gate: `python -B tools/build.py --all` exited 0 with 5,484 function,
5,535 section and 181 region comparisons and no mismatch or skip.
