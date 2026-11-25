# MenuManager::setup exact match

`MenuManager::setup(bool)` matches all 1792 retail bytes at Thumb address
`0x002e574d`, including relocations.

```text
OK  _ZN11MenuManager5setupEb  0x002e574d  1792 bytes
```

## Source form

`setup` builds the menu system in this order:

1. It loads the car-rental table from `./CarRentals.gmap`. Each record is read
   with its length prefix, and the stream is reseeked when a record reads short.
2. It copies the minimap reference and resets the four cursor entries.
3. It initialises RenderFX with the 512×512 glyph cache and the texture loader,
   creates and loads `MyMenuFX`, and sets the input behaviour.
4. It creates the 32 menu widgets and registers the 23 menu states in retail
   order.
5. It clears every text slot and hides the dialog arrow.

Details that the retail bytes require:

- The RenderFX initialisation parameters are stored in retail order: driver
  local, both cache sizes, the flag, the driver, then the loader.
- The cursor entries are reset in field order `unknown4`, `unknown0`,
  `unknown12`.
- The car-rental counters, the `CarRental` reader and the widget-array resize
  are reached through local `extern` declarations. The reader and the resize
  are `long_call`.

## Strings and data

The twelve names `setup` uses are file-local arrays placed at their retail
addresses. They are the rental file, the menu file, the widget and state
names, `Confirm` and `Tutorial`. The 16-byte zero initializer for
`new Structs::CarRental()` (retail `C.1518`) is placed at `0x00419820`, and the
inline `DataStream` destructor at `0x002d3654`.

The helper object is also linked by `ai-startup-menustate` and five state-hook
units.

- **Menu-state link:** that unit places its own copies of the shared strings,
  so the helper's copies go to verification-only storage.
- **Each dependent link:** `cleanupMap` and the destructor are placed in each
  one. `operator new`, `operator new[]` and the other new callees are bound in
  the shared `MenuManagerFocus.ld`.

No branch hint, inline assembly, register constraint or output edit is used,
and no header change.

## Verification

`python -B tools/build.py` passes for menu-manager-helpers, ai-startup-menustate
and the five state-hook units that link the helper object. A fresh complete
build, `python -B tools/build.py --all`, exited 0 with 5,588 function, 5,675
section and 181 region comparisons and no mismatch or skip; the previous
baseline was 5,587, 5,674 and 181.
