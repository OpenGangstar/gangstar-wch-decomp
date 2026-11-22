# CarSounds::AddTurboSounds

`CarSounds::AddTurboSounds(TurboSoundSettings*)` at Thumb address `0x00350019`
matches all 464 retail bytes. Its complete linked section is also exact.

The preserved candidate used integer views for a settings gain and its receiver
field. Native code copies settings offset 28 into receiver offset 240; the turbo
update routine passes that value to floating-point multiplication. Both views
are now float, preserving a direct copy without an integer-to-float conversion.
The auxiliary gain at receiver offset 288 likewise follows the native copy and
float-use evidence. The observed CarSounds prefix therefore extends to 292
bytes; existing member offsets remain unchanged. TurboSoundSettings remains 72
bytes, with its existing pointer/gain tail at offsets 60, 64 and 68 preserved.

A private complete-source control exposed the match. Canonical integration adds
only AddTurboSounds and the fields/declaration it requires. The other four
pending CarSounds methods remain unmatched and outside canonical source. All
previously accepted function bodies remain unchanged. No compiler-output edits,
assembly, register constraints, new likelihood hints or optimizer flags were used.

The existing car-sound-callbacks verification profile places the new section at
`0x00350018`, asserts its 464-byte extent, and checks both the function and full
section. The canonical rebuild prints:

```text
OK  _ZN9CarSounds14AddTurboSoundsEP18TurboSoundSettings  0x00350019  464 bytes
OK SECTION .car_sounds_add_turbo  0x00350018  464 bytes
```

The coordinator rebuilt all 191 ARM profiles after integration, including Vehicle
and other header consumers: 5,446 function, 5,355 section and 181 region checks
passed, totaling 10,982 exact comparisons. All 1,078 frozen source/configuration
inputs remained unchanged throughout that run. A separate catalogue audit found
direct successful comparisons for all 4,284 matched game functions, with no gaps.

Progress increases by one function and 464 bytes to 350,018/561,716 bytes
(62.31%). The CarSounds unit is still incomplete, so Fully Linked remains
114,548 bytes (20.39%). No approximate matching credit is added.
