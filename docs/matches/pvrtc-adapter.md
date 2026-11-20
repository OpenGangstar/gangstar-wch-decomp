# PVRTC adapter match

PVRTCDecompress at Thumb 0x0020ccd5 now matches all 20 native bytes and its
complete physical section at 0x0020ccd4. This reconstructs the thin adapter
already classified as game code. The native decoder remains an external Thumb
binding; none of its implementation or other vendor helpers is reconstructed.
No source classification or game-code denominator changes.

The wrapper passes its first four arguments unchanged, inserts 1 as the fifth
argument and forwards the original output pointer as the sixth. The actual
callee symbol establishes AMTC_BLOCK_STRUCT*, four int arguments and an
unsigned-char pointer. The inferred void source view is consistent with the
observed epilogue and legacy interface, but the original return type and wrapper
authorship are not proven. Complete machine-code equality preserves the native
R0 behavior. No internal direct/static caller or relocation supplies additional
return-type evidence; this does not exclude external or dynamic callers.

Only one ordinary C++ candidate was needed, using existing NDK 1.6_r1 GCC 4.2.1
flags. No hints, inline assembly, compiler-output editing or helper bodies.
The coordinator independently rebuilds the reviewed source and obtains:

```text
BUILD pvrt-decompress
OK  _Z15PVRTCDecompressPKviiiPh  0x0020ccd5  20 bytes
OK SECTION .pvrtc_wrapper  0x0020ccd4  20 bytes
```

Native and linked function SHA256:
`b800cb4f7edbb0d4ce1b8f1ca98585da5737230927c21a6431d90ce611426bf0`.
The object defines only the assigned function. Exact start, size and end guards
retain the original decoder end and next animator-factory constructor start:
0x0020ccd4 through 0x0020cce8. Those native neighbors are not newly compiled or
moved by this profile.

The full current-root native gate passes 191 profiles, 5435 functions, 5339
sections and 181 regions: all 10955 comparisons exact, exit 0, with all 1065
frozen source/configuration/tool/nonmatching inputs stable. The coordinator then
removes only the verified assembly marker and regenerates the official tables.
All 17703 original identities, classifications and sizes remain unchanged;
only this function changes from pending to matched.

Matched/Fuzzy becomes 344426/561716 bytes (61.32%), 4273/4550 functions.
Fully Linked remains 112376/561716 bytes (20.01%), 125/203 units. Five functions
in this source unit remain pending; this match does not complete the unit.
No existing function body or native Windows implementation changes.
