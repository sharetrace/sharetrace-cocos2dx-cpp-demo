//
// Created by Sharetrace on 2020/1/28.
//

#include "SharetraceCallbackProxy.h"
#include "../../../cocos2d/cocos/platform/android/jni/JniHelper.h"

#include <android/log.h>
#define  LOG_TAG    "Sharetrace"
#define  LOGD(...)  __android_log_print(ANDROID_LOG_DEBUG,LOG_TAG,__VA_ARGS__)
#define  LOGE(...)  __android_log_print(ANDROID_LOG_ERROR,LOG_TAG,__VA_ARGS__)

static void (*cacheWakeUpCallbackMethod)(SharetraceAppData appData);
static void (*cacheInstallCallbackMethod)(SharetraceAppData appData);

SharetraceAppData jAppData2AppData(jobject jAppData) {
    JNIEnv *env = cocos2d::JniHelper::getEnv();
    jclass clsAppData = env->FindClass("cn/net/shoot/sharetracesdk/AppData");
    jfieldID fID_paramsData = env->GetFieldID(clsAppData, "paramsData", "Ljava/lang/String;");
    jfieldID fID_channel = env->GetFieldID(clsAppData, "channel", "Ljava/lang/String;");
    jstring jParamsData = (jstring) (env->GetObjectField(jAppData, fID_paramsData));
    jstring jChannel = (jstring) (env->GetObjectField(jAppData, fID_channel));
    std::string paramsData = cocos2d::JniHelper::jstring2string(jParamsData);
    std::string channel = cocos2d::JniHelper::jstring2string(jChannel);
    SharetraceAppData appData = SharetraceAppData(paramsData, channel);
    return appData;
}

JNIEXPORT void JNICALL Java_com_sharetrace_cocos_WakeUpCallback_wakeup(JNIEnv *env, jobject obj, jobject jAppData) {
    LOGD("JNI WakeUpCallback start...");
    if (cacheWakeUpCallbackMethod == NULL) {
        return;
    }

    if (jAppData == NULL) {
        return;
    }

    SharetraceAppData appData = jAppData2AppData(jAppData);
    cacheWakeUpCallbackMethod(appData);
    LOGD("JNI WakeUpCallback success...");
}

JNIEXPORT void JNICALL Java_com_sharetrace_cocos_InstallCallback_install(JNIEnv *env, jobject obj, jobject jAppData) {
    LOGD("JNI InstallCallback start...");
    if (cacheInstallCallbackMethod == NULL) {
        return;
    }

    if (jAppData == NULL) {
        return;
    }

    SharetraceAppData appData = jAppData2AppData(jAppData);
    cacheInstallCallbackMethod(appData);
    LOGD("JNI InstallCallback success...");
}

void setWakeUpCallbackMethod(void (*wakeUpCallbackMethod)(SharetraceAppData appData)) {
    cacheWakeUpCallbackMethod = wakeUpCallbackMethod;
}

void setInstallCallbackMethod(void (*installCallbackMethod)(SharetraceAppData appData)) {
    cacheInstallCallbackMethod = installCallbackMethod;
}



