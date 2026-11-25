# ScriptManager::reachRunningCommand exact match

`ScriptManager::reachRunningCommand(int)` matches all 112 retail bytes at
Thumb address `0x0033d271`, including relocations.

```text
OK  _ZN13ScriptManager19reachRunningCommandEi  0x0033d271  112 bytes
```

## Source form

The function collects the running scripts into a temporary
`new Script*[scriptCount]` array. It then advances each collected script to
the given command with `Script::nextCommand` and frees the array with
`operator delete`.

Details that the retail bytes require:

- **Running predicate.** The `getState() == Script::State2` test goes through a
  file-local `static inline bool isScriptRunning(const Script*)` helper. The
  helper keeps the natural branch probability that gives retail's register
  priorities for `this` and the loop index. A raw compare or a
  `__builtin_expect` hint does not.
- **Placement.** The body comes after `loadCommand` in `ScriptManager.cpp`.
  That keeps the numbering of `loadCommand`'s `C.149` initializer stable.

No branch hint, inline assembly, register constraint or output edit is used.
The only header change declares the method in `ScriptManager.h`.

## Verification

`python -B tools/build.py` passes for script-manager-helpers and every unit
that links the helper object. The new section is placed in the shared
`ScriptManagerQuerySections.ld`. A fresh complete build, `python -B tools/build.py --all`, exited 0 with 5,593 function, 5,680 section and 181 region comparisons and no mismatch or skip; the previous baseline was 5,589, 5,676 and 181.
