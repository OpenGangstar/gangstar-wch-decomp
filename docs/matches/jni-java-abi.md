# JNI bridges recovered from the associated Java ABI

The associated APK contains the exact target `libsanangeles.so` and a checksum-valid
175,508-byte DEX. The DEX SHA-256 is
`72214c50a441e687f83977f22d52a8b0b38a38473c30e5fad92af553bee25f08`.
Its signed-manifest digests and CMS signature verify. The signing certificate's
identity is not independently established; no Gameloft-authorship claim is made.
The launcher copies this APK byte for byte rather than rewriting its Java code.
APK, DEX, signing files and native game data remain private and uncommitted.

All three methods have DEX access flags `0x10a`: private, static and native.

| Method | DEX descriptor | Native reconstruction |
| --- | --- | --- |
| GLMediaPlayer.nativeSetStopOnMusic | `(I)V` | Empty `void(JNIEnv*, jclass, jint)` bridge |
| Gangstar.nativeCanInterrupt | `()I` | Return incoming environment-pointer bits as the observed 32-bit integer result |
| GameRenderer.nativeGetJNIEnv | `()V` | Store the incoming environment pointer in the existing `mEnv` global |

`nativeCanInterrupt` is not a void no-op: Java `Gangstar.pause()` consumes its
integer result with `move-result` and `if-nez`. The retail `bx lr` leaves incoming
`r0` unchanged. The explicit pointer-to-integer conversion preserves that observed
result under the 32-bit ABI, with compile-time width checks. It avoids inventing
a Boolean constant or leaving a C return value undefined. Whether the original
author intentionally returned those bits or omitted a return remains unknown.

The environment cache imports the genuine existing `mEnv` symbol at `0x004b65f0`;
it does not create duplicate storage. Only the game JNI wrapper is reconstructed
in `CIrrDevicePS3.cpp`, not an Irrlicht engine implementation. Existing JNI headers
and decompiled function bodies are unchanged.

Coordinator comparison output:

```
OK  Java_com_gameloft_android_GAND_GloftGANG_GLMediaPlayer_nativeSetStopOnMusic  0x002d1de1  2 bytes
OK  Java_com_gameloft_android_GAND_GloftGANG_Gangstar_nativeCanInterrupt  0x002d1349  2 bytes
OK  Java_com_gameloft_android_GAND_GloftGANG_GameRenderer_nativeGetJNIEnv  0x002d1335  20 bytes
```

`python tools/build.py jni-glmedia-player app-android jni-cache-environment`
passes all target, existing function, section and GOT comparisons. A fresh
`python tools/build.py --all` passes 183 profiles and 10,265 comparisons with
exit zero. Evidence is retained in `_scratch/jni-abi-integrated.log` and
`_scratch/jni-abi-integrated-full.log` / `.exit`; private worker packages retain
the independent DEX parsers, provenance and executable-definition audits.

Matched progress is 4,209/4,661 functions and 332,842/575,264 bytes (57.86%).
Completing the game-code source groups for `app-android.c` and `CIrrDevicePS3.cpp`
raises Fully Linked to 104,088/575,264 bytes (18.09%), across 120/208 report units.
This does not claim complete engine or data reconstruction. The two C exports
`GetNativeSoundRaw` and `GetNativeResourceSoundRawLength` remain pending: their
signatures were not established by the DEX or native reference audit.
