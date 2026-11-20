# Minimap target-marker call grouping

The existing unmatched `MiniMap::draw2d() const` reconstruction fetched the
TargetMarker singleton separately for depth, X offset, Y offset and drawing.
Retail fetches it three times: once for depth, once for both offsets and once
for drawing. The reconstruction now retains the second pointer for both
stores. This changes an existing unmatched body; it does not credit the parent.

The native GOT literal at 0x0032a654 is 0x4450. With GOT base 0x004b0048,
the resolved slot contains 0x002e6661, TargetMarker::getInstance(). The
register BLX instructions are two bytes each. Calls at 0x0032a5d6 and
0x0032a5da precede depth storage at 0x0032a5d8 and the paired offset stores
at 0x0032a5f0 and 0x0032a600. The final singleton call is 0x0032a602.

The corrected candidate remains 1,356 bytes against 1,380 native bytes:

```text
MISMATCH  _ZNK7MiniMap6draw2dEv  0x0032a0f9
  expected : 4d 46 44 46 f0 b4 08 49 b7 b0 83 46 89 46 41 6c
  actual   : 4d 46 44 46 f0 b4 08 49 b5 b0 83 46 79 44 04 91
  differs at 0xe
```

Its complete linked SHA256 is
`8673dde0000228caa13c96eb5cf54ba71afadd9c01994fd45db281e126f3506c`.
The target-present private build exits 1 because the parent and its section
remain mismatched. Its 16 existing function and 18 region comparisons pass,
including the genuine 20-byte ARM secondary thunk. The fresh dependency
retains another 15 functions and 17 regions. Old absolute-symbol thunk
fixtures were not used as compiled proof.

After applying only this call-grouping correction to the existing
nonmatching body, the coordinator ran `python tools/build.py --all` against
the retail library. All 190 profiles passed: 5,434 function, 5,338 section
and 181 region comparisons, 10,953 exact comparisons total, exit 0.
All 1,042 frozen source/configuration/tool/nonmatching inputs stayed stable.
This gate verifies the existing credited definitions; it does not convert
the deliberately uncredited parent into a match.

No assembly marker, catalogue status, matched function, compiler flag or
native Windows source changes. Matched and Fuzzy Matched remain 61.31%;
Fully Linked remains 20.01%. Further parent work requires new evidence,
not another repetition of exhausted scheduling forms.
