# Menus::ServiceWeaponShop::Refresh exact match

`Menus::ServiceWeaponShop::Refresh()` matches all 568 retail bytes at Thumb
address `0x002e7ac5`, including relocations.

```text
OK  _ZN5Menus17ServiceWeaponShop7RefreshEv  0x002e7ac5  568 bytes
```

## Source form

`Refresh` resets the shop widget and sets the availability text. For each of
the four visible entries on the current page it then does the following:

1. It computes the scaled price.
2. It computes the item flags: 4 when weapons are limited or the item is
   restricted outside the game; otherwise 7 when the player is in the normal
   context and can afford the item, or 6 when not.
3. It clears the selectable bit for full health or full armour items.
4. It formats the frame name and sets the item.

Details that the retail bytes require:

- **Flags expression.** The flags use one outer condition, `limited == -1 &&
  (inGame || !restricted)`, and a single ternary for 7 or 6. Out-of-SSA's
  edge-leader forwarders then emit the 6, 4 and 7 constant blocks in retail
  order, and the price test branches with `bgt` as retail does.
- **Case order.** In the inner switch, `case 2` (health) is written before
  `case 1` (armour). That moves the reload spill-register rotation onto
  retail's registers.
- **Declarations.** The locals are declared C-style, in the order count,
  weapons, player, price, shop and arrows, which gives retail's spill slots.
- **Arrows lookup.** It is the one documented hint: `__builtin_expect(18 <
  table.count, 1)`. Retail places the missing-arrows block after
  `__stack_chk_fail`. Without the hint, that block's placement is the only
  difference: eight instruction lines in the unhinted forms. `18 < count` has
  no opcode heuristic in GCC 4.2.1, so only a probability change places the
  block. MenuState.cpp uses the same hinted widget-table lookup in two other
  matched functions.

No inline assembly, register constraint, flag change or output edit is used,
and no header change. `ServiceMissions::GotFocus` keeps all 228 bytes.

## Verification

`python -B tools/build.py ai-startup-menustate` passes every function and
section check. `WeaponManager::getWeaponLimitedTo` is bound as a Thumb callee.
A fresh complete build, `python -B tools/build.py --all`, exited 0 with
5,601 function, 5,689 section and 181 region comparisons and no mismatch or
skip; the previous baseline was 5,600, 5,688 and 181.
