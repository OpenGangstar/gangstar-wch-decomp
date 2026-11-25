# AccelerometerBase::_calcAngles exact match

`AccelerometerBase::_calcAngles()` matches all 264 retail bytes at Thumb address
`0x0034d479`, and its strict section ends at the retail extent.

```text
OK  _ZN17AccelerometerBase11_calcAnglesEv  0x0034d479  264 bytes
OK SECTION .accelerometer_calc_angles  0x0034d478  264 bytes
```

## Source form

For each axis, the function saves the previous angle and then sets the new one:

- `±Float::HALF_PI` when the axis component is below `Float::EPSILON` in
  magnitude, with the sign taken from the previous angle;
- otherwise `atan2f` of the next component pair.

As in retail, the third axis saves `curX`, not `curZ`.

Earlier forms were 8 bytes short because they read `Float::EPSILON` once into a
named local. That swaps the two high registers: retail keeps EPSILON in `r7` and
the PIC base in `r8`, which needs a `mov` before each GOT access. Reading
`Float::EPSILON` directly in each comparison reproduces retail's allocation and
its `fcmplt`/`fcmpgt` call forms.

`Float::EPSILON` and `Float::HALF_PI` are the retail rodata globals at
`0x00413ae0` and `0x00413adc`. The three opaque 4-byte fields at +56/+64/+72 are
typed as the `float` current angles `curX`/`curY`/`curZ`. The layout is
unchanged.

The `atan2f` PLT entry `0x001c4718` is the retail call target.

No branch hint, inline assembly, register constraint or output edit is used.

## Verification

`python -B tools/build.py --all` exited 0 with 5,547 function, 5,629 section
and 181 region comparisons and no mismatch or skip. Unit tests, repository
checks and progress checks pass.
