# Preferences::SampleAndSave

`_ZN11Preferences13SampleAndSaveEPKc`, Thumb entry `0x003438e5`, matches all
336 retail bytes. The definition belongs to `src/game/ui/Preferences.cpp`.

The reconstruction writes the native preference blocks in order, preserves the
separate singleton calls and volume conversions, and uses the current HUD,
SoundManager and orientation declarations. A narrow read-only view accesses the
observed StringManager word at offset 4 without claiming a complete class layout.

An archived exact candidate depended on global `long_call` destructor declarations
that affected other matches. This version keeps every canonical header unchanged.
It reuses the existing GS3D performance-profile lifetime pattern: construct real
DataStream and BlockInt objects in correctly sized and aligned storage, then call
their genuine native weak D1 imports exactly once on the native cleanup path.
FileStream retains its ordinary automatic lifetime. No existing function body is
modified, and no additional helper or destructor definition is emitted.

Coordinator verification:

```
python tools/build.py ai-startup-preferences
OK  _ZN11Preferences13SampleAndSaveEPKc  0x003438e5  336 bytes
```

That strict native-address link also preserves all 10 existing unit functions,
seven named sections and the complete 17,972-byte GOT region. The worker's full
consumer check passed 386 function, 242 section and five region comparisons;
15 native layout/ABI assertions also passed.

The coordinator's fresh `python tools/build.py --all` passed all 182 profiles and
10,259 function/section/region comparisons with exit zero. Local evidence is kept
in `_scratch/preferences-sample-save-integrated.log` and
`_scratch/preferences-sample-save-integrated-full.log` / `.exit`. The actual
native-address executable definition has size 336 and SHA-256
`8e14e3f474e0b6ac7df1d94c16d808a6c4aa4ad79694d3ebcc573b96e85647ce`.

Regenerated progress is 4,206/4,661 functions and 332,818/575,264 bytes, or 57.85%.
Preferences still has pending functions, so Fully Linked remains 18.03%; this
individual match does not complete its original source unit.
