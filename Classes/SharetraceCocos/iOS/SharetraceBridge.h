//
//  SharetraceBridge.h
//  cocos-cpp
//
// Created by Sharetrace on 2020/1/26.
//

#ifndef SharetraceBridge_h
#define SharetraceBridge_h

#include "SharetraceAppData.h"

namespace sharetrace2dx {
    
    class SharetraceBridge {
        
    public:
                
        static void getInstallTrace(void (*installCallback)(SharetraceAppData appData));
        
        static void registerWakeUpTrace(void (*wakeupCallback)(SharetraceAppData appData));
        
        static void onGetWakeupTrace(SharetraceAppData appData);
        
    };
}

#endif //SharetraceBridge_h

