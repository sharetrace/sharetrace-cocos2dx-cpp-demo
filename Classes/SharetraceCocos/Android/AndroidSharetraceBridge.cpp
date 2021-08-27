//
// Created by Sharetrace on 2020/1/28.
//

#include "AndroidSharetraceBridge.h"
#include "SharetraceCallbackProxy.h"
#include <jni.h>
#include "../../../cocos2d/cocos/platform/android/jni/JniHelper.h"

#include <android/log.h>
#define  LOG_TAG    "Sharetrace"
#define  LOGD(...)  __android_log_print(ANDROID_LOG_DEBUG,LOG_TAG,__VA_ARGS__)
#define  LOGE(...)  __android_log_print(ANDROID_LOG_ERROR,LOG_TAG,__VA_ARGS__)

using namespace cocos2d;

void AndroidSharetraceBridge::getInstallTrace(void (*installCallback)(SharetraceAppData appData)) {

    JniMethodInfo methodInfo_getInstallTrace;
    if (!JniHelper::getStaticMethodInfo(methodInfo_getInstallTrace,
                                        "cn/net/shoot/sharetracesdk/ShareTrace",
                                        "getInstallTrace",
                                        "(Lcn/net/shoot/sharetracesdk/ShareTraceInstallListener;)V")) {
        LOGD("ShareTrace.getInstallTrace getStaticMethodInfo failed.");
        return;
    }

    JniMethodInfo methodInfo_InstallCallback_init;
    if (!JniHelper::getMethodInfo(methodInfo_InstallCallback_init, "com/sharetrace/cocos/InstallCallback", "<init>", "()V")) {
        LOGD("ShareTrace InstallCallback getMethodInfo failed.");
        return;
    }

    jclass clsInstallCallback = methodInfo_InstallCallback_init.env->FindClass("com/sharetrace/cocos/InstallCallback");
    jmethodID methodID_init = methodInfo_InstallCallback_init.env->GetMethodID(clsInstallCallback, "<init>", "()V");
    jobject jInstallCallback = methodInfo_InstallCallback_init.env->NewObject(clsInstallCallback, methodID_init);

    setInstallCallbackMethod(installCallback);

    methodInfo_getInstallTrace.env->CallStaticVoidMethod(methodInfo_getInstallTrace.classID,
                                                         methodInfo_getInstallTrace.methodID,
                                                         jInstallCallback);
    methodInfo_InstallCallback_init.env->DeleteLocalRef(jInstallCallback);

    LOGD("ShareTrace.getInstallTrace jni success.");
}

void AndroidSharetraceBridge::registerWakeUpTrace(void (*wakeupCallback)(SharetraceAppData appData)) {
    setWakeUpCallbackMethod(wakeupCallback);
}