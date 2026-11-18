/*
 * JNI sound bridge from the original jni_GLMediaPlayer.c translation unit.
 * The JNI interface below is an observed prefix, not a complete JNI table.
 */

typedef int jint;
typedef unsigned char jboolean;
#ifndef __cplusplus
typedef _Bool bool;
#endif
typedef float jfloat;
typedef void* jobject;
typedef jobject jclass;
typedef jobject jstring;
struct _jmethodID;
typedef struct _jmethodID* jmethodID;
struct JNINativeInterface;
typedef const struct JNINativeInterface* JNIEnv;
struct JNINativeInterface {
    void* preceding[21];
    jobject (*NewGlobalRef)(JNIEnv*, jobject);
    void* beforeDeleteLocal[1];
    void (*DeleteLocalRef)(JNIEnv*, jobject);
    void* beforeStaticMethod[89];
    jmethodID (*GetStaticMethodID)(JNIEnv*, jclass, const char*, const char*);
    void* beforeStaticBoolean[3];
    jboolean (*CallStaticBooleanMethod)(JNIEnv*, jclass, jmethodID, ...);
    void* beforeStaticInt[11];
    jint (*CallStaticIntMethod)(JNIEnv*, jclass, jmethodID, ...);
    void* beforeStaticVoid[11];
    void (*CallStaticVoidMethod)(JNIEnv*,jclass,jmethodID,...);
    void* beforeNewStringUTF[25];
    jstring (*NewStringUTF)(JNIEnv*, const char*);
};
#ifdef __cplusplus
extern "C" {
#endif
extern JNIEnv* mEnv;
static jclass mClassGLMediaPlayer;
static jmethodID pauseSoundID;
static jmethodID resumeSoundID;
static jmethodID stopSoundID;
static jmethodID unloadSoundID;
static jmethodID isSoundLoadedID;
static jmethodID loadSoundID;
static jmethodID pauseSoundBigID;
static jmethodID pauseAllID;
static jmethodID stopSoundBigID;
static jmethodID resumeSoundBigID;
static jmethodID unloadSoundBigID;
static jmethodID isSoundLoadedBigID;
static jmethodID loadSoundBigID;
static jmethodID resetSoundID;
static jmethodID setVolumeBigID;
void nativePauseSound(jint sound,jint instance)
{
    (*mEnv)->CallStaticVoidMethod(mEnv,mClassGLMediaPlayer,pauseSoundID,sound,instance);
}
void nativeResumeSound(jint sound, jint instance)
{
    (*mEnv)->CallStaticVoidMethod(mEnv, mClassGLMediaPlayer, resumeSoundID, sound, instance);
}
void nativeStopSound(jint sound, jint instance)
{
    (*mEnv)->CallStaticVoidMethod(mEnv, mClassGLMediaPlayer, stopSoundID, sound, instance);
}
void nativeUnloadSound(jint sound, jint instance)
{
    (*mEnv)->CallStaticVoidMethod(mEnv, mClassGLMediaPlayer, unloadSoundID, sound, instance);
}
jint nativeIsSoundLoaded(jint sound, jint instance)
{
    return (*mEnv)->CallStaticIntMethod(mEnv, mClassGLMediaPlayer, isSoundLoadedID, sound, instance);
}
void nativeLoadSound(jint sound, jint instance)
{
    (*mEnv)->CallStaticVoidMethod(mEnv, mClassGLMediaPlayer, loadSoundID, sound, instance);
}
void nativePauseSoundBig(jint sound)
{
    (*mEnv)->CallStaticVoidMethod(mEnv, mClassGLMediaPlayer, pauseSoundBigID, sound);
}
void nativePauseAllSounds(void)
{
    (*mEnv)->CallStaticVoidMethod(mEnv, mClassGLMediaPlayer, pauseAllID);
}
void nativeResumeSoundBig(jint sound)
{
    (*mEnv)->CallStaticVoidMethod(mEnv, mClassGLMediaPlayer, resumeSoundBigID, sound);
}
void nativeStopSoundBig(jint sound)
{
    (*mEnv)->CallStaticVoidMethod(mEnv, mClassGLMediaPlayer, stopSoundBigID, sound);
}
void nativeUnloadSoundBig(jint sound)
{
    (*mEnv)->CallStaticVoidMethod(mEnv, mClassGLMediaPlayer, unloadSoundBigID, sound);
}
jint nativeIsSoundLoadedBig(jint sound)
{
    return (*mEnv)->CallStaticIntMethod(mEnv, mClassGLMediaPlayer, isSoundLoadedBigID, sound);
}
void nativeLoadSoundBig(jint sound)
{
    (*mEnv)->CallStaticVoidMethod(mEnv, mClassGLMediaPlayer, loadSoundBigID, sound);
}
void nativeResetSound(jint sound)
{
    (*mEnv)->CallStaticVoidMethod(mEnv, mClassGLMediaPlayer, resetSoundID, sound);
}
void nativeSetVolumeBig(jint sound, jfloat volume)
{
    (*mEnv)->CallStaticVoidMethod(mEnv, mClassGLMediaPlayer, setVolumeBigID, sound, volume);
}
static jmethodID playSoundID;
static jmethodID playSoundBigID;
static jmethodID setVolID;

static jmethodID setPitchID;
static jmethodID stopAllID;
static jmethodID unloadAllID;
static jmethodID stopAllPoolID;
static jmethodID stopAllBigID;
static jmethodID destroySoundPoolID;
static jmethodID initSoundPoolArrayID;
static jmethodID loadMovie;
static jmethodID isMediaPlaying;
static jmethodID IsVideoPlayDone;
static const char jniText_4132b8[] __attribute__((section(".rodata.jni_text_4132b8"))) = "isSoundLoaded";
static const char jniText_4132c8[] __attribute__((section(".rodata.jni_text_4132c8"))) = "(II)I";
static const char jniText_4132d0[] __attribute__((section(".rodata.jni_text_4132d0"))) = "isSoundLoadedBig";
static const char jniText_4132e4[] __attribute__((section(".rodata.jni_text_4132e4"))) = "(I)I";
static const char jniText_4132ec[] __attribute__((section(".rodata.jni_text_4132ec"))) = "unloadSound";
static const char jniText_4132f8[] __attribute__((section(".rodata.jni_text_4132f8"))) = "(II)V";
static const char jniText_413300[] __attribute__((section(".rodata.jni_text_413300"))) = "unloadSoundBig";
static const char jniText_413310[] __attribute__((section(".rodata.jni_text_413310"))) = "(I)V";
static const char jniText_413318[] __attribute__((section(".rodata.jni_text_413318"))) = "loadSound";
static const char jniText_413324[] __attribute__((section(".rodata.jni_text_413324"))) = "loadSoundBig";
static const char jniText_413334[] __attribute__((section(".rodata.jni_text_413334"))) = "playSound";
static const char jniText_413340[] __attribute__((section(".rodata.jni_text_413340"))) = "(IIF)V";
static const char jniText_413348[] __attribute__((section(".rodata.jni_text_413348"))) = "playSoundBig";
static const char jniText_413358[] __attribute__((section(".rodata.jni_text_413358"))) = "(IFZ)V";
static const char jniText_413360[] __attribute__((section(".rodata.jni_text_413360"))) = "pauseSound";
static const char jniText_41336c[] __attribute__((section(".rodata.jni_text_41336c"))) = "pauseSoundBig";
static const char jniText_41337c[] __attribute__((section(".rodata.jni_text_41337c"))) = "pauseAllSounds";
static const char jniText_413248[] __attribute__((section(".rodata.jni_text_413248"))) = "()V";
static const char jniText_41338c[] __attribute__((section(".rodata.jni_text_41338c"))) = "resumeSound";
static const char jniText_413398[] __attribute__((section(".rodata.jni_text_413398"))) = "resumeSoundBig";
static const char jniText_4133a8[] __attribute__((section(".rodata.jni_text_4133a8"))) = "stopSound";
static const char jniText_4133b4[] __attribute__((section(".rodata.jni_text_4133b4"))) = "stopSoundBig";
static const char jniText_4133c4[] __attribute__((section(".rodata.jni_text_4133c4"))) = "setVolume";
static const char jniText_4133d0[] __attribute__((section(".rodata.jni_text_4133d0"))) = "setVolumeBig";
static const char jniText_4133e0[] __attribute__((section(".rodata.jni_text_4133e0"))) = "(IF)V";
static const char jniText_4133e8[] __attribute__((section(".rodata.jni_text_4133e8"))) = "resetSound";
static const char jniText_4133f4[] __attribute__((section(".rodata.jni_text_4133f4"))) = "setPitch";
static const char jniText_413400[] __attribute__((section(".rodata.jni_text_413400"))) = "stopAllSounds";
static const char jniText_413410[] __attribute__((section(".rodata.jni_text_413410"))) = "unloadAllSounds";
static const char jniText_413420[] __attribute__((section(".rodata.jni_text_413420"))) = "stopAllPool";
static const char jniText_41342c[] __attribute__((section(".rodata.jni_text_41342c"))) = "stopAllBig";
static const char jniText_413438[] __attribute__((section(".rodata.jni_text_413438"))) = "destroySoundPool";
static const char jniText_41344c[] __attribute__((section(".rodata.jni_text_41344c"))) = "initSoundPoolArray";
static const char jniText_413460[] __attribute__((section(".rodata.jni_text_413460"))) = "loadMovie";
static const char jniText_413258[] __attribute__((section(".rodata.jni_text_413258"))) = "(Ljava/lang/String;)V";
static const char jniText_41346c[] __attribute__((section(".rodata.jni_text_41346c"))) = "isMediaPlaying";
static const char jniText_41347c[] __attribute__((section(".rodata.jni_text_41347c"))) = "(I)Z";
static const char jniText_413484[] __attribute__((section(".rodata.jni_text_413484"))) = "IsVideoPlayDone";
static const char jniText_413494[] __attribute__((section(".rodata.jni_text_413494"))) = "()Z";
void Java_com_gameloft_android_GAND_GloftGANG_GLMediaPlayer_nativeInit(JNIEnv* unusedEnv, jclass clazz)
{
    mClassGLMediaPlayer = (*mEnv)->NewGlobalRef(mEnv, clazz);
    isSoundLoadedID = (*mEnv)->GetStaticMethodID(mEnv, mClassGLMediaPlayer, jniText_4132b8, jniText_4132c8);
    isSoundLoadedBigID = (*mEnv)->GetStaticMethodID(mEnv, mClassGLMediaPlayer, jniText_4132d0, jniText_4132e4);
    unloadSoundID = (*mEnv)->GetStaticMethodID(mEnv, mClassGLMediaPlayer, jniText_4132ec, jniText_4132f8);
    unloadSoundBigID = (*mEnv)->GetStaticMethodID(mEnv, mClassGLMediaPlayer, jniText_413300, jniText_413310);
    loadSoundID = (*mEnv)->GetStaticMethodID(mEnv, mClassGLMediaPlayer, jniText_413318, jniText_4132f8);
    loadSoundBigID = (*mEnv)->GetStaticMethodID(mEnv, mClassGLMediaPlayer, jniText_413324, jniText_413310);
    playSoundID = (*mEnv)->GetStaticMethodID(mEnv, mClassGLMediaPlayer, jniText_413334, jniText_413340);
    playSoundBigID = (*mEnv)->GetStaticMethodID(mEnv, mClassGLMediaPlayer, jniText_413348, jniText_413358);
    pauseSoundID = (*mEnv)->GetStaticMethodID(mEnv, mClassGLMediaPlayer, jniText_413360, jniText_4132f8);
    pauseSoundBigID = (*mEnv)->GetStaticMethodID(mEnv, mClassGLMediaPlayer, jniText_41336c, jniText_413310);
    pauseAllID = (*mEnv)->GetStaticMethodID(mEnv, mClassGLMediaPlayer, jniText_41337c, jniText_413248);
    resumeSoundID = (*mEnv)->GetStaticMethodID(mEnv, mClassGLMediaPlayer, jniText_41338c, jniText_4132f8);
    resumeSoundBigID = (*mEnv)->GetStaticMethodID(mEnv, mClassGLMediaPlayer, jniText_413398, jniText_413310);
    stopSoundID = (*mEnv)->GetStaticMethodID(mEnv, mClassGLMediaPlayer, jniText_4133a8, jniText_4132f8);
    stopSoundBigID = (*mEnv)->GetStaticMethodID(mEnv, mClassGLMediaPlayer, jniText_4133b4, jniText_413310);
    setVolID = (*mEnv)->GetStaticMethodID(mEnv, mClassGLMediaPlayer, jniText_4133c4, jniText_413340);
    setVolumeBigID = (*mEnv)->GetStaticMethodID(mEnv, mClassGLMediaPlayer, jniText_4133d0, jniText_4133e0);
    resetSoundID = (*mEnv)->GetStaticMethodID(mEnv, mClassGLMediaPlayer, jniText_4133e8, jniText_413310);
    setPitchID = (*mEnv)->GetStaticMethodID(mEnv, mClassGLMediaPlayer, jniText_4133f4, jniText_413340);
    stopAllID = (*mEnv)->GetStaticMethodID(mEnv, mClassGLMediaPlayer, jniText_413400, jniText_413248);
    unloadAllID = (*mEnv)->GetStaticMethodID(mEnv, mClassGLMediaPlayer, jniText_413410, jniText_413248);
    stopAllPoolID = (*mEnv)->GetStaticMethodID(mEnv, mClassGLMediaPlayer, jniText_413420, jniText_413310);
    stopAllBigID = (*mEnv)->GetStaticMethodID(mEnv, mClassGLMediaPlayer, jniText_41342c, jniText_413310);
    destroySoundPoolID = (*mEnv)->GetStaticMethodID(mEnv, mClassGLMediaPlayer, jniText_413438, jniText_413248);
    initSoundPoolArrayID = (*mEnv)->GetStaticMethodID(mEnv, mClassGLMediaPlayer, jniText_41344c, jniText_413248);
    loadMovie = (*mEnv)->GetStaticMethodID(mEnv, mClassGLMediaPlayer, jniText_413460, jniText_413258);
    isMediaPlaying = (*mEnv)->GetStaticMethodID(mEnv, mClassGLMediaPlayer, jniText_41346c, jniText_41347c);
    IsVideoPlayDone = (*mEnv)->GetStaticMethodID(mEnv, mClassGLMediaPlayer, jniText_413484, jniText_413494);
}
void nativeStopAllSounds(void)
{
    (*mEnv)->CallStaticVoidMethod(mEnv, mClassGLMediaPlayer, stopAllID);
}
void nativeUnloadAllSounds(void)
{
    (*mEnv)->CallStaticVoidMethod(mEnv, mClassGLMediaPlayer, unloadAllID);
}
void nativeStopAllSoundPool(jint sound)
{
    (*mEnv)->CallStaticVoidMethod(mEnv, mClassGLMediaPlayer, stopAllPoolID, sound);
}
void nativeStopAllBigSound(jint sound)
{
    (*mEnv)->CallStaticVoidMethod(mEnv, mClassGLMediaPlayer, stopAllBigID, sound);
}
void nativeDestroySoundPool(void)
{
    (*mEnv)->CallStaticVoidMethod(mEnv, mClassGLMediaPlayer, destroySoundPoolID);
}
void nativeInitSoundPoolArray(void)
{
    (*mEnv)->CallStaticVoidMethod(mEnv, mClassGLMediaPlayer, initSoundPoolArrayID);
}
void nativeLoadMovie(const char* filename)
{
    jstring name = (*mEnv)->NewStringUTF(mEnv, filename);
    (*mEnv)->CallStaticVoidMethod(mEnv, mClassGLMediaPlayer, loadMovie, name);
    (*mEnv)->DeleteLocalRef(mEnv, name);
}
jboolean nativeIsMediaPlaying(jint media)
{
    return (*mEnv)->CallStaticBooleanMethod(mEnv,mClassGLMediaPlayer,isMediaPlaying,media);
}
jboolean nativeIsVideoPlayDone(void)
{
    return (*mEnv)->CallStaticBooleanMethod(mEnv,mClassGLMediaPlayer,IsVideoPlayDone);
}
void nativePlaySoundBig(jint sound,jfloat volume,bool loop)
{
    (*mEnv)->CallStaticVoidMethod(mEnv,mClassGLMediaPlayer,playSoundBigID,sound,volume,loop);
}
void nativePlaySound(jint sound, jint instance, jfloat volume)
{
    (*mEnv)->CallStaticVoidMethod(mEnv, mClassGLMediaPlayer, playSoundID, sound, instance, volume);
}
void nativeSetVolume(jint sound, jint instance, jfloat volume)
{
    (*mEnv)->CallStaticVoidMethod(mEnv,mClassGLMediaPlayer,setVolID,sound,instance,volume);
}
void nativeSetPitch(jint sound, jint instance, jfloat pitch)
{
    (*mEnv)->CallStaticVoidMethod(mEnv,mClassGLMediaPlayer,setPitchID,sound,instance,pitch);
}
#ifdef __cplusplus
}
#endif
