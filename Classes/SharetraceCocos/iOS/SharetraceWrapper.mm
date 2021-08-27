//
//  SharetraceWrapper.m
//  Sharetrace-cocos-js
//
//  Created by Sharetrace on 2020/12/24.
//

#import "SharetraceWrapper.h"
#import "Sharetrace.h"
#import "WakeupAppDataHolder.h"

@implementation SharetraceWrapper

+ (void)startInit {
    [Sharetrace initWithDelegate: [WakeupAppDataHolder shareInstance]];
}

+ (BOOL)handleSchemeLinkURL:(NSURL * _Nullable)url {
    return [Sharetrace handleSchemeLinkURL:url];
}

+ (BOOL)handleUniversalLink:(NSUserActivity * _Nullable)userActivity {
    return [Sharetrace handleUniversalLink:userActivity];
}

@end
