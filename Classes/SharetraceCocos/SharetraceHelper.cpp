//
//  SharetraceHelper.cpp
//  cocos-cpp
//
// Created by Sharetrace on 2020/1/26.
//

#include "SharetraceHelper.h"

#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
#include "Android/AndroidSharetraceBridge.h"
#elif (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
#include "SharetraceBridge.h"
#endif

using namespace sharetrace2dx;

void SharetraceHelper::getInstallTrace(void (*installCallback)(SharetraceAppData appData)) {
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
    AndroidSharetraceBridge::getInstallTrace(installCallback);
#elif (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    SharetraceBridge::getInstallTrace(installCallback);
#endif
}

void SharetraceHelper::registerWakeUpTrace(void (*wakeupCallback)(SharetraceAppData appData)) {
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
    AndroidSharetraceBridge::registerWakeUpTrace(wakeupCallback);
#elif (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    SharetraceBridge::registerWakeUpTrace(wakeupCallback);
#endif
}
