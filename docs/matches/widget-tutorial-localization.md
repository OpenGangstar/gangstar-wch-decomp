# Widgets::Tutorial::UpdateLocalization

The 464-byte Thumb function at `0x002ef6f5` matches in the widget owner and
MenuState consumer. It preserves localized title/content lookup, text-height
measurement, scroll reset and arrow visibility. Character pointers are reloaded
across callbacks rather than caching borrowed names.

The reconstruction reuses the authenticated `get_name()` const-reference and
shared string accessor chain. A never-instantiated partial view observes the
retail name at offset 136; it does not claim a complete character layout.
Existing matched name helpers remain unchanged. A real `tu_stringi` member
constructs the property temporary once, with ordinary automatic cleanup.

`RetailSwfValue.h` shares the existing 40-byte, eight-byte-aligned value type.
Only proven default-constructor and double-returning `to_number()` declarations
are added; implementations remain native imports. Their strong Thumb call
metadata is retained in both images. The consumer places new sections before
its existing discard rule, preserving actual compiled definitions.

```text
OK  _ZN7Widgets8Tutorial18UpdateLocalizationEv  0x002ef6f5  464 bytes
OK SECTION .widgets_tutorial_localize  0x002ef6f4  464 bytes
```

Function SHA-256:
`8c86c67af8d8e6bbace06c0037a425a6dc16b627b89591e7e0c63cf3b4a1378c`.
Only the target and three native-placed literal arrays are newly emitted.
Existing helper bodies, compiler flags, layouts and matched payloads are
preserved; no hints, register constraints or output edits are used.

The combined localization/mouse closure passes 634 functions, 407 sections and
five GOT regions. The full integrated gate passes 190 profiles and 10,656
comparisons, exit 0, with no mismatches or skipped profiles. The original source
remains incomplete, so no Fully Linked credit is added.

Primary public-domain references:
[character name accessor](https://github.com/weihuoya/gameswf/blob/7fdd64b3cdae7ad36ecaf1da023a5cb61cd38a9e/tu-testbed/gameswf/gameswf_character.h)
and [string interfaces](https://github.com/weihuoya/gameswf/blob/7fdd64b3cdae7ad36ecaf1da023a5cb61cd38a9e/tu-testbed/base/container.h).
The different upstream storage layout is not transplanted.
