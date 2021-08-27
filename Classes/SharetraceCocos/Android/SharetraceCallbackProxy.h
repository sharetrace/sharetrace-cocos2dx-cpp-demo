//
// Created by Sharetrace on 2020/1/28.
//

#ifndef PROJ_ANDROID_SHARETRACECALLBACKPROXY_H
#define PROJ_ANDROID_SHARETRACECALLBACKPROXY_H

#include "../SharetraceAppData.h"
#include <jni.h>

using namespace sharetrace2dx;

extern "C" {
JNIEXPORT void JNICALL Java_com_sharetrace_cocos_WakeUpCallback_wakeup(JNIEnv *, jobject, jobject);
JNIEXPORT void JNICALL Java_com_sharetrace_cocos_InstallCallback_install(JNIEnv *, jobject, jobject);

void setWakeUpCallbackMethod(void (*wakeUpCallbackMethod)(SharetraceAppData appData));
void setInstallCallbackMethod(void (*installCallbackMethod)(SharetraceAppData appData));
}

#endif //PROJ_ANDROID_SHARETRACECALLBACKPROXY_H
