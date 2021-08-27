//
//  SharetraceBridge.m
//  cocos-cpp
//
// Created by Sharetrace on 2020/1/26.
//

#import <Foundation/Foundation.h>
#import "Sharetrace.h"
#include "SharetraceBridge.h"

using namespace sharetrace2dx;

static void(*cacheWakeUpCallBack)(SharetraceAppData appData);

void SharetraceBridge::getInstallTrace(void (*installCallback)(SharetraceAppData appData)) {
    [Sharetrace getInstallTrace:^(AppData * _Nullable appData) {
        
        std::string paramsData = std::string([@"" UTF8String]);
        std::string channel = std::string([@"" UTF8String]);
        
        if (appData == nil) {
            SharetraceAppData ret = SharetraceAppData(paramsData, channel);
            installCallback(ret);
            return;
        }
        
        if (appData.paramsData != nil) {
            paramsData = std::string([appData.paramsData UTF8String]);
        }
        
        if (appData.channel != nil) {
            channel = std::string([appData.channel UTF8String]);
        }
        
        SharetraceAppData ret = SharetraceAppData(paramsData, channel);
        installCallback(ret);

    } :^(NSInteger code, NSString * _Nonnull msg) {
        std::string paramsData = std::string([@"" UTF8String]);
        std::string channel = std::string([@"" UTF8String]);
        SharetraceAppData ret = SharetraceAppData(paramsData, channel);
        installCallback(ret);
    }];
}

void SharetraceBridge::registerWakeUpTrace(void (*wakeupCallback)(SharetraceAppData appData)) {
    cacheWakeUpCallBack = wakeupCallback;
}

void SharetraceBridge::onGetWakeupTrace(SharetraceAppData appData) {
    if (cacheWakeUpCallBack) {
        cacheWakeUpCallBack(appData);
    }
}


