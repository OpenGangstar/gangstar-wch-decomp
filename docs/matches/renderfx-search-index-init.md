# RenderFX::SearchIndex::Init exact match

`RenderFX::SearchIndex::Init(RenderFX&)` matches all 488 retail bytes at Thumb
address `0x003f02c5`, including relocations.

```text
OK  _ZN8RenderFX11SearchIndex4InitERS_  0x003f02c5  488 bytes
```

## Source form

`Init` clears the index, then walks every named character returned by
`FindCharacters`. For each one it builds the dotted path from the root by
walking the parent chain. It then appends an `Entry` to the name's entry list,
which is created on first use, and adds the list to the hash.

Details that the retail bytes require:

- **Name test.** The name-length test runs before the entry list is
  initialised. The name reference is bound after the test with a direct
  cast to the character's name field.
- **Hash insertion.** `hash::add` receives `this`, which is the address of
  `entries` at offset 0.
- **Why both matter.** Together these leave 190 instructions entering gcse1, so
  its expression table has 47 buckets. With 47 buckets, PRE creates the
  stack-guard GOT offset register before the `&list` register, which gives
  retail's spill slots. At 192 instructions the table has 49 buckets, and the
  two slots swap.
- **Placement.** `Init` is defined before `Clear` in the source, so its call to
  `Clear` stays a GOT call, as in retail.
- **Entry list.** The file-local `gameswf::array<Entry>` specialisation gains
  a constructor, a `push_back` and an out-of-line `resize`, declared
  `weak, long_call` to match retail's GOT call.

Every call and GOT slot was checked against retail: `FindCharacters`,
`memset`, `strcat`, `memcpy`, `operator delete`, `strlen`, the `swf` operator
new, `__stack_chk_fail`, `__stack_chk_guard`, `Clear`, `hash::find_index`,
`array<Entry>::resize` and `hash::add`.

No branch hint, inline assembly, register constraint or output edit is used,
and no header change.

## Verification

`python -B tools/build.py` passes for renderfx-animation, ai-startup-menustate
and ai-startup-menuwidget. `strcat` is bound at its PLT address `0x001c43a0`.
A fresh complete build, `python -B tools/build.py --all`, exited 0 with
5,597 function, 5,685 section and 181 region comparisons and no mismatch or
skip; the previous baseline was 5,596, 5,684 and 181.
