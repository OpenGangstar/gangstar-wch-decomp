# Application::UnRegisterForUpdate exact match

`Application::UnRegisterForUpdate(IUpdatable*)` matches all 48 retail bytes at
Thumb address `0x002d4015`, including the relocation of its `operator delete`
call.

```text
OK  _ZN11Application19UnRegisterForUpdateEP10IUpdatable  0x002d4015  48 bytes
```

## Source form

Retail inlines STLport's `list<IUpdatable*>::remove(const value_type&)` behind a
null test of the argument. The reconstruction writes out that inlined
expansion over the existing `ApplicationListIterator.h` views:

- It walks the list with a saved `next` iterator.
- It unlinks every node whose value equals the argument, and frees the node
  with `operator delete`.

The decisive detail is the reference binding `IUpdatable* const& value = object;`.
It mirrors `remove`'s `const _Tp& __val` parameter. With it, the value is
reloaded after each delete call (`adds r1, r5, #0`), as in retail. Comparing
`object` directly gives 48 bytes with 35 differing.

The definition follows `UnRegisterForDrawingInScene`, matching retail address
order. No branch hint, inline assembly, register constraint or output edit is
used, and no header changes.

## Verification

`python -B tools/build.py application-helpers` passes every function and
section check of the unit. `Application::Quit` keeps its unchanged call
relocation to this function. The section is placed in the shared
`ApplicationRuntimeSections.ld`, so `state-hooks-gsfade`, which links the
application object, places it too. A fresh complete build,
`python -B tools/build.py --all`, exited 0 with 5,571 function, 5,654 section
and 181 region comparisons and no mismatch or skip; the previous baseline was
5,570, 5,653 and 181.
