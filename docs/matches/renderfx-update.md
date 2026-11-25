# RenderFX::Update exact match

`RenderFX::Update(int, bool)` matches all 248 retail bytes at Thumb address
`0x003f0041`, and its strict section ends at the retail extent.

```text
OK  _ZN8RenderFX6UpdateEib  0x003f0041  248 bytes
OK SECTION .renderfx_update  0x003f0040  248 bytes
```

## Source form

The function advances the gameswf root by `elapsed / 1000` seconds. For each of
the four controllers whose tracked character is in play state 1, it sends a
type-2 event with the character's name and the controller index, then clears the
reference.

The earlier best had 12 to 17 block-layout bytes:

- **Retail's layout.** Retail places the non-null character test's call path out
  of line, so it predicts the null case.
- **Why a plain test did not.** A plain pointer test triggers GCC's non-null
  pointer heuristic, which predicts the opposite.
- **The fix.** The pointer is tested through a file-local
  `bool hasCharacter(const gameswf::smart_ptr<T>&)` helper. A bool-valued test
  is not subject to the pointer heuristic, so the guess and layout follow
  retail.

The helper is local to `menufx.cpp`, so `RenderFX.h` is unchanged.
`gameswf::root::advance(float, bool)` is declared in the file's local `root`
interface.

No header change, branch hint, inline assembly, register constraint or output
edit is used.

## Verification

`python -B tools/build.py --all` exited 0 with 5,549 function, 5,631 section
and 181 region comparisons and no mismatch or skip. Unit tests, repository
checks and progress checks pass.
