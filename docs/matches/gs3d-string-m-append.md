# std::string::_M_append exact match

The STLport `basic_string<char>::_M_append(char const*, char const*)` emitted in
the GS3DStuff unit matches all 372 retail bytes at Thumb address `0x002dcd29`,
including relocations. As in retail, it is a weak function. The existing
`append(char const*)` caller next to it is unchanged.

```text
OK  _ZNSs9_M_appendEPKcS0_  0x002dcd29  372 bytes
OK  _ZNSs6appendEPKc  0x002dce9d  40 bytes
```

## Source form

The body follows STLport 5.x `_string.c`: a length-error check, then either a
reallocating copy or an in-place append. The STLport copyright and modification
notice sits next to the definition. Details that the retail bytes required:

- The element count `n` is the pointer difference (`ptrdiff_t`). It reaches
  STLport's `(max)(old_size, (size_type)n)` as a cast temporary, as in the
  library source.
- `_M_throw_length_error` is `noreturn`.
- The small inline helpers (`_M_deallocate_block`, the uninitialised copy) are
  written in the body. With this unit's `-finline-limit` they would otherwise be
  emitted out of line.
- The deallocate test reads `static_buf + 16 != end_of_storage`.

`std::allocator<char>::allocate(unsigned, unsigned&)` and the length-error
function are reached through the GOT. Both are declared as weak `extern "C"`
symbols with their mangled names.

No branch hint, inline assembly, register constraint or output edit is used.

## Linking

The section is placed at `0x002dcd28` in the shared `GS3DSceneTraversal.ld`,
next to `append`. Every unit that links the GS3DStuff object therefore places
it too: game-object-list, game-object-manager, item, level-object, save-game,
sdk-startup-scenecamera and weapon. All of these were rebuilt successfully.

A fresh complete build, `python -B tools/build.py --all`, exited 0 with 5,574
function, 5,657 section and 181 region comparisons and no mismatch or skip; the
previous baseline was 5,571, 5,654 and 181.
