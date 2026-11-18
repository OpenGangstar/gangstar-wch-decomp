# Android and application wrappers

The following functions are reconstructed from their complete native ARM code:

```text
OK  appResume  0x002d24f5  24 bytes
OK  launchTwitter  0x002d2715  28 bytes
OK  Java_com_gameloft_android_GAND_GloftGANG_GameRenderer_nativeDone  0x002d1415  12 bytes
OK  Java_com_gameloft_android_GAND_GloftGANG_Gangstar_nativeOnKeyUp  0x002d134d  14 bytes
OK  Java_com_gameloft_android_GAND_GloftGANG_Gangstar_nativeOnKeyDown  0x002d135d  14 bytes
```

Each first source candidate matches. appResume stores one in the genuine native
signed m_timerForResume counter; native appRun performs the deferred resume.
It does not directly call Application::Resume. launchTwitter passes the original
complete URL string to the native browser bridge. The URL object is 75 bytes;
its 76-byte aligned linked section is compared in full. No URL is opened during
verification. nativeDone calls the existing native appDeinit with no arguments.
Its unused JNI reference may represent a class or instance; that distinction is
unobservable in this body and does not change the pointer ABI.

Existing wrapper startup, path helper, JNI sound and MenuState caller functions
remain unchanged. The generated native-address verification images use genuine
Thumb bindings for imported callees; imported code/data receive no matching
credit. No compiler output edits, inline assembly, likelihood hints or invented
support bodies are used. The Windows port is unchanged.

The two JNI key bridges forward the unchanged signed integer key argument to
the native appOnKeyUp/appOnKeyDown wrappers. Shared jint is declared once.
All eight wrapper verification images (own profile plus seven direct consumers)
retain both reconstructed wrappers and the complete URL at original addresses.
Their manifests independently compare both executable definitions and URL bytes,
using a common linker placement include and native browser Thumb import.

Coordinator full `python tools/build.py --all` passed all 181 profiles and
9,834 function/section/GOT comparisons, exit zero. Full proof logs:
_scratch/android-wrapper-root-final.log and .exit.
