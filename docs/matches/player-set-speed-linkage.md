# PlayerTest::SetSpeed: native weak linkage

The retail `_ZN10PlayerTest8SetSpeedEv` is a weak/default ARM ELF function at
Thumb `0x00301f69`, with a 48-byte body. The previous reconstruction emitted
the correct bytes with global/default binding. The declaration now carries
`__attribute__((weak))`, preserving the actual compiled definition and its
original body while restoring the native binding.

This matters to callers in the same translation unit: the pending
`PlayerTest::Update()` calls this weak function through the GOT in retail.
The previous global declaration allowed a direct Thumb call. Correcting the
binding produces an actual `R_ARM_GOT32` reference in the private Update
replay; it does not substitute an absolute retail address for compiled code.

## Verification

The integrated declaration-only change passed `python tools/build.py --all`
with the original per-profile toolchain selection: 190 profiles, 5,304 function
comparisons, 5,202 section comparisons and 181 region comparisons. There were
no failed or skipped profiles. No C++ implementation or compiler flag changed.

The comparison tool printed:

```text
OK  _ZN10PlayerTest8SetSpeedEv  0x00301f69  48 bytes
```

Independent extraction from the integrated executable confirms weak/default
function binding, extent 48, and complete equality with the retail function.
Both bodies have SHA256
`d661e6cadd11ec8c2b5d396bc6537216828342b6c21608cc2eba630f7354ddb8`.

No new function is credited. Matched, fuzzy and fully linked totals remain
unchanged. Update remains pending: its separate unchanged-source replay with
the corrected binding emits 2,200 bytes versus native 2,228 and stops before
linking. See the baseline candidate in
[PlayerTest-Update.md](../../nonmatching/ai/PlayerTest-Update.md).
