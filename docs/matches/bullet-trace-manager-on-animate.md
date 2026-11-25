# BulletTraceManager::OnAnimate exact match

```text
OK  _ZN18BulletTraceManager9OnAnimateEj  0x002f064d  496 bytes
OK SECTION .bullet_trace_on_animate  0x002f064c  496 bytes
```

Advances every active bullet trace. When a trace finishes it optionally shows
its impact node at the hit point, oriented from the trace direction, restarts
the impact's timeline animation once with the weapon animation callback, and
then removes the trace by moving the last active trace into its slot.

- The impact rotation's `quaternion` is declared before the `(1, 0, 0)` axis
  vector, which gives retail's order of the stack initialisation stores.
- The callback and its data are stored through named locals (`callback`,
  `data`), the pattern already used by matched code such as
  `Explosion::drawExplosion`. Loading `impacts[i]` into `data` before the
  callback's GOT load keeps that value live across the two-register GOT
  reload, so reload's round-robin spill choice includes r1 for the whole
  function, as in retail; without it every later reload chose different
  registers.

`ISceneNode::getAnimators` is bound to its retail Thumb address;
`quaternion::rotationFromTo` and the callback are reached through the GOT as
in retail. No header change, hint, inline assembly or register constraint is
used.

Full gate: `python -B tools/build.py --all` exited 0 with 5,531 function,
5,609 section and 181 region comparisons and no mismatch or skip.
