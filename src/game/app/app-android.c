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

typedef float jfloat;
#ifdef __cplusplus
extern "C" {
#endif
extern float m_AccX, m_AccY, m_AccZ;
void appOnAccelerometer(void);
void Java_com_gameloft_android_GAND_GloftGANG_Gangstar_nativeAccelerometer(
    JNIEnv* unusedEnv, jobject unusedReceiver, jfloat x, jfloat y, jfloat z)
{
    m_AccX = x;
    m_AccY = y;
    m_AccZ = z;
    appOnAccelerometer();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void appOnTouch(int pointerId, int action, int x, int y);
void Java_com_gameloft_android_GAND_GloftGANG_GameGLSurfaceView_nativeOnTouch(
    JNIEnv* unusedEnv, jobject unusedReceiver, jint pointerId, jint action, jint x, jint y)
{
    appOnTouch(pointerId, action, x, y);
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
extern int isResume;
void appRun(void);
void Java_com_gameloft_android_GAND_GloftGANG_GameRenderer_nativeRender(
    JNIEnv* unusedEnv, jobject unusedReceiver)
{
    if (isResume)
        appRun();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void appResume(void);
void Java_com_gameloft_android_GAND_GloftGANG_GameGLSurfaceView_nativeResume(
    JNIEnv* unusedEnv, jobject unusedReceiver)
{
    appResume();
    isResume = 1;
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void appPause(void);
void Java_com_gameloft_android_GAND_GloftGANG_GameGLSurfaceView_nativePause(
    JNIEnv* unusedEnv, jobject unusedReceiver)
{
    isResume = 0;
    appPause();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
extern int sWindowWidth;
extern int sWindowHeight;
/* NDK GLES/gl.h: GLint and GLsizei are int. */
void glViewport(int x, int y, int width, int height);
void Java_com_gameloft_android_GAND_GloftGANG_GameRenderer_nativeResize(
    JNIEnv* unusedEnv, jobject unusedReceiver, jint width, jint height)
{
    sWindowWidth = width;
    sWindowHeight = height;
    glViewport(0, 0, width, height);
}
#ifdef __cplusplus
}
#endif


#ifdef __cplusplus
extern "C" {
#endif
extern int gAppAlive;
extern int needInterruptReload;
void appInit(void);
void Java_com_gameloft_android_GAND_GloftGANG_GameRenderer_nativeInit(
    JNIEnv* unusedEnv, jobject unusedReceiver, jint reload, jint width, jint height)
{
    if (gAppAlive) {
        needInterruptReload = reload;
    } else {
        sWindowWidth = width;
        sWindowHeight = height;
        appInit();
        gAppAlive = 1;
    }
}
#ifdef __cplusplus
}
#endif
