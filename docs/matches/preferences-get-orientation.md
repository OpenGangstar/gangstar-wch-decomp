# Preferences::GetOrientation

The natural C++ implementation matches the complete 176-byte Thumb function
`_ZN11Preferences14GetOrientationEPKc` at `0x00343835`. It opens the preference
file, reads at most eight integer blocks, and returns the value of block 6 or
`-1`. Automatic objects preserve native BlockInt, DataStream and FileStream
cleanup on every exit. The original stored stream pointer is not reset.

The existing DataStream and Persistence headers, destructor bodies and compiler
flags are unchanged. The owning unit also emits the actual canonical weak
DataStream and BlockInt D1 definitions. Their executable sections are placed at
retail addresses and compared explicitly; neither is replaced by an address
binding. They were already matched, so only GetOrientation adds progress. No
additional data or helper implementation is introduced.

Reproduce with the configured matching toolchain and retail library:

```sh
python tools/build.py ai-startup-preferences
```

Exact comparison output:

```text
OK  _ZN11Preferences14GetOrientationEPKc  0x00343835  176 bytes
OK  _ZN10DataStreamD1Ev  0x002d3655  36 bytes
OK  _ZN11Persistence8BlockIntD1Ev  0x003435e9  36 bytes
OK SECTION .preferences_get_orientation  0x00343834  176 bytes
OK SECTION .orientation_datastream_d1  0x002d3654  36 bytes
OK SECTION .orientation_blockint_d1  0x003435e8  36 bytes
```

The complete function SHA-256 is
`1ff542c6f961447b4c9163c07e93693b745416ca8da82bddaf29f8c95fe573f3`.
All existing owning-unit comparisons, including SampleAndSave, remain enabled.
The affected Preferences header/caller closure covers five configured profiles
including dependencies: 389 function, 245 section and five region comparisons
pass. This is ARM matching evidence; native Windows execution was not tested.

Earlier private placement-storage candidates remained eight bytes different.
An older exact experiment changed global destructor declarations; those changes
are unnecessary for this current natural-object match and are not included.
No controlled experiment identified a unique cause of the older-context
difference. LoadAndApply remains pending, so this does not complete the source
unit or increase Fully Linked progress.

Canonical full verification also passed: `python tools/build.py --all`,
190 profiles and 10,509 successful function/section/region comparisons, with
all prior checks retained. Independent executable audits cover all 4,227
credited functions / 334,746 bytes and all 1,634 Fully Linked entries /
108,614 bytes, with no missing proofs.
