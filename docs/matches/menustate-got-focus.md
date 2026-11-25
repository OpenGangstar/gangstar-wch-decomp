# MenuState::GotFocus exact match

`MenuState::GotFocus()` matches all 248 retail bytes at Thumb address
`0x002e86fd`, and its strict section ends at the retail extent.

```text
OK  _ZN9MenuState8GotFocusEv  0x002e86fd  248 bytes
OK SECTION .menustate_got_focus  0x002e86fc  248 bytes
```

## Source form

The function visits all 32 menu widgets. Each visible widget is:

- enabled if its index is listed in the state's `widgetIds`;
- otherwise disabled if the state is modal;
- otherwise hidden, with the menu animation flag, if it auto-hides.

Every listed widget that is not visible is then shown.

Earlier forms had 12 register-byte differences. They looked the listed widget up
with a getter whose two null results formed a three-set phi. That phi had a live
length of 48, so global allocation ranked the widget (about 57) below the entry
index (about 73), and the index took `r4`.

The second loop now reads the table directly with one combined condition:
`index >= 0 && index < table.count ? table.widgets[index] : 0`. This uses the
file-local `MenuWidgetTable` view already used elsewhere in MenuState.cpp. The
single shared null block matches retail's one `movs r4,#0`. It shortens the
widget's live range to 10, so the widget is allocated first and gets `r4`, and
the index gets `r6`.

As in retail, `IsVisible`/`Show` are still called on an out-of-range null result.

The function is placed directly before `Menus::MainMenu::GotFocus`, matching
retail order. Placing it at the end of the file perturbs
`ServiceCarRental::Notify` through declaration order.

No header change, branch hint, inline assembly, register constraint or output
edit is used.

## Verification

`python -B tools/build.py --all` exited 0 with 5,545 function, 5,627 section
and 181 region comparisons and no mismatch or skip. Unit tests, repository
checks and progress checks pass.
