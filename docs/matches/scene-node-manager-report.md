# SceneNodeManager::report exact match

`SceneNodeManager::report() const` matches all 384 retail bytes at Thumb
address `0x00321721`, including relocations. Its 436 bytes of format strings
are placed at `0x00421074` and also compare exactly.

```text
OK  _ZNK16SceneNodeManager6reportEv  0x00321721  384 bytes
OK SECTION .scene_node_report_strings  0x00421074  436 bytes
```

## Source form

The report prints one line per node pool (size, minimum, usage and idle
time) followed by totals. The class keeps its pools private and does not
declare the method, so the function is an `extern "C"` definition over
file-local layout views.

Details that the retail bytes require:

- **Zero-pools store order.** `totalMinimum += __builtin_constant_p(totalNodes);`
  inside the `totalNodes > 0` branch always adds 0 and is folded away after
  jump threading. It gives `totalMinimum` its own merge at the join, so the
  constant copies on the zero-pools path come out in retail's order.
- **Declaration order.** `averageUsage` is declared just before
  `totalMinimum` and assigned 0 after the loop, which gives its store retail's
  register.
- **Branch hint.** The folded builtin counts as a call for GCC's call
  heuristic, which lowers the branch's predicted likelihood. A documented
  `__builtin_expect(totalNodes > 0, 1)` restores retail's block order.
