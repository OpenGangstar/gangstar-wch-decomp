# Widgets::Volumes::UpdateLocalization

The 736-byte Thumb function at `0x002ef415` matches in both the widget owner and
MenuState consumer. It preserves volume sliders, on/off states, localized labels
and playlist selection. Names longer than 20 UTF8 characters use the original
17-character substring, trailing-space handling and ellipsis.

The shared string retains its verified retail 16-byte storage and unhinted
destructor. Authentic ordinary-inline `utf8_length()` calls the real static
`utf8_char_count(get_buffer(), length())`; `utf8_substring(start, end)` returns a
nontrivial string by value with its original hidden-result ABI. Native strong
Thumb callees remain imports; no vendor implementation is credited.

Final mute selections use ordinary float truth-value conditions, preserving
zero/nonzero behavior. All four hints from the historical candidate are removed.
No forced inlining, new lifetime, register constraint or output edit is used.
The singleton access sequence and both string lifetimes remain unchanged.

```text
OK  _ZN7Widgets7Volumes18UpdateLocalizationEv  0x002ef415  736 bytes
OK SECTION .widgets_volumes_localization  0x002ef414  736 bytes
```

Function SHA-256:
`fecadd57625dda22d1e7d2356a71428468f6de2372b21b98277c93a170f487b1`.
Only the target and 14 native-placed, byte-checked literal arrays are new. The
consumer selects them before its existing discard rule. The linker asserts the
complete 736-byte extent; no actual definition is masked by a retail binding.

The combined localization/mouse closure passes 632 functions, 397 sections and
five GOT regions. The full integrated gate passes 190 profiles and 10,644
comparisons, exit 0, with no mismatches or skipped profiles. Existing matched
functions, sections and GOT regions remain exact. No Fully Linked credit is
added because the original source is incomplete.

Primary public-domain reference:
[UTF8 string interfaces](https://github.com/weihuoya/gameswf/blob/7fdd64b3cdae7ad36ecaf1da023a5cb61cd38a9e/tu-testbed/base/container.h).
Retail static count is Thumb `0x00389ac1`/50 bytes; substring is Thumb
`0x00389f59`/160 bytes. Their declarations carry no invented weak or long-call
attributes.
