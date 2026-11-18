/* Shared observed JNI aliases/table prefix; not a complete JNI table. */
#ifndef WCH_APP_NATIVE_JNI_H
#define WCH_APP_NATIVE_JNI_H
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
#endif
