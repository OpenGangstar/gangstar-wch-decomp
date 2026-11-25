# RenderFX::Load exact match

`RenderFX::Load(char const*, gameswf::player_context*)` matches all 312 retail
bytes at Thumb address `0x003edde5`, and its strict section ends at the retail
extent.

```text
OK  _ZN8RenderFX4LoadEPKcPN7gameswf14player_contextE  0x003edde5  312 bytes
OK SECTION .renderfx_load  0x003edde4  312 bytes
```

## Source form

The function does the following, in order:

1. Uses the default context when none is given.
2. Creates a `gameswf::player` with `swf::DefaultMemHint` and links it back to
   this `RenderFX`.
3. Sets the player's working directory to the file's directory, derived from
   the last `/` or `\`.
4. Loads the movie root.
5. Sets the root movie as the current context.

Retail keeps an empty default-constructed `tu_string` alive in memory within the
directory block. Its constructor stores the size tag and the terminating byte,
and GCC sinks the dead terminator store into the destructor's heap path.

The file-local `LoadWorkString` reproduces it with the real 16-byte inline and
heap union layout. Without the union, SRA scalarises the object away and the
register allocation shifts. The gameswf player constructor, `set_workdir` and
`load_file` are called through local mangled declarations. No header is changed.

No branch hint, inline assembly, register constraint or output edit is used.

## Verification

`python -B tools/build.py --all` exited 0 with 5,562 function, 5,645 section
and 181 region comparisons and no mismatch or skip. Unit tests, repository
checks and progress checks pass.
