# Native browser bridge

The first source candidate matches the complete 92-byte browser bridge:

```text
OK  nativeOpenBrowser  0x002d1869  92 bytes
```

It reuses the existing nativeLoadMovie JNI algorithm: create a local Java string,
call the cached static method, then delete that local reference. Native
initialization code identifies openBrowser with descriptor (Ljava/lang/String;)V
and the actual cached class/method stores. No exception checks, null guards,
string changes or Java/browser execution are introduced during verification.

The existing Media JNI declaration prefix is extracted verbatim into NativeJNI.h.
Aliases, fields, slots and comments are unchanged; this remains an observed
prefix rather than a complete JNI table. All 31 current Media functions and 40
regions compare after extraction. No existing function body changes.

The native class and browser-method caches are genuine four-byte LOCAL NOBITS
objects at 0x004b65f8 and 0x004b6600. Size assertions and independent final-ELF
audits prove both objects in all nine linked images. mEnv remains imported.
Only the owned browser body is reconstructed in the new JNI source/profile;
other original functions remain pending.

The wrapper profile and seven consumers now link the compiled browser object,
retain its code/caches through a shared linker include, and explicitly compare
the actual executable definition. The previous native import cannot override
compiled code. Existing launchTwitter and wrapper bytes remain exact. No helper,
vtable, engine body, data progress or compiler-output edits receive credit.

Coordinator graph: 21 profiles, 1,939 passing function/section/GOT comparisons.
Proof: _scratch/browser-root.log and .exit. Windows sources/build configuration
are unchanged. Only the original 92-byte game function is newly credited.

The later complete-unit integration expands this original nine-image proof to
twelve images and adds the seven individually verified original JNI functions.
See [the complete JNI unit](jni-gangstar-complete.md) for current coverage.
