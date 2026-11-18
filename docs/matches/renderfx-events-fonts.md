# RenderFX event dispatch and font clearing

Both first source bodies match completely:

```text
OK  _ZN8RenderFX9SendEventERNS_5EventE  0x003ef139  200 bytes
OK  _ZN8RenderFX10ClearFontsEPN7gameswf14player_contextE  0x003eee95  280 bytes
```

SendEvent calls the existing listener before checking consumed, with no invented
null guard. Its ordinary C++ switch preserves all eight callback strings and
the no-action cases. The compiler-generated ten-entry, 40-byte relative table
and all complete literal sections compare in each of the three linked images.
No jump instructions or table bytes are handwritten or patched.

The genuine Event record is 296 bytes: the native 256-byte character path starts
at offset 37 after consumed at 36. The previous unknown12 byte view is preserved
through an alternate named payload view of observed scalar fields. Unknown28
remains opaque and uninitialized unless native behavior supplies a value.
Twelve independent ARM compiler assertions prove size and all relevant offsets;
_scratch/renderfx-event-abi.cpp/.s retain that check. Existing reader bodies and
controller layouts are unchanged.

ClearFonts preserves default-context selection, both weak native provider-clear
calls, movie traversal, root-character lookup, native type-30 filtering and text
reset. The movie array refines the same context-prefix extent; the existing
movie view is reused and only a read-only root pointer at offset 16 is exposed.
No full engine-object size or engine implementation is invented. The existing
four-byte empty-text constant at 0x0044d91c is reused, avoiding duplicate data.

Shared original-address placements and explicit function/data comparisons cover
RenderFX and both menu/widget images. Existing weak/provider/string imports and
all earlier RenderFX functions remain exact. Coordinator graph: 10 profiles,
1,940 passing function/section/GOT comparisons, exit zero. Proof:
_scratch/renderfx-events-fonts-root.log and .exit. All affected headers pass;
no old function body, Windows source or compiler output changes.
