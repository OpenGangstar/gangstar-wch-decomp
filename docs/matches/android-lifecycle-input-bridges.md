# Android lifecycle and input bridges

Seven additive JNI functions match all 284 native bytes. Their combined source
preserves every existing shutdown/key bridge and the complete used GOT region:

```text
OK  Java_com_gameloft_android_GAND_GloftGANG_GameRenderer_nativeDone  0x002d1415  12 bytes
OK  Java_com_gameloft_android_GAND_GloftGANG_Gangstar_nativeOnKeyUp  0x002d134d  14 bytes
OK  Java_com_gameloft_android_GAND_GloftGANG_Gangstar_nativeOnKeyDown  0x002d135d  14 bytes
OK  Java_com_gameloft_android_GAND_GloftGANG_Gangstar_nativeAccelerometer  0x002d136d  52 bytes
OK  Java_com_gameloft_android_GAND_GloftGANG_GameGLSurfaceView_nativeOnTouch  0x002d13a1  20 bytes
OK  Java_com_gameloft_android_GAND_GloftGANG_GameRenderer_nativeRender  0x002d13b5  36 bytes
OK  Java_com_gameloft_android_GAND_GloftGANG_GameGLSurfaceView_nativeResume  0x002d13d9  28 bytes
OK  Java_com_gameloft_android_GAND_GloftGANG_GameGLSurfaceView_nativePause  0x002d13f5  32 bytes
OK  Java_com_gameloft_android_GAND_GloftGANG_GameRenderer_nativeResize  0x002d1421  44 bytes
OK  Java_com_gameloft_android_GAND_GloftGANG_GameRenderer_nativeInit  0x002d144d  72 bytes
OK REGION .got+0x360  0x004b03a8  17972 bytes
OK REGION .got+0x360  0x004b03a8  17972 bytes
OK REGION .got+0x360  0x004b03a8  17972 bytes
OK REGION .got+0x360  0x004b03a8  17972 bytes
```

Pause clears the native integer resume flag before appPause. Resume calls
appResume before setting the flag. Render calls appRun only when that flag is
nonzero. Touch forwards all four unchanged integer arguments. Accelerometer
stores the three float inputs in X/Y/Z order before its native wrapper call.
Resize stores width/height before glViewport(0,0,width,height), using its real ARM
PLT. Initialization preserves the existing-alive reload path and the initial
width/height, appInit and alive-flag sequence. appInit remains a native import;
its unintegrated candidate receives no credit.

One ordinary declaration supplies each shared imported global. Existing JNI
types and C linkage are reused; no full Java descriptor or class-versus-instance
meaning is claimed for unused receiver arguments. Native argument movement,
float stores, callee signatures and exported object widths support the types.
No new storage, engine implementation or compiler-output manipulation is used.

The original three functions needed no global PIC loads. The added bridges use
the repository's standard retail GOT placement at 0x004b0048 with the verified
0x360-offset region, plus the existing GOT primer at 0x00600000. Shared setup is
merged once. Real Thumb metadata is retained for native wrappers; glViewport
uses its actual ARM entry. The entire 17,972-byte used GOT region compares.

Coordinator graph: 5 profiles, 161 passing function/section/GOT comparisons,
including the current wrapper unit, Application, accelerometer base and logging
support. Proof: _scratch/android-bridges-root.log and .exit. No other matching
profile consumes this JNI object and no shared header changed. Existing matched
bodies and native Windows sources are unchanged. nativeCanInterrupt remains
pending; this translation unit is not marked complete merely for these matches.
