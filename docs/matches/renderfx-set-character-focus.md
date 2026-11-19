# RenderFX::SetFocus(character*, int)

The 356-byte Thumb function at `0x003ef201` matches the retail library exactly.
It preserves focus-out and focus-in events, ownership changes, event-listener
filtering and the original animation/callback sequence. Event initialization
matches the original stores; unobserved payload bytes are not fabricated.

The reconstruction reuses the current character-name const-reference and
shared string conversion/accessor chain. No helper or header body changes,
likelihood hints, register constraints or compiler flags are introduced.
Earlier direct string-selection forms were not exact; the authentic helper
structure now produces the original hot/cold name-access paths.

```text
OK  _ZN8RenderFX8SetFocusEPN7gameswf9characterEi  0x003ef201  356 bytes
OK SECTION .set_character_focus  0x003ef200  356 bytes
```

Function SHA-256:
`d43c6f2ec6aac79808816bcfc0b3e927c7acd820cc3dd081c2a5fa8a9b4541ed`.
Only the new target function/text section is emitted; no new helpers, vtables
or data objects are introduced. All 113 previous owning functions, 32 previous
section/region checks and three existing focus callers remain exact.

Both native consumers remove only the now-obsolete retail import and retain
the real compiled target at its original address, with explicit function and
section comparisons. The narrow closure passes 622 functions, 353 sections and
five GOT regions. No compiled definition is masked or replaced by a binding.

The full current-root gate passes 190 profiles and 10,590 comparisons. The
original source remains incomplete, so the 356 matched bytes add no Fully Linked
credit. Shared helper provenance is recorded in the CollectCharacters match note.
