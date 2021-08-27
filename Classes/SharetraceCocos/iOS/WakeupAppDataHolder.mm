//
//  WakeupAppDataHolder.m
//  cocos-cpp
//
// Created by Sharetrace on 2020/1/27.
//

#import "WakeupAppDataHolder.h"

#include "SharetraceBridge.h"

using namespace sharetrace2dx;

@implementation WakeupAppDataHolder

+ (WakeupAppDataHolder *) shareInstance {
    
    static WakeupAppDataHolder *holder;
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^{
        if (holder == nil) {
            holder = [[WakeupAppDataHolder alloc] init];
        }
    });
    
    return holder;
}

- (void)getWakeUpTrace:(AppData *)appData {
    if (appData == nil) {
        return;
    }
    
    std::string paramsData = std::string([@"" UTF8String]);
    std::string channel = std::string([@"" UTF8String]);
    
    if (appData.paramsData != nil) {
        paramsData = std::string([appData.paramsData UTF8String]);
    }
    
    if (appData.channel != nil) {
        channel = std::string([appData.channel UTF8String]);
    }
    
    SharetraceAppData ret = SharetraceAppData(paramsData, channel);
    sharetrace2dx::SharetraceBridge::onGetWakeupTrace(ret);
}

@end
