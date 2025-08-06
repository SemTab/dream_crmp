#include "main.h"
#include "CJavaWrapper.h"

#include <jni.h>
#include <string>
#include <sys/system_properties.h>

inline int GetAndroidVersion(char *value)
{
	return __system_property_get(weikton("ro.build.version.release"), value);
}

inline int GetBrand(char *value)
{
	return __system_property_get(weikton("ro.product.brand"), value);
}

inline int GetModel(char *value)
{
	return __system_property_get(weikton("ro.product.model"), value);
}

inline int GetArm(char *value)
{
    return __system_property_get(weikton("ro.product.cpu.abi"), value);
}

inline jstring GetPackageName(JNIEnv *env, jobject jActivity)
{
    jmethodID method = env->GetMethodID(env->GetObjectClass(jActivity), weikton("getPackageName"), weikton("()Ljava/lang/String;"));
    return (jstring)env->CallObjectMethod(jActivity, method);
}

inline jobject GetGlobalActivity(JNIEnv *env)
{
    jclass activityThread = env->FindClass(weikton("android/app/ActivityThread"));
    jmethodID currentActivityThread = env->GetStaticMethodID(activityThread, weikton("currentActivityThread"), weikton("()Landroid/app/ActivityThread;"));
    jobject at = env->CallStaticObjectMethod(activityThread, currentActivityThread);
    jmethodID getApplication = env->GetMethodID(activityThread, weikton("getApplication"), weikton("()Landroid/app/Application;"));
    jobject context = env->CallObjectMethod(at, getApplication);
    return context;
}

inline void toasty(JNIEnv *mEnv, const char* txt, int msDuration = 3500, ...)
{
    jclass ToastClass = mEnv->FindClass(weikton("android/widget/Toast"));
    jmethodID makeTextMethodID = mEnv->GetStaticMethodID(ToastClass, weikton("makeText"), weikton("(Landroid/content/Context;Ljava/lang/CharSequence;I)Landroid/widget/Toast;"));
    jmethodID showMethodID = mEnv->GetMethodID(ToastClass, weikton("show"), weikton("()V"));

    jstring message = mEnv->NewStringUTF(txt);
    jint duration = msDuration;
    jobject toast = mEnv->CallStaticObjectMethod(ToastClass, makeTextMethodID, GetGlobalActivity(mEnv), message, duration);

    mEnv->CallVoidMethod(toast, showMethodID);
    mEnv->DeleteLocalRef(message);
}