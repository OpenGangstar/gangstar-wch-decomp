# RenderFX::Find exact match

`RenderFX::Find(char const*, gameswf::character*)` matches all 416 retail bytes
at Thumb address `0x003ed6e5`, and its strict section ends at the retail extent.

```text
OK  _ZN8RenderFX4FindEPKcPN7gameswf9characterE  0x003ed6e5  416 bytes
```

## Source form

The function splits a dotted path into components. For each component it
collects the candidate characters below the current parent with
`FindCharacters`. It keeps the candidate whose name matches exactly and whose
parent chain back to the current parent is shortest. The parent chain is walked
through the weak parent pointer, clearing references whose proxy is no longer
alive. The winning candidate becomes the parent for the next component.

Three details decide the bytes:

- **The walk.** The loop variable that walks the parent chain is itself the
  file-local `CharacterFindFields` view pointer, re-cast only at the bottom of
  the loop. Casting through a separate helper created an extra SSA name and a
  top-of-loop copy. That code pushed two branches out of short range (420
  bytes).
- **Store and compare order.** `bestDepth` is stored before `result`, and the
  first test is written `parent != character`. Both give retail's store and
  compare operand order.
- **The weak-proxy check.** It reads the alive byte through the existing
  integer-address idiom, which keeps retail's null check after the dereference.

The file keeps an older unused inline parent accessor next to these views.
Removing it renumbers declarations and perturbs this function's register
allocation, so a comment records why it stays.

No header change, branch hint, inline assembly, register constraint or output
edit is used.

## Verification

`python -B tools/build.py --all` exited 0 with 5,557 function, 5,640 section
and 181 region comparisons and no mismatch or skip. Unit tests, repository
checks and progress checks pass.
