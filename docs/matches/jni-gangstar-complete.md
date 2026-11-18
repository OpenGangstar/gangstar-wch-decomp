# Gangstar JNI compilation unit

All eight original functions from jni_Gangstar.c are reconstructed and matched:
the earlier 92-byte browser bridge and these seven functions (632 bytes):

```text
OK  nativeNotifyPause  0x002d1835  52 bytes
OK  nativeExit  0x002d18c5  52 bytes
OK  nativedetectPhoneLang  0x002d18f9  52 bytes
OK  nativeUnlockDemo  0x002d192d  52 bytes
OK  nativeGetVersionMode  0x002d1961  52 bytes
OK  nativeGetNumLaunch  0x002d1995  52 bytes
OK  Java_com_gameloft_android_GAND_GloftGANG_Gangstar_nativeInit  0x002d16f5  320 bytes
```

The complete original function budget is 724 bytes. Method initialization uses
the existing global mEnv, ignores the incoming environment argument exactly as
the native code does, creates the class global reference and caches seven static
methods in native order. No extra environment assignment, validation or cleanup
is invented. Actual Java names/descriptors are recovered from the native lookup
literals: notifyPaused()V, openBrowser(String)V, Exit()V, detectPhoneLang()I,
unlockDemo()V, getVersionMode()I and getNumLaunch()I. Integer callbacks return the
JNI value unchanged; void callbacks add no behavior.

The class and seven method caches are genuine four-byte LOCAL NOBITS objects at
0x004b65f8 through 0x004b6614. All eight addresses, extents, bindings and section
types are independently verified in all twelve images, with linker size guards.
The ten complete initializer literals and full used GOT region also compare.
Only eight executable definitions are emitted; no helper/engine implementation
or compiler-output edit is introduced. No Java method is executed for testing.

Application and menu callers now link the actual compiled callback object,
including GSFade's Application dependency. Existing eight wrapper images retain
the same compiled JNI definitions. All consumers explicitly compare these
functions/literals and remove obsolete imports that could replace compiled code.
Current Media's 31 functions/40 regions remain exact, with unchanged JNI types.

Coordinator graph: 29 profiles, 3,747 passing function/section/GOT comparisons,
exit zero. Proof: _scratch/jni-gangstar-complete-root.log and .exit. All game
functions attributed to this original source are complete; progress is derived
from real comparisons and generated catalogue updates, never completion flags
entered by hand. ByteMatch publication still requires merging/report ingestion.
Windows source and build configuration are unchanged.
