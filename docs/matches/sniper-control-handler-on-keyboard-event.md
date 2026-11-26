# SniperControlHandler::onKeyboardEvent exact match

`SniperControlHandler::onKeyboardEvent(IEvent const*)` matches all 400
retail bytes at Thumb address `0x0032f201`, including relocations. Its
98-entry key table at `0x00426a74` and the field-of-view static at
`0x004b5970` also match.

```text
OK  _ZN20SniperControlHandler15onKeyboardEventEPK6IEvent  0x0032f201  400 bytes
```

## Source form

The sniper control handler maps key presses to attacking, zooming, showing
or hiding the player and leaving sniper mode, and on release ends the
attack.

Details that the retail bytes require:

- **Release as a switch.** The released side is a one-case `switch` on the
  key. A switch gets no opcode branch heuristic, unlike the equivalent
  `if (key == 'F')`, so the release block's predicted frequency is above
  the pressed block's, and block reordering places it first as retail does.
- **Grouped case labels** for the pressed keys, private Character methods
  called through their mangled names and a file-local camera view, as in
  the matched `COnFootControlHandler::onKeyboardEvent`.
- **Field of view.** The zoom level is a file-scope `static int fov = 50`,
  placed at its retail address.

No branch hint, inline assembly, register constraint, output edit or header
change is used. The other SniperControlHandler.cpp functions keep their
bytes. The earlier non-matching draft and patch under `nonmatching/input/`
are retired.

## Verification

`python -B tools/build.py ai-startup-snipercontrolhandler` passes. A fresh complete
build, `python -B tools/build.py --all`, exited 0 with 5,628 function, 5,713
section and 180 region comparisons and no mismatch or skip; the previous
baseline was 5,627, 5,710 and 180 (the three new sections are the
function, key table and field-of-view placements).
