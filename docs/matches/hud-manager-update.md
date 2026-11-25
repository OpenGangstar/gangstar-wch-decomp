# CHudManager::update exact match

`CHudManager::update(double)` matches all 720 retail bytes at Thumb address
`0x00324399`, and its strict section ends at the retail extent.

```text
OK  _ZN11CHudManager6updateEd  0x00324399  720 bytes
OK SECTION .hud_manager_update  0x00324398  720 bytes
```

## Source form

The earlier retained reconstruction
(`nonmatching/hud/CHudManager-update-authentic-list.patch`) differed in 14 bytes.
Two genuine source corrections remove all of them:

- The default-receiver release path ends the touch handling with `break`
  instead of jumping to the driving-HUD refresh through a label. Control flow is
  unchanged. Without the extra label, the join and the register copy at `+0x1d4`
  follow retail.
- `HudElement::getTouchRegion()` returns `irr::core::rect<float>`. It previously
  returned the raw `HudTouchRegion` struct, which callers reinterpreted as a
  rect. That reinterpretation is a `NOP_EXPR` that tree PRE hoisted ahead of the
  loop-index initialisation. With a rect-typed result, the argument is a plain
  address. Loop-invariant motion then emits the retail preheader order:
  `movs r3,#0; mov r1,sp; add r2,sp,#16; adds r1,#32`.

The `HudElement::getTouchRegion` definition builds the rect from the two stored
corner points. Its bytes, and the rest of `hud-element`, are unchanged.

Supporting interface changes:

- `TouchIDListSupport.h`: STLport-style `distance` and `ConstIterator` support,
  plus `TouchIDList::size()`.
- `MenuManager::isCurrentState(const char*) const`.
- `friend class CHudManager` in `ToggleButton` and `Radio`.

No branch hint, inline assembly, register constraint or output edit is used.

## Linking

Every unit that links `hud-manager-helpers.o` includes
`config/linker/CHudManagerUpdateSections.ld`, which places the function and its
two log strings at their retail addresses. `CHudManagerUpdateText.ld` places the
`"BlockingTutorial"` state name at `0x00414c84`. GSBlockingTutorial's own
identical retail string already occupies that address, so that unit links the
HUD copy at an unused verification address. It does not compare `update`.

## Verification

`python -B tools/build.py --all` exited 0 with 5,538 function, 5,620 section
and 181 region comparisons and no mismatch or skip. The previous baseline was
5,537, 5,619 and 181. Unit tests, repository checks and progress checks pass.
