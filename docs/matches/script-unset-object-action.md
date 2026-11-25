# Script::unsetScriptObjectAction exact match

```text
OK  _ZN6Script23unsetScriptObjectActionEP11LevelObjectNS_13eScriptActionE  0x003398b5  136 bytes
OK SECTION .script_unset_object_action  0x003398b4  136 bytes
```

Clears one action bit from a level object's entry in the script's
`std::map<LevelObject*, int>` and erases the entry when no bits remain:

```cpp
if (found) {
    objectActions[object] &= ~action;
    if (objectActions[object] == 0)
        objectActions.erase(object);
}
```

Retail inlines STLport's `_Rb_tree::_M_find` (a lower-bound walk followed by a
`key < y.key` check), then makes two out-of-line `operator[]` calls and one
`erase_unique(key)` call. The project's `ScriptActionTree` is a layout view of
that map, so the lookup is written as a small static inline helper matching
STLport's algorithm, and the erase is bound by its mangled STLport name in the
same way the file already binds `_M_erase`.

- The find's header node is written as `&tree.headerColor` while `end()` is
  `&objectActions`. When both used the same expression GCC proved them equal
  and merged the not-found path, losing 8 bytes; retail keeps `this` in two
  registers.
- Comparing through a tiny iterator type's `operator!=` instead of a raw
  pointer compare gives retail's block order.
- The header test is written `header != y` (STLport spells it
  `__y != &_M_header`); this sets the compare operand order.

No header change, hint, inline assembly or register constraint is used.

Full gate: `python -B tools/build.py --all` exited 0 with 5,503 function,
5,580 section and 181 region comparisons and no mismatch or skip.
