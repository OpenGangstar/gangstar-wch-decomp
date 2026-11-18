# JNI sound count

The nativeGetTotalSounds JNI bridge returns the original constant 274.
Its first source candidate matches the complete six-byte Thumb function:

```text
OK  Java_com_gameloft_android_GAND_GloftGANG_GLMediaPlayer_nativeGetTotalSounds  0x002d1dd5  6 bytes
```

The JNI unit freshly compiles and links at original addresses. All 30 function
and 40 section/GOT comparisons pass, including every existing match. No other
matching profile consumes this object, and no shared header changes. Proof:
_scratch/jni-total-sounds-root.log. Existing JNI bodies and Windows sources are
unchanged; imported code and alignment padding receive no new credit.

The source uses the existing jint return type and JNI implicit parameters.
A positive constant alone cannot prove signedness or distinguish a positive
16-bit Java return descriptor. The 32-bit integer-count interpretation is
consistent with the bridge's existing sound identifiers and native return ABI;
the unavailable Java declaration is not claimed as recovered evidence.
