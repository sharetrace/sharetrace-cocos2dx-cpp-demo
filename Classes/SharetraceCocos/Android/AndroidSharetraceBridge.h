//
// Created by Sharetrace on 2020/1/28.
//

#ifndef PROJ_ANDROID_ANDROIDSHARETRACEBRIDGE_H
#define PROJ_ANDROID_ANDROIDSHARETRACEBRIDGE_H

#include "../SharetraceAppData.h"

using namespace sharetrace2dx;

class AndroidSharetraceBridge {

public:

    static void getInstallTrace(void (*installCallback)(SharetraceAppData appData));

    static void registerWakeUpTrace(void (*wakeupCallback)(SharetraceAppData appData));

};

#endif //PROJ_ANDROID_ANDROIDSHARETRACEBRIDGE_H
