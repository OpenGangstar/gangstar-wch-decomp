# Menus::ServiceMissions::Notify exact match

`Menus::ServiceMissions::Notify(MenuWidget const*, int)` matches all 340
retail bytes at Thumb address `0x002eb9dd`, including relocations. The form
uses no hints.

```text
OK  _ZN5Menus15ServiceMissions6NotifyEPK10MenuWidgeti  0x002eb9dd  340 bytes
```

## Source form

The handler forwards to the base menu, then, when the page arrows widget is
the sender, looks up the available mission scripts and fills the mission
and title widgets for the selected page.

The earlier best form differed in two reload registers (`r3` where retail
uses `r2`). Both come from one source detail: the page slot is cast twice,
independently, with the compare cast first:

```cpp
void* pageSlot = 18 < table.count ? table.widgets[18] : 0;
const MenuWidget* pageWidget = static_cast<const MenuWidget*>(pageSlot);
const Widgets::Arrows* arrows = static_cast<const Widgets::Arrows*>(pageSlot);
if (widget != pageWidget)
    return false;
```

Partial redundancy elimination then creates the compare value's merge
first. Leaving SSA form emits the null arm's zero copies in that order, so
the reload pass finds the first register busy, takes `r2`, and its register
rotation gives retail's choices at both sites. With the arrows cast first,
the old 9-byte difference returns.
