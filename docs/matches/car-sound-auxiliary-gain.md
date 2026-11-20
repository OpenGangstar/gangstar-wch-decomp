# Auxiliary turbo gain declaration

CarSoundSettings byte 192 was declared as int turboValue192. Native code
copies those bits to the auxiliary turbo gain and consumes them as float.
Declare the existing field as float auxiliaryTurboGain, matching the
corresponding field in the already recovered TurboSoundSettings layout.
No function body or compiler configuration changes.

Three independent observations establish the type and offset:

- TurboSoundSettings is 72 bytes and its existing float auxiliaryTurboGain
  is at 68. Its settings tail begins at CarSoundSettings 124, yielding 192.
- CarSounds::Init loads settings 192 at 0x00350862 and stores the same bits
  to CarSounds 288 at 0x00350868. The sequence begins at 0x00350860:
  `c0 22 b2 58 90 23 5b 00 ea 50`.
- UpdateTurboSounds loads CarSounds 288 at 0x0034fd78, retains it in SL,
  then passes it in R1 to __aeabi_fmul at 0x0034fdc6. R0 holds masterVolume 20
  saved before the intervening isSoundPlaying callback. The relevant words
  were checked directly in retail bytes, not inferred from a masked match.

A raw LDR/STR pair alone would not distinguish int and float. The independent
floating-point consumer and matching settings-tail layout supply that evidence.
The owning Init and UpdateTurboSounds bodies remain unmatched.

Original GCC 4.2.1 before/after syntax and layout probes both exit 0. They verify:

| Property | Before and after |
| --- | ---: |
| CarSoundSettings size/alignment | 204/4 |
| Auxiliary gain offset | 192 |
| Filter flag/frequency offsets | 196/200 |
| TurboSoundSettings size | 72 |
| TurboSoundSettings auxiliary gain offset | 68 |
| Existing partial CarSounds size | 288 |

The gain pointer probe changes from int* to float* as intended. Both runs
produce the same eight known offsetof warnings from the old compiler. No
CarSounds tail field is added; this correction does not pretend its partial
class model already includes native byte 288.

The coordinator then runs the full current-root native preservation gate:
190 profiles, 5434 functions, 5338 sections and 181 regions; all 10953 comparisons
exact, exit 0. All 1044 frozen source/configuration/tool/nonmatching inputs
remain stable. Existing function bodies, sections and genuine thunks retain
their complete original bytes.

Related private AddTurboSounds work separately tests settings 28 and
CarSounds 240 as floats. Its one corrected 468-byte object is byte-identical to
the old object, including all 15 semantic relocations, and fails strict native
464-byte placement before a real SoundFade::Clean neighbor. Those extra
private views and unmatched source are not integrated by this declaration fix.

No assembly marker, catalogue status, data measure, Windows implementation or
matched-function total changes. Matched/Fuzzy remain 61.31%; Fully Linked
remains 20.01%. All 17703 original function identities stay accounted for.
