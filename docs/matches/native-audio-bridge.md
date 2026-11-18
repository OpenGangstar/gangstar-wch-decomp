# Native JNI audio bridge

The original jni_GLMediaPlayer.c translation unit forwards sound operations to
the Java GLMediaPlayer class. Each reconstructed wrapper preserves its cached
class reference, named static method-ID storage, argument order, and JNI table
slot. The JNI declaration is an observed prefix, not a complete JNI interface.
The original NDK table confirms CallStaticIntMethod at slot 129 and
CallStaticVoidMethod at slot 141. Every combined comparison also checks the
complete 17,972-byte global GOT region after its existing 864-byte prefix.

The Java method lookup strings and descriptors in the original nativeInit
establish the wrapper ABIs. Pause, resume, stop, unload and load use (II)V;
their Big variants and reset use (I)V; pauseAllSounds uses ()V. The loaded
queries use (II)I and (I)I, so they return jint without boolean normalization.
The original names and retail addresses of all static method-ID variables are
preserved for future initializer integration. Each storage section has a
four-byte linker extent assertion. No Java initialization behavior or sibling
function receives matching credit merely because its descriptor was analyzed.

The initializer preserves NewGlobalRef at slot 21 followed by the original 28
GetStaticMethodID calls at slot 113, in their original order. It uses the shared
mEnv, stores the incoming class global reference, and does not invent an env
assignment or additional checks. All 39 name/descriptor sections compare fully.
Movie loading uses NewStringUTF at slot 167 and DeleteLocalRef at slot 23.
Video queries use CallStaticBooleanMethod at slot 117 and return jboolean.
Play/volume arguments retain natural float-to-double and bool-to-int promotions.

SetVolume and SetPitch initially differed in scheduling. Their unchanged plain
bodies match in the completed initializer/canonical-ID context. A bounded replay
proved both without hints, function reordering, or compiler-output changes.
The C frontend diagnostic produced the same former mismatch, so no tooling
frontend change was made. Existing wrappers remained exact throughout.

The integrated command `python tools/build.py jni-glmedia-player` exited 0.
The final full regression command also exited 0. Exact JNI comparison output:

```text
OK  nativePauseSound  0x002d1f31  60 bytes
OK  nativeResumeSound  0x002d1fd5  60 bytes
OK  nativeStopSound  0x002d2045  60 bytes
OK  nativeUnloadSound  0x002d20b5  60 bytes
OK  nativeIsSoundLoaded  0x002d2125  60 bytes
OK  nativeLoadSound  0x002d1ded  60 bytes
OK  nativePauseSoundBig  0x002d1f6d  52 bytes
OK  nativePauseAllSounds  0x002d1fa1  52 bytes
OK  nativeResumeSoundBig  0x002d2011  52 bytes
OK  nativeStopSoundBig  0x002d2081  52 bytes
OK  nativeUnloadSoundBig  0x002d20f1  52 bytes
OK  nativeIsSoundLoadedBig  0x002d2161  52 bytes
OK  nativeLoadSoundBig  0x002d1e29  52 bytes
OK  nativeResetSound  0x002d225d  52 bytes
OK  nativeSetVolumeBig  0x002d21fd  96 bytes
OK  Java_com_gameloft_android_GAND_GloftGANG_GLMediaPlayer_nativeInit  0x002d19c9  1036 bytes
OK  nativeStopAllSounds  0x002d22f9  52 bytes
OK  nativeUnloadAllSounds  0x002d232d  52 bytes
OK  nativeStopAllSoundPool  0x002d2361  52 bytes
OK  nativeStopAllBigSound  0x002d2395  52 bytes
OK  nativeDestroySoundPool  0x002d23c9  52 bytes
OK  nativeInitSoundPoolArray  0x002d23fd  52 bytes
OK  nativeLoadMovie  0x002d2431  92 bytes
OK  nativeIsMediaPlaying  0x002d248d  52 bytes
OK  nativeIsVideoPlayDone  0x002d24c1  52 bytes
OK  nativePlaySoundBig  0x002d1ec5  108 bytes
OK  nativePlaySound  0x002d1e5d  104 bytes
OK  nativeSetVolume  0x002d2195  104 bytes
OK  nativeSetPitch  0x002d2291  104 bytes
OK REGION .got+0x360  0x004b03a8  17972 bytes
OK SECTION .jni_text_4132b8  0x004132b8  16 bytes
OK SECTION .jni_text_4132c8  0x004132c8  8 bytes
OK SECTION .jni_text_4132d0  0x004132d0  20 bytes
OK SECTION .jni_text_4132e4  0x004132e4  8 bytes
OK SECTION .jni_text_4132ec  0x004132ec  12 bytes
OK SECTION .jni_text_4132f8  0x004132f8  8 bytes
OK SECTION .jni_text_413300  0x00413300  16 bytes
OK SECTION .jni_text_413310  0x00413310  8 bytes
OK SECTION .jni_text_413318  0x00413318  12 bytes
OK SECTION .jni_text_413324  0x00413324  16 bytes
OK SECTION .jni_text_413334  0x00413334  12 bytes
OK SECTION .jni_text_413340  0x00413340  8 bytes
OK SECTION .jni_text_413348  0x00413348  16 bytes
OK SECTION .jni_text_413358  0x00413358  8 bytes
OK SECTION .jni_text_413360  0x00413360  12 bytes
OK SECTION .jni_text_41336c  0x0041336c  16 bytes
OK SECTION .jni_text_41337c  0x0041337c  16 bytes
OK SECTION .jni_text_413248  0x00413248  4 bytes
OK SECTION .jni_text_41338c  0x0041338c  12 bytes
OK SECTION .jni_text_413398  0x00413398  16 bytes
OK SECTION .jni_text_4133a8  0x004133a8  12 bytes
OK SECTION .jni_text_4133b4  0x004133b4  16 bytes
OK SECTION .jni_text_4133c4  0x004133c4  12 bytes
OK SECTION .jni_text_4133d0  0x004133d0  16 bytes
OK SECTION .jni_text_4133e0  0x004133e0  8 bytes
OK SECTION .jni_text_4133e8  0x004133e8  12 bytes
OK SECTION .jni_text_4133f4  0x004133f4  12 bytes
OK SECTION .jni_text_413400  0x00413400  16 bytes
OK SECTION .jni_text_413410  0x00413410  16 bytes
OK SECTION .jni_text_413420  0x00413420  12 bytes
OK SECTION .jni_text_41342c  0x0041342c  12 bytes
OK SECTION .jni_text_413438  0x00413438  20 bytes
OK SECTION .jni_text_41344c  0x0041344c  20 bytes
OK SECTION .jni_text_413460  0x00413460  12 bytes
OK SECTION .jni_text_413258  0x00413258  24 bytes
OK SECTION .jni_text_41346c  0x0041346c  16 bytes
OK SECTION .jni_text_41347c  0x0041347c  8 bytes
OK SECTION .jni_text_413484  0x00413484  16 bytes
OK SECTION .jni_text_413494  0x00413494  4 bytes
```

The final `python tools/build.py --all` run exited 0 with 9,662 retail comparisons.
