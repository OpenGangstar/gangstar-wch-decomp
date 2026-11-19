# Widgets::Confirm::UpdateLocalization

The 252-byte Thumb function at `0x002edec1` matches in the widget owner and
MenuState consumer. It preserves the optional message-ID guard, localized
message/yes/no text and character-pointer reloads across callbacks.

All three borrowed names reuse the existing Tutorial partial view's authentic
`get_name()` const-reference and shared string accessor chain. No duplicate
character class, new header, hint, lifetime workaround or compiler flag is
introduced. The previously matched helper bodies remain unchanged.

```text
OK  _ZN7Widgets7Confirm18UpdateLocalizationEv  0x002edec1  252 bytes
OK SECTION .widgets_confirm_localize  0x002edec0  252 bytes
OK SECTION .widgets_confirm_vtable  0x004a9b68  40 bytes
```

Function SHA-256:
`df4052d98fff9b6c658582b1cfca392d2626f14c696f44c9f47e860ad4166fff`.

Defining this virtual key function causes GCC to emit the real Confirm vtable.
Its symbol is 36 bytes; the allocated section is 40 bytes, including four native
zero alignment bytes before the Dialog vtable at `0x004a9b90`. The linker places
the actual compiled data at `0x004a9b68` and checks all 40 bytes in both images.
The comparison uses the real compiled definition, including its existing
alignment padding. Physical-span SHA-256:
`aa3433901eb84e2fd5f7d43993eca232056e124eab931945de4edf3cd8c1396c`.

The only new definitions are the target, three native-placed format literals and
that compiler-generated vtable. Existing compiled payloads and relocation
semantics remain unchanged. Both consumers select the new sections before their
existing discard rules; the complete target and support extents are asserted.

The affected closure passes 634 functions, 407 sections and five GOT regions.
The full integrated gate passes 190 profiles and 10,656 comparisons, exit 0,
without mismatches or skipped profiles. The original source remains incomplete;
only the 252 function bytes add code progress, with no Fully Linked credit.

Shared accessor provenance is recorded in
[the Tutorial localization note](widget-tutorial-localization.md).
