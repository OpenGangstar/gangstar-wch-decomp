# StringManager::unloadPackSheet and ScriptManager::checkScreenPress exact matches

```text
OK  _ZN13StringManager15unloadPackSheetEjj  0x0034b5a5  114 bytes
OK SECTION .string_unload_pack_sheet  0x0034b5a4  116 bytes
OK  _ZN13ScriptManager16checkScreenPressEv  0x0033f4c9  72 bytes
OK SECTION .script_check_screen_press  0x0033f4c8  72 bytes
```

## StringManager::unloadPackSheet

Frees every string of a loaded pack sheet, then the sheet array, and clears
the sheet slot. The 116-byte section includes retail's two-byte alignment pad.
Retail keeps the sheet pointer in one register for both the loop and the final
`delete[]`. Re-reading the slot into the same `strings` variable before
`delete[]`, rather than deleting `packSheets[pack][sheet]` directly, puts both
values in one out-of-SSA partition and reproduces that.

## ScriptManager::checkScreenPress

Tests whether the whole screen rectangle is pressed, stores the result,
clears the touch state and returns the stored flag.

- Retail returns the raw byte at offset 24, so `ScriptManager.h` names it
  `bool screenPressed` (the old `unknown24[4]` becomes the bool plus three
  padding bytes). The one existing writer, in `COnFootControlHandler.cpp`, now
  assigns `false` to it.
- The region is built with the Irrlicht 1.4.2 two-corner constructor,
  `rect(position2d(0, 0), position2d(width, height))`, now added to
  `core/Rect.h`. With the four-value constructor GCC's sink pass moved both
  integer-to-float conversions after the zero stores, which kept the height in
  a callee-saved register.
- The function is placed after `ScriptManager::loadCommand`, matching retail
  order. Placing it earlier renumbered `loadCommand`'s `C.N` jump-table
  constants that the linker script places by name.

`TouchScreenBase::clear` is bound to its retail Thumb address and
`__aeabi_i2f` to its PLT entry. No hint, inline assembly or register
constraint is used.

Full gate: `python -B tools/build.py --all` exited 0 with 5,520 function,
5,597 section and 181 region comparisons and no mismatch or skip.
