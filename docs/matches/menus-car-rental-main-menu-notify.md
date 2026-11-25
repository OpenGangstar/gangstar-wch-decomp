# Menus::ServiceCarRental::Notify and Menus::MainMenu::Notify exact matches

```text
OK  _ZN5Menus16ServiceCarRental6NotifyEPK10MenuWidgeti  0x002eb761  448 bytes
OK  _ZN5Menus8MainMenu6NotifyEPK10MenuWidgeti  0x002ea479  544 bytes
```

- **ServiceCarRental::Notify** fills the four shop slots for the current arrows
  page (price scaled, affordability flags, `"<name>"`/`"<name>_sel"` frames)
  or confirms the selected vehicle. A multi-way `switch (event)` for the arrows
  events gives neutral edge probabilities, and declaring `flags` after `name`
  and `suffix` reproduces retail's out-of-SSA copy order and register set.
  Retail shares `"%s%s"` at `0x00419e70` with MenuWidget; this file declares it
  extern hidden (verified not to change the code) and the MenuState linker
  script aliases it. `"_sel"` is placed at `0x00419e68`.
- **MainMenu::Notify** handles the four main buttons and the promotion link.
  Converting the looked-up widget to `const Widgets::MainMenu*` keeps the derived
  pointer alive into `GetPressedButton()` after GCC propagates the equality test.
  The promotion URL is placed at `0x00419f14`. The definition sits at the end of
  the source file: placed earlier, its declarations perturb
  ServiceCarRental::Notify's register allocation. The linker still places both
  functions at their retail addresses.

No hint, inline assembly or output edit is used.

Full gate: `python -B tools/build.py --all` exited 0 with 5,492 function,
5,569 section and 181 region comparisons and no mismatch or skip.
