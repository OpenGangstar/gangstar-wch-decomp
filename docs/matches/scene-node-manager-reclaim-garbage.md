# SceneNodeManager::reclaimGarbage exact match

`SceneNodeManager::reclaimGarbage()` matches all 244 retail bytes at Thumb
address `0x003218d9`, including relocations. The other sections of
`SceneNodeManager.cpp` are unchanged.

## Source form

The function walks every node pool that has been idle for more than 60
seconds. It destroys available nodes whose last use is also older than 60
seconds, until the pool is back at its constructed count. The source is an
`extern "C"` definition over header-free views (`RGManager`, `RGPool`,
`RGNode`). Details that the retail bytes require, each commented in the source:

- **Exit order.** The inner loop is laid out before the time test and entered
  by `goto`, and the `size > constructedCount` test is hoisted to the loop
  head. The three `poolsLast` exit splits then come in retail's order, so
  reload's `r2`/`r3` alternation pairs the exits as retail does. Every test is
  side-effect free, so the reordering keeps behaviour.
- **Reload rotation.** Two statements are written as identical arms selected by
  `(int)now < 0`. Each compare takes one reload, which sets the spill-register
  rotation for the following exits and latch constant. Crossjump merges the
  arms after reload and deletes the selector, so neither emits code.
  - The first wraps `pool->pop_back()` in the destroy path.
  - The second repeats the loop's first `i < size` check before entering it.
