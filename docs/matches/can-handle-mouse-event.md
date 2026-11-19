# CanHandleMouseEvent

The 92-byte Thumb function at `0x003eca0d` matches in the renderer owner and both
native consumers. It preserves the button-name substring search, character flag
at offset 307, type query and sprite-enabled field at offset 676.

The existing `CharacterCollectionFields::get_name()` const-reference and shared
string accessor chain reproduce the native inline/heap search paths. Relative
to the faithful candidate, only that borrowed-name expression changes. The
existing button literal is reused; no header, helper body, hint, compiler flag
or extra data definition is introduced.

```text
OK  _Z19CanHandleMouseEventPN7gameswf9characterE  0x003eca0d  92 bytes
OK SECTION .can_handle_mouse  0x003eca0c  92 bytes
```

Function SHA-256:
`f9b63df5fcdff52add2301ddb79c842241176cb8250b85a3d2162a26952ee076`.
The sole new definition is the real target. All three images retain its original
address, complete section check and 92-byte assertion. Stale Thumb imports are
removed only where the compiled definition now supplies the symbol.

The combined localization/mouse closure passes 634 functions, 407 sections and
five GOT regions. The full integrated gate passes 190 profiles and 10,656
comparisons, exit 0, with no mismatches or skipped profiles. Existing matched
payloads remain unchanged. The function belongs to the core progress area while
its original source remains `menufx.cpp`; no catalogue reclassification is made.
No Fully Linked credit is added.

Shared helper provenance is recorded in
[the character collection note](renderfx-collect-characters.md).
