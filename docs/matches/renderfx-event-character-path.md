# RenderFX::Event::GetCharacterPath exact match

```text
OK  _ZN8RenderFX5Event16GetCharacterPathEv  0x002e76e9  192 bytes
OK SECTION .event_character_path  0x002e76e8  192 bytes
```

Builds and caches the event's dotted character path: it walks the gameswf
character's parent chain (through the out-of-line weak-pointer
`check_proxy`), collects the non-empty names, then joins them from the root
with `strcat` and `"."`.

The function lives in MenuState.cpp's unit. Like the file's existing
`MenuManager` helpers it is defined under its retail mangled name as an
`extern "C"` function taking `RenderFX::Event*`, so `RenderFX.h` is not
changed (header changes perturb the matched `Menus::ServiceCarRental::Notify`,
which was re-verified). A local `PathCharacter` view describes the parent
weak pointer (+0x80/+0x84) and name string (+0x88).

- A single `return` after the cache test shares retail's return tail.
- `strcpy(path, "")` produces retail's `strb` through the path register.
- The traversal variable and the `parent` field are both typed
  `gameswf::character*`; with differing pointer types GCC kept separate
  pseudos and emitted an extra register copy at the loop entry and the parent
  load.

No hint, inline assembly or register constraint is used.

Full gate: `python -B tools/build.py --all` exited 0 with 5,516 function,
5,593 section and 181 region comparisons and no mismatch or skip.
