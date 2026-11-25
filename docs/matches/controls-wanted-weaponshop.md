# Widgets::Controls::OnEvent, WantedLevelManager::onEvent and Menus::ServiceWeaponShop::Update

```text
OK  _ZN7Widgets8Controls7OnEventERN8RenderFX5EventE  0x002efda5  372 bytes
OK  _ZN18WantedLevelManager7onEventEPK6IEventPK12EventManager  0x00343141  368 bytes
OK  _ZN5Menus17ServiceWeaponShop6UpdateEv  0x002eb45d  380 bytes
```

- **Controls::OnEvent** cycles the steering or throttle choice on left/right and
  applies it to the HUD, then saves preferences. The single-case
  `switch (event.type)` gives the click body a neutral edge probability; the
  `if` form allocates registers differently. "steering"/"throttle" are placed
  at their retail addresses; the button names reuse existing statics.
- **WantedLevelManager::onEvent** counts arriving/leaving cops from NPC and
  vehicle events, reacts to player crimes and re-evaluates the wanted level. A
  two-case `switch` on the vehicle event type (instead of an if/else chain) and
  `unknown8 < 2` in place of the equivalent `== 1` set GCC's predicted edge
  frequencies so block reordering reproduces retail; the emitted compare is still
  `cmp r3,#1; beq`. The jump table and four log strings are placed and compared.
  `NPC` grants `WantedLevelManager` friendship and `EvNPCVehicle` gains a
  `getType()` accessor. The `wanted-update-thunk` verification image now places
  the new function and binds `printf`.
- **ServiceWeaponShop::Update** applies a confirmed purchase. Writing the widget
  lookup as `count <= 16 ? 0 : widgets[16]` reproduces retail's block polarity
  without a hint.

No hint, inline assembly or output edit is used.

Full gate: `python -B tools/build.py --all` exited 0 with 5,490 function, 5,565 section and 181 region comparisons and no mismatch or skip.
