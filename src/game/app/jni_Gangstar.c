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
