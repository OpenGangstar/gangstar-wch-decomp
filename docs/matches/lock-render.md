# Lock::render exact match

`Lock::render()` matches all 304 retail bytes at Thumb address `0x002fd291`,
and its strict section ends at the retail extent.

```text
OK  _ZN4Lock6renderEv  0x002fd291  304 bytes
OK SECTION .lock_render  0x002fd290  304 bytes
```

## Source form

The body was rebuilt from the retail instructions:

- With no target, it returns.
- With a dead target, it clears the target, hides the billboard and renders.
- Otherwise it reads the device timer's real time and does one of three things:
  - flashes white between 750 and 1000 ms;
  - before that, sets a red/green health tint;
  - after 1000 ms, restarts the cycle.

  It then shows and renders the billboard.

Two source details decide the bytes:

- **Duplicated tails.** The dead-target path keeps its own
  `setVisible(false); render(); return;` tail. RTL cross-jumping then merges the
  5-instruction `setVisible` plus `render` tail into retail's shape, where the
  false path branches into the shared call sequence. A single join block, or a
  late boolean, does not produce it.
- **Load order in the tint path.** The tint path loads `billboard` and its
  null-checked `ISceneNode*` view before the float health ratio. This keeps both
  in `r7`/`r8` across the libcalls. The `SColor` is built directly in the
  argument, which keeps retail's channel store order.

`CustomBillboardSceneNode::setColor(ISceneNode*, SColor)` is the existing retail
symbol. It is declared locally in `Lock.cpp` through its mangled name. Declaring
it in `CustomBillboardSceneNode.h` perturbs the matched
`GameObjectManager::GetMetatypeFromName` through declaration UIDs, which the
first full gate showed.

No branch hint, inline assembly, register constraint or output edit is used.

## Verification

`python -B tools/build.py --all` exited 0 with 5,547 function, 5,629 section
and 181 region comparisons and no mismatch or skip. Unit tests, repository
checks and progress checks pass.
