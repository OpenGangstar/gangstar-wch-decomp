# Widgets::GameSetting::OnEvent and Widgets::Corruption::UpdateLocalization

```text
OK  _ZN7Widgets11GameSetting7OnEventERN8RenderFX5EventE  0x002efafd  308 bytes
OK  _ZN7Widgets10Corruption18UpdateLocalizationEv  0x002ef0b1  524 bytes
```

**GameSetting::OnEvent.** `if (listener) switch (event.type) { case 6: ... }`
gives the click case a neutral edge probability; `if (event.type == 6)` gets
GCC's equality heuristic and a different global allocation. The left/right/OK
button names reuse the file's existing `volumesLeftButton`,
`volumesRightButton` and `tutorialOkButton` statics (retail shares the
strings). Defining this key method emits the GameSetting vtable, placed at its
retail address `0x004a9930` and compared.

**Corruption::UpdateLocalization.** Visibility, enabling and text for the
corruption widget, with the 1500 price check. **Disclosed name choice:** the ten
string statics are unnamed in retail; the function spills three GOT offsets, and
reload orders those slots by gcse expression hash buckets of the symbol names.
The uniform `corruption*` names reproduce retail; the archived `corrupt*`
names reproduce the old six-byte slot mismatch. All strings are placed at their
retail addresses by `WidgetCorruptionLocalization.ld`.

Full gate: `python -B tools/build.py --all` exited 0 with 5,482 function, 5,530 section and 181 region comparisons and no mismatch or skip.
