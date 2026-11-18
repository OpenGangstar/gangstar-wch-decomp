/* Native browser definition and its original local JNI caches. */
SECTIONS
{
 .gangstar_init 0x002d16f4 : { *jni-gangstar.o(.text.Java_com_gameloft_android_GAND_GloftGANG_Gangstar_nativeInit) }
 .jni_text_413238 0x00413238 : { *jni-gangstar.o(.rodata.jni_text_413238) }
 .jni_text_413248 0x00413248 : { *jni-gangstar.o(.rodata.jni_text_413248) }
 .jni_text_41324c 0x0041324c : { *jni-gangstar.o(.rodata.jni_text_41324c) }
 .jni_text_413258 0x00413258 : { *jni-gangstar.o(.rodata.jni_text_413258) }
 .jni_text_413270 0x00413270 : { *jni-gangstar.o(.rodata.jni_text_413270) }
 .jni_text_413278 0x00413278 : { *jni-gangstar.o(.rodata.jni_text_413278) }
 .jni_text_413288 0x00413288 : { *jni-gangstar.o(.rodata.jni_text_413288) }
 .jni_text_41328c 0x0041328c : { *jni-gangstar.o(.rodata.jni_text_41328c) }
 .jni_text_413298 0x00413298 : { *jni-gangstar.o(.rodata.jni_text_413298) }
 .jni_text_4132a8 0x004132a8 : { *jni-gangstar.o(.rodata.jni_text_4132a8) }
 .gangstar_launch 0x002d1994 : { *jni-gangstar.o(.text.nativeGetNumLaunch) }
 .gangstar_launch_method 0x004b6614 (NOLOAD) : { *jni-gangstar.o(.bss.mGetNumLaunchID) }
 .gangstar_notify 0x002d1834 : { *jni-gangstar.o(.text.nativeNotifyPause) }
 .gangstar_notify_method 0x004b65fc (NOLOAD) : { *jni-gangstar.o(.bss.mMethodNotifyPause) }
 .gangstar_exit 0x002d18c4 : { *jni-gangstar.o(.text.nativeExit) }
 .gangstar_exit_method 0x004b6604 (NOLOAD) : { *jni-gangstar.o(.bss.mMethodExit) }
 .gangstar_phone 0x002d18f8 : { *jni-gangstar.o(.text.nativedetectPhoneLang) }
 .gangstar_phone_method 0x004b6608 (NOLOAD) : { *jni-gangstar.o(.bss.mMethoddetectPhoneLang) }
 .gangstar_unlock 0x002d192c : { *jni-gangstar.o(.text.nativeUnlockDemo) }
 .gangstar_unlock_method 0x004b660c (NOLOAD) : { *jni-gangstar.o(.bss.mUnlockDemoID) }
 .gangstar_version 0x002d1960 : { *jni-gangstar.o(.text.nativeGetVersionMode) }
 .gangstar_version_method 0x004b6610 (NOLOAD) : { *jni-gangstar.o(.bss.mGetVersionModeID) }
 .gangstar_browser 0x002d1868 : { *jni-gangstar.o(.text.nativeOpenBrowser) }
 .gangstar_class 0x004b65f8 (NOLOAD) : { *jni-gangstar.o(.bss.mClassGLGangstar) }
 .gangstar_browser_method 0x004b6600 (NOLOAD) : { *jni-gangstar.o(.bss.mMethodOpenBrowser) }
}
