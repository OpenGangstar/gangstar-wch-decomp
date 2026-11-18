/*
 * app-android.c: native renderer shutdown bridge.
 * JNI parameters are unused. The second reference may denote the class or
 * an instance; its native representation is identical and not inspected here.
 */
struct JNINativeInterface;
typedef const struct JNINativeInterface* JNIEnv;
typedef void* jobject;
#ifdef __cplusplus
extern "C" {
#endif
void appDeinit(void);
void Java_com_gameloft_android_GAND_GloftGANG_GameRenderer_nativeDone(
    JNIEnv* unusedEnv, jobject unusedReceiver)
{
    appDeinit();
}
#ifdef __cplusplus
}
#endif


typedef int jint;
#ifdef __cplusplus
extern "C" {
#endif
void appOnKeyUp(int key);
void Java_com_gameloft_android_GAND_GloftGANG_Gangstar_nativeOnKeyUp(
    JNIEnv* unusedEnv, jobject unusedReceiver, jint key)
{
    appOnKeyUp(key);
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void appOnKeyDown(int key);
void Java_com_gameloft_android_GAND_GloftGANG_Gangstar_nativeOnKeyDown(
    JNIEnv* unusedEnv, jobject unusedReceiver, jint key)
{
    appOnKeyDown(key);
}
#ifdef __cplusplus
}
#endif
