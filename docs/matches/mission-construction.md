# Mission construction

Both constructor aliases at `0x003360c1` match the same complete 128-byte
function and section. Native/linked SHA256:
`00c6a75a4b149c97695a3644a8a0de371c23bdd8b73be3fa5d31037e4bc11da8`.

The coordinator authorized one bounded seventh source form after six historical
attempts. It replaces only the eight pointer-zero assignments with ordinary
`memset(conditions,0,sizeof conditions)`. This is the actual eight-pointer array
at offsets 196 through 227. No padding, neighboring name bytes, mission count
or tail fields are cleared. Both AnimObject constructor calls, all member
initializers and final intro-sprite name byte remain unchanged. The ordinary
call expands to the eight native stores without an emitted memset call.
No compiler flags, inline assembly, forced builtins or output edits are used.

The fresh private baseline passes 32 functions, 25 sections and one GOT region;
the candidate passes 34 functions, 26 sections and that same GOT region, with
890 stable inputs. It introduces only C1/C2 aliases. The AnimObject constructor
is a genuine imported Thumb symbol at `0x00349375`; its body is not reconstructed
or credited by this change.

Integration places the unchanged constructor between the real destructor and
`getFrameModuleRect`, matching native definition order. Independent root checks
pass both aliases, the entire section, the actual adjacent compiled functions
and all existing owner comparisons. The final full gate passes all 191 profiles:
5,445 functions, 5,354 sections and 181 regions, totaling 10,980 exact comparisons,
exit 0, with all 1,072 inputs stable.

```text
OK  _ZN7MissionC1Ev  0x003360c1  128 bytes
OK  _ZN7MissionC2Ev  0x003360c1  128 bytes
OK SECTION .mission_constructor  0x003360c0  128 bytes
```

Only the two verified markers are removed. Catalogue accounting retains both
original aliases and their existing denominator convention; they share one
128-byte implementation. Mission still has pending code, so this match adds no
Fully Linked unit. No shared headers, existing function bodies or Windows port
files change for this function.
