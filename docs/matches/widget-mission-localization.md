# Mission widget localization

Widgets::Mission::UpdateLocalization() at 0x002ed8ad matches all 580 bytes.
It updates mission-panel visibility, start-button state/text, objective,
location, type, reward and icon frame label using existing metadata and
localization interfaces. The original no-mission message path is preserved.

The existing 36-byte Structs::Mission declaration moves unchanged from
Mission.cpp to MissionData.h, included at its original declaration location.
The parser and all existing matched function bodies remain unchanged. This
shares the recovered record instead of introducing a duplicate guessed layout.
Native pointer mutability and existing call conventions are preserved.

Eleven original widget path strings also compare exactly. Shared native linker
placements retain the new method and literals in both widget and menu-state
verification images. The initial dependent link rejected a discarded method
referenced by the widget vtable; shared retention resolves that failure.
No compiler output is rewritten or missing function replaced by an absolute
address. The new symbol is an executable native-address STT_FUNC definition.

Validation:

```sh
python tools/build.py --all
```

Exit 0; all 9,763 function, section and region comparisons passed. Fresh widget,
Mission and RenderFX checks passed. Removing trailing blank lines afterward
leaves the complete widget object byte identical; current widget/menu-state/
Mission comparisons were rerun successfully. No branch hints, register
constraints, ordering barriers or gameplay tests are introduced. The 84 unit
tests and repository/progress checks run before commit.

Exact new function/paths and existing name/vtable output:

```text
OK  _ZN7Widgets7Mission18UpdateLocalizationEv  0x002ed8ad  580 bytes
OK SECTION .widget_mission_name  0x0041a8f0  16 bytes
OK SECTION .widget_mission_vtable  0x004a9a48  40 bytes
OK SECTION .widget_mission_objective  0x0041ad40  28 bytes
OK SECTION .widget_mission_message  0x00419090  28 bytes
OK SECTION .widget_mission_locationtitle  0x004190b8  32 bytes
OK SECTION .widget_mission_locationvalue  0x0041ad5c  32 bytes
OK SECTION .widget_mission_typetitle  0x0041ad7c  28 bytes
OK SECTION .widget_mission_typevalue  0x0041ad98  28 bytes
OK SECTION .widget_mission_cashtitle  0x0041adb4  36 bytes
OK SECTION .widget_mission_cashvalue  0x0041add8  36 bytes
OK SECTION .widget_mission_icon  0x0041adfc  24 bytes
OK SECTION .widget_mission_button  0x0041ae14  32 bytes
OK SECTION .widget_mission_buttontext  0x0041ae34  36 bytes
```
