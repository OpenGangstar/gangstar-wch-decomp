# MenuManager::setText exact match

`MenuManager::setText(MenuManager::eText, char const*, int*)` matches all 1104
retail bytes at Thumb address `0x002e51fd`, including relocations. Its
17-entry jump table also matches all 68 retail bytes at `0x004191e4`.

```text
OK  _ZN11MenuManager7setTextENS_5eTextEPKcPi  0x002e51fd  1104 bytes
OK SECTION .menu_manager_set_text        0x002e51fc  1104 bytes
OK SECTION .menu_manager_set_text_table  0x004191e4  68 bytes
```

## Source form

`setText` does the following in order:

1. If the text slot's character is not cached yet, it looks the character up
   in the menu movie by slot name. It returns `false` when the character is
   missing.
2. It shows or hides the character and stores the text. When the text is
   null it returns `true`.
3. It sets the text and, when asked, writes the text height to `*arguments`.
4. For the cutscene dialog slot, it also clamps the dialog's `_y` to keep the
   text on screen.

Details that the retail bytes require:

- **Null re-check placement.** The cached-character null re-check sits after
  the lookup `if`, not inside it. That removes the call heuristic from the
  switch edge. With the 19% branch into the switch, bb-reorder places all 54
  blocks, including the 17 case blocks, in retail order. This was modelled
  with the bb-reorder simulator before compiling.
- **Visibility flag.** The visibility flag is a named `bool` used twice. Its
  second use keeps a separate 50/50 PHI block, as in retail.
- **Dialog clamp.** The cutscene dialog's `_y` is computed by an if/else over
  named `bottom` and `dialogY` locals. That join breaks the cse1 path between
  the text-height read and the `_y` write, so the `tu_string` constructor
  address is reloaded from the GOT as retail does, rather than shared.
- **Character access.** `setMember` addresses the character as
  `characters[slot]`, which is `characters[2]` in that block. This keeps the
  `this + 344` add, so the 344 offset stays in callee-saved `r5` across the
  `set_double` call.

## Strings and data

The 19 slot and property names are file-local arrays. The 18 slot names are
placed as one pool at `0x00418db4`. Retail shares `textHeight` (`0x00418f50`)
with MenuState:
- The helper and state-hook links place the helper's copy there.
- The ai-startup-menustate link checks MenuState's own copy there and moves
  the helper's duplicate to verification-only storage.

No branch hint, inline assembly, register constraint or output edit is used,
and no header change.

## Verification

`python -B tools/build.py` passes for menu-manager-helpers,
ai-startup-menustate and the five state-hook units that link the helper
object. A fresh complete build, `python -B tools/build.py --all`, exited 0 with
5,603 function, 5,693 section and 181 region comparisons and no mismatch or
skip; the previous baseline was 5,602, 5,691 and 181.
