# StringManager::loadPackSheet exact match

`StringManager::loadPackSheet(unsigned int, unsigned int)` matches all 976
retail bytes at Thumb address `0x0034b78d`, including relocations. Its
strings, pointer statics and buffers are placed at their retail addresses,
and their contents equal retail's.

```text
OK  _ZN13StringManager13loadPackSheetEjj  0x0034b78d  976 bytes
```

## Source form

The function opens the string sheet for a language pack, reads the string
count and each string, expands the markup escapes (colour tags, the
non-breaking space before punctuation and line breaks), and stores the
resulting table for the pack.

Details that the retail bytes require:

- **Length at function scope.** The string length is declared next to the
  count at function scope. As a block-scope local it shared a stack slot
  with the first endian flag; at function scope the two endian blocks
  share one slot instead, which gives retail's frame.
- **Scan latch.** The markup scan advances with `last = ++found;` before the
  next search, which places the phi copy after the search call as retail
  does.
- **Buffer reset order.** `source[0]` is cleared before `destination[0]`,
  which gives retail's order of the two buffer addresses in the loop
  preheader and literal pool.
- **Placed strings.** The colour tags, the non-breaking space and the
  needle set are named local arrays, so that each lands in its own section
  and can be placed where retail has it; the closing tag sits in another
  translation unit's string pool in retail. The code only loads the
  pointer statics, so its bytes are unaffected.
- **Mangled names.** `SHEETS`, `LANGUAGES`, `readAs<unsigned short>` (weak,
  called through the GOT as in retail) and
  `MenuManager::getCharAutoLineFeed` are declared through their mangled
  names, so no header changes.

No branch hint, inline assembly, register constraint, output edit or header
change is used. The other StringManager.cpp functions keep their bytes; the
`loadStyles` default constant is renumbered, which its wildcard placement
covers.

## Verification

`python -B tools/build.py sdk-startup-stringmanager` passes, and the placed
strings and pointer data compare equal to retail. A fresh complete build,
`python -B tools/build.py --all`, exited 0 with 5,629 function, 5,713
section and 180 region comparisons and no mismatch or skip; the previous
baseline was 5,628, 5,713 and 180.
