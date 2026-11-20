# PVRTC helper source reuse

Five additional functions from `PVRTDecompress.cpp` are reconstructed using the
legacy PVRTC source retained in cocos2d-x commit
[e4b6a5ef8fcdc99a7ebea606312b67fe4c534b9f](https://github.com/cocos2d/cocos2d-x/blob/e4b6a5ef8fcdc99a7ebea606312b67fe4c534b9f/cocos/base/pvr.cpp).
The source retains Imagination Technologies Limited's 2000Ã¢â‚¬â€œ2008 copyright
notice. The exact revision incorporated into the retail game remains unknown;
this is source reuse supported by complete native byte comparisons, not a
provenance reclassification. All original catalogue identities remain present.

## Reconstructed functions

`util_number_is_power_2(unsigned int)` at `0x0020c469` uses the original
zero check and OR/XOR predicate. Its 28-byte function and entire 28-byte section
match on the first source trial. Raw, linked and native SHA256:
`fc17be2f911f60ad78ade7b35862b347966235f9ceee23eba0ff8530d6720039`.

`TwiddleUV(unsigned long,unsigned long,unsigned long,unsigned long)` at
`0x0020c6ed` preserves the legacy Y-size/X-size/Y-position/X-position argument
order, explicit minimum-dimension branches, interleaving loop and remaining-bit
shift. The 78-byte function and full 80-byte section, including the native
assembler alignment tail, match. Raw, linked and native function SHA256:
`fd5c85ff193bea159874de34e5b77651923a7e763231de42f91f663497a7da8e`.
The source uses the retail unsigned-long signature rather than the later
reference's uint32_t typedef. Assertion-only checks and the reference's disabled
debug twiddling override have no counterpart in the native function and are not
introduced. No branch hints or compiler-flag changes are required.

The TwiddleUV investigation used six compiles: two 82-byte source forms, two
valid 78-byte forms with commuted comparison operands, one accidental
unsigned-int third-parameter form that was discarded, and the matching explicit
legacy branch form. The accidental form emitted the wrong mangled name and is
not target evidence. Only two valid compared source forms had identical bytes;
the three-identical valid-form stop was not reached. Initial failed-link output
was observed in the tool transcript; subsequent actual logs and all six objects
were retained privately. No compiler output was edited.

`InterpolateColours(int const*,int const*,int const*,int const*,int,int,int,int*)`
at `0x0020c485` matches its 310-byte function and complete 312-byte section,
including the native `c046` alignment tail, on the first source trial. It reuses
the legacy integer interpolation with original numeric block dimensions;
assertion-only checks are omitted as in the native release build. Its `void`
return view follows the reference and is inferred, since this mangled name does
not encode the original return spelling. Native/raw/linked function SHA256:
`74152a055cb12e408148a7bdc4f30d960d89f559e64df0adb9b74a44b4b0fd0e`.

`GetModulationValue(int,int,int,int const (*)[16],int const (*)[16],int*,int*)`
at `0x0020c5bd` matches its complete 304-byte function and section on the first
source trial. Its integer mode parameter already agrees with the reference and
retail symbol. Original local tables `RepVals0={0,3,5,8}` and
`RepVals1={0,4,4,8}` each match all 16 bytes at `0x00409b2c` and `0x00409b1c`.
The normal PIC GOT base is preserved at `0x004b0048`. Linked/native SHA256:
`3f4e14ae88f8a1a750663bf245a3d141e668e35ddc0d1d8fb5521c9d9beff9c6`.

## Native comparison

Using the existing ARM GCC 4.2.1 profile, `python tools/build.py pvrt-decompress`
prints:

```text
BUILD pvrt-decompress
OK  _Z22util_number_is_power_2j  0x0020c469  28 bytes
OK  _Z18InterpolateColoursPKiS0_S0_S0_iiiPi  0x0020c485  310 bytes
OK  _Z18GetModulationValueiiiPA16_KiS1_PiS2_  0x0020c5bd  304 bytes
OK  _Z9TwiddleUVmmmm  0x0020c6ed  78 bytes
OK  _Z15PVRTCDecompressPKviiiPh  0x0020ccd5  20 bytes
OK  _Z10DecompressP17AMTC_BLOCK_STRUCTiiiiPh  0x0020c73d  1432 bytes
OK SECTION .pvrtc_power_two  0x0020c468  28 bytes
OK SECTION .pvrtc_interpolate  0x0020c484  312 bytes
OK SECTION .pvrtc_modulation  0x0020c5bc  304 bytes
OK SECTION .pvrtc_rep0  0x00409b2c  16 bytes
OK SECTION .pvrtc_rep1  0x00409b1c  16 bytes
OK SECTION .pvrtc_twiddle  0x0020c6ec  80 bytes
OK SECTION .pvrtc_wrapper  0x0020ccd4  20 bytes
OK SECTION .pvrtc_decoder  0x0020c73c  1432 bytes
OK SECTION .pvrtc_previous_init  0x00409b0c  16 bytes
```

The existing wrapper remains byte-identical. Linker assertions preserve each
new function's original boundaries; adjacent pending decoder helpers remain
native and are not claimed as compiled neighbors. Verification images add only
the assigned definitions, with no synthetic helper, instruction padding,
assembly, register binding or postprocessing.

## Progress scope

The five new functions add 2,152 matched bytes. Together with the previously
matched 20-byte adapter, they complete all six functions and all 2,172 code bytes
in this original source unit. Fully Linked gains exactly 2,172 bytes and one
complete unit; no incomplete source fragment receives completion credit.
No existing decompiled function body, Windows implementation or launcher is
modified.

## Completing the decoder

`Decompress(AMTC_BLOCK_STRUCT*,int,int,int,int,unsigned char*)` at
`0x0020c73d` matches its complete 1,432-byte function and section. Linked/native
SHA256: `3a2bbf82e87e123633102dbd071bd0e23a64d73018375e5f1ccd48ecc7c38600`.
The native eight-byte packed block, integer mode, signed division, helper calls,
1,444-byte frame and 16-byte compiler-emitted initializer at `0x00409b0c` are
preserved. Two original static unpacking helpers inline naturally; no synthetic
out-of-line implementation or force-inline attribute is introduced.

Four source trials were used. Initial source reuse emitted the correct size but
105 differing bytes. Changing the shared U32 view to unsigned long, based on the
retail TwiddleUV signature, left the same bytes. Restoring native value-first
outer MIN tie selection reduced the difference to 31 stack-offset bytes. The
fourth trial reused all accepted helper definitions unchanged and restored
complete original source-unit order; every byte then matched. This proves the
combined definition/context change mattered, not that ordering alone was
isolated as the cause. Compiler flags and the owned decoder body remained
unchanged between trials three and four.

Historical link failures from initializer-section names and old GNU ld assignment
syntax were fixed only in link metadata, then the same frozen objects were
relinked. No compiler output was edited. The two initializer names changed
naturally as source-unit context changed; the emitted 16-byte payload matches
native data in both cases. The final profile checks all six actual executable
functions and all nine sections, including the three original data payloads.

The final combined integration gate, also covering SoundManager construction,
passes all 191 profiles: 5,443 functions, 5,353 sections and 181 regions,
totaling 10,977 exact comparisons, exit 0. All 1,072 frozen inputs remain stable.
Only the five verified PVRTC markers and two constructor alias markers are
removed across the complete batch; official tables are regenerated.

The complete batch reports 349,298/561,716 matched bytes (62.18%), 4,281/4,550
functions. Fully Linked is 114,548/561,716 bytes (20.39%), 126/203 units. No
provenance, original identity or denominator changes occur.
