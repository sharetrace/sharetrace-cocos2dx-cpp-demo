//
//  SharetraceHelper.hpp
//  cocos-cpp
//
// Created by Sharetrace on 2020/1/26.
//

#ifndef SharetraceHelper_h
#define SharetraceHelper_h

#include "SharetraceAppData.h"
#include "cocos2d.h"

namespace sharetrace2dx {
    
    class SharetraceHelper {
        
    public:
        
        static void getInstallTrace(void (*installCallback)(SharetraceAppData appData));
        
        static void registerWakeUpTrace(void (*wakeupCallback)(SharetraceAppData appData));
        
    };

}

#endif /* SharetraceHelper_h */
