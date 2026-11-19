# Menus::Options::Notify

The complete 208-byte Thumb function at `0x002eab95` matches retail using the
existing canonical `MenuManager::getWidgetByIndex` member. The previous
reconstruction used a free getter returning `void*`. Reusing the genuine typed
member changes GCC's allocation and scheduling sufficiently to reproduce the
native function, including its SoundManager address calculation.

The function delegates to `InGameMenu::Notify`, accepts button-release events
from widget 1, plays sound 222 with the existing playback-override flag, and
switches to the volume, controls, language or game-settings menu according to
the pressed button. Existing sound operations, arguments, switch cases and
manager evaluation counts remain unchanged from the faithful candidate.

No branch hints, compiler-flag changes, inline assembly, register constraints,
padding or output modifications are used. Existing shared headers and old
function bodies are unchanged. The partial IGMenu interface supplies the
already known nonvirtual `GetLastPressedButton` signature.

The comparison tool printed:

```text
OK  _ZN5Menus7Options6NotifyEPK10MenuWidgeti  0x002eab95  208 bytes
OK SECTION .options_notify  0x002eab94  208 bytes
```

The complete native function SHA-256 is
`9eb73296b3d3b6591b263642b111c4d4d2ba824785107255bc8f9f94e95c1f24`.
The linker asserts the complete 208-byte physical section extent.

The affected five-profile closure passes 636 function, 409 section and five GOT
region comparisons: 1,050 checks, retaining all 1,048 previous checks, including
the accepted InfoAchievements notification. No support implementation, vtable
or data section is added.

Two preceding probability experiments remained unmatched. Diagnostic RTL dumps
then refuted the hypothesis that late copy propagation removed the native SL
roundtrip: the differing choice already existed during allocation/reload.
Only the canonical source-interface reuse succeeded. Diagnostic compilations
preserved their corresponding ordinary assembly, objects and linked images;
none of their flags or failed candidate bodies are adopted.

The final integrated `python tools/build.py --all` exits 0 across all 190 profiles:
5,295 function, 5,192 section and 181 region comparisons (10,668 total), with no
failed or skipped profiles. Independent native executable audits have no missing
proofs for all 4,250 credited entries and all 1,647 completed-source entries.
All 89 tests, repository/progress checks and pinned objdiff schema validation pass.
The four-entry hourly batch adds 658 bytes: Matched/Fuzzy is 59.22%, and Fully
Linked remains 19.19%.
