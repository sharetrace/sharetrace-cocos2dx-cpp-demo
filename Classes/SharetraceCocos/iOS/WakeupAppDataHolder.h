//
//  WakeupAppDataHolder.h
//  cocos-cpp
//
// Created by Sharetrace on 2020/1/27.
//

#import <Foundation/Foundation.h>
#import "Sharetrace.h"

@interface WakeupAppDataHolder : NSObject<SharetraceDelegate>

+ (WakeupAppDataHolder *) shareInstance;

@end

