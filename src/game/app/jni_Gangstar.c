/* Native browser bridge from the original jni_Gangstar.c translation unit. */
#include "NativeJNI.h"
#ifdef __cplusplus
extern "C" {
#endif
extern JNIEnv* mEnv;
static jclass mClassGLGangstar;
static jmethodID mMethodOpenBrowser;
void nativeOpenBrowser(const char* url)
{
    jstring name = (*mEnv)->NewStringUTF(mEnv, url);
    (*mEnv)->CallStaticVoidMethod(mEnv, mClassGLGangstar, mMethodOpenBrowser, name);
    (*mEnv)->DeleteLocalRef(mEnv, name);
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
static jmethodID mMethodNotifyPause;
void nativeNotifyPause(void)
{
    (*mEnv)->CallStaticVoidMethod(mEnv, mClassGLGangstar, mMethodNotifyPause);
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
static jmethodID mMethodExit;
void nativeExit(void)
{
    (*mEnv)->CallStaticVoidMethod(mEnv, mClassGLGangstar, mMethodExit);
}
#ifdef __cplusplus
}
#endif


#ifdef __cplusplus
extern "C" {
#endif
static jmethodID mMethoddetectPhoneLang;
jint nativedetectPhoneLang(void)
{
    return (*mEnv)->CallStaticIntMethod(mEnv, mClassGLGangstar, mMethoddetectPhoneLang);
}
#ifdef __cplusplus
}
#endif


#ifdef __cplusplus
extern "C" {
#endif
static jmethodID mUnlockDemoID;
void nativeUnlockDemo(void)
{
    (*mEnv)->CallStaticVoidMethod(mEnv, mClassGLGangstar, mUnlockDemoID);
}
#ifdef __cplusplus
}
#endif


#ifdef __cplusplus
extern "C" {
#endif
static jmethodID mGetVersionModeID;
jint nativeGetVersionMode(void)
{
    return (*mEnv)->CallStaticIntMethod(mEnv, mClassGLGangstar, mGetVersionModeID);
}
#ifdef __cplusplus
}
#endif


#ifdef __cplusplus
extern "C" {
#endif
static jmethodID mGetNumLaunchID;
jint nativeGetNumLaunch(void)
{
    return (*mEnv)->CallStaticIntMethod(mEnv, mClassGLGangstar, mGetNumLaunchID);
}
#ifdef __cplusplus
}
#endif


#ifdef __cplusplus
extern "C" {
#endif
static const char jniText_413238[] __attribute__((section(".rodata.jni_text_413238"))) = "notifyPaused";
static const char jniText_413248[] __attribute__((section(".rodata.jni_text_413248"))) = "()V";
static const char jniText_41324c[] __attribute__((section(".rodata.jni_text_41324c"))) = "openBrowser";
static const char jniText_413258[] __attribute__((section(".rodata.jni_text_413258"))) = "(Ljava/lang/String;)V";
static const char jniText_413270[] __attribute__((section(".rodata.jni_text_413270"))) = "Exit";
static const char jniText_413278[] __attribute__((section(".rodata.jni_text_413278"))) = "detectPhoneLang";
static const char jniText_413288[] __attribute__((section(".rodata.jni_text_413288"))) = "()I";
static const char jniText_41328c[] __attribute__((section(".rodata.jni_text_41328c"))) = "unlockDemo";
static const char jniText_413298[] __attribute__((section(".rodata.jni_text_413298"))) = "getVersionMode";
static const char jniText_4132a8[] __attribute__((section(".rodata.jni_text_4132a8"))) = "getNumLaunch";
void Java_com_gameloft_android_GAND_GloftGANG_Gangstar_nativeInit(JNIEnv* unusedEnv, jclass clazz)
{
    mClassGLGangstar = (*mEnv)->NewGlobalRef(mEnv, clazz);
    mMethodNotifyPause = (*mEnv)->GetStaticMethodID(mEnv, mClassGLGangstar, jniText_413238, jniText_413248);
    mMethodOpenBrowser = (*mEnv)->GetStaticMethodID(mEnv, mClassGLGangstar, jniText_41324c, jniText_413258);
    mMethodExit = (*mEnv)->GetStaticMethodID(mEnv, mClassGLGangstar, jniText_413270, jniText_413248);
    mMethoddetectPhoneLang = (*mEnv)->GetStaticMethodID(mEnv, mClassGLGangstar, jniText_413278, jniText_413288);
    mUnlockDemoID = (*mEnv)->GetStaticMethodID(mEnv, mClassGLGangstar, jniText_41328c, jniText_413248);
    mGetVersionModeID = (*mEnv)->GetStaticMethodID(mEnv, mClassGLGangstar, jniText_413298, jniText_413288);
    mGetNumLaunchID = (*mEnv)->GetStaticMethodID(mEnv, mClassGLGangstar, jniText_4132a8, jniText_413288);
}
#ifdef __cplusplus
}
#endif
