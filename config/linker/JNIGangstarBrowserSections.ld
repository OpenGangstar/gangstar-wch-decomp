/* Native browser definition and its original local JNI caches. */
SECTIONS
{
 .gangstar_browser 0x002d1868 : { *jni-gangstar.o(.text.nativeOpenBrowser) }
 .gangstar_class 0x004b65f8 (NOLOAD) : { *jni-gangstar.o(.bss.mClassGLGangstar) }
 .gangstar_browser_method 0x004b6600 (NOLOAD) : { *jni-gangstar.o(.bss.mMethodOpenBrowser) }
}
