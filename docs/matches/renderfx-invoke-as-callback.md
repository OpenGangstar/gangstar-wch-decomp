# RenderFX::InvokeASCallback exact match

`RenderFX::InvokeASCallback(gameswf::character*, char const*)` matches all 368
retail bytes at Thumb address `0x003eefad`, including relocations.

```text
OK  _ZN8RenderFX16InvokeASCallbackEPN7gameswf9characterEPKc  0x003eefad  368 bytes
```

## Source form

The function finds the sprite that owns an ActionScript callback (the
character itself, or its parent when the character is not a sprite), looks
up the named member and calls it.

The code matched earlier; the remaining difference was block order and the
register allocation that follows from it. Four commented hint forms give
retail's branch probabilities without emitting any code:

- **Null character.** `__builtin_expect(!character, 0)`.
- **Typed test.** The `is()` result is compared through a one-field struct
  against a non-zero constant, with a no-code `__builtin_prefetch` in the
  sprite arm. The call and comparison heuristics combine to 71%.
- **Null parent and parent type.** The same one-field struct comparison,
  which adds the comparison heuristic to the early return.

Later passes fold every test back to a plain compare with zero. The
combination was found by sweeping 1944 hint combinations over six branch
sites; it is the only one that gives both retail's block order and its
register allocation.

## Integration

The gameswf callees are bound as external Thumb functions, and the units
that link the RenderFX object place the function at its retail address.
